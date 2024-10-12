#pragma once
#ifndef RECIPE_H
#define RECIPE_H

#include "GroceryItem.h" // ���ش��� �ۼ��� GroceryItem ����
#include "GroceryList.h" // GroceryList ����
#include <string>
#include <vector>

class Recipe {

public:
    std::string name;                // �丮 �̸�
    std::string picture;             // ���� ��� �Ǵ� ���� �̸�
    std::vector<GroceryItem> ingredients; // ��� ��� (GroceryItem ��ü�� ����)
    int serving_size;                // �� �κ� ����
    int estimated_time;              // ���� �ð� (�� ����)
    std::vector<std::string> steps;  // �غ� �ܰ�

    // ������
    Recipe(std::string name, std::string picture, int serving_size, int estimated_time, std::vector<GroceryItem> ingredients, std::vector<std::string> steps);

    // ��ü ��� ���
    int display();

    // ��� ��� �Լ�
    void displayIngredients();

    // �غ� �ܰ� ��� �Լ�
    void displaySteps();

    // ������ ���� �Լ�(�ܰ質 ��� �߰��� �ƴ϶� �ƿ� ó������ ���Ӱ� ����)
    void editRecipe();

    // ��� �߰� �Լ� (GroceryItem ��ü�� �̿��� ���� �߰�)
    void addIngredient(const GroceryItem& ingredient);

    // ��� �߰��ϴ� �Լ� (����� �Է��� ���� GroceryItem ��ü�� ���� �� �߰�)
    void addIngredientByInput();

    // �ܰ� �߰��ϴ� �Լ�
    void addStepByInput();

    // ������ ������ �ؽ�Ʈ ���Ϸ� �����ϴ� �Լ�
    void printToFile(const std::string& filename);

    // getter �Լ���
    std::string getName() const { return name; }
    std::string getPicture() const { return picture; }
    int getServingSize() const { return serving_size; }
    int getEstimatedTime() const { return estimated_time; }
    std::vector<GroceryItem> getIngredients() const { return ingredients; }
    std::vector<std::string> getSteps() const { return steps; }
};

#endif // RECIPE_H
