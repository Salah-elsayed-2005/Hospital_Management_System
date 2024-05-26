//
// Created by Fouad Hashesh on 24/05/2024.
//

#ifndef UNTITLED1_GUI_H
#define UNTITLED1_GUI_H


#include <gtk/gtk.h>
#include <vector>
#include <string>
#include "CityGraph.h"
#include "utility"
#include "CityGraph.h"
#include "Clinics.h"
#include "Patient.h"


// Function to activate the GTK application and set up the main window
void activate(GtkApplication *app, gpointer user_data);

// Callback functions for the buttons
void on_start_button_clicked(GtkWidget *widget, gpointer data);
void on_credits_button_clicked(GtkWidget *widget, gpointer data);
void emergancy_requests(GtkWidget *widget, gpointer data);

// Callback functions for the main menu buttons
void edit_patients(GtkWidget *widget, gpointer data);
void open_add_patient_window(GtkWidget *widget, gpointer data);
void open_add_doctor_window(GtkWidget *widget, gpointer data);
void edit_doctors(GtkWidget *widget, gpointer data);
void display_patients(GtkWidget *widget, gpointer data);
void display_doctors(GtkWidget *widget, gpointer data);
void display_emergencies(GtkWidget *widget, gpointer data);
void on_destination_changed(GtkComboBox *combo, gpointer data);
void on_emergency_selected(GtkComboBox *combo, gpointer data);
void display_patients_layout(GtkApplication *app);
void display_doctors_layout(GtkApplication *app);
void reserve_clinic(GtkWidget *widget, gpointer data);
void display_clinic_schedule(GtkWidget *widget, gpointer data);
void go_back_to_main_menu(GtkWidget *widget, gpointer data);
void save_doctor_data(GtkWidget *widget, gpointer data);
void save_patient_data(GtkWidget *widget, gpointer data);
void open_delete_doctor_window(GtkWidget *widget, gpointer data);
void open_delete_patient_window(GtkWidget *widget, gpointer data);
void delete_patient(GtkWidget *widget, gpointer data);
void delete_doctor(GtkWidget *widget, gpointer data);
void populate_patient_dropdown(GtkWidget *combo, const std::vector<std::string>& patient_names);

// Function to populate the dropdown with patient/doctor names
void populate_patient_dropdown(GtkWidget *combo, const std::vector<std::string>& patient_names);
void populate_doctor_dropdown(GtkWidget *combo);

// Callback function to display selected patient's/doctor's data
void on_patient_selected(GtkComboBox *combo, gpointer data);
void on_doctor_selected(GtkComboBox *combo, gpointer data);
void on_emergency_selected(GtkComboBox *combo, gpointer data);

void create_clinic_objects();

void open_reserve_clinic_window(GtkWidget *widget, gpointer data);
void on_add_button_clicked(GtkWidget *widget, gpointer data);
void populate_clinic_dropdown(GtkComboBoxText *combo);
void populate_patient_dropdown(GtkComboBoxText *combo);
Patient searchByName(const std::vector<Patient>& patient, string pat_name);
void on_clinic_selected(GtkComboBox *combo, gpointer data);
void open_clinic_schedule_window(GtkWidget *widget, gpointer data);



#endif //UNTITLED1_GUI_H
