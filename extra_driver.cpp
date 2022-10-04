// Author: Atyub Ahmad
// Extra driver for Vending Machine

#include <iostream>
#include "Item.h"
#include "Datafile.h"
#include "Vending.h"

int main(){
    cout << "TEST 1: LOADING IN THE VENDING MACHINE" << endl;

    Datafile dataItem = Datafile();
    vector<string> items = dataItem.LoadDirectory();
    Vending vend = Vending(items);

    cout << "END TEST 1" << endl << endl;

    cout << "TEST 2: DISPLAYING ITEMS AND THEIR STATS" << endl;
    vend.DisplayStats();
    cout << "END TEST 2" << endl << endl;

    cout << "TEST 3: VENDING ITEMS" << endl;
    //Check input.txt and see if it takes from the Coca-Cola with the greater amount first
    // and check if it is the same amount it takes from the lower indexed slot
    vend.UnloadItems(dataItem.LoadSampleInput());
    cout << "END TEST 3" << endl << endl;


    cout << "TEST 4: DISPLAYING ITEMS TO CHECK IF AMOUNTS DECREASED PROPERLY" << endl;
    vend.DisplayItems();
    cout << "END TEST 4" << endl << endl;

    cout << "TEST 5: ADDING ITEMS WITHOUT FILE" << endl;
    vend.AddItem("Drink,Coca-Cola,120,16,Soda,1");
    vend.AddItem("Snack,Jerky,220,4,false,3");
    vend.DisplayItems();
    cout << "END TEST 5" << endl << endl;

    cout << "TEST 6: VENDING ITEMS WITHOUT FILE" << endl;
    vend.UnloadItems(6);
    vend.UnloadItems(7);
    vend.UnloadItems(6);
    cout << endl;
    vend.DisplayItems();
    cout << "END TEST 6" << endl << endl;

    cout << "TEST 7: DESTRUCTOR" << endl;


    return 0;
}
