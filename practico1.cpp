#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	// Declarar variables
	double num1, num2, num3;
	
	// Solicitar al usuario que ingrese los n�meros
	cout << "Ingrese el primer n�mero: ";
	cin >> num1;
	
	cout << "Ingrese el segundo n�mero: ";
	cin >> num2;
	
	cout << "Ingrese el tercer n�mero: ";
	cin >> num3;
	
	// Encontrar el n�mero mayor usando operadores ternarios
	double mayor = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
	
	// Mostrar el resultado
	cout << "El n�mero mayor es: " << mayor << endl;
	
	return 0;
}

