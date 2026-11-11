#ifndef ENFERMERO_H
#define ENFERMERO_H
#include "Empleado.h"


//Esto es una clase MODELO 
//Enfermero es un empleado y su bonificacion sale de cuantos turnos nocturnos hizo 

class Enfermero : public Empleado {
private:
	
	string area;
	int turnosNocturnos;
	
	
	
public:
	Enfermero(string ced, string nom, string codDep, double salario, string are);
	~Enfermero();
	
	string getTipo()                   override;
	string getDatoPropio()             override;
	string getNombreBono()             override;
	int getCantidadBono()              override;
	void setCantidadBono(int cantidad) override;
	double calcularBonificacion()      override;
	string toString()                  override;
};


#endif
