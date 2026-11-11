#include "Departamento.h"



Departamento :: Departamento( string cod, string nom) {
	
	codigo = cod;
	nombre = nom;
	puestos = new ListaPuestos(); // el todo crea su colección de partes
}



// cuanedo 3elk departamento es eliminado sus puestos tambein 
Departamento::~Departamento() {
	delete puestos;
}

string Departamento::getCodigo()         { return codigo; }
string Departamento::getNombre()         {return nombre; }
void Departamento::setNombre(string nom) { nombre = nom; }

// el puesto se crea aqui en esta parte con el new pero nadie de afuera lo puede crear y devuelve false si ya excisyte un puesto con ese nombre 
bool Departamento::agregarPuesto(string nombrePuesto, int plazas) {
	if (puestos->buscar(nombrePuesto) != NULL) {
		return false;
	}
	puestos->insertarFinal(new Puesto(nombrePuesto, plazas));
	return true;
}



bool Departamento::eliminarPuesto(string nombrePuesto) {
	return puestos->eliminar(nombrePuesto);
}




ListaPuestos* Departamento::getPuestos() {
	return puestos;
}





int Departamento::totalPlazas() {
	int total = 0;
	NodoPuesto* actual = puestos->getPrimero();
	while (actual != NULL) {
		total = total + actual->getDato()->getPlazas();
		actual = actual->getSiguiente();
	}
	return total;
}





string Departamento::toString() {
	stringstream s;
	s << "[" << codigo << "] " << nombre
		<< "  (" << puestos->contar() << " puestos, " << totalPlazas() << " plazas)" << endl
		<< puestos->toString();
	return s.str();
}
//el destructor ahora en esta parte si tiene codigo y se utiliza para borrar la cadena 
