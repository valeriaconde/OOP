//

#include "RelojD.h"

RelojD :: RelojD(){
  iHr = 0;
  iMin = 0;
}
//Verifica que la hora y los minutos esten dentro de un rango, de lo 
//contrario, se establecen como 00
RelojD :: RelojD (int iHr, int iMin) {
  if (iHr >= 0 && iHr <=23) {
    this->iHr = iHr;
  }
  else {
    this->iHr = 0;
  }
  if (iMin >= 0 && iMin <=59) {
    this->iMin = iMin;
  }
  else {
    this->iMin = 0;
  }
};

//Cambia la hora a la ingresada por el usuario
void RelojD :: setHoras (int iHora) {
  if (iHora >= 0 && iHora <=23) {
    iHr = iHora;
  }
  //si no esta dentro del rango, se establece como 00
  else {
    iHr = 0;
  }
}

//Cambia los minutos a los ingresados por el usuario
void RelojD :: setMinutos (int iMinutos) {
  if (iMinutos >= 0 && iMinutos <=59) {
    iMin = iMinutos;
  }
//Si no estan dentro del rango, se establencen como 00
  else {
    iMin = 0;
  }
}

//Imprime la hora en formato
int RelojD :: getHora () {
  return iHr;
}

//Imprime los minutos
int RelojD :: getMin () {
  return iMin;
}

//Incrementa los minutos por 1
void RelojD :: incrementaMinutos () {
  if (iMin == 59) {
    if (iHr == 23) {
      //En caso de ser las 23 horas con 59 minutos el reloj reinicia
      iMin = 0;
      iHr = 0;
    }
    else {
      //En caso de ser los 59 minutos solamente los minutos reinician
      iMin = 0;
      iHr++;
    }
  }
  else {
    //En caso de no cumplir con ambas especificaciones, se incrementa
    //1 a los minutos
    iMin++;
  }
}

//Imprime la hora con los minutos en formato 00:00
string RelojD :: str () {
  string reloj = "";
  if (iHr <= 9) {
    reloj = "0";
  }
  reloj = reloj+ std::to_string(iHr) +":";
    
  if (iMin <= 9) {
      reloj = reloj + "0" ;
  }

  return reloj + std::to_string(iMin);
  
}
