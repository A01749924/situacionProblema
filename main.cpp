#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Pelicula.h"
#include "Video.h"
#include "Serie.h"
using namespace std;

int main(){
    //Abrir datos
    ifstream entrada("DatosPeliculas.csv");
    string linea,l0,l1,l2,l3;
    string cols[10] = {};
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
            //cout << endl << "Película" << endl;
            string tempID = cols[0];
            string tempNombre = cols[1];
            int tempDuracion = stoi(cols[2]);
            string tempGenero = cols[3];
            double tempCalificacion = stod(cols[4]);
            string tempRelease = cols[5];

            Pelicula peli(tempID,tempNombre,tempGenero,tempCalificacion,tempDuracion,tempRelease);
            peli.verVideo();
        }
        else
        {
            //cout << endl << "Serie" << endl;
            string tempID = cols[0];
            string tempNombre = cols[1];
            int tempDuracion = stoi(cols[2]);
            string tempGenero = cols[3];
            double tempCalificacion = stod(cols[4]);
            string tempRelease = cols[5];
            string tempIDEpisodio = cols[6];
            string tempNombreEpisodio = cols[7];
            int tempTemporada = stoi(cols[8]);
            int tempEpisodio = stoi(cols[9]);

            Serie ser(tempID,tempNombre,tempGenero,tempCalificacion,tempDuracion,tempRelease,tempIDEpisodio,
            tempNombreEpisodio,tempTemporada,tempEpisodio);
            ser.verVideo();
        }
    }
    entrada.close();
    return 0;
}