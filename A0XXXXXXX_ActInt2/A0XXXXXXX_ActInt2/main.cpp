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

//Función auxiliar que utiliza recursividad para regresar el número de valores de la mochila correspondientes
//con el peso de los elementos y el peso maximo.
//Complejidad: 0(2^n) siendo n el numero de elementos en la mochila.
int auxMochila(vector<int> &valores, vector<int> &pesos, int pesoMax, int size)
{
    //Si el peso maximo es más pequeño que cero, regresamos un número negativo grande para indicar
    //que se ha superado el limite de peso.
    if (pesoMax < 0)
    {
        return -9999999;
    }
    //Si se ha alcanzado el limite de peso, o bien, se ha alcanzado el total de numero de elementos, se regresa 0.
    if (size < 0 || pesoMax == 0)
    {
        return 0;
    }
    else
    {
        //Agregamos el valor a la mochila y le sumamos el valor que sigue en el vector llamando a la funcion
        //recursivamente. Esto restandole el peso del valor agregado al peso maximo.
        int agregado = valores[size] + auxMochila(valores, pesos, pesoMax - pesos[size], size - 1);
        //A la par de lo anterior, ignoramos el valor actual y no lo agregamos. Pasamos al siguiente valor
        //enviandolo a la recursividad.
        int noAgregado = auxMochila(valores, pesos, pesoMax, size - 1);
        //Al final comparamos los resultados de ambos procesos recursivos para obtener el máximo de los valores que
        //se obtuvieron dentro de la mochila y sin superar el peso maximo.
        return max(agregado, noAgregado);
    }
}

//Función principal que mandá llamar a la auxiliar que será la que regresará los valores dentro
//de la mochila.
//Complejidad O(1).
void mochila(vector<int> &valores, vector<int> &pesos, int pesoMax, int size)
{
    //Si el numero de valores es 0, o bien, el peso maximo es 0. Entonces solo imprimimos el 0
    if (size == 0 || pesoMax == 0)
    {
        cout << "0" << endl;
    }
    else
    {
        //Llamamos a la funcion auxiliar que nos permitira la recursividad
        cout << endl
             << auxMochila(valores, pesos, pesoMax, size - 1) << endl;
    }
}

//Funcion 2
//Complejidad: O()
void rutaFun2(vector<vector<int>> &matriz, int n)
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