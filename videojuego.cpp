#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;
// 2 ESTRUCTURAS PARA PERSONAS Y VIDEOS JUEGOS 
// LLENADO AUTOMATICO DE DATOS EJ. CONST INT TAM=?;
// IMPRESION DE LAS PERSONAS Y LOS VIDEOS JUEGOS QUE LE GUSTAN 
// LOS JUEGOS DEBEN TENER UN RAKING DE VALORACION
const int TAMJ = 3;

struct vjuego {
	string nombre;
	int ranking; // 1 al 10;
	bool tipo;   // offline y online.
	string des;
};

struct persona {
	string nombre;
	int id_persona;
	vjuego juegos[TAMJ];
};
//AL LLENAR NO DEBE EXISTIR REPETIDOS.
string nombtres[] = {"Juan Perez", "Maria Flor", "Pedro Vaca", "Juan Peralta"};
string vjuegos[] = {"Wow", "Age of Empire", "Dota", "Tetris", "Mario Bros"};

int randomico(int max) {
	return rand() % max;
}

void llenar(persona p[], int cant) {
	for (int i = 0; i < cant; ++i) {
		p[i].nombre = nombtres[i];
		p[i].id_persona = i + 1;
		for (int j = 0; j < TAMJ; ++j) {
			int indice;
			bool repetido;
			do {
				indice = randomico(5);
				repetido = false;
				for (int k = 0; k < j; ++k) {
					if (p[i].juegos[k].nombre == vjuegos[indice]) {
						repetido = true;
						break;
					}
				}
			} while (repetido);
			p[i].juegos[j].nombre = vjuegos[indice];
			p[i].juegos[j].ranking = randomico(10) + 1; // entre 1 y 10
			p[i].juegos[j].tipo = randomico(2);          // 0 o 1
			p[i].juegos[j].des = "Descripción del juego " + to_string(indice);
		}
	}
}

void imprimir(persona p[], int cant) {
	for (int i = 0; i < cant; ++i) {
		cout << "Nombre: " << p[i].nombre << endl;
		cout << "ID: " << p[i].id_persona << endl;
		cout << "Juegos:" << endl;
		for (int j = 0; j < TAMJ; ++j) {
			cout << "  - Nombre: " << p[i].juegos[j].nombre << endl;
			cout << "    Ranking: " << p[i].juegos[j].ranking << endl;
			cout << "    Tipo: " << (p[i].juegos[j].tipo ? "Online" : "Offline") << endl;
			cout << "    Descripción: " << p[i].juegos[j].des << endl;
		}
		cout << endl;
	}
}

void ranking(persona p[], int cant) {
	for (int i = 0; i < cant; ++i) {
		cout << "Nombre: " << p[i].nombre << endl;
		cout << "Juegos y su ranking: " << endl;
		for (int j = 0; j < TAMJ; ++j) {
			cout << p[i].juegos[j].nombre << ": " << p[i].juegos[j].ranking << endl;
		}
		cout << endl;
	}
}

void menu() {
	cout << "MENU" << endl;
	cout << "1) Llenado de personas" << endl; // 1) llenado de personas
	cout << "2) Impresion personas" << endl;  // 2) impresion personas
	cout << "3) Ranking de juegos por personas" << endl; // 3) ranking de juegos por personas
	cout << "0) Salir" << endl; // 0) salir
}

int main(int argc, char *argv[]) {
	const int TAMP = 4;
	persona arrPersona[TAMP];
	
	srand(time(NULL)); // Inicialización del generador de números aleatorios
	
	int opcion;
	
	do {
		menu();
		cout << "Ingrese una opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			llenar(arrPersona, TAMP);
			cout << "Datos de personas llenados." << endl;
			break;
		case 2:
			imprimir(arrPersona, TAMP);
			break;
		case 3:
			ranking(arrPersona, TAMP);
			break;
		case 0:
			cout << "Saliendo del programa..." << endl;
			break;
		default:
			cout << "Opción no válida. Intente de nuevo." << endl;
		}
	} while (opcion != 0);
	
	return 0;
}
