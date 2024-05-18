#include "Clinics.h"
//#include "PriorityQueue.h"
using namespace std;

void Clinic ::setType(string s) {type = s;}
void Clinic ::setDoctor(Doctor *& d) {doctor = d;}
void Clinic ::addtoWaiting(Patient p) {waiting.enqueue(p); }

void Clinic ::removefromWaiting() {waiting.dequeue();} // x
void Clinic ::printInfo() {
    cout << "Type is : " << type ;
//missing doctor
//missing waitin list
}

string Clinic ::getType() {return type;}
Doctor* Clinic ::getDoctor() {return doctor;}
PriorityQueue Clinic :: getWaitingList(){return waiting;}