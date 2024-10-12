#pragma once
#ifndef RECIPEDATABASEMANAGER_H
#define RECIPEDATABASEMANAGER_H

#include <string>
#include <vector>
#include "GroceryList.h"
#include "GroceryItem.h"
#include "Recipe.h"

class RecipeDatabaseManager {
public:
    void display();
    void showAll();
    Recipe* searchRecipe(std::string name);
    void addRecipe(Recipe a);
    void deleteRecipe(std::string name);

private:
    std::vector<Recipe> recipes;
    GroceryList grocery;
};

#endif // RECIPEDATABASEMANAGER_H
