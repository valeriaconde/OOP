//  main.cpp
//  pointers
//
//  Created by Valeria Conde on 18/05/20.
//  Copyright © 2020 Valeria Conde. All rights reserved.

#include <iostream>
using namespace std;

int main() {
    int a = 5;
    int *ptrA = &a, b, *ptrB;
    b = 10;
    ptrB = &b;
    
    // Pointer: almacena la direccion de memoria de otra variable
    cout << "Valor de a: " << a << endl;
    cout << "Direccion de memoria: " << ptrA << endl;
    cout << "Valor de ptrA: " << *ptrA << endl;
    
    return 0;
}
