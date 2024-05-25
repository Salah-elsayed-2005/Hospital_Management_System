#include "Clinics.h"
using namespace std;

Clinic :: Clinic(){}
Clinic :: Clinic(string c, PriorityQueue p,vector<Doctor> d):type(c), waitingList(p),doctor(d) {}

void Clinic ::setType(string s) {type = s;}
void Clinic ::setDoctor(vector<Doctor> d) {doctor = d;}
void Clinic ::addtoWaiting(Patient p) {waitingList.enqueue(p); }
void Clinic ::removefromWaiting() {waitingList.dequeue();}
void Clinic ::printInfo() {
    cout << "Type is : " << type <<endl;
    cout << "The list of doctors available : "<<endl;
    for (auto i = 0 ; i<doctor.size() ; i++){
        cout <<doctor[i].getName();
        cout<<endl;
    }
    cout << "Current waiting List is : "<<endl;
    PriorityQueue toprint=waitingList;
    while(!toprint.isEmpty()){
        cout<<toprint.dequeue().getName()<<endl;
    }
    /*cout<<"Avalaible days : ";
    for (auto it :doctor.getAvailableDays()) {
        cout<<it<<"  ";
    }
    cout<<endl;*/
}

string Clinic ::getType() {return type;}
vector<Doctor> Clinic ::getDoctor() {return doctor;}
PriorityQueue Clinic :: getWaitingList(){return waitingList;}