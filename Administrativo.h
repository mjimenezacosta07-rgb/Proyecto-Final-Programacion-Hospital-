#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include "Empleado.h"

//Se calcula su aumento dependiendo de cuanto gana el estimado 
//cada feriado se paga un dia extra pero administrativo es un empleado mas 


class Administrativo : public Empleado {
private:
	string oficina;
	int feriadosTrabajados;
	
public:
	Administrativo(string ced, string nom, string codDep, double salario, string ofi);
	~Administrativo();
	
	string getTipo() override;
	string getDatoPropio() override;
	string getNombreBono() override;
	int getCantidadBono() override;
	void setCantidadBono(int cantidad) override;
	double calcularBonificacion() override;
	string toString() override;
};

#endif
