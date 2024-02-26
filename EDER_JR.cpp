#include <iostream>
#include <string>
#include <ctime> // Para generar n�meros aleatorios
using namespace std;

// Definici�n de la estructura LIBRO
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

// Definici�n de la estructura USUARIO
struct Usuario {
	int userID;
	string nombre;
	string apellido;
	string email;
	string direccion;
};

// Definici�n de la estructura BIBLIOTECARIO
struct Bibliotecario {
	int empleadoID;
	string nombre;
	string apellido;
	string email;
	string telefono;
};

// Funci�n para generar datos aleatorios
string generarDatoAleatorio(string lista[], int longitud) {
	return lista[rand() % longitud];
}

// Funci�n para llenar una estructura Libro
void llenarLibro(Libro& libro, string listaTitulos[], string listaAutores[], string listaISBN[], string listaGeneros[], string listaEditoriales[]) {
	libro.titulo = generarDatoAleatorio(listaTitulos, 3);
	libro.autor = generarDatoAleatorio(listaAutores, 3);
	libro.ISBN = generarDatoAleatorio(listaISBN, 5);
	libro.anioPublicacion = rand() % 50 + 1970;
	libro.genero = generarDatoAleatorio(listaGeneros, 3);
	libro.estado = "disponible";
	libro.editorial = generarDatoAleatorio(listaEditoriales, 3);
	libro.idioma = "Espa�ol";
	libro.ubicacion = "Estanter�a " + to_string(rand() % 10 + 1);
	libro.formato = "Impreso";
}

// Funci�n para llenar una estructura Usuario
void llenarUsuario(Usuario& usuario, string listaNombres[], string listaApellidos[]) {
	usuario.userID = rand() % 5 + 1;
	usuario.nombre = generarDatoAleatorio(listaNombres, 3);
	usuario.apellido = generarDatoAleatorio(listaApellidos, 3);
	usuario.email = usuario.nombre + usuario.apellido + "@gmail.com";
	usuario.direccion = "Calle " + usuario.nombre + " " + usuario.apellido + ", Ciudad";
}

// Funci�n para llenar una estructura Bibliotecario
void llenarBibliotecario(Bibliotecario& bibliotecario, string listaNombres[], string listaApellidos[]) {
	bibliotecario.empleadoID = rand() % 5 + 1;
	bibliotecario.nombre = generarDatoAleatorio(listaNombres, 3);
	bibliotecario.apellido = generarDatoAleatorio(listaApellidos, 3);
	bibliotecario.email = bibliotecario.nombre + bibliotecario.apellido + "@library.com";
	bibliotecario.telefono = "123-456-789";
}

// Funci�n para imprimir una estructura Libro
void imprimir(const Libro& libro) {
	cout << "T�tulo: " << libro.titulo << ", Autor: " << libro.autor << ", ISBN: " << libro.ISBN
		<< ", A�o de Publicaci�n: " << libro.anioPublicacion << ", G�nero: " << libro.genero
		<< ", Estado: " << libro.estado << ", Editorial: " << libro.editorial << endl;
	cout << "Idioma: " << libro.idioma << ", Ubicaci�n: " << libro.ubicacion << ", Formato: " << libro.formato << endl;
}

// Funci�n para imprimir una estructura Usuario
void imprimir(const Usuario& usuario) {
	cout << "ID: " << usuario.userID << ", Nombre: " << usuario.nombre << ", Apellido: " << usuario.apellido
		<< ", Email: " << usuario.email << ", Direcci�n: " << usuario.direccion << endl;
}

// Funci�n para imprimir una estructura Bibliotecario
void imprimir(const Bibliotecario& bibliotecario) {
	cout << "ID: " << bibliotecario.empleadoID << ", Nombre: " << bibliotecario.nombre << ", Apellido: " << bibliotecario.apellido
		<< ", Email: " << bibliotecario.email << ", Tel�fono: " << bibliotecario.telefono << endl;
}

// Funci�n para listar libros de forma recursiva
void listarLibros(const Libro libros[], int cantidadLibros, int indiceActual = 0) {
	if (indiceActual >= cantidadLibros) {
		return;
	}
	imprimir(libros[indiceActual]);
	listarLibros(libros, cantidadLibros, indiceActual + 1);
}

// Funci�n para listar usuarios de forma recursiva
void listarUsuarios(const Usuario usuarios[], int cantidadUsuarios, int indiceActual = 0) {
	if (indiceActual >= cantidadUsuarios) {
		return;
	}
	imprimir(usuarios[indiceActual]);
	listarUsuarios(usuarios, cantidadUsuarios, indiceActual + 1);
}

// Funci�n para listar bibliotecarios de forma recursiva
void listarBibliotecarios(const Bibliotecario bibliotecarios[], int cantidadBibliotecarios, int indiceActual = 0) {
	if (indiceActual >= cantidadBibliotecarios) {
		return;
	}
	imprimir(bibliotecarios[indiceActual]);
	listarBibliotecarios(bibliotecarios, cantidadBibliotecarios, indiceActual + 1);
}

// Funci�n para buscar un libro por t�tulo de forma recursiva
void buscar(const Libro libros[], int cantidadLibros, const string& titulo, int indiceActual = 0) {
	if (indiceActual >= cantidadLibros) {
		cout << "El libro no fue encontrado." << endl;
		return;
	}
	if (libros[indiceActual].titulo == titulo) {
		cout << "Libro encontrado: " << endl;
		imprimir(libros[indiceActual]);
		return;
	}
	buscar(libros, cantidadLibros, titulo, indiceActual + 1);
}

// Funci�n para buscar un usuario por nombre y apellido de forma recursiva
void buscar(const Usuario usuarios[], int cantidadUsuarios, const string& nombre, const string& apellido, int indiceActual = 0) {
	if (indiceActual >= cantidadUsuarios) {
		cout << "El usuario no fue encontrado." << endl;
		return;
	}
	if (usuarios[indiceActual].nombre == nombre && usuarios[indiceActual].apellido == apellido) {
		cout << "Usuario encontrado: " << endl;
		imprimir(usuarios[indiceActual]);
		return;
	}
	buscar(usuarios, cantidadUsuarios, nombre, apellido, indiceActual + 1);
}

// Funci�n para buscar un bibliotecario por nombre y apellido de forma recursiva
void buscar(const Bibliotecario bibliotecarios[], int cantidadBibliotecarios, const string& nombre, const string& apellido, int indiceActual = 0) {
	if (indiceActual >= cantidadBibliotecarios) {
		cout << "El bibliotecario no fue encontrado." << endl;
		return;
	}
	if (bibliotecarios[indiceActual].nombre == nombre && bibliotecarios[indiceActual].apellido == apellido) {
		cout << "Bibliotecario encontrado: " << endl;
		imprimir(bibliotecarios[indiceActual]);
		return;
	}
	buscar(bibliotecarios, cantidadBibliotecarios, nombre, apellido, indiceActual + 1);
}

// Funci�n para mostrar el men� principal
void mostrarMenu() {
	cout << "----- Men� -----" << endl;
	cout << "1. Llenado de datos" << endl;
	cout << "2. Listados" << endl;
	cout << "3. B�squedas" << endl;
	cout << "0. Salir" << endl;
	cout << "----------------" << endl;
}

// Funci�n para mostrar el submen� de Listados
void mostrarSubMenuListados() {
	cout << "----- Submen� Listados -----" << endl;
	cout << "A. Listados de libros" << endl;
	cout << "B. Listados de usuarios" << endl;
	cout << "C. Listados de bibliotecarios" << endl;
	cout << "X. Salir" << endl;
	cout << "----------------" << endl;
}

// Funci�n para mostrar el submen� de B�squedas
void mostrarSubMenuBusquedas() {
	cout << "----- Submen� B�squedas -----" << endl;
	cout << "A. B�squeda de libros (t�tulo)" << endl;
	cout << "B. B�squeda de usuarios (nombre y apellido)" << endl;
	cout << "C. B�squeda de bibliotecarios (nombre y apellido)" << endl;
	cout << "X. Salir" << endl;
	cout << "----------------" << endl;
}

int main() {
	// Semilla para la generaci�n de n�meros aleatorios
	srand(time(0));
	
	// Arrays fijos de referencia
	string listaTitulos[] = {"Aprende C++", "Aprende Python", "Aprende Java"};
	string listaAutores[] = {"Autor A", "Autor B", "Autor C"};
	string listaISBN[] = {"1", "2", "3", "4", "5"};
	string listaGeneros[] = {"Ficci�n", "No ficci�n", "Fantas�a"};
	string listaEditoriales[] = {"Editorial A", "Editorial B", "Editorial C"};
	string listaNombres[] = {"Juan", "Mar�a", "Pedro"};
	string listaApellidos[] = {"Gonz�lez", "Rodr�guez", "L�pez"};
	
	// Arrays para almacenar datos generados aleatoriamente
	Libro libros[10];
	Usuario usuarios[5];
	Bibliotecario bibliotecarios[5];
	
	// Variable para almacenar la opci�n del usuario
	int opcion;
	
	do {
		mostrarMenu();
		cout << "Ingrese su opci�n: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			// Llenado de datos
			for (int i = 0; i < 10; ++i) {
				llenarLibro(libros[i], listaTitulos, listaAutores, listaISBN, listaGeneros, listaEditoriales);
			}
			for (int i = 0; i < 5; ++i) {
				llenarUsuario(usuarios[i], listaNombres, listaApellidos);
				llenarBibliotecario(bibliotecarios[i], listaNombres, listaApellidos);
			}
			cout << "Datos llenados correctamente." << endl;
			break;
		case 2: {
			char opcionListados;
			do {
				mostrarSubMenuListados();
				cout << "Ingrese su opci�n: ";
				cin >> opcionListados;
				
				switch (opcionListados) {
				case 'A':
					// Listado de libros
					cout << "Listado de libros:" << endl;
					listarLibros(libros, 10);
					break;
				case 'B':
					// Listado de usuarios
					cout << "Listado de usuarios:" << endl;
					listarUsuarios(usuarios, 5);
					break;
				case 'C':
					// Listado de bibliotecarios
					cout << "Listado de bibliotecarios:" << endl;
					listarBibliotecarios(bibliotecarios, 5);
					break;
				case 'X':
					cout << "Saliendo al men� principal." << endl;
					break;
				default:
					cout << "Opci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
					break;
				}
			} while (opcionListados != 'X');
			break;
		}
		case 3: {
			char opcionBusquedas;
			do {
				mostrarSubMenuBusquedas();
				cout << "Ingrese su opci�n: ";
				cin >> opcionBusquedas;
				
				switch (opcionBusquedas) {
				case 'A': {
					string titulo;
					cout << "Ingrese el t�tulo del libro a buscar: ";
					cin.ignore();
					getline(cin, titulo);
					buscar(libros, 10, titulo);
					break;
				}
				case 'B': {
					string nombre, apellido;
					cout << "Ingrese el nombre y apellido del usuario a buscar: ";
					cin >> nombre >> apellido;
					buscar(usuarios, 5, nombre, apellido);
					break;
				}
				case 'C': {
					string nombre, apellido;
					cout << "Ingrese el nombre y apellido del bibliotecario a buscar: ";
					cin >> nombre >> apellido;
					buscar(bibliotecarios, 5, nombre, apellido);
					break;
				}
				case 'X':
					cout << "Saliendo al men� principal." << endl;
					break;
				default:
					cout << "Opci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
					break;
				}
			} while (opcionBusquedas != 'X');
			break;
		}
		case 0:
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opci�n no v�lida. Por favor, ingrese una opci�n v�lida." << endl;
			break;
		}
	} while (opcion != 0);
	
	return 0;
}
