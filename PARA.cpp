#include <iostream>
#include <string>
#include <ctime> // Para generar números aleatorios
using namespace std;

// Definición de la estructura LIBRO
struct Libro {
	string titulo;
	string autor;
	string ISBN;
	int anioPublicacion;
	string genero;
	string estado;
	string editorial;
	string idioma;
	string ubicacion;
	string formato;
};

// Definición de la estructura USUARIO
struct Usuario {
	int userID;
	string nombre;
	string apellido;
	string email;
	string direccion;
};

// Definición de la estructura BIBLIOTECARIO
struct Bibliotecario {
	int empleadoID;
	string nombre;
	string apellido;
	string email;
	string telefono;
};

// Función para generar datos aleatorios
string generarDatoAleatorio(string lista[], int longitud) {
	return lista[rand() % longitud];
}

// Función para llenar una estructura Libro de forma recursiva
void llenarLibro(Libro& libro, string listaTitulos[], string listaAutores[], string listaISBN[], string listaGeneros[], string listaEditoriales[], int indice = 0) {
	if (indice == 0) {
		libro.titulo = generarDatoAleatorio(listaTitulos, 3);
		libro.autor = generarDatoAleatorio(listaAutores, 3);
		libro.ISBN = generarDatoAleatorio(listaISBN, 5);
		libro.anioPublicacion = rand() % 50 + 1970;
		libro.genero = generarDatoAleatorio(listaGeneros, 3);
		libro.estado = "disponible";
		libro.editorial = generarDatoAleatorio(listaEditoriales, 3);
		libro.idioma = "Español";
		libro.ubicacion = "Estantería " + to_string(rand() % 10 + 1);
		libro.formato = "Impreso";
	} else if (indice < 10) {
		llenarLibro(libro, listaTitulos, listaAutores, listaISBN, listaGeneros, listaEditoriales, indice - 1);
	}
}

// Función para llenar una estructura Usuario de forma recursiva
void llenarUsuario(Usuario& usuario, string listaNombres[], string listaApellidos[], int indice = 0) {
	if (indice == 0) {
		usuario.userID = rand() % 5 + 1;
		usuario.nombre = generarDatoAleatorio(listaNombres, 3);
		usuario.apellido = generarDatoAleatorio(listaApellidos, 3);
		usuario.email = usuario.nombre + usuario.apellido + "@gmail.com";
		usuario.direccion = "Calle " + usuario.nombre + " " + usuario.apellido + ", Ciudad";
	} else if (indice < 5) {
		llenarUsuario(usuario, listaNombres, listaApellidos, indice - 1);
	}
}

// Función para llenar una estructura Bibliotecario de forma recursiva
void llenarBibliotecario(Bibliotecario& bibliotecario, string listaNombres[], string listaApellidos[], int indice = 0) {
	if (indice == 0) {
		bibliotecario.empleadoID = rand() % 5 + 1;
		bibliotecario.nombre = generarDatoAleatorio(listaNombres, 3);
		bibliotecario.apellido = generarDatoAleatorio(listaApellidos, 3);
		bibliotecario.email = bibliotecario.nombre + bibliotecario.apellido + "@library.com";
		bibliotecario.telefono = "123-456-789";
	} else if (indice < 5) {
		llenarBibliotecario(bibliotecario, listaNombres, listaApellidos, indice - 1);
	}
}

// Función para imprimir una estructura Libro
void imprimir(const Libro& libro) {
	cout << "Título: " << libro.titulo << ", Autor: " << libro.autor << ", ISBN: " << libro.ISBN
		<< ", Año de Publicación: " << libro.anioPublicacion << ", Género: " << libro.genero
		<< ", Estado: " << libro.estado << ", Editorial: " << libro.editorial << endl;
	cout << "Idioma: " << libro.idioma << ", Ubicación: " << libro.ubicacion << ", Formato: " << libro.formato << endl;
}

// Función para imprimir una estructura Usuario
void imprimir(const Usuario& usuario) {
	cout << "ID: " << usuario.userID << ", Nombre: " << usuario.nombre << ", Apellido: " << usuario.apellido
		<< ", Email: " << usuario.email << ", Dirección: " << usuario.direccion << endl;
}

// Función para imprimir una estructura Bibliotecario
void imprimir(const Bibliotecario& bibliotecario) {
	cout << "ID: " << bibliotecario.empleadoID << ", Nombre: " << bibliotecario.nombre << ", Apellido: " << bibliotecario.apellido
		<< ", Email: " << bibliotecario.email << ", Teléfono: " << bibliotecario.telefono << endl;
}


// Función para buscar un libro por título de forma recursiva
void buscarLibro(const Libro libros[], int longitud, const string& titulo, int indice = 0) {
	if (indice < longitud) {
		if (libros[indice].titulo == titulo) {
			cout << "Libro encontrado:" << endl;
			imprimir(libros[indice]);
			return;
		}
		buscarLibro(libros, longitud, titulo, indice + 1);
	} else {
		cout << "Libro no encontrado." << endl;
	}
}

// Función para buscar un usuario por nombre y apellido de forma recursiva
void buscarUsuario(const Usuario usuarios[], int longitud, const string& nombre, const string& apellido, int indice = 0) {
	if (indice < longitud) {
		if (usuarios[indice].nombre == nombre && usuarios[indice].apellido == apellido) {
			cout << "Usuario encontrado:" << endl;
			imprimir(usuarios[indice]);
			return;
		}
		buscarUsuario(usuarios, longitud, nombre, apellido, indice + 1);
	} else {
		cout << "Usuario no encontrado." << endl;
	}
}

// Función para buscar un bibliotecario por nombre y apellido de forma recursiva
void buscarBibliotecario(const Bibliotecario bibliotecarios[], int longitud, const string& nombre, const string& apellido, int indice = 0) {
	if (indice < longitud) {
		if (bibliotecarios[indice].nombre == nombre && bibliotecarios[indice].apellido == apellido) {
			cout << "Bibliotecario encontrado:" << endl;
			imprimir(bibliotecarios[indice]);
			return;
		}
		buscarBibliotecario(bibliotecarios, longitud, nombre, apellido, indice + 1);
	} else {
		cout << "Bibliotecario no encontrado." << endl;
	}
}
// Función para mostrar el menú principal
void mostrarMenu() {
	cout << "----- Menú -----" << endl;
	cout << "1. Llenado de datos" << endl;
	cout << "2. Listados" << endl;
	cout << "3. Búsquedas" << endl;
	cout << "0. Salir" << endl;
	cout << "----------------" << endl;
}

// Función para mostrar el submenú de Listados
void mostrarSubMenuListados() {
	cout << "----- Submenú Listados -----" << endl;
	cout << "A. Listados de libros" << endl;
	cout << "B. Listados de usuarios" << endl;
	cout << "C. Listados de bibliotecarios" << endl;
	cout << "X. Salir" << endl;
	cout << "----------------" << endl;
}

// Función para mostrar el submenú de Búsquedas
void mostrarSubMenuBusquedas() {
	cout << "----- Submenú Búsquedas -----" << endl;
	cout << "A. Búsqueda de libros (título)" << endl;
	cout << "B. Búsqueda de usuarios (nombre y apellido)" << endl;
	cout << "C. Búsqueda de bibliotecarios (nombre y apellido)" << endl;
	cout << "X. Salir" << endl;
	cout << "----------------" << endl;
}

int main() {
	// Semilla para la generación de números aleatorios
	srand(time(0));
	
	// Arrays fijos de referencia
	string listaTitulos[] = {"Aprende C++", "Aprende Python", "Aprende Java"};
	string listaAutores[] = {"Autor A", "Autor B", "Autor C"};
	string listaISBN[] = {"1", "2", "3", "4", "5"};
	string listaGeneros[] = {"Ficción", "No ficción", "Fantasía"};
	string listaEditoriales[] = {"Editorial A", "Editorial B", "Editorial C"};
	string listaNombres[] = {"Juan", "María", "Pedro"};
	string listaApellidos[] = {"González", "Rodríguez", "López"};
	
	// Arrays para almacenar datos generados aleatoriamente
	Libro libros[10];
	Usuario usuarios[5];
	Bibliotecario bibliotecarios[5];
	
	// Variable para almacenar la opción del usuario
	int opcion;
	
	do {
		mostrarMenu();
		cout << "Ingrese su opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			// Llenado de datos
			llenarLibro(libros[0], listaTitulos, listaAutores, listaISBN, listaGeneros, listaEditoriales, 0);
			llenarUsuario(usuarios[0], listaNombres, listaApellidos, 0);
			llenarBibliotecario(bibliotecarios[0], listaNombres, listaApellidos, 0);
			cout << "Datos llenados correctamente." << endl;
			break;
		case 2: {
			char opcionListados;
			do {
				mostrarSubMenuListados();
				cout << "Ingrese su opción: ";
				cin >> opcionListados;
				
				switch (opcionListados) {
				case 'A':
					// Listado de libros
					cout << "Listado de libros:" << endl;
					imprimir(libros[0]);
					break;
				case 'B':
					// Listado de usuarios
					cout << "Listado de usuarios:" << endl;
					imprimir(usuarios[0]);
					break;
				case 'C':
					// Listado de bibliotecarios
					cout << "Listado de bibliotecarios:" << endl;
					imprimir(bibliotecarios[0]);
					break;
				case 'X':
					cout << "Saliendo al menú principal." << endl;
					break;
				default:
					cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
					break;
				}
			} while (opcionListados != 'X');
			break;
		}
		case 3: {
			char opcionBusquedas;
			do {
				mostrarSubMenuBusquedas();
				cout << "Ingrese su opción: ";
				cin >> opcionBusquedas;
				
				switch (opcionBusquedas) {
				case 'A': {
					string titulo;
					cout << "Ingrese el título del libro a buscar: ";
					cin.ignore();
					getline(cin, titulo);
					buscarLibro(libros, 10, titulo);
					break;
				}
				case 'B': {
					string nombre, apellido;
					cout << "Ingrese el nombre y apellido del usuario a buscar: ";
					cin >> nombre >> apellido;
					buscarUsuario(usuarios, 5, nombre, apellido);
					break;
				}
				case 'C': {
					string nombre, apellido;
					cout << "Ingrese el nombre y apellido del bibliotecario a buscar: ";
					cin >> nombre >> apellido;
					buscarBibliotecario(bibliotecarios, 5, nombre, apellido);
					break;
				}
				case 'X':
					cout << "Saliendo al menú principal." << endl;
					break;
				default:
					cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
					break;
				}
			} while (opcionBusquedas != 'X');
			break;
		}
		case 0:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opción no válida. Por favor, ingrese una opción válida." << endl;
			break;
		}
	} while (opcion != 0);
	
	return 0;
}
