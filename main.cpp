#include <vector>
#include <thread>
#include <mutex>
#include <chrono>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <random>
#include <queue>
#include <algorithm>
#include "headerFiles/conditions.hpp"

std::mutex getpatientlock;
std::shared_ptr<spdlog::logger> dbgLogger = std::make_shared<spdlog::logger>("dbgLogger");
std::shared_ptr<spdlog::logger> queueLogger = std::make_shared<spdlog::logger>("queueLogger");
std::shared_ptr<spdlog::logger> assignLogger = std::make_shared<spdlog::logger>("assignLogger");
struct Clinic{
    int workingReceptionists;
    bool open = true;
    void work(Clinic & clinic){
        while (true){
            if (clinic.workingReceptionists == 0){
                clinic.open=false;
                queueLogger->error("The clinic stopped taking patients");
                break;
            }  
            std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
};
struct Patient{
    std::string name;
    std::string surname;
    std::vector<Condition> conditions;
};


struct Doctor{
    std::string name;
    
    void treatPatient(Patient patient){
        int timetotreat = 0;
        std::string text = "Doctor " + name + " is now treating " + patient.name;
        spdlog::info(text);
        std::string dbgtext;

        for (Condition x: patient.conditions){
            timetotreat += x.timeToTreat;
            dbgtext += x.name +" (" + std::to_string(x.timeToTreat*3)+"ms) ";
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(timetotreat*3));
        spdlog::critical("Dr " + name + " finished treating " + patient.name + " " + patient.surname + " in "+ std::to_string(timetotreat*3)+"ms");
        dbgLogger->debug("Dr " + name + " finished treating " + patient.name + " " + patient.surname + " for " + dbgtext);
        
    }
};

struct patientQueue{
    std::queue<Patient> patientQueue;
};



Patient get_patient(patientQueue & pqueue){

    Patient currentPatient = pqueue.patientQueue.front();
    pqueue.patientQueue.pop();
    
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return currentPatient;

}


struct Office{
    Doctor currentDoctor;
    Patient currentPatient;
    bool occupied = false;
    void work(patientQueue& queue, Clinic & clinic){
        while (true)
        {
            if(occupied==false){
                std::unique_lock <std::mutex> patientlock(getpatientlock);
                if(queue.patientQueue.size()>0){
                occupied = true;
                currentPatient = get_patient(queue);
                assignLogger->warn("Assigned " + currentPatient.name + " " + currentPatient.surname +" to Dr "+ currentDoctor.name);
                patientlock.unlock();
                }
                else if (not clinic.open) {
                    spdlog::error("Dr " + currentDoctor.name+ " has finished for the day");
                    break;
                }
            }
            else{
                currentDoctor.treatPatient(currentPatient);{

                occupied = false;

                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
};


class Receptionist{
    void addRandomPatient(patientQueue& kolejka){
    std::vector<std::string> names{"John", "Noah", "Olivia", "Amelia", "George", "Oliver", "Jared", "Monica", "Sarah", "Mark", "Mat"};
    std::vector<std::string> surnames{"Smith", "Brown", "Wilson", "Stewart", "Campbell", "Robertson", "Thomson", "Anderson", "Scott", "Macdonald", "Taylor"};

    Patient newPatient;
    
    std::vector<Condition> conditions{StomachAche{}, HeadAche{}, Fracture{}, Fever{}, SoreThroat{}, RunnyNose{}, HeartAttack{}, Stroke{}, Seizure{}, Diabetes{}};
    std::random_shuffle(conditions.begin(), conditions.end());
    std::random_shuffle(names.begin(), names.end());
    std::random_shuffle(surnames.begin(), surnames.end());

    newPatient.name = names[0];
    newPatient.surname = surnames[0];

    int numberOfConditions = rand() % conditions.size();

    for (int i=0; i<=numberOfConditions; i++){
        newPatient.conditions.push_back(conditions[0]);
        conditions.erase(conditions.begin());
    }

    kolejka.patientQueue.push(newPatient);
    queueLogger->info(newPatient.name + " " + newPatient.surname + " has been added to the queue by "+ name);

}
    public:
    std::string name;
    const int timeToGetPatients;
    const int patientsToServe;
    void work(patientQueue& queue, Clinic & clinic){
        int i = 0;
        while (true)
        {
            if (i==patientsToServe){

                clinic.workingReceptionists -= 1;
                break;
            }
            addRandomPatient(queue);
            std::this_thread::sleep_for(std::chrono::milliseconds(timeToGetPatients));
            i++;    
        }
    }
};

int main(){
    auto treatFinishSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("../logfiles/finish.log", true);
    treatFinishSink->set_level(spdlog::level::trace);

    auto conditionDebugSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("../logfiles/debug.log", true);
    conditionDebugSink->set_level(spdlog::level::trace);    
    
    auto queueSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("../logfiles/queue.log", true);
    queueSink->set_level(spdlog::level::trace);    
   
    auto assignSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("../logfiles/assign.log", true);
    assignSink->set_level(spdlog::level::trace);    
    
    auto allSink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("../logfiles/all.log", true);
    allSink->set_level(spdlog::level::trace);    
   
    auto stdSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
    stdSink->set_level(spdlog::level::trace);    
    
    
    dbgLogger->set_level(spdlog::level::debug);
    dbgLogger->sinks().push_back(conditionDebugSink);


    queueLogger->sinks().push_back(queueSink);
    queueLogger->sinks().push_back(stdSink);
    queueLogger->sinks().push_back(allSink);


    assignLogger->sinks().push_back(assignSink);
    assignLogger->sinks().push_back(stdSink);
    assignLogger->sinks().push_back(allSink);



    spdlog::default_logger()->sinks().push_back(treatFinishSink);
    spdlog::default_logger()->sinks().push_back(allSink);

    srand(time(NULL));  
    patientQueue kolejka;
    Doctor doctor1{"House"};
    Doctor doctor2{"Who"};
    Doctor doctor3{"Phil"};
    Office office1;
    Office office2;
    Office office3;
    office1.currentDoctor = doctor1;
    office2.currentDoctor = doctor2;
    office3.currentDoctor = doctor3;
    Receptionist r1{"Mary", 500, 5};
    Receptionist r2{"Clara", 100, 10};

    Clinic clinic{2};

    std::thread recep1(&Receptionist::work, r1, std::ref(kolejka), std::ref(clinic));
    std::thread recep2(&Receptionist::work, r2, std::ref(kolejka), std::ref(clinic));

    std::thread working1(&Office::work, office1, std::ref(kolejka), std::ref(clinic));
    std::thread working2(&Office::work, office2, std::ref(kolejka), std::ref(clinic));
    std::thread working3(&Office::work, office3, std::ref(kolejka), std::ref(clinic));

    std::thread clinicRun(&Clinic::work, clinic, std::ref(clinic));

    recep1.join();
    recep2.join();
    working1.join();
    working2.join();
    working3.join();
    clinicRun.join();

    spdlog::error("The clinic has closed");
}