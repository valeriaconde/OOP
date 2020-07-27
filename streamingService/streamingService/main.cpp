//
//  main.cpp
//  streamingService
//
//  Created by Valeria Conde on 27/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

#include "Movie.h"
#include "Serie.h"
#include "Movies.h"
#include "Series.h"

void showMenu() {
    cout << "Peliculas" << endl;
    cout << "1. Alta Pelicula" << endl;
    cout << "2. Mostrar peliculas con su calificacion" << endl;
    cout << "3. Mostrar las peliculas con cierta calificacion" << endl;
    cout << "4. Reporte de peliculas por genero" << endl;
    cout << "5. Incrementar Oscares" << endl;
    cout << endl;
    cout << "Series" << endl;
    cout << "6. Alta Serie" << endl;
    cout << "7. Mostrar series con su calificacion" << endl;
    cout << "8. Mostrar series con cierta calificacion" << endl;
    cout << "9. Reporte de series por genero" << endl;
    cout << "10. Reporte de serie de temporada" << endl;
    cout << endl;
    cout << "Episodios" << endl;
    cout << "11. Alta Episodio" << endl;
    cout << "12. Mostrar los episodios de una serie" << endl;
    cout << "0. Salir" << endl;
}

int main() {
    // Objetos
    Movies movies;
    Series series;
    
    ifstream pIn("Peliculas.csv", ios::in);
    ifstream sIn("Series.csv", ios::in);
    ifstream eIn("Episodios.csv", ios::in);
    
    string line;
    // read movies
    while(getline(pIn, line)) {
        cout << "Pelicula = " << line << endl;
        
        string word;
        string row[6];
        stringstream s(line);
        int iR = 0;
        while(getline(s, word, ',')) {
            row[iR++] = word;
        }
        
        movies.altaPelicula(stoi(row[5]), row[0], row[1], stoi(row[2]), row[3], stod(row[4]));
    }
    
    // read series
    while(getline(sIn, line)) {
        cout << "Serie = " << line << endl;
        
        string word;
        string row[6];
        stringstream s(line);
        int iR = 0;
        while(getline(s, word, ',')) {
            row[iR++] = word;
        }
        
        series.altaSerie(row[0], row[1], stoi(row[2]), row[3], stod(row[4]));
    }
    
    // read episodes
    while(getline(eIn, line)) {
        cout << "Episodio = " << line << endl;
        
        string word;
        string row[4];
        stringstream s(line);
        int iR = 0;
        while(getline(s, word, ',')) {
            row[iR++] = word;
        }
        
        string id = row[0];
        for(int i = 0; i < series.getSeries().size(); i++) {
            if(series.getSeries()[i]->getID() == id) {
                series.getSeries()[i]->altaEpisodio(row[1], stoi(row[2]), stod(row[3]));
            }
        }
    }
    
    pIn.close();
    sIn.close();
    eIn.close();
    
    int opcion = 0;
    
    do {
        showMenu();
        cin >> opcion;
        
        cout << "A01281637 - Valeria Conde Naranjo" << endl;
        
        switch (opcion) {
            case 1:
                movies.altaPelicula();
                break;
            case 2:
                movies.pelisConCalif();
                break;
            case 3:
                movies.peliPorCalif();
                break;
            case 4:
                movies.pelisPorGenero();
                break;
            case 5:
                movies.addOscar();
                break;
            case 6:
                series.altaSerie();
                break;
            case 7:
                series.serieConCal();
                break;
            case 8:
                series.seriesConCalif();
                break;
            case 9:
                series.seriesPorGenero();
                break;
            case 10:
                series.reporteTemporada();
                break;
            case 11:
                series.altaEpisodio();
                break;
            case 12:
                series.episodioPorCal();
                break;
            case 0:
                cout << "Adios!" << endl;
                break;
            default:
                cout << "Opcion invalida, intente de nuevo" << endl;
                break;
        }
    } while(opcion != 0);
    
    
    
    return 0;
}
