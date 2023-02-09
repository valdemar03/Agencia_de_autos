#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include "Encabezados/Auto.h"
using namespace::std;

int contadorAuto = 0;

Auto* archivo = new Auto();

void menu();
void menuAuto();
void menuUsuario();
void menuVendedor();

int main()
{
	menu();

	return 0;
}
void menu()
{
	int opcion;

	do
	{
		system("cls");
		cout << "\t.:MENU:." << endl;
		cout << "1.- Catalogo de autos" << endl;
		cout << "2.- Compra de autos" << endl;
		cout << "3.- Editor de autos" << endl;
		cout << "4.- Editor de usuarios" << endl;
		cout << "5.- Editor de vendedores" << endl;
		cout << "6.- Ver historial de autos vendidos" << endl;
		cout << "7.- Ver historial de vendedor" << endl;
		cout << "8.- Ver historial de comprador" << endl;
		cout << "9.- Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion)
		{
			case 1:			
				archivo->abrirArchivo("Catalogo.txt");
				archivo->verCatalogo(contadorAuto);
				archivo->cerrarArchivo();
				break;
			case 2:
				
				break;
			case 3:
				menuAuto();
				break;
			case 4:
				
				break;
			case 5:
				
				break;
			case 6:

				break;
			case 7:

				break;
			case 8:

				break;
			case 9:
				cout << "\nGracias por visitarnos" << endl;
				break;
			default: 
				cout << "Opcion incorrecta" << endl;
		}

	} while (opcion != 9);
}
void menuAuto()
{
	int opcion;

	do
	{
		system("cls");
		cout << "\t.:Editor de autos:." << endl;
		cout << "1.- Agregar auto" << endl;
		cout << "2.- Buscar auto" << endl;
		cout << "3.- Modificar auto" << endl;
		cout << "4.- Eliminar auto" << endl;
		cout << "5.- Salir del editor" << endl;
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion)
		{
			case 1:
				archivo->abrirArchivo("Catalogo.txt");
				archivo->agregarAuto();
				archivo->cerrarArchivo();
				break;
			case 2:
				archivo->abrirArchivo("Catalogo.txt");
				archivo->buscarAuto();
				archivo->cerrarArchivo();
				break;
			case 3:
				archivo->modificarAuto(contadorAuto);
				break;
			case 4:
				archivo->eliminarAuto(contadorAuto);
				break;
			case 5:

				break;
			default:
				cout << "Opcion incorrecta" << endl;
		}
	} while (opcion != 5);

}
void menuUsuario()
{

}
void menuVendedor()
{

}