//
//  Vuelo.h
//  OOPproyectoIntegrador
//
//  Created by Valeria Conde on 05/03/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include "Avion.h"
#include "Itinerario.h"
#ifndef Vuelo_h
#define Vuelo_h
using namespace std;

class Vuelo {
private:
    Itinerario itinerario;
    Avion avion;
    string aerolinea;
    int numPasajeros;
public:
    // Constructores
    Vuelo() {
        itinerario = Itinerario();
        avion = Avion();
        aerolinea = "";
        numPasajeros = 0;
    }
    
    Vuelo(Itinerario itinerario, Avion avion, string aerolinea, int numPasajeros) {
        this -> itinerario = itinerario;
        this -> avion = avion;
        this -> aerolinea = aerolinea;
        this -> numPasajeros = numPasajeros;
    }
    
    // getters
    Itinerario getItinerario() {
        return itinerario;
    }
    
    Avion getAvion() {
        return avion;
    }
    
    string getAerolinea() {
        return aerolinea;
    }
    
    int getNumPasajeros() {
        return numPasajeros;
    }
    
    //setters
    void setItinerario(Itinerario itinerario) {
        this -> itinerario = itinerario;
    }
    
    void setAvion(Avion avion) {
        this -> avion = avion;
    }
    
    void setAerolinea(string aerolinea) {
        this -> aerolinea = aerolinea;
    }
    
    void setNumPasajeros(int numPasajeros) {
        this -> numPasajeros = numPasajeros;
    }
};

#endif /* Vuelo_h */
