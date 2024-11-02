cmake_minimum_required(VERSION 3.29)
project(student_management C)

set(CMAKE_C_STANDARD 11)

add_executable(student_management main.c
        data_access/data_access.h
        data_access/data_access.c)
