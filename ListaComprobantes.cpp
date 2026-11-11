#include "ListaComprobantes.h"
// Aca se programan las operaciones del tren los comprobantes o sea de comprobante pago h y cpp despues nodo comprobante h y cpp 
// lo que hace mas que todo o sea se integra con las antes mencionadas pero como tal se calcula el comprobante en ellas 
//aca lo que se hacen son otras cosas como: insertar al final, buscar por numero, borrar comprobantes al cerrarse pero NO borra 
//a los empleados, es obvio que no los va a borrar con el ejemplo que dijimos antes o sea, si borras un recibo no vas a borrar el 
//local que te lo dio o las mismas cosas que compraste, ademas usa estos 4 metodos nuevos 
//existeComprobante: esto evita que se haga un doble cobro al mes
//hayComprobantesDe: dice si un empleado tiene comprobantes, para no dejar borrarlo
//hayComprobantesEn: dice si un departamento tiene comprobantes, para no dejar borrarlo 
//mayorNumero: da el numero del comprobante siguiente 


//le pedi ayuda a claude que me diera una indicacion de ayuda de como podia estructurarlo porque me perdi un poco al elaborarlo 
// ya que algunas veces dejaba sin cubrir algunos huecos que podrian perjudicar el sistema 


ListaComprobantes::ListaComprobantes() {
	primero = NULL;
}






ListaComprobantes::~ListaComprobantes() {
	NodoComprobante* actual = primero;
	while (actual != NULL) {
		NodoComprobante* siguiente = actual->getSiguiente();
		delete actual->getDato(); // borra el comprobante pero no al empleado
		delete actual;
		actual = siguiente;
	}
	primero = NULL;
}






bool ListaComprobantes::estaVacia() {
	return primero == NULL;
}





int ListaComprobantes::contar() {
	int cantidad = 0;
	NodoComprobante* actual = primero;
	while (actual != NULL) {
		cantidad++;
		actual = actual->getSiguiente();
	}
	return cantidad;
}









void ListaComprobantes::insertarFinal(ComprobantePago* c) {
	NodoComprobante* nuevo = new NodoComprobante(c);
	if (primero == NULL) {
		primero = nuevo;
	} else {
		NodoComprobante* actual = primero;
		while (actual->getSiguiente() != NULL) {
			actual = actual->getSiguiente();
		}
		actual->setSiguiente(nuevo);
	}
}







ComprobantePago* ListaComprobantes::buscar(int numero) {
	NodoComprobante* actual = primero;
	while (actual != NULL) {
		if (actual->getDato()->getNumero() == numero) {
			return actual->getDato();
		}
		actual = actual->getSiguiente();
	}
	return NULL;
}





//esta parte evita que se pague 2 veces a la misma persona en un mes 


bool ListaComprobantes::existeComprobante(string cedula, string periodo) {
	NodoComprobante* actual = primero;
	while (actual != NULL) {
		ComprobantePago* c = actual->getDato();
		if (c->getEmpleado()->getCedula() == cedula && c->getPeriodo() == periodo) {
			return true;
		}
		actual = actual->getSiguiente();
	}
	return false;
}






//aca revisa si hay comprobantes usando punteros a diferentes partes con su cedula 

bool ListaComprobantes::hayComprobantesDe(string cedula) {
	NodoComprobante* actual = primero;
	while (actual != NULL) {
		if (actual->getDato()->getEmpleado()->getCedula() == cedula) {
			return true;
		}
		actual = actual->getSiguiente();
	}
	return false;
}




//aca esto revisa si un departamento tiene comprobantes si tiene devuelve true, el que impide borrarlo es SistemaPlanilla 
bool ListaComprobantes::hayComprobantesEn(string codigoDepartamento) {
	NodoComprobante* actual = primero;
	while (actual != NULL) {
		Departamento* d = actual->getDato()->getDepartamento();
		if (d != NULL && d->getCodigo() == codigoDepartamento) {
			return true;
		}
		actual = actual->getSiguiente();
	}
	return false;
}


//esta parte se usa para darle el siguiente numero al siguiente comprobante para llevarlos en orden 
int ListaComprobantes::mayorNumero() {
	int mayor = 0;
	NodoComprobante* actual = primero;
	while (actual != NULL) {
		if (actual->getDato()->getNumero() > mayor) {
			mayor = actual->getDato()->getNumero();
		}
		actual = actual->getSiguiente();
	}
	return mayor;
}




NodoComprobante* ListaComprobantes::getPrimero() {
	return primero;
}



//si no encuentra comprobantes en el sistema 

string ListaComprobantes::toString() {
	if (estaVacia()) {
		return "No hay comprobantes registrados en el sistema \n";
	}
	stringstream s;
	NodoComprobante* actual = primero;
	while (actual != NULL) {
		s << actual->getDato()->resumen();
		actual = actual->getSiguiente();
	}
	return s.str();
}
