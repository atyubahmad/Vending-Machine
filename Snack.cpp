// Author: Atyub Ahmad
// File for Snack class that contains functions' definitions

#include "Snack.h"

//Overloaded cout operator
ostream &operator<< (ostream &output, Snack &mySnack){
    output << "Snack: " << mySnack.GetName() << ", Calories: " << mySnack.GetCalories() << ", Weight: " << mySnack.m_weight
           << ", Contains Nuts: " << mySnack.m_containsNuts << endl;
    return output;
}

//Default Constructor
Snack::Snack() {
    //Setting default values
    m_weight = 0.0;
    m_containsNuts = false;
}

//Overloaded Constructor, that uses Initialization list to inherit from Item class
Snack::Snack(string name, double calories, string itemType, float weight, bool containsNuts):Item(name, calories, itemType){
    //Setting member variables
    m_weight = weight;
    m_containsNuts = containsNuts;
}

//Destructor
Snack::~Snack() {}

//Setting weight
void Snack::SetWeight(float weight) {
    m_weight = weight;
}

//Setting ContainsNuts
void Snack::SetContainsNuts(bool containsNuts) {
    m_containsNuts = containsNuts;
}

//Getting weight
float Snack::GetWeight() {
    return m_weight;
}

//Getting ContainsNuts
bool Snack::GetContainsNuts() {
    return m_containsNuts;
}


