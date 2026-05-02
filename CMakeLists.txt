cmake_minimum_required(VERSION 4.0)
project(TABB C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(TABB
        TABB.c
        TABB.h
        main_TABB.c
        TG.h
        TG.c
        TLSE.c
        gabarito/src/q6.c
        gabarito/headers/q6.h
        gabarito/src/q9.c
        gabarito/headers/q9.h)
