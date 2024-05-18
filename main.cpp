#include <iostream>
#include <vector>

#include "Patient.h"
#include "PriorityQueue.h"
using namespace std;
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
            {"Atta", "8621562",20 , 1, "zy elfol", d[0]},
            {"Ali", "8512616",19 , 0, "negro", d[1]},
            {"nabarawy", "54124522",34 , 1, "el3tba 3alnazr", d[2]},
            {"shafey", "8985564",17 , 1, "t3ban ya capten", d[3]},
            {"se7s", "87755151",988 , 1, "whar", d[4]},
    };

    PriorityQueue pq;
    pq.enqueue(p[1]);
    pq.enqueue(p[4]);
    pq.enqueue(p[2]);
    pq.enqueue(p[0]);
    pq.enqueue(p[3]);
    Patient pt;
    while(!pq.isEmpty()){
        pt = pq.dequeue();
    }

}
