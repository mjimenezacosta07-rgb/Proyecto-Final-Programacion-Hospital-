#include "NodoDepartamento.h"

NodoDepartamento::NodoDepartamento(Departamento* d) {
	dato = d;
	siguiente = NULL;
}

NodoDepartamento::~NodoDepartamento() {
}

Departamento* NodoDepartamento::getDato()                  { return dato; }
NodoDepartamento* NodoDepartamento::getSiguiente()         { return siguiente; }
void NodoDepartamento::setSiguiente(NodoDepartamento* sig) { siguiente = sig; }

//aca se programan los metodos ya declarados en el nodo departamento.h el constructor guarda el departamento rerspectivo
//y deja siguiente en NULL muy importante para la secuencia del tren y que no de error 
