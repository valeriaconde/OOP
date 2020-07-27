//
//  Movie.h
//  streamingService
//
//  Created by Valeria Conde on 27/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Movie_h
#define Movie_h
#include "Video.h"
using namespace std;

class Movie : public Video {
private:
    int oscars;
public:
    // CONSTRUCTORS
    Movie() : Video() {
        oscars = 0;
    }
    
    Movie(int oscars, string ID, string name, int length, string genre, double rating) : Video(ID, name, length, genre, rating) {
        this-> oscars = oscars;
    }
    
    // SETTERS
    void setOscars(int oscars) {
        this-> oscars = oscars;
    }
    
    // GETTERS
    int getOscars() {
        return oscars;
    }
    
    double avgRating() {
        return getRating() + 0.5 * oscars;
    }
    
    // METHODS
    
    void show() {
        cout << "ID: " << getID() << endl;
        cout << "Name: " << getName() << endl;
        cout << "Length: " << getLength() << endl;
        cout << "Genre: " << getGenre() << endl;
        cout << "Rating: " << avgRating() << endl;
        cout << "Oscars: " << oscars << endl;
    }
};

#endif /* Movie_h */
