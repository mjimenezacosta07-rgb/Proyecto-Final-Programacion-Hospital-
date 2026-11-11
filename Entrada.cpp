#include "Entrada.h"

Entrada::Entrada() {
}

Entrada::~Entrada() {
}
//Esta parte le pedi ayuda a claude para que me de una guia para que no se me pasara por alto ningun dato 
//ya que es una parte importante del sistema y no podia pasarse por alto un dato si no el sistema no iba a funcionar 
//o la persona podria poner algo que el sistema no puede guardar y dejar de funcionar.


//aca lee lo que se escribe en el usuario y no deja pasar datos que se pongan mal esto es importante, por ejemplo si 
//escribe abc donde va un numero, muestra error y vuelve a preguntar por el dato


//aca lee la linea 
string Entrada::leerLinea(string mensaje) {
	string linea = "";
	cout << mensaje;
	if (!getline(cin, linea)) {
		return "";
	}
	return linea;
}




// esta parte lo que hace es quitar los espacios del inicio y del final, ejemplo "  Ana  " queda "Ana", los de en medio no se tocan
//con un sistema simple que analiza el texto 

string Entrada::quitarEspacios(string texto) {
	while (texto.length() > 0 && texto[0] == ' ') {
		texto.erase(0, 1);
	}
	while (texto.length() > 0 && texto[texto.length() - 1] == ' ') {
		texto.erase(texto.length() - 1, 1);
	}
	return texto;
}



//esto es por si acaso la persona llega a dejar un dato vacio te dice que lo dejaste vacio y vuelve a preguntarlo 
string Entrada::leerTexto(string mensaje) {
	string texto = quitarEspacios(leerLinea(mensaje));
	while (texto == "" && cin) {
		cout << "Error: este dato no puede quedar vacio." << endl;
		texto = quitarEspacios(leerLinea(mensaje));
	}
	return texto;
}



//esta parte usa un stringstream para convertir el texto en un numero o sea 
//el sobrante detecta lo que queda despues del numero como en 12abc o 2.5 (sobra el .5) y en esos casos el dato se rechaza 
//ademas te da monitoreo de errores de digitacion por ejemplo los entero sin letras 
//ni decimales en caso de que los digiten y ademas te dice entre cuales valores debe de estar por si no se sabe entre cuales o se digita 
//uno de mas 

int Entrada::leerEntero(string mensaje, int minimo, int maximo) {
	bool valido = false;
	int numero = minimo;
	while (!valido && cin) {
		string linea = leerLinea(mensaje);
		stringstream conversor(linea);
		char sobrante;
		if (!(conversor >> numero) || (conversor >> sobrante)) {
			if (cin) {
				cout << "Error: digite un numero entero, sin letras ni decimales." << endl;
			}
			numero = minimo;
		} else if (numero < minimo || numero > maximo) {
			cout << "Error: el numero debe estar entre " << minimo << " y " << maximo << "." << endl;
		} else {
			valido = true;
		}
	}
	return numero;
}



//en caso de que digite hace casi lo mismo que la anterior o sea si se digita un numero valido y o sea los decimales 
//y el monto dice entre cuales debe de estar se usa una separada a la anterior para mayor orden 

double Entrada::leerDecimal(string mensaje, double minimo, double maximo) {
	bool valido = false;
	double numero = minimo;
	while (!valido && cin) {
		string linea = leerLinea(mensaje);
		stringstream conversor(linea);
		char sobrante;
		if (!(conversor >> numero) || (conversor >> sobrante)) {
			if (cin) {
				cout << "Error: digite un numero valido (use punto para los decimales)." << endl;
			}
			numero = minimo;
		} else if (numero < minimo || numero > maximo) {
			cout << "Error: el monto debe estar entre " << minimo << " y " << maximo << "." << endl;
		} else {
			valido = true;
		}
	}
	return numero;
}



// aca se cubre de que los periodos de edicion o sea entre cuales debe de estar cada fecha un ejemplo las fechas 
//estan conformadas por AAAA-MM y se completa por 2026-11 o sea se usa ese tipo y se da un ejemplo en caso que la persona
//utilice un formato incorrecto a la hora de ponerlo y se usa un sistema algo mas complejo para saber esto 

//la idea de esto me quede atrapado durante un rato claude me ayudo a estructurarlo ya que no entendia como hacerlo bien
string Entrada::leerPeriodo(string mensaje) {
	bool valido = false;
	string periodo = "";
	while (!valido && cin) {
		periodo = quitarEspacios(leerLinea(mensaje));
		bool formatoBien = periodo.length() == 7 && periodo[4] == '-';
		for (int i = 0; i < (int)periodo.length() && formatoBien; i++) {
			if (i != 4 && (periodo[i] < '0' || periodo[i] > '9')) {
				formatoBien = false;
			}
		}
		if (formatoBien) {
			int anio = stoi(periodo.substr(0, 4));
			int mes = stoi(periodo.substr(5, 2));
			if (anio >= 2000 && anio <= 2100 && mes >= 1 && mes <= 12) {
				valido = true;
			}
		}
		if (!valido && cin) {
			cout << "Error: escriba el periodo como AAAA-MM (por ejemplo 2026-11)." << endl;
		}
	}
	return periodo;
}



//aca se lee si hay un si o un no con S y N en caso de que no digita ninguno o el formato incorrecto 
//tira un error y le pide que vuelva a ponerlo 
bool Entrada::leerSiNo(string mensaje) {
	while (cin) {
		string respuesta = quitarEspacios(leerLinea(mensaje + " (S/N): "));
		if (respuesta == "S" || respuesta == "s") {
			return true;
		}
		if (respuesta == "N" || respuesta == "n") {
			return false;
		}
		if (cin) {
			cout << "Error: responda S o N." << endl;
		}
	}
	return false;
}


//aca se dice para que la persona pueda continuar con el programa luego de iniciar los datos 
void Entrada::pausar() {
	leerLinea("\nPresione Enter para continuar...");
}
