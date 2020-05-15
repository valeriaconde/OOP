#include "Evento.h"


//	👩‍🏭👨‍🏭 Constructor default
Evento::Evento(){
  RelojD rolexOro;
  hora = rolexOro;
  iDuracionMin = 100;
  sAsunto = "Fiesta Chava 19 XIX";
}

//	👩‍🏭👨‍🏭 Constructor con parámetros
Evento::Evento(RelojD rolex, int iDuracion, string sAsunto){
  hora = rolex;
  iDuracionMin = iDuracion;
  this->sAsunto = sAsunto;
}

// 🎮 🔏 Metodos modificadores 
void Evento::setHora(RelojD rolex){
 hora = rolex;
}
void Evento::setDuracion(int iDuracion){
   iDuracionMin = iDuracion;
}
void Evento::setAsunto(string sAsunto){
 this->sAsunto = sAsunto;
}

//💳 🔓  Metodos de acceso
RelojD Evento::getHora (){
  return hora;
}
int Evento::getDuracion(){
  return iDuracionMin;
}
string Evento::getAsunto(){
  return sAsunto;
}
//	💃🏻🕺🏽 Otros métodos
string Evento::str(){
  string a(30,'-');
  a = "\n"+ a + "\n";
  return  a + "Evento:" + a + "Hora:" + hora.str() + "\nDuracion:" + 
  to_string(iDuracionMin) + "\nAsunto:" + sAsunto + a;
}
