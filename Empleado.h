#ifndef EMPLEADO_H
#define EMPLEADO_H
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;


//Empleado es abstracto ya que tiene metodos virtuales puros o sea = 0 por eso no se le puede 
//hacer un new empleado 



class Empleado {
private:
	string cedula;
	string nombre;
	string codigoDepartamento;  
	//es la asociacion con departamento por medio de codigo
	double salarioBase;
	//salario mensual sin extras
	int horasExtra;
	//horas extra trabajadas en un mes
	
	
	
public:
	//el constructor
	Empleado (string ced, string nom, string codDep, double salario);
	//virtual, al hacer el delete a un empleado con el * se ejecuta primero el destructor de la clase hija y luego este 
	
	virtual ~Empleado();
	
	
	
	
	string getCedula();
	string getNombre();
	string getCodigoDepartamento();
	double getSalarioBase();
	int getHorasExtra();
	
	
	
	
	
	void setNombre(string nom);
	void setCodigoDepartamento(string codDep);
	void setSalarioBase(double salario);
	void setHorasExtra(int horas);
	
	
	
	//aca van los metodos de cada clase o sea lo que hace cada empleado a su manera (el polimorfismo)
	
	virtual string getTipo() = 0;    //MEDICO ENFERMERO Y ADMINISTRATIVO
	virtual string getDatoPropio() = 0;     // especialidad, su area o oficina
	virtual string getNombreBono() = 0;     //guardias o los turnos nocturnos 
	virtual int getCantidadBono() = 0;     // cuantas guardias, turnos etc tiene la persona 
	virtual void setCantidadBono(int cantidad) = 0;   //lo de un bono 
	virtual double calcularBonificacion() = 0;   
	
	
	
	virtual string toString();
	
	
	
};
#endif
