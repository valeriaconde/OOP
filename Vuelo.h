//
//  Header.h
//  vuelosCLASES
//
//  Created by Valeria Conde on 20/02/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Header_h
#define Header_h

class Vuelo {
private:
    string pais;
    string matricula;
    int vuelo;
public:
    Vuelo();
    Vuelo(string pais, string matricula, int vuelos);
    string getPais();
    string getMatricula();
    int getVuelo();
    void setPais();
    void setMatricula(string matricula);
    void setVuelo(int Vuelos);
    void show();
};

Vuelo::Vuelo() {
    pais = "Mexico";
    matricula = "XA";
    vuelos = 0;
}

Vuelo::Vuelo(string pais, string matricula, int vuelo) {
    this->pais = pais;
    this->matricula = matricula;
    this->vuelo = vuelo;
}

string Vuelo::getPais() {
    return pais;
}

string Vuelo::getMatricula() {
    return matricula;
}

int Vuelo::getVuelo() {
    return vuelos;
}

void Vuelo::setPais(string pais) {
    this->pais = pais;
}

void Vuelo::setMatricula(string matricula) {
    this->matricula = matricula;
}

void Vuelo::setVuelo(int vuelo) {
    this->vuelo = vuelo;
}

void Vuelo::show() {
    cout << "Pais: " << pais << "Matricula: " << matricula << "Vuelos: " << vuelo << endl;
}


#endif /* Header_h */
