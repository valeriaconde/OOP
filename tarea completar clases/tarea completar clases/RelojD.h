//Inclusion de librerias
#include <iostream>
#include <string>
using namespace std;

#ifndef RELOJD_H
#define RELOJD_H
//Se establece la clase
class RelojD {
  //Se establecen los metodos publicos
  public:
    //Metodo constructor
    RelojD (int, int);
    RelojD();
    //Metodos modificadores
    void setHoras (int);
    void setMinutos (int);
    //Metodos de acceso
    int getHora ();
    int getMin ();
    //Metodos
    void incrementaMinutos ();
    std::string str();
  //Se establecen los atributos privados
  private:
    int iHr, iMin;
};

#endif
