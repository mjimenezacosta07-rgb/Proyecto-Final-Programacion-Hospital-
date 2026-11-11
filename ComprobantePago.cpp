#include "ComprobantePago.h"
//en esta parte empeieza todos los montos en 0 y guardan los que le pasan osea calcula en bruto, deduccion y el neto y arma el recibo completo
//con todo lo declarado anteriormente en el comprobantePago.h aca se hacen los calculos y arma el comprobante de la persona 
// y su destructor va vacio porque el empleado no va en el osea esto es el fenomeno de agregacion 


ComprobantePago::ComprobantePago(int num, string per, Empleado* emp, Departamento* dep) {
	numero =          num;
	periodo =         per;
	empleado =        emp;        // solo se guarda la dirección: no se hace new
	departamento =    dep;
	horasExtra =      0;
	cantidadBono =    0;
	salarioBase =     0;
	montoHorasExtra = 0;
	bonificacion =    0;
	deduccionSalud =  0;
	deduccionPensiones = 0;
	deduccionBanco =  0;
	estado = "PENDIENTE";
}

// NO hay un delete el empleado ni departamentos esto es una diferencia de la agregacion y la composicion 

ComprobantePago::~ComprobantePago() {
}

int ComprobantePago::getNumero()                     { return numero; }
string ComprobantePago::getPeriodo()                 { return periodo; }
Empleado* ComprobantePago::getEmpleado()             { return empleado; }
Departamento* ComprobantePago::getDepartamento()     { return departamento; }
int ComprobantePago   ::getHorasExtra()              { return horasExtra; }
int ComprobantePago   ::getCantidadBono()            { return cantidadBono; }
double ComprobantePago::getSalarioBase()             { return salarioBase; }
double ComprobantePago::getMontoHorasExtra()         { return montoHorasExtra; }
double ComprobantePago::getBonificacion()            { return bonificacion; }
double ComprobantePago::getDeduccionSalud()          { return deduccionSalud; }
double ComprobantePago::getDeduccionPensiones()      { return deduccionPensiones; }
double ComprobantePago::getDeduccionBanco()          { return deduccionBanco; }
string ComprobantePago::getEstado()                  { return estado; }




void ComprobantePago::setIngresos(int horas, int cantBono, double base, double extras, double bono) {
	horasExtra = horas;
	cantidadBono = cantBono;
	salarioBase = base;
	montoHorasExtra = extras;
	bonificacion = bono;
}





void ComprobantePago::setDeducciones(double salud, double pensiones, double banco) {
	deduccionSalud = salud;
	deduccionPensiones = pensiones;
	deduccionBanco = banco;
}




void ComprobantePago::setEstado(string est) { estado = est; }



//aca se da el salario en bruto osea al salario base se le suman las horas extra y la bonificacion 
double ComprobantePago::getSalarioBruto() {
	return salarioBase + montoHorasExtra + bonificacion;
}




// aca se hace la deduccion de salud mas las pensiones y se le suman lo del Banco Popular  para rebajarles 
double ComprobantePago::getTotalDeducciones() {
	return deduccionSalud + deduccionPensiones + deduccionBanco;
}




// aca al salario neto se le bajan las deducciones 
double ComprobantePago::getSalarioNeto() {
	return getSalarioBruto() - getTotalDeducciones();
}




//solo responde true si el estado es PAGADO y false si no, no paga nada; lo que se le entrega al empleado es el salario neto 
bool ComprobantePago::estaPagado() {
	return estado == "PAGADO";
}




string ComprobantePago::toString() {
	stringstream s;
	s << fixed << setprecision(2);
	s << "========= COMPROBANTE DE PAGO #"          << numero << " ==========" << endl
		<< "Periodo...................: "          << periodo << endl
		<< "Empleado...................: "         << empleado->getNombre()
		<< " (" << empleado->getCedula()           << ")" << endl
		<< "Tipo......................: "          << empleado->getTipo() << endl;
	
	
	//aca se muestra el departamento existe si existe se muestra en cual esta 
	if (departamento != NULL) {
		s << "Departamento................: "       << departamento->getCodigo()
			<< " - " << departamento->getNombre()   << endl;
	}
	
	
	//se muestran los ingresos y las deducciones que se les dan al usuario 
	s << "------------- INGRESOS --------------"    << endl
		<< "Salario base................: " << salarioBase << endl
		<< "Horas extra (" << horasExtra << ")...........: " << montoHorasExtra << endl
		<< "Bonificacion (" << cantidadBono << " " << empleado->getNombreBono() << "): "
		<< bonificacion << endl
		<< "SALARIO BRUTO...............: " << getSalarioBruto() << endl
		<< "----------- DEDUCCIONES DE LEY --------" << endl
		<< "CCSS Salud............: " << deduccionSalud << endl
		<< "CCSS Pensiones ........: " << deduccionPensiones << endl
		<< "Banco Popular...............: " << deduccionBanco << endl
		<< "Total de deducciones........: " << getTotalDeducciones() << endl
		<< "======================================" << endl
		<< "SALARIO NETO A PAGAR........: " << getSalarioNeto() << endl
		<< "Estado......................: " << estado << endl;
	return s.str();
}


//por ultimo se da un resumen de los numeros del salario 
string ComprobantePago::resumen() {
	stringstream s;
	s << fixed << setprecision(2);
	s << "#" << numero << " - " << periodo << " - " << empleado->getCedula()
		<< " " << empleado->getNombre() << "  Neto: " << getSalarioNeto()
		<< " - " << estado << endl;
	return s.str();
}
