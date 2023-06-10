#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
int main(){
    //Abrir datos
    ifstream entrada("DatosPeliculas.csv");
    string linea,l0,l1,l2,l3,c1,c2,c3,c4,c5,c6,c7,c8,c9,c10;
    string cols[10] = {c1,c2,c3,c4,c5,c6,c7,c8,c9,c10};
    getline(entrada,linea);        //Obtener la línea del título para descartar

    while (getline(entrada,linea))
    {
        stringstream ss(linea);
        
        for (int i=0;i<10;i++){
            getline(ss,cols[i],',');
            cout << cols[i] << " " ;    
        }
        cout << endl << endl;
        if (cols[8] == "")
        {
            cout << endl << "Película" << endl;
        }
        else
        {
            cout << endl << "Serie" << endl;
        }
    }
    entrada.close();
    return 0;
}