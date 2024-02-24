#include <iostream>
#include <string>
#include <ctime> // Para generar números aleatorios
using namespace std;

// Definición de la estructura LIBRO
struct Libro {
	string title;
	string author;
	string ISBN;
	int publicacionanio;
	string genero;
	string estado;
	string editorial;
	string idioma; // Nuevo elemento
};

// Definición de la estructura USUARIO
struct Usuario {
	string userID;
	string nombre;
	string apellido;
	string email;
	string direccion; // Nuevo elemento
	Libro librosPrestados[5]; // Arreglo de libros
};

// Definición de la estructura BIBLIOTECARIO
struct Bibliotecario {
	string empleadoID;
	string nombre;
	string apellido;
	string email;
	string fechaContratacion;
	string telefono; // Nuevo elemento
};

// Función para generar datos aleatorios
string generarDatoAleatorio(string lista[], int longitud) {
	return lista[rand() % longitud];
}

// Función para llenar una estructura Libro
void llenarLibro(Libro& libro, string listaLibros[], string listaNombres[], string listaApellidos[], string listaGeneros[], string listaEditoriales[], string listaIdiomas[]) {
	libro.title = generarDatoAleatorio(listaLibros, 3);
	libro.author = generarDatoAleatorio(listaNombres, 3) + " " + generarDatoAleatorio(listaApellidos, 3);
	libro.ISBN = to_string(rand() % 5 + 1); // Número aleatorio entre 1 y 5
	libro.publicacionanio = rand() % 50 + 1970; // Año entre 1970 y 2019
	libro.genero = generarDatoAleatorio(listaGeneros, 3); // No es necesario crear un nuevo string
	libro.estado = "disponible";
	libro.editorial = generarDatoAleatorio(listaEditoriales, 3);
	libro.idioma = generarDatoAleatorio(listaIdiomas, 3); // Nuevo dato aleatorio
}

// Función para llenar una estructura Usuario
void llenarUsuario(Usuario& usuario, string listaNombres[], string listaApellidos[], string listaEmails[], Libro libros[], string listaLibros[], string listaGeneros[], string listaEditoriales[], string listaIdiomas[]) {
	usuario.userID = to_string(rand() % 5 + 1); // Convertido a string
	usuario.nombre = generarDatoAleatorio(listaNombres, 3);
	usuario.apellido = generarDatoAleatorio(listaApellidos, 3);
	usuario.email = usuario.nombre + usuario.apellido + generarDatoAleatorio(listaEmails, 3);
	usuario.direccion = "Dirección de " + usuario.nombre + " " + usuario.apellido; // Nueva dirección
	// Asignar libros aleatorios al usuario
	for (int i = 0; i < 5; ++i) {
		llenarLibro(usuario.librosPrestados[i], listaLibros, listaNombres, listaApellidos, listaGeneros, listaEditoriales, listaIdiomas);
	}
}

// Función para llenar una estructura Bibliotecario
void llenarBibliotecario(Bibliotecario& bibliotecario, string listaNombres[], string listaApellidos[], string listaEmails[], string listaFechas[], string listaTelefonos[]) {
	bibliotecario.empleadoID = to_string(rand() % 5 + 1); // Convertido a string
	bibliotecario.nombre = generarDatoAleatorio(listaNombres, 3);
	bibliotecario.apellido = generarDatoAleatorio(listaApellidos, 3);
	bibliotecario.email = bibliotecario.nombre + bibliotecario.apellido + generarDatoAleatorio(listaEmails, 3);
	bibliotecario.fechaContratacion = generarDatoAleatorio(listaFechas, 3); // No es necesario crear un nuevo string
	bibliotecario.telefono = generarDatoAleatorio(listaTelefonos, 3); // Nuevo dato aleatorio
}

// Función para imprimir una estructura Libro de forma recursiva
void imprimirLibro(const Libro& libro, int elementoActual = 0) {
	if (elementoActual == 0) {
		cout << "Datos del Libro:" << endl;
	}
	cout << "Título: " << libro.title << ", Autor: " << libro.author << ", ISBN: " << libro.ISBN
		<< ", Año de Publicación: " << libro.publicacionanio << ", Género: " << libro.genero
		<< ", Estado: " << libro.estado << ", Editorial: " << libro.editorial << ", Idioma: " << libro.idioma << endl;
}

// Función para imprimir una estructura Usuario de forma recursiva
void imprimirUsuario(const Usuario& usuario, int elementoActual = 0) {
	if (elementoActual == 0) {
		cout << "Datos del Usuario:" << endl;
	}
	cout << "ID: " << usuario.userID << ", Nombre: " << usuario.nombre << ", Apellido: " << usuario.apellido
		<< ", Email: " << usuario.email << ", Dirección: " << usuario.direccion << endl;
	if (elementoActual < 5) {
		imprimirLibro(usuario.librosPrestados[elementoActual], elementoActual + 1);
	}
}

// Función para imprimir una estructura Bibliotecario de forma recursiva
void imprimirBibliotecario(const Bibliotecario& bibliotecario, int elementoActual = 0) {
	if (elementoActual == 0) {
		cout << "Datos del Bibliotecario:" << endl;
	}
	cout << "ID: " << bibliotecario.empleadoID << ", Nombre: " << bibliotecario.nombre << ", Apellido: " << bibliotecario.apellido
		<< ", Email: " << bibliotecario.email << ", Fecha de Contratación: " << bibliotecario.fechaContratacion
		<< ", Teléfono: " << bibliotecario.telefono << endl;
}

// Función para buscar un libro por título de forma recursiva
void buscarPorTitulo(const Libro libros[], int cantidadLibros, const string& titulo, int indiceActual = 0) {
	if (indiceActual >= cantidadLibros) {
		cout << "El libro no fue encontrado." << endl;
		return;
	}
	if (libros[indiceActual].title == titulo) {
		cout << "Libro encontrado: " << endl;
		imprimirLibro(libros[indiceActual]);
		return;
	}
	buscarPorTitulo(libros, cantidadLibros, titulo, indiceActual + 1);
}

// Función para buscar un libro por autor de forma recursiva
void buscarPorAutor(const Libro libros[], int cantidadLibros, const string& autor, int indiceActual = 0) {
	if (indiceActual >= cantidadLibros) {
		cout << "El libro no fue encontrado." << endl;
		return;
	}
	if (libros[indiceActual].author == autor) {
		cout << "Libro encontrado: " << endl;
		imprimirLibro(libros[indiceActual]);
		return;
	}
	buscarPorAutor(libros, cantidadLibros, autor, indiceActual + 1);
}

// Función para mostrar el menú
void mostrarMenu() {
	cout << "----- Menú -----" << endl;
	cout << "1. Mostrar todos los libros" << endl;
	cout << "2. Buscar libro por título" << endl;
	cout << "3. Buscar libro por autor" << endl;
	cout << "4. Mostrar todos los usuarios" << endl;
	cout << "5. Mostrar todos los bibliotecarios" << endl;
	cout << "6. Salir" << endl;
	cout << "----------------" << endl;
}

int main() {
	// Arrays fijos de referencia
	string listaLibros[] = {"Aprende C", "Aprende PHP", "Aprende Linux"};
	string listaGeneros[] = {"Ficción", "No ficción", "Fantasía"};
	string listaEditoriales[] = {"Editorial A", "Editorial B", "Editorial C"};
	string listaNombres[] = {"Juan", "María", "Pedro"};
	string listaApellidos[] = {"González", "Rodríguez", "López"};
	string listaEmails[] = {"@gmail.com", "@yahoo.com", "@outlook.com"};
	string listaFechas[] = {"01/01/2020", "15/05/2018", "20/11/2015"};
	string listaIdiomas[] = {"Español", "Inglés", "Francés"};
	string listaTelefonos[] = {"123456789", "987654321", "555555555"};
	
	// Semilla para la generación de números aleatorios
	srand(time(0));
	
	// Generar estructuras y arrays
	Libro libros[10];
	Usuario usuarios[5];
	Bibliotecario bibliotecarios[5];
	
	// Llenar datos aleatorios para libros
	for (int i = 0; i < 10; ++i) {
		llenarLibro(libros[i], listaLibros, listaNombres, listaApellidos, listaGeneros, listaEditoriales, listaIdiomas);
	}
	
	// Llenar datos aleatorios para usuarios
	for (int i = 0; i < 5; ++i) {
		llenarUsuario(usuarios[i], listaNombres, listaApellidos, listaEmails, libros, listaLibros, listaGeneros, listaEditoriales, listaIdiomas);
	}
	
	// Llenar datos aleatorios para bibliotecarios
	for (int i = 0; i < 5; ++i) {
		llenarBibliotecario(bibliotecarios[i], listaNombres, listaApellidos, listaEmails, listaFechas, listaTelefonos);
	}
	
	// Variable para almacenar la opción del usuario
	int opcion;
	
	do {
		mostrarMenu();
		cout << "Ingrese su opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Mostrando todos los libros:" << endl;
			for (int i = 0; i < 10; ++i) {
				imprimirLibro(libros[i]);
			}
			break;
		case 2:
		{
			string titulo;
			cout << "Ingrese el título del libro a buscar: ";
			cin.ignore();
			getline(cin, titulo);
			buscarPorTitulo(libros, 10, titulo);
		}
		break;
		case 3:
		{
			string autor;
			cout << "Ingrese el autor del libro a buscar: ";
			cin.ignore();
			getline(cin, autor);
			buscarPorAutor(libros, 10, autor);
		}
		break;
		case 4:
			cout << "Mostrando todos los usuarios:" << endl;
			for (int i = 0; i < 5; ++i) {
				imprimirUsuario(usuarios[i]);
			}
			break;
		case 5:
			cout << "Mostrando todos los bibliotecarios:" << endl;
			for (int i = 0; i < 5; ++i) {
				imprimirBibliotecario(bibliotecarios[i]);
			}
			break;
		case 6:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
			break;
		}
	} while (opcion != 6);
	
	return 0;
}
