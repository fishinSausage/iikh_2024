#include "recipe.h"
#include <iostream>
#include <fstream>

// 생성자
Recipe::Recipe(std::string name, std::string picture, int serving_size, int estimated_time, std::vector<GroceryItem> ingredients, std::vector<std::string> steps)
    : name(name), picture(picture), serving_size(serving_size), estimated_time(estimated_time), ingredients(ingredients), steps(steps) {}

// 전체 요소 출력 & 루프를 통해 사용자의 메소드 선택
int Recipe::display() {
    int choice;
    do {
        // 레시피 정보 출력
        std::cout << "\n\nRecipe: " << name << "\n"; // 레시피 이름 출력
        std::cout << "Serving Size: " << serving_size << " servings\n"; // 레시피가 몇인분 기준으로 저장돼 있는지 출력
        std::cout << "Estimated Time: " << estimated_time << " minutes\n\n"; // 예상 조리시간 출력

        // 재료 출력
        std::cout << "Ingredients:\n";
        for (const auto& ingredient : ingredients) {
            std::cout << "- " << ingredient.get_name() << " (" << ingredient.get_quantity() << " " << ingredient.get_unit() << ")\n";
        }

        // 준비 단계 출력
        std::cout << "\nSteps:\n";
        int stepNum = 1;
        for (const auto& step : steps) {
            std::cout << stepNum++ << ". " << step << "\n";
        }

        // 사용자에게 추가적인 선택을 제공하는 루프
        std::cout << "\nChoose an option:\n";
        std::cout << "0. Exit\n";
        std::cout << "1. Print recipe to file\n";
        std::cout << "2. Edit recipe\n";
        std::cout << "3. Add ingredient (by input)\n";
        std::cout << "4. Add step (by input)\n";
        std::cout << "5. Add all ingredients to GroceryList\n";
        std::cout << "6. Delete recipe\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 0:
            std::cout << "Exiting...\n";
            break;
        case 1:
            printToFile("recipe.txt");
            std::cout << "Recipe saved to 'recipe.txt'.\n";
            break;
        case 2:
            editRecipe();
            break;
        case 3:
            addIngredientByInput();
            break;
        case 4:
            addStepByInput();
            break;
        case 5: {
            int servings;
            std::cout << "Enter the number of servings: ";
            std::cin >> servings;

            // 레시피 객체와 인원 수를 RecipeDB로 반환하는 로직
            return servings;  // 루프 종료
        }
        case 6:
            // 레시피 이름을 RecipeDB로 반환하는 로직
            return -1;  // 루프 종료
        default:
            std::cout << "Invalid choice. Please choose again.\n";
        }
    } while (choice != 0);  // 0을 입력하면 루프 종료

    return 0;
}

// 재료를 출력하는 함수
void Recipe::displayIngredients() {
    std::cout << "Ingredients for " << name << " (" << serving_size << " servings):\n";
    for (const auto& ingredient : ingredients) {
        std::cout << "- " << ingredient.get_name() << " (" << ingredient.get_quantity() << " " << ingredient.get_unit() << ")\n";
    }
}

// 준비 단계를 출력하는 함수
void Recipe::displaySteps() {
    std::cout << "Steps to prepare " << name << ":\n";
    int stepNum = 1;
    for (const auto& step : steps) {
        std::cout << stepNum++ << ". " << step << "\n";
    }
}

// 레시피 수정 함수(내부 변수를 아예 처음부터 다시 설정하고 싶을 때, 재료와 단계를 '추가' 하고 싶으면 다른 메소드 사용)
void Recipe::editRecipe() {
    int choice;
    std::cout << "\n\nWhich part of the recipe would you like to edit?\n";
    std::cout << "1. Name\n2. Picture\n3. Serving Size\n4. Estimated Time\n5. Ingredients\n6. Steps\n";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Enter new name: ";
        std::cin.ignore(); // 이전 입력 버퍼 정리
        std::getline(std::cin, name);
        break;
    case 2:
        std::cout << "Enter new picture path: ";
        std::cin >> picture;
        break;
    case 3:
        std::cout << "Enter new serving size: ";
        std::cin >> serving_size;
        break;
    case 4:
        std::cout << "Enter new estimated time (minutes): ";
        std::cin >> estimated_time;
        break;
    case 5:
        ingredients.clear();
        int num_ingredients;
        std::cout << "How many ingredients to add? ";
        std::cin >> num_ingredients;
        for (int i = 0; i < num_ingredients; ++i) {
            std::string ing_name, ing_unit;
            float ing_quantity;
            std::cout << "Enter ingredient " << i + 1 << " name: ";
            std::cin >> ing_name;
            std::cout << "Enter quantity: ";
            std::cin >> ing_quantity;
            std::cout << "Enter unit: ";
            std::cin >> ing_unit;
            ingredients.push_back(GroceryItem(ing_name, ing_quantity, ing_unit));
        }
        break;
    case 6:
        steps.clear();
        int num_steps;
        std::cout << "How many steps to add? ";
        std::cin >> num_steps;
        std::cin.ignore(); // 버퍼 정리
        for (int i = 0; i < num_steps; ++i) {
            std::string step;
            std::cout << "Enter step " << i + 1 << ": ";
            std::getline(std::cin, step);
            steps.push_back(step);
        }
        break;
    default:
        std::cout << "Invalid choice.\n";
        break;
    }
}

// 재료 추가 함수 (GroceryItme 객체를 만들어 추가하면 레시피의 재료에 추가됨)
void Recipe::addIngredient(const GroceryItem& ingredient) {
    ingredients.push_back(ingredient);
}

// 사용자 입력을 통해 재료 추가하는 함수
void Recipe::addIngredientByInput() {
    std::string ing_name, ing_unit;
    float ing_quantity;
    std::cout << "Enter ingredient name: ";
    std::cin >> ing_name;
    std::cout << "Enter quantity: ";
    std::cin >> ing_quantity;
    std::cout << "Enter unit: ";
    std::cin >> ing_unit;
    ingredients.push_back(GroceryItem(ing_name, ing_quantity, ing_unit));
}

// 사용자 입력을 통해 단계 추가하는 함수
void Recipe::addStepByInput() {
    std::string step;
    std::cout << "Enter step: ";
    std::cin.ignore(); // 이전 입력 버퍼 정리
    std::getline(std::cin, step);
    steps.push_back(step);
}

// 레시피 정보를 텍스트 파일로 저장하는 함수
void Recipe::printToFile(const std::string& filename) {
    std::ofstream file(filename);

    if (!file) {
        std::cerr << "Error opening file: " << filename << "\n";
        return;
    }

    // 레시피 이름, 서빙 사이즈, 예상 시간 출력
    file << "Recipe: " << name << "\n";
    file << "Serving Size: " << serving_size << " servings\n";
    file << "Estimated Time: " << estimated_time << " minutes\n\n";

    // 재료 출력
    file << "Ingredients:\n";
    for (const auto& ingredient : ingredients) {
        file << "- " << ingredient.get_name() << " (" << ingredient.get_quantity() << " " << ingredient.get_unit() << ")\n";
    }

    // 준비 단계 출력
    file << "\nSteps:\n";
    int stepNum = 1;
    for (const auto& step : steps) {
        file << stepNum++ << ". " << step << "\n";
    }

    // 파일 닫기
    file.close();

    if (file) {
        std::cout << "Recipe successfully written to " << filename << "\n";
    }
    else {
        std::cerr << "Error writing to file: " << filename << "\n";
    }
}