//
// Created by salah elsayed on 5/23/2024.
//

#ifndef UNTITLED1_FUNCTIONALITIES_H
#define UNTITLED1_FUNCTIONALITIES_H
#include <iostream>
#include "Patient.h"
#include "Doctor.h"
using namespace std;
Patient* searchPatient(string );
Patient* searchPatient_byName(string );
void addPatient();
void removePatient(string);
void editPatient(string);
void displaypatients();

Doctor* searchDoctor(string );
Doctor* searchDoctor_byname(string );
void addDoctor();
void removeDoctor(string);
void editDoctor(string);
void displaydoctors();

void reserveClinic(); //needs to be implemented
void displayClinicSchedule(); //needs to be implemented

void startingmenu();
void mainmenu();
void editmenu();
void displaymenu();
void clinicmenu();
void creditsmenu();

int checkinput(int,int,int);

#endif //UNTITLED1_FUNCTIONALITIES_H
