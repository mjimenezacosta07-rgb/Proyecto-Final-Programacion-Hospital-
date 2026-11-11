#ifndef ALMACENEMPLEADOS_H
#define ALMACENEMPLEADOS_H
#include "ListaEmpleados.h"

//se declaran las clases abstractas osea se hace una persistencia que es una abstraccion 
//clase abstracta que dice que hacer con los empleados guadados si cargar o guardar pero no como, el sistema
//depende de esta abstracdcion y no de un archivo en concreto 

class AlmacenEmpleados {
public:
	AlmacenEmpleados();
	virtual ~AlmacenEmpleados();
	
	virtual void cargar(ListaEmpleados* lista) = 0;
	virtual void guardar(ListaEmpleados* lista) = 0;
};

#endif
