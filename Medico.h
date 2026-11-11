#ifndef MEDICO_H
#define MEDICO_H
#include "Empleado.h"


// esta es la capa de medico, medico es un empleado osea es una herencia publica y su bonificacion sale de la cantidad de guardias
//que hace al mes 
//el class Medif
class Medico : public Empleado {
private:
	string especialidad;
	int guardias;
	
	
public:
	Medico (string ced, string nom, string codDep, double salario, string esp) ;
	
	//destructor
	~Medico();
	
	
	
	//los set y get del medico 
	//los override es como una red de seguridad si nos equivocamos al dijitar el sistema nos avisa del error 
	
	string getTipo() override;
	
	string getDatoPropio() override;
	
	string getNombreBono() override;
	
	int getCantidadBono() override;
	
	void setCantidadBono(int cantidad) override;
	
	double calcularBonificacion() override;
	
	string toString() override;

};







#endif
