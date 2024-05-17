#include <iostream>
#include "Diagnosis.h"
using namespace std;

class Patient {
    string name;
    string id;
    int age;
    bool gender;
    string condition_description;
    Diagnosis diagnosis;

    int urgency_level;

public:
    string getName();
    string getId();
    int getAge();
    bool getGender();
    string getConditionDescription();
    Diagnosis getDiagnosis();
    int getUrgencyLevel();

    void setName(string&);
    void setId(string&);
    void setAge(int&);
    void setGender(bool&);
    void setConditionDescription(string&);
    void setDiagnosis(Diagnosis&);


    bool operator >(Patient& obj) const{
        return this->urgency_level > obj.urgency_level;
    }
    bool operator <(Patient& obj) const{
        return this->urgency_level < obj.urgency_level;
    }
    bool operator ==(Patient& obj) const{
        return this->urgency_level == obj.urgency_level;
    }
};
