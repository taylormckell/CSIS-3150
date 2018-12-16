/*
 Taylor Cella
 Dungeon Master Main File
 October 3rd, 2018
 Compiled using g++ version 9.1.0
 */

#include <iostream>
#include "dungeon.h"

using namespace std;

int main() {
    //Explains rules and instructions
    dungeonArt();
    cout << "Welcome to the dungeon master game!" << endl;
    cout << "How to play: " << endl;
    cout << "Your hero is represented by the * sign, and the object of the game is to make it from start to finish ('E') without dying." << endl;
    cout << "To move, enter the direction that you want your character to go (North, West, South, East), but not every move is safe. " << endl;
    cout << "Some parts of the dungeon contain traps, and hitting one will decrease your health." << endl;
    cout << "You must stay within the dungeon! If you try to move into a wall and go off of the board, you will automatically die, so be careful!" << endl;
    cout << "Enjoy the game, and good luck!" << endl;
    cout << endl;
    //Moves user into actual gameplay
    simpleCharBoard();
}



