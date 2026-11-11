#ifndef PUESTO_H
#define PUESTO_H
#include <string>
#include <sstream>
using namespace std;

// un puesto por ejemplo el de medico de emergencias y 4 plazas mas solo eciste en una parte de la composicion 

class Puesto {
private:
	string nombre;
	int plazas;
	
public:
	Puesto(string nom, int pla);
	~Puesto();
	
	string getNombre();
	int getPlazas();
	void setPlazas(int pla);
	string toString();
};

#endif
