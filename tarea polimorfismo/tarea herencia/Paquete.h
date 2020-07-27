//
//  Paquete.h
//  tarea herencia
//
//  Created by Valeria Conde on 20/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Paquete_h
#define Paquete_h
#include "Envio.h"
#include "Cliente.h"

class Paquete: public Envio {
private:
    int profundidad;
    double peso;
    double costoXKg;
public:
    // Constructor
    Paquete(int profundidad, double peso, double costoXKg, int largo, int ancho, Cliente remitente, Cliente destinatario) : Envio(remitente, destinatario, largo, ancho) {
        this -> profundidad = profundidad;
        this -> peso = peso;
        this -> costoXKg = costoXKg;
    }
    
    // Getters
    
    int getProfundidad() {
        return profundidad;
    }
    
    double getPeso() {
        return peso;
    }
    
    double getCostoXKg() {
        return costoXKg;
    }
    
    // Setters
    void setProfundidad(int profundidad) {
        this -> profundidad = profundidad;
    }
    
    void setPeso(double peso) {
        this -> peso = peso;
    }
    
    void setCostoXkg(double costoXKg) {
        this -> costoXKg = costoXKg;
    }
    
    // calculaCosto
    double calculaCosto() {
        double costoTotal = costoXKg * peso;
        return costoTotal + getCostoEstandar();
    }
    
    // str
    void str() {
        cout << "Informacion paquete:" << endl;
        cout << "Profundidad: " << profundidad << endl;
        cout << "Peso: " << peso << endl;
        cout << "Costo por kilogramo: " << costoXKg << endl;
        
        cout << "Remitente: ";
        getRemitente().str();
        cout << "\nDestinatario: ";
        getDestinatario().str();
        cout << "\nCosto Estandar: " << getCostoEstandar() << endl;
        cout << "Largo: " << getLargo() << endl;
        cout << "Ancho: " << getAncho() << endl;
        cout << "-------------------------\n";
    }
    
};

#endif /* Paquete_h */
