#ifndef CALCULADORASALARIO_H
#define CALCULADORASALARIO_H
#include "ComprobantePago.h"

//esta parte la calculadora.h es lo que por asi decirlo la calculadora deve de saber osea solo declara aca no se calcula nada todava 
//solos e conoce empleado en general pero no al medico enfermero o administrativo, esto se hace asi porque si se nos ocurre agregar un 
//nuevo tipo de empleado este archivo no se toca 


class CalculadoraSalario {
	
public:
	CalculadoraSalario();
	~CalculadoraSalario();
	
	
	
	
	
	double calcularValorHora          (Empleado* e);
	double calcularMontoHorasExtra    (Empleado* e);
	double calcularSalarioBruto       (Empleado* e);
	double calcularDeduccionSalud     (double bruto);
	double calcularDeduccionPensiones (double bruto);
	double calcularDeduccionBanco     (double bruto);
	double redondear                  (double monto);
	void llenarComprobante            (ComprobantePago* c);
};

#endif
