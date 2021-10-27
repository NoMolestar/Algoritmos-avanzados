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

//Funcion 1
//Complejidad: O()
void cableadoFun1(int n,vector<vector<int>> &distancia, int source)
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

//Funcion 2
//Complejidad: O()
void rutaFun2(vector<vector<int>> &distancia, int n)
{
}

//Funcion 3
//Complejidad: O()
void flujoFun3(vector<vector<int>> &datos, int n)
{
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
    file.close();                      //Cierra el archivo
    for(int i=0;i<colonias;i++){
        cableadoFun1(colonias,distancia,i);
    }
     //Llamamos a la funcion que mostrara el cableado de las colonias
    rutaFun2(distancia, colonias);     //Llamamos a la funcion que muestra la ruta a seguir por el personal
    flujoFun3(capacidad, colonias);    //Llamamos a la funcion que muestra el valor del flujo maximo
}




int main()
{
    string input = "caso1.txt";
    leerArchivo(input);
    return 0;
}