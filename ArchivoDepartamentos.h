#ifndef ARCHIVODEPARTAMENTOS_H
#define ARCHIVODEPARTAMENTOS_H
#include <fstream>
#include "AlmacenDepartamentos.h"

//Aca se declaran las variables que vamos a usar en el ArchivoDepartamentos.cpp y seguimos usando el principio de override


class ArchivoDepartamentos : public AlmacenDepartamentos {
private:
	string nombreArchivo;
	
public:
	ArchivoDepartamentos(string nombre);
	~ArchivoDepartamentos();
	
	void cargar(ListaDepartamentos* lista)  override;
	void guardar(ListaDepartamentos* lista) override;
};

#endif
