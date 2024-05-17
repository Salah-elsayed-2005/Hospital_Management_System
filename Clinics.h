//
// Created by salah elsayed on 5/11/2024.
//

#ifndef HOPSITAL_MANAGEMENT_SYSTEM_CLINICS_H
#define HOPSITAL_MANAGEMENT_SYSTEM_CLINICS_H
#include <iostream>
#include <vector>
#include "Person.h"
using namespace std;
class Clinic{
    string type;
    vector<Patient*>waiting;// to be changed with priority queue
    Doctor*doctor;
public:
};
#endif //HOPSITAL_MANAGEMENT_SYSTEM_CLINICS_H
