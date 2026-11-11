#include "Puesto.h"

Puesto::Puesto(string nom, int pla) {
	nombre = nom;
	plazas = pla;
}




Puesto::~Puesto() {
}




string Puesto::getNombre()       { return nombre; }
int Puesto::getPlazas()          { return plazas; }
void Puesto::setPlazas(int pla)  { plazas = pla; }


//Se muestran las plazas 

string Puesto :: toString() {
	stringstream s;
	s << "   - " << nombre << " (" << plazas << " plazas)" << endl;
	return s.str();
}
