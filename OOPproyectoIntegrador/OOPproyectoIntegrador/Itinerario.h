//
//  Itinerario.h
//  OOPproyectoIntegrador
//
//  Created by Valeria Conde on 05/03/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Itinerario_h
#define Itinerario_h

using namespace std;

class Itinerario {
private:
    string hora;
    string fecha;
    string destino;
    char formato;
public:
    // constructores
    Itinerario() {
        hora = "";
        fecha = "";
        destino = "";
        formato = 'A';
    }
    
    Itinerario(string hora, string fecha, string destino, char formato) {
        this -> hora = hora;
        this -> fecha = fecha;
        this -> destino = destino;
        this -> formato = formato;
    }
    
    // getters
    string getHora() {
        return hora;
    }
    
    string getFecha() {
        return fecha;
    }
    
    string getDestino() {
        return destino;
    }
    
    char getFormato() {
        return formato;
    }
    
    // setters
    void setHora(string hora) {
        this -> hora = hora;
    }
    
    void setFecha(string fecha) {
        this -> fecha = fecha;
    }
    
    void setDestino(string destino) {
        this -> destino = destino;
    }
    
    void setFormato(char formato) {
        this -> formato = formato;
    }
};


#endif /* Itinerario_h */
