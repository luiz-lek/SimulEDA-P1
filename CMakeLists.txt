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
        TLSE.c)
