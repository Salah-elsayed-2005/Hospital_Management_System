#include "Doctor.h"

Doctor :: Doctor(){}
Doctor :: Doctor(string nm, vector<string> avdays, int prices , string cltype ,string id11) : name(nm)
,avaialbleDays(avdays), appointmentPrice(prices),clinicType(cltype),id(id11) {}



vector<string> Doctor::getAvailableDays() { return avaialbleDays;}
int Doctor::getPrice() {return appointmentPrice;}
string Doctor::getName() {return name;}
string Doctor::getClinicType() {return clinicType;}
string Doctor::getID() {return id;}

void Doctor::setAvailableDays(vector<std::string>days) {avaialbleDays=days;}
void Doctor::setClinicType(std::string t) {clinicType=t;}
void Doctor::setID(std::string i) {id=i;}
void Doctor::setName(std::string n) {name=n;}
void Doctor::setPrice(int p) {appointmentPrice=p;}