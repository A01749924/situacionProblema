/*
PT1 L13
PT2 L71
PT3 L185
*/
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
    //PARTE 1
    //Abrir datos
    ifstream entrada("DatosPeliculas.csv");
    string linea,l0,l1,l2,l3;
    string cols[10] = {};
    getline(entrada,linea);        //Obtener la línea del título para descartar
    vector<string> nombresPelis;
    vector<string> nombresSeries;
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
            int dentro = 0;
            for (int i=0; i<size(nombresPelis);i++)
            {
                if(tempNombre == nombresPelis[i])
                {
                    dentro++;
                }
            }
            if(dentro<1)
            {
                nombresPelis.push_back(tempNombre);
            }
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
            int dentro = 0;
            for (int i=0; i<size(nombresSeries);i++)
            {
                if(tempNombre == nombresSeries[i])
                {
                    dentro++;
                }
            }
            if(dentro<1)
            {
                nombresSeries.push_back(tempNombre);
            }
        }
    }
    entrada.close();
    for (int i=0; i<size(nombresPelis);i++)
    {
        cout << nombresPelis[i] << endl;
    }
    cout << endl;

    for (int i=0; i<size(nombresSeries);i++)
    {
        cout << nombresSeries[i] << endl;
    }
    cout << endl;

    int tam = size(videos);
    for (int i=0; i<tam;i++)
    {
        cout << to_string(i+1);
        videos[i]->verVideo();        //Método polimórfico
    }

    //Parte 2
    cout << endl << endl << "FILTRAR POR GÉNERO" << endl << "Los géneros disponibles son" 
    << endl << "1) Acción\n" << "2) Aventura\n" << "3) Drama\n" << "4) Fantasy\n" << "5) Romance\n" << "6) Sci-Fi\n"
    << "7) Suspenso\n" << "8) Animación\n" << "9) Familiar\n" << "10) Musical\n" << "11) Guerra\n" << "12) Crimen\n"
    << "13) Misterio\n" << "14) Comedia\n" << "15) Western\n" << "16) Biografía\n" << endl << 
    "Ingrese el número del género deseado: ";
    string genDeseado;
    int input;
    while (true){
        cin >> input;
        if (input == 1)
        {
            genDeseado = "Accion";
            break;
        }
        else if (input == 2)
        {
            genDeseado = "Aventura";
            break;
        }
        else if (input == 3)
        {
            genDeseado = "Drama";
            break;
        }
        else if (input == 4)
        {
            genDeseado = "Fantasy";
            break;
        }
        else if (input == 5)
        {
            genDeseado = "Romance";
            break;
        }
        else if (input == 6)
        {
            genDeseado = "Sci-Fi";
            break;
        }
        else if (input == 7)
        {
            genDeseado = "Suspenso";
            break;
        }
        else if (input == 8)
        {
            genDeseado = "Animacion";
            break;
        }
        else if (input == 9)
        {
            genDeseado = "Familiar";
            break;
        }
        else if (input == 10)
        {
            genDeseado = "Musical";
            break;
        }
        else if (input == 11)
        {
            genDeseado = "Guerra";
            break;
        }
        else if (input == 12)
        {
            genDeseado = "Crimen";
            break;
        }
        else if (input == 13)
        {
            genDeseado = "Misterio";
            break;
        }
        else if (input == 14)
        {
            genDeseado = "Comedia";
            break;
        }
        else if (input == 15)
        {
            genDeseado = "Western";
            break;
        }
        else if (input == 16)
        {
            genDeseado = "Biografía";
            break;
        }
        else{
            cout << "Valor inválido, ingrese un número entero del 1-16: ";
        }
    }
    cout << "Ingrese la calificación mínima a filtrar: ";
    double califDeseada;
    cin >> califDeseada;
    string genTemp;
    double califTemp;
    cout << "Mostrando todos los videos del género " << genDeseado << " con una calificación mayor a " << califDeseada << endl;
    for (int i=0; i<tam;i++)
    {
        genTemp=videos[i]->getGenero();
        califTemp=videos[i]->getCalificacion();
        if(califTemp>=califDeseada)
        {
            size_t found = genTemp.find(genDeseado);
            if (found != string::npos) 
            {
                videos[i]->verVideo();
            } 
        }

    }

    //Parte 3
    for (int i=0; i<size(nombresSeries);i++)
    {
        cout << nombresSeries[i] << endl;
    }
    string serieSeleccionada3;
    cout << "Ingrese el nombre de la serie deseada: ";
    cin.ignore();
    getline(cin,serieSeleccionada3);
    cout << endl;
    for (int i = 0; i < tam; i++) 
    {
        if (Serie* serieVector3 = dynamic_cast<Serie*>(videos[i])) 
        {
            if (serieVector3->getNombre() == serieSeleccionada3)
            {
                serieVector3->verEpisodio();
            }
        }
    }    
    //Parte 4


    cout << endl;
    cout << "Ingrese La calificación mínima para pedir película: ";
    double califSeleccionada5;
    cin >> califSeleccionada5;
    cout << endl;

    for (int i = 0; i < tam; i++) 
    {
        if (Pelicula* peliVector5 = dynamic_cast<Pelicula*>(videos[i])) 
        {
            if ((peliVector5->getCalificacion()) > califSeleccionada5)
            {
                peliVector5->verVideo();
            }
        }
    }    

    //Parte 5
    //Parte 6

    string serieAProm;
    cout << endl << endl << "CALIFICACIÓN PROMEDIO DE UNA SERIE" << endl;
    for (int i=0; i<size(nombresSeries);i++)
    {
        cout << nombresSeries[i] << endl;
    }    
    
    cout << "Ingrese el nombre de la serie deseada para obtener su promedio: ";
    string serieSeleccionada6;
    cin.ignore();
    getline(cin,serieSeleccionada6);
    cout << endl;
    double promedioSerie = 0;
    int contadorEpisodios = 0;
    for (int i = 0; i < tam; ++i) 
    {
        if (Serie* serieVector6 = dynamic_cast<Serie*>(videos[i])) 
        {
            if (serieVector6->getNombre() == serieSeleccionada6)
            {
                promedioSerie += videos[i]->getCalificacion();
                contadorEpisodios ++;
            }
        }
    }    
    cout << endl << "La calificación promedio de la serie es de: " << to_string(promedioSerie/contadorEpisodios) << endl;



    return 0;
}