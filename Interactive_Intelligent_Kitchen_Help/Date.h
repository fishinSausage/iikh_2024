#pragma once
#ifndef DATE_H
#define DATE_H

#include <vector>
#include "Meal.h"
#include "GroceryList.h"
using namespace std;


class Date {

private:
    vector<Meal> Meals;
    GroceryList grocerylist;

public:
    // Show today's meals 
    // e.g. 1. Name: brunch, (# of Guests): 1 guest, (# of recipes): 4
    void display();

    // Check if this day has Meal schedule
    bool hasMeal();

    // Add a meal to the day's meal schedule
    void addMeal(Meal& meal);

    // Add items to the grocery list
    void addToGroceryList(GroceryList grocerylist);


    Date() = default;
};

#endif // DATE_H