cmake_minimum_required(VERSION 3.31)
project(RingBuffer C)

set(CMAKE_C_STANDARD 11)

add_executable(RingBuffer main.c
        RingBuffer.c
        RingBuffer.h)
