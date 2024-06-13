cmake_minimum_required(VERSION 3.10)
project(spdlog CXX)

set(CMAKE_CXX_STANDARD 20)

if(NOT TARGET spdlog)
    find_package(spdlog REQUIRED)
endif()


include_directories(headerFiles spdlog)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>)