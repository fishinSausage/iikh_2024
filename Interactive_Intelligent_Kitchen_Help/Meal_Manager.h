#ifndef MEAL_MANAGER_H
#define MEAL_MANAGER_H

#include <iostream>
#include <string>
#include <vector>
#include <Date.h>
#include <GroceryList.h>
public:
    // Date 인스턴스의 벡터 (각 날짜에 대한 정보를 저장)
    vector<Date*> dates;

    // 생성자
    MealManager();

    // 달력 출력 및 각 작업을 수행할 수 있는 메인 메소드
    void displayCalendar();

    // 날짜 선택
    void selectDate();

    // 특정 기간의 모든 Meal 출력
    void printMealsForDate();

    // 특정 기간의 장보기 목록 출력
    void printGrocery();
};

#endif