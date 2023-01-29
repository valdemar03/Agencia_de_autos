#include <iostream>
#include <fstream>
#include "Encabezados/Auto.h"
using namespace::std;

void menu();
void archivo();

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
				archivo();
				break;
			case 2:

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
				cout << "Gracias por visitarnos" << endl;
				break;
			default: 
				cout << "Opcion incorrecta" << endl;
		}

	} while (opcion != 8);
}
void archivo()
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
		while (archivo >> datos)
		{
			cout << datos;
			cout << endl;
		}
	}
	cout << endl;
	system("pause");
	archivo.close();
}