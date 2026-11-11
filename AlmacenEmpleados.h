#ifndef ALMACENEMPLEADOS_H
#define ALMACENEMPLEADOS_H
#include "ListaEmpleados.h"

//Se declaran las clases abstractas o sea se hace una persistencia que es una abstraccion 
//clase abstracta que dice que hacer con los empleados guardados si cargar o guardar pero no como, el sistema
//depende de esta abstraccion y no de un archivo en concreto 

class AlmacenEmpleados {
public:
	AlmacenEmpleados();
	virtual ~AlmacenEmpleados();
	
	virtual void cargar(ListaEmpleados* lista) = 0;
	virtual void guardar(ListaEmpleados* lista) = 0;
};

#endif
