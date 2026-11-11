#ifndef NODOCOMPROBANTE_H
#define NODOCOMPROBANTE_H
#include "ComprobantePago.h"




//aca se declaran las variables private y public osea se declara por asi decirlo el vagon que vamos a usar y que guardara el ComprobantePago
//y el siguiente vagon 


class NodoComprobante {
private:
	ComprobantePago* dato;
	NodoComprobante* siguiente;
	
	
	
public:
	NodoComprobante(ComprobantePago* d);
	~NodoComprobante();
	
	ComprobantePago* getDato();
	NodoComprobante* getSiguiente();
	void setSiguiente(NodoComprobante* sig);
};

#endif
