#ifndef MENU_H
#define MENU_H
#include "SistemaPlanilla.h"
#include "Entrada.h"
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"

//en esta parte se declaran los 3 submenus osea los Departamernto, Empleados y Planilla una funcion por cada uno y se da el INICIAR()
//es la unica parte del porgrama que habla con el usuario con los cout 
//no calcula salarios ni toca archuvs, le pide a la planilla que relacione por asociacion con sistemapkanilla y con Entrada
//los usa pero no los crea ni destruye osea solo lee


class Menu {
private:
	
	
	
	SistemaPlanilla* sistema;
	Entrada* entrada;
	
	
	void menuDepartamentos();
	void menuEmpleados();
	void menuPlanilla();
	
	
	void agregarDepartamento();
	void agregarPuesto();
	void eliminarPuesto();
	void eliminarDepartamento();
	
	
	void registrarEmpleado();
	void consultarEmpleado();
	void modificarEmpleado();
	void registrarNovedades();
	void eliminarEmpleado();
	
	
	void calcularPlanilla();
	void verComprobante();
	void procesarPago();
	void procesarPagosPeriodo();
	void resumenPeriodo();
	
	
public:
	Menu(SistemaPlanilla* s, Entrada* e);
	~Menu();
	void iniciar();
};

#endif
