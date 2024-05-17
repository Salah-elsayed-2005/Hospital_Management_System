#include "Diagnosis.h"

void Diagnosis::setAirwayLevel(int airway_observed) {
    /*
     * text              level
     * no free airway       4
     * changed voice        3
     * irritated throat     2
     * free airway          1
     */
    airway_level = airway_observed;
}

void Diagnosis::setBreathingLevel(double spo2) {
    if(spo2 < 80)
        breathing_level = 4;
    else if (spo2 < 89)
        breathing_level = 3;
    else if (spo2 < 94)
        breathing_level = 2;
    else
        breathing_level = 1;
}

void Diagnosis::setPulseLevel(int pulse) {
    if(pulse > 130 || pulse < 30)
        pulse_level = 4;
    else if(pulse > 120 || pulse < 40)
        pulse_level = 3;
    else if(pulse > 100 || pulse < 50)
        pulse_level = 2;
    else
        pulse_level = 1;
}

void Diagnosis::setDisabilityLevel(int agitation_level) {
    /*
     * who ever works on main will make switch case and if the user chooses the text
     * will pass the agitation level to the funciton
     *
     * text                     agitation level    disability level
     * observed pupil dilation      4                   4
     * very agitated                3                   3
     * moderately agitated          2                   2
     * normal pupils                1                   1
     */

    if(agitation_level == 4)
        disability_level = 4;
    else if(agitation_level == 3)
        disability_level = 3;
    else if(agitation_level == 2)
        disability_level = 2;
    else
        disability_level = 1;


}

void Diagnosis::setExposureLevel(bool chemical_contamination, float temperature) {
    if(chemical_contamination)
        exposure_level = 4;
    else if (temperature > 40 || temperature < 32)
        exposure_level = 3;
    else if (temperature > 38 || temperature < 36)
        exposure_level = 2;
    else
        exposure_level = 1;
}

void Diagnosis::setTriageLevel() {
    triage_level = max(airway_level, breathing_level);
    triage_level = max(triage_level, pulse_level);
    triage_level = max(triage_level, disability_level);
    triage_level = max(triage_level, exposure_level);
}

int Diagnosis::getTriageLevel() {
    return triage_level;
}


