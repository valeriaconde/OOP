#include "Fecha.h"

//	👩‍🏭👨‍🏭 Constructor default
Fecha::Fecha(){
  iDia = 1;
  iMes = 1;
  iYear = 1900;
}

//	👩‍🏭👨‍🏭 Constructor con parámetros
Fecha::Fecha(int iD, int iM, int iY){
  iDia = iD;
  iMes = iM;
  iYear = iY;
}

// 🎮 🔏 Metodos modificadores 
void Fecha::setDia(int iD){
  iDia = iD;
}
void Fecha::setMes(int iM){
  iMes = iM;
}
void Fecha::setYear(int iY){
  iYear = iY;
}

//💳 🔓  Metodos de acceso
int Fecha::getDia (){
  return iDia;
}
int Fecha::getMes(){
  return iMes;
}
int Fecha::getYear(){
  return iYear;
}

//	💃🏻🕺🏽 Otros métodos
void Fecha::diaSiguiente(){
     iDia = 10;
     iMes = 10;
     iYear = 2010;
}

string Fecha::str(){
  string a(30,'-');
  a = "\n"+ a + "\n";
  return a;
}

// Programar el método que retorna la cantidad de dias que tiene el mes actual
int Fecha::diasMes(){
    switch (iMes) {
        case 4: case 6: case 9 : case 11:
            return 30;
            break;
        case 2:
            return 28;
            break;
        default:
            return 31;
            break;
    }
}

// Programar el método que retorna el nombre del mes en string
string Fecha::mes(){
    switch (iMes) {
        case 1:
            return "Enero";
            break;
        case 2:
            return "Febrero";
            break;
        case 3:
            return "Marzo";
            break;
        case 4:
            return "Abril";
            break;
        case 5:
            return "Mayo";
            break;
        case 6:
            return "Junio";
            break;
        case 7:
            return "Julio";
            break;
        case 8:
            return "Agosto";
            break;
        case 9:
            return "Septiembre";
            break;
        case 10:
            return "Octubre";
            break;
        case 11:
            return "Noviembre";
            break;
        default:
            return "Diciembre";
            break;
    }
}
