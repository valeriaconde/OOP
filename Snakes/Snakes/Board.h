//  Board.h
//  Snakes
//
//  Created by Valeria Conde on 14/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.

#ifndef Board_h
#define Board_h

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



#endif /* Board_h */
