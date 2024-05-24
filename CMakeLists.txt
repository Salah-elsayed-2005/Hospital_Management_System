cmake_minimum_required(VERSION 3.24)
project(Hospital_Management_System)

set(CMAKE_CXX_STANDARD 17)
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK4 REQUIRED gtk4)

include_directories(${GTK4_INCLUDE_DIRS})
link_directories(${GTK4_LIBRARY_DIRS})
add_definitions(${GTK4_CFLAGS_OTHER})
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
        Trie.h
        Functionalities.cpp
        Functionalities.h
        CityGraph.cpp
        CityGraph.h
        gui.h
        gui.cpp)
target_link_libraries(Hospital_Management_System ${GTK4_LIBRARIES})