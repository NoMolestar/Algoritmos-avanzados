/*
09 de Noviembre del 2021
Actividad Integradora 2
Luis Armando Salazar Lopez A01114901
Carlos Moises Chavez Jimenez A01637322
*/

// La ultima funcion (4) del programa la realizamos en un archivo de python por separado

#include <iostream>
#include <string>
#include <cstdlib>
#include <string.h>
#include <fstream>
#include <vector>
#include <sstream>
#include <limits.h>
#include <queue>

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
            cout << "De la colonia " << source + 1 << " a la colonia " << k + 1 << " : " << recorrido[k] << "KM de cableado. " << endl;
        }
    }
}

//Algoritmo Agente Viajero
//Complejidad: O()
void rutaFun2(int n, vector<vector<int>> &distancia, int source)
{
}

//Funcion auxiliar que regresa
//Complejidad: O(n) donde n es el numero de vertices del grafo.
bool auxFun3(vector<vector<int>> &rGraph, int s, int t, vector<int> &parent, int n)
{
    vector<bool> visited(n, 0);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (visited[v] == false && rGraph[u][v] > 0)
            {
                if (v == t)
                {
                    parent[v] = u;
                    return true;
                }
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return false;
}

//Funcion 3 : Algoritmo Ford-Fulkerson
//Complejidad: O(n^3) donde n es el número de vertices del grafo
void flujoFun3(vector<vector<int>> &graph, int s, int t, int n)
{
    int u;
    int v;
    vector<int> minGraph(n, 0);
    vector<vector<int>> rGraph(n, minGraph);
    for (u = 0; u < n; u++)
    {
        for (v = 0; v < n; v++)
        {
            rGraph[u][v] = graph[u][v];
        }
    }
    vector<int> parent(n, 0);
    int max_flow = 0;
    while (auxFun3(rGraph, s, t, parent, n))
    {
        int path_flow = INF;
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (v = t; v != s; v = parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    cout << endl
         << "- Funcion 3" << endl;
    cout << "El flujo maximo es: " << max_flow << endl;
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
    }
    file.close(); //Cierra el archivo
    cout << endl
         << "- Funcion 1" << endl;
    for (int i = 0; i < colonias; i++)
    {
        cableadoFun1(colonias, distancia, i);
    }
    //Llamamos a la funcion que mostrara el cableado de las colonias
    //rutaFun2(distancia, colonias); //Llamamos a la funcion que muestra la ruta a seguir por el personal
    flujoFun3(capacidad, 0, colonias - 1, colonias);
}

int main()
{
    string input = "caso1.txt";
    leerArchivo(input);
    return 0;
}