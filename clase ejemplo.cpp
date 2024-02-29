#include <iostream>
using namespace std;
class ejemplo
{ //ATRIBUTOS DEL OBJETO PRIVADO
	int iprivado, isegundo;
public:
	ejemplo(int valor, int valor2)
	{
		this->iprivado=valor;
		this->isegundo=valor2;
	}
	int get_iprivado()//METODO PARA RETORNAR EL VALOR DEL ATRIBUTO IPRIVADO
	{
		return iprivado;
	}
	int get_isegundo()//METODO PARA RETORNAR EL VALOR DEL ATRIBUTO ISEGUNDO
	{
		return isegundo;
	}
	void set_iprivado(int valor)//METODO PARA ASIGNAR ELVALOR DEL ATRIBUTO IPRIVADO
	{
		if(valor >0)
		{
			iprivado=valor;
		}
	}
	void set_isegundo(int valor)//METODO PARA AISIGANR DEL ATRIBUTO ISEGUNDO
	{
		if(valor >0)
		{
			isegundo=valor;
		}
	}
	void set_ejemplo(int valor, int valor2)//METODO PARA ASIGNAR VALORES A TODOS LOS ATRIBUTOS
	{
		if(valor >0&&valor2>0)
		{
		  iprivado=valor;
		  isegundo=valor2;
		}
	}
    //GENERAR EL DESTRUCTOR
	~ejemplo()
	{
		iprivado=-1;
		isegundo=-1;
		cout<<"se esta ejecutando el DESTRUCTOR"<<endl;
	}
};
int main(int argc, char *argv[])
{
	ejemplo objeto1(0, 0);
	cout<<"Objeto1 atributo iprivado:"<<objeto1.get_iprivado()<<endl;
	objeto1.set_iprivado(100);
	cout<<"Objeto1 atributo iprivado:"<<objeto1.get_iprivado()<<endl;
	//delete objeto2;
	objeto1.set_iprivado(-20);
	cout<<"Objeto1 atributo iprivado:"<<objeto1.get_iprivado()<<endl;
	return 0;
}
