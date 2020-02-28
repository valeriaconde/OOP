//
//  Point.h
//  act4
//
//  Created by Valeria Conde on 20/02/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <cmath>

#ifndef Point_h
#define Point_h

class Point {
private:
    double x;
    double y;
public:
    Point(double x, double y) {
        this->x = x;
        this->y = y;
    }
    
    Point() {
        x = 0.0;
        y = 0.0;
    }
    
    double getX() {
        return x;
    }
    
    double getY() {
        return y;
    }
    
    void setX(double num) {
        x = num;
    }
    
    void setY(double num) {
        y = num;
    }
    
    double distance (double x1, double y1) {
        return sqrt(pow(x1-x,2)+pow(y1-y,2));
    }
        
};



#endif /* Point_h */
