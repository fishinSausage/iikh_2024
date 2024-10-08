#ifndef GROCERYITEM_H
#define GROCERYITEM_H

#include <string>

class GroceryItem           // GroceryItem은 식재료의 이름과 양, 단위를 가지는 클래스임.
{                           // GroceryItem을 정의한 이유: GroceryList의 벡터에 GroceryItem의 객체들을 저장하기 위해.
private:
    std::string name;       // GroceryItem의 이름
    std::string unit;       // GroceryItem의 단위
    float quantity;         // GroceryItem의 양 

public:
    GroceryItem(std::string name, float quantity, std::string unit);
    /*-----게터-----  */ 
    const std::string get_name() const;     // GroceryItem의 이름을 반환하는 함수
    float get_quantity() const;             // GroceryItem의 양을 반환하는 함수 
    const std::string get_unit() const;     // GroceryItem의 단위를 반환하는 함수

    void add_quantity(float additional_quantity);   // GroceryList에 이미 동일한 GroceryItem이 존재할 경우, 양만 추가해주기 위함.

    std::string to_file_format() const;                             // GroceryItem 객체를 파일 형식으로 변환.
    static GroceryItem from_file_format(const std::string& line);   // 파일에서 읽은 문자열을 GroceryItem 객체로 변환
};

#endif // GROCERYITEM_H
