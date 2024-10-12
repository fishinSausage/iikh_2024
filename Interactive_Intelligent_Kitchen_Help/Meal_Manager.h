#ifndef MEAL_MANAGER_H
#define MEAL_MANAGER_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MealManager {
public:
    // Date �ν��Ͻ��� ���� (�� ��¥�� ���� ������ ����)
    vector<Date*> dates;

    // ������
    MealManager();

    // �޷� ��� �� �� �۾��� ������ �� �ִ� ���� �޼ҵ�
    void displayCalendar();

    // ��¥ ����
    void selectDate();

    // Ư�� �Ⱓ�� ��� Meal ���
    void printMealsForDate();

    // Ư�� �Ⱓ�� �庸�� ��� ���
    void printGrocery();
};

#endif