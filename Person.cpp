//
// Created by salah elsayed on 5/11/2024.
//
#include "Person.h"
#include "iostream"
using namespace std;
/*******    USER    *********/



/******** Patient ***********/
void Patient::displaydata(){
cout<<"\nName : "<<getname()<<endl
<<"Age : "<<getage()<<endl
<<"Id : "<<getID()<<endl
<<"charges : "<<charges<<endl;
}

/******   Doctor  *********/
void Doctor:: displaydata(){
cout<<"\nName : "<<getname()<<endl
<<"Age : "<<getage()<<endl
<<"Id : "<<getID()<<endl
<<"Clinic : "<<clinic<<endl;
}