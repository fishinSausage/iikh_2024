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
	};// ������, Greeter�� GroceryList�� ������ �޾ƿ�

	void display();
	void showAll();	//��ü ���
	Recipe* searchRecipe(std::string name); //�̸��� ��ġ�ϴ� ������ �ּ� ��ȯ
	void addRecipe(Recipe a); //�����Ǹ� DB�� �߰�
	void deleteRecipe(std::string name); //�̸��� ��ġ�ϴ� ������ ����

private:
	std::vector<Recipe> recipes;	//����� ������ ����
	GroceryList* Grocery;		//�����ؾ��� GroceryList �ּ�

};

#endif