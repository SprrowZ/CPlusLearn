# cmake_minimum_required(VERSION <specify CMake version here>)
project(untitled1)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled1 main.cpp TestCinCout.cpp demo1/myfun.cpp demo1/myfun.h   cdemo/ctest.c cdemo/ctest.h
        demo1/chapter2.cpp  demo1/chapter2.h)