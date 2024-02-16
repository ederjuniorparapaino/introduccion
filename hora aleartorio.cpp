#include <iostream>
using namespace std;


typedef struct tiempo {
	int hora, minuto, segundo;
} tiempo;


int horaRand() {
	return rand() % 24; // Generar hora aleatoria entre 0 y 23
}

int msRand() {
	return rand() % 60; // Generar minuto o segundo aleatorio entre 0 y 59
}

void agregar(tiempo vt[], int TMA) {
	for (int i = 0; i < TMA; ++i) {
		vt[i].hora = horaRand(); // Generar hora aleatoria
		vt[i].minuto = msRand(); // Generar minuto aleatorio
		vt[i].segundo = msRand(); // Generar segundo aleatorio
	}
}

void imprimir(tiempo vt[], int TMA) {
	for (int i = 0; i < TMA; ++i) {
		cout << "Hora: " << vt[i].hora << ":" << vt[i].minuto << ":" << vt[i].segundo << endl;
	}
}

int main(int argc, char *argv[]) {
	const int TMA = 5;
	tiempo vt[TMA];
	
	
	agregar(vt, TMA); // Llamar a la función para agregar tiempos aleatorios
	
	imprimir(vt, TMA); // Llamar a la función para imprimir
	
	return 0;
}
