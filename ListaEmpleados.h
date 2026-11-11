#ifndef LISTAEMPLEADOS_H
#define LISTAEMPLEADOS_H
#include "NodoEmpleado.h"

//aca esta es como la estructura de nuestros datos de nuestro siguiente tren, aca el expediente de empleadis 
//la lista es duela de los empleados osea al destruirse o al eliminar un vagon, libera la memoria 
//asca extra se declara el hayEmpleadosEn


class ListaEmpleados {
private:
	NodoEmpleado* primero;
	
	
	
	
	
public:
	ListaEmpleados();
	~ListaEmpleados();//destructor 
	
	bool estaVacia();
	int contar();
	void insertarFinal          (Empleado* e);
	Empleado* buscar            (string cedula);
	bool eliminar               (string cedula);
	bool hayEmpleadosEn         (string codigoDepartamento);
	NodoEmpleado*               getPrimero();
	string                      toString();
};

#endif
