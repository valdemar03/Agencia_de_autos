#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include "Encabezados/Auto.h"
using namespace::std;

int contadorAuto = 0;

struct Automovil
{
	int id;
	string marca;
	string modelo;
	int fechaFabricacion;
	float precio;
}automovil, autos[100];

Auto* archivo = new Auto();

void menu();
void menuAuto();
void compraAutos();
void historialVentas();
void historialVendedor();
void historialComprador();

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
		cout << "4.- Ver historial de ventas" << endl;
		cout << "5.- Ver historial de vendedor" << endl;
		cout << "6.- Ver historial de comprador" << endl;
		cout << "7.- Salir" << endl;
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
				compraAutos();
				break;
			case 3:
				menuAuto();
				break;
			case 4:
				historialVentas();
				break;
			case 5:
				historialVendedor();
				break;
			case 6:
				historialComprador();
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

	} while (opcion != 7);
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
void compraAutos()
{
	string datos, nombreComprador, nombreVendedor;
	int id, largo;

	ifstream archivo("Catalogo.txt");

	if (!archivo.is_open())
	{
		cout << "Error al abrir Catalogo.txt\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		system("cls");
		cout << "Ingrece el id del auto para vender: ";
		cin >> id;

		while (getline(archivo, datos))
		{
			if (stoi(datos) == id)
			{
				cout << "ID: " << datos << endl;
				automovil.id = stoi(datos);
				getline(archivo, datos);
				cout << "Marca: " << datos << endl;
				automovil.marca = datos;
				getline(archivo, datos);
				cout << "Modelo: " << datos << endl;
				automovil.modelo = datos;
				getline(archivo, datos);
				cout << "Fecha de fabricacion: " << datos << endl;
				automovil.fechaFabricacion = stoi(datos);
				getline(archivo, datos);
				cout << "Precio: $" << datos << endl << endl;
				automovil.precio = stof(datos);
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
	archivo.close();

	ofstream archivo2("Historial_de_ventas.txt",ios::app);
	
	if (!archivo2.is_open())
	{
		cout << "Error al abrir Historial_de_ventas.txt\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		cin.ignore();
		cout << "Ingrece el nombre del vendedor: ";
		getline(cin, nombreVendedor);
		cout << "Ingrece el nombre del comprador: ";
		getline(cin, nombreComprador);

		largo = nombreComprador.size();
		for (int i = 0; i < largo; i++)
		{
			nombreComprador[i] = toupper(nombreComprador[i]);
		}

		largo = nombreVendedor.size();
		for (int i = 0; i < largo; i++)
		{
			nombreVendedor[i] = toupper(nombreVendedor[i]);
		}

		//archivo2 << automovil.id << endl;
		archivo2 << automovil.marca << endl;
		archivo2 << automovil.modelo << endl;
		archivo2 << automovil.fechaFabricacion << endl;
		archivo2 << automovil.precio << endl;
		archivo2 << nombreVendedor << endl;
		archivo2 << nombreComprador << endl;
		archivo2 << endl;

	}
	cout << endl;
	system("pause");
	archivo2.close();
}
void historialVentas()
{
	string datos;

	ifstream archivo("Historial_de_ventas.txt");

	if (!archivo.is_open())
	{
		cout << "Error al abrir Historial_de_ventas.txt\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		system("cls");
		while (getline(archivo, datos))
		{
			//cout << "ID: " << datos << endl;

			//getline(archivo, datos);
			cout << "Marca: " << datos << endl;

			getline(archivo, datos);
			cout << "Modelo: " << datos << endl;

			getline(archivo, datos);
			cout << "Fecha de fabricacion: " << datos << endl;

			getline(archivo, datos);
			cout << "Precio: $" << datos << endl;

			getline(archivo, datos);
			cout << "Vendedor: " << datos << endl;

			getline(archivo, datos);
			cout << "Comprador: " << datos << endl << endl;

			getline(archivo, datos);
		}
	}
	cout << endl;
	system("pause");
	archivo.close();
}
void historialVendedor()
{
	string datos, nombreComprador, nombreVendedor, buscarNombreVendedor;
	int largo, iautos = 0;

	ifstream archivo("Historial_de_ventas.txt");

	if (!archivo.is_open())
	{
		cout << "Error al abrir Historial_de_ventas.txt\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		system("cls");
		cin.ignore();
		cout << "Ingrece el nombre del vendedor: ";
		getline(cin, buscarNombreVendedor);

		largo = buscarNombreVendedor.size();
		for (int i = 0; i < largo; i++)
		{
			buscarNombreVendedor[i] = toupper(buscarNombreVendedor[i]);
		}

		while (!archivo.eof())
		{
			getline(archivo, datos);
			automovil.marca = datos;
			getline(archivo, datos);
			automovil.modelo = datos;
			getline(archivo, datos);
			getline(archivo, datos);
			getline(archivo, datos);
			if (datos == buscarNombreVendedor)
			{
				iautos++;
				cout << "Auto " << iautos << endl;
				cout << "Marca: " << automovil.marca << endl;
				cout << "Modelo: " << automovil.modelo << endl;
				cout << endl;
			}
			else
			{
				
			}
			getline(archivo, datos);
			getline(archivo, datos);
		}
	}
	cout << endl;
	system("pause");
	archivo.close();
}
void historialComprador()
{
	string datos, nombreComprador, nombreVendedor, buscarNombreComprador;
	int largo, iautos = 0;

	ifstream archivo("Historial_de_ventas.txt");

	if (!archivo.is_open())
	{
		cout << "Error al abrir Historial_de_ventas.txt\n";
		exit(EXIT_FAILURE);
	}
	else
	{
		system("cls");
		cin.ignore();
		cout << "Ingrece el nombre del comprador: ";
		getline(cin, buscarNombreComprador);

		largo = buscarNombreComprador.size();
		for (int i = 0; i < largo; i++)
		{
			buscarNombreComprador[i] = toupper(buscarNombreComprador[i]);
		}

		while (!archivo.eof())
		{
			getline(archivo, datos);
			automovil.marca = datos;
			getline(archivo, datos);
			automovil.modelo = datos;
			getline(archivo, datos);
			getline(archivo, datos);
			getline(archivo, datos);
			getline(archivo, datos);
			if (datos == buscarNombreComprador)
			{
				iautos++;
				cout << "Auto " << iautos << endl;
				cout << "Marca: " << automovil.marca << endl;
				cout << "Modelo: " << automovil.modelo << endl;
				cout << endl;
			}
			else
			{

			}
			getline(archivo, datos);
		}
	}
	cout << endl;
	system("pause");
	archivo.close();
}