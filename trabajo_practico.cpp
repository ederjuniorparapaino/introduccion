#include <iostream>
#include <ctime>
using namespace std;
// 2 ESTRUCTURAS PARA PERSONAS Y VIDEOS JUEGOS 
// LLENADO AUTOMATICO DE DATOS EJ. CONST INT TAM=?;
// IMPRESION DE LAS PERSONAS Y LOS VIDEOS JUEGOS QUE LE GUSTAN 
// LOS JUEGOS DEBEN TENER UN RAKING DE VALORACION
const int TAMJ = 3;
const int MNOMBRE = 6;

struct vjuego {
	string nombre;
	int ranking; //1 al 10;
	bool tipo; // offline y  online.
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

bool repetido(string n, persona *p, int cant) {
	for (int i = 0; i < cant; ++i) {
		if (n.compare(p[i].nombre) == 0)
			return true;
	}
	return false;
}

void llenar(persona p[], int cant) {
	int index = 0;
	while (index < cant) {
		string nombre = nombtres[randomico(MNOMBRE)];
		if (!repetido(nombre, p, index)) {
			p[index].nombre = nombre;
			p[index].id_persona = index + 1;
			for (int i = 0; i < TAMJ; ++i) {
				vjuego juego;
				juego.nombre = vjuegos[randomico(5)];
				juego.ranking = randomico(10) + 1;
				juego.tipo = randomico(2);
				juego.des = "Descripción del juego";
				p[index].juegos[i] = juego;
			}
			index++;
		}
	}
}

void imprimir(persona p[], int cant) {
	for (int i = 0; i < cant; ++i) {
		cout << "Persona " << p[i].id_persona << ": " << p[i].nombre << endl;
		cout << "Juegos favoritos:" << endl;
		for (int j = 0; j < TAMJ; ++j) {
			cout << "  - " << p[i].juegos[j].nombre << " (Ranking: " << p[i].juegos[j].ranking << ")" << endl;
		}
		cout << endl;
	}
}

void ranking(persona p[], int cant) {
	for (int i = 0; i < cant; ++i) {
		cout << "Nombre: " << p[i].nombre << endl;
		vjuego juegoMasJugado = p[i].juegos[0];
		for (int j = 1; j < TAMJ; ++j) {
			if (p[i].juegos[j].ranking > juegoMasJugado.ranking) {
				juegoMasJugado = p[i].juegos[j];
			}
		}
		cout << "Juego más jugado: " << juegoMasJugado.nombre << " (Ranking: " << juegoMasJugado.ranking << ")" << endl;
		cout << endl;
	}
}

void menu() {
	cout << "MENU" << endl;
	cout << "1) Llenado de personas" << endl; // 1) llenado de personas
	cout << "2) Impresion personas" << endl; //2) impresion personas
	cout << "3) Ranking de juegos por personas" << endl;  // 3) ranking de juegos por personas
	cout << "0) Salir" << endl; // 0) salir
}

int main(int argc, char *argv[]) {
	const int TAMP = 4;
	persona personas[TAMP];
	int opcion;
	do {
		menu();
		cout << "Ingrese su opcion: ";
		cin >> opcion;
		switch (opcion) {
		case 1:
			llenar(personas, TAMP);
			break;
		case 2:
			imprimir(personas, TAMP);
			break;
		case 3:
			ranking(personas, TAMP);
			break;
		case 0:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opcion no valida. Intente de nuevo." << endl;
		}
	} while (opcion != 0);
	
	return 0;
}
