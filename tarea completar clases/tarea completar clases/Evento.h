#include <iostream>
#include <string>
using namespace std;
//#endif

#include "RelojD.h"

//Se establece la clase
class Evento {
  //Se establecen los metodos publicos
  public:
    //	👩‍🏭👨‍🏭 Constructores
    Evento();
    Evento (RelojD, int, string);

    // 🎮 🔏 Metodos modificadores 🎂🎉
    void setHora(RelojD);
    void setDuracion(int);
    void setAsunto(string);
 
    //💳 🔓  Metodos de acceso
    RelojD getHora ();
    int getDuracion();
    string getAsunto();

    //	💃🏻🕺🏽 Otros métodos
    string str();
  
  //	🔐 atributos privados 
  private:
    RelojD hora; 
    int iDuracionMin; 
    std::string sAsunto;
};

