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



void funcion(int n){
	cout<<"Funcion INTEGER"<<endl;
}
void funcion(int n, int m){//no utilizar parametros por defectos
	cout<<"Funcion 2 PARAMETROS"<<endl;
}	
void funcion(double n){//CAMBIAR A OTRO TIPO DE DATO
	cout<<"Funcion DOUBLE"<<endl;
}	
void funcion(char c){
	cout<<"Funcion CHAR"<<endl;
}	
void funcion(){
	cout<<"Hola mundo"<<endl;
}
void funcion(strTiempo tt){
	cout<<"la hora es:"<<tt.hora<<":"<<tt.minuto<<":"<<tt.segundo<<endl;
}
void funcion(strFecha tt){
	cout<<"la fecha es:"<<tt.anio<<"/"<<tt.mes<<"/"<<tt.dia<<endl;
}	
int main(int argc, char *argv[]) {
	funcion();
	funcion(15);
	funcion(11.5);
	funcion('h');
	funcion(12,7);
	strTiempo t;
	strFecha f;
	t.hora=10; t.minuto=35; t.segundo=0;
	f.anio=2024; f.mes=2; f.dia=19;
	funcion(t);
	funcion(f);
	return 0;
}

