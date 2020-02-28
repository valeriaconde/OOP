//  main.cpp
//  actCalificaciones
//
//  Created by Valeria Conde
//  A01281637
// 13/02/20.

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
    string calificaciones[20][20];
    string nombre;
    string calif;
    int indice = 0, suma = 0;
    ifstream archivo;
    
    archivo.open("calificaciones.txt");
    
    while (archivo >> nombre >> calif) {
        
        nombre = "";
        
        while (nombre != "x") {
            cout << "Teclea tu nombre: ";
            cin >> nombre;
            if (nombre != "x") {
                cout << "Teclea la calificacion: ";
                cin >> calif;
                calificaciones[indice][0] = nombre;
                calificaciones[indice][1] = calif;
                suma += stoi(calif);
                indice++;
            }
        }
        
        
        for(int i = 0; i < indice; i++) {
            cout << "Nombre: " << calificaciones[i][0] << " Calificacion: " << calificaciones[i][1] << endl;
        }
        
        cout << "La suma de calificaciones es: " << suma << " y el promedio es: " << suma/indice << endl;
            
    }
    
    archivo.close();
    
    return 0;
}
