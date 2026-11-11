#include "ListaDepartamentos.h"

ListaDepartamentos::ListaDepartamentos() {
	primero = NULL;
}


//en esta parte de porgrama digamos como insterrat al final buscar por codigo, elimira datos, contra y mostrar datois
//el destructor borra todos los departamentos y sus vagones


//aca se borran los departamentos cuando se ejecuta erstoe s lo que dirijen los vagones y les dice que hacer a los nodos 
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





//sirve para contra cuantos hay con un sistema simple usando un puntero de actual a obtener el siguiente vagon 
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
//vagon extra al tren y el vago agregado mediente un puntero y cambios se transforma en el final 
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






//esta funcion ayuda a buscra los datos entre lso vagones del tren de for4mq ordenada usando valores de igualdad y distintos punteros 
// se usan tambien valores que apuntanm a otras funciones 

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





//esta funcion lo que hace es eliminar un vagon del trn mediante un mecanismo de remplazos tal como se hizo en porgra 1 
//como funciona es al vagon eliminado los re ordena si eliminas uno todos los demas pasan a coupar el puesto del anterior 
//puede ocntra como mecanismo de ordenamiento simple pero muy util para nuestro dato, si n0 encuentra algo al querer eliminar devuelve 
//false y cuandoe ncuentra algo devuelve true 
//el vagon anterior se engancah al siguiente y ese se borra 
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
		return "No hay departamentos registrados ERROR 404 \n";
	}
	stringstream s;
	NodoDepartamento* actual = primero;
	while (actual != NULL) {
		s << actual->getDato()->toString() << endl;
		actual = actual->getSiguiente();
	}
	return s.str();
}




