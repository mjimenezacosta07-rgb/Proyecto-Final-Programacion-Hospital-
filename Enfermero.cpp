#include "Enfermero.h"

// Recargo que se paga por cada turno nocturno (valor de ejemplo).
const double MONTO_POR_TURNO_NOCTURNO = 15000;

Enfermero::Enfermero(string ced, string nom, string codDep, double salario, string are)
	: Empleado(ced, nom, codDep, salario) {
	area = are;
	turnosNocturnos = 0;
}

Enfermero::~Enfermero() {
}

string Enfermero::getTipo()                   { return "ENFERMERO"; }
string Enfermero::getDatoPropio()             { return area; }
string Enfermero::getNombreBono()             { return "turnos nocturnos"; }
int Enfermero::getCantidadBono()              { return turnosNocturnos; }
void Enfermero::setCantidadBono(int cantidad) { turnosNocturnos = cantidad; }



double Enfermero::calcularBonificacion() {
	return turnosNocturnos * MONTO_POR_TURNO_NOCTURNO;
}

string Enfermero::toString() {
	stringstream s;
	s << "Tipo..............: Enfermero" << endl
		<< Empleado::toString()
		<< "Área.............: " << area << endl
		<< "Turnos nocturnos.: " << turnosNocturnos << endl;
	return s.str();
}
