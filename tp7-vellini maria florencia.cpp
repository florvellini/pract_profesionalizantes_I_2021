#include <iostream>
#include <string>
#include <fstream>
using namespace std;


const int MAX = 100;
typedef struct{
	string nombre;
	string apellido;
	int año;
}talumno;
typedef talumno tArray[MAX];
typedef struct{
	tArray elementos;
	int contador;
}tLista;

void abrir_archivo(tLista lista);
void mostrar_listados(tLista lista);
void insertar_alumno(tLista lista);
void eliminar_alumno(tLista lista, string alumno);
void guardar_archivo(tLista lista);

int main(){
	tLista lista;
	int opcion;
	string alumno, alumno1;
	abrir_archivo(lista);
	cout << "Menu de operaciones " << endl;
	cout << "1. Listado de alumnos " << endl;
	cout << "2. Insertar un alumno " << endl;
	cout << "3. Eliminar un alumno " << endl;
	cout << "4. Buscar un alumno " << endl;
	cout << "0. Guardar cambios y salir " << endl;

	while(opcion != 0){
	cout << "Ingrese la opcion a elegir: " << endl;
	cin >> opcion;

	switch(opcion){
		case 1: Mostrar_listado(lista);
		break;
		case 2: insertar_alumno(lista);
		break;
		case 3: cout << "Ingrese el nombre del alumno a eliminar: "; cin >> alumno;
		eliminar_alumno(lista,alumno);
		break;
		case 4: cout << "Ingrese el nombre del alumno en busqueda: " << endl; cin >> alumno1; buscar_alumno();
		break;
		case 0; guardar_archivo(lista);
		break;

		default: cout << "Error, ingrese de nuevo la opcion: " << endl;
	}

}

return 0;}
