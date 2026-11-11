#include "CalculadoraSalario.h"
#include <cmath> // Para round()

// estos de aca son valores meramente de ejemplo basados en los de costa rica actualmente 
//claude me ayudo a buscar datos ejemplo parecidos a los actuales


const double HORAS_LABORALES_MES =    240;   // 30 días x 8 horas
const double RECARGO_HORA_EXTRA =     1.5;    // la hora extra se paga 50% más
const double PORCENTAJE_SALUD =       0.055;    // CCSS SEM: 5.50 %
const double PORCENTAJE_PENSIONES =   0.0433; // CCSS IVM: 4.33 %
const double PORCENTAJE_BANCO =       0.01;     // Banco Popular: 1 %



//constructor y destructor 
CalculadoraSalario::CalculadoraSalario() {
}

CalculadoraSalario::~CalculadoraSalario() {
}



//calcula el valor por la hora o sea divide el salario base de la persona por las horas laborales 

double CalculadoraSalario::calcularValorHora(Empleado* e) {
	return e->getSalarioBase() / HORAS_LABORALES_MES;
}



//aca se multiplican las horas extra, por el valor de la hora y el recargo de la hora 
double CalculadoraSalario::calcularMontoHorasExtra(Empleado* e) {
	return e->getHorasExtra() * calcularValorHora(e) * RECARGO_HORA_EXTRA;
}





// e->calcularBonificacion() es una llamada de POLIMORFISMO : se ejecuta
// la versión de Medico, Enfermero o Administrativo según el objeto real


double CalculadoraSalario::calcularSalarioBruto(Empleado* e) {
	return e->getSalarioBase() + redondear(calcularMontoHorasExtra(e)) + redondear(e->calcularBonificacion());
}



//salud
double CalculadoraSalario::calcularDeduccionSalud(double bruto) {
	return bruto * PORCENTAJE_SALUD;
}



//pensiones
double CalculadoraSalario::calcularDeduccionPensiones(double bruto) {
	return bruto * PORCENTAJE_PENSIONES;
}



//Deduccion del banco 
double CalculadoraSalario::calcularDeduccionBanco(double bruto) {
	return bruto * PORCENTAJE_BANCO;
}





//aca el dinero se maneja en centimos o sea se redondea a 2 decimales para que el comprobante de exactamente 
//lo mismo que antes y despues de guardarlos 
double CalculadoraSalario::redondear(double monto) {
	return round(monto * 100) / 100;
}




// aca se calcula todo el desglose y lo deja guardado en el comprobante



void CalculadoraSalario::llenarComprobante(ComprobantePago* c) {
	Empleado* e = c->getEmpleado();
	double extras = redondear(calcularMontoHorasExtra(e));
	double bono = redondear(e->calcularBonificacion());
	double bruto = calcularSalarioBruto(e);
	
	c->setIngresos(e->getHorasExtra(), e->getCantidadBono(), e->getSalarioBase(), extras, bono);
	c->setDeducciones(redondear(calcularDeduccionSalud(bruto)),
					  redondear(calcularDeduccionPensiones(bruto)),
					  redondear(calcularDeduccionBanco(bruto)));
}
