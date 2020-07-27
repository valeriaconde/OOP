//
//  Sobre.h
//  tarea herencia
//
//  Created by Valeria Conde on 20/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Sobre_h
#define Sobre_h
#include "Envio.h"
#include "Cliente.h"

class Sobre : public Envio {
private:
    double cargoAdicional = 0;
public:
    // Constructor
    Sobre(Cliente remitente, Cliente destinatario, int largo, int ancho) : Envio(remitente, destinatario, largo, ancho) {
    }
    
    // Getters
    double getCargoAdicional() {
        return cargoAdicional;
    }
    
    // Setters
    void setCargoAdicional(double cargoAdicional) {
        this -> cargoAdicional = cargoAdicional;
    }
    
    // calculaCosto
    double calculaCosto() {
        if (getLargo() > 25 || getAncho() > 25) {
            cargoAdicional += 30;
            return getCostoEstandar() + cargoAdicional;
        } else {
            return getCostoEstandar();
        }
    }
    
    // str
    void str() {
        cout << "Informacion de sobre:" << endl;
        cout << "Remitente: ";
        getRemitente().str();
        cout << "\nDestinatario: ";
        getDestinatario().str();
        cout << "\nCosto Estandar: " << getCostoEstandar() << endl;
        cout << "Largo: " << getLargo() << endl;
        cout << "Ancho: " << getAncho() << endl;
        cout << "Cargo adicional: " << cargoAdicional << endl;
        cout << "-------------------------\n";
    }
};

#endif /* Sobre_h */
