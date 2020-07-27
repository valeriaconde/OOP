//
//  main.cpp
//  Poliformismo
//
//  Created by Ma. Guadalupe Roque on 5/17/20.
//  Copyright © 2020 Invitado. All rights reserved.


/* Por fin vamos a introducir un concepto muy importante de la programación orientada a objetos: el polimorfismo.

En lo que concierne a clases, el polimorfismo en C++, llega a su máxima expresión cuando las usamos junto con apuntadores .

C++ nos permite acceder a objetos de una clase derivada usando un apuntador a la clase base. En esa capacidad es posible el polimorfismo.

Pero, sólo podremos acceder a datos y funciones que existan en la clase base, los datos y funciones propias de los objetos de clases derivadas serán inaccesibles. */

#include <iostream>
#include <string>
using namespace std;

class Persona
{
    public:
    Persona();
    Persona(std::string, int);
    std::string getNombre();
    void setNombre(std::string);
    int getEdad();
    void setEdad(int);
    std::string str();

    protected:
    std::string nombre;
    int edad;
};

Persona::Persona()
{
    nombre = "Chilindrina";
    edad = 100;
}

Persona::Persona(std::string nom, int ed)
{
    nombre = nom;
    edad = ed;
}

std::string Persona::getNombre()
{
    return nombre;
}

int Persona::getEdad()
{
    return edad;
}

void Persona::setNombre(std::string nom)
{
    nombre = nom;
}

void Persona::setEdad(int ed)
{
    edad = ed;
}

std::string Persona::str()
{
   return "Persona - \nNombre: "+ nombre + "\nedad:" + to_string(edad);
}

class Estudiante : public Persona
{
public:
        Estudiante();
        Estudiante(std::string, int, std::string);
        std::string getCarrera();
        void setCarrera(std::string);
        std::string str();
    private:
        std::string carrera;
};

Estudiante::Estudiante() : Persona()
{
    carrera = "Ing. Programación";
}

Estudiante::Estudiante(std::string nom, int ed, std::string ca) : Persona(nom, ed)
{
    carrera = ca;
}

string Estudiante::getCarrera()
{
    return carrera;
}

void Estudiante::setCarrera(std::string ca)
{
    carrera = ca;
}
// overriding
std::string Estudiante::str()
{
  return "Estudiante : \nNombre: " + nombre + "\nEdad: " + to_string(edad) + "\nCarrera: " + carrera;
    
}

class Medico : public Persona
{
    public:
    Medico();
        Medico(std::string, int, std::string, int);
        std::string getEspecialidad();
        int getPacientes();
        void setEspecialidad(std::string);
        void setPacientes(int);
        std::string str();
    private:
        std::string especialidad;
        int pacientes;
};
Medico::Medico( ) : Persona( )
{
    especialidad = "Epidemiologo";
    pacientes = 645;
}
// Constructor con parámetros
Medico::Medico(string nombre, int edad, string especialidad, int pacientes) : Persona(nombre, edad)
{   // prefijo this-> para diferenciar el nombre del atributo al nombre del parámetro
    this->especialidad = especialidad;
    this->pacientes = pacientes;
}

string Medico::getEspecialidad()
{
    return especialidad;
}

int Medico::getPacientes()
{
    return pacientes;
}
// overriding
string Medico::str( )
{
    return "Medico: \nNombre: " + nombre + "\nedad: " + to_string(edad) + "\nEspecialidad: " + especialidad + "\nPacientes: " +  to_string(pacientes);
}


int main() {
    // Una variable que puede guardar una dirección de memoria se
    // llama apuntador. Sintaxis: tipo *ptrNombre;
    Persona *ptrPersona, chanoPersona("Chano", 80);
    Estudiante *ptrEstudiante, chaveloEstudiante("Chavelo", 90, "Dr.");
    
        Medico *ptrMedico, gattel("Hugo Lopez",51,"infectologo", 0);
        
    // El operador & se utiliza para obtener la dirección de una
    // variable y tiene el siguiente formato:
    ptrPersona = &chanoPersona;
    ptrEstudiante = &chaveloEstudiante;
    cout << "\nPtrPersona(chanoPersona):" << ptrPersona << endl;
    cout << "\nPtrEstudiante(chaveloEstudiante):" << ptrEstudiante << endl;
    cout << "\nPtrPersona(chanoPersona)->str():" << ptrPersona->str() << endl;
    cout << "\nPtrEstudiante(chaveloEstudiante)->str():" << ptrEstudiante->str() << endl;
    
    // Ahora el apuntador persona se le asigna la dirección de un objeto estudiante
    // sin embargo el objeto al almacenarlo en un apuntador de la clase Base - este
    // objeto se comporta como si fuera de la clase Base- ****La funcionalidad depende del
    // tipo de apuntador, no del tipo del objeto *****-
    // Por lo tanto solo se podrán llamar a los métodos de la clase Persona
    ptrPersona = &chaveloEstudiante;
    cout << "\nPtrPersona(chaveloEstudiante):" << ptrPersona << endl;
    cout << "\nPtrPersona(chaveloEstudiante)->str():" << ptrPersona->str() << endl;
    
    return 0;

}
