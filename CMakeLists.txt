cmake_minimum_required(VERSION 3.24)
project(leetcodeC C)

set(CMAKE_C_STANDARD 17)

add_executable(leetcodeC runner.c utils.h 01-TwoSum.h 01-TwoSum.c utils.c 02-Palindrome.c 02-Palindrome.h)
