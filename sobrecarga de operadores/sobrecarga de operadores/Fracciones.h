//
//  Fracciones.hpp
//  Revision
//
//  Created by Valeria Conde on 5/28/20.
//  Copyright © 2020 Invitado. All rights reserved.
//

#ifndef Fracciones_h
#define Fracciones_h

#include <string>
using namespace std;

#include <stdio.h>
class Fracciones{
private:
    int iNum, iDen;
public:
    // Constructor default : 0/1  2/4 debe ser 1/2
    Fracciones() {
        iNum = 0;
        iDen = 1;
    }
    
    // Constructor con parámetros :todos positivos
    Fracciones(int num, int den) {
        iNum = num;
        iDen = den;
        simplifica(iNum, iDen);
    }
    
    // funcion gcd
    int gcd(int a, int b) {
        if (b != 0) return gcd(b, a % b);
        else return a;
    }
    
    // metodo simplificar
    void simplifica(int &iNum, int &iDen) {
        int x = gcd(iNum, iDen);
        iNum = iNum / x;
        iDen = iDen / x;
        
        if (iDen < 0) {
            iNum = -iNum;
            iDen = -iDen;
        }
    }
    
    // método set cambia el valor del numerador
    void setNum(int x) {
        iNum = x;
    }
    // get retorna el valor del numerador
    int getNum() {
        return iNum;
    }
    // set cambia el valor del denominador
    void setDen(int x) {
        iDen = x;
    }
    
    // get retorna el valor del denominador
    int getDen() {
        return iDen;
    }
    
    // str retorna iNum/iDen
    string show() {
        return to_string(iNum) + "/" + to_string(iDen);
    }
    
    // strPtoFlotante la forma en punto flotante ? 1/2 = "0"
    string strFlotante() {
        return to_string((double) iNum / iDen);
    }
    // Lee una fraccion
    void input() {
        cout << "Ingresa el numerador y denominador" << endl;
        cin >> iNum >> iDen;
    }
    // despliega la fraccion
    void output() {
        cout << show() << endl;
    }
    
    // - Sobrecarga de operadores aritméticos -
   
    // Suma de dos Fracciones
     Fracciones operator +(Fracciones f2){
        Fracciones resp;
         if (iDen == f2.iDen)
         {
             resp.setNum(iNum + f2.iNum);
             resp.setDen(iDen);
         }
         else
         {
             resp.setNum(iNum * f2.iDen + iDen * f2.iNum);
             resp.setDen(iDen * f2.iDen);
         }
         simplifica(resp.iNum, resp.iDen);
         return resp;
     }
    
    // Resta de dos Fracciones
    Fracciones operator-(Fracciones f2){
        Fracciones resp;
        if (iDen == f2.iDen)
        {
            resp.setNum(iNum - f2.iNum);
            resp.setDen(iDen );
        }
        else
        {
            resp.setNum(iNum * f2.iDen - iDen * f2.iNum);
            resp.setDen(iDen * f2.iDen);
        }
        simplifica(resp.iNum, resp.iDen);
        return resp;
    }
    
    // Multiplicacion de fracciones
    Fracciones operator*(Fracciones f2) {
        Fracciones ans;
        ans.setNum(iNum * f2.getNum());
        ans.setDen(iNum * f2.getDen());
        simplifica(ans.iNum, ans.iDen);
        return ans;
    }
    
    // Division de fracciones
    Fracciones operator/(Fracciones f2) {
        Fracciones ans;
        ans.setNum(iNum * f2.getDen());
        ans.setDen(iDen * f2.getNum());
        simplifica(ans.iNum, ans.iDen);
        return ans;
    }
    
    // Operador >
    bool operator>(Fracciones f2) {
        Fracciones ans;
        ans.setNum(iNum * f2.getDen() - iDen * f2.getNum());
        ans.setDen(iDen * f2.getDen());
        
        if (ans.iNum > 0) return true;
        return false;
    }
    
    // Operador <
    bool operator<(Fracciones f2) {
        Fracciones ans;
        ans.setNum(iNum * f2.getDen() - iDen * f2.getNum());
        ans.setDen(iDen * f2.getDen());
        
        if (ans.iNum < 0) return true;
        return false;
    }
    
    // Operador ==
    bool operator==(Fracciones f2) {
           Fracciones ans;
           ans.setNum(iNum * f2.getDen() - iDen * f2.getNum());
           ans.setDen(iDen * f2.getDen());
           
           if (ans.iNum == 0) return true;
           return false;
       }
};

#endif /* Fracciones_hpp */
