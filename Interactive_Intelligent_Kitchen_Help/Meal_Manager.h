#ifndef MEALMANAGER_H
#define MEALMANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include "Date.h" // Assuming Date and GroceryList classes are declared in Date.h

using namespace std;

class MealManager {
public:
    // Vector of Date pointers (to store information for each date)
    vector<Date*> dates;

    // Constructor to initialize 31 date slots, all set to nullptr
    MealManager();

    // Main method to display the calendar and perform actions
    void displayCalendar();

    // Select a date and allow meal management on it
    void selectDate();

    // Print all meals scheduled for a specific date range
    void printMealsForDate();

    // Print grocery list for a specific date range
    void printGrocery();
};

#endif // MEALMANAGER_H
