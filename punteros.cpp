#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
	int v[]={6,7,8};
	int *pi=NULL;
	int num;
	num=v[0];
	pi=v; //puntando al primer elemento.
	cout<<"num:"<<num<<endl;
	cout<<"pi:"<<*pi<<endl;	
	
	for (int i = 0; i < 3; ++i) {
		num = v[i];
		cout << "num: " << num << endl;
		cout << "pi: " << *pi << endl;
		pi++;
	}
	return 0;
}
