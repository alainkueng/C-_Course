cmake_minimum_required(VERSION 3.17)
project(exercise4)

set(CMAKE_CXX_STANDARD 14)

add_executable(exercise4 main.cpp playfield.h human.cpp human.h intel.cpp intel.h computer.cpp computer.h com_dom.cpp)