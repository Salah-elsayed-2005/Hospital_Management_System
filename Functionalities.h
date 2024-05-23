//
// Created by salah elsayed on 5/23/2024.
//

#ifndef UNTITLED1_FUNCTIONALITIES_H
#define UNTITLED1_FUNCTIONALITIES_H
#include <iostream>
using namespace std;
void searchPatient(string id);
void addPatient();
void removePatient(string);
void editPatient(string);
void displaypatients();

void searchDoctor(string id);
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
