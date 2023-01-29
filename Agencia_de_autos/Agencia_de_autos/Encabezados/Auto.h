#pragma once
#include <iostream>
#include <string>
using namespace::std;

class Auto
{
	private:
		string marca;
		string modelo;
		int fechaFabricacion;
		float precio;

	public:
		Auto(string _marca, string _modelo, int _fechaFabricacion, float _precio)
		{
			this->marca = _marca;
			this->modelo = _modelo;
			this->fechaFabricacion = _fechaFabricacion;
			this->precio = _precio;
		}
		~Auto()
		{

		}
		void mostrarAuto()
		{
			cout << "Marca: " << marca << endl;
			cout << "Modelo: " << modelo << endl;
			cout << "Fecha de fabricacion: " << fechaFabricacion << endl;
			cout << "Precio: " << precio << endl;
		}
};
		