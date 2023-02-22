cmake_minimum_required(VERSION 3.24)
project(leetcodeC C)

set(CMAKE_C_STANDARD 17)

add_executable(leetcodeC main.c runner.c utils.h 01-TwoSum.h 01-TwoSum.c)
