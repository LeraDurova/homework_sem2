cmake_minimum_required(VERSION 4.1)
project(task11)

set(CMAKE_CXX_STANDARD 17)

add_executable(task11 main.cpp
        Student.hpp
        Student.cpp
        Person.hpp
        Person.cpp
        RecordBook.hpp
        RecordBook.cpp
        Group.hpp
        Group.cpp
        FileManager.hpp
        FileManager.cpp
        Teacher.hpp
        Teacher.cpp)
