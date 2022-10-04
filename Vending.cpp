// Author: Atyub Ahmad
// Class: CMSC 341
//  File for Vending class that contains the functions' definitions

#include "Vending.h"

//Overloaded cout operator
ostream &operator<<(ostream &output, Item &myVending) {
    output << myVending.GetName() << ": (" << myVending.GetItemType() << "): ";
    return output;
}

//Default Constructor
Vending::Vending() {}

//Overloaded Constructor
Vending::Vending(vector<string> items) {
    LoadItem(items); //Calling LoadItem() to stock the Vending Machine
}

//Destructor
Vending::~Vending() {
    cout << "Deleting contents within m_slots: " << endl; //Letting the user know the destructor was called
    DisplayItems();
    //Deleting the content within m_slots which was dynamically allocated
    for(unsigned int i = 0; i < m_slots.size(); i++){
        delete m_slots.at(i).back();
    }
}

//Fills up the Vending Machine with items from the vector that was passed in from the file
void Vending::LoadItem(vector<string> items) {

    //Variables to take in each different information about the item
    string itemType, name, calories, weightOrOunces, typeOrNuts, quantity;

    //Loop to go through the items vector
    for(unsigned int i = 0; i < items.size(); i++) {
        queue<Item*> add; //Queue of the item that gets added to the m_slots vector
        istringstream ss(items[i]); //converting each line of the vector to a string stream

        //Getting each information
        getline(ss, itemType, ',');
        getline(ss, name, ',');
        getline(ss, calories, ',');
        getline(ss, weightOrOunces, ',');
        getline(ss, typeOrNuts, ',');
        getline(ss, quantity, ',');

        //Adding the name of the item to the directory
        m_directory.push_back(name);

        //Checking if the item is a drink
        if(itemType == "Drink") {
            //Creating a new drink object with all its necessary information
            Drink *vendingSlots = new Drink(name, stod(calories), typeOrNuts,stof(weightOrOunces), itemType);

            //Adding the item to the queue however many times it needs based on the quantity
            for(int i = 0; i < stoi(quantity); i++) {
                add.push(vendingSlots);
            }
            //Adding to the drinks vector (extra_driver.cpp)
            m_drinks.push_back(vendingSlots);

        //Snack
        } else{
            //Setting a boolean for checking if the snack contains nuts
            bool nuts = true;
            //Flipping the boolean if there are no nuts
            if(typeOrNuts == "false"){
                nuts = false;
            }
            //Creating a new snack object with all its necessary information
            Snack *vendingSlots = new Snack(name, stod(calories), itemType,stof(weightOrOunces), nuts);

            //Adding the item to the queue however many times it needs based on the quantity
            for(int i = 0; i < stoi(quantity); i++) {
                add.push(vendingSlots);
            }
            //Adding to the snacks vector (extra_driver.cpp)
            m_snacks.push_back(vendingSlots);
        }
        //Adding the queue into m_slots vector
        m_slots.push_back(add);


    }
    //Displaying the vending machine
    DisplayItems();
}

void Vending::AddItem(string item) {
    //Variables to take in each different information about the item
    string itemType, name, calories, weightOrOunces, typeOrNuts, quantity;

    queue<Item*> add; //Queue of the item that gets added to the m_slots vector

    istringstream ss(item); //converting the string to a string stream

    //Getting each information
    getline(ss, itemType, ',');
    getline(ss, name, ',');
    getline(ss, calories, ',');
    getline(ss, weightOrOunces, ',');
    getline(ss, typeOrNuts, ',');
    getline(ss, quantity, ',');

    //Adding the name of the item to the directory
    m_directory.push_back(name);


    //Checking if the item is a drink
    if(itemType == "Drink") {
        //Creating a new drink object with all its necessary information
        Drink *vendingSlots = new Drink(name, stod(calories), typeOrNuts,stof(weightOrOunces), itemType);

        //Adding the item to the queue however many times it needs based on the quantity
        for(int i = 0; i < stoi(quantity); i++) {
            add.push(vendingSlots);
        }
        //Adding to the drinks vector (extra_driver.cpp)
        m_drinks.push_back(vendingSlots);

        //Snack
    } else{
        //Setting a boolean for checking if the snack contains nuts
        bool nuts = true;
        //Flipping the boolean if there are no nuts
        if(typeOrNuts == "false"){
            nuts = false;
        }
        //Creating a new snack object with all its necessary information
        Snack *vendingSlots = new Snack(name, stod(calories), itemType,stof(weightOrOunces), nuts);

        //Adding the item to the queue however many times it needs based on the quantity
        for(int i = 0; i < stoi(quantity); i++) {
            add.push(vendingSlots);
        }
        //Adding to the snacks vector (extra_driver.cpp)
        m_snacks.push_back(vendingSlots);
    }
    //Adding the queue into m_slots vector
    m_slots.push_back(add);

}

//Vending the item out of the machine based off the index passed in from the vector or manual input
void Vending::UnloadItems(int index) {
    //Checking if there are multiple slots of the passed in item
    vector<int> foundSlots = FindProduct(m_slots.at(index).back()->GetName());

    //If there are multiple of the same item
    if(foundSlots.size() > 1){
        int maximum = 0; //Setting a variable to keep track of the desired slot

        //Looping through the foundSlots vector which contains the slots of the item
        for(unsigned int i = 0; i < foundSlots.size(); i++) {
            //Setting an edge case
            if(i+1 < foundSlots.size()) {
                //Comparing the quantity of the item from two different slots
                if (m_slots.at(foundSlots[i + 1]).size() > m_slots.at(foundSlots[i]).size()) {
                    //Setting maximum equal to the other slot if the quantity of the item is higher there
                    maximum = foundSlots[i + 1];
                } else {
                    //Setting maximum equal to this slot if the quantity of item is higher here
                    maximum = foundSlots[i];
                }
            }
        }

        //Checking if the slot is empty
        if(m_slots.at(maximum).empty()){
            cout << "No " << m_slots.at(maximum).back()->GetName() << " available to vend" << endl;
        }else {
            //Vending the item
            cout << "Vending: " << m_slots.at(maximum).back()->GetName() << " at slot " << maximum << endl;
            m_slots.at(maximum).pop();
        }

    //If the item is only in one slot
    }else{
        //Checking if the slot is empty
        if(m_slots.at(index).empty()){
            cout << "No " << m_slots.at(index).back()->GetName() << " available to vend" << endl;
        }else {
            //Vending the item
            cout << "Vending: " << m_slots.at(index).back()->GetName() << " at slot " << index << endl;
            m_slots.at(index).pop();
        }
    }

}

//Parsing the vector of ints passed in to be able to Unload the vending machine
void Vending::UnloadItems(vector<int> input) {

    //Looping through the vector
    for(unsigned int i = 0; i < input.size(); i++){
        //Calling UnloadItems(int) and passing through each integer within the vector
        UnloadItems(input[i]);
    }
}

//Finding multiple occurrences of the desired item
vector<int> Vending::FindProduct(string name) {
    vector<int> found; //Vector of ints
    int count = 0; //Keeps track of the slot number

    for(unsigned int i = 0; i < m_directory.size(); i++){
        //Checking if the directory equals the passed in name
        if(m_directory[i] == name){
            //Adding the slot number to the vector
            found.push_back(count);
        }
        count++; //Incrementing count
    }
    //Returning the vector of ints
    return found;
}

//Displays the content within the Vending Machine
void Vending::DisplayItems() {
    //Looping through m_slots
    for(unsigned int i = 0; i < m_slots.size(); i++) {
        //Printing the name, type, and quantity using the overloaded cout operator
        cout << *m_slots.at(i).back() << m_slots.at(i).size() <<endl;
    }
}

//Displays the information of each item within the vending machine
void Vending::DisplayStats() {
    //Looping through m_drinks
    for(unsigned int i = 0; i < m_drinks.size(); i++) {
        //Outputting information
        cout << "Name of Item: " << m_drinks.at(i)->GetName() << " | Type of Item: " << m_drinks.at(i)->GetItemType() <<
             " | Amount of Calories: " << m_drinks.at(i)->GetCalories() << " | Amount of Ounces: "
             << m_drinks.at(i)->GetOunces()<< endl;
    }
    //Looping through m_snacks
    for(unsigned int i = 0; i < m_snacks.size(); i++){
        //Checking if the snack has nuts or not
        string nuts = m_snacks.at(i)->GetContainsNuts() ? "Yes" : "No";
        //Outputting information
        cout << "Name of Item: " << m_snacks.at(i)->GetName() << " | Type of Item: " << m_snacks.at(i)->GetItemType()
             << " | Amount of Calories: " << m_snacks.at(i)->GetCalories() << " | Weight: "
             << m_snacks.at(i)->GetWeight()<< " | Contains Nuts: " << nuts << endl;
    }
}









