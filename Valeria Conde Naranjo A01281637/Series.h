//
//  Series.h
//  streamingService
//
//  Created by Valeria Conde on 06/06/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Series_h
#define Series_h
#include <vector>
using namespace std;

class Series {
private:
    vector<Serie*> series;
    vector<Episode*> arEpisodes;
public:
    vector<Serie*> getSeries() {
        return series;
    }
    
    // ALTA SERIE //
    void altaSerie() {
        // Variables
        string nom, g, i;
        int a, d;
        double c;
        // Data of serie
        cout << "ID de la serie: ";
        cin >> i;
        cout << "Nombre de la serie: ";
        cin >> nom;
        cout << "Duracion de la serie: ";
        cin >> d;
        cout << "Genero de la serie: ";
        cin >> g;
        cout << "Calificacion de la serie: ";
        cin >> c;
        
        // Episodes of serie
        cout << "Cuantos episodios vas a dar de alta? ";
        cin >> a;
        
        int f = a;
        
        
        // Creates obj & appends to ptr array
        Serie *ser = new Serie(arEpisodes, f, i, nom, d, g, c);
        
        while(a > 0) {
            ser->altaEpisodio();
            // actualiza contador
            a--;
        }
        series.push_back(ser);
    }
    
    void altaSerie(string i, string nom, int d, string g, double c) {
        vector<Episode*> arEpisodes;
        // Creates obj & appends to ptr array
        Serie *ser = new Serie(arEpisodes, 0, i, nom, d, g, c);
        series.push_back(ser);
    }
    
    // MOSTRAR SERIES CON SU CALIFICACION //
    void serieConCal() {
        // Variables
        double sum = 0;
        
        // Printing series
        cout << "SERIES DISPONIBLES" << endl;
        for(int i = 0; i < series.size(); i++) {
            // rating variable
            double r = series[i]->avgRating();
            
            // calls show of each serie
            series[i]->show();
            sum += r;
        }
        
        // avg rating of all series
        cout << "PROMEDIO DE TODAS: " << sum / series.size() << endl;
    }
    
    // MOSTRAR SERIES CON CIERTA CALIFICACION //
    void seriesConCalif() {
        // variables
        double c;
        int cont = 0;
        
        // reads user input
        cout << "De que calificacion desea ver series disponibles?";
        cin >> c;
        
        // Printing
        cout << "Series con calificacion = " << c << endl;
        for(int i = 0; i < series.size(); i++) {
            if(series[i]->avgRating() == c) {
                cont++;
                series[i]->show();
            }
        }
             
        // No series available
        if (cont == 0) cout << "No hay series con calificacion exacta de " << c << " disponibles." << endl;
    }
    
    // MOSTRAR SERIES POR GENERO //
    void seriesPorGenero() {
           // Mensaje
           cout << "MOSTRANDO SERIES POR GENERO" << endl;
           cout << endl;
           
           // Variables
           vector<Serie*> drama;
           vector<Serie*> accion;
           vector<Serie*> misterio;
           
           // Recorrer el arreglo una sola vez
           for (int i = 0; i < series.size(); i++) {
               if(series[i]->getGenre() == "Drama") {
                   drama.push_back(series[i]);
               } else if(series[i]->getGenre() == "Accion") {
                   accion.push_back(series[i]);
               } else {
                   misterio.push_back(series[i]);
               }
           }
           
           // Printing
           cout <<  "DRAMA" << endl;
           for(int i = 0; i < drama.size(); i++) {
               drama[i]->show();
           }
           cout << endl;
           
           cout << "ACCION" << endl;
           for(int i = 0; i < accion.size(); i++) {
               accion[i]->show();
           }
           cout << endl;
           
           cout << "MISTERIO" << endl;
        for(int i = 0; i < misterio.size(); i++) {
               misterio[i]->show();
           }
           cout << endl;
       }
    
    // REPORTE DE SERIE DE TEMPORADA //
    void reporteTemporada() {
        // Variables
        int op;
        string sid;
        
        // Mssg
        cout << "De que serie quieres ver el reporte? ";
        
        // Showing all series
        for (int i = 0; i < series.size(); i ++) {
            cout << i + 1 << ". " << series[i]->getName() << endl;
        }
        
        // Reads ans
        cin >> op;
        
        // shows each episode
        cout << "SERIE: " << series[op-1]->getName() << endl;
        
        // prints episodes from chosen serie
        for(int i = 0; i < series[op-1]->getEpisodes().size(); i++) {
            series[op-1]->getEpisodes()[i]->show();
        }
    }
    
    // ALTA EPISODIO //
    void altaEpisodio() {
        // Variables
        int s;
        // Printing options
        cout << "Elige una serie: ";
        for(int i = 0; i < series.size(); i++) {
            cout << i + 1 << ". " << series[i]->getName() << endl;
        }
        cin >> s;
        series[s - 1]->altaEpisodio();
    }
    
    // EPISODIOS DE UNA SERIE QUE TENGAN CIERTA CALIFICACION //
    void episodioPorCal() {
        // variables
        double c;
        int s, cont = 0;
        
        // Printing options
        cout << "Elige una serie: ";
        for(int i = 0; i < series.size(); i++) {
            cout << i + 1 << ". " << series[i]->getName() << endl;
        }
        cin >> s;
        
        // asks for rating wished
        cout << "De que calificacion quieres ver episodios? ";
        cin >> c;
        
        // prints report
        cout << "Episodios de " << series[s-1]->getName() << " con calificacion " << c << endl;
        for(int i = 0; i < series[s-1]->getEpisodes().size(); i++) {
            if(series[s-1]->getEpisodes()[i]->getRating() == c) {
                cont++;
                series[s-1]->getEpisodes()[i]->show();
            }
        }
        
        // No episodes available
        if (cont == 0) cout << "No hay episodios de " << series[s-1]->getName() << " con calificacion exacta de " << c << " disponibles." << endl;
    }
};

#endif /* Series_h */
