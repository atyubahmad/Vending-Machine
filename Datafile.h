// Author: Atyub Ahmad
// Header file for Datafile class

#ifndef DATAFILE_H
#define DATAFILE_H
#include "Item.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;



class Datafile{
public:
    //Default Constructor
    Datafile();
    //Destructor
    ~Datafile();
    //Reads in the file with the items and returns a vector of the items (strings)
    vector<string> LoadDirectory();
    //Reads in a file of the input and returns a vector of inputs (integers)
    vector<int> LoadSampleInput();
    //Returns a vector of the items (strings)
    vector<string> GetDirectory();
    //Returns a vector of inputs (integers)
    vector<int> GetSelections();


private:
    //Member variable for both files
    string m_fileName;
    string m_fileName1;
};




#endif
