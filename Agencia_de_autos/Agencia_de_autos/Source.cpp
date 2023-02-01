#include <iostream>
#include <string>
#include <fstream>
#include "Encabezados/Auto.h"
using namespace::std;

int contadorAuto = 0;

void menu();
void menuAuto();
void menuUsuario();
void menuVendedor();
void verCatalogo();
void agregarAuto();
void buscarAuto();
void modificarAuto();
void eliminarAuto();

struct Automovil
{
	int id;
	string marca;
	string modelo;
	int fechaFabricacion;
	float precio;
}automovil,autos[100];

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
				cout << "\nGracias por visitarnos" << endl;
				break;
			default: 
				cout << "Opcion incorrecta" << endl;
		}

	} while (opcion != 8);
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
				agregarAuto();
				break;
			case 2:
				buscarAuto();
				break;
			case 3:
				//modificarAuto();
				break;
			case 4:
				//eliminarAuto();
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
void verCatalogo()
{
	string datos;
	int i = 0;

	ifstream archivo("Catalogo.txt");
	if (!archivo.is_open())
	{
		cout << "Error al abrir Catalogo.txt\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		system("cls");
		while (getline(archivo,datos))
		{
			autos[i].id = stoi(datos);
			cout << "ID: " << datos << endl;

			getline(archivo, datos);
			autos[i].modelo = datos;
			cout << "Marca: " << datos << endl;

			getline(archivo, datos);
			autos[i].marca = datos;
			cout << "Modelo: " << datos << endl;

			getline(archivo, datos);
			autos[i].fechaFabricacion = stoi(datos);
			cout << "Fecha de fabricacion: " << datos << endl;

			getline(archivo, datos);
			autos[i].precio = stof(datos);
			cout << "Precio: $" << datos << endl << endl;

			getline(archivo, datos);
			i++;
			contadorAuto++;
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

		cin.ignore();

		cout << "Marca: ";
		getline(cin, automovil.marca);

		cout << "Modelo: ";
		getline(cin, automovil.modelo);

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
void buscarAuto()
{
	string datos;
	int id;

	ifstream archivo("Catalogo.txt");
	if (!archivo.is_open())
	{
		cout << "Error al abrir Catalogo.txt\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		system("cls");
		cout << "Ingrece el id del auto: ";
		cin >> id;

		while (getline(archivo, datos))
		{
			if (stoi(datos) == id)
			{
				cout << "ID: " << datos << endl;

				getline(archivo, datos);
				cout << "Marca: " << datos << endl;

				getline(archivo, datos);
				cout << "Modelo: " << datos << endl;

				getline(archivo, datos);
				cout << "Fecha de fabricacion: " << datos << endl;

				getline(archivo, datos);
				cout << "Precio: $" << datos << endl << endl;

				getline(archivo, datos);
			}
			else
			{
				for (int i = 0; i < 5; i++)
				{
					getline(archivo, datos);
				}
			}
		}
	}
	cout << endl;
	system("pause");
	archivo.close();
}
void modificarAuto()
{

}
void eliminarAuto()
{

}