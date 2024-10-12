#ifndef GREETER_H
#define GREETER_H

#include "GroceryList.h"
#include "RecipeDatabaseManager.h"
#include "Meal_Manager.h"
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
