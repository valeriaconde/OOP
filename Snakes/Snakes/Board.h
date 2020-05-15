//  Board.h
//  Snakes
//
//  Created by Valeria Conde on 14/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.

#ifndef Board_h
#define Board_h

class Board {
private:
    const int initialTile = 1;
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
        random_shuffle(tiles.begin(), tiles.end(), seed);
        
        for(int i =0; i < tiles.size(); i++) cout << tiles[i] << endl;
        cout << tiles.size() << endl;
    }
    
    // 
    int newTile(int currentTile, int diceRoll) {
        currentTile += diceRoll;
        if(currentTile > 29) currentTile = 29;
        
        if(tiles[currentTile] == 'L') currentTile = min(currentTile + 3, 29);
        else if(tiles[currentTile] == 'S') currentTile = max(0, currentTile - 3);
        
        return currentTile;
    }
    
    
    
    
    
    
    
    
    
};



#endif /* Board_h */
