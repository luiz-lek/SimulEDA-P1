cmake_minimum_required(VERSION 4.0)
project(TABB C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TABB
        estrturas/src/TABB.c
        estrturas/headers/TABB.h
        main.c
        estrturas/headers/TG.h
        estrturas/src/TG.c
        estrturas/src/TLSE.c
        gabarito/src/q6.c
        gabarito/headers/q6.h
        gabarito/src/q9.c
        gabarito/headers/q9.h
        gabarito/headers/q8.h
        gabarito/src/q8.c
        gabarito/headers/q5.h
        gabarito/src/q5.c
        estrturas/src/TAB.c
        gabarito/headers/q2.h
        gabarito/src/q2.c
        gabarito/src/q7.c
        gabarito/headers/q7.h)
