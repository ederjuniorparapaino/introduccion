#include <iostream>
using namespace std;
int vocales(char *pc)
{
	int contador=0;
	while(*pc!=
}

int main(int argc, char *argv[]) {
	char cadena[]="hola mundo";
	char *pc=cadena;
	//REALIZAR EL CONTENO DE LAS VOCALES DE LA CADENA POR MEDIO DEL PUNTERO
	int contador_vocales[5] = {0}; // Un arreglo para contar las vocales (a, e, i, o, u)
	
	while (*pc != '\0') {
		// Convertir el carácter a minúscula para simplificar la comparación
		char c = tolower(*pc);
		
		// Verificar si el carácter es una vocal y aumentar el contador correspondiente
		switch (c) {
		case 'a':
			contador_vocales[0]++;
			break;
		case 'e':
			contador_vocales[1]++;
			break;
		case 'i':
			contador_vocales[2]++;
			break;
		case 'o':
			contador_vocales[3]++;
			break;
		case 'u':
			contador_vocales[4]++;
			break;
		}
		
		// Mover el puntero al siguiente carácter en la cadena
		pc++;
	}
	
	//PASARLO A UN FUNCION EL PARAMETRO DEL PUNTERO
	void contarVocales(char *cadena, int *contador_vocales) {
		char *pc = cadena;
		
		while (*pc != '\0') {
			// Convertir el carácter a minúscula para simplificar la comparación
			char c = tolower(*pc);
			
			// Verificar si el carácter es una vocal y aumentar el contador correspondiente
			switch (c) {
			case 'a':
				contador_vocales[0]++;
				break;
			case 'e':
				contador_vocales[1]++;
				break;
			case 'i':
				contador_vocales[2]++;
				break;
			case 'o':
				contador_vocales[3]++;
				break;
			case 'u':
				contador_vocales[4]++;
				break;
			}
			
			// Mover el puntero al siguiente carácter en la cadena
			pc++;
		}
	}
	
	int main(int argc, char *argv[]) {
		char cadena[] = "hola mundo";
		int contador_vocales[5] = {0}; // Un arreglo para contar las vocales (a, e, i, o, u)
		
		contarVocales(cadena, contador_vocales);
		
		// Imprimir los resultados
		cout << "Conteo de vocales en la cadena \"" << cadena << "\":" << endl;
		cout << "A: " << contador_vocales[0] << endl;
		cout << "E: " << contador_vocales[1] << endl;
		cout << "I: " << contador_vocales[2] << endl;
		cout << "O: " << contador_vocales[3] << endl;
		cout << "U: " << contador_vocales[4] << endl;
		
	return 0;
}
