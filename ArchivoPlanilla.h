#ifndef ARCHIVOPLANILLA_H
#define ARCHIVOPLANILLA_H
#include <fstream>
#include "AlmacenPlanilla.h"

// aca se da una implementacion concreta osea cada comprobante ocupa 13 lineas y estan organizadas tal que asi:
//numero, periodo, cedula, codigo de departamento, horas extra, cantidad del bono, salario basde, monto de horas extra,
//bonificacion, deduccion salud 




class ArchivoPlanilla : public AlmacenPlanilla {
private:
	string nombreArchivo;
	
	
	
	
public:
	ArchivoPlanilla(string nombre);
	~ArchivoPlanilla();
	
	void cargar(ListaComprobantes* lista, ListaEmpleados* empleados,
				ListaDepartamentos* departamentos) override;
	void guardar(ListaComprobantes* lista) override;
};

#endif
