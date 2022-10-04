// Author: Atyub Ahmad
//Driver file for Vending Machine

#include <iostream>
#include "Datafile.h"
#include "Item.h"
#include "Vending.h"

int main() {
    //Passing in the files  names
    Datafile dataItem =  Datafile();

    cout << "Items available to vend: " << endl;

    //Setting a vector equal to the vector return from LoadDirectory()
    vector<string> items = dataItem.LoadDirectory();

    //Making a Vending object and calling the overloaded constructor
    Vending vend = Vending(items); //Loads the Vending Machine
    cout << endl;

    //Unloading the Vending Machine
    vend.UnloadItems(dataItem.LoadSampleInput());
    cout << endl;

    //Displaying the content within Vending Machine
    vend.DisplayItems();
    cout << endl;

    return 0;
}
