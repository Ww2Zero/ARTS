cmake_minimum_required(VERSION 2.8)
project(093_Restore_IP_Addresses)
SET(CMAKE_C_COMPILER g++)
add_compile_options(-std=c++11)
add_executable(093_Restore_IP_Addresses test.cpp solution.h)