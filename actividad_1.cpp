#include <iostream>
#include <string>
#include <ctime> // Para generar números aleatorios
using namespace std;

// Definición de la estructura LIBRO
struct Libro {
	string title;
	string author;
	string ISBN;
	int publicationYear;
	string *genre;
	string status;
	string editorial;
};

// Definición de la estructura USUARIO
struct Usuario {
	int userID;
	string name;
	string lastname;
	string email;
	Libro* librosPrestados;
};

// Definición de la estructura BIBLIOTECARIO
struct Bibliotecario {
	int employeeID;
	string name;
	string lastname;
	string email;
	string* fechaContratacion;
};

// Función para generar datos aleatorios
string generarDatoAleatorio(string lista[], int longitud) {
	return lista[rand() % longitud];
}

// Función principal
int main() {
	// Arrays fijos de referencia
	string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux"};
	string listaGeneros[] = {"Ficción", "No ficción", "Fantasía"};
	string listaEditoriales[] = {"Editorial A", "Editorial B", "Editorial C"};
	string listaNombres[] = {"Juan", "María", "Pedro"};
	string listaApellidos[] = {"González", "Rodríguez", "López"};
	string listaEmails[] = {"@gmail.com", "@yahoo.com", "@outlook.com"};
	string listaFechas[] = {"01/01/2020", "15/05/2018", "20/11/2015"};
	
	// Semilla para la generación de números aleatorios
	srand(time(0));
	
	// Generar estructuras y arrays
	Libro libros[3];
	Usuario usuarios[3];
	Bibliotecario bibliotecarios[3];
	
	// Llenar datos aleatorios para libros
	for (int i = 0; i < 3; ++i) {
		libros[i].title = generarDatoAleatorio(listaLibros, 3);
		libros[i].author = generarDatoAleatorio(listaNombres, 3) + " " + generarDatoAleatorio(listaApellidos, 3);
		libros[i].ISBN = to_string(i + 1) + ",2,3,4,5";
		libros[i].publicationYear = rand() % 50 + 1970; // Año entre 1970 y 2019
		libros[i].genre = new string(generarDatoAleatorio(listaGeneros, 3));
		libros[i].status = "disponible";
		libros[i].editorial = generarDatoAleatorio(listaEditoriales, 3);
	}
	
	// Llenar datos aleatorios para usuarios
	for (int i = 0; i < 3; ++i) {
		usuarios[i].userID = i + 1;
		usuarios[i].name = generarDatoAleatorio(listaNombres, 3);
		usuarios[i].lastname = generarDatoAleatorio(listaApellidos, 3);
		usuarios[i].email = usuarios[i].name + usuarios[i].lastname + generarDatoAleatorio(listaEmails, 3);
		usuarios[i].librosPrestados = &libros[i];
	}
	
	// Llenar datos aleatorios para bibliotecarios
	for (int i = 0; i < 3; ++i) {
		bibliotecarios[i].employeeID = i + 1;
		bibliotecarios[i].name = generarDatoAleatorio(listaNombres, 3);
		bibliotecarios[i].lastname = generarDatoAleatorio(listaApellidos, 3);
		bibliotecarios[i].email = bibliotecarios[i].name + bibliotecarios[i].lastname + generarDatoAleatorio(listaEmails, 3);
		bibliotecarios[i].fechaContratacion = new string(generarDatoAleatorio(listaFechas, 3));
	}
	
	// Mostrar información
	cout << "Libros: " << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "Título: " << libros[i].title << ", Autor: " << libros[i].author << ", ISBN: " << libros[i].ISBN
			<< ", Año de Publicación: " << libros[i].publicationYear << ", Género: " << *(libros[i].genre)
			<< ", Estado: " << libros[i].status << ", Editorial: " << libros[i].editorial << endl;
	}
	
	cout << "\nUsuarios: " << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "ID: " << usuarios[i].userID << ", Nombre: " << usuarios[i].name << ", Apellido: " << usuarios[i].lastname
			<< ", Email: " << usuarios[i].email << ", Libro Prestado: " << usuarios[i].librosPrestados->title << endl;
	}
	
	cout << "\nBibliotecarios: " << endl;
	for (int i = 0; i < 3; ++i) {
		cout << "ID: " << bibliotecarios[i].employeeID << ", Nombre: " << bibliotecarios[i].name << ", Apellido: " << bibliotecarios[i].lastname
			<< ", Email: " << bibliotecarios[i].email << ", Fecha de Contratación: " << *(bibliotecarios[i].fechaContratacion) << endl;
	}
	
	// Liberar memoria
	for (int i = 0; i < 3; ++i) {
		delete libros[i].genre;
		delete bibliotecarios[i].fechaContratacion;
	}
	
	return 0;
}
