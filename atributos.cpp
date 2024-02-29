#include <iostream>
#include <string>
using namespace std;

class usuario
{
	// Atributos del objeto privado
	int UserID;
	string Nombre;
	string Apellido;
	string Email;
	int Edad;
	
public:
	// Constructor
	usuario(int userID, string nombre, string apellido, string email, int edad)
	{
		UserID = userID;
		Nombre = nombre;
		Apellido = apellido;
		Email = email;
		Edad = edad;
	}
	
	// Métodos de acceso para cada atributo
	int getUserID()
	{
		return UserID;
	}
	
	string getNombre()
	{
		return Nombre;
	}
	
	string getApellido()
	{
		return Apellido;
	}
	
	string getEmail()
	{
		return Email;
	}
	
	int getEdad()
	{
		return Edad;
	}
	
	// Métodos de modificación para cada atributo
	void setUserID(int userID)
	{
		UserID = userID;
	}
	
	void setNombre(string nombre)
	{
		Nombre = nombre;
	}
	
	void setApellido(string apellido)
	{
		Apellido = apellido;
	}
	
	void setEmail(string email)
	{
		Email = email;
	}
	
	void setEdad(int edad)
	{
		Edad = edad;
	}
};

int main(int argc, char *argv[])
{
	// Ejemplo de uso
	usuario user1(123, "Juan", "Perez", "juan@example.com", 30);
	
	// Acceder a los atributos y mostrarlos
	cout << "UserID: " << user1.getUserID() << endl;
	cout << "Nombre: " << user1.getNombre() << endl;
	cout << "Apellido: " << user1.getApellido() << endl;
	cout << "Email: " << user1.getEmail() << endl;
	cout << "Edad: " << user1.getEdad() << endl;
	
	// Modificar algunos atributos
	user1.setNombre("Pedro");
	user1.setEdad(35);
	
	// Mostrar los atributos modificados
	cout << "\nAtributos modificados:" << endl;
	cout << "Nombre: " << user1.getNombre() << endl;
	cout << "Edad: " << user1.getEdad() << endl;
	
	return 0;
}
