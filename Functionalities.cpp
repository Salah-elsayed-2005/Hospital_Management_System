//
// Created by salah elsayed on 5/23/2024.
//

#include "Functionalities.h"
#include <iostream>
#include <vector>
#include <sstream> //for the vector of strings available days
#include "Trie.h"
#include "Patient.h"
#include "PriorityQueue.h"
#include "Doctor.h"
#include "Clinics.h"
using namespace std;
extern vector<Patient>hospitalPatients;
extern vector<Doctor>hospitalDoctors;
extern vector<Clinic>hospitalClinics;
extern Trie<Patient>patientsnames;
extern Trie<Patient>patientsids;
extern Trie<Doctor>doctorsnames;
extern Trie<Doctor>doctorsids;




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
    cout<<"===Edit menu=== "<<endl;
    cout<<"1-Edit Doctor Info\n2-Add Doctor\n3-Remove Doctor\n4-Edit Patient Info\n5-Add Patient\n6-Remove Patient\n ";
    cout<<"Enter your choice : ";
    int choice;
    cin >> choice;
    choice = checkinput(choice,1,6);
    if (choice==1){
        string id;
        cout << "Enter the id of the Doctor you want to edit : ";
        cin>> id;
        editDoctor(id);
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
        editPatient(id);
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
    int choice;
    cout<<"1-Display clinic info"<<endl
        <<"2-Display Doctor info"<<endl
        <<"3-Display Patient info"<<endl;
    cout<<"Please Enter Your choice : ";
    cin>>choice;
    if (choice==1)
        cout<<"Not Yet";
    if (choice==2)
        displaydoctors();
    if(choice==3)
        displaypatients();
 }
void clinicmenu(){
    int choice;
    cout << "===Clinic Menu===\n";
    cout << "1- Reserve a Clinic\n";
    cout << "2- Display Clinic Schedule\n";
    cout << "3- Return to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;
    choice = checkinput(choice, 1, 3);

    switch (choice) {
        case 1:
            //reserveClinic(); lesa htt3mel
            break;
        case 2:
            //displayClinicSchedule(); // lesa htt3mel
            break;
        case 3:
            mainmenu(); //return to main menu
            break;
    }
}
//Patients' funcions


/*for (int i = 0; i < hospitalPatients.size() ; i++ ){ //iterate over the whole vector
        if (id == hospitalPatients[i].getId() ){//if condition to get the patientwith the id
            cout << "id "<< id << " found..."<<endl;
            //hospitalPatients[i].displayinfo();
            return ;
        }
    }*/
//function to search patient by id
Patient* searchPatient(string id){

    if (patientsids.search(id)){
        return patientsnames.search(id);
    }
    else {
        cout << "patient with ID " << id << " not found." << endl;
    }

}

Patient* searchPatient_byName(string name){
    if(patientsnames.search(name)) {
        return patientsnames.search(name);
    }
    else {
        cout << "patient with name " << name << " not found." << endl;

    }
}

void addPatient() {
    string name;
    string id;
    int age;
    bool gender;
    string condition;
    cout<<"Enter Patient Data"<<endl;
    cout<<"\nName : ";
    cin>>name; //takes the name of the patient from the user
    cout<<"\nID : ";
    cin>>id; //takes the id of the patient from the user
    cout<<"\nage: ";
    cin>>age; //takes the age of the patient from the user
    cout<<"\ngender (1 male 0 female ) : ";
    cin>>gender; //takes the gender of the patient from the user
    cout<<"\ncondition description : ";
    cin >>condition; //takes the condition of the patient from the user

    int airwaylevel,breathinglevel,pulselevel,disabilitylevel,exposurelevel;
    cout << "please enter the airway level : ";
    cin >> airwaylevel; //takes the airway level of the patient from the user
    cout << "please enter the breathing level : ";
    cin >> breathinglevel; //takes the breathing level of the patient from the user
    cout << "please enter the pulse level : ";
    cin >> pulselevel; //takes the pulse level of the patient from the user
    cout << "please enter the disbaility level : ";
    cin >> disabilitylevel; //takes the disability level of the patient from the user
    cout << "please enter the exposure level : ";
    cin >> exposurelevel; //takes the exposure level of the patient from the user
    //The following line initializes an object of class diagnosis and calls its constructor with the
    //given info from the user to put it in the patient class
    Diagnosis d1(airwaylevel,breathinglevel,pulselevel,disabilitylevel,exposurelevel);
    //The following line initializes an object of class patient with all the members collected from the user
    Patient patient(name,id,age,gender,condition,d1);
    hospitalPatients.push_back(patient); // push(store) patient object(with all the info collected from the user ) in the vector
    patientsnames.insert(patient.getName(),&patient);
    patientsnames.insert(patient.getId(),&patient);
}

//function to remove the patient from the vector
void removePatient(string id_toberemoved){
    for (int i = 0; i < hospitalPatients.size() ; i++ ){ //iterate over the whole vector
        if (id_toberemoved == hospitalPatients[i].getId() ){  //if condition to get the patient
            // with the id to be removed
            cout << "The patient is being removed... "<< endl;
            patientsnames.deleteWord(hospitalPatients[i].getName());
            patientsids.deleteWord(hospitalPatients[i].getId());
            hospitalPatients.erase(hospitalPatients.begin() + i); //remove the patient wanted to remove
            // from the vector
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
            cout << "===Edit menu===\n";
            cout << "what do you want to edit in the patient with id : "<< id_tobe_edited<<endl;
            cout << "1- Patient's name\n2- Patient's id\n3- Patient's age\n4- Patient's gender\n";
            cout << "5- Condition description\n";
            cout <<"6- Diagnosis level\nEnter your choice : ";
            cin >> choice;
            choice = checkinput(choice,1,6);
            if (choice == 1){
                string name;
                cout << "Enter the new name of the patient : ";
                cin.ignore(); //clear the buffer to ensure that getline works correctly
                getline(cin,name);
                patientsnames.deleteWord(patientsids.search(id_tobe_edited)->getName());
                patientsnames.insert(name,patientsids.search(id_tobe_edited));
                hospitalPatients[i].setName(name);
            }
            else if (choice == 2){
                string id;
                cout << "Enter the new id of the patient : ";
                cin >> id;
                patientsnames.deleteWord(patientsids.search(id_tobe_edited)->getId());
                patientsnames.insert(id,patientsids.search(id_tobe_edited));
                hospitalPatients[i].setId(id);
            }
            else if (choice == 3){
                int age;
                cout << "Enter the new age of the patient : ";
                cin >> age;
                hospitalPatients[i].setAge(age);
            }
            else if (choice == 4){
                bool gen;
                cout << "Enter the right gender of the patient (1 for male and 0 for female)  : ";
                cin >> gen;
                hospitalPatients[i].setGender(gen);
            }
            else if (choice == 5){
                string condition;
                cout << "Enter the condition description of the patient : ";
                cin.ignore(); //clear the buffer to ensure that getline works correctly
                getline(cin,condition);
                hospitalPatients[i].setConditionDescription(condition);
            }
            else if(choice == 6){
                int airwaylevel,breathinglevel,pulselevel,disabilitylevel,exposurelevel;
                cout << "please enter the airway level : ";
                cin >> airwaylevel;
                cout << "please enter the breathing level : ";
                cin >> breathinglevel;
                cout << "please enter the pulse level : ";
                cin >> pulselevel;
                cout << "please enter the disbaility level : ";
                cin >> disabilitylevel;
                cout << "please enter the exposure level : ";
                cin >> exposurelevel;
                Diagnosis d1(airwaylevel,breathinglevel,pulselevel,disabilitylevel,exposurelevel);
                hospitalPatients[i].setDiagnosis(d1);
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

Doctor* searchDoctor(string id){
    if (doctorsids.search(id))
        return doctorsnames.search(id);
    else
        cout << "Doctor with ID " << id << " not found." << endl;
}

Doctor* searchDoctor_byname(string name){
    if (doctorsids.search(name)) {
        return doctorsnames.search(name);
    }
    else {
        cout << "Doctor with name " << name << " not found." << endl;
    }
}


void addDoctor(){
    string name;
    vector<string>availableDays; string inputline;
    int appointmentPrice;
    string clinicType;
    string id;
    cout<<"Enter Doctor Data"<<endl;
    cout<<"Name : ";
    cin>>name; //takes the name of the doctor from the user
    cout<<"\nAvailable Days : ";
    cin.ignore(); //clear the buffer to ensure that getline works correctly
    getline(cin, inputline);//get the whole line as inputline becausecin can't take more than one word
    stringstream line(inputline);
    string day;
    while(line>>day){ //days separated by spaces not commas
        availableDays.push_back(day);
    }
    cout << "\nAppointment price : ";
    cin >> appointmentPrice;
    cout << "\nClinic type : ";
    cin >> clinicType;
    cout << "\nDoctor id : ";
    cin >> id;
    Doctor doc(name,availableDays,appointmentPrice,clinicType,id);
    hospitalDoctors.push_back(doc);
    doctorsnames.insert(name,&doc);
    doctorsids.insert(id,&doc);
}


void removeDoctor(string id_toberemoved){ //to be tested
    for (auto i = 0; i < hospitalDoctors.size() ; i++ ){ // iterate over the whole vector of Doctors
        if (id_toberemoved == hospitalDoctors[i].getID() ){  //if condition to get the doctor with the id to be removed
            cout << "The Doctor is being removed... "<< endl;
            doctorsnames.deleteWord(hospitalDoctors[i].getName());
            doctorsids.deleteWord(hospitalDoctors[i].getID());
            hospitalDoctors.erase( hospitalDoctors.begin() + i ); //remove the doctor from the vector
            cout << "Doctor with id "<< id_toberemoved<< " is removed successfully "<< endl;
            return ; // exits the function after erasing the doctor
        }
    }
    cout << "Doctor with ID " << id_toberemoved << " not found." << endl; // if the id doesn't exist
}

void editDoctor(string id_tobe_edited){
    int choice;
    for(int i = 0; i < hospitalDoctors.size() ; i++ ){ //loop over the whole vector
        if( id_tobe_edited == hospitalDoctors[i].getID() ){ //if condition to get the doctor with the id to be edited
            cout << "What do you want to edit in the doctor with id "<<id_tobe_edited <<endl;
            cout << "1-Doctor's name\n2-Doctor's available days\n3-appointment price\n4-clinic type\n5-Doctor's id : ";
            cin >> choice;
            choice = checkinput(choice,1,5); // make sure that the user entered a number from 1 to 5
            if (choice == 1){
                string name;
                cout <<"Enter the Doctor's right name: ";
                cin.ignore(); //clear the buffer to ensure that getline works correctly
                getline(cin,name); //get the whole line as the name as cin gets only the first word
                doctorsnames.deleteWord(doctorsids.search(id_tobe_edited)->getName());
                doctorsnames.insert(name,doctorsids.search(id_tobe_edited));
                hospitalDoctors[i].setName(name); //set the name to the edited name
            }
            if (choice == 2){
                vector<string> avd;
                cout <<"Enter Doctor's available days: ";
                string inputline; //string that'll be used to obtain the whole line
                cin.ignore(); //clear the buffer to ensure that getline works correctly
                getline(cin, inputline); //function to obtain the whole line and store it in inputline
                stringstream line(inputline);
                string day;
                //The following loop takes every whole word, store it in string day and push it in the vector
                while(line>>day){ //days separated by spaces not commas
                    avd.push_back(day);
                }
                hospitalDoctors[i].setAvailableDays(avd); //edit the available days to the inserted one
            }
            if (choice == 3){
                int apprice;
                cout << "Enter the appointment price: ";
                cin >> apprice; //take the price as input from the user
                hospitalDoctors[i].setPrice(apprice); //edit the price to the entered one
            }
            if (choice == 4){
                string clinic;
                cout <<"Enter the clinic type : ";
                cin.ignore(); //clear the buffer to ensure that getline works correctly
                getline(cin,clinic); //function to obtain the whole line and store it in inputline
                hospitalDoctors[i].setClinicType(clinic);
            }
            if (choice == 5){
                string id;
                cout << "Enter the Doctor's new id : ";
                cin >> id; //take the id as input to give it to the setter
                doctorsnames.deleteWord(doctorsids.search(id_tobe_edited)->getID());
                doctorsnames.insert(id,doctorsids.search(id_tobe_edited));
                hospitalDoctors[i].setID(id); //set the id to the inserted idfrom the user
            }
            cout << "Patient is edited successfully"<<endl;
            return;
        }

    }
    cout << "Doctor with ID " << id_tobe_edited << " not found." << endl;
}

void displaydoctors(){
    cout << "printing all doctors details..."<<endl;
    for (int i = 0 ; i<hospitalDoctors.size();i++){ // iterate over the whole vector
        hospitalDoctors[i].displayinfo(); //display the info of each doctor in the vector
        cout<<endl<<endl; // user-friendly interface
    }
    cout << "This is the end of the doctors list "<<endl;

}


//function that will be used multiple times to check the input
int checkinput(int choice,int first,int last){
    //The while loop is to check if the choice is within the range of the list
    while (choice < first || choice > last ){
        cout << "Please enter a number between "<<first<< " and " <<last <<" inclusively : ";
        cin >> choice;
    }
    return choice; // return the value after exiting the while loop with the right value that's within the range
}