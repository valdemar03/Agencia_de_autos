#include <iostream>
#include <fstream>
#include "Encabezados/Auto.h"
using namespace::std;

void menu();
void verCatalogo();
void agregarAuto();

struct Automovil
{
	int id;
	string marca;
	string modelo;
	int fechaFabricacion;
	float precio;
}automovil;

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
		cout << "2.- Agregar auto" << endl;
		cout << "3.- Agregar usuario" << endl;
		cout << "4.- Agregar vendedor" << endl;
		cout << "5.- Ver historial de ventas" << endl;
		cout << "6.- Ver historial de vendedor" << endl;
		cout << "7.- Ver historial de comprador" << endl;
		cout << "8.- Salir" << endl;
		cout << "Opcion: ";
		cin >> opcion;

		switch (opcion)
		{
			case 1:
				verCatalogo();
				break;
			case 2:
				agregarAuto();
				break;
			case 3:

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
				cout << "\nGracias por visitarnos" << endl;
				break;
			default: 
				cout << "Opcion incorrecta" << endl;
		}

	} while (opcion != 8);
}
void verCatalogo()
{
	string datos;

	ifstream archivo("Catalogo.txt");
	if (!archivo.is_open())
	{
		cout << "Error al abrir Catalogo.txt\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		system("cls");
		while (archivo >> datos)
		{
			cout << "ID: " << datos << endl;
			archivo >> datos;
			cout << "Marca: " << datos << endl;
			archivo >> datos;
			cout << "Modelo: " << datos << endl;
			archivo >> datos;
			cout << "Fecha de fabricacion: " << datos << endl;
			archivo >> datos;
			cout << "Precio: " << datos << endl << endl;
		}
	}
	cout << endl;
	system("pause");
	archivo.close();
}
void agregarAuto()
{
	ofstream archivo("Catalogo.txt", ios::app);
	if (!archivo.is_open())
	{
		cout << "Error al abrir Catalogo.txt\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		system("cls");
		cout << "ID: ";
		cin >> automovil.id;

		cout << "Marca: ";
		cin >> automovil.marca;

		cout << "Modelo: ";
		cin >> automovil.modelo;

		cout << "Fecha de fabricacion: ";
		cin >> automovil.fechaFabricacion;

		cout << "Precio: ";
		cin >> automovil.precio;

		archivo << automovil.id << endl;
		archivo << automovil.marca << endl;
		archivo << automovil.modelo << endl;
		archivo << automovil.fechaFabricacion << endl;
		archivo << automovil.precio << endl;
		archivo << endl;
	}
	cout << endl;
	system("pause");
	archivo.close();
}