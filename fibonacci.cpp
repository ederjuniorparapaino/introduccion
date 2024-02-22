#include <iostream>
using namespace std;
int fib(int n){
	if(n <= 1)
		return n; //condicion base
	else
		{
		//cout<<(n-1)<<", "<<(n-2)<<endl;
		return fib(n-1)+fib(n-2); //condicion recursiva
	}
}
int main(int argc, char *argv[]) {
	const int NUM=5;
	cout<<"Fibonacci de:"<<NUM<<"-"<<fib(NUM)<<endl;
	return 0;
}

