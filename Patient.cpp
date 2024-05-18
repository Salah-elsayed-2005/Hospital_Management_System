#include "Patient.h"

Patient::Patient() {

}

Patient::Patient(string _name, string _id, int _age, bool _gender, string _cond_descr, Diagnosis _diagnosis) {
    name = _name;
    id = _id;
    age = _age;
    gender = _gender;
    condition_description = _cond_descr;
    diagnosis = _diagnosis;
    urgency_level = diagnosis.getTriageLevel();
}

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

