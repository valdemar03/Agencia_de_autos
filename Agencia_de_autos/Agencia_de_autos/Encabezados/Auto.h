#pragma once
#include <iostream>
#include <string>
using namespace::std;

class Auto
{
	private:
		int id;
		string marca;
		string modelo;
		int fechaFabricacion;
		float precio;

	public:
		Auto(int _id, string _marca, string _modelo, int _fechaFabricacion, float _precio)
		{
			this->id = _id;
			this->marca = _marca;
			this->modelo = _modelo;
			this->fechaFabricacion = _fechaFabricacion;
			this->precio = _precio;
		}
		~Auto()
		{

		}
		void mostrarAuto();
};
		