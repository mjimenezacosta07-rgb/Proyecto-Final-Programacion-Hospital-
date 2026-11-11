#include "NodoPuesto.h"

NodoPuesto :: NodoPuesto(Puesto* d) {
	dato = d;
	siguiente = NULL;
	//Aca seria como un vagon que al usar el constructor dato = d y siguiente = null aca un vagon nuevo no esta enganchado a nada 
}

//el nodo no es el que llega a borrar un dato sino que se lo encarga de borrar y se lo manda a lista 

NodoPuesto::~NodoPuesto() {
}



Puesto* NodoPuesto::getDato()                  { return dato; }
NodoPuesto* NodoPuesto::getSiguiente()         { return siguiente; }
void NodoPuesto::setSiguiente(NodoPuesto* sig) { siguiente = sig; }
