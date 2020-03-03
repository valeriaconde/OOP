//
//  act8Taxi.h
//  act8
//
//  Created by Valeria Conde on 27/02/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef act8Taxi_h
#define act8Taxi_h
#include "act8Persona.h"

using namespace std;

class Taxi {
private:
    Persona resp;
    int ident;
public:
    Taxi() {
        resp = Persona();
        ident = 0;
    }
    
    Taxi(Persona resp, int ident) {
        this -> resp = resp;
        this -> ident = ident;
    }
    
    Persona getPersona() {
        return resp;
    }
    
    int getIdent() {
        return ident;
    }
    
    void setResp(Persona resp) {
        this -> resp = resp;
    }
    
    void setIdent(int ident) {
        this -> ident = ident;
    }
    
    void show() {
        cout << "Responsable: " << endl;
        resp.show();
        cout << "ID de taxi: " << ident << endl;
        cout << endl;
    }
    
};


#endif /* act8Taxi_h */
