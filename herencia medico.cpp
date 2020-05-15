#include <iostream>
#include <string>
using namespace std;

class Persona
{
	public:
	Persona();
	Persona(std::string, int);
	string getNombre();
	void setNombre(std::string);
	int getEdad();
	void setEdad(int);
	string str();

	protected:
	string nombre;
	int edad;
};

Persona::Persona() {
	nombre = "Escribe tu nombre";
	edad = 100;
}

Persona::Persona(std::string nom, int ed) {
	nombre = nom;
	edad = ed;
}

std::string Persona::getNombre() {
	return nombre;
}


void Persona::setNombre(std::string nom) {
	nombre = nom;
}

void Persona::setEdad(int ed) {
	edad = ed;
}

std::string Persona::str() {
   return "Nombre: "+ nombre + "edad:" + to_string(edad);
}



class Estudiante : public Persona {
public:
		Estudiante();
		Estudiante(string, int, string);
		string getCarrera();
		void setCarrera(string);
		string str();
	private:
		string carrera;
};

class Medico : public Persona {
private:
    string especialidad;
    int pacientes;
public:
    Medico();
    Medico(string, int, string, int);
    string getEspecialidad();
    int getPacientes();
    void setEspecialidad(string);
    void setPacientes(int);
    string str();
};
  
std::string Medico::str() {
   return "Nombre: "+ nombre + "edad:" + to_string(edad) + "Especialidad: " +especialidad + "Pacientes: " + to_string(pacientes);
}

Medico::Medico() : Persona() {
    especialidad = "General";
    pacientes = 0;
}

Medico::Medico(string nombre, int edad, string especialidad, int pacientes) : Persona(nombre, edad) {
    this -> especialidad = especialidad;
    this -> pacientes = pacientes;
}

Estudiante::Estudiante() : Persona() {
	carrera = "Escribe tu carrera";
}

Estudiante::Estudiante(std::string nom, int ed, std::string ca) : Persona(nom, ed) {
	carrera = ca;
}

string Estudiante::getCarrera() {
	return carrera;
}

void Estudiante::setCarrera(std::string ca) {
	carrera = ca;
}

std::string Estudiante::str() {
	return "Nombre: "+nombre+" edad: "+ to_string(edad)+ " Carrera: "+ carrera;
}


int Persona::getEdad() {	
	return edad;
}

int main() {
    Medico gatell("Hugo Lopez", 51, "Epidemiologo", 0), manuel;
    
    cout << "Subsecretario de Salud: " << endl;
    cout << gatell.str() << endl;
    cout << "Secretario de Salud de NL: " << endl;
    cout << manuel.str() << endl;
    
    
  Estudiante  chabelo("Chabelo", 125, "Dr."),  chilindrina;
	Persona  chano("Chano", 80),  chonita;
	cout << "Los datos del estudiante mayor: " << chabelo.str() << endl;
	
	cout<<"Los datos de la estudiante mayor: "<<endl;
	cout<<"Nombre " << chilindrina.getNombre() <<" Edad: "<< chilindrina.getEdad() << " Carrera "<< chilindrina.getCarrera();

	cout<<"Los datos de la persona 1 son: "<< chano.str() << endl;
	;
	cout<<"Los datos de la persona 2 son: "<<endl;
	cout<<"Nombre "<<chonita.getNombre()<<" Edad: "<<chonita.getEdad();
	return 0;

}
