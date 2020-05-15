//
//  main.cpp
//  Snakes
//
//  Created by Valeria Conde on 14/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
#include "Board.h"

/*
 
 1. imprimir el mensaje de inicio
 2. leer de la consola
 3. si no es letra valida, imprimir mensaje y volver a leer
 4. si es letra valida, si es E, imprimir game over
 5. 
 
 
 
 */



class MyGame {
public:
    void over() {
        cout << "--GAME OVER--" << endl;
    }
    
    void start() {
        // Prints initial message
        cout << "Press C to continue next turn, or E to end the game:" << endl;

        // Variable to store player's answer
        char ans = 'C';
        
        do {
            cin >> ans;
            switch (ans) {
                case 'C':
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    break;
                    
                case 'E':
                    over();
                    break;
                    
                default:
                    cout << "Invalid option, please press C to continue next turn of E to end the game" << endl;
                    break;
            }
        } while (ans != 'E');
        
        
        
        
        
        
        
        
        
        
    }
};

int main() {

    MyGame game;
    game.start();
    return 0;
}
