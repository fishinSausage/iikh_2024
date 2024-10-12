//
// Created by bambbdd(엄윤상).
//

#include "Meal.h"
#include "recipe.h"
#include "RecipeDatabaseManager.h"
#include <iostream>
#include <utility>
#include <conio.h>

// Constructor implementation
Meal::Meal(std::string name, unsigned int numGuests,
    const std::vector<Recipe>& recipes)
    : name(std::move(name)), numGuests(numGuests), recipes(recipes) {}

// Getter
std::string Meal::getName() const { return name; }
unsigned int Meal::getNumGuests() const { return numGuests; }
std::vector<Recipe> Meal::getRecipes() const { return recipes; }

// Setter
void Meal::setName(const std::string& mealName) { name = mealName; }
void Meal::setNumGuests(unsigned int guests) { numGuests = guests; }
void Meal::setRecipes(const std::vector<Recipe>& recipe) { recipes = recipe; }

/*
     display the name of the meal, the number of people, the name of all recipes,     #밀이름 + 사람수 + 레시피의 이름만
            select & call display method on that instance
            remove recipe from the meal
            add to meal
            add to grocery
            exit
*/
void Meal::displayAndSelectMealInfoByArrowKeys() {
    // Local Variables
    int selectedOption = 0;
    bool exitMenu = false;

    while (!exitMenu) {
        // clear the screen
        system("cls");

        // Display the Meal Info
        std::cout << "\n" << toString() << "\n";

        // Display Menu Options
        // 화살표로 현재 가리키고 있는 옵션을 표시함(방향키로 변경 가능)
        std::cout << "Select an option using the arrow keys\n";
        std::cout << (selectedOption == ADD ? "-> " : "    ") << "1. Add Recipe\n";
        std::cout << (selectedOption == DELETE ? "-> " : "    ") << "2. Delete Recipe\n";
        std::cout << (selectedOption == ADD_TO_GROCERY_LIST ? "-> " : "    ") << "3. Add to Grocery List\n";
        std::cout << (selectedOption == EXIT ? "-> " : "     ") << "4. Exit\n";

        // Get user input
        int key = _getch(); // Get single character input

        switch (key) {
        case 72: // Up Arrow Key
            selectedOption = (selectedOption > 0) ? selectedOption - 1 : EXIT;
            break;
        case 80: // Down Arrow Key
            selectedOption = (selectedOption < EXIT) ? selectedOption + 1 : 0;
            break;
        case 13: // Enter Key
            switch (selectedOption) {
            case ADD:
                addRecipe();
                break;
            case DELETE:
                deleteRecipe();
                break;
            case ADD_TO_GROCERY_LIST:
                addAllIngredientsToGroceryList();
                break;
            case EXIT:
                exitMenu = true;
                break;
            }
            break;
        }
    }


}

// browse recipes in Recipe_Database and add a particular recipe to the meal
void Meal::addRecipe() {
    std::string addRecipeName;
    // Recipe_Database_Manager dbm; ########?
    // Recipe* newRecipe; #######?

    while (true) {
        std::cout << "Recipe to add(0 to quit): ";
        std::cin >> addRecipeName;

        if (addRecipeName == "0") {
            return;
        }

        // Recipe DB
        // browse and get address of the recipe #######?

        // add Recipe to the meal
        // recipes.push_back(newRecipe); ##########?
    }





}

// user inputs a particular recipe name -> check and delete the recipe
// it is used in display method
void Meal::deleteRecipe() {
    std::string deleteRecipeName;

    while (true) {
        bool deleted = false;

        std::cout << "Recipe to delete(0 to quit): ";
        std::cin >> deleteRecipeName;

        if (deleteRecipeName == "0") {
            return;
        }

        for (auto it = recipes.begin(); it != recipes.end(); ++it) {
            if (deleteRecipeName == it->getName()) {
                recipes.erase(it);  // Erase that recipe
                deleted = true;
                std::cout << "Recipe '" << deleteRecipeName << "' deleted.\n";
                break;  // after the deleting, break
            }
        }

        // If there's no deleted recipe
        if (!deleted) {
            std::cout << "Recipe not found: " << deleteRecipeName << "\n";
        }
    }

}

// add all the ingredients to the grocery list by using the methods of recipe class
void Meal::addAllIngredientsToGroceryList() {
    for (const auto& recipe : recipes) {
        // recipe.addAllgredientsToGroceryList(); ##############? 아직 미구현(Recipe 클래스의 메서드 사용 예정)
    }

    std::cout << "All the ingredients added to the grocery list.\n";
}

// return all the information of this meal by std::string
//        name of the meal, numGuests, recipes name/ or whole information included
std::string Meal::toString() {
    std::string result = "<Meal Name>\n" + name + "\n";
    result += "<Number of Guests>\n" + std::to_string(numGuests) + "\n";
    result += "<Recipes>\n";
    for (const auto& recipe : recipes) {
        result += recipe.getName() + "\n"; // ###? - Name만 출력
    }

    return result;
}


/*
 * 1. display
 * 2. add/delete/addtogrocery/exit
 * 3. delete의 경우 - 레시피의 이름 입력으로 받아 수행
 * 4. add의 경우 - recipeDBMS 호출 - (여기부턴 DBMS 관할)search/browse 필요, recipe의 포인터값 리턴 필요
*/
