#pragma once
#ifndef RECIPE_H
#define RECIPE_H

#include "GroceryItem.h" // 승준님이 작성한 GroceryItem 포함
#include "GroceryList.h" // GroceryList 포함
#include <string>
#include <vector>

class Recipe {

public:
    std::string name;                // 요리 이름
    std::string picture;             // 사진 경로 또는 파일 이름
    std::vector<GroceryItem> ingredients; // 재료 목록 (GroceryItem 객체로 구성)
    int serving_size;                // 몇 인분 기준
    int estimated_time;              // 예상 시간 (분 단위)
    std::vector<std::string> steps;  // 준비 단계

    // 생성자
    Recipe(std::string name, std::string picture, int serving_size, int estimated_time, std::vector<GroceryItem> ingredients, std::vector<std::string> steps);

    // 전체 요소 출력
    int display();

    // 재료 출력 함수
    void displayIngredients();

    // 준비 단계 출력 함수
    void displaySteps();

    // 레시피 수정 함수(단계나 재료 추가가 아니라 아예 처음부터 새롭게 구성)
    void editRecipe();

    // 재료 추가 함수 (GroceryItem 객체를 이용해 직접 추가)
    void addIngredient(const GroceryItem& ingredient);

    // 재료 추가하는 함수 (사용자 입력을 통해 GroceryItem 객체를 만든 후 추가)
    void addIngredientByInput();

    // 단계 추가하는 함수
    void addStepByInput();

    // 레시피 정보를 텍스트 파일로 저장하는 함수
    void printToFile(const std::string& filename);

    // getter 함수들
    std::string getName() const { return name; }
    std::string getPicture() const { return picture; }
    int getServingSize() const { return serving_size; }
    int getEstimatedTime() const { return estimated_time; }
    std::vector<GroceryItem> getIngredients() const { return ingredients; }
    std::vector<std::string> getSteps() const { return steps; }
};

#endif // RECIPE_H
