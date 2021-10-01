//Knapsack problem
//8 de octubre del 2021
//Luis Armando Salazar Lopez A01114901
//Carlos Moises Chavez Jimenez A01637322
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Explicacion
//Complejidad O()
void Knapsack(vector<int> &valores, vector<int> &pesos, int pesoMax)
{
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
        valores.push_back(pesoMax);
    }
    cin >> pesoMax;
    //Pasamos la matriz a las funciones correspondientes
    cout << endl;
    Knapsack(valores, pesos, pesoMax);
    cout << endl;
    return 0;
}
