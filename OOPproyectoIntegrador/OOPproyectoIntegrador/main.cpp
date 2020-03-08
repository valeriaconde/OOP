//  main.cpp
//  OOPproyectoIntegrador
//
//  Created by Valeria Conde
//  A01281637
//  05/03/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

/*
 
 Tu programa deberá de resolver las siguientes preguntas que deberán de formar parte de un menú de opciones

 1. Hora de cada uno de los días con mayor saturación.
 2. Cantidad de llegadas por hora promedio.
 3. Cantidad de salidas por hora promedio.
 4. Cantidad de llegadas y salidas por aerolínea.
 5. Cantidad de pasajeros atendidos por día.
 6. Porcentaje promedio de capacidad utilizada en los aviones, es decir la cantidad de pasajeros entre la capacidad de pasajeros de todos los vuelos cada día.
 7. Pregunta que creas que ya faltado para complementar el análisis de la situación problema

 El proyecto debe de contener por lo menos 3 clases y al menos una clase con composición.
 
 
 datos vuelos:
 Formato: (Fecha(YYYY/MM/DD) Hora(HH:MM) Vuelo Llegada(A)/Salida(S) Aerolínea Destino Avión Pasajeros)
 
 aviones
 Formato: (Avion PasajerosCapacidad)
 
 */

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


void arrivalsPromedioPorHora(vector<int> arrArrivalsPorHora) {
    // code
}


int main() {
    // BORRAR PARA ENTREGAR //
    string dummy;
    
    ifstream datos, capacidades;
    string fech, hor, vuel, aeroline, destin, avio, tipoAvio;
    char format, resp;
    int pasajer, capacida;
    vector<Avion> arrAviones;
    vector<Vuelo> arrVuelos;
    vector<int> arrSalidasPorHora(24,0);
    vector<int> arrArrivalsPorHora(24,0);
    int arrivalsTotales = 0, salidasTotales = 0;
    // arreglo [24] con el numero total de salidas, indexado en la hora
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
        
    // obtiene mapa de vuelos por dia
    getVuelosPorDia(arrVuelos, vuelosPorDia);

    // menu
    do {
        cout << endl;
        cout << "Que desea ver" << endl;
        cout << "1. Hora de cada dia con mayor saturacion" << endl;
        cout << "2. Cantidad de llegadas promedio por hora" << endl;
        cout << "3. Cantidad de salidas promedio por hora" << endl;
        cout << "4. Cantidad de llegadas y salidas por aerolinea" << endl;
        cout << "5. Cantidad de pasajeros atendidos por dia" << endl;
        cout << "6. Porcentaje promedio de capacidad usada en los aviones" << endl;
        cout << "7. " << endl;
        cout << "0. SALIR" << endl;
        cout << endl;

        cin >> resp;
        
        switch (resp) {
            case '1':
                horasMayorSaturacion(arrVuelos, vuelosPorDia);
                break;
                
            case '2':
                break;
                
            case '3':
                break;
                
            case '4':
                break;
                
            case '5':
                break;
                
            case '6':
                break;
                
            case '7':
                break;
                
            case '0':
                break;
                
            default:
                cout << "Opcion invalida" << endl;
                break;
        }
        
    } while (resp != '0');

    // cierra archivos
    datos.close();
    capacidades.close();
    return 0;
}
