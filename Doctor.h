#include <iostream>
#include <vector>
using namespace std;
#ifndef UNTITLED1_DOCTOR_H
#define UNTITLED1_DOCTOR_H
class Doctor{
    string name;
    vector<string>availableDays;
    string clinicType;
    string id;
public:
    Doctor();
    Doctor(string, vector<string> , string,string);


    void setName(string);
    void setPrice(int);
    void setAvailableDays(vector<string>);
    void setClinicType(string);
    void setID(string);

    string getName();
    vector<string>getAvailableDays();
    string getClinicType();
    string getID();

    void displayinfo();
};
#endif //UNTITLED1_DOCTOR_H
