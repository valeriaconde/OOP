//  main.cpp
//  actCalificaciones
//
//  Created by Valeria Conde
//  A01281637
//  24/02/20

#include <iostream>
#include <string>
#include "calificacionesOBJETOS.h"
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    
    string alumno;
    int calif1, calif2, calif3;
    vector <Calificacion> arrCalifs;
    double sumaPromedios = 0;
    double promedioGrupo;
    
    ifstream archivo;
    archivo.open("Calificaciones.txt");
    
    while (archivo >> alumno >> calif1 >> calif2 >> calif3) {
        Calificacion unaCalificacion(alumno, calif1, calif2, calif3);
        arrCalifs.push_back(unaCalificacion);
    }
    
    // Despliega grupo
    cout << "GRUPO:" << endl;
    for (int i = 0; i < arrCalifs.size(); i++) {
        sumaPromedios += arrCalifs[i].getCalifFinal();
        arrCalifs[i].show();
    }
    
    // Despliega promedio final del grupo
    promedioGrupo = sumaPromedios / arrCalifs.size();
    cout << "Promedio del grupo: " << promedioGrupo << endl;
    
    archivo.close();
    
    return 0;
}
