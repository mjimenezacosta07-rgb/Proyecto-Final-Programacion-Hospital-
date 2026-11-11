#include "Empleado.h"

Empleado::Empleado(string ced, string nom, string codDep, double salario) {
	cedula = ced;
	nombre = nom;
	codigoDepartamento = codDep;
	salarioBase = salario;
	horasExtra = 0;
}

Empleado::~Empleado() {
	//No existe una memoria dinamica para liberar en esta parte
}

string Empleado::getCedula()                         { return cedula; }
string Empleado::getNombre()                         { return nombre; }
string Empleado::getCodigoDepartamento()             { return codigoDepartamento; }
double Empleado::getSalarioBase()                    {return salarioBase; }
int Empleado::getHorasExtra()                        { return horasExtra; }



void Empleado::setNombre(string nom)                 { nombre = nom; }
void Empleado::setCodigoDepartamento(string codDep)  { codigoDepartamento = codDep; }
void Empleado::setSalarioBase(double salario)        { salarioBase = salario; }
void Empleado::setHorasExtra(int horas)              { horasExtra = horas; }


//aca se arma el texto con los datos comunes y las clases hijas reutilizan el llamado a empleado::toString()
//el stringstream es como un cout que en vez de escribir en la pantalla escribe un texto guardado en la memoria y si se usa cout de los << 
// y al final el x.str nos devuelve todo el texto armado asi un empleado no usa cout asi nos pide el profe 
string Empleado::toString() {
	stringstream s;
	s << fixed << setprecision(2);
	s << "Cedula............: " << cedula << endl
	  << "Nombre............: " << nombre << endl
	  << "Departamento......: " << codigoDepartamento << endl
	  << "Salario base......: "<< salarioBase << endl
	  << "Horas extra al mes: " << horasExtra << endl;
	return s.str();
}

//usamos una clase abstracta ya que como empleado almacena los datos que es un tipo como enfermero, medico, empleado, administrativo
//no tiene sentido que usemos new y ademas daria error al no almacenar nada 
