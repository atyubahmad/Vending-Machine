// Author: Atyub Ahmad
// Header file for Drink class

#ifndef DRINK_H
#define DRINK_H
#include "Item.h"

class Drink: public Item{
public:
    //Default Constructor
    Drink();
    //Overloaded Constructor
    Drink(string, double, string, float, string);
    //Destructor
    ~Drink();
    //Setters
    void SetOunces(float);
    void SetType(string);
    //Getters
    float GetOunces();
    string GetType();

    //Overloaded cout operator
    friend ostream &operator<< (ostream &output, Drink &myDrink);

private:
    //Specific member variables needed by this class
    float m_ounces;
    string m_type;
};


#endif
