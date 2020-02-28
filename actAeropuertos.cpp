//  main.cpp
//  actAeropuertos
//  Este programa lee un archivo de texto que contiene vuelos y regresa los paises con los que se tiene mas del 20% de los vuelos totales

//  Created by Valeria Conde
//  A01281637
//  13/02/20.

/*
 CASOS PRUEBA
 Mexico DS 400
 Brasil XD 2
 Holanda FH 4
 Arabia RK 3
 REGRESA:
 Mexico
 
 Mexico DS 50
 Brasil XD 50
 Holanda FH 4
 Arabia RK 3
 REGRESA:
 Mexico
 Brasil
 
 */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Vuelo.h"

using namespace std;

int main() {
 
    string pais, matricula;
    int numVuelos, totalVuelos = 0;
    vector<string> arrPaises;
    vector<int> arrVuelos;
    
    ifstream archivo;
    archivo.open("vueloshoy.txt");
    
    while (archivo >> pais >> matricula >> numVuelos) {
        arrPaises.push_back(pais);
        arrVuelos.push_back(numVuelos);
    }
    
    for (int i = 0; i < arrVuelos.size(); i++) {
        totalVuelos += arrVuelos[i];
    }
    
    cout << "Paises con los que se tiene mayor contacto:" << endl;
    
    for (int i = 0; i < arrVuelos.size(); i++) {
        if (arrVuelos[i] >= totalVuelos / 5.0) {
            cout << arrPaises[i] << endl;
        }
    }

    archivo.close();

    return 0;
}
