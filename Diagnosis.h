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

    void setAirwayLevel(int);
    void setBreathingLevel(double);
    void setPulseLevel(int);
    void setDisabilityLevel(int);
    void setExposureLevel(bool, float);

    void setTriageLevel();

    int getTriageLevel();
};

