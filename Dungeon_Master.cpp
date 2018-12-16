/*
 Taylor Cella
 Dungeon Master Functions
 October 3rd, 2018
 Compiled using g++ version 9.1.0
 */

#include <iostream>
#include "dungeon.h"

using namespace std;
char chararray[10][10] = {
    { '#', '#', '#', '#', '#', '#','#', '#', '#', '#'},
    { 'S', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','#'},
    { '#', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', '#'},
    { '#', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', '#'},
    { '#', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', '#'},
    { '#', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', '#'},
    { '#', ' ', ' ', ' ', ' ',' ', ' ', ' ', ' ', '#'},
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','#'},
    { '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ','E'},
    { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
};

//Contains all conditions for movement based off of user input
void simpleCharBoard (){
    char input;
    setHero();
    printBoard();
    ranArrayFill();
    //Allows user to continually update movement until they quit or reach a win or lose condition
    while(input != 'q'){
    cout << "Where do you want to move? Please enter either n, w, e, or s. If you want to quit the game, enter 'q.'" << endl;
    cin >> input;
    int x,y;
        switch (input){
            case 'w':
                //Right and left are controlled by the y value, so update accordingly based off of movement
                //Checks to see if the user has gotten to the exit and not a wall
                x = getPos(y);
                if (!isWall(x, y-1)){
                    if(isExit(x, y-1)){
                            winCondition();
                        }
                    }
                //If the user hasn't hit a wall, check for traps, and update health and spot based off of movement
                if(!isWall(x,y-1)){
                    playerHealthStatus(x,y);
                    chararray[x][y] = space;
                    update(x,y-1);
                }
                break;
        
            case 's':
                    x = getPos(y);
                //Up and down are controlled by the x value, so update accordingly based off of movement
                //Checks to see if the user has gotten to the exit and not a wall
                    if (!isWall(x+1, y)){
                        if(isExit(x+1, y)){
                            winCondition();
                        }
                    }
                //If the user hasn't hit a wall, check for traps, and update health and spot based off of movement
                    if(!isWall(x+1,y)){
                        playerHealthStatus(x,y);
                        chararray[x][y] = space;
                        update(x+1,y);
                    }
                break;

            case 'n':
                x = getPos(y);
                //Up and down are controlled by the x value, so update accordingly based off of movement
                //Checks to see if the user has gotten to the exit and not a wall
                    if (!isWall(x-1, y)){
                        if(isExit(x-1, y)){
                            winCondition();
                        }
                    }
                //If the user hasn't hit a wall, check for traps, and update health and spot based off of movement
                    if(!isWall(x-1,y)){
                        playerHealthStatus(x,y);
                        chararray[x][y] = space;
                        update(x-1,y);
                    }
                break;
                    
            case 'e':
                x = getPos(y);
                    //Checks to see if the user has gotten to the exit and not a wall
                    if(!isWall(x, y+1)){
                        if(isExit(x, y+1)){
                            winCondition();
                        }
                    }
                    //If the user hasn't hit a wall, check for traps, and update health and spot based off of movement
                    if(!isWall(x,y+1)){
                        playerHealthStatus(x,y);
                        chararray[x][y] = space;
                        update(x,y+1);
                    }
                break;
            // Allows the user to quit if needed
            case 'q':
                cout << "Goodbye!" << endl;
                exit(0);
               break;
            default: main();
        }
    }
}

//Prints the game play board to the screen
void printBoard(){
        for (int i=0; i<10; ++i){
            for (int j=0; j<10; ++j)
                cout << " " << chararray[i][j];
                cout << endl;
        }
}

//Gets the position of the character so that it can be move through the board
int getPos(int &y){
    int xCoord;
        for (int i = 0; i < 10; ++i){
            for (int j = 0; j < 10; ++j){
                if (chararray[i][j] == hero){
                    xCoord = i;
                    y = j;
                    return xCoord;
                }
            }
        }
    return 0;
}

//Gets the x coordinate and makes sure the hero is set to start in the beginning place ('S')
int getX(int &y){
    int xCoord;
        for (int i = 0; i < 10; ++i){
            for (int j = 0; j < 10; ++j){
                if (chararray[i][j] == 'S'){
                    xCoord = i;
                    y = j;
                    return xCoord;
                }
            }
        }
    return 0;
}

//Checks to see if the user has made it out of the dungeon
bool isExit(int x, int y){
    //'E' marks the exit, if the user is at that spot in the array they have won
    if (chararray[x][y] == 'E'){
        return true;
    }
    else {
        return false;
    }
    return true;
}

//Checks to see if user is going off of the map
bool isWall(int x, int y){
    //# marks walls, and as such the end of the map
    if (chararray[x][y] == '#'){
        playerhealth = 0;
        cout << "You went off of the board! You lose. Better luck next time!" << endl;
        playAgain();
        return true;
    }
    return false;
}

//Updates the board to show the character at a new spot based on input given through x and y
void update(int x, int y){
    chararray[x][y] = hero;
    printBoard();
}

//Puts the hero in the beginning spot of the array to start
void setHero(){
    int x, y;
    x = getX(y);
    chararray[x][y] = hero;
}


