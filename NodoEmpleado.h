#ifndef NODOEMPLEADO_H
#define NODOEMPLEADO_H
#include "Empleado.h"

// Aca el nodo guarda un Empleado* ahi se usa un puntero que ese puntero apunta a un medico, un enfermero o alguien de administracion
// por eso una lista sirve para todos 


class NodoEmpleado {
private:
	Empleado* dato;
	NodoEmpleado* siguiente;
	
public:
	NodoEmpleado(Empleado* d);
	~NodoEmpleado();
	
	Empleado* getDato();
	NodoEmpleado* getSiguiente();
	void setSiguiente(NodoEmpleado* sig);
};

#endif
