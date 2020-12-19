cmake_minimum_required(VERSION 3.17)
project(Praktikum3 C)

set(CMAKE_C_STANDARD 11)

add_executable(Praktikum3 main.c konstanten.h arrayFunktionen.c arrayFunktionen.h mathFunktionen.c)
target_link_libraries(Praktikum3 m)