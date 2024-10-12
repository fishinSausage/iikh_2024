#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "GroceryItem.cpp"
#include "Recipe.cpp"



class Recipe {
public:
	std::string name;
};

class GroceryList {

};

class Database {

private:
	std::vector<Recipe> recipes;
	GroceryList Grocery;

public:
	void display() {


		char keyInput;
		int indexV = 0;
		int indexH = 0;
		bool isOnMenu = false;
		bool isSearching = true;
		std::vector<std::string> menu = { "[Search]", "[ Add ]", "[ Exit ]" };
		std::vector<std::string> names;

		for (int i = 0; i < recipes.size(); i++) { //검색 등을 위해, 레시피 이름만 모아 할당
			names.push_back(recipes[i].name);
		}

		while (1) { //break 전까지 반복
			system("cls");
			std::cout << "***\n";

			for (int i = 0; i < names.size(); i++) {	//레시피 목록을 표시

				if (isOnMenu == false && i == indexV) {
					std::cout << names[i] << "◀" << std::endl;		//레시피 목록 중 현재 커서 위치 표시
				}

				else {
					std::cout << names[i] << std::endl;
				}
			}

			if (isSearching) { //검색 중 뒤로가기 항목 제공
				std::cout << "Back…";
				if (indexV == names.size() && isOnMenu == false) std::cout << "◀";
				std::cout << std::endl;
			}

			std::cout << "***\n";

			for (int i = 0; i < 3; i++) {	//메뉴 목록을 표시

				if (isOnMenu == true && i == indexH) {
					std::cout << menu[i] << "◀ ";		//메뉴 중 현재 커서 위치 표시
				}

				else std::cout << menu[i] << "  ";
			}
			std::cout << std::endl;




			keyInput = _getch();
			int listSize = names.size();
			if (isSearching) listSize = names.size() + 1;

			if (keyInput == -32) { //arrow
				switch (_getch()) {
				case 72: // Up arrow
					if (indexV > 0 && isOnMenu == false) {
						indexV--;
					}
					else if (isOnMenu == true) { //메뉴 상태에서 나가기
						isOnMenu = false;
					}
					else indexV = listSize - 1;
					break;
				case 80: // Down arrow
					if (indexV < listSize - 1) {
						indexV++;
					}
					else if (indexV == listSize - 1) { //끝까지 내려가면 메뉴로 들어가기
						isOnMenu = true;
					}
					break;
				case 75: // Left arrow
					if (indexH > 0 && isOnMenu == true) { //메뉴 상태에서 좌우 이동
						indexH--;
					}
					break;
				case 77: // Right arrow
					if (indexH < 2 && isOnMenu == true) { //메뉴 상태에서 좌우 이동
						indexH++;
					}
					break;

				}
			}

			else if (keyInput == 13) {
				if (isOnMenu == false) {
					if (isSearching == true && indexV == listSize - 1) { //검색 중 Back을 눌렀으면 
						names.clear();
						for (int i = 0; i < recipes.size(); i++) { //검색 결과로 한정되었던 배열 초기화
							names.push_back(recipes[i].name);
						}
						isSearching = false;
						isOnMenu = false;
						indexV = 0;
						indexH = 0;
					}
					else {

						int recipeAction = displayRecipe(*searchRecipe(names[indexV])); //선택한 이름을 가진 레시피의 display를 호출. 레시피로 컨트롤이 넘어감. 이후 거기서 사용자가 선택한 액션에 따라 리턴됨

						if (recipeAction < 0) { //삭제를 선택한 경우
							deleteRecipe(names[indexV]);
						}
						else if (displayRecipe()>0){ //GroceryList에 추가하는 경우. 이때는 리턴값이 인분 수가 됨
							Grocery.update_item(*searchRecipe(names[indexV], recipeAction);
						}
					}

				}

				else if (indexH == 0) { //Search 선택

					std::cout << "Please Enter the Keyword: ";
					std::string keyWord;
					std::cin >> keyWord;
					
					for (int i = 0; i < names.size(); ) { //키워드를 포함하지 않는 이름을 전부 삭제
						
						if (names[i].find(keyWord) == std::string::npos) {
							names.erase(names.begin()+i);
						}
						else {
							i++;
						}
						
					}

					isSearching = true;
					isOnMenu = false;
					indexV = 0;
					indexH = 0;

				}

				else if (indexH == 1) { // Add 선택

					std::string recipeName;
					std::string picture;

					std::string groceryName;
					float groceryQuantity;
					std::string groceryUnit;
					std::vector<GroceryItem> ingridients;

					int estimatedTime;
					int servingSize;

					std::string step;
					std::vector<std::string> steps;

					//Recipe의 각 요소들을 입력받음

					std::cout << "Please Enter Recipe Name\n" << ": ";
					std::cin >> recipeName;
					std::cout << "Please Enter Picture Directory\n" << ": ";
					std::cin >> picture;
					std::cout << "Please Enter Ingridients Name, Quantity, Unit (ex: Sugar 5 spoon)" << std::endl;
					std::cout << "If you Entered All Ingridients, Enter 'done'.\n" << ": ";

					while (1){//done을 입력받기 전까지 여러 종류의 재료를 계속 입력받음
						std::cin >> groceryName;
						if (groceryName == "done" || groceryName == "Done") break;
						std::cin >> groceryQuantity;
						std::cin >> groceryUnit;

						ingridients.push_back(GroceryItem(groceryName, groceryQuantity, groceryUnit));
					}

					std::cout << "Please Enter Serving Size\n" << ": ";
					std::cin >> servingSize;

					std::cout << "Please Enter Estimated Cooking Time\n" << ": ";
					std::cin >> estimatedTime;

					std::cout << "Please Enter Cooking Steps." << std::endl;
					std::cout << "If you Entered All Steps, Enter 'done'.\n" << ": ";

					while (1) { //done을 입력받기 전까지 조리과정을 계속 입력받음
						std::getline(std::cin, step);
						if (step == "done" || step == "Done") break;
						steps.push_back(step);
					}

					addRecipe(Recipe(recipeName, picture, ingridients,servingSize, estimatedTime, steps)); //입력받은 값을 바탕으로 DB에 레시피 추가



				}

				else if (indexH == 2) { //Exit 선택
					system("cls");
					break;
				}
				
			}




		}

	}

	void showAll() { //레시피 이름 전체 출력.
		system("cls");

		for (auto r : recipes) {
			std::cout << r.name << '\n';
		}
	}

	Recipe* searchRecipe(std::string name) { //레시피를 검색 후, 해당 레시피의 주소를 반환.
		for (auto r : recipes) {
			if (r.name == name) {
				return &r;
			}
		}
		return NULL;
	}
	void addRecipe(Recipe a) { //DB에 레시피 추가

		recipes.push_back(a);
	}
	void deleteRecipe(std::string name) { //특정 이름의 레시피 제거
		for (int i = 0; i < recipes.size(); i++) {
			if (recipes[i].name == name) {
				recipes.erase(recipes.begin() + i);
				break;
			}
		}


	}


};
