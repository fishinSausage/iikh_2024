#include "Greeter.h"
#include "Meal_Manager.cpp"
#include <iostream>

#include <string>

void Greeter::show() // 메인함수에서 실행할 함수
{
    std::cout << "Welcome to IIKH (Interactive Intelligent Kitchen Helper)!" << std::endl;
    while (true)
    {
        select_option();
    }
}

void Greeter::print_greeting(int selected_option) // select_option에서 실행될 환영 메시지 및 안내 함수
{
    std::cout << "Please select an option: " << std::endl;
    
    const char* options[4] = {
        "1. Recipe Data Base Manager",
        "2. Meal Manager",
        "3. Grocery List",
        "4. Exit"
    };

    // 선택 옵션에 arrow key를 표시하여 옵션 출력
    for (int i = 0; i < 4; i++) {
        if (i == selected_option) {
            std::cout << "-> " << options[i] << std::endl; // 현재 선택중인 옵션 가리킴.
        }
        else {
            std::cout << "   " << options[i] << std::endl; // 선택중이지 않은 옵션은 빈칸으로
        }
    }
}

void Greeter::select_option()
{
    int selected_option = 0;

    while (true) {
        system("cls");
        print_greeting(selected_option); // 환명 메시지 및 옵션 표시

        char keyInput = _getch();
        if (keyInput == -32) { // arrow 키를 사용하기 위해 첫번째 키코드를 -32로 받음. 방향키 입력이 들어온지 확인하는 코드.
            keyInput = _getch(); // 방향키를 입력받음
            switch (keyInput) {
            case 72: // 윗 방향키
                if (selected_option > 0) {
                    selected_option--; // 위의 옵션으로
                }
                break;
            case 80: // 아래 방향키
                if (selected_option < 3) {// 인덱스는 0~3까지
                    selected_option++;
                }
                break;
            }
        }
        else if (keyInput == 13) { // 엔터 키 입력 시
            system("cls");
            switch (selected_option) {
            case 0:
                std::cout << "Recipe Data Base Manager selected.\n" << std::endl;
                // recipeDB.display();
                break;
            case 1:
                std::cout << "Meal Manager selected.\n" << std::endl;
                // mealmanager.display();
                break;
            case 2:
                std::cout << "GroceryList selected.\n" << std::endl;
                items.display();
                break;
            case 3:
                std::cout << "Exit the IIKH.\n";
                exit(0);
                break;
            default:
                std::cout << "Wrong choice. Please try again.\n";
                break;
            }
        }
    }
}
