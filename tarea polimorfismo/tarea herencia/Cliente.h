//
//  Cliente.h
//  tarea herencia
//
//  Created by Valeria Conde on 20/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Cliente_h
#define Cliente_h

class Cliente {
private:
    string nombre;
    string direccion;
    string ciudad;
    string estado;
    string cp;
public:
    // Constructores
    Cliente() {
        nombre = "Indefinido";
        direccion = "Indefinido";
        ciudad = "Indefinido";
        estado = "Indefinido";
        cp = "Indefinido";
    }
    
    Cliente(string nombre, string direccion, string ciudad, string estado, string cp) {
        this -> nombre = nombre;
        this -> direccion = direccion;
        this -> ciudad = ciudad;
        this -> estado = estado;
        this -> cp = cp;
    }
    
    // Getters
    string getNombre() {
        return nombre;
    }
    
    string getDireccion() {
        return direccion;
    }
    
    string getCiudad() {
        return ciudad;
    }
    
    string getEstado() {
        return estado;
    }
    
    string getCP() {
        return cp;
    }
    
    // Setters
    void setNombre(string nombre) {
        this -> nombre = nombre;
    }
    
    void setDireccion(string direccion) {
        this -> direccion = direccion;
    }
    
    void setCiudad(string ciudad) {
        this -> ciudad = ciudad;
    }
    
    void setEstado(string estado) {
        this -> estado = estado;
    }
    
    void setCP(string cp) {
        this -> cp = cp;
    }
    
    // Str
    void str() {
        cout << "Nombre: " << nombre << endl;
        cout << "Direccion: " << direccion << endl;
        cout << "Ciudad: " << ciudad << endl;
        cout << "Estado: " << estado << endl;
        cout << "CP: " << cp << endl;
    }
    
    
};

#endif /* Cliente_h */
