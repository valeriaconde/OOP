// main.cpp
//  vuelosCLASES
//
//  Created by Valeria Conde
//  A02382647
//  20/02/20


#include <iostream>
#include <string>
#include <vector>
#include "vuelosArrObj.h"
#include <fstream>

using namespace std;

int main() {
    
    
    Vuelo unVuelo;
    int vuelo;
    string pais, matricula;
    int totalVuelos = 0;
    vector<Vuelo> arrVuelos;
    
    ifstream archivo;
    archivo.open("vueloshoy.txt");
        
    
    while (archivo >> pais >> matricula >> vuelo) {
        Vuelo unVuelo(pais, matricula, vuelo);
        arrVuelos.push_back(unVuelo);
    }
    
    for (int i = 0; i < arrVuelos.size(); i++) {
        totalVuelos += arrVuelos[i].getVuelo();
    }
    
    cout << "Paises con los que se tiene mayor contacto:" << endl;
    
    for (int i = 0; i < arrVuelos.size(); i++) {
        if (arrVuelos[i].getVuelo() >= totalVuelos / 10.0) {
            arrVuelos[i].show();
        }
    }

    archivo.close();
    
    return 0;
}
