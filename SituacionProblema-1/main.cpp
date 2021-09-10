#include <iostream>
#include <string>
#include <string.h>
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

string preProcesamiento(string &trans){
    int length=trans.size();
    string str;
    str.push_back('#');
    for(int i=0;i<length;i++){
        str.push_back(trans[i]);
        str.push_back('#');
    }

    return str;
}
/*
string postProcesamiento(string palin){
    int length=palin.length();
    string str;
    for(int i=0;i<length;i++){
        if(palin[i] != '#'){
            str.push_back(palin[i]);
        }
    }
    return str;
}*/

string palindromo(const string &trans)
{
    string str=trans;
    str=preProcesamiento(str);
    int length=str.length();
    int p[length];//array para guardar longitudes de palindromos en cada prueba

    int c=0;//variable para llevar un centro
    int r=0;

    for(int i=0;i<length;i++){
        int i_mirror =c-(i-c);
        if(r>i){
            p[i]=min(r-i,p[i_mirror]);
        }else{
            p[i]=0;
        }
        while(str[i+1+p[i]]==str[i-1-p[i]]){
            p[i]++;
        }

        if(i+p[1]>r){
            c=1;
            r=i+p[i];
        }
    }
    int maxLen=0;
    int centerIndex=0;
    
    for(int i=1;i<length-1;i++){
        if(p[i]>maxLen){
            maxLen= p[i]; 
            centerIndex=i;
        }
    }
    string respuesta=to_string((centerIndex-maxLen)/2)+" "+to_string(((centerIndex-maxLen)/2)+maxLen-1);
    return respuesta;
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