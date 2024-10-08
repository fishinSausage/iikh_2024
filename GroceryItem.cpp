#include "GroceryItem.h"

GroceryItem::GroceryItem(std::string name, float quantity, std::string unit)        //GroceryItem의 생성자
    : name(name), quantity(quantity), unit(unit) {}

const std::string GroceryItem::get_name() const {       // GroceryItem의 이름을 반환하는 게터
    return name;
}

float GroceryItem::get_quantity() const {               // GroceryItem의 양을 반환하는 게터
    return quantity;
}

const std::string GroceryItem::get_unit() const {       // GroceryItem의 단위를 반환하는 게터
    return unit;
}

void GroceryItem::add_quantity(float additional_quantity) {     // GroceryList에 이미 동일한 GroceryItem이 존재할 경우, 양만 추가해주기 위함.
    quantity += additional_quantity;
}

std::string GroceryItem::to_file_format() const {                       // GroceryItem 객체를 파일 형식으로 변환.
    return name + "," + std::to_string(quantity) + "," + unit;
}

GroceryItem GroceryItem::from_file_format(const std::string& line) {    // 파일에서 읽은 문자열을 GroceryItem 객체로 변환
    size_t nameEnd = line.find(',');
    size_t qtyEnd = line.find(',', nameEnd + 1);

    std::string name = line.substr(0, nameEnd);
    float quantity = std::stof(line.substr(nameEnd + 1, qtyEnd - nameEnd - 1));
    std::string unit = line.substr(qtyEnd + 1);

    return GroceryItem(name, quantity, unit);
}
