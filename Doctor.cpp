#include "Doctor.h"

Doctor :: Doctor(){}
Doctor :: Doctor(string nm, vector<string> avdays, int prices , string cltype ,string id11) : name(nm)
,availableDays(avdays), appointmentPrice(prices),clinicType(cltype),id(id11) {}


vector<string> Doctor::getAvailableDays() { return availableDays;}
int Doctor::getPrice() {return appointmentPrice;}
string Doctor::getName() {return name;}
string Doctor::getClinicType() {return clinicType;}
string Doctor::getID() {return id;}

void Doctor::setAvailableDays(vector<std::string>days) {availableDays=days;}
void Doctor::setClinicType(std::string t) {clinicType=t;}
void Doctor::setID(std::string i) {id=i;}
void Doctor::setName(std::string n) {name= n;}
void Doctor::setPrice(int p) {appointmentPrice=p;}

void Doctor :: displayinfo(){
    cout<<"Doctor's name is : "<< name << endl;
    cout << "Available Days : ";
    for (int i = 0; i < availableDays.size(); i++) {
        cout << availableDays[i];
        if (i != availableDays.size() - 1) {
            cout << " ,";
        }
    }
    cout << "\b\b\b\b\b"<<endl;
    cout << "Appointment price : "<< appointmentPrice<<endl;
    cout << "Clinic Type : " << clinicType << endl;
    cout<< "Doctor's id : "<<id<<endl;
}