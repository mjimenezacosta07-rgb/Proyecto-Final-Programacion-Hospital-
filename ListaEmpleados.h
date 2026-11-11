#ifndef LISTAEMPLEADOS_H
#define LISTAEMPLEADOS_H
#include "NodoEmpleado.h"

//Aca esta es como la estructura de nuestros datos de nuestro siguiente tren, aca el expediente de empleados 
//la lista es dueña de los empleados o sea al destruirse o al eliminar un vagon, libera la memoria 
//aca extra se declara el hayEmpleadosEn


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
