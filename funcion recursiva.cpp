#include <iostream>

using namespace std;

void imprimir(int *n, int cant)
{
	for(int i=0;i<cant;++i)
		cout<<i<<"-"<<n[i]<<endl;
}
void imprec(int *n, int cant)
{
	if(cant>0)
	{
		imprec(n,cant-1);
		cout<<cant<<"-"<<n[cant-1];
	}
}
// FUNCION BUSQUEDA
void busquedaRecursiva(int *n, int cant, int elemento, bool &encontrado, int indice = 0)
{
	if(indice >= cant)
		return;
	if(n[indice] == elemento)
	{
		encontrado = true;
		return;
	}
	busquedaRecursiva(n, cant, elemento, encontrado, indice + 1);
}

// FUNCION MAYOR
void mayor(int *n, int cant, int &m)
{
	if(cant>0)
	{
		if(n[cant-1]>m)
			m=n[cant=1];
		mayor(n,cant-1,m);
		
	}
}
int main(int argc, char *argv[]) {
	const int TAM=7;
	int m=0;
	int numeros[]={3,5,2,1,7,4};
	cout<<"IMPRESION BUCLE"<<endl;
	imprimir(numeros, TAM);
	cout<<"IMPRESION RECURSIVA"<<endl;
	imprec(numeros,TAM);
	mayor(numeros,TAM,m);
	cout<<"MAYOR ES:"<<m<<endl;
	int elementoBuscado = 7;
	bool encontrado = false;
	busquedaRecursiva(numeros, TAM, elementoBuscado, encontrado);
	if(encontrado)
		cout << "El elemento " << elementoBuscado << " está presente en el arreglo." << endl;
	else
		cout << "El elemento " << elementoBuscado << " no está presente en el arreglo." << endl;
	
	
	
	return 0;
}

