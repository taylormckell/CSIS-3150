/*
 Taylor Cella
 Random Array / Health / Play again / ASCII Art functions
 October 3rd, 2018
 Compiled using g++ version 9.1.0
 */

#include <iostream>
#include "dungeon.h"

using namespace std;
int ranarray[10][10];
int playerhealth = 100;

//Fills an array with random numbers from 1-9, creates an array that is the same size as the board to move in conjunction
void ranArrayFill()
{
    srand(time(NULL));
    for (int i=0; i<10; i++) {
        for (int j=0; j<10; j++){
            ranarray[i][j] = rand() % 10;
        }
    }
}

//Determines health based off of traps
bool playerHealthStatus(int x, int y){
    //If the random array at spot that the user moves is a 4, 8, or 2, the user loses 10 health points.
    if(ranarray[x][y] == 4 or ranarray[x][y] == 8 or ranarray[x][y] == 2 or ranarray[x][y] == 3){
        playerhealth -= 10;
        trapArt();
        cout << "Oh no! You've hit a trap. Your health level is now at " << playerhealth << endl;
        //If player health decreases down to zero, the player has lost and has the chance to play again.
        if(playerhealth == 0){
            cout << "You're out of health, and your hero has died! Better luck next time.";
            playAgain();
        }
        return true;
    }
    return false;
}

//Tells user when they have won, and tells how much health they have left along with the option to play again.
void winCondition(){
    cout << endl;
    winArt();
    cout<< endl;
    cout << "Congratulations! You made it through the dungeon with " << playerhealth << " health left!" << endl;
    playAgain();
}

// Allows the user to play again if wanted. Moves to the main game play function to start over, doesn't give instructions again.
void playAgain(){
    cout << "Do you want to play again? Please enter yes or no." << endl;
    string playagain;
    cin >> playagain;
    if(playagain == "yes"){
        main();
    }
    else{
        cout << "Goodbye!" << endl;
        exit(0);
    }
}

void dungeonArt(){
    cout<<"                          .-----."<< endl;
    cout<<"                       .'        `."<<endl;
    cout<<"                      :      ^v^   :"<<endl;
    cout<<"                      :            :"<< endl;
    cout<<"                      '            '"<< endl;
    cout<<"       |~        www   `.        .'"<< endl;
    cout<<"      /.\\       /#^^\\_   `-/\\--'"<<endl;
    cout<<"     /#  \\     /#%    \\   /# \\"<< endl;
    cout<<"    /#%   \\   /#%______\\ /#%__\\"<< endl;
    cout<<"   /#%     \\   |= I I ||  |- |"<<endl;
    cout<<"   ~~|~~~|~~   |_=_-__|'  |[]|"<<endl;
    cout<<"     |[] |_______\\__|/_ _ |= |`."<<endl;
    cout<<" ^V^ |-  /= __   __    /-\\|= | :;"<<endl;
    cout<<"     |= /- /\\/  /\\/   /=- \\.-' :;"<<endl;
    cout<<"     | /_.=========._/_.-._\\  .:'"<<endl;
    cout<<"     |= |-.'.- .'.- |  /|\\ |.:'"<<endl;
    cout<<"     \\  |=|:|= |:| =| |~|~||'|"<<endl;
    cout<<"      |~|-|:| -|:|  |-|~|~||=|      ^V^"<<endl;
    cout<<"      |=|=|:|- |:|- | |~|~|| |"<<endl;
    cout<<"      | |-_~__=_~__=|_^^^^^|/___"<<endl;
    cout<<"      |-(=-=-=-=-=-(|=====/=_-=/\\"<<endl;
    cout<<"      | |=_-= _=- _=| -_=/=_-_/__\\"<<endl;
    cout<<"      | |- _ =_-  _-|=_- |]#| I II"<<endl;
    cout<<"      |=|_/ \\_-_= - |- = |]#| I II"<<endl;
    cout<<"      | /  _/ \\. -_=| =__|]!!!I_II!!"<<endl;
    cout<<"     _|/-'/  ` \\_/ \\|/' _ ^^^^`.==_^."<<endl;
    cout<<"   _/  _/`-./`-; `-.\\_ / \\_'\\`. `. ===`."<<endl;
    cout<<"  / .-'  __/_   `.   _/.' .-' `-. ; ====;\\"<<endl;
    cout<<" /.   `./    \\ `. \\ / -  /  .-'.' ====='  >"<<endl;
    cout<<"/  \\  /  .-' `--.  / .' /  `-.' ======.' /"<<endl;
}

void trapArt(){
    cout<<" __  .___________.      ._______.        ___         .___________..______          ___      .______    __"<<endl;
    cout<<"|  | |           |     /        |       /   \\        |           ||   _  \\        /   \\     |   _  \\  |  |"<<endl;
    cout<<"|  | `---|  |----`     |   (----`      /  ^  \\       `---|  |----`|  |_) |       /  ^  \\    |  |_)  | |  |"<<endl;
    cout<<"|  |     |  |           \\   \\         /  /_\\  \\          |  |     |      /      /  /_\\  \\   |   ___/  |  |"<<endl;
    cout<<"|  |     |  |       .----)   |       /  _____  \\         |  |     |  |\\  \\----./  _____  \\  |  |      |__|"<<endl;
    cout<<"|__|     |__|       |_______/       /__/     \\__\\        |__|     | _| `._____/__/     \\__\\ | _|      (__)"<<endl;
    
}

void winArt(){
    cout<<"dP    dP                     dP   dP   dP oo          dP dP dP"<<endl;
    cout<<"Y8.  .8P                     88   88   88             88 88 88"<<endl;
    cout<<"Y8aa8P  .d8888b. dP    dP    88  .8P  .8P dP 88d888b. 88 88 88"<<endl;
    cout<<"  88    88'  `88 88    88    88  d8'  d8' 88 88'  `88 dP dP dP"<<endl;
    cout<<"  88    88.  .88 88.  .88    88.d8P8.d8P  88 88    88"<<endl;
    cout<<"  dP    `88888P' `88888P'    8888' Y88'   dP dP    dP oo oo oo"<<endl;
}



