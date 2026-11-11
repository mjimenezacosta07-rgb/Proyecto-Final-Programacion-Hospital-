#include "ArchivoPlanilla.h"
//aca se guarda en 13 lineas este es el mas delicado de los 3 ya que este guarda la cedula y el codigo del departamento, no punteros 
//y al cargarbusca los objetos reales anteriormente creados 



ArchivoPlanilla::ArchivoPlanilla(string nombre) {
	nombreArchivo = nombre;
}





ArchivoPlanilla::~ArchivoPlanilla() {
}





//aca se cargan los comprobantes leyendo el archivo con getline 
void ArchivoPlanilla::cargar(ListaComprobantes* lista, ListaEmpleados* empleados,
							 ListaDepartamentos* departamentos) {
	ifstream archivo(nombreArchivo);
	if (!archivo) {
		return;
	}
	string linea, periodo, cedula, codigoDep, estado;
	int numero, horas, cantidadBono;
	double base, extras, bono, salud, pensiones, banco;
	
	
	
	
	while (getline(archivo, linea)) {
		if (linea == "") {
			continue;
		}
		numero = stoi(linea);
		getline(archivo,         periodo);
		getline(archivo,         cedula);
		getline(archivo,         codigoDep);
		getline(archivo, linea); horas = stoi(linea);
		getline(archivo, linea); cantidadBono = stoi(linea);
		getline(archivo, linea); base = stod(linea);
		getline(archivo, linea); extras = stod(linea);
		getline(archivo, linea); bono = stod(linea);
		getline(archivo, linea); salud = stod(linea);
		getline(archivo, linea); pensiones = stod(linea);
		getline(archivo, linea); banco = stod(linea);
		getline(archivo, estado);
		
		
		
		
		
		// en el archivo solo esta la cedula y el codigo y aca se buscan los objetos reales para volver a armarlos a su agregacion 
		//respectiva 
		
		
		Empleado* e = empleados->buscar(cedula);
		Departamento* d = departamentos->buscar(codigoDep);
		if (e != NULL) {
			ComprobantePago* c = new ComprobantePago(numero, periodo, e, d);
			c->setIngresos(horas, cantidadBono, base, extras, bono);
			c->setDeducciones(salud, pensiones, banco);
			c->setEstado(estado);
			lista->insertarFinal(c);
		}
	}
	
	archivo.close();
}



// aca se recorre la lista y se escribe en el archivo cada comporbante con sus datos 
void ArchivoPlanilla::guardar(ListaComprobantes* lista) {
	ofstream archivo(nombreArchivo);
	archivo << fixed << setprecision(2);
	NodoComprobante* actual = lista->getPrimero();
	while (actual != NULL) {
		ComprobantePago* c = actual->getDato();
		string codigoDep = "";
		if (c->getDepartamento() != NULL) {
			codigoDep = c->getDepartamento()->getCodigo();
		}
		
		
		
		
		archivo << c->getNumero() << endl
			<< c->getPeriodo() << endl
			<< c->getEmpleado()->getCedula() << endl
			<< codigoDep << endl
			<< c->getHorasExtra() << endl
			<< c->getCantidadBono() << endl
			<< c->getSalarioBase() << endl
			<< c->getMontoHorasExtra() << endl
			<< c->getBonificacion() << endl
			<< c->getDeduccionSalud() << endl
			<< c->getDeduccionPensiones() << endl
			<< c->getDeduccionBanco() << endl
			<< c->getEstado() << endl;
		actual = actual->getSiguiente();
	}
	archivo.close();
}
