//
//  act8Persona.h
//  act8
//
//  Created by Valeria Conde on 27/02/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef act8Persona_h
#define act8Persona_h

using namespace std;

class Persona {
private:
    string nombre;
    string numCel;
public:
    Persona() {
        nombre = "";
        numCel = "";
    }
    
    Persona(string nombre, string numCel) {
        this -> nombre = nombre;
        this -> numCel = numCel;
    }
    
    string getNombre() {
        return nombre;
    }
    
    string getNumCel() {
        return numCel;
    }
    
    void setNombre(string nombre) {
        this -> nombre = nombre;
    }
    
    void setNumCel(string numCel) {
        this -> numCel = numCel;
    }
    
    void show() {
        cout << "Nombre: " << nombre << " Telefono :" << numCel << endl;
    }
    
};

#endif /* act8Persona_h */
