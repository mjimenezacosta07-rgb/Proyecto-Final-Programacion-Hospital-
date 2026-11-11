#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include "ListaPuestos.h"

// se incuye lista puestos.h porque le departamento tiene una lista de puestos no hace falta el puesto.h 
//composicion: el departamento que es todo crea sus puestos osea las partes que tendra y los destrute en su destructor 
//un puesto no existe fuera de el 


class Departamento {
private:
	string codigo;
	string nombre;
	ListaPuestos* puestos;    //puestos lleva * porque es un puntero a una lista y esta misma se crea con new y puestos guarda la direccion 
	
	
public:
	Departamento(string cod, string nom);
	~Departamento();
	
	string getCodigo();
	string getNombre();
	void setNombre(string nom);
	
	bool agregarPuesto(string nombrePuesto, int plazas);
	bool eliminarPuesto(string nombrePuesto);
	    ListaPuestos* getPuestos();   // da la loista para que otros la recorran bien porque el archivo nesecita para poder guadrar 
	int totalPlazas();
	string toString();
};




#endif
