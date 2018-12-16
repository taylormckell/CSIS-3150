/*
 Taylor Cella
 Quote Generator / Text Editor that I cried over but eventually finished and was proud of
 November 1st, 2018
 Compiled using g++ version 9.1.0
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <ctime>
#include "quotes.h"

using namespace std;

//class driver
int main(int argc, char *argv[])
{
    if(argc == 1){
        Quote q;
    }
    if(argc == 2){
        string inputFile = argv[1];
        Quote r(inputFile);
    }
    else {
        cout << "Usage: " << endl;
        cout << "If you'd like to get a random quote, enter the name of the file you'd like to read from." << endl;
        cout << "If you'd like to see the menu, don't enter any input." << endl;
        cout << "num of arguments is " << argc << endl;
        return(0);
    }
    
}
