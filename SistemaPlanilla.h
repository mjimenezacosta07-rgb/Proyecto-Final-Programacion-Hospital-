#ifndef SISTEMAPLANILLA_H
#define SISTEMAPLANILLA_H
#include "AlmacenEmpleados.h"
#include "AlmacenDepartamentos.h"
#include "AlmacenPlanilla.h"
#include "CalculadoraSalario.h"

//Aca en esta capa es por asi decirlo el controlador, aca esto coordina todo listas en memoria, la calculadora,
//los almacenes. las 3 listas son suyas o sea crea y las destruye eso es una composicion,
//los almacenes y la calculadora llegan poniendolos desde el main por eso el constructor o sea el inyeccion de independencia 
// solo conoce sus clases abstractas, no si por detras hay archivos txt u otra cosa en el, aca no se usa cin ni cout 
//lo que devuelve es bool, numeros o textos para que la vista del menu decida que mostrar,

//dice que tiene la clase por dentro o sea las 3 listas 3 almacenes y la calculadora y tambien declara todos sus metodos 



class SistemaPlanilla {
private:
	ListaEmpleados*       empleados;
	ListaDepartamentos*   departamentos;
	ListaComprobantes*    comprobantes;
	AlmacenEmpleados*     almacenEmpleados;
	AlmacenDepartamentos* almacenDepartamentos;
	AlmacenPlanilla*      almacenPlanilla;
	CalculadoraSalario*   calculadora;
	
	void guardarTodo();
	
	
	
public:
	SistemaPlanilla(AlmacenEmpleados* ae, AlmacenDepartamentos* ad,
					AlmacenPlanilla* ap, CalculadoraSalario* calc);
	~SistemaPlanilla();
	
	
	
	
	// ACA SE DECLARAN LOS DEPARTAMENTOS Y SUS PUESTOS 
	Departamento* buscarDepartamento(string codigo);
	bool agregarDepartamento(string codigo, string nombre);
	bool agregarPuesto(string codigoDep, string nombrePuesto, int plazas);
	bool eliminarPuesto(string codigoDep, string nombrePuesto);
	bool puedeEliminarDepartamento(string codigo);
	bool eliminarDepartamento(string codigo);
	string listarDepartamentos();
	bool hayDepartamentos();
	
	
	
	
	// ACA SE DECLARAN LOS EMPLEADOS 
	Empleado* buscarEmpleado(string cedula);
	bool agregarEmpleado(Empleado* e);
	bool modificarEmpleado(string cedula, string nombre, string codigoDep, double salario);
	bool registrarNovedades(string cedula, int horasExtra, int cantidadBono);
	bool tieneComprobantes(string cedula);
	bool eliminarEmpleado(string cedula);
	string listarEmpleados();
	
	
	
	
	// ACA SE DECLARA LA PLANILLA 
	int calcularPlanilla(string periodo);
	ComprobantePago* buscarComprobante(int numero);
	bool procesarPago(int numero);
	int procesarPagosPeriodo(string periodo);
	string listarComprobantes();
	string resumenPeriodo(string periodo);
};

#endif
