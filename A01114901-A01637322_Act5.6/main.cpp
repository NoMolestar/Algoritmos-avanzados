//Knapsack problem
//25 de octubre del 2021
//Luis Armando Salazar Lopez A01114901
//Carlos Moises Chavez Jimenez A01637322
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

const int MAX = 999999;
const int CIUDADES = 128;

//Complejidad O()
void simulatedA(vector<vector<int>> &valores)
{
}

//Complejidad:
void lecturaArchivo(string nombreFile)
{
    ifstream archivo(nombreFile);
    string linea;
    string aux;
    vector<int> auxCiudades;
    vector<vector<int>> distancias;
    char delimitador = ',';
    // Leemos la primer línea para descartarla, pues es el encabezado
    getline(archivo, linea);
    // Leemos todas las líneas
    while (getline(archivo, linea))
    {
        stringstream stream(linea); // Convertir la cadena a un stream
        for (int i = 0; i < CIUDADES; i++)
        {
            getline(stream, aux, delimitador);
            auxCiudades.push_back(atoi(aux.c_str()));
            cout << aux << ",";
        }
        cout << endl;
        distancias.push_back(auxCiudades);
        auxCiudades.clear();
    }
    simulatedA(distancias);
}

int main()
{
    string nombreFile = "cities_128.csv";
    lecturaArchivo(nombreFile);
    return 0;
}
