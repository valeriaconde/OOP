//  main.cpp
//  Tarea estatutos de control
//
//  Created by Valeria Conde
//  A01281637
//  10/02/20.

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// conversionCelsiusFarenheit
// pide los grados en celsius y convierte a farenheit la cantidad de veces deseada, con los incrementos deseados
void conversionCelsiusFarenheit() {
    int conversiones, incremento;
    double ce, fa = 0;
    
    // Pide y valida que el valor incial sea positivo
    do {
        cout << "Ingresa cantidad inicial positiva de grados en celsius: ";
        cin >> ce;
    } while (ce <= 0);

    // Pide y valida que el numero de conversiones sea menor a 10000
    do {
        cout << "Ingresa el numero de conversiones que se haran (menor a 10,000): ";
        cin >> conversiones;
    } while (conversiones >= 10000);

    // Pide y valida que el incremento sea entre 2 y 10
    do {
        cout << "Ingrese el incremento entre los valores Celsius (2 - 10): ";
        cin >> incremento;
    } while (incremento < 2 || incremento > 10);
    
    
    // ENCABEZADO DE SALIDA
    cout << "Conversion de grados Celsuis a Farenheit" << endl;
    cout << "FARENHEIT\t CELSIUS" << endl;
    
    for (int i = 0; i < conversiones; i++) {
        fa = (9.0 / 5.0) * ce + 32;
        cout << fa << "\t\t\t" << ce << endl;
        ce += incremento;
    }
}

// serieAritmetica
// imprime los terminos y el valor de la suma de la serie aritmetica
// regresa: la suma de los terminos de la serie
int serieAritmetica() {
    int suma = 0, a = 1, d = 3, n = 25;
    
    for (int i = 1; i <= n; i++) {
        cout << "Termino " << i << ":" << a << endl;
        suma += a;
        a += d;
    }

    return suma;
}

// mediasGeometricaArmonica
// calcula la media geometrica y armonica de los numeros introducidos, hasta que se introduzca un 0
void mediasGeometricaArmonica() {
    int num = 1, multGeometrica = 1;
    vector<int> arr;
    double mediaGeometrica = 0, mediaArmonica = 0, sumaArmonica = 0;
    
    while (num != 0) {
        cout << "Ingrese un numero: ";
        cin >> num;
        
        if (num != 0) {
            arr.push_back(num);
        }
    }
    
    for (int i = 0; i < arr.size(); i++) {
        multGeometrica *= arr[i];
        sumaArmonica += (1.0/arr[i]);
    }
    
    mediaGeometrica = pow(multGeometrica, (1.0/arr.size()));
    mediaArmonica = arr.size() / sumaArmonica;
    
    cout << "Media geometrica: " << mediaGeometrica << endl;
    cout << "Media armonica: " << mediaArmonica << endl;
}

int main() {
    
    int opcion;
    int suma;
    
    // MENU para seleccionar el problema a resolver con opcion para terminar
    do {
        cout << endl;
        cout << "Opcion 1: conversion celsius farenheit" << endl;
        cout << "Opcion 2: serie aritmetica" << endl;
        cout << "Opcion 3: medias geometrica y armonica" << endl;
        cout << "Opcion 4: TERMINAR" << endl;
        cout << endl;
        cout << "Ingrese numero de opcion" << endl;
        cin >> opcion;
        
        // Llama a la funcion segun la opcion seleccionada
        switch (opcion) {
            case 1:
                conversionCelsiusFarenheit();
                break;
                
            case 2:
                suma = serieAritmetica();
                cout << "Suma = " << suma << endl;
                break;
                
            case 3:
                mediasGeometricaArmonica();
                break;
                
            case 4:
                cout << "bai" << endl;
                break;
                
            default:
                cout << "OPCION INVALIDA" << endl;
                break;
        }
        
    } while (opcion != 4);
    
    return 0;
}
