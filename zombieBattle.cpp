/*
 Taylor Cella
 Zombie Battle Game
 October 16th, 2018
 Compiled using g++ version 9.1.0
 */

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <algorithm>
#include <array>

using namespace std;

int roomNum;
int zomNum;
int regen;
int regeneration;
int zombCount = zomNum;
char* rooms = new char[roomNum];
char* zombies[100]; //Apparently you can't initialize a char* [] with an input variable, so I had to make do. This isn't the best solution.
char stun;
int randomNum;
void createGame(int roomNum, int zomNum, int regen);
void gameBoard();
void zombieRegen();
void winCheck();
void printBoard();

int main(int argc, char* argv[])
{
    //Creates variables based on input
    roomNum = stoi(argv[1]);
    zomNum = stoi(argv[2]);
    regen = stoi(argv[3]);
    
    //Checks for valid number of arguments
    if (argc < 3){
        cout << "Usage: Enter the number of rooms, a max number of zombies, and the desired zombie regeneration rate (as a number from 0 - 100)." << endl;
    }
    else if (roomNum < zomNum){
        cout << "You can't have more zombies than rooms. Try to run the program again." << endl;
    }
    else {
        //Start gameplay with arguments
        createGame(roomNum, zomNum, regen);
    }

}
    
void createGame(int roomNum, int zomNum, int regen){
    //Fills the room array as empty
    for(int i = 0; i < roomNum; i++){
        rooms[i] = 'E';
    }
    cout << endl;
    
    srand(time(0));
    
    //Points pointers in the zombie array to random spots in the room array
    for(int i = 0; i < roomNum; i++){
        randomNum = rand() % roomNum;
        zombies[i] = &rooms[randomNum];
        rooms[randomNum] = 'Z';
        zombCount++;
    }
    //Goes to game play
    gameBoard();
}

void printBoard(){
    for(int i = 0; i < roomNum; i++){
        cout << rooms[i] << " ";
    }
    cout << endl;
}

void gameBoard(){
    
    //Prints the board
    for (int i = 0; i < roomNum; i++){
        cout << '*' << " ";
    }
    cout << endl;
    for (int i = 1; i <= roomNum; i++){
        cout << i << " ";
    }
    cout << "test" << endl;
    cout << endl;
    
    int roomPick;
    
    //Allows for continuous play
    while (rooms[roomPick] != 'Z'){
        cout << "Please pick a room to shoot in." << endl;
        cin >> roomPick;
        cout << endl;
        //Reveals board if there is a zombie
        if(rooms[roomPick] == 'Z'){
            printBoard();
            cout << "The total number of zombies left are = " << zombCount << endl;
            zombieRegen();
        }
        //If there's no zombie, tries again
        else {
            cout << "No zombies here!" << endl;
        }
    }
    cout << endl;
}

//Sets zombies to stun or null
void zombieRegen(){
    int randomnum2;
    for(int i = 0; i < roomNum; i++){
        if(rooms[i] == 'Z'){
            //Stuns zombies automatically
            zombies[i] = &stun;
            randomnum2 = rand() % 100;
            //Regenerates zombies based on rate given
            if(randomnum2 > (100 - regen)){
                zombies[i] = &rooms[randomNum];
                cout << "A zombie has been regenerated" << endl;
                //Tries to make sure that more zombies aren't regenerated than how many are given, doesn't actually work
                if(zombCount < zomNum){
                    zombCount++;
                }
            }
            //If a zombie dies, set it to null and decrement the counter variable
            else{
                zombies[i] = nullptr;
                cout << "A zombie has died" << endl;
                zombCount--;
            }
        }
    }
    //Checks for win condition
    winCheck();
}

void winCheck(){
    int count;
    //If the pointer is set to null and the count of zombies is negative, then the game is over
    for(int i=0; i < zomNum; i++){
        if(zombies[i] == nullptr){
            if(zombCount < 0){
                cout << "All the zombies are dead! You win!" << endl;
                exit(0);
            }
            //Otherwise, start over with a new random board to make the game more complicated
            else {
                createGame(roomNum, zomNum, regen);
            }
        }
    }
}
