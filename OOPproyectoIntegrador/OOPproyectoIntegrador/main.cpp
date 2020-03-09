//  main.cpp
//  OOPproyectoIntegrador
//
//  Created by Valeria Conde
//  A01281637
//  05/03/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "Vuelo.h"
#include "Avion.h"
#include "Itinerario.h"
using namespace std;

// MAP
// 23/02/2020 -> [Vuelo1, Vuelo2, Vuelo3]
// 24/02/2020 -> [Vuelo5, Vuelo7, Vuelo 6]
void getVuelosPorDia(vector<Vuelo> &arr, map<string, vector<Vuelo>> &vuelosPorDia) {
    for(int i = 0; i < arr.size(); i++){
        string fecha = arr[i].getItinerario().getFecha();
        vuelosPorDia[fecha].push_back(arr[i]);
    }
}

// horasMayorSaturacion
// recibe un arreglo de Vuelos e imprime la hora de cada dia con mayor saturacion
// contar vuelos por hora,
void horasMayorSaturacion(vector<Vuelo> &arrVuelos, map<string, vector<Vuelo>> &vuelosPorDia) {
    // por cada dia mapear 24 horas
    for (auto it : vuelosPorDia) {
        string key = it.first;
        vector<Vuelo> values = it.second;
        vector<int> arrVuelosPorHora(24, 0);
        int maxi = 0;
        int hora = 0;
        for (int i = 0; i < values.size(); i++) {
            arrVuelosPorHora[values[i].getItinerario().getHora()]++;
        }
        for (int i = 0; i < 24; i++) {
            if (arrVuelosPorHora[i] > maxi) {
                maxi = arrVuelosPorHora[i];
                hora = i;
            }
        }
        cout << "La hora mas saturada en el dia " << key << " fueron las " << hora << " horas." << endl;
    }
}

void arrivalsPromedioPorHora(vector<Vuelo> &arr, int dias) {
    vector<int> arrArrivalsPorHora(24, 0);
    for(int i = 0; i < arr.size(); i++) {
        if (arr[i].getItinerario().getFormato() == 'A') {
            arrArrivalsPorHora[arr[i].getItinerario().getHora()]++;
        }
    }
    for (int i = 0; i < 24; i++) {
        cout << "Llegadas promedio a las " << i << ": " << arrArrivalsPorHora[i] * 1.0 / dias << endl;
    }
}


void salidasPromedioPorHora(vector<Vuelo> &arr, int dias) {
    vector<int> arrSalidasPorHora(24, 0);
    for(int i = 0; i < arr.size(); i++) {
        if (arr[i].getItinerario().getFormato() == 'S') {
            arrSalidasPorHora[arr[i].getItinerario().getHora()]++;
        }
    }
    for (int i = 0; i < 24; i++) {
        cout << "Salidas promedio a las " << i << ": " << arrSalidasPorHora[i] * 1.0 / dias << endl;
    }
}


void llegadasSalidasPorAerolinea(vector<Vuelo> &arrVuelos) {
    map<string, int> mapAerolineas;
    for(int i = 0; i < arrVuelos.size(); i++){
            string aerolinea = arrVuelos[i].getAerolinea();
            mapAerolineas[aerolinea]++;
        }
    for (auto it : mapAerolineas) {
        string key = it.first;
        int value = it.second;
        cout << key << ": " << value << " vuelos" << endl;
    }
}

void pasajerosPorDia(vector<Vuelo> &arrVuelos) {
    map<string, int> pasajerosPorDia;
    for (int i = 0; i < arrVuelos.size(); i++) {
        string fecha = arrVuelos[i].getItinerario().getFecha();
        pasajerosPorDia[fecha] += arrVuelos[i].getNumPasajeros();
    }

    for (auto it : pasajerosPorDia) {
        string key = it.first;
        int value = it.second;
        cout << "El dia " << key << " se atendieron " << value << " pasajeros." << endl;
    }
}

void usoDeAviones(vector<Vuelo> &arrVuelos, vector<Avion> arrAviones) {
    map<string, vector<int> > mapPasajeros;
    // cuenta el numero de vuelos para un avion
    for (int i = 0; i < arrVuelos.size(); i++) {
        string avion = arrVuelos[i].getAvion().getNombre();
        mapPasajeros[avion].push_back(arrVuelos[i].getNumPasajeros());
    }
    for (auto it : mapPasajeros) {
        string key = it.first;
        vector<int> pasajeros = it.second;
        int vuelosDeEsteAvion = pasajeros.size();
        int contPasajeros = 0;
        for(int i = 0; i < pasajeros.size(); i++){
            contPasajeros += pasajeros[i];
        }
        double promedio = contPasajeros / vuelosDeEsteAvion * 1.0;
        int capacidad;
        for (int i = 0; i < arrAviones.size(); i++) {
            if (key == arrAviones[i].getNombre()) capacidad = arrAviones[i].getCapacidad();
        }
        cout << "El avion " << key << " tiene un porcentaje promedio de capacidad usada de " << promedio / capacidad * 100.0 << "%" << endl;
    }
}

void vuelosPorHoraMayorCantPasajeros(vector<Vuelo> &arrVuelos) {
    //   Vuelos por hora con mayor cnantidad de pasajeros
    vector<Vuelo> maxPorHora(24);
    for(int i = 0; i < arrVuelos.size(); i++) {
        int hora = arrVuelos[i].getItinerario().getHora();
        if(arrVuelos[i].getNumPasajeros() > maxPorHora[hora].getNumPasajeros()) {
            maxPorHora[hora] = arrVuelos[i];
        }
    }
    for(int i = 0; i < 24; i++) {
        cout << "A las " << i << " horas el vuelo con mayor cantidad de pasajeros es\n ";
        maxPorHora[i].show();
    }
}

int main() {
    // BORRAR PARA ENTREGAR //
    string dummy;
    
    ifstream datos, capacidades;
    string fech, hor, vuel, aeroline, destin, avio, tipoAvio;
    char format, resp;
    int pasajer, capacida;
    int dias;
    vector<Avion> arrAviones;
    vector<Vuelo> arrVuelos;
    vector<int> arrSalidasPorHora(24,0);
    vector<int> arrArrivalsPorHora(24,0);
    vector<int> arrVuelosPorHora(24,0);
    map<string, vector<Vuelo>> vuelosPorDia;
    
    
    // abre archivos
    datos.open("datos_vuelos.txt");
    capacidades.open("aviones.txt");
    
    // lee archivo capacidades
    while (capacidades >> tipoAvio >> capacida) {
        // Crea objeto avion
        Avion avion(tipoAvio, capacida);
        
        // Agrega el objeto al arreglo
        arrAviones.push_back(avion);
    }
    
    // lee archivo datos
    while (datos >> fech >> hor >> vuel >> format >> aeroline >> destin >> avio >> pasajer >> dummy) {
        // Crea objeto itinerario
        Itinerario itinerario(hor, fech, destin, format);
        
        // Crea objeto VUELO con el itinerario que acaba de crear y le da un avion con un solo parametro (nombre)
        Vuelo unVuelo(itinerario, Avion(avio), aeroline, pasajer);
        
        // Agrega unVuelo al arreglo de vuelos
        arrVuelos.push_back(unVuelo);
    }
        
    // obtiene mapa de vuelos por dia y guarda cantidad de dias
    getVuelosPorDia(arrVuelos, vuelosPorDia);
    dias = vuelosPorDia.size();
    
    // menu
    do {
        cout << endl;
        cout << "Que desea ver?" << endl;
        cout << "1. Hora de cada dia con mayor saturacion de vuelos" << endl;
        cout << "2. Llegadas promedio por hora" << endl;
        cout << "3. Salidas promedio por hora" << endl;
        cout << "4. Llegadas y salidas por aerolinea" << endl;
        cout << "5. Pasajeros atendidos por dia" << endl;
        cout << "6. Porcentaje promedio de capacidad usada en los aviones" << endl;
        cout << "7. Vuelos por hora con mayor cantidad de pasajeros" << endl;
        cout << "0. SALIR" << endl;
        cout << endl;

        cin >> resp;
        
        switch (resp) {
            case '1':
                horasMayorSaturacion(arrVuelos, vuelosPorDia);
                break;
                
            case '2':
                arrivalsPromedioPorHora(arrVuelos, dias);
                break;
                
            case '3':
                salidasPromedioPorHora(arrVuelos, dias);
                break;
                
            case '4':
                llegadasSalidasPorAerolinea(arrVuelos);
                break;
                
            case '5':
                pasajerosPorDia(arrVuelos);
                break;
                
            case '6':
                usoDeAviones(arrVuelos, arrAviones);
                break;
            case '7':
                vuelosPorHoraMayorCantPasajeros(arrVuelos);
                break;
            case '0':
                break;
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        
    } while (resp != '0');

    cout << " bai estupida " << endl;
    
    // cierra archivos
    datos.close();
    capacidades.close();
    return 0;
}
