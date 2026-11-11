#include "ArchivoEmpleados.h"





//Aca se GUARDAN cada empleado en 8 lineas al cargar, lee el tipo y crea un MEDICO, enfermero o administrativo, segun lo que se este 
//necesitando en cada caso 


ArchivoEmpleados::ArchivoEmpleados(string nombre) {
	nombreArchivo = nombre;
}




ArchivoEmpleados::~ArchivoEmpleados() {
}

// Lee el archivo línea por línea y crea el objeto del tipo correcto
// Se usa getline (y no >>) porque los nombres tienen espacios entre ellos 
//si no no nos darian 


void ArchivoEmpleados::cargar(ListaEmpleados* lista) {
	ifstream archivo(nombreArchivo);
	if (!archivo) {
		return; // la primera vez el archivo no existe: se empieza vacío
	}
	string tipo, cedula, nombre, departamento, linea, datoPropio;
	double salario;
	int horas, cantidadBono;
	
	while (getline(archivo, tipo)) {
		if (tipo == "") {
			continue; // salta líneas en blanco
		}
		getline    (archivo, cedula);
		getline    (archivo, nombre);
		getline    (archivo, departamento);
		getline    (archivo, linea);
		salario = stod(linea);   // stod convierte texto a double
		getline    (archivo, linea);
		horas = stoi(linea);     // stoi convierte texto a int
		getline    (archivo, datoPropio);
		getline    (archivo, linea);
		cantidadBono = stoi(linea);
		
		
		
		
		
		// Aqui sí hay que preguntar el tipo o sea es el único lugar donde
		// se decide cual clase crear a partir del texto del archivo que nos dan 
		
		Empleado* e = NULL;
		if (tipo == "MEDICO") {
			e = new Medico(cedula, nombre, departamento, salario, datoPropio);
		} else if (tipo == "ENFERMERO") {
			e = new Enfermero(cedula, nombre, departamento, salario, datoPropio);
		} else if (tipo == "ADMINISTRATIVO") {
			e = new Administrativo(cedula, nombre, departamento, salario, datoPropio);
		}
		if (e != NULL) {
			e->setHorasExtra(horas);
			e->setCantidadBono(cantidadBono);
			lista->insertarFinal(e);
		}
	}
	archivo.close();
}



//reescribe el archivo completo con lo que hay en cada lista, para guardar no se pregunta el tipo o sea cada objeto responde por si 
//mismo gracias a los metodos virtuales que se emplean que son por ejemplo el getTipo getDatoPropio etc...


void ArchivoEmpleados::guardar(ListaEmpleados* lista) {
	ofstream archivo(nombreArchivo);      // por defecto borra y escribe de nuevo
	archivo << fixed << setprecision(2);  // evita la notación científica (1.5e+06)
	NodoEmpleado* actual = lista->getPrimero();
	while (actual != NULL) {
		Empleado* e = actual->getDato();
		archivo << e->getTipo() << endl
			<< e->getCedula() << endl
			<< e->getNombre() << endl
			<< e->getCodigoDepartamento() << endl
			<< e->getSalarioBase() << endl
			<< e->getHorasExtra() << endl
			<< e->getDatoPropio() << endl
			<< e->getCantidadBono() << endl;
		actual = actual->getSiguiente();
	}
	archivo.close();
}
