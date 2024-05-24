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
#include "CityGraph.h"
using namespace std;
extern vector<Patient>hospitalPatients;
extern vector<Doctor>hospitalDoctors;
extern vector<Clinic>hospitalClinics;
extern Trie<Patient>patientsnames;
extern Trie<Patient>patientsids;
extern Trie<Doctor>doctorsnames;
extern Trie<Doctor>doctorsids;
extern Trie<Clinic>clinictypes;

#if defined(_WIN32) || defined(_WIN64)
const std::string CLEAR_COMMAND = "cls";
#else
const std::string CLEAR_COMMAND = "clear";
#endif
bool endOfProgram= false;
bool backToTheMainMenu=false;
Date today;//global variable for today's date
Clinic*searchCLinic(string clinictype) {
    if (clinictypes.search(clinictype))
        return clinictypes.search(clinictype);
    else
        return nullptr;
}

bool checkBack(){       //check if the user want to back to the last page
    short back=1;
    do {
        cout << "\n\n[1] Back to the last page" << endl << "[2] Back to the main menu\n\n";
        cout << "Please enter your choice : ";
        cin >> back;
        if (back == 2)
            backToTheMainMenu = true;
    }while(back!=1 && back!=2); //validate input
    return (back==2);
}

/*
 Checkback() function is used all over the other options to check if the user wants to either go back to the previous menu or to go back to the main menu
 It's only used of there exists a previous menu not the main menu
 */
bool checkClose(){  //check if the user want to close the program
    short back=1;
    do {
        cout << "\n\n[1] Back to the last page" << endl << "[2] Close the program\n\n";
        cout << "Please enter your choice : ";
        cin >> back;
        if (back == 2)
            endOfProgram = true;
    }while(back!=1 && back!=2); //validate input
    return (back==2);
}

void creditsmenu(){
    cout<<"--------------------------------------------Thanks for using our program---------------------------------------------\n\n";
    cout<<"-------------------------------------------------------Credits-------------------------------------------------------\n\n";
    cout<<"--------------------------------------------------Salah eldin Elsayed------------------------------------------------\n\n";
    cout<<"-----------------------------------------------------Omar Nabarawy---------------------------------------------------\n\n";
    cout<<"--------------------------------------------------Abdulrahman Abogendia----------------------------------------------\n\n";
    cout<<"-----------------------------------------------------Fouad Hashesh---------------------------------------------------\n\n";
    cout<<"----------------------------------------------------Mohamed Farouk---------------------------------------------------\n\n";
    cout<<"-------------------------------------Under the Supervision of Dr. Fatma Elshehaby------------------------------------\n\n";
}
void mainmenu(){
    system(CLEAR_COMMAND.c_str()); //clear screen
    short choice=1;
    do{
        cout<<"1-Edit Database\n2-Display Info\n3-Reserve a clinic\n4-Emergency Request\n5-Close The program"<<endl;
        cout<<"\nPlease enter your choice : ";
        cin>>choice;
        if (choice==1)
            editmenu();
        if (choice==2)
            displaymenu();
        if (choice==3)
            clinicmenu();
        if (choice==4)
            emergencymenu();
        system(CLEAR_COMMAND.c_str()); //clear screen
        if(backToTheMainMenu) { //check if the user want to back to the main menu
            choice = 1;
            backToTheMainMenu=false;
        }
        if(endOfProgram)    //if the user want to end the program
            break;
    }while(choice!=5);
    creditsmenu();
    system("pause>0");

}

void editmenu(){
    system(CLEAR_COMMAND.c_str()); //clear screen
    short choice;
    do{
        cout<<"===Edit menu=== "<<endl;
        cout<<"1-Edit Doctor Info\n2-Add Doctor\n3-Remove Doctor\n4-Edit Patient Info\n5-Add Patient\n6-Remove Patient\n ";
        cout<<"Enter your choice : ";
        cin>>choice;
        if (choice<1 || choice > 6) {
            system(CLEAR_COMMAND.c_str());
            continue;
        }
        if (choice == 1) {
            string input;
            cout << "Enter the id or name of the Doctor you want to edit : ";
            cin>> input;

            if (searchDoctor_byname(input)|| searchDoctor_byid(input)){
                input= searchDoctor_byname(input)? searchDoctor_byname(input)->getID(): searchDoctor_byid(input)->getID();
                editDoctor(input);
            } else
                cout<<"ID not found"<<endl;
        }
        else if (choice == 2) {
            addDoctor();
        }
        else if (choice==3){
            string input;
            cout << "Enter the id or name of the Doctor you want to remove : ";
            cin>> input;

            if (searchDoctor_byname(input)|| searchDoctor_byid(input)){
                input= searchDoctor_byname(input)? searchDoctor_byname(input)->getID(): searchDoctor_byid(input)->getID();
                removeDoctor(input);
            } else
                cout<<"ID not found"<<endl;
        }
        else if (choice==4){
            string input;
            cout << "Enter the id or name of the patient you want to edit : ";
            cin>> input;

            if (searchPatient_byName(input)|| searchPatient_byid(input)){
                input= searchPatient_byName(input) ? searchPatient_byName(input)->getID() : searchPatient_byid(input)->getID();
                editPatient(input);
            } else
                cout<<"ID not found"<<endl;
        }
        else if (choice==5){
            addPatient();
        }
        else if (choice==6){
            string input;
            cout << "Enter the id or name of the patient you want to remove : ";
            cin>> input;

            if (searchPatient_byName(input)|| searchPatient_byid(input)){
                input= searchPatient_byName(input) ? searchPatient_byName(input)->getID() : searchPatient_byid(input)->getID();
                removePatient(input);
            } else
                cout<<"ID not found"<<endl;
        }
        if(choice>0 && choice<7)
            checkBack();    //check if the user want to back to the last menu

    }while(!backToTheMainMenu); //check if the user want to back to the main menu
}

void displaymenu(){
    system(CLEAR_COMMAND.c_str()); //clear screen
    short choice;
    do{
        cout<<"1-Display All clinics info"<<endl
            <<"2-Display All Doctors info"<<endl
            <<"3-Display All Patients info"<<endl
            <<"4-Display a clinic info"<<endl
            <<"5-Display a Doctor info"<<endl
            <<"6-Display a Patient info"<<endl;
        cout<<"Please Enter Your choice : ";
        cin>>choice;
        if (choice<1 || choice > 6) {
            system(CLEAR_COMMAND.c_str());
            continue;
        }
        if (choice == 1) {  //add member
            cout<<"A7a"<<endl;
//        displayclinics();// NOT yet implemented
        }
        else if (choice == 2) {     //remove member
            addDoctor();
        }
        else if (choice==3){
            displaydoctors();
        }
        else if (choice==4){
            cout<<"A7a"<<endl;
        }
        else if (choice==5){
            string input;
            cout << "Enter the id or name of the Doctor you want to View : ";
            cin>> input;
            if (searchDoctor_byname(input) || searchDoctor_byid(input)){
                searchDoctor_byname(input)? searchDoctor_byname(input)->displayinfo(): searchDoctor_byid(input)->displayinfo();
            }
            else
                cout<<"ID not found"<<endl;
        }
        else if (choice==6){
            string input;
            cout << "Enter the id or name of the patient you want to View : ";
            cin>> input;
            if (searchPatient_byName(input)|| searchPatient_byid(input)){
                searchPatient_byName(input) ? searchPatient_byName(input)->displayinfo()  : searchPatient_byid(input)->displayinfo()  ;
            } else
                cout<<"ID not found"<<endl;
        }
        if(choice>0 && choice<7)
            checkBack();    //check if the user want to back to the last menu

    }while(!backToTheMainMenu); //check if the user want to back to the main menu
 }
void clinicmenu(){
    system(CLEAR_COMMAND.c_str()); //clear screen
    short choice;
    do{
        cout << "===Clinic Menu===\n";
        cout << "1- Reserve a Clinic\n";
        cout << "2- Display Clinic Schedule\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice<1 || choice > 2) {
            system(CLEAR_COMMAND.c_str());
            continue;
        }
        if (choice == 1) {
            reserveClinic();
        }
        else if (choice == 2) {
            displayClinicSchedule(); // lesa htt3mel
        }
        if(choice>0 && choice<3)
            checkBack();    //check if the user want to back to the last menu

    }while(!backToTheMainMenu); //check if the user want to back to the main menu

}
//Patients' funcions

//function to search patient by id
Patient* searchPatient_byid(string id){

    if (patientsids.search(id)){
        return patientsnames.search(id);
    }
    else
        return nullptr;

}

Patient* searchPatient_byName(string name){
    if(patientsnames.search(name)) {
        return patientsnames.search(name);
    }
    else
        return nullptr;
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
    patientsnames.insert(patient.getID(), &patient);
}

//function to remove the patient from the vector
void removePatient(string id_toberemoved){
    for (int i = 0; i < hospitalPatients.size() ; i++ ){ //iterate over the whole vector
        if (id_toberemoved == hospitalPatients[i].getID() ){  //if condition to get the patient
            // with the id to be removed
            cout << "The patient is being removed... "<< endl;
            patientsnames.deleteWord(hospitalPatients[i].getName());
            patientsids.deleteWord(hospitalPatients[i].getID());
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
        if(id_tobe_edited == hospitalPatients[i].getID()){
            cout << "===Edit menu===\n";
            cout << "what do you want to edit in the patient with id : "<< id_tobe_edited<<endl;
            cout << "1- Patient's name\n2- Patient's id\n3- Patient's age\n4- Patient's gender\n";
            cout << "5- Condition description\n";
            cout <<"6- Diagnosis level\nEnter your choice : ";
            cin >> choice;
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
                patientsnames.deleteWord(patientsids.search(id_tobe_edited)->getID());
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
    patientsnames.print();
    cout << "This is the end of the patients list "<<endl;
}


//Doctors' functions

Doctor* searchDoctor_byid(string id){
    if (doctorsids.search(id))
        return doctorsnames.search(id);
    else
        return nullptr;
}

Doctor* searchDoctor_byname(string name){
    if (doctorsnames.search(name)) {
        return doctorsnames.search(name);
    }
    else
        return nullptr;
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

    cout << "\nClinic type : ";
    cin >> clinicType;
    cout << "\nDoctor id : ";
    cin >> id;
    Doctor doc(name,availableDays,clinicType,id);
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
            cout << "1-Doctor's name\n2-Doctor's available days \n3-clinic type\n4-Doctor's id : ";
            cin >> choice;
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
                string clinic;
                cout <<"Enter the clinic type : ";
                cin.ignore(); //clear the buffer to ensure that getline works correctly
                getline(cin,clinic); //function to obtain the whole line and store it in inputline
                hospitalDoctors[i].setClinicType(clinic);
            }
            if (choice == 4){
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
    doctorsnames.print();
    cout << "This is the end of the doctors list "<<endl;

}

# if 0
//function that will be used multiple times to check the input
int checkinput(int choice,int first,int last){
    //The while loop is to check if the choice is within the range of the list
    while (choice < first || choice > last ){
        cout << "Please enter a number between "<<first<< " and " <<last <<" inclusively : ";
        cin >> choice;
    }
    return choice; // return the value after exiting the while loop with the right value that's within the range
}
#endif
void reserveClinic() {
    string type;
    cout<<"Enter Type of the Clinic : "<<endl;
    cin>>type;
    if (searchCLinic(type)) {
            bool isavailable= false;
        for (auto it: searchCLinic(type)->getDoctor().getAvailableDays()) {
            if (it==today.getcurrentday())
                isavailable= true;
        }
        if (isavailable) {
            string input;
            cout << "Enter the id or name of the Patient : ";
            cin >> input;
            if (searchPatient_byid(input) || searchPatient_byName(input)) {
                searchPatient_byName(input) ? searchCLinic(type)->addtoWaiting(*searchPatient_byName(input))
                                            : searchCLinic(type)->addtoWaiting(*searchPatient_byid(input));
                editDoctor(input);
            } else
                cout << "ID not found" << endl;
        } else
            cout<<"Clinic isn't Available for Reserving Today "<<endl;
    }
    else cout<<"Clinic is not found "<<endl;
}
void displayClinicSchedule() {
    string t;
    cout<<"Enter The type of Clinic : ";
    cin>>t;
    if (clinictypes.search(t)) {
        for (auto it: clinictypes.search(t)->getDoctor().getAvailableDays()) {
            cout << it << " " << endl;
        }
    } else
        cout<<"Clinic Not found "<<endl;
}
void emergencymenu(){
    system(CLEAR_COMMAND.c_str()); //clear screen
    short choice;
    do{
        CityGraph Metropolis;
        cout << "Choose Emergency address: \n\n";

        cout << "1. Maple Grove Residences" << endl;
        cout << "2. Willow Heights" << endl;
        cout << "3. Sunset Pines Apartments" << endl;
        cout << "4. Cedar Ridge Villas" << endl;
        cout << "5. Lakeside Manor" << endl;
        cout << "6. Harbor View Estates" << endl;
        cout << "7. Oakwood Park Residences" << endl;
        cout << "8. Riverstone Apartments" << endl;
        cout << "9. Meadowlark Homes" << endl << endl;

        cout << "Your Choice: ";
        string address;

        cin >> choice;
        if (choice<1 || choice > 9) {
            system(CLEAR_COMMAND.c_str());
            continue;
        }
        switch (choice) {
            case 1:
                address = "Maple Grove Residences";
                break;
            case 2:
                address = "Willow Heights";
                break;
            case 3:
                address = "Sunset Pines Apartments";
                break;
            case 4:
                address = "Cedar Ridge Villas";
                break;
            case 5:
                address = "Lakeside Manor";
                break;
            case 6:
                address = "Harbor View Estates";
                break;
            case 7:
                address = "Oakwood Park Residences";
                break;
            case 8:
                address = "Riverstone Apartments";
                break;
            case 9:
                address = "Meadowlark Homes";
                break;

        }
        pair<int, string> route = Metropolis.shortestPath(address);

        cout << "ETA : " << route.first << " mins" << endl;
        cout << "Shortest route for Ambulance : " << route.second << endl;
        if(choice>0 && choice<10)
            checkBack();    //check if the user want to back to the last menu

    }while(!backToTheMainMenu); //check if the user want to back to the main menu
}