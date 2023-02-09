#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>	
using namespace::std;

class Auto
{
	private:
		fstream archivo;
		struct Automovil
		{
			int id;
			string marca;
			string modelo;
			int fechaFabricacion;
			float precio;
		}automovil, autos[100];
	public:
		Auto()
		{

		}
		~Auto()
		{

		}
		void verCatalogo(int& contadorAuto)
		{
			string datos;
			int i = 0;

			if (!archivo.is_open())
			{
				cout << "Error al abrir Catalogo.txt\n";
				exit(EXIT_FAILURE);
			}
			else
			{
				system("cls");
				while (getline(archivo, datos))
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
		}
		void agregarAuto()
		{
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
		}
		void buscarAuto()
		{
			string datos;
			int id;

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
		}
		void modificarAuto(int& contadorAuto)
		{
			string datos;
			int id, iAutos = 0, iAutosNuevos = 0;
			contadorAuto = 0;
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
					if (stoi(datos) <= id)
					{
						contadorAuto++;
					}

					autos[iAutos].id = stoi(datos);

					getline(archivo, datos);
					autos[iAutos].marca = datos;

					getline(archivo, datos);
					autos[iAutos].modelo = datos;

					getline(archivo, datos);
					autos[iAutos].fechaFabricacion = stoi(datos);

					getline(archivo, datos);
					autos[iAutos].precio = stof(datos);

					getline(archivo, datos);
					iAutos++;
					iAutosNuevos++;
				}
				archivo.close();
				rename("Catalogo.txt", "Catalogo_1.txt");

				ofstream archivo2("Catalogo.txt", ios::app);
				if (!archivo2.is_open())
				{
					cout << "Error al abrir Catalogo.txt\n";
					exit(EXIT_FAILURE);
				}
				else
				{
					for (int i = 0; i < iAutosNuevos; i++)
					{
						if (i == contadorAuto - 1)
						{
							automovil.id = id;

							cin.ignore();

							cout << "Nueva Marca: ";
							getline(cin, automovil.marca);

							cout << "Nueva Modelo: ";
							getline(cin, automovil.modelo);

							cout << "Nueva Fecha de fabricacion: ";
							cin >> automovil.fechaFabricacion;

							cout << "Nueva Precio: ";
							cin >> automovil.precio;

							archivo2 << automovil.id << endl;
							archivo2 << automovil.marca << endl;
							archivo2 << automovil.modelo << endl;
							archivo2 << automovil.fechaFabricacion << endl;
							archivo2 << automovil.precio << endl;
							archivo2 << endl;
						}
						else
						{
							archivo2 << autos[i].id << endl;
							archivo2 << autos[i].marca << endl;
							archivo2 << autos[i].modelo << endl;
							archivo2 << autos[i].fechaFabricacion << endl;
							archivo2 << autos[i].precio << endl;
							archivo2 << endl;
						}
					}
				}
				cout << endl;
				system("pause");
				archivo2.close();
				remove("Catalogo_1.txt");
			}
		}
		void eliminarAuto(int& contadorAuto)
		{
			string datos;
			int id, iAutos = 0, iAutosNuevos = 0;
			contadorAuto = 0;

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
					if (stoi(datos) <= id)
					{
						contadorAuto++;
					}

					autos[iAutos].id = stoi(datos);

					getline(archivo, datos);
					autos[iAutos].marca = datos;

					getline(archivo, datos);
					autos[iAutos].modelo = datos;

					getline(archivo, datos);
					autos[iAutos].fechaFabricacion = stoi(datos);

					getline(archivo, datos);
					autos[iAutos].precio = stof(datos);

					getline(archivo, datos);
					iAutos++;
					iAutosNuevos++;
				}
				archivo.close();
				rename("Catalogo.txt", "Catalogo_1.txt");

				ofstream archivo2("Catalogo.txt", ios::app);
				if (!archivo2.is_open())
				{
					cout << "Error al abrir Catalogo.txt\n";
					exit(EXIT_FAILURE);
				}
				else
				{
					for (int i = 0; i < iAutosNuevos; i++)
					{
						if (i == contadorAuto - 1)
						{
							continue;
						}
						else
						{
							archivo2 << autos[i].id << endl;
							archivo2 << autos[i].marca << endl;
							archivo2 << autos[i].modelo << endl;
							archivo2 << autos[i].fechaFabricacion << endl;
							archivo2 << autos[i].precio << endl;
							archivo2 << endl;
						}
					}
				}
				cout << endl;
				system("pause");
				archivo2.close();
				remove("Catalogo_1.txt");
			}
		}
		void renombrarArchivo(const char* ruta, const char* rutaNueva)
		{
			rename(ruta, rutaNueva);
		}
		void eliminarArchivo(const char* ruta)
		{
			remove(ruta);
		}
		void abrirArchivo(string ruta)
		{
			this->archivo.open(ruta, ios::in | ios::out | ios::app);
		}
		void cerrarArchivo()
		{
			this->archivo.close();
		}
};
		