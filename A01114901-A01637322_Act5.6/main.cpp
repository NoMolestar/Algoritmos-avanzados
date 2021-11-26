//Actividad 5.6 Implementación de Simulated annealing
//25 de noviembre del 2021

//Instituto Tecnológico y de Estudios Superiores de Monterrey
//Ingeniería en Tecnologías Computacionales

//Luis Armando Salazar Lopez A01114901
//Carlos Moises Chavez Jimenez A01637322
//Profesor Gildardo Sánchez Ante

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <time.h>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

const int CIUDADES = 128;
vector<int> ciudades;
vector<bool> flag(CIUDADES, false);
vector<vector<int>> distancias;

//Función que imprime el recorrido con menos costo obtenido.
//Complejidad: O(2n) siendo n el número de ciudades.
void imprimir(vector<int> &final)
{
    cout << "Ciudad origen\t"
         << "Ciudad destino\t"
         << "Costo" << endl;
    for (int i = 0; i < CIUDADES - 1; i++)
    {
        cout << final[i] << "\t\t" << final[i + 1] << "\t\t" << distancias[final[i]][final[i + 1]] << endl;
    }
    cout << final[127] << "\t\t" << final[0] << "\t\t" << distancias[final[127]][final[0]] << endl;
    cout << endl;
}

//Funcion que obtiene el costo del camino propuesto por el vector ciudades.
//Complejidad: O(2n) siendo n el número de ciudades.
int costo(vector<int> &costo)
{
    long c = 0;
    for (int i = 0; i < CIUDADES - 1; i++)
    {
        //Se obtiene la distancia entre las dos ciudades obtenidas
        int x1 = costo[i];
        int x2 = costo[i + 1];
        c += distancias[x1][x2];
    }
    //Agrego la distancia de la colonia final a la inicial
    c += distancias[costo[127]][costo[0]];
    return c;
}

//Función que obtiene un numero random de entre 0 y el número de ciudades - 1
//Y las intercambia dentro del vector del recorrido.
//Complejidad O(1)
void vecinos(vector<int> &aux)
{
    //Obtenemos número random de entre 0 y 127.
    int pick1 = rand() % CIUDADES;
    int pick2 = rand() % CIUDADES;
    swap(aux[pick1], aux[pick2]);
}

//Función que llena el arreglo del recorrido por las ciudades con las mismas ciudades
//acomodadas de manera random.
//Complejidad O(2n) siendo n el número de ciudades.
void llenarArreglo()
{
    srand(time(0));
    int n = 0;
    for (int i = 0; i < CIUDADES; ++i)
    {
        //Obtenemos la ciudad random y verificamos si ya fue visitada
        do
        {
            n = rand() % CIUDADES;
            //Si ya fue visitada, entonces obtenemos otra ciudad random.
        } while (flag[n] == true);
        //agregamos la ciudad a nuestro camino y la marcamos como visitida.
        ciudades.push_back(n);
        flag[n] = true;
    }
}

//Funcion que lee y guarda los elementos encontrados dentro del archivo csv
//Complejidad: O(n^2): siendo n el número de ciudades.
void lecturaArchivo(string nombreFile)
{
    ifstream archivo(nombreFile);
    string linea;
    string aux;
    vector<int> auxCiudades;
    char delimitador = ',';
    // Leemos cada fila del archivo.
    while (getline(archivo, linea))
    {
        // Convertir la fila a un stream
        stringstream stream(linea);
        for (int i = 0; i < CIUDADES; i++)
        {
            //Dividimos la fila por comas y guardamos cada valor en nuestra matriz.
            getline(stream, aux, delimitador);
            auxCiudades.push_back(atoi(aux.c_str()));
        }
        distancias.push_back(auxCiudades);
        auxCiudades.clear();
    }
    //imprimir(distancias);
    archivo.close();
}

int main()
{
    srand(time(NULL));
    //Maxima distancia: 3496
    //Minima distancia: 25
    //Calcularemos el valor de la temperatura con la formula dada -delta / ln(0.7)
    int delta = 3496 - 25;
    float temperatura = -delta / log(.7);
    cout << "Temperatura inicial: " << temperatura << endl;
    string nombreFile = "cities_128.csv";
    string archivoSalida = "tabla_iteraciones.txt";
    ofstream archivo;
    //Guardamos los valores del archivo .csv en nuestra matriz.
    lecturaArchivo(nombreFile);
    //Obtenemos nuestro primer path
    llenarArreglo();
    //Sacamos el costo del path obtenido
    int costoAct = costo(ciudades);
    cout << "El costo del camino inicial es: " << costoAct << endl
         << endl;
    //Abrimos y comenzamos a escribir en nuestro archivo de texto.
    archivo.open(archivoSalida.c_str(), fstream::out);
    archivo << "Luis Armando Salazar Lopez A01114901" << endl;
    archivo << "Carlos Moisés Chávez Jiménez A01637322" << endl
            << endl;
    archivo << "En este archivo de texto mostraremos la tabla con los datos obtenidos de cada iteracion." << endl
            << endl;
    archivo << "La temperatura inicial es " << temperatura << endl;
    archivo << "El costo del camino inicial es " << costoAct << endl
            << endl;
    archivo << "Iteración\t"
            << "Costo\t\t"
            << "Temperatura" << endl;
    //Realizamos las iteraciones que queramos para buscar el mejor path con el menor costo.
    for (int i = 0; i < 100000; i++)
    {
        //Obtenemos un numero random entre 0 y 1
        float rndm = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
        //Obtenemos nuestra diferencia con la formula dada
        float diferencia = exp(-delta / temperatura);
        vector<int> aux = ciudades;
        //Modificamos nuestro path para ver si encontramos un mejor camino
        vecinos(aux);
        //Sacamos el costo del nuevo path obtenido
        int costoNew = costo(aux);
        //Si el costo es menor, entonces dejamos al nuevo path, sino, vamos a utilizar otra condicionante
        if (costoNew < costoAct)
        {
            ciudades = aux;
            costoAct = costoNew;
        }
        else
        {
            delta = costoNew - costoAct;
            //Si nuestra diferencia es mayor al numero random, entonces permitimos hacer el cambio
            if (diferencia > rndm)
            {
                ciudades = aux;
                costoAct = costoNew;
            }
        }
        //Bajamos la temperatura y la guardamos junto con el costo en el archivo de texto.
        temperatura *= 0.99;
        archivo << i + 1 << "\t\t\t" << costoAct << "\t\t" << temperatura << endl;
    }
    archivo << endl
            << "La temperatura final es " << temperatura << endl;
    archivo << "El costo del camino final es " << costoAct;
    //Cerramos el archivo de texto e imprimimos nuestro path final
    archivo.close();
    imprimir(ciudades);
    cout << "Temperatura final: " << temperatura << endl;
    cout << "El costo del camino final es: " << costoAct << endl;
    return 0;
}
