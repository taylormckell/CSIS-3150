#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <ctime>
#include "quotes.h"

using namespace std;

//class functions
Quote::Quote()
{
    cout << "Now entering the menu " << endl;
    quoteMenu();
}

Quote::Quote(string fileName) : fileName(fileName) {
    getRandomQuote(fileName);
}

Quote::~Quote(){}

void Quote::quoteMenu() {
    int input;
    string name;
    cout << "Welcome to the menu! First, please enter the name of the file that you want to use. " << endl;
    cin >> name;
    cout << "Thank you! Now, here is the menu. Enter a number to pick the corresponding option. " << endl;
    cout << "1. Get Random Quote " << endl;
    cout << "2. Add a Quote " << endl;
    cout << "3. Remove a Quote by Line " << endl;
    cout << "4. Get Specific Quote by Line " << endl;
    cout << "5. Get Number of Current Quotes " << endl;
    cout << "6. Quit " << endl;
    cin >> input;
    switch(input){
        case 1:
            getRandomQuote(name);
            break;
        case 2:
            addLine(name);
            break;
        case 3:
            removeLine(name);
            break;
        case 4:
            getQuoteByLine(name);
            break;
        case 5:
            numLines(name);
            break;
        default:
            exit(1);
    }
}

void Quote::getRandomQuote(string fileName){
    ifstream infile (fileName);
    srand(time(NULL));
    int linenum = rand() % 31;
    string line;
    int lines_read = 0;
    int i = 0;
    //Checks to see if the file exists
    if (!infile){
        cout << "Your input file does not exist." << endl;
        exit(1);
    }
    else {
        //Reads in line by line, gets rid of default delimiter and returns the whole line
        char str[255];
        while(infile.getline(str, 255))
        {
            lines_read++;
            if (lines_read == linenum) {
                cout << "Your line is: " << "'" << str << "'" << endl;
                break;
            }
        }
        infile.close();
    }
    exit(1);
}

void Quote::addLine(string fileName){
    ofstream outfile (fileName, ios_base::app | ios_base::out);
    string input;
    cout << "Please enter a line that you'd like to input. " << endl;
    getline(cin, input);
    outfile << "\n" << input;
    exit(1);
}

void Quote::removeLine(string fileName){
    ifstream infile (fileName);
    ofstream outfile ("OutputFile.txt");
    string myArray[100];
    int lineNumber;
    int index=0;
    string line;
    cout << "Please enter a line number to remove. " << endl;
    cin >> lineNumber;
    
    if (!infile){
        cout << "Your input file does not exist." << endl;
        exit(1);
    }
    else {
        while (infile)
        {
            getline(infile,line);
            myArray[index] = line;
            index++;
        }
        infile.close();
    }
    for(int i = 0; i < index; i++){
        myArray[lineNumber-1] = " ";
    }
    for(int i = 0; i < index; i++){
        outfile << myArray[i] << endl;
    }
    exit(1);
}

void Quote::getQuoteByLine(string fileName){
    ifstream infile (fileName);
    string myArray[100];
    int lineNumber;
    int index=0;
    string line;
    cout << "Please enter a line number for the quote that you want. " << endl;
    cin >> lineNumber;
    if (!infile){
        cout << "Your input file does not exist." << endl;
        exit(1);
    }
    else {
        while (infile) //while the end of file is NOT reached
        {
            getline(infile,line); //get one line from the file
            myArray[index] = line;
            index++;
        }
        infile.close(); //closing the file
    }
    for(int i = 0; i < index; i++){
        line = myArray[lineNumber];
    }
    cout << line << endl;
    exit(1);
}

void Quote::numLines(string fileName){
    ifstream infile ("Quotes.txt");
    string myArray[100];
    int lineNumber;
    int index=0;
    string line;
    if (!infile){
        cout << "Your input file does not exist." << endl;
        exit(1);
    }
    else {
        while (infile) //while the end of file is NOT reached
        {
            getline(infile,line); //get one line from the file
            myArray[index] = line;
            index++;
        }
        infile.close(); //closing the file
    }
    cout << "The number of lines in the file is: " << index << endl;
    exit(1);
}
