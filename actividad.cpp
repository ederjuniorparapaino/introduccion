#include <iostream>
#include <string>
#include <ctime> // Para generar n�meros aleatorios
using namespace std;

// Definici�n de la estructura LIBRO
struct Libro {
	string title;
	string author;
	string ISBN;
	int publicacionanio;
	string *genero;
	string estado;
	string editorial;
};

// Definici�n de la estructura USUARIO
struct Usuario {
	int userID;
	string nombre;
	string apellido;
	string email;
	Libro* librosPrestados;
};

// Definici�n de la estructura BIBLIOTECARIO
struct Bibliotecario {
	int employeeID;
	string nombre;
	string apellido;
	string email;
	string *fechaContratacion;
};

// Funci�n para generar datos aleatorios
string generarDatoAleatorio(string lista[], int longitud) {
	return lista[rand() % longitud];
}

// Funci�n para llenar una estructura Libro
void llenarLibro(Libro& libro, string listaLibros[], string listaNombres[], string listaApellidos[], string listaGeneros[], string listaEditoriales[]) {
	libro.title = generarDatoAleatorio(listaLibros, 3);
	libro.author = generarDatoAleatorio(listaNombres, 3) + " " + generarDatoAleatorio(listaApellidos, 3);
	libro.ISBN = to_string(rand() % 5 + 1); // N�mero aleatorio entre 1 y 5
	libro.publicacionanio = rand() % 50 + 1970; // A�o entre 1970 y 2019
	libro.genero = new string(generarDatoAleatorio(listaGeneros, 3));
	libro.estado = "disponible";
	libro.editorial = generarDatoAleatorio(listaEditoriales, 3);
}

// Funci�n para llenar una estructura Usuario
void llenarUsuario(Usuario& usuario, string listaNombres[], string listaApellidos[], string listaEmails[], Libro* libros) {
	usuario.userID = rand() % 5 + 1; // ID entre 1 y 5
	usuario.nombre = generarDatoAleatorio(listaNombres, 3);
	usuario.apellido = generarDatoAleatorio(listaApellidos, 3);
	usuario.email = usuario.nombre + usuario.apellido + generarDatoAleatorio(listaEmails, 3);
	usuario.librosPrestados = libros;
}

// Funci�n para llenar una estructura Bibliotecario
void llenarBibliotecario(Bibliotecario& bibliotecario, string listaNombres[], string listaApellidos[], string listaEmails[], string listaFechas[]) {
	bibliotecario.employeeID = rand() % 5 + 1; // ID entre 1 y 5
	bibliotecario.nombre = generarDatoAleatorio(listaNombres, 3);
	bibliotecario.apellido = generarDatoAleatorio(listaApellidos, 3);
	bibliotecario.email = bibliotecario.nombre + bibliotecario.apellido + generarDatoAleatorio(listaEmails, 3);
	bibliotecario.fechaContratacion = new string(generarDatoAleatorio(listaFechas, 3));
}

// Funci�n para imprimir una estructura Libro
void imprimirLibro(const Libro& libro) {
	cout << "T�tulo: " << libro.title << ", Autor: " << libro.author << ", ISBN: " << libro.ISBN
		<< ", A�o de Publicaci�n: " << libro.publicacionanio << ", G�nero: " << *(libro.genero)
		<< ", Estado: " << libro.estado << ", Editorial: " << libro.editorial << endl;
}

// Funci�n para imprimir una estructura Usuario
void imprimirUsuario(const Usuario& usuario) {
	cout << "ID: " << usuario.userID << ", Nombre: " << usuario.nombre << ", Apellido: " << usuario.apellido
		<< ", Email: " << usuario.email << ", Libro Prestado: " << usuario.librosPrestados->title << endl;
}

// Funci�n para imprimir una estructura Bibliotecario
void imprimirBibliotecario(const Bibliotecario& bibliotecario) {
	cout << "ID: " << bibliotecario.employeeID << ", Nombre: " << bibliotecario.nombre << ", Apellido: " << bibliotecario.apellido
		<< ", Email: " << bibliotecario.email << ", Fecha de Contrataci�n: " << *(bibliotecario.fechaContratacion) << endl;
}

int main() {
	// Arrays fijos de referencia
	string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux"};
	string listaGeneros[] = {"Ficci�n", "No ficci�n", "Fantas�a"};
	string listaEditoriales[] = {"Editorial A", "Editorial B", "Editorial C"};
	string listaNombres[] = {"Juan", "Mar�a", "Pedro"};
	string listaApellidos[] = {"Gonz�lez", "Rodr�guez", "L�pez"};
	string listaEmails[] = {"@gmail.com", "@yahoo.com", "@outlook.com"};
	string listaFechas[] = {"01/01/2020", "15/05/2018", "20/11/2015"};
	
	// Semilla para la generaci�n de n�meros aleatorios
	srand(time(0));
	
	// Generar estructuras y arrays
	Libro libros[3];
	Usuario usuarios[3];
	Bibliotecario bibliotecarios[3];
	
	// Llenar datos aleatorios para libros
	for (int i = 0; i < 3; ++i) {
		llenarLibro(libros[i], listaLibros, listaNombres, listaApellidos, listaGeneros, listaEditoriales);
	}
	
	// Llenar datos aleatorios para usuarios
	for (int i = 0; i < 3; ++i) {
		llenarUsuario(usuarios[i], listaNombres, listaApellidos, listaEmails, &libros[i]);
	}
	
	// Llenar datos aleatorios para bibliotecarios
	for (int i = 0; i < 3; ++i) {
		llenarBibliotecario(bibliotecarios[i], listaNombres, listaApellidos, listaEmails, listaFechas);
	}
	
	// Mostrar informaci�n
	cout << "Libros: " << endl;
	for (int i = 0; i < 3; ++i) {
		imprimirLibro(libros[i]);
	}
	
	cout << "\nUsuarios: " << endl;
	for (int i = 0; i < 3; ++i) {
		imprimirUsuario(usuarios[i]);
	}
	
	cout << "\nBibliotecarios: " << endl;
	for (int i = 0; i < 3; ++i) {
		imprimirBibliotecario(bibliotecarios[i]);
	}
	return 0;
}
	
	// Liberar memoria
