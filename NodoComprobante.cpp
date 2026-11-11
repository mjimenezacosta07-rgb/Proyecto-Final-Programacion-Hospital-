#include "NodoComprobante.h"


//usamos una estructura similar que hemos usado en las listas  
//programa el vagon osea se hace su constructor y los get y setsiguiente y esto es igual a los otros nodos que hemos hecho 
//nada del otro mundo 

NodoComprobante::NodoComprobante(ComprobantePago* d) {
	
	
	dato = d;
	
	siguiente = NULL;
}





NodoComprobante::~NodoComprobante() {
}

ComprobantePago* NodoComprobante::getDato()              { return dato; }
NodoComprobante* NodoComprobante::getSiguiente()         { return siguiente; }
void NodoComprobante::setSiguiente(NodoComprobante* sig) { siguiente = sig; }
