#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	// Declarar variables
	double num1, num2, num3;
	
	// Solicitar al usuario que ingrese los números
	cout << "Ingrese el primer número: ";
	cin >> num1;
	
	cout << "Ingrese el segundo número: ";
	cin >> num2;
	
	cout << "Ingrese el tercer número: ";
	cin >> num3;
	
	// Encontrar el número mayor usando operadores ternarios
	double mayor = (num1 > num2) ? ((num1 > num3) ? num1 : num3) : ((num2 > num3) ? num2 : num3);
	
	// Mostrar el resultado
	cout << "El número mayor es: " << mayor << endl;
	
	return 0;
}

