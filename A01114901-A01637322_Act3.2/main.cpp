//Implementacion de los algoritmos Dijkstra and Floyd
//30 de Septiembre del 2021
//Luis Armando Salazar Lopez A01114901
//Carlos Moises Chavez Jimenez A01637322
#include <iostream>
#include <vector>

using namespace std;

//Funcion que imprime la matriz resuelta completa. Recibe la matriz y la longitud de sus lados.
//Complejidad: O(n) siendo n cada item de la matriz.
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

//Función que implementa el algoritmo de Floyd para encontrar la menor
//distancia entre dos vertices unidos por aristas con peso.
//El grafo será representado por una matriz, donde, cada fila y columna representara
//un vertice. Cada representará el peso que hay en la arista que une el vertice de la fila
//con el de la columna. Cuando la celda tiene un 0, significa que el vertice de la fila es
//igual al vertice de la columna. Cuando la celda tiene un -1, significa que el vertice de
//la fila o de la columna no tiene arista directamente conectada con el otro vertice. Cualquier
//otro numero que tenga la celda representa el peso de la arista que une ambos vertices.

//Complejidad: O(n^3) donde n es el número de vertices del grafo
void algFloyd(int n, vector<vector<int>> &matriz)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                //Filtramos las celdas que marcan infinito porque indican que no hay arista entre los vertices.
                if (matriz[j][i] != -1 && matriz[i][k] != -1)
                {
                    //Sumamos el peso de dos aristas conectadas para verificar si la sumatoria es menor
                    //al peso que está marcado en la celda objetivo.
                    //Nota: En caso de que la celda a compoarar este marcada como infinito, directamente se
                    //va a sustituir con la sumatoria. Esto porque la condicional if anterior nos inidico
                    //que existe un camino con más de una arista hacia el vertice objetivo.
                    if ((matriz[j][i] + matriz[i][k] < matriz[j][k]) || matriz[j][k] == -1)
                    {
                        //Si el peso que se obtiene de la suma de ambas aristas es menor al marcado en la celda,
                        //entonces se subsituye por la sumatoria.
                        matriz[j][k] = matriz[j][i] + matriz[i][k];
                    }
                }
            }
        }
    }
    imprimir(n, matriz);
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