#ifndef HOPSITAL_MANAGEMENT_SYSTEM_CLINICS_H
#define HOPSITAL_MANAGEMENT_SYSTEM_CLINICS_H


#include <iostream>
#include <vector>
#include "PriorityQueue.h"
#include "Doctor.h"
#include <sstream>

using namespace std;

class Clinic {
    string type;
    PriorityQueue waitingList;
    vector<Doctor> doctor;
public:
    Clinic();

    Clinic(string, PriorityQueue, vector<Doctor>);

    void setType(string);

    void setDoctor(vector<Doctor> d);

    void addtoWaiting(Patient);
    void removefromWaiting();
    void printInfo();

    void addDoctor(Doctor doc);

    string getType();
    PriorityQueue getWaitingList();

    vector<Doctor> getDoctor();




};
#endif //HOPSITAL_MANAGEMENT_SYSTEM_CLINICS_H
