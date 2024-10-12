//
// Created by bambbdd(엄윤상).
//

#ifndef IIKH_2024_MEAL_H
#define IIKH_2024_MEAL_H

#include <string>
#include <vector>

// Forward declaration of recipe class to avoid circular dependency
class Recipe;
class Recipe_Database_Manager;

class Meal {
private:
    std::string name;
    unsigned int numGuests;
    std::vector<Recipe> recipes;

public:
    enum MenuOption {
        ADD = 0,
        DELETE,
        ADD_TO_GROCERY_LIST,
        EXIT
    };

    // Constructor
    Meal(std::string name, unsigned int numGuests,
        const std::vector<Recipe>& recipes);

    // Getter
    std::string getName() const;
    unsigned int getNumGuests() const;
    std::vector<Recipe> getRecipes() const;

    // Setter
    void setName(const std::string& name);
    void setNumGuests(unsigned int numGuests);
    void setRecipes(const std::vector<Recipe>& recipes);

    /*
     display the name of the meal, the number of people, the name of all recipes,     #밀이름 + 사람수 + 레시피의 이름만
            select & call display method on that instance
            remove recipe from the meal
            add to meal
            add to grocery
            exit
    */
    void displayAndSelectMealInfoByArrowKeys();

    // browse recipes in Recipe_Database and add a particular recipe to the meal
    // it is used in display method
    void addRecipe();

    // user inputs a particular recipe name -> check and delete the recipe
    // it is used in display method
    void deleteRecipe();

    // add all the ingredients to the grocery list by using the methods of recipe class
    // it is used in display method
    void addAllIngredientsToGroceryList();

    // return all the information of this meal by std::string
    //        name of the meal, numGuests, recipes name/ or whole information included
    std::string toString();

};

#endif //IIKH_2024_MEAL_H
