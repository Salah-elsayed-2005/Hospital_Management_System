#include <iostream>
#include <vector>
using namespace std;
#ifndef UNTITLED1_DOCTOR_H
#define UNTITLED1_DOCTOR_H
class Doctor{
    string name;
    vector<string>avaialbleDays;// enum or Date.h ?
    int appointmentPrice;
    string clinicType;
    string id;
public:
    void setName(string);
    void setPrice(int);
    void setAvailableDays(vector<string>);
    void setClinicType(string);
    void setID(string);
    string getName();
    int getPrice();
    vector<string>getAvailableDays();
    string getClinicType();
    string getID();
};
#endif //UNTITLED1_DOCTOR_H
