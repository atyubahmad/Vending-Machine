// Author: Atyub Ahmad
// File for Drink class that contains functions' definitions

#include "Drink.h"

//Overloaded cout operator
ostream &operator<< (ostream &output, Drink &myDrink){
    output << "Drink: " << myDrink.GetName() << ", Calories: " << myDrink.GetCalories() << ", Ounces: " <<
           myDrink.m_ounces << ", Type: " << myDrink.m_type << endl;
    return output;
}

//Default Constructor
Drink::Drink() {
    //Default values
    m_ounces = 0.0;
    m_type = "";
}

//Overloaded Constructor, using Initialization list to inherit from Item class
Drink::Drink(string name, double calories, string itemType, float ounces, string type):Item(name, calories, itemType) {
    //Setting the member variables
    m_ounces = ounces;
    m_type = type;
}

//Destructor
Drink::~Drink() {}

//Setting Ounces
void Drink::SetOunces(float ounces) {
    m_ounces = ounces;
}

//Setting Type
void Drink::SetType(string type) {
    m_type = type;
}

//Getting Ounces
float Drink::GetOunces() {
    return m_ounces;
}

//Getting Type
string Drink::GetType() {
    return m_type;
}


