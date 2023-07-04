cmake_minimum_required(VERSION 3.24)
project(callToPythonProgram)

set(CMAKE_CXX_STANDARD 17)

add_executable(callToPythonProgram main.cpp dataset/reader.cpp)
