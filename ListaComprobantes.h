#ifndef LISTACOMPROBANTES_H
#define LISTACOMPROBANTES_H
#include "NodoComprobante.h"

//Es la estructura de datos aca declaramos las variables  y tambien 
//una lista de comprobantes planilla o sea es dueña de los comprobantes pero no los empleado ni los departamentos 
//a los que se apuntan sus punteros 


class ListaComprobantes {
private:
	NodoComprobante* primero;
	
public:
	ListaComprobantes();
	~ListaComprobantes();
	
	bool estaVacia();
	int contar();
	void insertarFinal              (ComprobantePago* c);
	ComprobantePago* buscar         (int numero);
	bool existeComprobante          (string cedula, string periodo);
	bool hayComprobantesDe          (string cedula);
	bool hayComprobantesEn          (string codigoDepartamento);
	int mayorNumero();
	NodoComprobante*                getPrimero();
	string toString();
};

#endif
