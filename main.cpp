#include <iostream>
#include <vector>
#include <sstream> //for the vector of strings available days
#include "Trie.h"
#include "Patient.h"
#include "PriorityQueue.h"
#include "Doctor.h"
#include "Clinics.h"
#include "Functionalities.h"

using namespace std;

vector<Patient>hospitalPatients;
vector<Doctor>hospitalDoctors;
vector<Clinic>hospitalClinics;

Trie<Patient>patientsnames;
Trie<Patient>patientsids;
Trie<Doctor>doctorsnames;
Trie<Doctor>doctorsids;

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


    Patient p[7] = {
            {"Mohamed Atta", "8621562",20 , true, "zy elfol", d[0]},
            {"Ali Ayman ", "8512616",19 , false, "negro", d[1]},
            {"nabarawy FTW", "54124522",34 , true, "el3tba 3alnazr", d[2]},
            {"shafey Elzoz", "8985564",17 , true, "t3ban ya capten", d[3]},
            {"se7s2", "1",988 , true, "whar", d[4]},
            {"se7", "2",988 , true, "whar", d[4]},
            {"se7s", "3",988 , true, "whar", d[4]},
    };
    for (auto & it :p) {
        hospitalPatients.push_back(it);
    }
    for (auto it:hospitalPatients) {
        Patient*toinsert=new Patient(it.getName(), it.getID(), it.getAge(), it.getGender(), it.getConditionDescription(), it.getDiagnosis());
        patientsnames.insert(toinsert->getName(),toinsert);
    }
    for (auto &it:hospitalPatients) {
        Patient*toinsert=new Patient(it.getName(), it.getID(), it.getAge(), it.getGender(), it.getConditionDescription(), it.getDiagnosis());
        patientsids.insert(toinsert->getID(), toinsert);
    }



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

    for (auto & it :doctors) {
        hospitalDoctors.push_back(it);
    }
    for (auto it:hospitalDoctors) {
        Doctor*toinsert=new Doctor(it.getName(),it.getAvailableDays(),it.getPrice(),it.getClinicType(),it.getID());
        doctorsnames.insert(toinsert->getName(),toinsert);
    }
    for (auto it:hospitalDoctors) {
        Doctor*toinsert=new Doctor(it.getName(),it.getAvailableDays(),it.getPrice(),it.getClinicType(),it.getID());
        doctorsids.insert(toinsert->getID(),toinsert);
    }

    Clinic pediatrics;
    for (auto it:hospitalPatients) {
        pediatrics.addtoWaiting(it);
    }
    pediatrics.setDoctor(doctors[0]);
    hospitalClinics.push_back(pediatrics);
    startingmenu();


} // end of main function


