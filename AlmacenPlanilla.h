#ifndef ALMACENPLANILLA_H
#define ALMACENPLANILLA_H
#include "ListaComprobantes.h"
#include "ListaEmpleados.h"
#include "ListaDepartamentos.h"

//Se usa solo para los comprobantes y su carga recibe 3 listas 
//porque este abarca los buscar empleados y departamentos ademas de el mismo 



class AlmacenPlanilla {
public:
	
	
	
	AlmacenPlanilla();
	virtual ~AlmacenPlanilla();
	
	
	
	
	virtual void cargar(ListaComprobantes* lista, ListaEmpleados* empleados,
						
						
						ListaDepartamentos* departamentos) = 0;
	virtual void guardar(ListaComprobantes* lista) =         0;
};

#endif
