#include <iostream>
#include <vector>
#include <sstream> //for the vector of strings available days
#include "Trie.h"
#include "Patient.h"
#include "PriorityQueue.h"
#include "Doctor.h"
#include "Clinics.h"
#include "Functionalities.h"
#include "Doctor.h"
#include "gui.h"

using namespace std;

vector<Patient>hospitalPatients;
vector<Doctor>hospitalDoctors;
vector<Clinic>hospitalClinics;

Trie<Patient>patientsnames;
Trie<Patient>patientsids;
Trie<Doctor>doctorsnames;
Trie<Doctor>doctorsids;
Trie<Clinic>clinictypes;

int main(int argc, char **argv) {
    GtkApplication *app;
    int status;
    create_clinic_objects();

    app = gtk_application_new("com.example.GtkApplication", G_APPLICATION_FLAGS_NONE);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}

