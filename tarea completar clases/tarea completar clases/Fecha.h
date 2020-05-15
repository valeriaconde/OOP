#include <iostream>
#include <string>
using namespace std;

//Se establece la clase
class Fecha {
  //Se establecen los metodos publicos
  public:
    //	👩‍🏭👨‍🏭 Constructores
    Fecha();
    Fecha (int, int, int);

    // 🎮 🔏 Metodos modificadores 🎂🎉
    void setDia(int);
    void setMes(int);
    void setYear(int);
 
    //💳 🔓  Metodos de acceso
    int getDia();
    int getMes();
    int getYear();

    //	💃🏻🕺🏽 Otros métodos
    void diaSiguiente();
    string str();
    int diasMes();
    string mes();
    
  
  //	🔐 atributos privados 
  private:
    int iDia, iMes, iYear;
};

/*
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

}

string Fecha::str(){
  string a(30,'-');
  a = "\n"+ a + "\n";
  return  a + "Fecha:" + a + "Hora:" + hora.muestra() + "\nDuracion:" + 
  to_string(iDuracionMin) + "\nAsunto:" + sAsunto + a;
}

int Fecha::diasMes(){
  
}

string Fecha::mes(){

}
*/