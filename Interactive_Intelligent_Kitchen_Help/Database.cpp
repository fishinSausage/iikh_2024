#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "GroceryItem.h"
#include "Recipe.h"




class RecipeDB {

private:
	std::vector<Recipe> recipes;
	GroceryList* Grocery;

public:

	RecipeDB(GroceryList* groceryList) {
		Grocery = groceryList;
	};// ������, Greeter�� GroceryList�� ������ �޾ƿ�

	void display() {


		char keyInput;
		int indexV = 0;
		int indexH = 0;
		bool isOnMenu = false;
		bool isSearching = true;
		std::vector<std::string> menu = { "[Search]", "[ Add ]", "[ Exit ]" };
		std::vector<std::string> names;

		for (int i = 0; i < recipes.size(); i++) { //�˻� ���� ����, ������ �̸��� ��� �Ҵ�
			names.push_back(recipes[i].getName());
		}

		while (1) { //break ������ �ݺ�
			system("cls");
			std::cout << "***\n";

			for (int i = 0; i < names.size(); i++) {	//������ ����� ǥ��

				if (isOnMenu == false && i == indexV) {
					std::cout << names[i] << "��" << std::endl;		//������ ��� �� ���� Ŀ�� ��ġ ǥ��
				}

				else {
					std::cout << names[i] << std::endl;
				}
			}

			if (isSearching) { //�˻� �� �ڷΰ��� �׸� ����
				std::cout << "Back��";
				if (indexV == names.size() && isOnMenu == false) std::cout << "��";
				std::cout << std::endl;
			}

			std::cout << "***\n";

			for (int i = 0; i < 3; i++) {	//�޴� ����� ǥ��

				if (isOnMenu == true && i == indexH) {
					std::cout << menu[i] << "�� ";		//�޴� �� ���� Ŀ�� ��ġ ǥ��
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
					else if (isOnMenu == true) {
						isOnMenu = false;
					}
					else indexV = listSize - 1;
					break;
				case 80: // Down arrow
					if (indexV < listSize - 1) {
						indexV++;
					}
					else if (indexV == listSize - 1) {
						isOnMenu = true;
					}
					break;
				case 75: // Left arrow
					if (indexH > 0 && isOnMenu == true) {
						indexH--;
					}
					break;
				case 77: // Right arrow
					if (indexH < 2 && isOnMenu == true) {
						indexH++;
					}
					break;

				}
			}

			else if (keyInput == 13) {
				if (isOnMenu == false) {
					if (isSearching == true && indexV == listSize - 1) { //�˻� �� Back�� �������� 
						names.clear();
						for (int i = 0; i < recipes.size(); i++) { //�˻� ����� �����Ǿ��� �迭 �ʱ�ȭ
							names.push_back(recipes[i].getName());
						}
						isSearching = false;
						isOnMenu = false;
						indexV = 0;
						indexH = 0;
					}
					else {

						int recipeAction = (*searchRecipe(names[indexV])).display(); //������ �̸��� ���� �������� display�� ȣ��. �����Ƿ� ��Ʈ���� �Ѿ. ���� �ű⼭ ����ڰ� ������ �׼ǿ� ���� ���ϵ�

						if (recipeAction < 0) { //������ ������ ���
							deleteRecipe(names[indexV]);
						}
						else if (recipeAction>0){ //GroceryList�� �߰��ϴ� ���. �̶��� ���ϰ��� �κ� ���� ��
							(*Grocery).update_item(*searchRecipe(names[indexV]), recipeAction);
						}
					}

				}

				else if (indexH == 0) { //Search ����

					std::cout << "Please Enter the Keyword: ";
					std::string keyWord;
					std::cin >> keyWord;
					
					for (int i = 0; i < names.size(); ) { //Ű���带 �������� �ʴ� �̸��� ���� ����
						
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

				else if (indexH == 1) { // Add ����

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

					//Recipe�� �� ��ҵ��� �Է¹���

					std::cout << "Please Enter Recipe Name\n" << ": ";
					std::cin >> recipeName;
					std::cout << "Please Enter Picture Directory\n" << ": ";
					std::cin >> picture;
					std::cout << "Please Enter Ingridients Name, Quantity, Unit (ex: Sugar 5 spoon)" << std::endl;
					std::cout << "If you Entered All Ingridients, Enter 'done'.\n" << ": ";

					while (1){//done�� �Է¹ޱ� ������ ���� ������ ��Ḧ ��� �Է¹���
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

					while (1) { //done�� �Է¹ޱ� ������ ���������� ��� �Է¹���
						std::getline(std::cin, step);
						if (step == "done" || step == "Done") break;
						steps.push_back(step);
					}

					addRecipe(Recipe(recipeName, picture, servingSize, estimatedTime, ingridients, steps)); //�Է¹��� ���� �������� DB�� ������ �߰�



				}

				else if (indexH == 2) { //Exit ����
					system("cls");
					break;
				}
				
			}




		}

	}

	void showAll() { //������ �̸� ��ü ���.
		system("cls");

		for (auto r : recipes) {
			std::cout << r.getName() << '\n';
		}
	}

	Recipe* searchRecipe(std::string name) { //�����Ǹ� �˻� ��, �ش� �������� �ּҸ� ��ȯ.
		for (auto r : recipes) {
			if (r.getName() == name) {
				return &r;
			}
		}
		return NULL;
	}
	void addRecipe(Recipe a) { //DB�� ������ �߰�

		recipes.push_back(a);
	}
	void deleteRecipe(std::string name) { //Ư�� �̸��� ������ ����
		for (int i = 0; i < recipes.size(); i++) {
			if (recipes[i].getName() == name) {
				recipes.erase(recipes.begin() + i);
				break;
			}
		}


	}


};
