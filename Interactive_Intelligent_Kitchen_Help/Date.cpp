
#include <vector>
#include <iostream>
#include "Meal.h"
#include "GroceryList.h"
using namespace std;

// this code is unnecessary
//typedef int GroceryList;
//typedef int Meal;

class Date {

	vector<Meal> Meals;
	GroceryList grocerylist;

	// show today's meals 
	// e.g. 1. Name: brunch, (# of Guests): 1 guest, (# of recipes): 4
	void display() {
		int n = 0;
		for (auto& meal : Meals) {
			//cout << ++n << ". Name: " << meal.name;
			//cout << ", (# of Guests): " << meal.numGuests << "guest";
			//cout << ", (# of Recipes): " << meal.recipes.size() << '\n';
		}
	}

	// This day has Meal schedule?
	bool hasMeal() {
		return Meals.size();
	}

	void addMeal(Meal& meal) {
		Meals.push_back(meal);
	}

	void addToGroceryList(GroceryList grocerylist) {
		this->grocerylist = grocerylist;
	}

};