//Implementacion de los algoritmos Dijkstra and Floyd
//30 de Septiembre del 2021
//Luis Armando Salazar Lopez A01114901
//Carlos Moises Chavez Jimenez A01637322
#include <iostream>
#include <vector>

using namespace std;

//Funcion que imprime la matriz resuelta completa. Recibe la matriz y sus dimensiones
//Complejidad: O(n) siendo n cada nodo de la matriz.
void imprimir(int n, vector<vector<int>> &final)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << final[i][j] << " ";
        }
        cout << endl;
    }
}

//Complejidad: O()
void algDijkstra(int n, vector<vector<int>> &matriz)
{
}

//Complejidad: O()
void algFloyd(int n, vector<vector<int>> &matriz)
{
}

int main()
{
    int n = 0;
    cin >> n;
    //Vectores para llenar la matriz.
    int espacio;
    vector<int> col;
    vector<vector<int>> row;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> espacio;
            col.push_back(espacio);
        }
        row.push_back(col);
        col.clear();
    }
    //Pasamos la matriz a las funciones correspondientes
    cout << "Dijkstra :" << endl;
    algDijkstra(n, row);
    cout << "Floyd :" << endl;
    algFloyd(n, row);
    return 0;
}
