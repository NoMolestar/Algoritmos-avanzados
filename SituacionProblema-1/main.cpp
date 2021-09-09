#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

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
    file.close();
    return texto;
}

string subsecuencias(const string &trans, const string &mcode)
{
    // Verificamos si ambas cadenas tienen texto
    if (trans.size() == 0 || mcode.size() == 0)
        return "false";

    vector<int> fallo(mcode.size(), -1);

    int l = -1;
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

    // Step 2. Search pattern
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
            string result(to_string(i - cola + 1));
            return "true " + result;
        }
    }

    return "false";
}

string palindromo(const string &trans)
{
    return "something";
}

string substring(const string &trans1, const string &trans2)
{
    return "something";
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