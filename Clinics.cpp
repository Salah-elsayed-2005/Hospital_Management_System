#include "Clinics.h"
//#include "PriorityQueue.h"
using namespace std;

void Clinic ::setType(string s) {type = s;}
void Clinic ::setDoctor(Doctor & d) {doctor = d;}
void Clinic ::addtoWaiting(Patient p) {waitingList.enqueue(p); }

void Clinic ::removefromWaiting() {waitingList.dequeue();}
void Clinic ::printInfo() {
    cout << "Type is : " << type <<endl
         << "Doctor is : "<<doctor.getName()<<endl
         << "Current waiting List is : "<<endl;
    PriorityQueue toprint=waitingList;
    while(!toprint.isEmpty()){
        cout<<toprint.dequeue().getName()<<endl;
    }
}
string Clinic ::getType() {return type;}
Doctor Clinic ::getDoctor() {return doctor;}
PriorityQueue Clinic :: getWaitingList(){return waitingList;}