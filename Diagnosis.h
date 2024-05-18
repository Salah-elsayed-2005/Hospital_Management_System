//#ifndef DIAGNOSIS_H
//#define DIAGNOSIS_H

#include <iostream>
using namespace std;

class Diagnosis {
    int airway_level;
    int breathing_level;
    int pulse_level;
    int disability_level;
    int exposure_level;

    int triage_level;

public:
    Diagnosis();
    Diagnosis(int, int, int, int ,int);
    void setAirwayLevel(int airway_observed);
    void setBreathingLevel(double);
    void setPulseLevel(int);
    void setDisabilityLevel(int);
    void setExposureLevel(bool, float);

    void setTriageLevel();

    int getTriageLevel();
};

//#endif