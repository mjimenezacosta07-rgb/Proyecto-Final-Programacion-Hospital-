#include "Menu.h"
//El codigo mas largo y mas importante del porgrama, aca se toiman toods los datos del usuario y se regresan los datos especificos
//para cada consulta, es importante y muy indispensable cubrir cada hueco para que la persona no pueda dijitar algo mal o se le devuelva
//en caso de que dijite algo incorrecto
//que a la hora de entrar datos es bastante comun 
// y ademas se utiliza a la ENTRADA.cpp para que esta misma devuelva en caso de dijitar algo mal se le llama varias veces ya que las de la 
//entrada se usan en varias partes, se crearon varias con doble uso osea varios punteros porque hay varias ocaciones que se ingrean 
//mismos datos entonces hay que llamarlas varias veces un ejemplo si dijita mal la cedula en empleaods  y en departamento llama a la misma 
//funcion que comprueba la cedula y le muestra error 


//aca se utilizo GUIA de CLAUDE porque el nivel de cuidado que hbia que tneer en esta parte para cubrir todas las posibilidades 
//de esta parte ya que es bastante importante, sirvio de guia en la mayoria de esta parte especialmenmte por su dificultal al intentar conectar 
//cada punto del programa sin dejar algo colgando o sin utilizar, o que no haya un desbordamiento por no cuidar
//un posible error de escritura de las personas que lleguen 
//a utilizar el programa, fue de importante ayuda en esta parte mas que en ningun otra 


//Aca se hacen unos montos maximos razonables que puede escribir el usuario, son de guia 
const double SALARIO_MAXIMO =   50000000;
const int MAXIMO_HORAS_EXTRA =  200;
const int MAXIMO_BONOS =        31;



Menu::Menu(SistemaPlanilla* s, Entrada* e) {
	sistema = s;
	entrada = e;
}



//aca no se borra nada el sistema y la entrada los crea por asociacion el main 
Menu::~Menu() {
}







// MENU PRINCIPAL=====================
//se utiliza un sistema de switch simple con el wile para salir y bueno es un sistema switch con opciones 
void Menu::iniciar() {
	int opcion;
	do {
		cout << endl
			<< "=========================================" << endl
			<< "   SISTEMA DE PLANILLA HOSPITALARIA" << endl
			<< "========================================" << endl
			<< "1. Departamentos y puestos" << endl
			<< "2. Empleados" << endl
			<< "3. Planilla y pagos" << endl
			<< "0. Salir" << endl;
		opcion = entrada->leerEntero("Opción: ", 0, 3);
		switch (opcion) {
		case 1: menuDepartamentos(); break;
		case 2: menuEmpleados(); break;
		case 3: menuPlanilla(); break;
		case 0: cout << "Datos guardados. ¡Hasta luego!" << endl; break;
		}
	} while (opcion != 0);
}


// PARTE DE LOS DEPARTAMENTOS===============================
//switch con opciones para los departamentos 
void Menu::menuDepartamentos() {
	int opcion;
	do {
		cout << endl << "------ DEPARTAMENTOS Y PUESTOS ------" << endl
			<< "1. Agregar departamento" << endl
			<< "2. Agregar puesto a un departamento" << endl
			<< "3. Eliminar puesto de un departamento" << endl
			<< "4. Listar departamentos" << endl
			<< "5. Eliminar departamento" << endl
			<< "0. Volver" << endl;
		opcion = entrada->leerEntero("Opción: ", 0, 5);
		switch (opcion) {
		case 1: agregarDepartamento(); break;
		case 2: agregarPuesto(); break;
		case 3: eliminarPuesto(); break;
		case 4: cout << endl << sistema->listarDepartamentos(); entrada->pausar(); break;
		case 5: eliminarDepartamento(); break;
		}
	} while (opcion != 0);
}






//en caso de que ya exista el departamento da error y vuelve al menu 
//si lo agrega bien le dice que se agrego correctamente 
void Menu::agregarDepartamento() {
	string codigo = entrada->leerTexto("Código del departamento (ej. D04): ");
	if (sistema->buscarDepartamento(codigo) != NULL) {
		cout << "Error: ya existe un departamento con ese código." << endl;
		return;
	}
	string nombre = entrada->leerTexto("Nombre del departamento: ");
	if (sistema->agregarDepartamento(codigo, nombre)) {
		cout << "Departamento agregado." << endl;
	}
}




//es el menu de agregar puesto aca le dice ejemplo si el comete error al escribir le dice que no existe 
//luego de eso le rpegunta nombre del puesto, la cantidad de plazas, y le dice donde fue agregado 

//en caso de error al preguntarle cual agregar se le tira un mensaje de error 
void Menu::agregarPuesto() {
	cout << endl << sistema->listarDepartamentos();
	string codigo = entrada->leerTexto("Código del departamento: ");
	Departamento* d = sistema->buscarDepartamento(codigo);
	if (d == NULL) {
		cout << "Error: no existe ese departamento." << endl;
		return;
	}
	string nombre = entrada->leerTexto("Nombre del puesto: ");
	int plazas = entrada->leerEntero("Cantidad de plazas: ", 1, 500);
	if (sistema->agregarPuesto(codigo, nombre, plazas)) {
		cout << "Puesto agregado a " << d->getNombre() << "." << endl;
	} else {
		cout << "Error: ese puesto ya existe en el departamento." << endl;
	}
}




//menu para eliminar un puesto aca se pide el codigo del departamento 
//si no existe tira error  luego pide el nombre extacto del puesto para eliminar, esto se relaciona con el sistema de antes
//si el puesto no existe te lo dice, aca no se revisa si tiene personas porque los empleados no guardan su puesto 

void Menu::eliminarPuesto() {
	cout << endl << sistema->listarDepartamentos();
	string codigo = entrada->leerTexto("Codigo del departamento: ");
	if (sistema->buscarDepartamento(codigo) == NULL) {
		cout << "Error: no existe ese departamento." << endl;
		return;
	}
	string nombre = entrada->leerTexto("Nombre exacto del puesto: ");
	if (sistema->eliminarPuesto(codigo, nombre)) {
		cout << "Puesto eliminado." << endl;
	} else {
		cout << "Error: ese puesto no existe en el departamento." << endl;
	}
}


//para eliminar un departamento aca es lo mismo que con puesto nadamas que para eliminar uno tiene que 
//asagurarse que no haya ningun empleado en el o un comporbante en el obvio porque 
// un comporbante que tiene datos importantes no podemos eliminarlo a la ligera 
//en el si no lo hay se elimina, ademas denuevo la misma logica, pide el coodigo del Departamento
//a eliminar su lo dijita mal le dice que no existe y ademas le pregunta que si quiere eliminarlo de verdad ya que 
//es importante y para asegurarse que no este cometiendo un error al querer eliminar algo 
void Menu::eliminarDepartamento() {
	string codigo = entrada->leerTexto("Código del departamento a eliminar: ");
	if (sistema->buscarDepartamento(codigo) == NULL) {
		cout << "Error: no existe ese departamento." << endl;
		return;
	}
	if (!sistema->puedeEliminarDepartamento(codigo)) {
		cout << "No se puede eliminar: tiene empleados o comprobantes registrados." << endl;
		return;
	}
	if (entrada->leerSiNo("¿Seguro que desea eliminarlo con todos sus puestos?")) {
		sistema->eliminarDepartamento(codigo);
		cout << "Departamento eliminado." << endl;
	}
}




//ACA SE HACE EL MENU PARA LOS EMPLEADOS==========================

//se hace un switch como los anteriores para los empleados y sus distintas funciones 
//que podemos checar 
void Menu::menuEmpleados() {
	int opcion;
	do {
		cout << endl << "------------- EMPLEADOS -------------" << endl
			<< "1. Registrar empleado" << endl
			<< "2. Consultar empleado" << endl
			<< "3. Modificar datos de un empleado" << endl
			<< "4. Registrar horas extra y bonos del mes" << endl
			<< "5. Eliminar empleado" << endl
			<< "6. Listar empleados" << endl
			<< "0. Volver" << endl;
		opcion = entrada->leerEntero("Opción: ", 0, 6);
		switch (opcion) {
		case 1: registrarEmpleado();  break;
		case 2: consultarEmpleado();  break;
		case 3: modificarEmpleado();  break;
		case 4: registrarNovedades(); break;
		case 5: eliminarEmpleado();   break;
		case 6: cout << endl << sistema->listarEmpleados(); entrada->pausar(); break;
		}
	} while (opcion != 0);
}



// aqui se decide que tipo de objeto se va a crear osea se guarda en un empleado con punteros hacia su clase base y desde ahi
//el sistema lo tarta igual 



//menu de registrra emplkeado con sus distintos casos y tipos de empleado al regustrarse 
void Menu::registrarEmpleado() {
	if (!sistema->hayDepartamentos()) {
		cout << "Primero debe registrar al menos un departamento." << endl;
		return;
	}
	cout << "Tipo de empleado: 1. Médico  2. Enfermero  3. Administrativo" << endl;
	int tipo = entrada->leerEntero("Tipo: ", 1, 3);
	
	//solicitud de cedula y si hay una registrada y si ya hay una
	string cedula = entrada->leerTexto("Cédula: ");
	if (sistema->buscarEmpleado(cedula) != NULL) {
		cout << "Error: ya existe un empleado con esa cédula." << endl;
		return;
	}
	//se pide el nombre y el codigo de departaento y si se dijita un departamento que no existe tira error 
	string nombre = entrada->leerTexto("Nombre completo: ");
	cout << endl << sistema->listarDepartamentos();
	string codigo = entrada->leerTexto("Código del departamento: ");
	if (sistema->buscarDepartamento(codigo) == NULL) {
		cout << "Error: no existe ese departamento." << endl;
		return;
	}
	//le dice el salario base que tiene 
	double salario = entrada->leerDecimal("Salario base mensual: ", 1, SALARIO_MAXIMO);
	
	
	
	//en caso de crear un empleado nuevo se hace un switch con sus distintas razones a registrar 
	Empleado* nuevo = NULL;
	switch (tipo) {
	case 1:
		nuevo = new Medico(cedula, nombre, codigo, salario, entrada->leerTexto("Especialidad: "));
		break;
	case 2:
		nuevo = new Enfermero(cedula, nombre, codigo, salario, entrada->leerTexto("Área: "));
		break;
	case 3:
		nuevo = new Administrativo(cedula, nombre, codigo, salario, entrada->leerTexto("Oficina: "));
		break;
	}
	
	//al queerr registrar un empleado nuevo y en caso de que falle al registrarlo te lo dice 
	if (sistema->agregarEmpleado(nuevo)) {
		cout << "Empleado registrado." << endl;
	} else {
		cout << "Error: no se pudo registrar el empleado." << endl;
		delete nuevo; // como no se agregoi a la lista se libera aca 
	}
}

//en caso de querer consultar un empleado se pide la cedula, si no existe te lo dice 
void Menu::consultarEmpleado() {
	string cedula = entrada->leerTexto("Cédula: ");
	Empleado* e = sistema->buscarEmpleado(cedula);
	if (e == NULL) {
		cout << "No existe un empleado con esa cédula." << endl;
	} else {
		cout << endl << e->toString();
	}
	entrada->pausar();
}



//en caso de querer modificar a un empleado se pide la cedula del empleado, en caso que no exista te lo dice y vuelve a pedir en menu
//luego te dice que dijite los datos nuevos en caso de querere modificarlo y agregar la cedula bien,
//te pide que dijite los datos nuevos como el nombre completo,
//el codigo del departamento y en caso de dijitarlos mal el departamento te dice que no existe ese departamento, y no hace ningun cambio
 
void Menu::modificarEmpleado() {
	string cedula = entrada->leerTexto("Cedula del empleado: ");
	Empleado* e = sistema->buscarEmpleado(cedula);
	if (e == NULL) {
		cout << "No existe un empleado con esa cédula." << endl;
		return;
	}
	cout << endl << e->toString() << endl << "Digite los datos nuevos:" << endl;
	string nombre = entrada->leerTexto("Nombre completo: ");
	cout << endl << sistema->listarDepartamentos();
	string codigo = entrada->leerTexto("Código del departamento: ");
	if (sistema->buscarDepartamento(codigo) == NULL) {
		cout << "Error: no existe ese departamento. No se hicieron cambios." << endl;
		return;
	}
	//le dice el salario base del nuevo empleado y le dice que los datos fueron actualizados 
	double salario = entrada->leerDecimal("Salario base mensual: ", 1, SALARIO_MAXIMO);
	if (sistema->modificarEmpleado(cedula, nombre, codigo, salario)) {
		cout << "Datos actualizados." << endl;
	}
}


//en casoi de querer registrar alguna hora erxtra o alguna novedad se entra aca, primero pide la cedula
//si la cedula es correcta pasa y si no tira un error y lo devuelve al menu para que la ingrese denuevo 

void Menu::registrarNovedades() {
	string cedula = entrada->leerTexto("Cédula del empleado: ");
	Empleado* e = sistema->buscarEmpleado(cedula);
	if (e == NULL) {
		cout << "No existe un empleado con esa cédula." << endl;
		return;
	}
	cout << "Empleado: " << e->getNombre() << " (" << e->getTipo() << ")" << endl;
	int horas = entrada->leerEntero("Horas extra del mes: ", 0, MAXIMO_HORAS_EXTRA);
	//aca el getnombrebono() es virtual osea pregunta las guardias los turnos nocturnos o los feriados de la persona sin usar if
	
	int cantidad = entrada->leerEntero("Cantidad de " + e->getNombreBono() + ": ", 0, MAXIMO_BONOS);
	sistema->registrarNovedades(cedula, horas, cantidad);
	cout << "Novedades registradas." << endl;
}//se registran las novedades



//en caso de querer eliminar un empleado primero se pregunta la cedula si es correcta pasa, si no te rebota error 
void Menu::eliminarEmpleado() {
	string cedula = entrada->leerTexto("Cedula del empleado a eliminar: ");
	Empleado* e = sistema->buscarEmpleado(cedula);
	if (e == NULL) {
		cout << "No existe un empleado con esa cedula." << endl;
		return;
	}//si la persona tiene algun comporbante de pago, pendiente o pagado, te lo dice y no deja eliminarlo 
	if (sistema->tieneComprobantes(cedula)) {
		cout << "No se puede eliminar: tiene comprobantes de pago en la planilla." << endl;
		return;
	}//luego si no tiene comprobantes y esta avacable te pregunta de crdad si quieres eliminarlo o es un error y te muestra la cedula del 
	//que quieres eliminar, si todo es correcto se elimina correctamente 
	if (entrada->leerSiNo("¿Seguro que desea eliminar a " + e->getNombre() + "?")) {
		sistema->eliminarEmpleado(cedula);
		cout << "Empleado eliminado." << endl;
	}
}

//ACA SE HACEN LAS PLANILLAS=========================

//switch para las planillas calcular periodos de planillas comprobantes listas de comporbantes pagos porcesar pagos
//resumen de periodo 
void Menu::menuPlanilla() {
	int opcion;
	do {
		cout << endl << "--------- PLANILLA Y PAGOS ---------" << endl
			<< "1. Calcular planilla de un periodo" << endl
			<< "2. Ver comprobante (desglose)" << endl
			<< "3. Listar comprobantes" << endl
			<< "4. Procesar pago de un comprobante" << endl
			<< "5. Procesar todos los pagos de un periodo" << endl
			<< "6. Resumen de un periodo" << endl
			<< "0. Volver" << endl;
		opcion = entrada->leerEntero("Opción: ", 0, 6);
		switch (opcion) {
		case 1: calcularPlanilla();  break;
		case 2: verComprobante();    break;
		case 3: cout << endl << sistema->listarComprobantes(); entrada->pausar(); break;
		case 4: procesarPago();      break;
		case 5: procesarPagosPeriodo(); break;
		case 6: resumenPeriodo();   break;
		}
	} while (opcion != 0);
}


//aca se calcula la planilla por periodo usando la fecha, compueba si se puede generar o si todos ya tienenn tienen generados 
//te dice los comporbantes y si se genera correctamente dice para quien se genera y para que periodo se aplico 

void Menu::calcularPlanilla() {
	string periodo = entrada->leerPeriodo("Periodo (AAAA-MM): ");
	int creados = sistema->calcularPlanilla(periodo);
	if (creados == 0) {
		cout << "No se generaron comprobantes: no hay empleados o todos ya tienen "
			<< "comprobante en " << periodo << "." << endl;
	} else {
		cout << "Se generaron " << creados << " comprobantes para " << periodo << "." << endl;
	}
}

//aca se puede ver los comporbantes y los numeros de comporbantes correspondientes para cada persona osea se le pide el numero
//del comprobante si la eprsona es correcta te lo dice y si ingresa dato erroneo te tira que no existe 

void Menu::verComprobante() {
	int numero = entrada->leerEntero("Numero de comprobante: ", 1, 1000000);
	ComprobantePago* c = sistema->buscarComprobante(numero);
	if (c == NULL) {
		cout << "No existe ese comprobante." << endl;
	} else {
		cout << endl << c->toString();
	}
	entrada->pausar();
}


//aca se porcesa el pago por el numero del comprobante y lo que hya que pagar, en caso de ingresra un dato erroneo te lo dice y vuelve a intentar
//en caso de que ya este pagado te lo dice y si no lo estaba te procesa el pago y te dice pago procesdado cuando ya se completa

void Menu::procesarPago() {
	int numero = entrada->leerEntero("Numero de comprobante a pagar: ", 1, 1000000);
	ComprobantePago* c = sistema->buscarComprobante(numero);
	if (c == NULL) {
		cout << "No existe ese comprobante." << endl;
	} else if (c->estaPagado()) {
		cout << "Ese comprobante ya estaba pagado." << endl;
	} else if (sistema->procesarPago(numero)) {
		cout << "Pago procesado." << endl;
	}
}

//aca se procesan los pagos por periodo y te dice los que ya se procesaron segun su fecha y los pagos que se efectuaron 
void Menu::procesarPagosPeriodo() {
	string periodo = entrada->leerPeriodo("Periodo (AAAA-MM): ");
	int pagados = sistema->procesarPagosPeriodo(periodo);
	cout << "Se procesaron " << pagados << " pagos." << endl;
}
//el remuen de los pagos del periodo 
void Menu::resumenPeriodo() {
	string periodo = entrada->leerPeriodo("Periodo (AAAA-MM): ");
	cout << endl << sistema->resumenPeriodo(periodo);
	entrada->pausar();
}
