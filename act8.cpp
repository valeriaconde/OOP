//
//  main.cpp
//  act8
//
//  Created by Valeria Conde on 27/02/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "act8Persona.h"
#include "act8Taxi.h"

using namespace std;

// Agrega un taxi a un vector por referencia donde se guardan todos los taxis
void agregarTaxi(vector<Taxi> &arr) {
    string nombre, telefono;
    int id;
    
    cout << "Ingrese los datos del Taxi.\n Responsable: ";
    cin >> nombre;
    cout << "Numero de telefono: ";
    cin >> telefono;
    cout << "ID de taxi: ";
    cin >> id;

    Persona responsable(nombre, telefono);
    Taxi nuevoTaxi(responsable, id);
    
    arr.push_back(nuevoTaxi);
    
    cout << "Taxi agregado :D" << endl;
}

// Despliega los taxis disponibles
void muestraTaxis(vector<Taxi> &arr) {
    
    cout << arr.size() << " taxis disponibles\n" << endl;
    
    if (arr.size() != 0) {
        cout << "Taxis disponibles:" << endl;
        
        for (int i = 0; i < arr.size(); i++) {
            arr[i].show();
        }
    }
}

// Busca un taxi a partir del nombre del responsable
void buscaTaxi(vector<Taxi> &arr) {
    
    string man;
    bool encontrado = false;
    
    cout << "Nombre del responsable que desea buscar" << endl;
    cin >> man;
    
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i].getPersona().getNombre() == man) {
            arr[i].show();
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontro ningun taxi con responsable " << man << " :(" << endl;
    }
}

int main() {
    
    char ans;
    vector<Taxi> arr;
    
    do {
        cout << "Que desea hacer?" << endl;
        cout << "1. Agregar taxis a la lista.\n2. Consultar la lista de Taxis disponibles. \n3.Busqueda de Taxis por responsable. \n0.Salir.\n";
        cin >> ans;
        
        switch (ans) {
            case '1':
                agregarTaxi(arr);
                break;
            case '2':
                muestraTaxis(arr);
                break;
                
            case '3':
                buscaTaxi(arr);
                break;
                
            case '0':
                break;
                
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
    } while (ans != '0');
        
    // princessval rocks

    cout << "Bai! :D" << endl;

    return 0;
}
