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

    void add_item(std::string name, float quantity, std::string unit);  //GroceryItem 객체를 GroceryList의 GroceryItem 벡터에 추가.
    void update_item(const Recipe& recipe, int people);     // GroceryItem 객체가 있을 경우 양 추가, 없을 경우 객체 추가.
    void remove_item(const Recipe& recipe, int people);     // GroceryItem 객체가 있을 경우 양 제거, 만약 quantity가 0보다 작아지면 객체 삭제.
    void reset_items();                                     // GroceryItem 벡터를 초기화
    void display();                                         // Greeter에서 제어권을 넘겨받고, 있는 레시피와 식재료 목록을 출력, 선택지 출력 및 수행
    void save_to_txt(const std::string& filename) const;    // txt 파일에 현재 식재료 목록을 저장.
    void load_from_txt(const std::string& filename);        // txt 파일에 저장된 식재료 목록을 불러옴.

private:
    std::vector<GroceryItem> items;
    std::vector<Recipe> saved_recipes;
};

#endif // GROCERYLIST_H
