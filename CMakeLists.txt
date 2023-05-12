cmake_minimum_required(VERSION 3.23)
project(Data_Structures_Assignment_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Data_Structures_Assignment_1
        main.cpp
        Node.cpp Node.h
        List.cpp List.h
        Globals.cpp Globals.h
        Stack.cpp Stack.h
        Item.cpp Item.h)
