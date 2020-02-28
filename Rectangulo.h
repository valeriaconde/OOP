//  Rectangulo.h
//  clases
//
//  Created by Valeria Conde on 17/02/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Rectangulo_h
#define Rectangulo_h

class Rectangulo {
private:
    int largo;
    int ancho;
public:
    // Constructores
    Rectangulo();
    Rectangulo(int largo, int ancho);
    
    // setter y getter para CADA atributo
    // setters
    void setLargo(int largo);
    void setAncho(int ancho);
    // getters
    int getLargo();
    int getAncho();
    
    //funciones
    int Area();
    void Despliega();
    
};

Rectangulo::Rectangulo() {
    largo = 2;
    ancho = 1;
}

// hacer constructores: clase dos puntos

Rectangulo::Rectangulo(int largo, int ancho) {
    // el this es que es el "largo" del ATRIBUTO y el otro es el del parametro
    this->largo = largo;
    this->ancho = ancho;
}

// los setters y getters
void Rectangulo::setLargo(int largo) {
    this->largo = largo;
}

void Rectangulo::setAncho(int ancho) {
    this->ancho = ancho;
}

int Rectangulo::getLargo() {
    return largo;
}

int Rectangulo::getAncho() {
    return ancho;
}

int Rectangulo::Area() {
    return largo * ancho;
}

void Rectangulo::Despliega() {
    cout << "Largo: " << largo << " Ancho: " << ancho << endl;
}

#endif /* Rectangulo_h */
