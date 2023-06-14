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
    vector<Video*> videos;
    while (getline(entrada,linea))
    {
        stringstream ss(linea);
        
        for (int i=0;i<10;i++){
            getline(ss,cols[i],',');
        }
        //cout << endl << endl;
        if (cols[8] == "")
        {
            string tempID = cols[0];
            string tempNombre = cols[1];
            int tempDuracion = stoi(cols[2]);
            string tempGenero = cols[3];
            double tempCalificacion = stod(cols[4]);
            string tempRelease = cols[5];

            Pelicula* peli = new Pelicula(tempID,tempNombre,tempGenero,tempCalificacion,tempDuracion,tempRelease);
            videos.push_back(peli);
        }
        else
        {
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

            Serie* ser = new Serie(tempID,tempNombre,tempGenero,tempCalificacion,tempDuracion,tempRelease,tempIDEpisodio,
            tempNombreEpisodio,tempTemporada,tempEpisodio);
            videos.push_back(ser);
        }
    }
    entrada.close();
    cout << endl << endl;
    int tam = size(videos);
    for (int i=0; i<tam;i++)
    {
        cout << to_string(i+1);
        videos[i]->verVideo();        //Método polimórfico
    }

    return 0;
}