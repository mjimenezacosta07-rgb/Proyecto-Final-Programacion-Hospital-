#ifndef LISTADEPARTAMENTOS_H
#define LISTADEPARTAMENTOS_H
#include "NodoDepartamento.h"

//Esta es como la estructura de datos una parte fundamental al declarar y hacer funcionar el tren con sus vagones (es solo una propuesta)
//primero se guarda el puntero primero y se dice que se puede hacer con la lista 


class ListaDepartamentos {
private:
	NodoDepartamento* primero;
	
public:
	ListaDepartamentos();
	~ListaDepartamentos();
	
	bool estaVacia();
	int contar();
	void insertarFinal          (Departamento* d);
	Departamento* buscar        (string codigo);
	bool eliminar               (string codigo);
	NodoDepartamento*           getPrimero();
	string toString();
};

#endif
