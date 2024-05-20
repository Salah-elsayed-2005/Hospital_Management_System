#include <iostream>
#include <vector>

#include "Patient.h"
#include "PriorityQueue.h"
#include "Doctor.h"
#include "Clinics.h"
using namespace std;

vector<Patient>hospitalPatients;
vector<Doctor>hospitalDoctors;
vector<Clinic>hospitalClinics;

void searchPatient(string id);
void addPatient();
void removePatient(string);
void displaypatients();

void searchDoctor(string id);
void addDoctor();
void removeDoctor(string);
void displaydoctors();

void startingmenu();
void mainmenu();
void editmenu();
void displaymenu();
void clinicmenu();
void creditsmenu();
int main() {


    Diagnosis d[5];
    d[0].setAirwayLevel(3);
    d[0].setBreathingLevel(99);
    d[0].setPulseLevel(110);
    d[0].setDisabilityLevel(2);
    d[0].setExposureLevel(false, 37);
    d[0].setTriageLevel();

    d[1].setAirwayLevel(1);
    d[1].setBreathingLevel(98);
    d[1].setPulseLevel(70);
    d[1].setDisabilityLevel(1);
    d[1].setExposureLevel(false, 37);
    d[1].setTriageLevel();

    d[2].setAirwayLevel(3);
    d[2].setBreathingLevel(99);
    d[2].setPulseLevel(110);
    d[2].setDisabilityLevel(2);
    d[2].setExposureLevel(false, 37);
    d[2].setTriageLevel();

    d[3].setAirwayLevel(2);
    d[3].setBreathingLevel(79);
    d[3].setPulseLevel(110);
    d[3].setDisabilityLevel(2);
    d[3].setExposureLevel(false, 37);
    d[3].setTriageLevel();

    d[4].setAirwayLevel(2);
    d[4].setBreathingLevel(99);
    d[4].setPulseLevel(60);
    d[4].setDisabilityLevel(2);
    d[4].setExposureLevel(false, 37);
    d[4].setTriageLevel();


    Patient p[5] = {
            {"Atta", "8621562",20 , true, "zy elfol", d[0]},
            {"Ali", "8512616",19 , false, "negro", d[1]},
            {"nabarawy", "54124522",34 , true, "el3tba 3alnazr", d[2]},
            {"shafey", "8985564",17 , true, "t3ban ya capten", d[3]},
            {"se7s", "87755151",988 , true, "whar", d[4]},
    };

    //start of nabarawy's tests
/*
    //patients functions test

    hospitalPatients.push_back(p[0]);
    hospitalPatients.push_back(p[1]);
    hospitalPatients.push_back(p[2]);
    hospitalPatients.push_back(p[3]);
    hospitalPatients.push_back(p[4]);

    removePatient("87755151");
    removePatient("8512616");
    searchPatient("8985564");
    searchPatient("87755151");
    //addPatient(); // diagnosis level missing and urgency levelriu


   // displaypatients();
    //end of patients tests


    // doctors functions test
    vector<string> days1 = {"Monday", "Wednesday", "Friday"};
    vector<string> days2 = {"Tuesday", "Thursday"};
    vector<string> days3 = {"Monday", "Thursday"};
    vector<string> days4 = {"Wednesday", "Saturday"};
    vector<string> days5 = {"Friday", "Sunday"};


    Doctor doctors[5] = {
            {"Salah", days1, 100, "General", "D001"},
            {"Hussein", days2, 150, "Specialist", "D002"},
            {"Abo Guendia", days3, 200, "Surgeon", "D003"},
            {"Behiry", days4, 250, "Dentist", "D004"},
            {"Atta Tany 3shan Bhebo", days5, 300, "Pediatrician", "D005"}
    };
    hospitalDoctors.push_back(doctors[0]);
    hospitalDoctors.push_back(doctors[1]);
    hospitalDoctors.push_back(doctors[2]);
    hospitalDoctors.push_back(doctors[3]);
    hospitalDoctors.push_back(doctors[4]);

    removeDoctor("D004");
    removeDoctor("D002");
    searchDoctor("D003");
    searchDoctor("D004");

    displaydoctors();
*/
    //Nabarawy's tests ends here


    PriorityQueue pq;
    for (auto & i : p) {
        pq.enqueue(i);
    }
    Patient pt;
    while(!pq.isEmpty()){
        cout<<pq.dequeue().getName()<<endl;
    }
    Doctor doctor;
    doctor.setName("Salah");
    doctor.setClinicType("ENT");
    doctor.setID("69420");
    doctor.setAvailableDays({"Monday","friday"});
    Clinic clinic;
    clinic.setDoctor(doctor);
    clinic.setType("ENT");

}

void startingmenu(){
    cout<<"Welcome to Our Hospital Management System"<<endl;
    cout<<"Please choose the desired option "<<endl;
    cout<<"1-Main menu\n2-credits :";
    int choice;
    cin >> choice;
    if (choice==1)
        mainmenu();
    if (choice==2)
        creditsmenu();
}
void creditsmenu(){
    cout<<"*******  Salah Eldin Elsayed *******"<<endl
        <<"*******  Abdulrahman Abougendia  *******"<<endl
        <<"*******  Omar Nabarawy   *******"<<endl
        <<"*******  Fouad Hasheesh  *******"<<endl
        <<"*******  Mohamed Farouk  *******"<<endl;
}
void mainmenu(){
    cout<<"Please choose the desired option "<<endl;
    cout<<"1-Edit Database\n2-Display Info\n3-Reserve a clinic :";
    int choice;
    cin >> choice;
    if (choice==1)
        editmenu();
    if (choice==2)
        displaymenu();
    if (choice==3)
        clinicmenu();
}

void editmenu(){
    cout<<"Please choose the desired option "<<endl;
    cout<<"1-Edit Doctor Info\n2-Add Doctor\n3-Remove Doctor\n4-Edit Patient Info\n5-Add Patient\n6-Remove Patient  :";
    int choice;
    cin >> choice;
    if (choice==1)
        //editDoctor();
    if (choice==2)
        addDoctor();
    if (choice==3)
        //removeDoctor(//put id);
    if (choice==4)
        //editPatient();
    if (choice==5)
        addPatient();
    //if (choice==6)
        //removePatient(put id);
}
void displaymenu(){
    // Display Clinic,Doctor,Patient
}
void clinicmenu(){
    // TBD
}
//Patients' funcions

void searchPatient(string id){
    for (int i = 0; i < hospitalPatients.size() ; i++ ){
        if (id == hospitalPatients[i].getId() ){
            cout << "id "<< id << " found..."<<endl;
            return ;
        }
    }
    cout << "patient with ID " << id << " not found." << endl;
}

void addPatient() {
    string name;
    string id;
    int age;
    bool gender;
    cout<<"Enter Patient Data"<<endl;
    cout<<"\nName : ";
    cin>>name;
    cout<<"\nID : ";
    cin>>id;
    cout<<"\nage: ";
    cin>>age;
    cout<<"\ngender (1 male 0 female ) : ";
    cin>>gender;
    Patient patient;
    patient.setName(name);
    patient.setId(id);
    patient.setAge(age);
    patient.setGender(gender);
    hospitalPatients.push_back(patient); //to be tested
}


void removePatient(string id_toberemoved){ // to be tested
    for (int i = 0; i < hospitalPatients.size() ; i++ ){
        if (id_toberemoved == hospitalPatients[i].getId() ){
            cout << "The patient is being removed... "<< endl;
            hospitalPatients.erase(hospitalPatients.begin() + i);
            cout << "Patient with id "<<id_toberemoved << " is removed successfully "<< endl;
            return ;
        }
    }
    cout << "patient with ID " << id_toberemoved << " not found." << endl;

}

void displaypatients(){
    cout << "printing all patients details..."<<endl;
    for (int i = 0;i<hospitalPatients.size();i++){
        hospitalPatients[i].displayinfo();
        cout<<endl<<endl;
    }
    cout << "This is the end of the patients list "<<endl;
}


//Doctors' functions

void searchDoctor(string id){
    for (int i = 0; i < hospitalDoctors.size() ; i++ ){
        if (id == hospitalDoctors[i].getID() ){
            cout << "id "<< id << " found..."<<endl;
            return ;
        }
    }
    cout << "Doctor with ID " << id << " not found." << endl;
}


void addDoctor(){
    string name;
    vector<string>availableDays;
    int appointmentPrice;
    string clinicType;
    string id;
    cout<<"Enter Doctor Data"<<endl;
    cout<<"Name : ";
    cin>>name;
    cout<<"\nAvailable Days : ";
   // getline(cin, availableDays);
    cout << "\nAppointment price : ";
    cin >> appointmentPrice;
    cout << "\nClinic type : ";
    cin >> clinicType;
    cout << "\nDoctor id : ";
    cin >> id;
    Doctor doc(name,availableDays,appointmentPrice,clinicType,id);
    hospitalDoctors.push_back(doc); // to be checked


}


void removeDoctor(string id_toberemoved){ //to be tested
    for (auto i = 0; i < hospitalDoctors.size() ; i++ ){
        if (id_toberemoved == hospitalDoctors[i].getID() ){
            cout << "The Doctor is being removed... "<< endl;
            hospitalDoctors.erase( hospitalDoctors.begin() + i );
            cout << "Doctor with id "<< id_toberemoved<< " is removed successfully "<< endl;
            return ;
        }
    }
    cout << "Doctor with ID " << id_toberemoved << " not found." << endl;
}

void displaydoctors(){
    cout << "printing all doctors details..."<<endl;
    for (int i = 0 ; i<hospitalDoctors.size();i++){
        hospitalDoctors[i].displayinfo();
        cout<<endl<<endl;
    }
    cout << "This is the end of the doctors list "<<endl;

}