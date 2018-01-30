#include <iostream>

using namespace std;

int arreglo[100];

void createArray()
{
	for (int i = 0; i < 100; i++)
	{
		arreglo[i] = i + 2;
	}
}

void searchArraySec(int x)
{
	for (int i = 0; i < 100; i++)
	{
		if (x == arreglo[i])
		{
			cout << "El numero " << x << " se encuentra en la posicion: " << i << endl;
			return;
		}
	}
	cout << "El numero no se encuentra dentro del arreglo";
}

void searchArrayBin(int x, int pivote, int inicio, int finaliza)
{
	if (arreglo[pivote] == x)
	{
		cout << "El numero " << x << " se encuentra en la posicion: " << pivote << " del arreglo." << endl;
		return;
	}
	if (x < arreglo[pivote])
	{
		finaliza = pivote;
		pivote = finaliza / 2;
		searchArrayBin(x, pivote, inicio, finaliza);
	}
	if (x > arreglo[pivote])
	{
		inicio = pivote;
		pivote = (inicio + finaliza) / 2;
		searchArrayBin(x, pivote, inicio, finaliza);
	}
	if (pivote == inicio && pivote == finaliza && arreglo[pivote] != x)
	{
		cout << "El numero que busca no se encuentra dentro del arreglo" << endl;
	}
}

int main()
{
	createArray();
	int inicio = 0;
	int finaliza = 99;
	int pivote = finaliza / 2;
	int opcion = 0;
	int x;

	cout << "Ingrese el numero que desea buscar: " << endl;
	cin >> x;

	cout << "\n1 - Busqueda secuencial";
	cout << "\n2 - Busqueda binaria";
	cout << "\nEscoga el metodo de busqueda: " << endl << endl;
	cin >> opcion;


	if (opcion == 1)
		searchArraySec(x);
	if (opcion == 2)
		searchArrayBin(x, pivote, inicio, finaliza);

}
