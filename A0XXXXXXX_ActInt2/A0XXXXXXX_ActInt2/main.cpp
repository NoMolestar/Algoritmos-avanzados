/*
09 de Noviembre del 2021
Actividad Integradora 2
Luis Armando Salazar Lopez A01114901
Carlos Moises Chavez Jimenez A01637322
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

//Función que imprime la matriz resuelta completa. Recibe la matriz y sus dimensiones
//Complejidad: O(n) siendo n cada nodo de la matriz.
void imprimir(vector<vector<int>> &final, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << final[i][j] << " ";
        }
        cout << endl;
    }
}

int INF = 999999;

//Funcion 1 : Algoritmo Dijkstra
//Complejidad: O(n^2) donde n es la cantidad de vertices
void cableadoFun1(int n, vector<vector<int>> &distancia, int source)
{
    //Complejidad: O(n^2) donde n es la cantidad de vertices

    vector<vector<int>> resultados = distancia;
    vector<int> visitados(n, 0); //vector para saber que vertices ya se han visitado
    vector<int> recorrido(n, INF);
    bool inicio = true; //establecemos una variable booleana de inicio para saber si podemos agregar la distancia al source
    int i = source;     //indicador de en que vertice se revisan las conexiones
    int v = 0;          //distancia al source
    int count = 0;      //contador para saber cuando hemos visitado todos los vertices
    while (count < n)
    {
        visitados[i] = 1;
        if (inicio)
        {
            inicio = false;
        }
        else
        {
            v = recorrido[i];
        }

        for (int j = 0; j < n; j++)
        { //funcion para actualizar los recorridos que se encuentren o se encuentren en menor peso(relaxation)
            if (i != j && j != source)
            {
                if ((resultados[i][j] + v) < recorrido[j] && resultados[i][j] >= 0)
                {
                    recorrido[j] = resultados[i][j] + v;
                }
            }
        }
        int min = INF;
        for (int h = 0; h < n; h++)
        { //funcion para encontrar la distancia menor y no visitada

            if (visitados[h] == 0 && recorrido[h] < min)
            {
                min = recorrido[h];
                i = h;
            }
        }
        count++;
    }

    //imprimir recorrido
    for (int k = 0; k < n; k++)
    {
        if (k != source && recorrido[k] != INF)
        {
            cout << "node " << source + 1 << " to node " << k + 1 << " : " << recorrido[k] << endl;
        }
    }
}

int minDistance(int dist[], bool sptSet[])
{

    // Initialize min value
    int min = INT_MAX, min_index;

    for (int v = 0; v < 4; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[])
{
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < 4; i++)
        cout << i << " \t\t" << dist[i] << endl;
}

//Funcion 2 : Algoritmo Floyd
//Complejidad: O(n^3) donde n es el número de vertices del grafo
void rutaFun2(vector<vector<int>> &matriz, int n)
{
    int dist[n]; // The output array.  dist[i] will hold the shortest
    // distance from src to i

    bool sptSet[n]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < n; i++)
        dist[i] = INT_MAX, sptSet[i] = false;

    // Distance of source vertex from itself is always 0
    dist[0] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++)
    {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDistance(dist, sptSet);

        // Mark the picked vertex as processed
        sptSet[u] = true;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < n; v++)

            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && matriz[u][v] && dist[u] != INT_MAX && dist[u] + matriz[u][v] < dist[v])
                dist[v] = dist[u] + matriz[u][v];
    }
    printSolution(dist);
}

//Funcion 3
//Complejidad: O(n^3) donde n es el número de vertices del grafo
void flujoFun3(vector<vector<int>> &matriz, int n)
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
    imprimir(matriz, n);
}

//Funcion que lee un archivo de texto (recibe el nombre como parametro) y regresa
//el string completo del contenido del archivo.
//Complejidad: O(n) donde n es el número de caracteres del archivo.
void leerArchivo(const string &name)
{
    ifstream file;
    string renglon;
    string texto;
    vector<vector<int>> distancia;
    vector<vector<int>> capacidad;
    vector<string> coordenadas;
    vector<int> aux;
    int colonias = 0;
    file.open(name, ios::in); //Instruccion que lee un archivo de texto.
    if (file.fail())
    { //Si no encuentra el archivo, regresa un mensaje de error.
        cout << "No se pudo abrir el archivo";
    }
    else
    {
        getline(file, renglon); //Obtiene cadenas de cada renglon.
        colonias = atoi(renglon.c_str());
        for (int i = 0; i < colonias; i++)
        {
            stringstream ss;        //Variable que nos ayudara a quitar los espacios de una cadena
            getline(file, renglon); //Obtiene cadenas de cada renglon.
            ss << renglon;          //Le pasamos la cadena a la variable
            string res;
            while (ss >> res) //Obtenemos cada valor que no sea un espacio
            {
                aux.push_back(atoi(res.c_str())); //Le agregamos al final del vector cada numero que obtenemos
            }
            distancia.push_back(aux); //Agregamos el vector a la matriz principal
            aux.clear();              //Dejamos el vector en blanco
        }
        for (int i = 0; i < colonias; i++)
        {
            stringstream ss;        //Variable que nos ayudara a quitar los espacios de una cadena
            getline(file, renglon); //Obtiene cadenas de cada renglon.
            ss << renglon;          //Le pasamos la cadena a la variable
            string res;
            while (ss >> res) //Obtenemos cada valor que no sea un espacio
            {
                aux.push_back(atoi(res.c_str())); //Le agregamos al final del vector cada numero que obtenemos
            }
            capacidad.push_back(aux); //Agregamos el vector a la matriz principal
            aux.clear();              //Dejamos el vector en blanco
        }
        for (int i = 0; i < colonias; i++)
        {
            getline(file, renglon); //Obtiene cadenas de cada renglon.
            coordenadas.push_back(renglon);
        }
    }
    file.close(); //Cierra el archivo
    for (int i = 0; i < colonias; i++)
    {
        cableadoFun1(colonias, distancia, i);
    }
    //Llamamos a la funcion que mostrara el cableado de las colonias
    rutaFun2(distancia, colonias);  //Llamamos a la funcion que muestra la ruta a seguir por el personal
    flujoFun3(capacidad, colonias); //Llamamos a la funcion que muestra el valor del flujo maximo
}

int main()
{
    string input = "caso1.txt";
    leerArchivo(input);
    return 0;
}