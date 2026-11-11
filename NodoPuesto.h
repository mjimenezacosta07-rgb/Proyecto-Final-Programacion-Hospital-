#ifndef NODOPUESTO_H
#define NODOPUESTO_H
#include "Puesto.h"





//Un nodo guarda un dato que es como un puesto y manda la direccion del siguiemnte nodo es como una cadena 
class NodoPuesto {
private:
	Puesto* dato;                    //es la carga que trae o la direccion de un puesto 
	NodoPuesto* siguiente;           //es la direccion de el siguiente nodo
	
public:
	NodoPuesto(Puesto* d);
	~NodoPuesto();
	
	Puesto* getDato();
	NodoPuesto* getSiguiente();
	void setSiguiente(NodoPuesto* sig);

};
#endif
