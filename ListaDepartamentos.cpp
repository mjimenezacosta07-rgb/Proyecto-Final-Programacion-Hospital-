#include "ListaDepartamentos.h"

ListaDepartamentos::ListaDepartamentos() {
	primero = NULL;
}


//En esta parte de programa digamos como insertar al final buscar por codigo, eliminar datos, contar y mostrar datos
//el destructor borra todos los departamentos y sus vagones


//aca se borran los departamentos cuando se ejecuta esto es lo que dirigen los vagones y les dice que hacer a los nodos 
ListaDepartamentos::~ListaDepartamentos() {
	NodoDepartamento* actual = primero;
	while (actual != NULL) {
		NodoDepartamento* siguiente = actual->getSiguiente();
		delete actual->getDato(); // borra el departamento (y este borra sus puestos)
		delete actual;
		actual = siguiente;
	}
	primero = NULL;
}




//es la lista , la que esta vacia no tienen ningun departamento 
bool ListaDepartamentos::estaVacia() {
	return primero == NULL;
}





//sirve para contar cuantos hay con un sistema simple usando un puntero de actual a obtener el siguiente vagon 
int ListaDepartamentos::contar() {
	int cantidad = 0;
	NodoDepartamento* actual = primero;
	while (actual != NULL) {
		cantidad++;
		actual = actual->getSiguiente();
	}
	return cantidad;
}




//se usa un sistema simple que el ultimo vagon se cambia de usar como ultimo para poder agregar un departamento o 
//vagon extra al tren y el vagon agregado mediante un puntero y cambios se transforma en el final 
void ListaDepartamentos::insertarFinal(Departamento* d) {
	NodoDepartamento* nuevo = new NodoDepartamento(d);
	if (primero == NULL) {
		primero = nuevo;
	} else {
		NodoDepartamento* actual = primero;
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}
}






//esta funcion ayuda a buscar los datos entre los vagones del tren de forma ordenada usando valores de igualdad y distintos punteros 
// se usan tambien valores que apuntan a otras funciones 

//los punteros apuntan a nodos y a departamentos recorre vagon por vagon y recorre el codigo y si no encuentra devuelve NULL

Departamento* ListaDepartamentos::buscar(string codigo) {
	NodoDepartamento* actual = primero;
	while (actual != NULL) {
		if (actual->getDato()->getCodigo() == codigo) {
			return actual->getDato();
		}
		actual = actual->getSiguiente();
	}
	return NULL;
}





//esta funcion lo que hace es eliminar un vagon del tren mediante un mecanismo de remplazos tal como se hizo en progra 1 
//como funciona es que en la lista solo cambia el puntero del nodo anterior  
//puede contar como mecanismo de ordenamiento simple pero muy util para nuestro dato, si no encuentra algo al querer eliminar devuelve 
//false y cuando encuentra algo devuelve true 
//el vagon anterior se engancha al siguiente y ese se borra 
bool ListaDepartamentos::eliminar(string codigo) {
	NodoDepartamento* anterior = NULL;
	NodoDepartamento* actual = primero;
	while (actual != NULL && actual->getDato()->getCodigo() != codigo) {
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





//para obtener un departamento 

NodoDepartamento* ListaDepartamentos::getPrimero() {
	return primero;
}




//por si no hay ningun departamento aun registrado y tira un ligero error que es el error de no encontrar algo 
string ListaDepartamentos::toString() {
	if (estaVacia()) {
		return "No hay departamentos registrados.\n";
	}
	stringstream s;
	NodoDepartamento* actual = primero;
	while (actual != NULL) {
		s << actual->getDato()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}




