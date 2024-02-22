#include <iostream>
using namespace std;
int factorialNORMAL (int n){
	int fact = 1;
	for (int i=1;i<=n;++i)
		fact=i*fact;
	return fact;
}
int factorial(int n){
	if(n==0)
		return 1;
	else
		return factorial(n-1)*n;
}
int main(int argc, char *argv[]) {
	const int NUM=6;
	cout<<"FACTORIAL DE NUMERO ES:"<<factorial(NUM)<<endl;
	cout<<"Factorial:"<<factorialNORMAL(5)<<endl;
	
	return 0;
}

