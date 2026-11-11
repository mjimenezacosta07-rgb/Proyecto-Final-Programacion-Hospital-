#include "ListaPuestos.h"

ListaPuestos::ListaPuestos() {
	primero = NULL;
}




// Recorre la lista y libera cada puesto y cada nodo
ListaPuestos::~ListaPuestos() {
	NodoPuesto* actual = primero;
	while (actual != NULL) {
		NodoPuesto* siguiente = actual->getSiguiente();
		delete actual->getDato();
		delete actual;
		actual = siguiente;
	}
	primero = NULL;
}






bool ListaPuestos::estaVacia() {
	return primero == NULL;
}

int ListaPuestos::contar() {
	int cantidad = 0;
	NodoPuesto* actual = primero;
	while (actual != NULL) {
		cantidad++;
		actual = actual->getSiguiente();
	}
	return cantidad;
}








// Inserta al final para que los datos queden en el mismo orden
// en que se registraron (y en que se guardan en el archivo).
void ListaPuestos::insertarFinal(Puesto* p) {
	NodoPuesto* nuevo = new NodoPuesto(p);
	if (primero == NULL) {
		primero = nuevo;
	} else {
		NodoPuesto* actual = primero;
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}
}








// Devuelve el puesto con ese nombre, o NULL si no está.
Puesto* ListaPuestos::buscar(string nombre) {
	NodoPuesto* actual = primero;
	while (actual != NULL) {
		if (actual->getDato()->getNombre() == nombre) {
			return actual->getDato();
		}
		actual = actual->getSiguiente();
	}
	return NULL;
}








bool ListaPuestos::eliminar(string nombre) {
	NodoPuesto* anterior = NULL;
	NodoPuesto* actual = primero;
	while (actual != NULL && actual->getDato()->getNombre() != nombre) {
		anterior = actual;
		actual = actual->getSiguiente();
	}
	if (actual == NULL) {
		return false; // no se encontró
	}
	if (anterior == NULL) {
		primero = actual->getSiguiente(); // era el primero
	} else {
		anterior->setSiguiente(actual->getSiguiente()); // se "salta" el nodo
	}
	delete actual->getDato();
	delete actual;
	return true;
}








NodoPuesto* ListaPuestos::getPrimero() {
	return primero;
}






string ListaPuestos::toString() {
	if (estaVacia()) {
		return "   (sin puestos registrados)\n";
	}
	stringstream s;
	NodoPuesto* actual = primero;
	while (actual != NULL) {
		s << actual->getDato()->toString();
		actual = actual->getSiguiente();
	}
	return s.str();
}

