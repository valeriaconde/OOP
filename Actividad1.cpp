//  main.cpp
//  Actividad1
//  Resuelve los 3 problemas de la actividad 1

//  Created by Valeria Conde
//  A01281637
//  10/02/20.

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// binADec
// convierte un numero binario a decimal
// parametros: un numero binario de tipo string
// regresa: un numero decimal de tipo int
int binADec(string dato) {
    int decimal = 0;
    long potencia = dato.length() - 1;
    int posicion = 0;
    while (posicion < dato.length()) {
        if (dato[posicion] == '1') {
            decimal += pow(2, potencia);
        }
        potencia -= 1;
        posicion += 1;
    }
    return decimal;
}

// biggestOf
// encuentra el mayor de tres numeros
// parametros: 3 numeros enteros
// regresa: el mayor de esos tres numeros
int biggestOf(int num1, int num2, int num3) {
    int cont = 0;
    
    if (num1 > num2) {
        if (num1 > num3) {
            cont = num1;
        } else {
            cont = num3;
        }
    } else if (num2 > num3) {
        cont = num2;
    } else {
        cont = num3;
    }
    
    return cont;
}

int main() {
    float base, altura;
    float area;
    int n1, n2, n3;
    string numBinario;
    
    cout << "Teclea la base del traingulo ";
    cin >> base;
    
    cout << "Teclea la altura del triangulo ";
    cin >> altura;
    
    area = (base * altura) / 2;
    
    /*
     CASOS PRUEBA
     base: 10
     altura: 10
     AREA: 50
     */
    
    cout << "Area del triangulo = " << area << endl;
    
    cout << "Teclea 3 numeros ";
    cin >> n1 >> n2 >> n3;
    
    cout << biggestOf(n1, n2, n3) << endl;
    
    /*
     CASOS PRUEBA
     3 2 1
     REGRESA 3
     
     1 2 3
     REGRESA 3
     
     1 3 2
     REGRESA 3
     */
    
    cout << "Numero binario: ";
    cin >> numBinario;
    
    cout << "El numero binario " << numBinario << " en decimal es: " << binADec(numBinario) << endl;
    
    /*
     CASOS PRUEBA
     100100
     REGRESA 36
     */
    
    return 0;
}
