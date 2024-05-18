
#ifndef HOPSITAL_MANAGEMENT_SYSTEM_CLINICS_H
#define HOPSITAL_MANAGEMENT_SYSTEM_CLINICS_H
#include <iostream>
#include <vector>
#include "PriorityQueue.h"
#include "Doctor.h"
using namespace std;
class Clinic{
    string type;
    PriorityQueue waiting;// to be changed with priority queue
    Doctor*doctor;
public:
    void setType(string);
    void setDoctor(Doctor*&);
    void addtoWaiting(Patient);
    void removefromWaiting(Patient);
    void printInfo();

};
#endif //HOPSITAL_MANAGEMENT_SYSTEM_CLINICS_H
