#ifndef ENTRADA_H
#define ENTRADA_H
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

//aca se declaran los metodos que vamos a usar para pedir los datos correspondientes osea el texto, los decimales,periodo , si o no 
//y el pausar


class Entrada {
private:
	string leerLinea(string mensaje);
	string quitarEspacios(string texto);
	
	
	
	
public:
	Entrada();
	~Entrada();
	
	string leerTexto          (string mensaje);
	int leerEntero            (string mensaje, int minimo, int maximo);
	double leerDecimal        (string mensaje, double minimo, double maximo);
	string leerPeriodo        (string mensaje);
	bool leerSiNo             (string mensaje);
	void pausar();
};

#endif
