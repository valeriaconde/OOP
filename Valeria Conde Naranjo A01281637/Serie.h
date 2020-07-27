//
//  Serie.h
//  streamingService
//
//  Created by Valeria Conde on 06/06/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Serie_h
#define Serie_h
#include <vector>
using namespace std;

#include "Video.h"
#include "Episode.h"

class Serie : public Video {
private:
    vector<Episode*> episodes;
    int amount;
public:
    // CONSTRUCTORS
    Serie() {
        amount = 0;
    }
    
    Serie(vector<Episode*> episodes, int amount, string ID, string name, int length, string genre, double rating) : Video(ID, name, length, genre, rating) {
        this-> episodes = episodes;
        this-> amount = amount;
    }
    
    //GETTERS
    vector<Episode*> getEpisodes() {
        return episodes;
    }
    
    int getAmount() {
        return amount;
    }
    
    // SETTERS
    void setEpisodes(vector<Episode*> episodes) {
        this-> episodes = episodes;
    }
    
    void setAmount(int amount) {
        this-> amount = amount;
    }
    
    // OTHER METHODS
    void show() {
        cout << "ID: " << getID() << endl;
        cout << "Nombre: " << getName() << endl;
        cout << "Duracion: " << getLength() << endl;
        cout << "Genero: " << getGenre() << endl;
        cout << "Calificacion: " << getRating() << endl;
        cout << "Cantidad: " << episodes.size() << endl;
        cout << "Episodios: " << endl;
        for (int i = 0; i < episodes.size(); i++) {
            cout << i + 1 << ". ";
            episodes[i]->show();
            cout << endl;
        }
    }
    
    double avgRating() {
        return getRating();
    }
    
    void addNew(Episode* episode) {
        episodes.push_back(episode);
    }
    
    void altaEpisodio() {
        string t;
        int tm;
        double cal;

       // Data from episode
       cout << "Ingresa el titulo del capitulo: ";
       cin >> t;
       cout << "Temporada del capitulo: ";
       cin >> tm;
       cout << "Calificacion del capitulo: ";
       cin >> cal;

       // Adding episode
       Episode* ep0 = new Episode(t, tm, cal);
       episodes.push_back(ep0);
    }
    
    void altaEpisodio(string t, int tm, double cal) {
        // Adding episode
        Episode* ep0 = new Episode(t, tm, cal);
        episodes.push_back(ep0);
    }
    
    // serie + episode
    // append episode to this serie
    void operator + (Episode * ep) {
        episodes.push_back(ep);
    }
};

#endif /* Serie_h */
