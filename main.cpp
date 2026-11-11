//ESTE ES EL SISTEMA DE PLANILLA HOSPITALARIA  PROYECTO 2 DE PROGRAMACION 1 
//main.cpp, aqui se arma por asi decirlo el programa y se crean los objetos concretos y se le pasa a inyectar a quienes lo necesitan
//al final se libera toda la memoria en orden inverso para limpiar el programa
//el main crea cada pieza, las conecta y arranca en el menu principal del hospital y al final se encarga de liberar la memoria 

//la mayoria de los comentarios los escribi yo con cuidado y salieron de mi
//claude me ayudo con la ortografia de los mismos para que no se fuera alguna palabra inentendible o mal

#include <iostream>
#include "ArchivoEmpleados.h"
#include "ArchivoDepartamentos.h"
#include "ArchivoPlanilla.h"
#include "CalculadoraSalario.h"
#include "SistemaPlanilla.h"
#include "Entrada.h"
#include "Menu.h"
#include <windows.h> // solo para las dos líneas de las tildes (le pregunte a Claude que usar y me dijo windows.h)

using namespace std;

int main() {
	//cambia la consola de windows a la tabla de caracteres 1252 o sea la misma esta guardando los archivos para que se vean y se puedan
	//escribir bien las tildes y las ñ 
	//porque si no aparecerian como caracteres indefinidos
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	
	
	
	//los punteros son del tipo abstractos pero apuntan a la clase concreta que trabaja con archivos txt (inversion de dependencias)
	AlmacenEmpleados*     almacenEmpleados =          new ArchivoEmpleados    ("empleados.txt");
	AlmacenDepartamentos* almacenDepartamentos =      new ArchivoDepartamentos("departamentos.txt");
	AlmacenPlanilla*      almacenPlanilla =           new ArchivoPlanilla     ("planilla.txt");
	CalculadoraSalario*   calculadora =               new CalculadoraSalario();
	
	
	
	// el sistema carga los 3 archivos nuevos al construir
	SistemaPlanilla* sistema = new SistemaPlanilla(almacenEmpleados, almacenDepartamentos,
												   almacenPlanilla, calculadora);
	Entrada* entrada = new Entrada();
	Menu* menu = new Menu(sistema, entrada);
	
	menu->iniciar();
	
	// aca se da la liberacion de la memoria o sea los que se usan a otros 
	delete menu;
	delete entrada;
	delete sistema;      // aca se borran las listas y todo lo que contienen 
	delete calculadora;
	delete almacenPlanilla;
	delete almacenDepartamentos;
	delete almacenEmpleados;
	return 0;
}
