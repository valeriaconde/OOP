//
//  Avion.h
//  OOPproyectoIntegrador
//
//  Created by Valeria Conde on 05/03/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Avion_h
#define Avion_h
using namespace std;

class Avion {
private:
    string nombre;
    int capacidad;
public:
    // Constructores
    Avion() {
        nombre = "";
        capacidad = 0;
    }
    
    Avion(string nombre, int capacidad) {
        this -> nombre = nombre;
        this -> capacidad = capacidad;
    }
    
    Avion(string nombre) {
        this -> nombre = nombre;
        capacidad = 0;
    }
    
    // getters
    string getNombre() {
        return nombre;
    }
    
    int getCapacidad() {
        return capacidad;
    }
    
    // setters
    void setNombre(string nombre) {
        this -> nombre = nombre;
    }
    
    void setCapacidad(int capacidad) {
        this -> capacidad = capacidad;
    }
};

#endif /* Avion_h */
