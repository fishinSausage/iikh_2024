#ifndef GREETER_H
#define GREETER_H

#include "GroceryList.h"
#include "Database.h"
#include "Meal_Manager.cpp"
#include <iostream>
#include <conio.h>
class Greeter
{
public:
	void show();
private:

	void print_greeting(int option);
	void select_option();

	//Database recipeDB;
	//MealManager mealmanager;
	GroceryList items;

};

#endif
