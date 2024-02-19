#include <iostream>
using namespace std;
struct strTiempo{
	int hora;
	int minuto;
	int segundo;
};
struct strFecha{
	int anio;
	int mes;
	int dia;
};
int randomica(int max){
	return rand()% max;//hora-24 minuto-60 segundo-60 dia-32 mes-13 anio-2000+rand(24)
}
void llenado(strTiempo t[], int cant){
	for (int i = 0; i < cant; ++i) {
		t[i].hora = randomica(24); // Generar hora aleatoria
		t[i].minuto = randomica(60); // Generar minuto aleatorio
		t[i].segundo = randomica(60); // Generar segundo aleatorio
	}
}
void llenado(strFecha af[], int cant){
	for(int i=0;i<cant;++i){
		af[i].anio=200+randomica(24);
		af[i].mes=randomica(12)+1;
		af[i].dia=randomica(31)+1;
	}
}
void imprimir(strTiempo, int cant) {
	for (int i = 0; i < cant; ++i) {
		cout << "Hora: " << vt[i].hora << ":" << vt[i].minuto << ":" << vt[i].segundo << endl;
	}
}
void imprimir(strFecha, int cant);
int main(int argc, char *argv[]) {
	const TAM=5;
	strTiempo t[TAM];
	strFecha f[TAM];
	//llenar el array de las estructuras
	//imprimir el larray
	return 0;
}

