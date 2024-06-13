#pragma once
#include <string>

struct Condition{
    std::string name;
    unsigned int timeToTreat;

    Condition(const std::string& name, unsigned int timeToTreat) :name(name), timeToTreat(timeToTreat){};
};

struct StomachAche: public Condition{
    StomachAche() : Condition("StomachAche", 40){};
};

struct HeadAche: public Condition{
    HeadAche() : Condition("HeadAche", 30){};
};

struct Fracture: public Condition{
    Fracture() : Condition("Fracture", 100){};
};

struct Fever: public Condition{
    Fever() : Condition("Fever", 70){};
};

struct SoreThroat: public Condition{
    SoreThroat() : Condition("SoreThroat", 20){};
};

struct RunnyNose: public Condition{
    RunnyNose() : Condition("RunnyNose", 30){};
};

struct HeartAttack: public Condition{
    HeartAttack() : Condition("HeartAttack", 500){};
};

struct Stroke: public Condition{
    Stroke() : Condition("Stroke", 400){};
};

struct Seizure: public Condition{
    Seizure() : Condition("Seizure", 300){};
};

struct Diabetes: public Condition{
    Diabetes() : Condition("Diabetes", 100){};
};