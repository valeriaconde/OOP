//
//  main.cpp
//  clases
//
//  Created by Valeria Conde on 17/02/20.
//  A01281637

#include <iostream>
#include <string>

using namespace std;

#include "Rectangulo.h"

int main() {
    
    char resp;
    int nuevoAncho, nuevoLargo;
    Rectangulo rectA;
    Rectangulo rectB(8, 2);
    
    rectA.Despliega();
    cout << "Area: " << rectA.Area() << endl;
    rectB.Despliega();
    cout << "Area: " << rectB.Area() << endl;
    
    cout << "Cual objeto quiere cambiar? (A o B)" << endl;
    cin >> resp;
    
    if (resp == 'a') {
        cout << "Nuevo ancho: ";
        cin >> nuevoAncho;
        rectA.setAncho(nuevoAncho);
        cout << "Nuevo largo: ";
        cin >> nuevoLargo;
        rectA.setLargo(nuevoLargo);
        
        rectB.setLargo(rectB.getAncho());
        rectB.setAncho(rectB.getLargo());
        
    } else if (resp == 'b') {
        cout << "Nuevo ancho: ";
        cin >> nuevoAncho;
        rectB.setAncho(nuevoAncho);
        cout << "Nuevo largo: ";
        cin >> nuevoLargo;
        rectB.setLargo(nuevoLargo);
        
        rectA.setLargo(rectA.getAncho());
        rectA.setAncho(rectA.getLargo());
    } else {
        cout << "Triangulo no existe" << endl;
    }
    
    return 0;
}
