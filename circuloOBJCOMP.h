//
//  circuloOBJCOMP.h
//  circuloOBJCOMPOSICION
//
//  Created by Valeria Conde on 27/02/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef circuloOBJCOMP_h
#define circuloOBJCOMP_h

using namespace std;

class Coordenada {
private:
    int x;
    int y;
public:
    Coordenada() {
        x = 0;
        y = 0;
    }
    
    Coordenada(int x, int y) {
        this -> x = x;
        this -> y = y;
    }
    
    void setX(int x) {
        this -> x = x;
    }
    
    void setY(int y) {
        this -> y = y;
    }
    
    int getX() {
        return x;
    }
    
    int getY() {
        return y;
    }
    
    void show() {
        cout << "X: " << x << " Y: " << y << endl;
    }
    
};

#endif /* circuloOBJCOMP_h */
