//
//  Movies.h
//  streamingService
//
//  Created by Valeria Conde on 06/06/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Movies_h
#define Movies_h
#include <vector>
using namespace std;

class Movies {
private:
    vector<Movie*> movies;
public:
    
    // ALTA PELICULA //
    void altaPelicula() {
        // Variables
        string i, n, g;
        int d, o;
        double c;
        
        // Lee datos
        cout << "Ingrese el ID de la pelicula: ";
        cin >> i;
        cout << "Ingrese nombre de la pelicula: ";
        cin >> n;
        cout << "Ingrese la duracion de la pelicula: ";
        cin >> d;
        cout << "Ingrese el genero de la pelicula: ";
        cin >> g;
        cout << "Ingrese la calificacion de la pelicula (1-5): ";
        cin >> c;
        cout << "Ingrese oscars de la pelicula: ";
        cin >> o;
        Movie *peli = new Movie(o, i, n, d, g, c);
        
        // Pushback
        movies.push_back(peli);
    }
    
    void altaPelicula(int o, string i, string n, int d, string g, double c) {
        Movie *peli = new Movie(o, i, n, d, g, c);
        // Pushback
        movies.push_back(peli);
    }

    // MOSTRAR PELICULAS CON SU CALIFICACION //
    void pelisConCalif() {
        // Variables
        double sum = 0;
        
        // Printing
        cout << "PELICULAS DISPONIBLES" << endl;
        for(int i = 0; i < movies.size(); i++) {
            double r = movies[i]->avgRating();
            movies[i]->show();
            cout << r << endl;
            sum += r;
        }
        
        // Avg rating
        cout << "PROMEDIO DE TODAS: " << sum / movies.size() << endl;
    }
    
    // MOSTRAR PELICULAS CON CIERTA CALIFICACION //
    void peliPorCalif() {
        // Variables
        double c;
        int cont = 0;
        
        // Lee datos
        cout << "De que calificacion desea ver peliculas disponibles?";
        cin >> c;
        
        // Printing
        cout << "Peliculas con calificacion = " << c << endl;
        for(int i = 0; i < movies.size(); i++) {
            if(movies[i]->avgRating() == c) {
                cont++;
                movies[i]->show();
            }
        }
        
        // No movies available
        if (cont == 0) cout << "No hay peliculas con calificacion exacta de " << c << " disponibles" << endl;
    }
    
    // REPORTE DE PELICULAS POR GENERO //
    void pelisPorGenero() {
        // Mensaje
        cout << "MOSTRANDO PELICULAS POR GENERO" << endl;
        cout << endl;
        
        // Variables
        vector<Movie*> drama;
        vector<Movie*> accion;
        vector<Movie*> misterio;
        
        // Recorrer el arreglo una sola vez
        for (int i = 0; i < movies.size(); i++) {
            if(movies[i]->getGenre() == "Drama") {
                drama.push_back(movies[i]);
            } else if(movies[i]->getGenre() == "Accion") {
                accion.push_back(movies[i]);
            } else {
                misterio.push_back(movies[i]);
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
    
    // INCREMENTAR OSCARS //
    void addOscar() {
        // variables
        int p, m;
        
        // question
        cout << "A que pelicula desea agregar premios oscar?" << endl;
        
        // menu of movies
        for (int i = 0; i < movies.size(); i++) {
            cout << i + 1 << ". " << movies[i]->getName() << endl;
        }
        cout << "Pelicula numero: " << endl;
        cin >> m;
        
        // Asking oscar number
        cout << "Cuantos premios oscar desea agregar?";
        cin >> p;
        
        // Adding oscar
        movies[m - 1]->setOscars(movies[m-1]->getOscars() + p);
    }
    
};

#endif /* Movies_h */
