#include <iostream>
using namespace std;
typedef struct tiempo{int hora, minuto, segundo;}tiempo;

void imprimir(tiempo vt[], int TMA) {
	for (int i = 0; i < TMA; ++i) {
		cout << "Hora:"<< vt[i].hora << ":" << vt[i].minuto << ":" << vt[i].segundo << endl;
	}
}

int main(int argc, char *argv[]) {
	const int TMA=2;
	tiempo t1, vt[TMA];
	t1.hora = 12;
	t1.minuto = 0;
	t1.segundo = 0;
	
	//registro de aarray vt
	vt[0].hora=13;
	vt[0].minuto=30;
	vt[0].segundo=10;
	
	//Registro de array vt 2
	vt[1].hora=23;
	vt[1].minuto=0;
	vt[1].segundo=10;
	
	imprimir(vt,TMA); //realizar funcion para imprimir
	//cout<<"Hora 0:"<<vt[0].hora<<":"<<vt[0].minuto<<":"<<vt[0].segundo<<endl;
	
	//cout<<"Hora es:"<<t1.hora<<":"<<t1.minuto<<":"<<t1.segundo<<endl;
	
	return 0;
}

