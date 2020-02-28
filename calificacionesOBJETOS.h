//
//  calificacionesOBJETOS.h
//  calificacionesOBJETOS
//
//  Created by Valeria Conde on 24/02/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.
//

#ifndef calificacionesOBJETOS_h
#define calificacionesOBJETOS_h

using namespace std;

class Calificacion {
private:
    string alumno;
    int calif1;
    int calif2;
    int calif3;
    double califFinal;
public:
    Calificacion() {
        alumno = "Valeria";
        calif1 =  100;
        calif2 = 100;
        calif3 = 100;
        califFinal = 100;
    }
    
    Calificacion(string alumno, int calif1, int calif2, int calif3) {
        this -> alumno = alumno;
        this -> calif1 = calif1;
        this -> calif2 = calif2;
        this -> calif3 = calif3;
        califFinal = getPromedio();
    }
    
    // getters
    string getAlumno() {
        return alumno;
    }
    
    int getCalif1() {
        return calif1;
    }
    
    int getCalif2() {
        return calif2;
    }
    
    int getCalif3() {
        return calif3;
    }
    
    double getCalifFinal() {
        return califFinal;
    }

    // setters
    
    void setAlumno(string alumno) {
        this -> alumno = alumno;
    }
    
    void setCalif1(int calif1) {
        this -> calif1 = calif1;
    }
    
    void setCalif2(int calif2) {
        this -> calif2 = calif2;
    }
    
    void setCalif3(int calif3) {
        this -> calif3 = calif3;
    }
    
    void setCalifFinal(double califFinal) {
        this -> califFinal = califFinal;
    }
    
    // otros metodos
    
    double getPromedio() {
        double promedio = (calif1 + calif2 + calif3) / 3.0;
        return promedio;
    }
    
    void show() {
        cout << "Alumno: " << alumno << "Calificacion 1: " << calif1 << "Calificacion 2: " << calif2 << "Calificacion 3: " << calif3 << endl;
    }
    
};



#endif /* calificacionesOBJETOS_h */
