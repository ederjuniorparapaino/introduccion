#include <iostream>
using namespace std;

typedef struct tiempo {int hora, minuto, segundo;} tiempo;

void imprimir(tiempo vt[], int TMA) {
	for (int i = 0; i < TMA; ++i) {
		cout << "Hora " << vt[i].hora << ":" << vt[i].minuto << ":" << vt[i].segundo << endl;
	}
}

int main(int argc, char *argv[]) {
	const int TMA = 2;
	tiempo t1, vt[TMA];
	
	t1.hora = rand() % 24; // Generar hora aleatoria
	t1.minuto = rand() % 60; // Generar minuto aleatorio
	t1.segundo = rand() % 60; // Generar segundo aleatorio
	
	// Registro del array vt
	vt[0].hora = rand() % 24; // Generar hora aleatoria
	vt[0].minuto = rand() % 60; // Generar minuto aleatorio
	vt[0].segundo = rand() % 60; // Generar segundo aleatorio
	
	// Registro del array vt 2
	vt[1].hora = rand() % 24; // Generar hora aleatoria
	vt[1].minuto = rand() % 60; // Generar minuto aleatorio
	vt[1].segundo = rand() % 60; // Generar segundo aleatorio
	
	imprimir(vt, TMA); // Llamar a la función para imprimir
	
	//cout << "Hora aleatoria generada para t1: " << t1.hora << ":" << t1.minuto << ":" << t1.segundo << endl;
	
	return 0;
}
