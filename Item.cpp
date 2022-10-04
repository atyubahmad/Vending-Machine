// Author: Atyub Ahmad
// File for Item class that contains functions' definitions

#include "Item.h"

//Default constructor
Item::Item() {
    //Default values
    m_name = "";
    m_calories = 0.0;
    m_itemType = "";
}

//Overloaded Constructor for use of Initialization lists used by Drink and Snack
Item::Item(string name, double calories, string itemType) {
    //Setting the member variables
    m_name = name;
    m_calories = calories;
    m_itemType = itemType;
}

//Destructor
Item::~Item() {}

//Setting name
void Item::SetName(string name) {
    m_name = name;
}

//Setting calories
void Item::SetCalories(double calories) {
    m_calories = calories;
}

//Setting the type of item
void Item::SetItemType(string itemType) {
    m_itemType = itemType;
}

//Getting name
string Item::GetName() {
    return m_name;
}

//Getting calories
double Item::GetCalories() {
    return m_calories;
}

//Getting type of the item
string Item::GetItemType() {
    return m_itemType;
}



