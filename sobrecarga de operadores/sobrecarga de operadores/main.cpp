//
//  main.cpp
//  Revision
//
//  Created by Valeria Conde on 5/28/20.
//  Copyright © 2020 Invitado. All rights reserved.
//

#include <stdio.h>
// Example program
#include <iostream>
#include <iomanip>
#include "Fracciones.h"
using namespace std;

int menu(){
    int iOpcion;
    cout << "\n1. Ingresa la Fraccion1:";
    cout << "\n2. Ingresa la fraccion2:";
    cout << "\n3. f1 + f2 ";
    cout << "\n4. f1 - f2 ";
    cout << "\n5. f1 * f2 ";
    cout << "\n6. f1 / f2 ";
    cout << "\n7. f1 < f2 ";
    cout << "\n8. f1 > f2 ";
    cout << "\n9. f1 == f2 ";
    cout << "\n0. Salir";
    cout << "\nTeclea la opcion:";
    cin >> iOpcion;
    return iOpcion;
}
int main() {
    Fracciones f1(3,5), f2(1,5);
    Fracciones f3(3,5), f4(2,6);
    Fracciones resultado;
    bool res;
    int iOpcion, iNum, iDen;
    resultado = f1 + f2;
    cout << f1.show() << " + " << f2.show() << "= " << resultado.show() << endl;
    resultado = f3 + f4;
    cout << f3.show() << " + " << f4.show() << "= " << resultado.show() << endl;
    
    // Inicializar la vcc antes del ciclo
    iOpcion = menu();
    while (iOpcion != 0) {
        switch (iOpcion) {
            case 1:
                f1.input();
                f1.output();
                break;
            case 2:
                f2.input();
                f2.output();
                break;
            case 3:
                resultado = f1 + f2;
                cout << f1.show() << " + " << f2.show() << "= " << resultado.show() <<  "= " << resultado.strFlotante()<< endl;
                break;
            case 4:
                resultado = f1 - f2;
                cout << f1.show() << " - " << f2.show() << "= " << resultado.show() <<  "= " << resultado.strFlotante()<< endl;
                break;
            case 5:
                resultado = f1 * f2;
                cout << f1.show() << " * " << f2.show() << "= " << resultado.show() <<  "= " << resultado.strFlotante()<< endl;
                break;
            case 6:
                resultado = f1 / f2;
                cout << f1.show() << " / " << f2.show() << "= " << resultado.show() <<  "= " << resultado.strFlotante()<< endl;
                break;
            case 7:
               res = f1 < f2;
               cout << f1.show() << " < " << f2.show() << "= " << res << endl;
               break;
           case 8:
               res = f1 > f2;
               cout << f1.show() << " > " << f2.show() << "= " << res << endl;
               break;
           case 9:
               res = f1 == f2;
               cout << f1.show() << " == " << f2.show() << "= " << res << endl;
                break;
            default:
                break;
        }
        // Actualizar la vcc dentro del ciclo
        iOpcion = menu();
    }// fin while
    
    return 0;
}
