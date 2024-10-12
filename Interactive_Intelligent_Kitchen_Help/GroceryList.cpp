#include "GroceryList.h"
#include "Recipe.h"

void GroceryList::add_item(std::string name, float quantity, std::string unit) { // 객체 추가 함수
    items.push_back(GroceryItem(name, quantity, unit));
} 

void GroceryList::update_item(const Recipe& recipe, int people) { // GroceryItem 객체가 있을 경우 양 추가, 없을 경우 객체 추가.
    using namespace std;
    int serve_size = recipe.getServingSize(); // 몇인분인지 받아옴.
    for (const auto& ingredient : recipe.getIngredients()) {
        string item_name = ingredient.get_name();
        float quantity = ingredient.get_quantity();
        string unit = ingredient.get_unit();
        bool found = false;

        quantity = quantity / serve_size * people; // 레시피가 만약 2인분 이상일 경우, 명수를 입력받고 양 조절
        for (auto& item : items) {
            if (item.get_name() == item_name) { // 식재료 목록에 있을 경우
                item.add_quantity(quantity);
                cout << item_name << " has been added " << quantity << " " << unit << endl;
                found = true;
                break;
            }
        }
        if (!found) {                           // 식재료 목록에 없을 경우
            add_item(item_name, quantity, unit);
            cout << item_name << " has been added " << quantity << " " << unit << " to the grocery list!" << endl;
        }
    }
    saved_recipes.push_back(recipe);
    cout << "Recipe '" << recipe.getName() << "' is saved in Grocery List Recipe!\n";
}

void GroceryList::remove_item(const Recipe& recipe, int people) { // GroceryItem 객체가 있을 경우 양 삭제, 양이 0 이하일 경우 객체 삭제.
    using namespace std;
    int serve_size = recipe.getServingSize();
    for (const auto& ingredient : recipe.getIngredients()) {
        string item_name = ingredient.get_name();
        float quantity = ingredient.get_quantity();
        string unit = ingredient.get_unit();
        bool found = false;

        quantity = quantity / serve_size * people;
        for (auto& item : items) {
            if (item.get_name() == item_name) {
                if (item.get_quantity() > quantity) {   // GroceryItem 객체가 있고, 객체가 가진 양이 삭제할 양보다 많은 경우
                    item.add_quantity(-quantity);       // 기존 수량에서 제거
                    cout << item_name << " has been removed " << quantity << " " << unit << " from the grocery list!" << endl;
                }
                else {                                  // 만약 수량이 0 이하로 떨어지면 목록에서 삭제
                    items.erase(remove(items.begin(), items.end(), item), items.end());
                    cout << item_name << " has been removed entirely from the grocery list!" << endl;
                }
                found = true;
                break;
            }
        }
        if (!found) {                                   // GroceryItem 객체가 없을 경우
            cout << item_name << " not found in the grocery list." << endl;
        }
    }

    // saved_recipes에서 해당 레시피 제거
    auto it = find_if(saved_recipes.begin(), saved_recipes.end(),
        [&](const Recipe& r) { return r.getName() == recipe.getName(); });
    if (it != saved_recipes.end()) {
        saved_recipes.erase(it);
        cout << "Recipe '" << recipe.getName() << "' has been removed from saved recipes!" << endl;
    }
    else {
        cout << "Recipe '" << recipe.getName() << "' not found in saved recipes." << endl;
    }
}

void GroceryList::reset_items() { // GroceryItem 벡터 초기화.
    items.clear();
    std::cout << "Grocery list has been reset." << std::endl;
}

void GroceryList::display() {     // 메인함수에서 실행할 함수.
    using namespace std;
    int selected_option = 0; // Start with the first option selected
    const int total_options = 4; // We have 4 menu options

    while (true) {
        system("cls");
        // 현재 레시피와 식재료 품목 출력
        cout << "Saved Recipes: " << endl;
        if (saved_recipes.empty()) {
            cout << "No saved recipes." << endl;
        }
        else {
            for (const auto& recipe : saved_recipes) {
                for (const auto& ingredient : recipe.getIngredients()) {
                    cout << recipe.getName() << ": " << ingredient.get_name() << ": " << ingredient.get_quantity() << " " << ingredient.get_unit() << endl;
                }
                cout << endl;
            }
        }

        cout << "Grocery List: " << endl;
        if (items.empty()) {
            cout << "Grocery list is empty." << endl;
        }
        else {
            for (const auto& item : items) {
                cout << item.get_name() << ": " << item.get_quantity() << " " << item.get_unit() << endl;
            }
        }

        // 메뉴 리스트
        string menu[4] = {
            "1. Save to txt file",
            "2. Reset GroceryList",
            "3. Load from file",
            "4. Exit"
        };

        for (int i = 0; i < total_options; i++) {
            if (i == selected_option) {
                cout << "-> " << menu[i] << endl;
            }
            else {
                cout << "   " << menu[i] << endl;
            }
        }

        char keyInput = _getch(); 
        if (keyInput == -32) { 
            keyInput = _getch();
            switch (keyInput) {
            case 72:
                if (selected_option > 0) {
                    selected_option--;
                }
                break;
            case 80:
                if (selected_option < total_options - 1) {
                    selected_option++;
                }
                break;
            }
        }
        else if (keyInput == 13) {
            system("cls");
            switch (selected_option) {
            case 0: // Save to txt file
                print("grocerylist.txt");
                break;
            case 1: // Reset GroceryList
                reset_items();
                break;
            case 2: // Load from file
                load_from_txt("grocerylist.txt");
                break;
            case 3: // Exit
                std::cout << "Exit the grocery list." << std::endl;
                return; // Exit the function to break the loop
            }
        }
    }
}

void GroceryList::print(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for saving." << std::endl;
        return;
    }
    for (const auto& item : items)
    {
        file << item.to_file_format();
        file << "\n";
        
    }
    file.close();
    std::cout << "Grocery list has been saved to " << filename << std::endl;
}

void GroceryList::load_from_txt(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file for loading." << std::endl;
        return;
    }

    std::string line;
    reset_items();  // 기존 리스트 초기화

    while (std::getline(file, line)) {  // 파일에서 한 줄씩 읽음
        std::istringstream iss(line);  // 파일 줄을 입력 스트림으로 변환
        std::string name, unit;
        float quantity;

        // 첫 번째 값: 이름
        if (!std::getline(iss, name, ',')) {
            std::cerr << "Error parsing item name." << std::endl;
            continue;
        }

        // 두 번째 값: 수량 (실수형)
        std::string quantity_str;
        if (!std::getline(iss, quantity_str, ',')) {
            std::cerr << "Error parsing quantity." << std::endl;
            continue;
        }

        try {
            quantity = std::stof(quantity_str);  // 수량을 실수로 변환
        }
        catch (const std::invalid_argument& e) {
            std::cerr << "Invalid quantity format: " << quantity_str << std::endl;
            continue;
        }

        // 세 번째 값: 단위
        if (!std::getline(iss, unit, ',')) {
            std::cerr << "Error parsing unit." << std::endl;
            continue;
        }

        // 파싱한 재료를 리스트에 추가
        items.push_back(GroceryItem(name, quantity, unit));
    }

    file.close();
    std::cout << "Grocery list has been loaded from " << filename << std::endl;
}
