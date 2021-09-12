/*
12 de Septiembre del 2021
Actividad Integradora 1
Luis Armando Salazar Lopez A01114901
Carlos Moises Chavez Jimenez A01637322
*/
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>

using namespace std;

//Funcion que lee un archivo de texto (recibiendo el nombre como parametro) y regresa
//el string completo del contenido del archivo.
//Complejidad: O(n) donde n es el número de caracteres del archivo.
string leerArchivo(const string &name)
{
    ifstream file;
    string renglon;
    string texto;
    file.open(name, ios::in); //Intruccion que lee un archivo de texto.
    if (file.fail())
    { //Si no encuentra el archivo, regresa un mensaje de error.
        cout << "No se pudo abrir el archivo";
    }
    else
    {
        while (!file.eof())
        {                           //Ciclo que recorre el archivo completo.
            getline(file, renglon); //Obtiene cadenas de cada renglon.
            texto += renglon;
        }
    }
    file.close(); //Cierra el archivo
    return texto;
}

//Funcion que recibe el string de transmision y el string de mcode como parametros, y
//busca el patron de string de mcode dentro del string de transmision
//Complejidad: O(n + m) donde n y m son los caracteres de ambas cadenas que se recibio de parametro.
string subsecuencias(const string &trans, const string &mcode)
{
    // Verificamos si ambas cadenas tienen texto
    if (trans.size() == 0 || mcode.size() == 0)
        return "false";

    //Creamos el vector que nos guiará por el archivo mcode
    vector<int> fallo(mcode.size(), -1);

    int l = -1;
    //Recorremos todo el archivo mcode
    for (int r = 1; r < mcode.size(); r++)
    {

        while (l != -1 && mcode[l + 1] != mcode[r])
        {
            l = fallo[l];
        }

        if (mcode[l + 1] == mcode[r])
        {
            fallo[r] = ++l;
        }
    }

    // Buscamos el patron en el archivo de transmision
    int cola = -1;
    for (int i = 0; i < trans.size(); i++)
    {

        while (cola != -1 && trans[i] != mcode[cola + 1])
        {
            cola = fallo[cola];
        }

        if (trans[i] == mcode[cola + 1])
        {
            cola++;
        }

        if (cola == mcode.size() - 1)
        {
            //Si la cola tiene el mismo tamaño que el mcode
            //significa que encontró el patron
            //Regresa la posicion
            string result(to_string(i - cola + 1));
            return "true " + result;
        }
    }
    //Si nunca encuentra el patro, regresa falso
    return "false";
}

string preProcesamiento(string &trans)
{
    int length = trans.size();
    string str;
    str.push_back('#');
    for (int i = 0; i < length; i++)
    {
        str.push_back(trans[i]);
        str.push_back('#');
    }

    return str;
}

string palindromo(const string &trans)
{
    string str = trans;
    str = preProcesamiento(str);
    int length = str.length();
    vector<int> p(length); //array para guardar longitudes de palindromos en cada prueba

    int c = 0; //variable para llevar un centro
    int r = 0;

    for (int i = 0; i < length; i++)
    {
        int i_mirror = c - (i - c);
        if (r > i)
        {
            p[i] = min(r - i, p[i_mirror]);
        }
        else
        {
            p[i] = 0;
        }
        while (str[i + 1 + p[i]] == str[i - 1 - p[i]])
        {
            p[i]++;
        }

        if (i + p[1] > r)
        {
            c = 1;
            r = i + p[i];
        }
    }
    int maxLen = 0;
    int centerIndex = 0;

    for (int i = 1; i < length - 1; i++)
    {
        if (p[i] > maxLen)
        {
            maxLen = p[i];
            centerIndex = i;
        }
    }
    string respuesta = to_string((centerIndex - maxLen) / 2 + 1) + " " + to_string(((centerIndex - maxLen) / 2) + maxLen);
    return respuesta;
}

//Funcion que compara los contenidos de ambos archivos de transmision
//para encontrar la palabra más larga que coincida en ambos archivos.
//Complejidad: O(m*n) donde m y n son las longitudes de ambos archivos de transmision
string substring(const string &trans1, const string &trans2)
{
    const int m = trans1.length();
    const int n = trans2.length();
    int beg = 0;
    int end = 0;
    //Cramos la tabla que nos permitira guardar las longitudes
    //de los más grandes suffixes de cadenas.
    int LCSuff[m + 1][n + 1];
    //vector<vector<int>> example(n + 1, vector<int>(m + 1, 0));
    int len = 0;
    //Guardaremos las guías de las posiciones de las cadenas
    //comunes mas largas
    int row, col;
    //Recorremos los archivos
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;

            else if (trans1[i - 1] == trans2[j - 1])
            {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                if (len < LCSuff[i][j])
                {
                    len = LCSuff[i][j];
                    row = i;
                    col = j;
                }
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    if (len == 0)
    {
        return "0 0";
    }
    else
    {
        //Obtenemos la posicion inicial y final de las guias que utilizamos.
        int fin = row;
        while (LCSuff[row][col] != 0)
        {
            row--;
            col--;
        }
        int ini = row;
        string result(to_string(ini + 1) + " " + to_string(fin));
        return result;
    }
}

int main()
{
    string trans1 = leerArchivo("transmission1.txt");
    string trans2 = leerArchivo("transmission2.txt");
    string mcode1 = leerArchivo("mcode1.txt");
    string mcode2 = leerArchivo("mcode2.txt");
    string mcode3 = leerArchivo("mcode3.txt");
    string subSec = subsecuencias(trans1, mcode1);
    cout << endl
         << subSec << endl;
    subSec = subsecuencias(trans1, mcode2);
    cout << subSec << endl;
    subSec = subsecuencias(trans1, mcode3);
    cout << subSec << endl;
    subSec = subsecuencias(trans2, mcode1);
    cout << subSec << endl;
    subSec = subsecuencias(trans2, mcode2);
    cout << subSec << endl;
    subSec = subsecuencias(trans2, mcode3);
    cout << subSec << endl;
    string pal = palindromo(trans1);
    cout << pal << endl;
    pal = palindromo(trans2);
    cout << pal << endl;
    string subCadena = substring(trans1, trans2);
    cout << subCadena << endl;
    return 0;
}