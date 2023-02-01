#include <iostream>
#include <fstream>
#include <string>
#include "Encabezados/Auto.h"
using namespace::std;

void Auto::mostrarAuto()
{
	cout << "ID:" << id << endl;
	cout << "Marca: " << marca << endl;
	cout << "Modelo: " << modelo << endl;
	cout << "Fecha de fabricacion: " << fechaFabricacion << endl;
	cout << "Precio: " << precio << endl;
}
