/*
 Taylor Cella
 Hex / ASCII Converter
 October 24th, 2018
 Compiled using g++ version 9.1.0
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>

using namespace std;
string infileName;
string outfileName;
string line;
string token;
char delimiter;
int i;
void toASCII();
void toHex();
char txt;

// This code currently gives a segmentation fault, because of issues with the command line input. The logic for conversion is correct and works just fine if the ifstream infile is given a file name directly within the code, ie ifstream infile("in.txt"), but doesn't work for command line arguments. I know this is a big part of the assigment and I don't know why it's not working, so I'm sorry that it's not easily testable. The conversion does work though, but I know the main portion of the points comes from it all actually working as expected.

int main(int argc, char* argv[])
{

    //Is supposed to take the file in and out name as inputs, along with the deliminator.
    infileName = (argv[1]);
    outfileName = (argv[2]);
    delimiter = stoi(argv[3]);
    
    //Supposed to check if the input file is converting from hex or ascii
    string hexCheck = "HEX_";
    string ascCheck = "ASC_";
    if (argc < 3){
        cout << "Usage: Enter an input file to convert, the name of the output file, as well as a delimiter." << endl;
        cout << "To convert from ASCII to Hex, make sure your input file starts with ASC_" << endl;
        cout << "To convert from Hex to ASCII, make sure your input file starts with HEX_" << endl;
    }
    //If valid input
    else {
        //If starts with hex, go to ascii converter
        if(infileName.find(hexCheck) != string::npos){
            toASCII();
        }
        //If starts with asc, go to hex converter
        else if(infileName.find(ascCheck) != string::npos){
            toHex();
        }
        else{
            cout << "That is not an appropriate file name." << endl;
            return 0;
        }
    }
}

void toASCII(){
    //Reads in the file and creates output file
    ifstream infile (infileName);
    ofstream outfile (outfileName);
    //Checks to see if the file exists
    if (!infile){
        cout << "Your input file does not exist." << endl;
    }
    else {
        //Reads in line by line
        while(getline(infile, line))
        {
            infile >> line;
            istringstream ss(line);
            //Gets the lines but separates by the delimiter
            while(getline(ss, token, delimiter)) {
                //Puts the character before the delimiter into the stringstream
                istringstream iss (token);
                //Converts to hex
                iss.flags(std::ios::hex);
                //Makes an int
                iss >> i;
                //Converts int to char to show ascii value
                outfile << (char)i << endl;
            }
        }
    //Closes file
    infile.close();
    }
}

void toHex(){
    ifstream infile (infileName + ".txt");
    ofstream outfile (outfileName + ".txt");
    int value;
    char input;
    long lnum;
    if (!infile){
        cout << "Your input file does not exist." << endl;
    }
    else {
        //Gets the single character instead of a string
        while(infile.get(input))
        {
            //Reads input
            infile >> input;
            //Converts character into number
            value = (int)input;
            //Converts decimal number into hex and puts it into the outfile
            outfile << std::hex << value << endl;
        }
    }
    //Closes file
    infile.close();
}

