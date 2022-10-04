// Author: Atyub Ahmad
// Header file for Snack class

#ifndef SNACK_H
#define SNACK_H
#include "Item.h"
class Snack: public Item{
public:
    //Default Constructor
    Snack();
    //Overloaded Constructor
    Snack(string, double, string, float, bool);
    //Destructor
    ~Snack();

    //Setters
    void SetWeight(float);
    void SetContainsNuts(bool);

    //Getters
    float GetWeight();
    bool GetContainsNuts();

    //Overloaded cout operator
    friend ostream &operator<< (ostream &output, Snack &mySnack);

private:
    //Member variables needed by this class
    float m_weight;
    bool m_containsNuts;
};
#endif
