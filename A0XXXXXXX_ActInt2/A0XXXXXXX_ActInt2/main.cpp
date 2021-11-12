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

const int INF = 999999;

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
    string alfabeto="ABCDEFGHIJKLMNOPQRSTUVXYZ";
    for (int k = 0; k < n; k++)
    {
        if (k != source && recorrido[k] != INF)
        {
            cout << "De la colonia " << alfabeto[source] << " a la colonia " << alfabeto[k] << " : " << recorrido[k] << "KM de cableado. " << endl;
        }
    }
}

//Algoritmo Agente Viajero
//cheapest link
//Complejidad: O(N!)
void rutaFun2(int n, vector<vector<int>> &distancia)
{
    vector<vector<int>> matrizNodos=distancia;
    bool listo=false;
    int suma=0;
    vector<int> nodoVisitado(n,0);
    vector<vector<int>> solucion(n, vector<int> (n,0));
    int i=0;
    //int contador=0;
    while(!listo){
       // contador++;
       // cout<<"iteracion num: "<<contador<<endl;
        if(nodoVisitado[i]<2){
            int min=INT_MAX;
            int minPos=INT_MAX;
            bool visita=false;
            for(int j=0;j<n;j++){
                if(i!=j && matrizNodos[i][j]<min && matrizNodos[i][j]>0){
                    if( (nodoVisitado[i]+nodoVisitado[j])<2 ){
                        min=matrizNodos[i][j];
                        minPos=j;
                        visita=true;
                       // cout<<"intendo de minimo: "<<min<<endl;
                    }else if(nodoVisitado[i]+nodoVisitado[j]==2 && suma == ((n*2)-2) ){
                        listo=true;
                        min=matrizNodos[i][j];
                        minPos=j;
                        visita=true;
                    }
                }
            }
            if(visita){
                //establecemos la conexion en el vector de visitas y solucion
                solucion[i][minPos]=matrizNodos[i][minPos];
                solucion[minPos][i]=matrizNodos[minPos][i];

                matrizNodos[i][minPos]=0;
                matrizNodos[minPos][i]=0;

                nodoVisitado[i]++;
                nodoVisitado[minPos]++;

                suma+=2;
                
            }

            if(suma==n*2){
                listo=true;
            }
            i=minPos-1;
        }


        i++;
        if(i==n){
            i=0;
        }
    }

    
    //comprobacion de solucion
    
    if(listo){
        string alfabeto="ABCDEFGHIJKLMNOPQRSTUVXYZ";
        cout<<"La ruta(TSP) es: "<<endl;
        int posActual, posAnterior ;
        posActual=posAnterior=0;
        
        for(int i=0;i<n;i++){//for para desplegar todos los caminos

            for(int j=0;j<n;j++){//for para encontrar una ruta en la solucion ya creada
                if(solucion[posActual][j]>0 && j!=posAnterior && j!=posActual){
                    cout<<"Desde : colonia "<<alfabeto[posActual]<<" hacia : colonia "<<alfabeto[j]<<" valor: "<<solucion[posActual][j]<<endl;
                    posAnterior=posActual;
                    posActual=j;  
                    break; 
                }
            }
        }
        

    }else{
        cout<<"Solucion no encontrada"<<endl;
    }
    
    //

}

//Funcion auxiliar que verifica si existe un camino entre el nodo s y el nodo t.
//Se guarda ese camino en el vector parent.
//Complejidad: O(n) donde n es el numero de vertices del grafo.
bool auxFun3(vector<vector<int>> &rGraph, int s, int t, vector<int> &padre, int n)
{
    //Lista de nodos visitados
    vector<bool> visitado(n, 0);
    queue<int> q;
    q.push(s);
    visitado[s] = true;
    padre[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 0; v < n; v++)
        {
            if (visitado[v] == false && rGraph[u][v] > 0)
            {
                if (v == t)
                {
                    //Si encontramos conexión con el nodo final
                    //Regresamos verdadero
                    padre[v] = u;
                    return true;
                }
                q.push(v);
                padre[v] = u;
                visitado[v] = true;
            }
        }
    }
    //Si terminamos la cola y no encontramos conexion
    //Regresamos falso.
    return false;
}

//Funcion 3 : Algoritmo Ford-Fulkerson
//Regresa el flujo maximo entre el nodo inicial (s) y el final (t)
//Complejidad: O(n^3) donde n es el número de vertices del grafo
void flujoFun3(vector<vector<int>> &grafo, int s, int t, int n)
{
    int u;
    int v;
    //Creamos un grafo auxiliar para trabajar sobre el
    vector<int> minGrafo(n, 0);
    vector<vector<int>> rGraph(n, minGrafo);
    //Llenamos el grafo auxiliar con los mismos valores del grafo principal
    for (u = 0; u < n; u++)
    {
        for (v = 0; v < n; v++)
        {
            rGraph[u][v] = grafo[u][v];
        }
    }
    vector<int> padre(n, 0);
    //Inicializamos el flujo maximo en 0
    int flujoMax = 0;
    while (auxFun3(rGraph, s, t, padre, n))
    {
        //Encuentra el flujo maximo posible dentro
        //del camino establecido del nodo inicial al final
        int flujoRuta = INF;
        for (v = t; v != s; v = padre[v])
        {
            u = padre[v];
            flujoRuta = min(flujoRuta, rGraph[u][v]);
        }
        //Actualizamos las capacidades residuales de los bordes del grafo
        for (v = t; v != s; v = padre[v])
        {
            u = padre[v];
            rGraph[u][v] -= flujoRuta;
            rGraph[v][u] += flujoRuta;
        }
        //Agregamos el flujo maximo encontrado al flujo maximo final
        flujoMax += flujoRuta;
    }
    cout << endl
         << "- Funcion 3" << endl;
    cout << "El flujo maximo de informacion es: " << flujoMax << endl;
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

    rutaFun2(colonias,distancia);

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