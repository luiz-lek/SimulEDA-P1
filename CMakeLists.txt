cmake_minimum_required(VERSION 4.0)
project(TABB C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TABB
        TABB.c
        TABB.h
        main.c
        TG.h
        TG.c
        TLSE.c
        gabarito/src/q6.c
        gabarito/headers/q6.h
        gabarito/src/q9.c
        gabarito/headers/q9.h
        gabarito/headers/q8.h
        gabarito/src/q8.c
        gabarito/headers/q5.h
        gabarito/src/q5.c
        TAB.c)
