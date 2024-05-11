cmake_minimum_required(VERSION 3.24)
project(Hopsital_Management_System)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hopsital_Management_System main.cpp DatabaseManager.cpp DatabaseManager.h CustomHeap.cpp CustomHeap.h CustomPriorityQueue.cpp Person.cpp Clinics.cpp Clinics.h  Person.h CustomPriorityQueue.h CustomPriorityQueue.h)
