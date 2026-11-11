#ifndef NODODEPARTAMENTO_H
#define NODODEPARTAMENTO_H
#include "Departamento.h"

// aca declaramos como cada vagon del tren osea el qie guarda Departamento+ y el siguiente 
//con suss respectivos metodos set y los get 
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
