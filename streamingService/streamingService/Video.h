//
//  Video.h
//  streamingService
//
//  Created by Valeria Conde on 27/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Video_h
#define Video_h
using namespace std;

class Video {
private:
    string ID;
    string name;
    int length;
    string genre;
    double rating;
public:
    // CONSTRUCTORS
    Video() {
        ID = "000";
        name = "Untitled";
        length = 120;
        genre = "Undefined";
        rating = 0;
    }
    
    Video(string ID, string name, int length, string genre, double rating) {
        this-> ID = ID;
        this-> name = name;
        this-> length = length;
        this-> genre = genre;
        this-> rating = rating;
    }
    
    // SETTERS
    void setID(string ID) {
        this-> ID = ID;
    }
    
    void setName(string name) {
        this-> name = name;
    }
    
    void setLength(int length) {
        this-> length = length;
    }
    
    void setGenre(string genre) {
        this-> genre = genre;
    }
    
    void setRating(double rating) {
        this-> rating = rating;
    }
    
    // GETTERS
    string getID() {
        return ID;
    }
    
    string getName() {
        return name;
    }
    
    int getLength() {
        return length;
    }
    
    string getGenre() {
        return genre;
    }
    
    double getRating() {
        return rating;
    }
    
    // OTHER METHODS
    void show() {
        cout << "ID: " <<  ID << endl;
        cout << "Nombre: " << name << endl;
        cout << "Duracion: " << length << endl;
        cout << "Genero: " << genre << endl;
        cout << "Calificacion: " << rating << endl;
    }
    
    virtual double avgRating() {
        return 0;
    }
};

#endif /* Video_h */
