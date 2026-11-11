#ifndef LISTAPUESTOS_H
#define LISTAPUESTOS_H
#include "NodoPuesto.h"

// Lista simplemente enlaza los puestos y la lista es como la que es dueña de los puestos y los administra ella destruye borra nodos 
//y tambien los puestos 
class ListaPuestos {
private:
	NodoPuesto* primero;
	
public:
	ListaPuestos();
	~ListaPuestos();
	
	bool estaVacia();
	int contar();
	void insertarFinal     (Puesto* p);
	Puesto* buscar         (string nombre);
	bool eliminar          (string nombre);
	NodoPuesto* getPrimero();
	string toString();
};

#endif
