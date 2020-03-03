//
//  circuloOBJCOMP_circulo.h
//  circuloOBJCOMPOSICION
//
//  Created by Valeria Conde on 27/02/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef circuloOBJCOMP_circulo_h
#define circuloOBJCOMP_circulo_h

// incluir la clase en el header
#include "circuloOBJCOMP.h"

using namespace std;

class Circulo {
private:
    Coordenada coord;
    int radio;
public:
    Circulo() {
        coord = Coordenada();
        radio = 1;
    }
    
    Circulo(Coordenada coord, int radio) {
        this -> coord = coord;
        this -> radio = radio;
    }
    
    void setCoord(Coordenada coord) {
        this -> coord = coord;
    }
    
    void setRadio(int radio) {
        this -> radio = radio;
    }
    
    Coordenada getCoord() {
        return coord;
    }
    
    int getRadio() {
        return radio;
    }
    
    void show() {
        coord.show();
        cout << "Radio: " << radio << endl;
    }
};


#endif /* circuloOBJCOMP_circulo_h */
