//
//  Episode.h
//  streamingService
//
//  Created by Valeria Conde on 06/06/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef Episode_h
#define Episode_h

class Episode {
private:
    string title;
    int season;
    int rating;
public:
    // CONSTRUCTORS
    Episode() {
        title = "";
        season = 1;
        rating = 0;
    }
    
    Episode(string title, int season, double rating) {
        this-> title = title;
        this-> season = season;
        this-> rating = rating;
    }
    
    // GETTERS
    string getTitle() {
        return title;
    }
    
    int getSeason() {
        return season;
    }
    
    double getRating() {
        return rating;
    }
    
    // SETTERS
    void setTitle(string title) {
        this-> title = title;
    }
    
    void setSeason(int season) {
        this-> season = season;
    }
    
    void setRating(double rating) {
        this-> rating = rating;
    }
    
    // OTHER METHODS
    void show() {
        cout << title << ", " << season << ", " << rating;
    }
    
    void add() {
        
    }
};


#endif /* Episode_h */
