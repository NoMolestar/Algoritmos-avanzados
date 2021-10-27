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
    cableadoFun1(distancia, colonias); //Llamamos a la funcion que mostrara el cableado de las colonias
    rutaFun2(distancia, colonias);     //Llamamos a la funcion que muestra la ruta a seguir por el personal
    flujoFun3(capacidad, colonias);    //Llamamos a la funcion que muestra el valor del flujo maximo
}

//Funcion 1
//Complejidad: O()
void cableadoFun1(vector<vector<int>> &distancia, int n)
{
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

int main()
{
    string input = "caso1.txt";
    leerArchivo(input);
    return 0;
}