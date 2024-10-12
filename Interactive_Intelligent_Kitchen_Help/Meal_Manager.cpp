
#include <iostream>
#include <string>
#include <vector>
#include "Date.h"


using namespace std;

class MealManager {
public:
  // Date 인스턴스의 벡터 (각 날짜에 대한 정보를 저장)
  vector<Date *> dates;

  MealManager() : dates(31, nullptr) {} // 처음에는 모든 인덱스가 nullptr

  // 달력 출력 및 각 작업을 수행할 수 있는 메인 메소드
  void displayCalendar() {
    while (true) {
      cout << "This Month's Calendar" << endl;

      for (int i = 0; i < 2; ++i) {
        cout << "   "; // 화요일이 1일이므로 두칸 띄고 출력
      }

      for (int i = 0; i < 31; ++i) {
        if (dates[i] != nullptr) {
          if (dates[i]->hasMeal()) {
            cout << (i + 1) << "* ";
          }
        } else {
          cout << (i + 1) << " ";
        }
        if ((i + 3) % 7 == 0) {
          cout << endl; // 7일씩 한 줄로 표시
        }
      }
      cout << "\n" << endl;

      // 작업 선택 메뉴 출력
      cout << "1. Select Date" << endl;
      cout << "2. Print Menu" << endl;
      cout << "3. PrintGrocery List" << endl;
      cout << "4. Exit" << endl;
      cout << "Select (1-4): ";

      int choice;
      cin >> choice;

      switch (choice) {
      case 1:
        selectDate();
        break;
      case 2:
        printMealsForDate();
        break;
      case 3:
        printGrocery();
        break;
      case 4:
        cout << "Exit." << endl;
        return;
      }
    }
  }

  // 날짜 선택
  void selectDate() {
    cout << "Select Date (1-30): ";
    int selectedDate;
    cin >> selectedDate;

    // 날짜가 비어있는 경우 새로운 Date 객체 생성하고 추가
    if (dates[selectedDate - 1] == nullptr) {
      dates[selectedDate - 1] = new Date();
    }

    // 선택한 날짜의 display 호출 (Date 클래스에서 작업 처리)
    dates[selectedDate - 1]->display();
  }

  // 특정 기간의 모든 Meal 출력
  void printMealsForDate() {
    int startDate, endDate;
    cout << "Enter The Start And End Dates (ex: 3 10): ";
    cin >> startDate >> endDate;

    for (int i = startDate; i <= endDate; ++i) {
      if (dates[i - 1] != nullptr) {
        if (dates[i - 1]->hasMeal()) {
          dates[i - 1]->display();
        }
      } else {
        cout << "No Meals For This Date" << endl;
      }
    }
  }

  // 특정 기간의 장보기 목록 출력
  void printGrocery() {
    int startDate, endDate;
    cout << "Enter The Start And End Dates (ex: 3 10): ";
    cin >> startDate >> endDate;

    // 새로운 GroceryList 생성
    GroceryList groceryList;

    // 선택한 날짜 범위 내 모든 Date 인스턴스의 장보기 목록 추가
    for (int i = startDate; i <= endDate; ++i) {
      dates[i - 1]->addToGroceryList(groceryList);
    }

    // 생성된 장보기 목록 출력
    groceryList.print();

    // 임시 GroceryList 객체 삭제 (스코프가 끝나면 자동으로 소멸됨)
  }
};