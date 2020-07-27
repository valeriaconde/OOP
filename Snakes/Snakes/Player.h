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
    bool win;
    
public:
    // CONSTRUCTORS
    
    // Empty constructor
    Player() {
        currentTile = 0;
        playerNumber = 1;
        win = 0;
    }
    
    // Constructor with parameter for player number
    Player(int playerNumber) {
        currentTile = 0;
        this -> playerNumber = playerNumber;
        win = 0;
    }
    
    // Getters
    int getCurrentTile() {
        return currentTile;
    }
    
    int getPlayerNumber() {
        return playerNumber;
    }
    
    int getStatus() {
        return win;
    }
    
    // Setters
    void setCurrentTile(int currentTile) {
        this-> currentTile = currentTile;
    }
    
    void setPlayerNumber(int playerNumber) {
        this-> playerNumber = playerNumber;
    }
    
    void setStatus(bool win) {
        this-> win = win;
    }
    
};

#endif /* Player_h */
