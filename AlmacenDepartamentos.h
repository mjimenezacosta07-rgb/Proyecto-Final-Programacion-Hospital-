#ifndef ALMACENDEPARTAMENTOS_H
#define ALMACENDEPARTAMENTOS_H
#include "ListaDepartamentos.h"

// aca se declaran pero solo para los departamentos ISP
//es lo mismo que los almacenes empleados nadamkas que para los departamentos 

class AlmacenDepartamentos {
public:
	AlmacenDepartamentos();
	virtual ~AlmacenDepartamentos();
	
	virtual void cargar(ListaDepartamentos* lista) = 0;
	virtual void guardar(ListaDepartamentos* lista) = 0;
};

#endif
