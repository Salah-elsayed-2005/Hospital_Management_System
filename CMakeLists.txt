cmake_minimum_required(VERSION 3.24)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hospital_Management_System
        main.cpp
        PriorityQueue.cpp
        PriorityQueue.h
        MaxHeap.cpp
        MaxHeap.h
        Patient.cpp
        Patient.h
        Diagnosis.cpp
        Diagnosis.h
        Clinics.cpp
        Clinics.h
        DatabaseManager.cpp
        DatabaseManager.h
        Doctor.cpp
        Doctor.h
        Date.cpp
        Date.h
        Trie.h)
