#include "Administrativo.h"

// Para sacar el valor de un día se divide el salario mensual entre 30
//y asi calculamos cuanto le damos de salario y ayuda a calcular el tiempo extra  
const int DIAS_DEL_MES = 30;



Administrativo :: Administrativo (string ced, string nom, string codDep, double salario, string ofi)
	: Empleado(ced, nom, codDep, salario) {
	oficina = ofi;
	feriadosTrabajados = 0;
}

 Administrativo :: ~Administrativo() {
}

string Administrativo::getTipo()                   { return "ADMINISTRATIVO"; }
string Administrativo::getDatoPropio()             { return oficina; }
string Administrativo::getNombreBono()             { return "feriados trabajados"; }
int Administrativo::getCantidadBono()              { return feriadosTrabajados; }
void Administrativo::setCantidadBono(int cantidad) { feriadosTrabajados = cantidad; }

// cada feriado trabajado se le paga con un dia de salario adicional 
// salarioBase es private en Empleado por eso usamos el get

double Administrativo :: calcularBonificacion() {
	double valorDia = getSalarioBase() / DIAS_DEL_MES;  //aca el get 
	return feriadosTrabajados * valorDia;
}

string Administrativo::toString() {
	stringstream s;
	s << "Tipo..................: Administrativo" << endl
		<< Empleado::toString()
		<< "Oficina.............: " << oficina << endl
		<< "Feriados trabajados.: " << feriadosTrabajados << endl;
	return s.str();
}
