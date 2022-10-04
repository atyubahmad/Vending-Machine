// Author: Atyub Ahmad
// Header file for Item (Parent) class

#include <iostream>
#include <string>
#ifndef ITEM_H
#define ITEM_H
using namespace std;

class Item{
public:
    //Default Constructor
    Item();
    //Overloaded Constructor
    Item(string, double, string);
    //Destructor
    ~Item();
    //Setters
    void SetName(string);
    void SetCalories(double);
    void SetItemType(string);
    //Getters
    string GetName();
    double GetCalories();
    string GetItemType();
private:
    //Member variables needed for this class
    string m_name;
    float m_calories;
    string m_itemType;
};



#endif
