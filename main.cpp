#include <iostream>
#include <vector>
#include "Trie.h"
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
void editPatient(string);
void displaypatients();

void searchDoctor(string id);
void addDoctor();
void removeDoctor(string);
void editDoctor(string);
void displaydoctors();

void startingmenu();
void mainmenu();
void editmenu();
void displaymenu();
void clinicmenu();
void creditsmenu();

int checkinput(int,int,int);
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
            {"Mohamed Atta", "8621562",20 , true, "zy elfol", d[0]},
            {"Ali Ayman ", "8512616",19 , false, "negro", d[1]},
            {"nabarawy FTW", "54124522",34 , true, "el3tba 3alnazr", d[2]},
            {"shafey Elzoz", "8985564",17 , true, "t3ban ya capten", d[3]},
            {"se7s se7s", "87755151",988 , true, "whar", d[4]},
    };
    for (auto & it :p) {
        hospitalPatients.push_back(it);
    }
    Trie<Patient>patientsnames;
    for (auto it:hospitalPatients) {
        patientsnames.insert(it.getName(),&it);
    }
     cout<<patientsnames.search("Mohamed Atta")->getId();

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
    */


    // doctors functions test
/*    vector<string> days1 = {"Monday", "Wednesday", "Friday"};
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
    cout << "Enter the id of the doctor you want to edit : ";
    string id;
    cin >> id;

    editDoctor(id);

    displaydoctors();
    */
    //Nabarawy's tests ends here


    PriorityQueue pq;
    for (auto & i : p) {
        pq.enqueue(i);
    }
    Patient pt;
    while(!pq.isEmpty()){
   //     cout<<pq.dequeue().getName()<<endl;
    }
    Doctor doctor;
    doctor.setName("Salah");
    doctor.setClinicType("ENT");
    doctor.setID("69420");
    doctor.setAvailableDays({"Monday","friday"});
    Clinic clinic;
    clinic.setDoctor(doctor);
    clinic.setType("ENT");

} // end of main function




void startingmenu(){
    cout<<"Welcome to Our Hospital Management System"<<endl;
    cout<<"Please choose the desired option "<<endl;
    cout<<"1-Main menu\n2-credits :";
    int choice;
    cin >> choice;
    choice = checkinput(choice ,1,2);
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
    choice = checkinput(choice,1,3);
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
    choice = checkinput(choice,1,6);
    if (choice==1){
        string id;
        cout << "Enter the id of the Doctor you want to edit : ";
        cin>> id;
        //editDoctor(id);
        }
    else if (choice==2){
        addDoctor();
    }
    else if (choice==3){
        string id;
        cout << "Enter the id of the Doctor you want to remove : ";
        cin>> id;
        removeDoctor( id);
        }
    else if (choice==4){
        string id;
        cout << "Enter the id of the patient you want to edit : ";
        cin>> id;
        //editPatient();
    }
    else if (choice==5) {
        addPatient();
    }
    else if (choice==6) {
        string id;
        cout << "Enter the id of the patient you want to remove : ";
        cin>> id;
        removePatient( id);
    }
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
    //Na2es diagnosis
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


void editPatient(string id_tobe_edited){
    for (int i = 0; i < hospitalPatients.size() ; i++ ){
        int choice;
        if(id_tobe_edited == hospitalPatients[i].getId()){
            cout << "what do you want to edit in the patient with id "<< id_tobe_edited<<endl;
            cout << "1-Patient's name\n2-Patient's id\n3-Patient's age\n4-Patient's gender\n5-condition description\n";
            cout <<"6-diagnosis level : ";
            cin >> choice;
            choice = checkinput(choice,1,6);
            if (choice == 1){
                string name;
                cout << "Enter the new name of the patient : ";
                getline(cin,name);
                getline(cin,name); // msh btshtgal b getline wahda w m3rfsh leh
                hospitalPatients[i].setName(name);
            }
            if (choice == 2){
                string id;
                cout << "Enter the new id of the patient : ";
                cin >> id;
                hospitalPatients[i].setId(id);
            }
            if (choice == 3){
                int age;
                cout << "Enter the new age of the patient : ";
                cin >> age;
                hospitalPatients[i].setAge(age);
            }
            if (choice == 4){
                bool gen;
                cout << "Enter the right gender of the patient (1 for male and 0 for female)  : ";
                cin >> gen;
                hospitalPatients[i].setGender(gen);
            }
            if (choice == 5){
                string condition;
                cout << "Enter the condition description of the patient : ";
                getline(cin,condition);
                getline(cin,condition); //msh btshtghal b getline wahda w m3rfsh leh
                hospitalPatients[i].setConditionDescription(condition);
            }
            if(choice == 6){
                //diagnosissssssssssssssssssss
            }
            cout << "Patient is edited successfully"<<endl;
            return;
        }
    }
    cout << "patient with ID " << id_tobe_edited << " not found." << endl;
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

void editDoctor(string id_tobe_edited){
    int choice;
    for(int i = 0; i < hospitalDoctors.size() ; i++ ){
        if( id_tobe_edited == hospitalDoctors[i].getID() ){
            cout << "What do you want to edit in the doctor with id "<<id_tobe_edited <<endl;
            cout << "1-Doctor's name\n2-Doctor's available days\n3-appointment price\n4-clinic type\n5-Doctor's id : ";
            cin >> choice;
            choice = checkinput(choice,1,5);
            if (choice == 1){
                string name;
                cout << "Enter the Doctor's right name: ";
                getline(cin,name);
                getline(cin,name); //msh btshtghal b getline wahda w m3rfsh leh
                hospitalDoctors[i].setName(name);
            }
            if (choice == 2){
                vector<string> avd;
                cout << "Enter Doctor's available days: ";
                //missing cin method
                hospitalDoctors[i].setAvailableDays(avd);
            }
            if (choice == 3){
                int apprice;
                cout << "Enter the appointment price: ";
                cin >> apprice;
                hospitalDoctors[i].setPrice(apprice);
            }
            if (choice == 4){
                string clinic;
                cout <<"Enter the clinic type : ";
                getline(cin,clinic);
                getline(cin,clinic); //msh btshtghal b getline wahda w m3rfsh leh
                hospitalDoctors[i].setClinicType(clinic);
            }
            if (choice == 5){
                string id;
                cout << "Enter the Doctor's new id : ";
                cin >> id;
                hospitalDoctors[i].setID(id);
            }
            cout << "Patient is edited successfully"<<endl;
            return;
        }

    }
    cout << "Doctor with ID " << id_tobe_edited << " not found." << endl;
}

void displaydoctors(){
    cout << "printing all doctors details..."<<endl;
    for (int i = 0 ; i<hospitalDoctors.size();i++){
        hospitalDoctors[i].displayinfo();
        cout<<endl<<endl;
    }
    cout << "This is the end of the doctors list "<<endl;

}


//function that will be used multiple times to check the input
int checkinput(int choice,int first,int last){

    while (choice < first || choice > last ){
        cout << "Please enter a number between "<<first<< " and " <<last <<" inclusively : ";
        cin >> choice;
    }
    return choice;
}