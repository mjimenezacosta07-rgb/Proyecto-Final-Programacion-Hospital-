#include <iostream>
#include "Medico.h"
#include "Enfermero.h"
#include "Administrativo.h"
#include "ListaDepartamentos.h"
#include "ListaEmpleados.h"
#include <windows.h>   // para que la consola muestre bien las tildes (le pregunte a Claude que usar y me dijo windows.h)

using namespace std;

// main provisional: prueba de la etapa 4 (listas de departamentos y empleados).
// El main definitivo se hace en la etapa 10.
int main() {
	SetConsoleOutputCP(1252);   // la consola escribe con tildes y enes
	SetConsoleCP(1252);         // y tambien las lee bien cuando el usuario escribe

	cout << "===== DEPARTAMENTOS =====" << endl;
	ListaDepartamentos* deps = new ListaDepartamentos();
	deps->insertarFinal(new Departamento("D01", "Emergencias"));
	deps->insertarFinal(new Departamento("D02", "Pediatría"));
	deps->buscar("D01")->agregarPuesto("Cirujano", 2);
	cout << deps->toString();

	cout << "===== EMPLEADOS =====" << endl;
	ListaEmpleados* emps = new ListaEmpleados();
	emps->insertarFinal(new Medico("1-1111-1111", "Ana Rojas Mora", "D01", 1500000, "Emergencias"));
	emps->insertarFinal(new Enfermero("3-3333-3333", "Luis Mora", "D01", 800000, "UCI"));
	emps->insertarFinal(new Administrativo("5-5555-5555", "María Jiménez", "D02", 600000, "RRHH"));
	cout << emps->toString();

	cout << "===== REVISIONES =====" << endl;
	cout << "Empleados en la lista (debe dar 3): " << emps->contar() << endl;
	cout << "Hay alguien en D01 (debe dar 1): " << emps->hayEmpleadosEn("D01") << endl;
	cout << "Hay alguien en D09 (debe dar 0): " << emps->hayEmpleadosEn("D09") << endl;
	cout << "Eliminar a Luis (debe dar 1): " << emps->eliminar("3-3333-3333") << endl;
	cout << "Eliminar a alguien que no existe (debe dar 0): " << emps->eliminar("9-9999-9999") << endl;
	cout << "Empleados que quedan (debe dar 2): " << emps->contar() << endl;

	delete emps;   // borra a cada empleado con su destructor correcto (virtual)
	delete deps;   // borra los departamentos, y estos borran sus puestos

	cout << "Fin de la prueba: si llegaste aqui, todo se borro sin caerse." << endl;
	return 0;
}
