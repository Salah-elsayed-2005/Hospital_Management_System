#include "gui.h"
#include <gtk/gtk.h>
#include <vector>
#include <string>
#include <sstream>
#include "PriorityQueue.h"
#include "Doctor.h"
#include "Clinics.h"
#include "Functionalities.h"
#include "Doctor.h"
#include "utility"
#include "CityGraph.h"
#include "Patient.h"

std::vector<Patient> patients_vector ={};
std::vector<Doctor> doctors_vector ={};
std::vector<Clinic> clinics_vector ={};


// Dummy data
std::vector<std::string> patient_names = {};

std::vector<std::string> patient_data = {};

std::vector<std::string> doctor_names = {};

std::vector<std::string> doctor_data ={};

std::vector<std::string> emergency_names = {
        "Maple Grove Residences",
        "Willow Heights" ,
        "Sunset Pines Apartments" ,
        "Cedar Ridge Villas" ,
        "Lakeside Manor" ,
        "Harbor View Estates" ,
        "Oakwood Park Residences" ,
        "Riverstone Apartments" ,
        "Meadowlark Homes"

};



void create_clinic_objects(){
    static std::string clinics[] = {"IM", "Cardio", "Surgery", "Ophthalmology", "Gynecology", "ENT", "Dermatology", "Ortho", "Dental", "Radiology"};
    int num_clinics = sizeof(clinics) / sizeof(clinics[0]);

    for (int i = 0; i < num_clinics; ++i) {
        Clinic clinic_obj;
        clinic_obj.setType(clinics[i]);
        clinics_vector.push_back(clinic_obj);
    }

}


void show_credits(GtkWidget *widget, gpointer data) {
    GtkWidget *parent_window = GTK_WIDGET(data);
    GtkWidget *dialog = gtk_message_dialog_new(GTK_WINDOW(parent_window),
                                               GTK_DIALOG_MODAL,
                                               GTK_MESSAGE_INFO,
                                               GTK_BUTTONS_OK,
                                               "CSE 121 Hospital Management System Project\n\nThis project was developed by:\n\n"
                                               "22-101188\t SalahEldin El-Sayed\n"
                                               "22-101194\t Abdulrahman Abougendia\n"
                                               "22-101062\t Fouad Hashesh\n"
                                               "22-xxxxxx\t Omar Nabarawy\n"
                                               "22-101284\t Mohamed Farouk\n");
    gtk_window_set_transient_for(GTK_WINDOW(dialog), GTK_WINDOW(parent_window));
    g_signal_connect(dialog, "response", G_CALLBACK(gtk_window_destroy), NULL);
    gtk_widget_show(dialog);
}

void create_main_menu(GtkApplication *app) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hospital Management System");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    // Add buttons to the grid
    GtkWidget *button = gtk_button_new_with_label("Add Doctor");
    g_signal_connect(button, "clicked", G_CALLBACK(open_add_doctor_window), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 2, 1);

    button = gtk_button_new_with_label("Add Patient");
    g_signal_connect(button, "clicked", G_CALLBACK(open_add_patient_window), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 2, 1);

    button = gtk_button_new_with_label("Delete Patient");
    g_signal_connect(button, "clicked", G_CALLBACK(open_delete_patient_window), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 2, 1);

    button = gtk_button_new_with_label("Delete Doctor");
    g_signal_connect(button, "clicked", G_CALLBACK(open_delete_doctor_window), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 2, 1);

    button = gtk_button_new_with_label("Display Patients");
    g_signal_connect(button, "clicked", G_CALLBACK(display_patients), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 2, 1);

    button = gtk_button_new_with_label("Display Doctors");
    g_signal_connect(button, "clicked", G_CALLBACK(display_doctors), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 5, 2, 1);

    button = gtk_button_new_with_label("Reserve Clinic");
    g_signal_connect(button, "clicked", G_CALLBACK(open_reserve_clinic_window), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 6, 2, 1);

    button = gtk_button_new_with_label("Clinic Schedule");
    g_signal_connect(button, "clicked", G_CALLBACK(open_clinic_schedule_window), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 7, 2, 1);

    button = gtk_button_new_with_label("Emergency requests");
    g_signal_connect(button, "clicked", G_CALLBACK(display_emergencies), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 8, 2, 1);

    button = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(g_application_quit), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 9, 2, 1);

    gtk_widget_show(window);
}

void on_start_button_clicked(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    GtkWindow *current_window = GTK_WINDOW(gtk_widget_get_root(widget));
    gtk_window_destroy(current_window);
    create_main_menu(app);
}

void on_credits_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *parent_window = GTK_WIDGET(data);
    show_credits(parent_window, NULL);
}

// Declare the DatabaseManager instance globally if you want to access it across different functions.

// Load data into the vectors when the application starts
void activate(GtkApplication *app, gpointer user_data) {
    // Load data from the database


    // Existing code for creating the window and setting up the main menu
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Hospital Management System");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    GtkWidget *label = gtk_label_new("Date: 23-05-2024");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_START);
    gtk_widget_set_valign(label, GTK_ALIGN_START);

    GtkWidget *button = gtk_button_new_with_label("Start");
    gtk_widget_set_hexpand(button, TRUE);
    gtk_widget_set_vexpand(button, TRUE);
    g_signal_connect(button, "clicked", G_CALLBACK(on_start_button_clicked), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 1, 2, 1);

    button = gtk_button_new_with_label("Credits");
    gtk_widget_set_hexpand(button, TRUE);
    gtk_widget_set_vexpand(button, TRUE);
    g_signal_connect(button, "clicked", G_CALLBACK(on_credits_button_clicked), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 2, 1);

    button = gtk_button_new_with_label("Quit");
    g_signal_connect_swapped(button, "clicked", G_CALLBACK(g_application_quit), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 2, 1);

    gtk_widget_show(window);
}

void edit_patients(GtkWidget *widget, gpointer data) {
    g_print("Edit Patients button clicked\n");
}
void edit_doctors(GtkWidget *widget, gpointer data) {
    GtkWidget *window = gtk_application_window_new(GTK_APPLICATION(data));
    gtk_window_set_title(GTK_WINDOW(window), "Edit Doctors");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    GtkWidget *label = gtk_label_new("Select Doctor to Edit");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);

    GtkWidget *combo = gtk_combo_box_text_new();
    populate_doctor_dropdown(combo);
    gtk_grid_attach(GTK_GRID(grid), combo, 0, 1, 2, 1);

    g_signal_connect(combo, "changed", G_CALLBACK(on_doctor_selected), window);

    GtkWidget *button = gtk_button_new_with_label("Main Menu");
    g_signal_connect(button, "clicked", G_CALLBACK(go_back_to_main_menu), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 2, 1);

    gtk_widget_show(window);
}

void display_patients(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    display_patients_layout(app);
}

void populate_patient_dropdown(GtkWidget *combo, const std::vector<std::string>& patient_names) {
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(combo));
    for (const std::string& name : patient_names) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), name.c_str());
    }
}





void on_patient_selected(GtkComboBox *combo, gpointer data) {
    GtkWidget *text_view = GTK_WIDGET(data);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    int index = gtk_combo_box_get_active(combo);
    if (index >= 0 && index < static_cast<int>(patient_data.size())) {
        gtk_text_buffer_set_text(buffer, patient_data[index].c_str(), -1);
    }
}


void populate_doctor_dropdown(GtkWidget *combo) {
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(combo));
    for (const std::string& name : doctor_names) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), name.c_str());
    }
}




void on_doctor_selected(GtkComboBox *combo, gpointer data) {
    GtkWidget *text_view = GTK_WIDGET(data);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    int index = gtk_combo_box_get_active(combo);
    if (index >= 0 && index < static_cast<int>(doctor_data.size())) {
        gtk_text_buffer_set_text(buffer, doctor_data[index].c_str(), -1);
    }
}

void display_patients_layout(GtkApplication *app) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Display Patients");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    GtkWidget *label = gtk_label_new("Select Patient");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);

    GtkWidget *combo = gtk_combo_box_text_new();
    populate_patient_dropdown(combo, patient_names);
    gtk_grid_attach(GTK_GRID(grid), combo, 0, 1, 2, 1);

    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);

    GtkWidget *scroll_win = gtk_scrolled_window_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll_win), text_view);
    gtk_widget_set_vexpand(scroll_win, TRUE);
    gtk_widget_set_hexpand(scroll_win, TRUE);
    gtk_grid_attach(GTK_GRID(grid), scroll_win, 0, 2, 2, 1);

    g_signal_connect(combo, "changed", G_CALLBACK(on_patient_selected), text_view);

    GtkWidget *button = gtk_button_new_with_label("Main Menu");
    g_signal_connect(button, "clicked", G_CALLBACK(go_back_to_main_menu), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 2, 1);

    gtk_widget_show(window);
}

void display_doctors_layout(GtkApplication *app) {
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Display Doctors");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    GtkWidget *label = gtk_label_new("Select Doctor");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);

    GtkWidget *combo = gtk_combo_box_text_new();
    populate_doctor_dropdown(combo);
    gtk_grid_attach(GTK_GRID(grid), combo, 0, 1, 2, 1);

    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);

    GtkWidget *scroll_win = gtk_scrolled_window_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll_win), text_view);
    gtk_widget_set_vexpand(scroll_win, TRUE);
    gtk_widget_set_hexpand(scroll_win, TRUE);
    gtk_grid_attach(GTK_GRID(grid), scroll_win, 0, 2, 2, 1);

    g_signal_connect(combo, "changed", G_CALLBACK(on_doctor_selected), text_view);

    GtkWidget *button = gtk_button_new_with_label("Main Menu");
    g_signal_connect(button, "clicked", G_CALLBACK(go_back_to_main_menu), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 2, 1);

    gtk_widget_show(window);
}

void display_emergencies_layout(GtkApplication *app) {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *label;
    GtkWidget *combo;
    GtkWidget *text_view;
    GtkWidget *scroll_win;
    GtkWidget *button;
    GtkWidget *image;

    // Create a new window
    window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Emergency Requests");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a grid
    grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    // Add label for "Select Emergency"
    label = gtk_label_new("Choose Emergency address:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);

    // Add a combo box (dropdown) for emergency selection
    combo = gtk_combo_box_text_new();
    for (const std::string& name : emergency_names) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), name.c_str());
    }
    gtk_grid_attach(GTK_GRID(grid), combo, 0, 1, 2, 1);

    // Add a text view for displaying emergency details
    text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);
    scroll_win = gtk_scrolled_window_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll_win), text_view);
    gtk_widget_set_vexpand(scroll_win, TRUE);
    gtk_widget_set_hexpand(scroll_win, TRUE);
    gtk_grid_attach(GTK_GRID(grid), scroll_win, 0, 2, 2, 1);

    // Add the image for the route
    image = gtk_image_new_from_file("paths.png");
    gtk_widget_set_size_request(image, 450, 475);
    gtk_grid_attach(GTK_GRID(grid), image, 2, 0, 1, 6);

    // Connect the signal for combo box selection change
    g_signal_connect(combo, "changed", G_CALLBACK(on_emergency_selected), text_view);

    // Add a "Main Menu" button
    button = gtk_button_new_with_label("Main Menu");
    g_signal_connect(button, "clicked", G_CALLBACK(go_back_to_main_menu), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 2, 1);

    // Show the window
    gtk_widget_show(window);
}

void on_emergency_selected(GtkComboBox *combo, gpointer data) {
    CityGraph Metropolis;
    GtkWidget *text_view = GTK_WIDGET(data);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    int index = gtk_combo_box_get_active(combo);


    std::stringstream ss;


    if (index >= 0 && index < static_cast<int>(emergency_names.size())) {

        std::pair<int, std::string> route = Metropolis.shortestPath(emergency_names[index].c_str());
        ss  << "ETA : " << route.first << " mins"<<"\n\n" << "Shortest route for Ambulance : " << route.second;
        std::string result = ss.str();



        gtk_text_buffer_set_text(buffer, result.c_str(), -1);
    }
}


void open_add_patient_window(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Add Patient");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    GtkWidget *label = gtk_label_new("ID:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
    GtkWidget *entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 0, 3, 1);
    g_object_set_data(G_OBJECT(window), "id_entry", entry);

    label = gtk_label_new("Name:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 1, 1, 1);
    entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), entry, 1, 1, 3, 1);
    g_object_set_data(G_OBJECT(window), "name_entry", entry);

    label = gtk_label_new("Age:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 2, 1, 1);
    GtkAdjustment *adjustment = gtk_adjustment_new(30, 0, 100, 1, 10, 0);
    GtkWidget *slider = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, adjustment);
    gtk_scale_set_draw_value(GTK_SCALE(slider), TRUE);
    gtk_grid_attach(GTK_GRID(grid), slider, 1, 2, 3, 1);
    g_object_set_data(G_OBJECT(window), "age_slider", slider);

    label = gtk_label_new("Gender:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 3, 1, 1);
    GtkWidget *combo0 = gtk_combo_box_text_new();
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo0), "0", "Female");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo0), "1", "Male");
    gtk_grid_attach(GTK_GRID(grid), combo0, 1, 3, 3, 1);
    g_object_set_data(G_OBJECT(window), "gender_combo", combo0);

    label = gtk_label_new("Condition Description:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 4, 1, 1);
    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);
    GtkWidget *scroll_win = gtk_scrolled_window_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll_win), text_view);
    gtk_widget_set_size_request(scroll_win, 200, 100);
    gtk_grid_attach(GTK_GRID(grid), scroll_win, 1, 4, 3, 1);
    g_object_set_data(G_OBJECT(window), "condition_text", text_view);

    label = gtk_label_new("Diagnosis: ");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 5, 1, 1);

    label = gtk_label_new("Observed airway: ");
    gtk_grid_attach(GTK_GRID(grid), label, 1, 6, 1, 1);
    GtkWidget *combo = gtk_combo_box_text_new();
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), "0", "Free airway");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), "2", "Irritated throat");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), "1", "Changed voice");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo), "3", "No Free airway");
    gtk_grid_attach(GTK_GRID(grid), combo, 2, 6, 2, 1);
    g_object_set_data(G_OBJECT(window), "airway_combo", combo);

    label = gtk_label_new("SPO2 measured: ");
    gtk_grid_attach(GTK_GRID(grid), label, 1, 7, 1, 1);
    GtkAdjustment *adjustment2 = gtk_adjustment_new(80, 50, 100, 1, 10, 0);
    GtkWidget *slider2 = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, adjustment2);
    gtk_scale_set_draw_value(GTK_SCALE(slider2), TRUE);
    gtk_grid_attach(GTK_GRID(grid), slider2, 2, 7, 2, 1);
    g_object_set_data(G_OBJECT(window), "spo2_slider", slider2);

    label = gtk_label_new("Pulse measured: ");
    gtk_grid_attach(GTK_GRID(grid), label, 1, 8, 1, 1);
    entry = gtk_entry_new();
    gtk_entry_set_input_purpose(GTK_ENTRY(entry), GTK_INPUT_PURPOSE_DIGITS);
    gtk_grid_attach(GTK_GRID(grid), entry, 2, 8, 2, 1);
    g_object_set_data(G_OBJECT(window), "pulse_entry", entry);

    label = gtk_label_new("Agitation observed: ");
    gtk_grid_attach(GTK_GRID(grid), label, 1, 9, 1, 1);
    GtkWidget *combo2 = gtk_combo_box_text_new();
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo2), "0", "Normal pupils");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo2), "1", "Moderately agitated");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo2), "2", "Very agitated");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo2), "3", "Observed pupil dilation");
    gtk_grid_attach(GTK_GRID(grid), combo2, 2, 9, 2, 1);
    g_object_set_data(G_OBJECT(window), "agitation_combo", combo2);

    label = gtk_label_new("Observed chemical contamination: ");
    gtk_grid_attach(GTK_GRID(grid), label, 1, 10, 1, 1);
    GtkWidget *combo3 = gtk_combo_box_text_new();
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo3), "0", "No");
    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo3), "1", "Yes");

    gtk_grid_attach(GTK_GRID(grid), combo3, 2, 10, 2, 1);
    g_object_set_data(G_OBJECT(window), "occ_combo", combo3);

    label = gtk_label_new("Temperature measured: ");
    gtk_grid_attach(GTK_GRID(grid), label, 1, 11, 1, 1);
    GtkAdjustment *adjustment3 = gtk_adjustment_new(37, 30, 45, 2, 1, 0);
    GtkWidget *slider3 = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, adjustment3);
    gtk_scale_set_draw_value(GTK_SCALE(slider3), TRUE);
    gtk_grid_attach(GTK_GRID(grid), slider3, 2, 11, 2, 1);
    g_object_set_data(G_OBJECT(window), "temp_slider", slider3);

    GtkWidget *button = gtk_button_new_with_label("Save");
    gtk_grid_attach(GTK_GRID(grid), button, 0, 12, 5, 1);
    g_signal_connect(button, "clicked", G_CALLBACK(save_patient_data), window);

    gtk_widget_show(window);
}

void save_patient_data(GtkWidget *widget, gpointer data) {
    GtkWidget *window = GTK_WIDGET(data);

    GtkWidget *id_entry = (GtkWidget *)g_object_get_data(G_OBJECT(window), "id_entry");
    GtkWidget *name_entry = (GtkWidget *)g_object_get_data(G_OBJECT(window), "name_entry");
    GtkWidget *age_slider = (GtkWidget *)g_object_get_data(G_OBJECT(window), "age_slider");
    GtkWidget *gender_combo = (GtkWidget *)g_object_get_data(G_OBJECT(window), "gender_combo");
    GtkWidget *condition_text = (GtkWidget *)g_object_get_data(G_OBJECT(window), "condition_text");
    GtkWidget *airway_combo = (GtkWidget *)g_object_get_data(G_OBJECT(window), "airway_combo");
    GtkWidget *spo2_slider = (GtkWidget *)g_object_get_data(G_OBJECT(window), "spo2_slider");
    GtkWidget *pulse_entry = (GtkWidget *)g_object_get_data(G_OBJECT(window), "pulse_entry");
    GtkWidget *agitation_combo = (GtkWidget *)g_object_get_data(G_OBJECT(window), "agitation_combo");
    GtkWidget *occ_combo = (GtkWidget *)g_object_get_data(G_OBJECT(window), "occ_combo");
    GtkWidget *temp_slider = (GtkWidget *)g_object_get_data(G_OBJECT(window), "temp_slider");

    std::string id = gtk_editable_get_text(GTK_EDITABLE(id_entry));
    std::string name = gtk_editable_get_text(GTK_EDITABLE(name_entry));
    gint age = gtk_adjustment_get_value(gtk_range_get_adjustment(GTK_RANGE(age_slider)));
    bool gender = gtk_combo_box_get_active(GTK_COMBO_BOX(gender_combo));
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(condition_text));
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    std::string condition = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    gint airway = gtk_combo_box_get_active(GTK_COMBO_BOX(airway_combo));
    gint spo2 = gtk_adjustment_get_value(gtk_range_get_adjustment(GTK_RANGE(spo2_slider)));
    gint pulse = atoi(gtk_editable_get_text(GTK_EDITABLE(pulse_entry)));
    gint agitation = gtk_combo_box_get_active(GTK_COMBO_BOX(agitation_combo));
    gint occ = gtk_combo_box_get_active(GTK_COMBO_BOX(occ_combo));
    gfloat temp = gtk_adjustment_get_value(gtk_range_get_adjustment(GTK_RANGE(temp_slider)));

    Diagnosis patient_diagnosis;
    patient_diagnosis.setAirwayLevel(++airway);
    patient_diagnosis.setBreathingLevel(spo2);
    patient_diagnosis.setPulseLevel(pulse);
    patient_diagnosis.setDisabilityLevel(++agitation);
    patient_diagnosis.setExposureLevel(occ,temp);
    patient_diagnosis.setTriageLevel();

    Patient pat;
    pat.setId(id);
    pat.setName(name);
    pat.setAge(age);
    pat.setGender(gender);
    pat.setConditionDescription(condition);
    pat.setDiagnosis(patient_diagnosis);



    patients_vector.push_back(pat);
    patient_names.push_back(name);
    std::stringstream pat_ss;
    pat_ss << "ID: " << id << "\nName: " << name << "\nAge: " << age << "\nGender: " << (gender ? "Yes" : "No") << "\nCondition: " << condition << "\nUrgency level: " << pat.getUrgencyLevel() << "\n\nDiagnosis:" << "\n\tAirway: " << airway << "\n\tSPO2: " << spo2 << "\n\tPulse: " << pulse << "\n\tAgitation: " << agitation << "\n\tChemical Contamination: " << (occ ? "Yes" : "No") << "\n\tTemperature: " << temp;
    patient_data.push_back(pat_ss.str());




    std::cout << "ID: " << id <<endl;
    //g_print("ID: %s\n", id);
    std::cout << "Name: " << name <<endl;
    //g_print("Name: %s\n", name);
    g_print("Age: %d\n", age);
    g_print("Gender: %d\n", gender);
    std::cout << "Condition: " << condition <<endl;
    //g_print("Condition: %s\n", condition);
    g_print("Airway: %d\n", airway);
    g_print("SPO2: %d\n", spo2);
    g_print("Pulse: %d\n", pulse);
    g_print("Agitation: %d\n", agitation);
    g_print("Chemical Contamination: %d\n", occ);
    g_print("Temperature: %0.2f\n", temp);


    // Save to database

    gtk_window_destroy(GTK_WINDOW(window));
}

void go_back_to_main_menu(GtkWidget *widget, gpointer data) {
    GtkWidget *current_window = GTK_WIDGET(data);
    gtk_window_destroy(GTK_WINDOW(current_window));
}

void display_doctors(GtkWidget *widget, gpointer data) {
    g_print("Display Doctors button clicked\n");
    GtkApplication *app = GTK_APPLICATION(data);
    display_doctors_layout(app);
}

void display_emergencies(GtkWidget *widget, gpointer data) {
    g_print("Display Emergency requests button clicked\n");
    GtkApplication *app = GTK_APPLICATION(data);
    display_emergencies_layout(app);
}

void open_add_doctor_window(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Add Doctor");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    GtkWidget *label = gtk_label_new("ID:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
    GtkWidget *id_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), id_entry, 1, 0, 2, 1);
    g_object_set_data(G_OBJECT(window), "id_entry", id_entry);

    label = gtk_label_new("Name:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 1, 1, 1);
    GtkWidget *name_entry = gtk_entry_new();
    gtk_grid_attach(GTK_GRID(grid), name_entry, 1, 1, 2, 1);
    g_object_set_data(G_OBJECT(window), "name_entry", name_entry);

    label = gtk_label_new("Specialization:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 2, 1, 1);
    GtkWidget *specialization_combo = gtk_combo_box_text_new();
    const char *specializations[] = {"IM", "Cardio", "Surgery", "Ophthalmology", "Gynecology", "ENT", "Dermatology", "Ortho", "Dental", "Radiology"};
    for (int i = 0; i < 10; i++) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(specialization_combo), specializations[i]);
    }
    gtk_grid_attach(GTK_GRID(grid), specialization_combo, 1, 2, 2, 1);
    g_object_set_data(G_OBJECT(window), "specialization_combo", specialization_combo);

    label = gtk_label_new("Available Days:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 3, 1, 1);

    const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 0; i < 7; i++) {
        GtkWidget *check_button = gtk_check_button_new_with_label(days[i]);
        gtk_grid_attach(GTK_GRID(grid), check_button, 1, 3 + i, 2, 1);
        gchar *button_name = g_strdup_printf("day_button_%d", i);
        g_object_set_data(G_OBJECT(window), button_name, check_button);
        g_free(button_name);
    }

    GtkWidget *save_button = gtk_button_new_with_label("Save");
    gtk_grid_attach(GTK_GRID(grid), save_button, 1, 10, 2, 1);
    g_signal_connect(save_button, "clicked", G_CALLBACK(save_doctor_data), window);

    gtk_widget_show(window);
}

void save_doctor_data(GtkWidget *widget, gpointer data) {
    GtkWidget *window = GTK_WIDGET(data);

    GtkWidget *id_entry = (GtkWidget *)g_object_get_data(G_OBJECT(window), "id_entry");
    GtkWidget *name_entry = (GtkWidget *)g_object_get_data(G_OBJECT(window), "name_entry");
    GtkWidget *specialization_combo = (GtkWidget *)g_object_get_data(G_OBJECT(window), "specialization_combo");

    std::string id = gtk_editable_get_text(GTK_EDITABLE(id_entry));
    std::string name = gtk_editable_get_text(GTK_EDITABLE(name_entry));
    std::string specialization = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(specialization_combo));

    std::string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    std::vector<std::string> available_days;
    for (int i = 0; i < 7; i++) {
        gchar *button_name = g_strdup_printf("day_button_%d", i);
        GtkWidget *check_button = (GtkWidget *)g_object_get_data(G_OBJECT(window), button_name);
        gboolean is_active = gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button));

        if(is_active){
            available_days.push_back(days[i]);
        }

    }

    Doctor doc;
    doc.setID(id);
    doc.setName(name);
    doc.setClinicType(specialization);
    doc.setAvailableDays(available_days);

    doctors_vector.push_back(doc);
    doctor_names.push_back(name);

    searchByType(clinics_vector, specialization).addDoctor(doc);



// Create a stringstream and print the vector into it
    std::stringstream doc_ss;
    doc_ss << "ID: " << id << "\n";
    doc_ss << "Name: " << name << "\n";
    doc_ss << "Specialization: " << specialization << "\n";
    doc_ss << "Available Days: ";
    for (const std::string& day : available_days) {
        doc_ss << "\n\t" << day ;
    }
    doc_ss << "\n";
    doctor_data.push_back(doc_ss.str());


    gtk_window_destroy(GTK_WINDOW(window));
}

void open_delete_patient_window(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Delete Patient");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    GtkWidget *label = gtk_label_new("Select Patient to Delete:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);

    GtkWidget *combo = gtk_combo_box_text_new();
    populate_patient_dropdown(combo, patient_names);
    gtk_grid_attach(GTK_GRID(grid), combo, 0, 1, 2, 1);

    GtkWidget *button = gtk_button_new_with_label("Delete");
    g_signal_connect(button, "clicked", G_CALLBACK(delete_patient), combo);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 2, 1);

    button = gtk_button_new_with_label("Main Menu");
    g_signal_connect(button, "clicked", G_CALLBACK(go_back_to_main_menu), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 2, 1);


    gtk_widget_show(window);
}

void delete_patient(GtkWidget *widget, gpointer data) {
    GtkComboBox *combo = GTK_COMBO_BOX(data);
    int index = gtk_combo_box_get_active(combo);
    if (index >= 0 && index < static_cast<int>(patient_names.size())) {
        std::string name = patient_names[index];
        patient_names.erase(patient_names.begin() + index);
        patient_data.erase(patient_data.begin() + index);
        patients_vector.erase(patients_vector.begin() + index);
        populate_patient_dropdown(GTK_WIDGET(combo), patient_names);  // Ensure correct type

    }
}


void open_delete_doctor_window(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Delete Doctor");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    GtkWidget *label = gtk_label_new("Select Doctor to Delete:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);

    GtkWidget *combo = gtk_combo_box_text_new();
    populate_doctor_dropdown(combo);
    gtk_grid_attach(GTK_GRID(grid), combo, 0, 1, 2, 1);

    GtkWidget *button = gtk_button_new_with_label("Delete");
    g_signal_connect(button, "clicked", G_CALLBACK(delete_doctor), combo);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 2, 1);

    button = gtk_button_new_with_label("Main Menu");
    g_signal_connect(button, "clicked", G_CALLBACK(go_back_to_main_menu), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 2, 1);

    gtk_widget_show(window);
}

void delete_doctor(GtkWidget *widget, gpointer data) {
    GtkComboBox *combo = GTK_COMBO_BOX(data);
    int index = gtk_combo_box_get_active(combo);
    if (index >= 0 && index < static_cast<int>(doctor_names.size())) {
        std::string name = doctor_names[index];
        doctor_names.erase(doctor_names.begin() + index);
        doctor_data.erase(doctor_data.begin() + index);
        doctors_vector.erase(doctors_vector.begin() + index);
        populate_doctor_dropdown(GTK_WIDGET(combo));  // Ensure correct type

    }
}

void open_reserve_clinic_window(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Reserve Clinic");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    // Create and populate clinic dropdown
    GtkWidget *label = gtk_label_new("Select Clinic:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 1, 1);
    GtkComboBoxText *clinic_combo = GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new());
    populate_clinic_dropdown(clinic_combo);
    gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(clinic_combo), 1, 0, 2, 1);
    g_object_set_data(G_OBJECT(window), "clinic_combo", clinic_combo);

    // Create and populate patient dropdown
    label = gtk_label_new("Select Patient:");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 1, 1, 1);
    GtkComboBoxText *patient_combo = GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new());
    populate_patient_dropdown(patient_combo);
    gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(patient_combo), 1, 1, 2, 1);
    g_object_set_data(G_OBJECT(window), "patient_combo", patient_combo);

    // Add button
    GtkWidget *add_button = gtk_button_new_with_label("Add");
    gtk_grid_attach(GTK_GRID(grid), add_button, 0, 2, 3, 1);
    g_signal_connect(add_button, "clicked", G_CALLBACK(on_add_button_clicked), window);

    // Main Menu button
    GtkWidget *main_menu_button = gtk_button_new_with_label("Main Menu");
    gtk_grid_attach(GTK_GRID(grid), main_menu_button, 0, 3, 3, 1);
    g_signal_connect(main_menu_button, "clicked", G_CALLBACK(go_back_to_main_menu), window);

    gtk_widget_show(window);
}

void on_add_button_clicked(GtkWidget *widget, gpointer data) {
    GtkWidget *window = GTK_WIDGET(data);
    GtkComboBoxText *clinic_combo = GTK_COMBO_BOX_TEXT(g_object_get_data(G_OBJECT(window), "clinic_combo"));
    GtkComboBoxText *patient_combo = GTK_COMBO_BOX_TEXT(g_object_get_data(G_OBJECT(window), "patient_combo"));

    std::string selected_clinic = gtk_combo_box_text_get_active_text(clinic_combo);
    std::string selected_patient = gtk_combo_box_text_get_active_text(patient_combo);

    searchByType(clinics_vector, selected_clinic).addtoWaiting(searchByName(patients_vector, selected_patient));


}

void open_clinic_schedule_window(GtkWidget *widget, gpointer data) {
    GtkApplication *app = GTK_APPLICATION(data);
    GtkWidget *window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(window), "Clinic Schedule");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    GtkWidget *grid = gtk_grid_new();
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_widget_set_margin_start(grid, 10);
    gtk_widget_set_margin_end(grid, 10);
    gtk_widget_set_margin_top(grid, 10);
    gtk_widget_set_margin_bottom(grid, 10);
    gtk_window_set_child(GTK_WINDOW(window), grid);

    // Add label for "Select Clinic"
    GtkWidget *label = gtk_label_new("Select Clinic");
    gtk_grid_attach(GTK_GRID(grid), label, 0, 0, 2, 1);
    gtk_widget_set_halign(label, GTK_ALIGN_CENTER);

    // Add a combo box (dropdown) for clinic selection
    GtkComboBoxText *combo = GTK_COMBO_BOX_TEXT(gtk_combo_box_text_new());
    populate_clinic_dropdown(combo);
    gtk_grid_attach(GTK_GRID(grid), GTK_WIDGET(combo), 0, 1, 2, 1);

    // Add a text view for displaying clinic schedule
    GtkWidget *text_view = gtk_text_view_new();
    gtk_text_view_set_editable(GTK_TEXT_VIEW(text_view), FALSE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(text_view), GTK_WRAP_WORD);

    GtkWidget *scroll_win = gtk_scrolled_window_new();
    gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scroll_win), text_view);
    gtk_widget_set_vexpand(scroll_win, TRUE);
    gtk_widget_set_hexpand(scroll_win, TRUE);
    gtk_grid_attach(GTK_GRID(grid), scroll_win, 0, 2, 2, 1);

    // Connect the signal for combo box selection change
    g_signal_connect(combo, "changed", G_CALLBACK(on_clinic_selected), text_view);

    // Add a "Main Menu" button
    GtkWidget *button = gtk_button_new_with_label("Main Menu");
    g_signal_connect(button, "clicked", G_CALLBACK(go_back_to_main_menu), window);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 2, 1);

    gtk_widget_show(window);
}



void on_clinic_selected(GtkComboBox *combo, gpointer data) {
    static std::string clinics[] = {"IM", "Cardio", "Surgery", "Ophthalmology", "Gynecology", "ENT", "Dermatology", "Ortho", "Dental", "Radiology"};
    GtkWidget *text_view = GTK_WIDGET(data);
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));
    int index = gtk_combo_box_get_active(combo);

    if (index >= 0 && index < static_cast<int>(sizeof(clinics) / sizeof(clinics[0]))) {
        std::string clinic_type = clinics[index];
        std::vector<Doctor> clinic_docs = (searchByType(clinics_vector, clinic_type).getDoctor());
        std::stringstream ss;

        ss << "Clinic Type: " << clinic_type;
        ss << "\n\nDoctors: ";

        for (auto& it : clinic_docs) {
            ss << "\n\tName: " << it.getName();
            ss << "\n\tAvailable Days: " << it.getAvailableDaysTxt();
        }

        std::string result = ss.str();
        gtk_text_buffer_set_text(buffer, result.c_str(), -1);
    }
}


void populate_clinic_dropdown(GtkComboBoxText *combo) {
    static std::string clinics[] = {"IM", "Cardio", "Surgery", "Ophthalmology", "Gynecology", "ENT", "Dermatology", "Ortho", "Dental", "Radiology"};
    for (const auto& clinic : clinics) {
        gtk_combo_box_text_append_text(combo, clinic.c_str());
    }
}

void populate_patient_dropdown(GtkComboBoxText *combo) {
    for (const auto& name : patient_names) {
        gtk_combo_box_text_append_text(combo, name.c_str());
    }
}

void display_clinic_schedule(GtkWidget *widget, gpointer data) {
    g_print("Clinic Schedule button clicked\n");
}