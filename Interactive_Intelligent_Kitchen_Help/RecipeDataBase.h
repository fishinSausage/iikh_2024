#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <conio.h>
#include "GroceryList.h"
#include "Recipe.h"

class RecipeDB
{

public:

	RecipeDB(GroceryList* groceryList) {
		Grocery = groceryList;
	};// 생성자, Greeter의 GroceryList를 참조로 받아옴

	void display();
	void showAll();	//전체 출력
	Recipe* searchRecipe(std::string name); //이름이 일치하는 레시피 주소 반환
	void addRecipe(Recipe a); //레시피를 DB에 추가
	void deleteRecipe(std::string name); //이름이 일치하는 레시피 제거

private:
	std::vector<Recipe> recipes;	//저장된 레시피 집합
	GroceryList* Grocery;		//참조해야할 GroceryList 주소

};

#endif