//
// Created by salah elsayed on 5/11/2024.
//

#ifndef HOPSITAL_MANAGEMENT_SYSTEM_PERSON_H
#define HOPSITAL_MANAGEMENT_SYSTEM_PERSON_H
#include "iostream"
using namespace std;
class Person{ // Abstract
    string name;
    int age;
    string Id;
public:
    string getname();
    string getID();
    int    getage();
    void setAame(string n);
    void setId(string i);
    void setAge(int a);

    virtual void displaydata()=0;
};
class Patient:public Person{
    int charges;
public:
    void displaydata()override;
};
class Doctor:public Person{
string clinic;
public:
    void displaydata()override;
};
#endif //HOPSITAL_MANAGEMENT_SYSTEM_PERSON_H
