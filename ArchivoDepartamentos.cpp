#include "ArchivoDepartamentos.h"




// Aca se guarda cada departamento, cuantos puestos tiene y luego esos puestos, al cargar ese numero dice cuantas veces repetir 
//el guardado 


ArchivoDepartamentos::ArchivoDepartamentos(string nombre) {
	nombreArchivo = nombre;
}

ArchivoDepartamentos::~ArchivoDepartamentos() {
}





void ArchivoDepartamentos::cargar(ListaDepartamentos* lista) {
	ifstream archivo(nombreArchivo);
	if (!archivo) {
		return;
	}
	string codigo, nombre, linea, nombrePuesto;
	int cantidadPuestos, plazas;
	
	while (getline(archivo, codigo)) {
		if (codigo == "") {
			continue;
		}
		getline(archivo, nombre);
		getline(archivo, linea);
		cantidadPuestos = stoi(linea);
		
		Departamento* d = new Departamento(codigo, nombre);
		
		
		// los puestos los crea el departamento o sea hacemos una composicion 
		for (int i = 0; i < cantidadPuestos; i++) {
			getline(archivo, nombrePuesto);
			getline(archivo, linea);
			plazas = stoi(linea);
			d->agregarPuesto(nombrePuesto, plazas);
		}
		lista->insertarFinal(d);
	}
	archivo.close();
}





//aca se usa un principio para guardar los departamentos en la lista 
void ArchivoDepartamentos::guardar(ListaDepartamentos* lista) {
	ofstream archivo(nombreArchivo);
	NodoDepartamento* actual = lista->getPrimero();
	
	
	
	while (actual != NULL) {
		Departamento* d = actual->getDato();
		archivo << d->getCodigo() << endl
			<< d->getNombre() << endl
			<< d->getPuestos()->contar() << endl;
		NodoPuesto* puesto = d->getPuestos()->getPrimero();
		
		
		
		while (puesto != NULL) {
			archivo << puesto->getDato()->getNombre() << endl
				<< puesto->getDato()->getPlazas() << endl;
			puesto = puesto->getSiguiente();
		}
		actual = actual->getSiguiente();
	}
	archivo.close();
}
