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

// getVuelosPorDia
// Hace un mapeo de vuelos por cada dia, asignando un arreglo de vuelos como valor para cada llave tipo string que corresponde a una fecha
void getVuelosPorDia(vector<Vuelo> &arr, map<string, vector<Vuelo>> &vuelosPorDia) {
    for(int i = 0; i < arr.size(); i++){
        string fecha = arr[i].getItinerario().getFecha();
        vuelosPorDia[fecha].push_back(arr[i]);
    }
}

// horasMayorSaturacion
// Calcula las horas de cada dia con mayor saturacion, leyendo el mapa de vuelos por dia y luego encontrando la hora con mayor cantidad de vuelos
void horasMayorSaturacion(vector<Vuelo> &arrVuelos, map<string, vector<Vuelo>> &vuelosPorDia) {
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

// arrivalsPromedioPorHora
// Calcula las llegadas promedio por hora
void arrivalsPromedioPorHora(vector<Vuelo> &arr, int dias) {
    // arrArrivalsPorHora guarda el numero de llegadas por hora, donde la hora es el indice del vector
    vector<int> arrArrivalsPorHora(24, 0);
    // Para cada vuelo de llegada suma una unidad al vector contador en el indice de esa hora
    for(int i = 0; i < arr.size(); i++) {
        if (arr[i].getItinerario().getFormato() == 'A') {
            arrArrivalsPorHora[arr[i].getItinerario().getHora()]++;
        }
    }
    // Imprime las llegadas promedio para cada hora
    for (int i = 0; i < 24; i++) {
        cout << "Llegadas promedio a las " << i << ": " << arrArrivalsPorHora[i] * 1.0 / dias << endl;
    }
}

// salidasPromedioPorHora
// Calcula las salidas promedio por hora
void salidasPromedioPorHora(vector<Vuelo> &arr, int dias) {
    // arrSalidasPorHora guarda el numero de llegadas por hora, donde la hora es el indice del vector
    vector<int> arrSalidasPorHora(24, 0);
    // Para cada vuelo de llegada suma una unidad al vector contador en el indice de esa hora
    for(int i = 0; i < arr.size(); i++) {
        if (arr[i].getItinerario().getFormato() == 'S') {
            arrSalidasPorHora[arr[i].getItinerario().getHora()]++;
        }
    }
    // Imprime las llegadas promedio para cada hora
    for (int i = 0; i < 24; i++) {
        cout << "Salidas promedio a las " << i << ": " << arrSalidasPorHora[i] * 1.0 / dias << endl;
    }
}

// llegadasSalidasPorAerolinea
void llegadasSalidasPorAerolinea(vector<Vuelo> &arrVuelos) {
    // Crea un mapa con las llegadas de cada aerolinea
    map<string, int> mapArrivals;
    // Crea un mapa con las salidas de cada aerolinea
    map<string, int> mapSalidas;
    // Si es salida suma un vuelo al mapa de salidas, si es llegada lo suma al mapa de llegadas
    for(int i = 0; i < arrVuelos.size(); i++){
        string aerolinea = arrVuelos[i].getAerolinea();
        if (arrVuelos[i].getItinerario().getFormato() == 'A') {
            mapArrivals[aerolinea]++;
        } else {
            mapSalidas[aerolinea]++;
        }
    }
    // Imprime las llegadas por aerolinea
    cout << "Llegadas por aerolinea:" << endl;
    for (auto it : mapArrivals) {
        string key = it.first;
        int value = it.second;
        cout << key << ": " << value << " vuelos" << endl;
    }
    cout << endl;
    //Imprime las salidas por aerolinea
    cout << "Salidas por aerolinea:" << endl;
    for (auto it : mapSalidas) {
        string key = it.first;
        int value = it.second;
        cout << key << ": " << value << " vuelos" << endl;
    }
}

// pasajerosPorDia
// Calcula el total de pasajeros por cada dia
void pasajerosPorDia(vector<Vuelo> &arrVuelos) {
    // Crea un mapa cada dia como llave y el numero total de pasajeros como valor
    map<string, int> pasajerosPorDia;
    // Lee el arreglo de vuelos y mapea el total de pasajeros para cada dia
    for (int i = 0; i < arrVuelos.size(); i++) {
        string fecha = arrVuelos[i].getItinerario().getFecha();
        pasajerosPorDia[fecha] += arrVuelos[i].getNumPasajeros();
    }
    // Imprime el total de pasajeros para cada dia
    for (auto it : pasajerosPorDia) {
        string key = it.first;
        int value = it.second;
        cout << "El dia " << key << " se atendieron " << value << " pasajeros." << endl;
    }
}

// usoDeAviones
// Calcula el porcentaje promedio de uso de cada avion, considerando el numero de pasajeros de cada avion y la capacidad que tiene esa aeronave
void usoDeAviones(vector<Vuelo> &arrVuelos, vector<Avion> arrAviones) {
    // Crea un mapa de aviones como llave y un arreglo con el numero de pasajeros de cada vuelo
    map<string, vector<int>> mapPasajeros;
    // Cuenta el numero de vuelos para un avion
    for (int i = 0; i < arrVuelos.size(); i++) {
        string avion = arrVuelos[i].getAvion().getNombre();
        mapPasajeros[avion].push_back(arrVuelos[i].getNumPasajeros());
    }
    // Lee los datos del mapa y calcula el promedio dividiendo el numero total de pasajeros entre la cantidad de vuelos
    for (auto it : mapPasajeros) {
        string key = it.first;
        vector<int> pasajeros = it.second;
        int vuelosDeEsteAvion = pasajeros.size();
        int contPasajeros = 0;
        // Suma la cantidad de pasajeros en un contador
        for(int i = 0; i < pasajeros.size(); i++){
            contPasajeros += pasajeros[i];
        }
        // Calcula el promedio de pasajeros
        double promedio = contPasajeros / vuelosDeEsteAvion * 1.0;
        int capacidad;
        // Lee la capacidad de cada aeronave del archivo de capacidades
        for (int i = 0; i < arrAviones.size(); i++) {
            if (key == arrAviones[i].getNombre()) capacidad = arrAviones[i].getCapacidad();
        }
        // Imprime el porcentaje promedio de capacidad usada de cada aeronave
        cout << "El avion " << key << " tiene un porcentaje promedio de capacidad usada de " << promedio / capacidad * 100.0 << "%" << endl;
    }
}

// vuelosPorHoraMayorCantPasajeros
// Calcula el vuelo con mayor cantidad de pasajeros para cada hora
void vuelosPorHoraMayorCantPasajeros(vector<Vuelo> &arrVuelos) {
    // Crea un vector con 24 horas para hacer el calculo por hora
    vector<Vuelo> maxPorHora(24);
    // Calcula el vuelo con mayor cantidad de pasajeros
    for(int i = 0; i < arrVuelos.size(); i++) {
        int hora = arrVuelos[i].getItinerario().getHora();
        if(arrVuelos[i].getNumPasajeros() > maxPorHora[hora].getNumPasajeros()) {
            maxPorHora[hora] = arrVuelos[i];
        }
    }
    // Imprime el vuelo con mayor cantidad de pasajeros de cada hora
    for(int i = 0; i < 24; i++) {
        cout << "A las " << i << " horas el vuelo con mayor cantidad de pasajeros es\n ";
        maxPorHora[i].show();
    }
}

int main() {
    
    
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
    while (datos >> fech >> hor >> vuel >> format >> aeroline >> destin >> avio >> pasajer) {
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

    // retroalimentacion de final del programa
    cout << " FIN " << endl;
    
    // cierra archivos
    datos.close();
    capacidades.close();
    return 0;
}
