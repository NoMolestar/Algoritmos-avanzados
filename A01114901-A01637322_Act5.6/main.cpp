//Actividad 5.6 Implementación de Simulated annealing
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

//Función que imprime la matriz resuelta completa. Recibe la matriz y sus dimensiones
//Complejidad: O(n) siendo n cada nodo de la matriz.
void imprimir(vector<vector<int>> &final)
{
    for (int i = 0; i < CIUDADES; i++)
    {
        for (int j = 0; j < CIUDADES; j++)
        {
            cout << final[i][j] << " ";
        }
        cout << endl;
    }
}

//Algoritmo Agente Viajero
//cheapest link
//Complejidad: O(n!) siendo n la cantidad de nodos de la matriz.
void simulatedA(vector<vector<int>> &distancia)
{
    vector<vector<int>> matrizNodos = distancia;
    bool listo = false;
    int suma = 0;
    vector<int> nodoVisitado(CIUDADES, 0);
    vector<vector<int>> solucion(CIUDADES, vector<int>(CIUDADES, 0));
    int i = 0;
    //int contador=0;
    while (!listo)
    {
        // contador++;
        // cout<<"iteracion num: "<<contador<<endl;
        if (nodoVisitado[i] < 2)
        {
            int min = INT_MAX;
            int minPos = INT_MAX;
            bool visita = false;
            for (int j = 0; j < CIUDADES; j++)
            {
                if (i != j && matrizNodos[i][j] < min && matrizNodos[i][j] > 0)
                {
                    if ((nodoVisitado[i] + nodoVisitado[j]) < 2)
                    {
                        min = matrizNodos[i][j];
                        minPos = j;
                        visita = true;
                        // cout<<"intendo de minimo: "<<min<<endl;
                    }
                    else if (nodoVisitado[i] + nodoVisitado[j] == 2 && suma == ((CIUDADES * 2) - 2))
                    {
                        listo = true;
                        min = matrizNodos[i][j];
                        minPos = j;
                        visita = true;
                    }
                }
            }
            if (visita)
            {
                //establecemos la conexion en el vector de visitas y solucion
                solucion[i][minPos] = matrizNodos[i][minPos];
                solucion[minPos][i] = matrizNodos[minPos][i];

                matrizNodos[i][minPos] = 0;
                matrizNodos[minPos][i] = 0;

                nodoVisitado[i]++;
                nodoVisitado[minPos]++;

                suma += 2;
            }

            if (suma == CIUDADES * 2)
            {
                listo = true;
            }
            i = minPos - 1;
        }

        i++;
        if (i == CIUDADES)
        {
            i = 0;
        }
    }

    //comprobacion de solucion

    /*if (listo)
    {
        string alfabeto = "ABCDEFGHIJKLMNOPQRSTUVXYZ";
        cout << endl
             << "- Funcion 2" << endl;
        cout << "La ruta(TSP) es: " << endl;
        int posActual, posAnterior;
        posActual = posAnterior = 0;

        for (int i = 0; i < CIUDADES; i++)
        { //for para desplegar todos los caminos

            for (int j = 0; j < CIUDADES; j++)
            { //for para encontrar una ruta en la solucion ya creada
                if (solucion[posActual][j] > 0 && j != posAnterior && j != posActual)
                {
                    cout << "Desde : colonia " << alfabeto[posActual] << " hacia : colonia " << alfabeto[j] << " valor: " << solucion[posActual][j] << "KM" << endl;
                    posAnterior = posActual;
                    posActual = j;
                    break;
                }
            }
        }
    }
    else
    {
        cout << "Solucion no encontrada" << endl;
    }*/

    //
}

//Funcion que lee y guarda los elementos encontrados dentro del archivo csv
//Complejidad: O(n): siendo n cada elemento dentro del archivo csv
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
        }
        distancias.push_back(auxCiudades);
        auxCiudades.clear();
    }
    simulatedA(distancias);
    //imprimir(distancias);
    archivo.close();
}

int main()
{
    string nombreFile = "cities_128.csv";
    lecturaArchivo(nombreFile);
    return 0;
}
