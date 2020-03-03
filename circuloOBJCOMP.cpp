//
//  main.cpp
//  circuloOBJCOMPOSICION
//
//  Created by Valeria Conde
//  A01281637

//  27/02/20
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
#include "circuloOBJCOMP.h"
#include "circuloOBJCOMP_circulo.h"

using namespace std;

int main() {
    
    int x, y, radio;
    Coordenada coord;
    Circulo circ;
    
    cout << "Teclea coordenada x, y y el radio" << endl;
    cin >> x >> y >> radio;
    
    coord = Coordenada(x, y);
    circ = Circulo(coord, radio);
    circ.show();
    
    return 0;
}
