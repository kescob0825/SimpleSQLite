cmake_minimum_required(VERSION 3.30)
project(SimpleSQLite C)

set(CMAKE_C_STANDARD 99)

add_executable(SimpleSQLite main.c
        InputBuffer.h
        InputBuffer.c)
