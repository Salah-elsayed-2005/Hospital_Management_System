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

void addPatient();
void removePatient();
void addDoctor();
void removeDoctor();
void clinicmenu();
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
    for (auto &it : p) {
        clinic.addtoWaiting(it);
    }
    clinic.printInfo();


    cout<<"Welcome To Fla7een El3asema Hospital "<<endl
        <<"Please Choose your desired option : "<<endl;

    cout<<"1-Add patient to Database"<<endl
        <<"2-Remove patient from Database"<<endl
        <<"3-Add doctor to the Database"<<endl
        <<"4-Remove doctor from the Database"<<endl
        <<"5-Update Clinic info"<<endl // clinic functions
        <<"For further Update";
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
}
void removePatient();
void addDoctor();
void removeDoctor();