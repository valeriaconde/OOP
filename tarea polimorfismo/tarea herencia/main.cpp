//
//  main.cpp
//  tarea herencia
//
//  Created by Valeria Conde on 20/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
#include "Paquete.h"
#include "Sobre.h"

// El polimorfismo se aplica en este programa al utilizar un vector de apuntadores de tipo Envio, que apuntan a objetos de tipo Paquete y Sobre y se guardan en el mismo vector, y cada uno aplica sus propios metodos de tipo al objeto apuntado.

int main() {
    cout << "INICIANDO SIMULACION DE ENVIOS" << endl;
    cout << "Clientes: " << endl;
    Cliente remitente("Valeria Conde", "Garza Sada 1001", "Monterrey", "Nuevo Leon", "64989");
    Cliente destinatario("Elias Mera", "Redmond 8", "Monterrey", "Nuevo Leon", "64777");
    remitente.str();
    destinatario.str();
    cout << endl;
    
    vector<Envio*> vec;
    double sumaCosto = 0;
    
    vec.push_back(new Paquete(2, 3, 5, 7, 11, remitente, destinatario));
    vec.push_back(new Paquete(1, 2, 3, 4, 5, remitente, destinatario));
    vec.push_back(new Paquete(13, 17, 19, 23, 29, remitente, destinatario));
    vec.push_back(new Paquete(7, 7, 7, 7, 7, remitente, destinatario));
    vec.push_back(new Paquete(5, 8, 40, 69, 7, remitente, destinatario));

    
    vec.push_back(new Sobre(remitente, destinatario, 1, 1));
    vec.push_back(new Sobre(remitente, destinatario, 30, 27));
    vec.push_back(new Sobre(remitente, destinatario, 1, 30));
    vec.push_back(new Sobre(remitente, destinatario, 5, 14));
    vec.push_back(new Sobre(remitente, destinatario, 10, 10));

    
    for(int i = 0; i < vec.size(); i++) {
        vec[i]->str();
        sumaCosto += vec[i]->calculaCosto();
    }
    
    cout << "El costo de todos los envios es: " << sumaCosto << endl;
    return 0;
}
