//
//  Player.h
//  Snakes
//
//  Created by Valeria Conde on 14/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Player_h
#define Player_h

class Player {
private:
    int currentTile;
    int playerNumber;
    bool won;
    
public:
    // CONSTRUCTORS
    
    // Empty constructor
    Player() {
        currentTile = 1;
        playerNumber = 1;
        won = 0;
    }
    
    // Constructor with parameter for player number
    Player(int playerNumber) {
        currentTile = 1;
        this -> playerNumber = playerNumber;
        won = 0;
    }
    
    
    
};

#endif /* Player_h */
