//  main.cpp
//  actCalificaciones
//
//  Created by Valeria Conde
//  A01281637
// 13/02/20.

#include <iostream>
#include <string>

using namespace std;

int main() {
    
    string nombres[20];
    int califs[20];
    string nombre;
    int calif, indice = 0;
    
    nombre = "";
    
    while (nombre != "x") {
        cout << "Teclea tu nombre: ";
        cin >> nombre;
        if (nombre != "x") {
            cout << "Teclea la calificacion: ";
            cin >> calif;
            nombres[indice] = nombre;
            califs[indice] = calif;
            indice++;
        }
        
        for(int i = 0; i < indice; i++) {
            cout << "Nombre: " << nombres[i] << " Calificacion: " << califs[i] << endl;
        }
    }
    
    
    return 0;
}
