// Author: Atyub Ahmad
// File for Datafile class that contains functions' definitions

#include "Datafile.h"

//Default Constructor
Datafile::Datafile(){
    //Setting the member variables to the correct file
    m_fileName = "directory.txt";
    m_fileName1 = "input.txt";
}

//Destructor
Datafile::~Datafile() {}


//Reads in the file with the items and returns a vector of the items (strings)
vector<string> Datafile::LoadDirectory() {
    //Variable to hold each line of the file
    string item;
    //Vector to hold each item
    vector<string> items;

    //Reading and opening the file
    ifstream itemfile(m_fileName);

    //Checking if the file is open
    if(itemfile.is_open()){

        //While the file isn't at the end
        while(itemfile.peek() != EOF){
            //Storing each line of the file into the variable
            getline(itemfile, item);
            //Adding to the vector
            items.push_back(item);

        }
        //Closing the file
        itemfile.close();

    //Error Statement
    } else{
        cout << "Directory file did not open" << endl;
    }
    //Returning the vector
    return items;
}

vector<int> Datafile::LoadSampleInput() {
    //Variable to hold each line of the file
    string input;
    //Vector to hold each item
    vector<int> inputs;

    //Reading and opening the file
    ifstream inputfile(m_fileName1);

    //Checking if the file is open
    if(inputfile.is_open()){
        //cout << "File opened" << endl;
        while (inputfile.peek() != EOF){
            //While the file isn't at the end
            getline(inputfile, input);
            //Adding to the vector
            inputs.push_back(stoi(input));
        }
        //Closing the file
        inputfile.close();

    //Error Statement
    } else{
        cout << "Input file did not open" << endl;
    }
    //Returning the vector
    return inputs;
}

//Returns a vector of the items (strings)
vector<string> Datafile::GetDirectory() {
    //Setting a vector equal to the vector being returned from LoadDirectory()
    vector<string> items = LoadDirectory();
    //Returning the vector
    return items;
}

//Returns a vector of inputs (integers)
vector<int> Datafile::GetSelections() {
    //Setting a vector equal to the vector being returned from LoadSampleInput()
    vector<int> inputs = LoadSampleInput();
    //Returning the vector
    return inputs;
}


