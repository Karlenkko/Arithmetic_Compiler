cmake_minimum_required(VERSION 3.17)
project(Arithmetic_Compiler)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Arithmetic_Compiler
        symbole.cpp
        symbole.h
        Automate.cpp
        Automate.h
        lexer.cpp
        lexer.h
        main.cpp
        state.cpp
        state.h
        )
