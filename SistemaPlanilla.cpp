#include "SistemaPlanilla.h"

//en esta parte Claude me ayudo a estructurarlos ya que era muchas cosas por cordinar y a veces se me escapaban algunas entonces 
//me fue de ayuda para ayudarme a cordinar mejor el proyecto y buscar errores en la escrituda del codigo y ponerlos bien 


//al empezar se crean las listas vacias y se llenan desde los armacenes, el orden importa: los comporbantes cse cargarn de ultimo 
//porque nesecitan encontrar a su empkeado y su departamento, no ttendria sentido pionerlo de primro ya que no tendria que buscar

//aca se programa estos metodos: agregar, modificar, eliminar, calcular la planilla y porcesar pagos 



SistemaPlanilla::SistemaPlanilla(AlmacenEmpleados* ae, AlmacenDepartamentos* ad,
								 AlmacenPlanilla* ap, CalculadoraSalario* calc) {
	almacenEmpleados = ae;
	almacenDepartamentos = ad;
	almacenPlanilla = ap;
	calculadora = calc;
	
	empleados =     new ListaEmpleados();
	departamentos = new ListaDepartamentos();
	comprobantes =  new ListaComprobantes();
	
	
	almacenDepartamentos->cargar(departamentos);
	almacenEmpleados->cargar(empleados);
	almacenPlanilla->cargar(comprobantes, empleados, departamentos);
}





//aca se destruyen las llineas en orden inverso osea primero los comporbantes estos los que apuntan a empleado y departamentos, y despues
//lo demas osea los almacenes y la calculadora no se borran aca eso es en susu propios lugares 
//y adems no se borran aca porque los crea el main cuando se ejecuta el codigo 


SistemaPlanilla::~SistemaPlanilla() {
	delete comprobantes;
	delete empleados;
	delete departamentos;
}





// aca permite que cada cambio se guarde automaticamente en los 3 archivos 


void SistemaPlanilla::guardarTodo() {
	almacenDepartamentos->guardar(departamentos);
	almacenEmpleados->guardar(empleados);
	almacenPlanilla->guardar(comprobantes);
}

//ACA SE VEN LOS DEPARTAMENTOS Y SUS PUESTOS 

Departamento* SistemaPlanilla::buscarDepartamento(string codigo) {
	return departamentos->buscar(codigo);
}




//aca se determina el departamento que queremos agregar y si este ya existia o no con if 
bool SistemaPlanilla::agregarDepartamento(string codigo, string nombre) {
	if (departamentos->buscar(codigo) != NULL) {
		return false; // si ya existiera un departamento con este codigo 
	}
	departamentos->insertarFinal(new Departamento(codigo, nombre));
	guardarTodo();
	return true;
}




//aca se ven los puestos y se depermina si existia o no con un if 
bool SistemaPlanilla::agregarPuesto(string codigoDep, string nombrePuesto, int plazas) {
	Departamento* d = departamentos->buscar(codigoDep);
	if (d == NULL) {
		return false;
	}
	if (!d->agregarPuesto(nombrePuesto, plazas)) {
		return false; // si el puesto ya existia 
	}
	guardarTodo();
	return true;
}





//aca se elimina el puesto, si no encuentra regresa que no se encontro 
bool SistemaPlanilla::eliminarPuesto(string codigoDep, string nombrePuesto) {
	Departamento* d = departamentos->buscar(codigoDep);
	if (d == NULL || !d->eliminarPuesto(nombrePuesto)) {
		return false;
	}
	guardarTodo();
	return true;
}




//es una condicion, un departamento solo se puede eliminar si nadie depende de el 
bool SistemaPlanilla::puedeEliminarDepartamento(string codigo) {
	return !empleados->hayEmpleadosEn(codigo) && !comprobantes->hayComprobantesEn(codigo);
}




//aca se elimina el departamento y de compureba si nadie depende de el en la parte anterior 
bool SistemaPlanilla::eliminarDepartamento(string codigo) {
	if (!puedeEliminarDepartamento(codigo)) {
		return false;
	}
	if (!departamentos->eliminar(codigo)) {
		return false;
	}
	guardarTodo();
	return true;
}






string SistemaPlanilla::listarDepartamentos() {
	return departamentos->toString();
}



bool SistemaPlanilla::hayDepartamentos() {
	return !departamentos->estaVacia();
}





//ESTA ES LA PARTE DE LOS EMPLEADOS 

Empleado* SistemaPlanilla::buscarEmpleado(string cedula) {
	return empleados->buscar(cedula);
}




//aca recibe un empleado con un puntero que puede ser cualquier tipo de empleado si devuelve flase, quien lo creo debe hacer
//el delete


bool SistemaPlanilla::agregarEmpleado(Empleado* e) {
	if (e == NULL) {
		return false;
	}
	if (empleados->buscar(e->getCedula()) != NULL) {
		return false; // en caso de tener una cedula repetida 
	}
	if (departamentos->buscar(e->getCodigoDepartamento()) == NULL) {
		return false; // en caso de que el departamento no exista 
	}
	empleados->insertarFinal(e);
	guardarTodo();
	return true;
}




bool SistemaPlanilla::modificarEmpleado(string cedula, string nombre, string codigoDep, double salario) {
	Empleado* e = empleados->buscar(cedula);
	if (e == NULL || departamentos->buscar(codigoDep) == NULL) {
		return false;
	}
	e->setNombre(nombre);
	e->setCodigoDepartamento(codigoDep);
	e->setSalarioBase(salario);
	guardarTodo();
	return true;
}

// aca se hacen las novedades osea lo que cambia cada mes con diferencias osea las horas extra y guardias/turnos/feriados 
bool SistemaPlanilla::registrarNovedades(string cedula, int horasExtra, int cantidadBono) {
	Empleado* e = empleados->buscar(cedula);
	if (e == NULL) {
		return false;
	}
	e->setHorasExtra(horasExtra);
	e->setCantidadBono(cantidadBono); //este es un metodo virtual osea cada tipo guarda lo suyo 
	guardarTodo();
	return true;
}




bool SistemaPlanilla::tieneComprobantes(string cedula) {
	return comprobantes->hayComprobantesDe(cedula);
}

//no se deja borrar a alguien con comprobantes osea esos comporbantes quedarian apuntando a memoria liberada osea se quedarian 
//en punteros colgantes 

bool SistemaPlanilla::eliminarEmpleado(string cedula) {
	if (comprobantes->hayComprobantesDe(cedula)) {
		return false;
	}
	if (!empleados->eliminar(cedula)) {
		return false;
	}
	guardarTodo();
	return true;
}



string SistemaPlanilla::listarEmpleados() {
	return empleados->toString();
}





// ACA SE HACE LA PLANILLA 

//se genera un comporbante por cada empleado que todavia no tenga alguno creado y en este periodo aqui se ve el polimorfismo
//osea se recorre la lista tratando a todos como un empkeado con punteros y no se pregunta el tipo eso de hace despues 

int SistemaPlanilla::calcularPlanilla(string periodo) {
	int creados = 0;
	NodoEmpleado* actual = empleados->getPrimero();
	while (actual != NULL) {
		Empleado* e = actual->getDato();
		if (!comprobantes->existeComprobante(e->getCedula(), periodo)) {
			Departamento* d = departamentos->buscar(e->getCodigoDepartamento());
			int numero = comprobantes->mayorNumero() + 1;
			ComprobantePago* c = new ComprobantePago(numero, periodo, e, d);
			calculadora->llenarComprobante(c);
			comprobantes->insertarFinal(c);
			// las novedades que ya fueron pagadas se borran y quedan en 0 para el proximo mes (es muy importante para no darle 
			//algo que no se hizo)
			e->setHorasExtra(0);
			e->setCantidadBono(0);
			creados++;
		}
		actual = actual->getSiguiente();
	}
	if (creados > 0) {
		guardarTodo();
	}
	return creados;
}




//sistema de busqueda en la planilla del comprobante 
ComprobantePago* SistemaPlanilla::buscarComprobante(int numero) {
	return comprobantes->buscar(numero);
}


//procesamiento del pago correspondiente 
bool SistemaPlanilla::procesarPago(int numero) {
	ComprobantePago* c = comprobantes->buscar(numero);
	if (c == NULL || c->estaPagado()) {
		return false;
	}
	c->setEstado("PAGADO");
	guardarTodo();
	return true;
}



//se procesan los pagos del peridoo de cada uno osea se procesan los apgos e indica pagado si ya se completo 
int SistemaPlanilla::procesarPagosPeriodo(string periodo) {
	int pagados = 0;
	NodoComprobante* actual = comprobantes->getPrimero();
	while (actual != NULL) {
		ComprobantePago* c = actual->getDato();
		if (c->getPeriodo() == periodo && !c->estaPagado()) {
			c->setEstado("PAGADO");
			pagados++;
		}
		actual = actual->getSiguiente();
	}
	if (pagados > 0) {
		guardarTodo();
	}
	return pagados;
}


//e hace una revisionde comprobantes en lista 
string SistemaPlanilla::listarComprobantes() {
	return comprobantes->toString();
}



// Aca se suma todos los montos de los comporbantes de los periodos 


string SistemaPlanilla::resumenPeriodo(string periodo) {
	int cantidad = 0, pendientes = 0;
	double totalBruto = 0, totalDeducciones = 0, totalNeto = 0;
	NodoComprobante* actual = comprobantes->getPrimero();
	while (actual != NULL) {
		ComprobantePago* c = actual->getDato();
		if (c->getPeriodo() == periodo) {
			cantidad++;
			totalBruto = totalBruto + c->getSalarioBruto();
			totalDeducciones = totalDeducciones + c->getTotalDeducciones();
			totalNeto = totalNeto + c->getSalarioNeto();
			if (!c->estaPagado()) {
				pendientes++;
			}
		}
		actual = actual->getSiguiente();
	}
	
	
	
	
	
	//la parte que se muestra si no hay comporbante y los resumenes de las planilla
	stringstream s;
	s << fixed << setprecision(2);
	if (cantidad == 0) {
		s << "No hay comprobantes en el periodo " << periodo << "." << endl;
	} else {
		s << "===== RESUMEN DE PLANILLA " << periodo << " ======" << endl
			<< "Comprobantes..........: " << cantidad << endl
			<< "Pendientes de pago....: " << pendientes << endl
			<< "Total bruto...........: " << totalBruto << endl
			<< "Total de deducciones..: " << totalDeducciones << endl
			<< "Total neto a pagar....: " << totalNeto << endl;
	}
	return s.str();
}
