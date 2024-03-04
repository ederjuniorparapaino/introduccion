#include <iostream>
#include <string>
#include <random>
#include <vector>
using namespace std;

class persona {
	string nombre, direccion;
public:
	persona() {
		nombre = "";
		direccion = "";
	}
	string get_nombre() { return nombre; }
	string get_direccion() { return direccion; }
	void set_nombre(string n) { nombre = n; }
	void set_direccion(string d) { direccion = d; }
	void mostrarDatos() {
		cout << "Nombre: " << nombre << endl;
		cout << "Direccion: " << direccion << endl;
	}
};

class estudiante : public persona {
	string cod_estudiante;
	string carrera;
public:
	estudiante() {
		cod_estudiante = "sin codigo de estudiante";
		carrera = "sin nombre de carrera";
	}
	string get_cod_estudiante() { return cod_estudiante; }
	string get_carrera() { return carrera; }
	void set_cod_estudiante(string cod) { cod_estudiante = cod; }
	void set_carrera(string car) { carrera = car; }
	void mostrarDatos() {
		persona::mostrarDatos();
		cout << "Codigo estudiante: " << cod_estudiante << endl;
		cout << "Carrera: " << carrera << endl;
	}
	
	string generar_codigo_estudiante() {
		random_device rd;
		mt19937 gen(rd());
		uniform_int_distribution<> dis(100000, 999999);
		return to_string(dis(gen));
	}
};

string generar_nombre_aleatorio() {
	string nombres[] = {"Juan", "Maria", "Pedro", "Felipe"};
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 3);
	return nombres[dis(gen)];
}

string generar_apellido_aleatorio() {
	string apellidos[] = {"Perez", "Flor", "Vaca", "Peralta"};
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 3);
	return apellidos[dis(gen)];
}

string generar_direccion_aleatoria() {
	string direcciones[] = {"Av. Beni", "Calle Sucre", "Av. 6 de Agosto", "Calle Ballivian", "Av. America", "Calle Mercado", "Av. Santa Cruz", "Calle Junin", "Av. Buenos Aires", "Calle Chuquisaca"};
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 9);
	return direcciones[dis(gen)];
}

string generar_carrera_aleatoria() {
	string carreras[] = {"Ingenieria en Sistemas", "Medicina", "Arquitectura", "Derecho", "Administracion de Empresas", "Economia", "Psicologia", "Contaduria Publica", "Ciencias de la Computacion", "Comunicacion Social"};
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 9);
	return carreras[dis(gen)];
}

int main() {
	const int num_estudiantes = 20;
	vector<estudiante> estudiantes(num_estudiantes);
	
	int opcion;
	do {
		cout << "Menu:" << endl;
		cout << "1. Llenar datos" << endl;
		cout << "2. Imprimir" << endl;
		cout << "3. Buscar " << endl;
		cout << "4. Salir" << endl;
		cout << "Ingrese opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1: {
			int indice;
			cout << "Ingrese el indice del estudiante (0-" << num_estudiantes - 1 << "): ";
			cin >> indice;
			if (indice < 0 || indice >= num_estudiantes) {
				cout << "Indice invalido. Debe estar entre 0 y " << num_estudiantes - 1 << "." << endl;
				break;
			}
			string nombre = generar_nombre_aleatorio() + " " + generar_apellido_aleatorio();
			string direccion = generar_direccion_aleatoria();
			string carrera = generar_carrera_aleatoria();
			
			estudiantes[indice].set_nombre(nombre);
			estudiantes[indice].set_direccion(direccion);
			estudiantes[indice].set_cod_estudiante(estudiantes[indice].generar_codigo_estudiante());
			estudiantes[indice].set_carrera(carrera);
			break;
		}
		case 2: {
			cout << "Datos de los estudiantes:" << endl;
			for (int i = 0; i < num_estudiantes; ++i) {
				cout << "Estudiante " << i + 1 << ":" << endl;
				estudiantes[i].mostrarDatos();
				cout << endl;
			}
			break;
		}
		case 3: {
			string direccion_parcial;
			cout << "Ingrese una parte de la dirección a buscar: ";
			cin.ignore();
			getline(cin, direccion_parcial);
			
			bool encontrado = false;
			cout << "Estudiantes encontrados con dirección parcial '" << direccion_parcial << "':" << endl;
			for (int i = 0; i < num_estudiantes; ++i) {
				if (estudiantes[i].get_direccion().find(direccion_parcial) != string::npos) {
					estudiantes[i].mostrarDatos();
					cout << endl;
					encontrado = true;
				}
			}
			if (!encontrado) {
				cout << "Ningun estudiante encontrado con esa parte de la dirección." << endl;
			}
			break;
		}
		case 4:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opcion invalida. Por favor, ingrese una opcion valida." << endl;
		}
	} while (opcion != 4);
	
	return 0;
}
