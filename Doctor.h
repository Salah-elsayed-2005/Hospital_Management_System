#include <iostream>
#include <vector>
using namespace std;
#ifndef UNTITLED1_DOCTOR_H
#define UNTITLED1_DOCTOR_H
class Doctor{
    string name;
    vector<string>avaialbleDays;// enum or Date.h ?
    int appointmentPrice;
    string Clinictype;
public:
    void setName(string);
    void setPrice(int);
    void setAvailableDays(vector<string>);
    void setClinicType(string);
    string getName();
    int getPrice();
    vector<string>getAvailableDays();
    string getClinicType();
};
#endif //UNTITLED1_DOCTOR_H
