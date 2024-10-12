#ifndef GROCERYLIST_H
#define GROCERYLIST_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <conio.h>
#include "GroceryItem.h"
#include "Recipe.h"
#include "Database.cpp"

class Recipe;

class GroceryList
{
public:
    GroceryList() = default;

    void add_item(std::string name, float quantity, std::string unit);
    void update_item(const Recipe& recipe, int people);
    void remove_item(const Recipe& recipe, int people);
    void reset_items();
    void display();
    void save_to_txt(const std::string& filename) const;
    void load_from_txt(const std::string& filename);

private:
    std::vector<GroceryItem> items;
    std::vector<Recipe> saved_recipes;
};

#endif // GROCERYLIST_H
