#include "Medico.h"

//Aca se calcula el monto que va a pagarle al medico por cada guardia 
const double MONTO_POR_GUARDIA = 35000;

//lo primero es construir la parte del empleado y luego la del medico

Medico::Medico(string ced, string nom, string codDep, double salario, string esp)
	
	//lista de inicializacion que significa que antes de construir la del medico se construye una parte del empleado con estos datos 
	//hace falta porque la cedula el nombre y el salario son private de empleado: y el constructor de medico no los puede
	//asignar directamente 
	: Empleado(ced, nom, codDep, salario) {
	especialidad = esp;
	guardias = 0;
}
Medico::~Medico() {
}
	string Medico::getTipo()                   { return "MEDICO"; }
	string Medico::getDatoPropio()             { return especialidad; }
	string Medico::getNombreBono()             { return "guardias"; }
	int Medico::getCantidadBono()              { return guardias; }
	void Medico::setCantidadBono(int cantidad) { guardias = cantidad; }
	
double Medico::calcularBonificacion() {
	return guardias * MONTO_POR_GUARDIA;
}
	
	
	string Medico::toString() {
		stringstream s;
		s << "Tipo.............: Médico" << endl
			<< Empleado::toString()
			<< "Especialidad.....: "     << especialidad << endl
			<< "Guardias del mes..: "    << guardias << endl;
		return s.str();
	}
