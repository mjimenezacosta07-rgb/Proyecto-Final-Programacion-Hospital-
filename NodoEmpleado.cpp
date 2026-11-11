#include "NodoEmpleado.h"

//el constructor guarda al empleado y deja siguiente y null, usamos d y NULL para reducirlos en terminaciones y darles un valor 

NodoEmpleado :: NodoEmpleado(Empleado* d) {
	
	dato = d;
	//dato = d
	siguiente = NULL;
	//siguiente = NULL
	
}

NodoEmpleado :: ~NodoEmpleado() {
	
}

Empleado* NodoEmpleado::         getDato()                       { return dato; }
NodoEmpleado* NodoEmpleado::     getSiguiente()                  { return siguiente; }
void NodoEmpleado::              setSiguiente(NodoEmpleado* sig) { siguiente = sig; }
