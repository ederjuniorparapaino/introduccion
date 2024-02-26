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

// Funci�n para llenar una estructura Libro de forma recursiva
void llenarLibro(Libro& libro, string listaTitulos[], string listaAutores[], string listaISBN[], string listaGeneros[], string listaEditoriales[], int indice = 0) {
	if (indice == 0) {
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
	} else if (indice < 10) {
		llenarLibro(libro, listaTitulos, listaAutores, listaISBN, listaGeneros, listaEditoriales, indice - 1);
	}
}

// Funci�n para llenar una estructura Usuario de forma recursiva
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

// Funci�n para llenar una estructura Bibliotecario de forma recursiva
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


// Funci�n para buscar un libro por t�tulo de forma recursiva
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

// Funci�n para buscar un usuario por nombre y apellido de forma recursiva
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

// Funci�n para buscar un bibliotecario por nombre y apellido de forma recursiva
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
			llenarLibro(libros[0], listaTitulos, listaAutores, listaISBN, listaGeneros, listaEditoriales, 0);
			llenarUsuario(usuarios[0], listaNombres, listaApellidos, 0);
			llenarBibliotecario(bibliotecarios[0], listaNombres, listaApellidos, 0);
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
