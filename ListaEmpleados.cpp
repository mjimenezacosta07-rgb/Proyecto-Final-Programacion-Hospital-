#include "ListaEmpleados.h"



// Se programan las mismas operaciones pero por departamentos o sea por cedula, ademas agregamos una nueva funcion o sea un nuevo parametro 
//el cual es hayEmpleadosEn que revisa si hay alguien en un vagon o sea revisa si esta ocupado y por quien o sea no por quien pero 
//revisa si esta ocupado 


ListaEmpleados::ListaEmpleados() {
	primero = NULL;
}





ListaEmpleados::~ListaEmpleados() {
	NodoEmpleado* actual = primero;
	while (actual != NULL) {
		NodoEmpleado* siguiente = actual->getSiguiente();
		//delete con un Empleado* o sea un puntero como es un destructor virtual se libera aunque el objeto sea un medico o un enfermero etc 
		delete actual->getDato();
		delete actual;
		actual = siguiente;
	}
	primero = NULL;
}



//revisa la lista
bool ListaEmpleados::estaVacia() {
	return primero == NULL;
}



//cuenta los vagones con datos 
int ListaEmpleados::contar() {
	int cantidad = 0;
	NodoEmpleado* actual = primero;
	while (actual != NULL) {
		cantidad++;
		actual = actual->getSiguiente();
	}
	return cantidad;
}





//hace lo que hicimos en Lista Departamento nada mas que con un empleado para agregar otro al vagon 
void ListaEmpleados::insertarFinal(Empleado* e) {
	NodoEmpleado* nuevo = new NodoEmpleado(e);
	if (primero == NULL) {
		primero = nuevo;
	} else {
		NodoEmpleado* actual = primero;
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}
}




//este buscar lo utilizan en los empleados 
Empleado* ListaEmpleados::buscar(string cedula) {
	NodoEmpleado* actual = primero;
	while (actual != NULL) {
		if (actual->getDato()->getCedula() == cedula) {
			return actual->getDato();
		}
		actual = actual->getSiguiente();
	}
	return NULL;
}





//el sistema de eliminacion es una estructura similar a como se usa en lista departamento.cpp
bool ListaEmpleados::eliminar(string cedula) {
	NodoEmpleado* anterior = NULL;
	NodoEmpleado* actual = primero;
	while (actual != NULL && actual->getDato()->getCedula() != cedula) {
		anterior = actual;
		actual = actual->getSiguiente();
	}
	if (actual == NULL) {
		return false;
	}
	if (anterior == NULL) {
		primero = actual->getSiguiente();
	} else {
		anterior->setSiguiente(actual->getSiguiente());
	}
	delete actual->getDato();
	delete actual;
	return true;
}







// Esto nos asegura de que no vayamos a borrar un vagon o bueno un departamento que aun tenga personal en el 
bool ListaEmpleados::hayEmpleadosEn(string codigoDepartamento) {
	NodoEmpleado* actual = primero;
	while (actual != NULL) {
		if (actual->getDato()->getCodigoDepartamento() == codigoDepartamento) {
			return true;
		}
		actual = actual->getSiguiente();
	}
	return false;
}








NodoEmpleado* ListaEmpleados::getPrimero() {
	return primero;
}











string ListaEmpleados::toString() {
	if (estaVacia()) {
		return "No hay empleados registrados en el sistema .\n";
	}
	stringstream s;
	NodoEmpleado* actual = primero;
	while (actual != NULL) {
		
		
		
		// toString() es virtual o sea cada objeto usa la versión de su clase
		s << actual->getDato()->toString() << "------------------------" << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}
