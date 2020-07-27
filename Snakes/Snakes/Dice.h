//
//  Dice.h
//  Snakes
//
//  Created by Valeria Conde on 14/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Dice_h
#define Dice_h

#include <iostream>
using namespace std;

#include <time.h>
#include <stdlib.h>

class Dice {
public:
    Dice() {
        srand(time(0));
    }
    
    int getRoll() {
        return  (rand() % 6) + 1;
    }
};

#endif /* Dice_h */
