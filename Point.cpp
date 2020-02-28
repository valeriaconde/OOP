//  main.cpp
//  act4
//
//  Created by Valeria Conde on 20/02/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#include <iostream>
#include "Point.h"

using namespace std;

int main() {
    
    int x, y;
    
    cin >> x >> y;
    
    Point punto(x,y);

    cout << punto.distance(x, y) << endl;
    
    return 0;
}
