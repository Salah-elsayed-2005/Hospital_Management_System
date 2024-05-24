#include "gui.h"
#include <gtk/gtk.h>
#include <vector>
#include <string>
#include <sstream>
#include "utility"
#include "CityGraph.h"


// Dummy data
std::vector<std::string> patient_names = {
        "Patient 1",
        "Patient 2",
        "Patient 3"
};

std::vector<std::string> patient_data = {
        "Name: Patient 1\nAge: 30\nCondition: Stable",
        "Name: Patient 2\nAge: 45\nCondition: Critical",
        "Name: Patient 3\nAge: 29\nCondition: Recovering"
};

std::vector<std::string> doctor_names = {
        "Doctor 1",
        "Doctor 2",
        "Doctor 3"
};

std::vector<std::string> doctor_data = {
        "Name: Doctor 1\nSpecialization: Cardiology\nYears of Experience: 15",
        "Name: Doctor 2\nSpecialization: Neurology\nYears of Experience: 20",
        "Name: Doctor 3\nSpecialization: Orthopedics\nYears of Experience: 12"
};

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

std::vector<std::string> airway_level = {
        "No Free airway",
        "Changed voice",
        "Irritated throat",
        "Free airway"
};

std::vector<std::string> agitation_level = {
        "Observed pupil dilation",
        "Very agitated",
        "Moderately agitated",
        "Normal pupils"
};

std::vector<std::string> occ = {
        "Yes",
        "No"
};


std::vector<std::string> gender = {
        "ENGINEER",
        "Male",
        "Female",
        "Optimus prime"
};







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

    button = gtk_button_new_with_label("Edit Patients");
    g_signal_connect(button, "clicked", G_CALLBACK(edit_patients), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 2, 2, 1);

    button = gtk_button_new_with_label("Edit Doctors");
    g_signal_connect(button, "clicked", G_CALLBACK(edit_doctors), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 3, 2, 1);

    button = gtk_button_new_with_label("Display Patients");
    g_signal_connect(button, "clicked", G_CALLBACK(display_patients), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 4, 2, 1);

    button = gtk_button_new_with_label("Display Doctors");
    g_signal_connect(button, "clicked", G_CALLBACK(display_doctors), app);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 5, 2, 1);

    button = gtk_button_new_with_label("Reserve Clinic");
    g_signal_connect(button, "clicked", G_CALLBACK(reserve_clinic), NULL);
    gtk_grid_attach(GTK_GRID(grid), button, 0, 6, 2, 1);

    button = gtk_button_new_with_label("Clinic Schedule");
    g_signal_connect(button, "clicked", G_CALLBACK(display_clinic_schedule), NULL);
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

void activate(GtkApplication *app, gpointer user_data) {
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
    g_print("Edit Doctors button clicked\n");
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

void populate_airway_dropdown(GtkWidget *combo) {
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(combo));
    for (const std::string &name : airway_level) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), name.c_str());
    }
}

void populate_gender_dropdown(GtkWidget *combo) {
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(combo));
    for (const std::string &name : gender) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), name.c_str());
    }
}

void populate_agitation_dropdown(GtkWidget *combo) {
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(combo));
    for (const std::string &name : agitation_level) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), name.c_str());
    }
}

void populate_occ_dropdown(GtkWidget *combo) {
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(combo));
    for (const std::string &name : occ) {
        gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(combo), name.c_str());
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
    GtkAdjustment *adjustment2 = gtk_adjustment_new(30, 0, 100, 1, 10, 0);
    GtkWidget *slider2 = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, adjustment2);
    gtk_scale_set_draw_value(GTK_SCALE(slider2), TRUE);
    gtk_grid_attach(GTK_GRID(grid), slider2, 2, 7, 2, 1);
    g_object_set_data(G_OBJECT(window), "spo2_slider", slider2);

    label = gtk_label_new("Pulse measured: ");
    gtk_grid_attach(GTK_GRID(grid), label, 1, 8, 1, 1);
    entry = gtk_entry_new();
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

    const gchar *id = gtk_editable_get_text(GTK_EDITABLE(id_entry));
    const gchar *name = gtk_editable_get_text(GTK_EDITABLE(name_entry));
    gint age = gtk_adjustment_get_value(gtk_range_get_adjustment(GTK_RANGE(age_slider)));
    gint gender = gtk_combo_box_get_active(GTK_COMBO_BOX(gender_combo));
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(condition_text));
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buffer, &start, &end);
    gchar *condition = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    gint airway = gtk_combo_box_get_active(GTK_COMBO_BOX(airway_combo));
    gint spo2 = gtk_adjustment_get_value(gtk_range_get_adjustment(GTK_RANGE(spo2_slider)));
    const gchar *pulse = gtk_editable_get_text(GTK_EDITABLE(pulse_entry));
    gint agitation = gtk_combo_box_get_active(GTK_COMBO_BOX(agitation_combo));
    gint occ = gtk_combo_box_get_active(GTK_COMBO_BOX(occ_combo));
    gint temp = gtk_adjustment_get_value(gtk_range_get_adjustment(GTK_RANGE(temp_slider)));

    g_print("ID: %s\n", id);
    g_print("Name: %s\n", name);
    g_print("Age: %d\n", age);
    g_print("Gender: %d\n", gender);
    g_print("Condition: %s\n", condition);
    g_print("Airway: %d\n", airway);
    g_print("SPO2: %d\n", spo2);
    g_print("Pulse: %s\n", pulse);
    g_print("Agitation: %d\n", agitation);
    g_print("Chemical Contamination: %d\n", occ);
    g_print("Temperature: %d\n", temp);

    g_free(condition);
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
    gtk_window_set_default_size(GTK_WINDOW(window), 350, 400);

    GtkWidget *grid = gtk_grid_new();
    gtk_widget_set_margin_start(grid, 15);
    gtk_widget_set_margin_end(grid, 15);
    gtk_widget_set_margin_top(grid, 15);
    gtk_widget_set_margin_bottom(grid, 15);
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

    GList *check_buttons = NULL;
    gtk_grid_attach(GTK_GRID(grid), gtk_label_new("Available days:"), 0, 2, 1, 1);

    const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    for (int i = 0; i < 7; i++) {
        GtkWidget *check_button = gtk_check_button_new_with_label(days[i]);
        gtk_grid_attach(GTK_GRID(grid), check_button, 1, 3 + i, 2, 1);
        check_buttons = g_list_append(check_buttons, check_button);
    }
    g_object_set_data(G_OBJECT(window), "check_buttons", check_buttons);

    GtkWidget *save_button = gtk_button_new_with_label("Save");
    gtk_grid_attach(GTK_GRID(grid), save_button, 1, 9, 2, 1);
    g_signal_connect(save_button, "clicked", G_CALLBACK(save_doctor_data), window);

    gtk_widget_show(window);
}

void save_doctor_data(GtkWidget *widget, gpointer data) {
    GtkWidget *window = GTK_WIDGET(data);

    GtkWidget *id_entry = (GtkWidget *)g_object_get_data(G_OBJECT(window), "id_entry");
    GtkWidget *name_entry = (GtkWidget *)g_object_get_data(G_OBJECT(window), "name_entry");
    const gchar *id = gtk_editable_get_text(GTK_EDITABLE(id_entry));
    const gchar *name = gtk_editable_get_text(GTK_EDITABLE(name_entry));

    g_print("ID: %s\n", id);
    g_print("Name: %s\n", name);

    GList *check_buttons = (GList *)g_object_get_data(G_OBJECT(window), "check_buttons");
    const char *days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    int i = 0;
    for (GList *l = check_buttons; l != NULL; l = l->next) {
        GtkWidget *check_button = GTK_WIDGET(l->data);
        gboolean is_active = gtk_check_button_get_active(GTK_CHECK_BUTTON(check_button));
        g_print("Day %s: %s\n", days[i], is_active ? "Available" : "Not available");
        i++;
    }

    g_list_free(check_buttons);
    gtk_window_destroy(GTK_WINDOW(window));
}

void reserve_clinic(GtkWidget *widget, gpointer data) {
    g_print("Reserve Clinic button clicked\n");
}

void display_clinic_schedule(GtkWidget *widget, gpointer data) {
    g_print("Clinic Schedule button clicked\n");
}