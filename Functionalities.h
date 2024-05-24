//
// Created by salah elsayed on 5/23/2024.
//

#ifndef UNTITLED1_FUNCTIONALITIES_H
#define UNTITLED1_FUNCTIONALITIES_H
#include <iostream>
#include "Patient.h"
#include "Doctor.h"
#include "Clinics.h"
#include "Date.h"
using namespace std;
Patient* searchPatient_byid(string );
Patient* searchPatient_byName(string );
void addPatient();
void removePatient(string);
void editPatient(string);
void displaypatients();
Doctor* searchDoctor_byid(string );
Doctor* searchDoctor_byname(string );

void addDoctor();
void removeDoctor(string);
void editDoctor(string);
void displaydoctors();

void reserveClinic(); //needs to be implemented
void displayClinicSchedule(); //needs to be implemented
void displayclinics();
Clinic*searchCLinic(string);

void mainmenu();
void editmenu();
void displaymenu();
void clinicmenu();
void creditsmenu();
void emergencymenu();

#endif //UNTITLED1_FUNCTIONALITIES_H
