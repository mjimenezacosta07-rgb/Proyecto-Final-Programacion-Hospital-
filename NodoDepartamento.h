#ifndef NODODEPARTAMENTO_H
#define NODODEPARTAMENTO_H
#include "Departamento.h"

// Aca declaramos como cada vagon del tren o sea el que guarda Departamento+ y el siguiente 
//con sus respectivos metodos set y los get 
class NodoDepartamento {
private:
	Departamento* dato;
	NodoDepartamento* siguiente;
	
public:
	NodoDepartamento(Departamento* d);
	~NodoDepartamento();
	
	Departamento* getDato();
	NodoDepartamento* getSiguiente();
	void setSiguiente(NodoDepartamento* sig);
};

#endif
