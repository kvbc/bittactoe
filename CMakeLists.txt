cmake_minimum_required(VERSION 3.0.2)

project(bittactoe)

set(CMAKE_C_FLAGS "-Wall -s -O2")

add_executable(${PROJECT_NAME} main.c cell.c)
