#include "Patient.h"

string Patient::getName() {
    return name;
}

string Patient::getId() {
    return id;
}

int Patient::getAge() {
    return age;
}

bool Patient::getGender() {
    return gender;
}

string Patient::getConditionDescription() {
    return condition_description;
}

Diagnosis Patient::getDiagnosis() {
    return diagnosis;
}

int Patient::getUrgencyLevel() {
    return urgency_level;
}



void Patient::setName(string& _name) {
    name = _name;
}

void Patient::setId(string & _id) {
    id = _id;
}

void Patient::setAge(int & _age) {
    age = _age;
}

void Patient::setGender(bool & _gender) {
    gender = _gender;
}

void Patient::setConditionDescription(string & _description) {
    condition_description = _description;
}

void Patient::setDiagnosis(Diagnosis & _diagnosis) {
    diagnosis = _diagnosis;
    diagnosis.setTriageLevel();
    urgency_level = diagnosis.getTriageLevel();
}




