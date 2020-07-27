//
//  Envio.h
//  tarea herencia
//
//  Created by Valeria Conde on 20/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Envio_h
#define Envio_h
#include "Cliente.h"

class Envio {
private:
    Cliente remitente;
    Cliente destinatario;
    int costoEstandar = 100;
    int largo;
    int ancho;
public:
    //Constructor
    Envio() {
        largo = 0;
        ancho = 0;
    }
    
    Envio(Cliente remitente, Cliente destinatario, int largo, int ancho) {
        this -> remitente = remitente;
        this -> destinatario = destinatario;
        this -> largo = largo;
        this -> ancho = ancho;
    }
    
    //Getters
    Cliente getRemitente() {
        return remitente;
    }
    
    Cliente getDestinatario() {
        return destinatario;
    }
    
    int getCostoEstandar() {
        return costoEstandar;
    }
    
    int getLargo() {
        return largo;
    }
    
    int getAncho() {
        return ancho;
    }
    
    //Setters
    void setRemitente(Cliente remitente) {
        this -> remitente = remitente;
    }
    
    void setDestinatario(Cliente destinatario) {
        this -> destinatario = destinatario;
    }
    
    void setCostoEstandar(int costoEstandar) {
        this -> costoEstandar = costoEstandar;
    }
    
    void setLargo(int largo) {
        this -> largo = largo;
    }
    
    void setAncho(int ancho) {
        this -> ancho = ancho;
    }
    
    //Otros metodos
    virtual double calculaCosto() {
        return 0.0;
    }
    
    //Str
    virtual void str() {
        cout << "Remitente: ";
        remitente.str();
        cout << "\nDestinatario: ";
        destinatario.str();
        cout << "\nCosto: " << costoEstandar << endl;
        cout << "Largo: " << largo << endl;
        cout << "Ancho: " << ancho << endl;
    }
};


#endif /* Envio_h */
