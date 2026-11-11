#ifndef ARCHIVOEMPLEADOS_H
#define ARCHIVOEMPLEADOS_H
#include <fstream>
#include "AlmacenEmpleados.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"




// aca se hace una implementacion osea aca se guardan y carga los empleados en un archivo de texto plano
//cada empleado ocupa 8 lineas en orden: tipo, cedula, nombre, departamento, salario, horas extra, dato propio(especialidad, area, oficina
// y la cantidad del bono 



class ArchivoEmpleados : public AlmacenEmpleados {
private:
	string nombreArchivo;
	
	
	
public:
	ArchivoEmpleados(string nombre);
	~ArchivoEmpleados();
	
	void cargar (ListaEmpleados* lista)  override;
	void guardar(ListaEmpleados* lista) override;
};

#endif
