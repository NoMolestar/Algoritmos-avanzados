//Knapsack problem
//8 de octubre del 2021
//Luis Armando Salazar Lopez A01114901
//Carlos Moises Chavez Jimenez A01637322
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

int main()
{
    int n = 0;
    cin >> n;
    //Vectores para llenar la matriz.
    vector<int> valores;
    int pesoMax = 0;
    vector<int> pesos;
    //Llenamos el vector de valores de los elementos.
    for (int i = 0; i < n; i++)
    {
        cin >> pesoMax;
        valores.push_back(pesoMax);
    }
    //Llenamos el vector de los pesos asociados
    for (int i = 0; i < n; i++)
    {
        cin >> pesoMax;
        pesos.push_back(pesoMax);
    }
    cin >> pesoMax;
    //Pasamos la matriz a las funciones correspondientes
    mochila(valores, pesos, pesoMax, n);
    return 0;
}
