// Author: Atyub Ahmad
// Header file for Vending class

#ifndef VENDING_H
#define VENDING_H
#include "Datafile.h"
#include "Item.h"
#include "Snack.h"
#include "Drink.h"
#include <queue>
#include <sstream>

class Vending{
public:
    //Default Constructor
    Vending();
    //Overloaded Constructor that takes in a vector of strings
    Vending(vector<string>);
    //Destructor
    ~Vending();
    //Loads in the items from the vector into the Vending Machine
    void LoadItem(vector<string>);
    //Loads in an item manually passed into the Vending Machine
    void AddItem(string);
    //Unloads an item from the Vending Machine (Both from a vector and manual input)
    void UnloadItems(int);
    //Unloads a vector of integers to be singly passed through to UnloadItems(int)
    void UnloadItems(vector<int>);
    //Finds matching products from different slots
    vector<int> FindProduct(string);
    //Displays content within the Vending Machine using the overloaded cout operator
    void DisplayItems();
    //Displays item's information (Used in extra_driver.cpp for extra credit)
    void DisplayStats();
    //Overloaded cout operator
    friend ostream &operator<< (ostream &output, Item &myVending);


private:
    vector<string> m_directory; //Vector with all the item's names
    vector<queue<Item*>> m_slots; //Vector that acts like the actual Vending Machine

    //Two vectors that separate drinks and snacks from the vending machine (extra vectors used for extra_driver.cpp for extra credit)
    vector<Drink*> m_drinks;
    vector<Snack*> m_snacks;
};

#endif
