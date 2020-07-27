//  Snakes
//
//  Created by Valeria Conde on 14/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

class Board {
private:
    int totalTiles = 30;
    
    // Tile array for the board
    vector<char> tiles;
    
    // Random seed
    static int seed(int i) {
        return rand() % i;
    }
public:
    
    // CONSTRUCTORS
    // Empty constructor
    Board() {
        // Adds 3 snakes and 3 ladders to the board
        for(int i = 0; i < 3; i++) {
            tiles.push_back('S');
            tiles.push_back('L');
        }
        
        // Fills the rest of the board with normal tiles
        for(int i = 0; i < totalTiles - 6; i++) {
            tiles.push_back('N');
        }
        
        // Random shuffles all the tiles in the board
        srand(unsigned(time(0)));
        do {
            random_shuffle(tiles.begin(), tiles.end(), seed);
        } while (tiles[totalTiles - 1] == 'S');

    }
    
    // Updates current tile with dice roll
    int newTile(int currentTile, int diceRoll) {
        currentTile += diceRoll;
        if(currentTile > 29) currentTile = 29;
        
        cout << tiles[currentTile] << " ";
        
        if(tiles[currentTile] == 'L') currentTile = min(currentTile + 3, 29);
        else if(tiles[currentTile] == 'S') currentTile = max(0, currentTile - 3);
        
        return currentTile;
    }
    
    
    // Getters
    vector<char> getTiles() {
        return tiles;
    }
    
    // Setters
    void setTile(vector<char> tiles) {
        this -> tiles = tiles;
    }
};

class Player {
private:
    int currentTile;
    int playerNumber;
    
public:
    // CONSTRUCTORS
    // Empty constructor
    Player() {
        currentTile = 0;
        playerNumber = 1;
    }
    
    // Constructor with parameter for player number
    Player(int playerNumber) {
        currentTile = 0;
        this -> playerNumber = playerNumber;
    }
    
    // Getters
    int getCurrentTile() {
        return currentTile;
    }
    
    int getPlayerNumber() {
        return playerNumber;
    }
    
    // Setters
    void setCurrentTile(int currentTile) {
        this-> currentTile = currentTile;
    }
    
    void setPlayerNumber(int playerNumber) {
        this-> playerNumber = playerNumber;
    }
};

class Dice {
public:
    Dice() {
        srand(time(0));
    }
    
    int getRoll() {
        return  (rand() % 6) + 1;
    }
};

class MyGame {
public:
    void start() {
        // Variables
        int winner = 0;
        
        // Prints initial message
        cout << "Press C to continue next turn, or E to end the game:" << endl;

        // Store player's answer
        char ans = 'C';
        
        // Count turns
        int turn = 1;
        
        // Two players
        Player one;
        Player two(2);
        Board board;
        
        do {
            // Variables
            int playing, diceNum;
            Dice dice;
            int newTileNum;
            
            cin >> ans;
            switch (toupper(ans)) {
                case 'C':
                    
                    // Print turn number
                    cout << turn << " ";

                    // Determines which player is playing
                    turn % 2 == 1 ? playing = 1 : playing = 2;
                    cout << playing << " ";

                    // Rolls dice
                    diceNum = dice.getRoll();

                    // Does the corresponding moves to the player playing
                    if (playing == 1) {
                        cout << one.getCurrentTile() + 1 << " ";
                        cout << diceNum << " ";

                        newTileNum = board.newTile(one.getCurrentTile(), diceNum);


                        cout << newTileNum + 1 << endl;
                        
                        one.setCurrentTile(newTileNum);
                    } else {
                        cout << two.getCurrentTile() + 1 << " ";
                        cout << diceNum << " ";
                        
                        
                        newTileNum = board.newTile(two.getCurrentTile(), diceNum);

                        cout << newTileNum + 1 << endl;
                        
                        two.setCurrentTile(newTileNum);
                    }
                                        
                    turn++;
                    break;
                    
                case 'E':
                    cout << "--GAME OVER--" << endl;
                    cout << "Thanks for playing!!" << endl;
                    break;
                    
                default:
                    cout << "Invalid option, please press C to continue next turn of E to end the game" << endl;
                    break;
            }
            
            // Checks if anyone has won and ends the game
            if (newTileNum == 29) {
                winner = playing;
                ans = 'E';
            }
        } while (ans != 'E');
        
        cout << "--GAME OVER--" << endl;
        if (winner == 1 || winner == 2) cout << "Player " << winner << " is the winner!!!" << endl;
    }
};

int main() {
    MyGame game;
    game.start();
    return 0;
}
