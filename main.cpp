#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Pelicula.h"
#include "Video.h"
#include "Serie.h"
using namespace std;

void desplegarMenu()
{
    cout << endl
         << "Seleccione una opción:" << endl
         << "1) Cargar el archivo de datos (sin este no se pueden ejecutar las opciones 2-6)"
         << endl
         << "2) Mostrar todos los videos con cierta calificación mínima de un género" << endl
         << "3) Mostrar todos los episodios de una serie" << endl
         << "4) Mostrar todas las películas con cierta calificación mínima"
         << endl
         << "5) Calificar un video" << endl
         << "6) Calcular el promedio de la calificación de una serie"
         << endl
         << "7) Salir" << endl
         << endl;
}

int main()
{
    cout << endl
         << endl
         << "Bienvenid@ a la base de datos del servicio de streaming" << endl;
    vector<string> nombresPelis;
    vector<string> nombresSeries;
    vector<Video *> videos;
    int tam;
    int opcionMenu;
    bool catalogoCargado = false;
    bool continuar = true;
    while (continuar == true)
    {
        desplegarMenu();
        cout << "Ingrese la opción deseada: ";
        cin >> opcionMenu;
        if (opcionMenu < 1 || opcionMenu > 7)
        {
            cout << "OPCIÓN NO EXISTENTE" << endl;
        }
        else if (opcionMenu == 7)
        {
            cout << "Muchas gracias por utilizar el servicio";
            continuar = false;
        }
        else
        {
            if (catalogoCargado == false)
            {
                if (opcionMenu == 1)
                {
                    cout << "Cátalogo cargado exitosamente" << endl;
                    catalogoCargado = true;
                    // Abrir datos
                    ifstream entrada("DatosPeliculas.csv");
                    string linea, l0, l1, l2, l3;
                    string cols[10] = {};
                    getline(entrada, linea); // Obtener la línea del título para descartar

                    while (getline(entrada, linea))
                    {
                        stringstream ss(linea);

                        for (int i = 0; i < 10; i++)
                        {
                            getline(ss, cols[i], ',');
                        }
                        // cout << endl << endl;
                        if (cols[8] == "")
                        {
                            string tempID = cols[0];
                            string tempNombre = cols[1];
                            int tempDuracion = stoi(cols[2]);
                            string tempGenero = cols[3];
                            double tempCalificacion = stod(cols[4]);
                            string tempRelease = cols[5];

                            Pelicula *peli = new Pelicula(tempID, tempNombre, tempGenero, tempCalificacion, tempDuracion, tempRelease);
                            videos.push_back(peli);
                            int dentro = 0;
                            for (int i = 0; i < size(nombresPelis); i++)
                            {
                                if (tempNombre == nombresPelis[i])
                                {
                                    dentro++;
                                }
                            }
                            if (dentro < 1)
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

                            Serie *ser = new Serie(tempID, tempNombre, tempGenero, tempCalificacion, tempDuracion, tempRelease, tempIDEpisodio,
                                                   tempNombreEpisodio, tempTemporada, tempEpisodio);
                            videos.push_back(ser);
                            int dentro = 0;
                            for (int i = 0; i < size(nombresSeries); i++)
                            {
                                if (tempNombre == nombresSeries[i])
                                {
                                    dentro++;
                                }
                            }
                            if (dentro < 1)
                            {
                                nombresSeries.push_back(tempNombre);
                            }
                        }
                    }
                    entrada.close();
                    tam = size(videos);
                }
                else
                {
                    cout << "El cátalogo no ha sido cargado" << endl;
                }
            }
            else
            {
                if (opcionMenu == 1)
                {
                    cout << "Cátalogo previamente cargado" << endl;
                }
                else if (opcionMenu == 2)
                {
                    cout << endl
                         << endl
                         << "FILTRAR POR GÉNERO" << endl
                         << "Los géneros disponibles son"
                         << endl
                         << "1) Acción\n"
                         << "2) Aventura\n"
                         << "3) Drama\n"
                         << "4) Fantasy\n"
                         << "5) Romance\n"
                         << "6) Sci-Fi\n"
                         << "7) Suspenso\n"
                         << "8) Animación\n"
                         << "9) Familiar\n"
                         << "10) Musical\n"
                         << "11) Guerra\n"
                         << "12) Crimen\n"
                         << "13) Misterio\n"
                         << "14) Comedia\n"
                         << "15) Western\n"
                         << "16) Biografía\n"
                         << endl
                         << "Ingrese el número del género deseado: ";
                    string genDeseado;
                    int input;
                    while (true)
                    {
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
                        else
                        {
                            cout << "Valor inválido, ingrese un número entero del 1-16: ";
                        }
                    }
                    double califDeseada2 = 0;
                    while (califDeseada2 < 1 || califDeseada2 > 7)
                    {
                        cout << "Ingrese la calificación mínima a filtrar: ";
                        cin >> califDeseada2;
                        if (califDeseada2 < 1 || califDeseada2 > 7)
                        {
                            cout << "La calificación no es válida. Tiene que estar entre 1 y 7" << endl;
                        }
                    }
                    string genTemp;
                    double califTemp;
                    cout << "Mostrando todos los videos del género " << genDeseado << " con una calificación mayor a " << califDeseada2 << endl;
                    for (int i = 0; i < tam; i++)
                    {
                        genTemp = videos[i]->getGenero();
                        califTemp = videos[i]->getCalificacion();
                        if (califTemp >= califDeseada2)
                        {
                            size_t found = genTemp.find(genDeseado);
                            if (found != string::npos)
                            {
                                videos[i]->verVideo();
                            }
                        }
                    }
                }
                else if (opcionMenu == 3)
                {
                    for (int i = 0; i < size(nombresSeries); i++)
                    {
                        cout << nombresSeries[i] << endl;
                    }
                    int adentro3 = 0;
                    string serieSeleccionada3;
                    while (adentro3 == 0)
                    {
                        cout << "Ingrese el nombre de la serie deseada: ";
                        getline(cin, serieSeleccionada3);
                        for (int i = 0; i < tam; i++)
                        {
                            if (Serie *serieVector3 = dynamic_cast<Serie *>(videos[i]))
                            {
                                if (serieVector3->getNombre() == serieSeleccionada3)
                                {
                                    adentro3++;
                                }
                            }
                        }
                        if (adentro3 == 0)
                        {
                            cout << "La serie no está en el catálogo" << endl;
                        }
                    }

                    cout << endl;
                    for (int i = 0; i < tam; i++)
                    {
                        if (Serie *serieVector3 = dynamic_cast<Serie *>(videos[i]))
                        {
                            if (serieVector3->getNombre() == serieSeleccionada3)
                            {
                                serieVector3->verEpisodio();
                            }
                        }
                    }
                }
                else if (opcionMenu == 4)
                {
                    cout << endl;
                    double califSeleccionada5 = 0;
                    while (califSeleccionada5 < 1 || califSeleccionada5 > 7)
                    {
                        cout << "Ingrese La calificación mínima para pedir película: ";
                        cin >> califSeleccionada5;
                        cout << endl;
                        if (califSeleccionada5 < 1 || califSeleccionada5 > 7)
                        {
                            cout << "La calificación no es válida. Tiene que estar entre 1 y 7" << endl;
                        }
                    }
                    for (int i = 0; i < tam; i++)
                    {
                        if (Pelicula *peliVector5 = dynamic_cast<Pelicula *>(videos[i]))
                        {
                            if ((peliVector5->getCalificacion()) > califSeleccionada5)
                            {
                                peliVector5->verVideo();
                            }
                        }
                    }
                }
                else if (opcionMenu == 5)
                {
                    string nombreVidCalif, nombreEpisCalif;
                    int numEpisodios = 0;
                    int contiene = 0;
                    double oldCalif, newCalif;
                    while (contiene == 0)
                    {
                        cout << "Ingrese el nombre de la serie o película a calificar: ";
                        getline(cin, nombreVidCalif);
                        for (int i = 0; i < tam; i++)
                        {
                            if (videos[i]->getNombre() == nombreVidCalif)
                            {
                                contiene++;
                            }
                        }
                        if (contiene == 0)
                        {
                            cout << "El video no está en el catálogo" << endl;
                        }
                    }
                    for (int i = 0; i < tam; ++i)
                    {
                        if (videos[i]->getNombre() == nombreVidCalif)
                        {
                            numEpisodios++;
                        }
                    }
                    if (numEpisodios > 1)
                    {
                        for (int i = 0; i < tam; i++)
                        {
                            if (Serie *serieVector5 = dynamic_cast<Serie *>(videos[i]))
                            {
                                if (serieVector5->getNombre() == nombreVidCalif)
                                {
                                    serieVector5->verVideo();
                                }
                            }
                        }
                        contiene = 0;
                        while (contiene == 0)
                        {
                            cout << "Ingrese el nombre del capítulo de la serie " << nombreVidCalif << " a calificar: ";
                            getline(cin, nombreEpisCalif);
                            for (int i = 0; i < tam; i++)
                            {
                                if (Serie *serieVector3 = dynamic_cast<Serie *>(videos[i]))
                                {
                                    if (serieVector3->getNombreEpisodio() == nombreEpisCalif)
                                    {
                                        contiene++;
                                    }
                                }
                            }
                            if (contiene == 0)
                            {
                                cout << "El episodio no está en el catálogo" << endl;
                            }

                            for (int i = 0; i < tam; i++)
                            {
                                if (Serie *serieVector5 = dynamic_cast<Serie *>(videos[i]))
                                {
                                    if ((serieVector5->getNombreEpisodio() == nombreEpisCalif) && (serieVector5->getNombre() == nombreVidCalif))
                                    {
                                        oldCalif = serieVector5->getCalificacion();
                                        double newCalif = 0;
                                        while (newCalif < 1 || newCalif > 7)
                                        {
                                            cout << "Ingrese la nueva calificación: ";
                                            cin >> newCalif;
                                            if (newCalif < 1 || newCalif > 7)
                                            {
                                                cout << "La calificación no es válida. Tiene que estar entre 1 y 7" << endl;
                                            }
                                        }
                                        serieVector5->setCalificacion(newCalif);
                                        cout << "La calificación de ";
                                        serieVector5->verVideo();
                                        cout << "cambio de " << to_string(oldCalif) << " a " << to_string(serieVector5->getCalificacion());
                                    }
                                }
                            }
                        }
                    }
                    else
                    {
                        for (int i = 0; i < tam; i++)
                        {
                            if (videos[i]->getNombre() == nombreVidCalif)
                            {
                                oldCalif = videos[i]->getCalificacion();
                                double newCalif = 0;
                                while (newCalif < 1 || newCalif > 7)
                                {
                                    cout << "Ingrese la nueva calificación: ";
                                    cin >> newCalif;
                                    if (newCalif < 1 || newCalif > 7)
                                    {
                                        cout << "La calificación no es válida. Tiene que estar entre 1 y 7" << endl;
                                    }
                                }
                                videos[i]->setCalificacion(newCalif);
                                cout << "La calificación de ";
                                videos[i]->verVideo();
                                cout << "cambio de " << to_string(oldCalif) << " a " << to_string(videos[i]->getCalificacion()) << endl;
                            }
                        }
                    }
                }
                else
                {
                    Serie vacio;
                    Serie sbtl;
                    double subtotal = 0;
                    double local = 0;
                    int numEpisodios = 0;
                    for (int i = 0; i < size(nombresSeries); i++)
                    {
                        cout << nombresSeries[i] << endl;
                    }
                    int contiene = 0;
                    string serieAProm;
                    while (contiene == 0)
                    {
                        cout << "Ingrese el nombre de la serie para obtener su promedio: ";
                        getline(cin, serieAProm);
                        for (int i = 0; i < tam; i++)
                        {
                            if (videos[i]->getNombre() == serieAProm)
                            {
                                contiene++;
                            }
                        }
                        if (contiene == 0)
                        {
                            cout << "La serie no existe en el catálogo"  << endl;
                        }
                    }
                    for (int i = 0; i < tam; i++)
                    {
                        if (Serie *serieVector6 = dynamic_cast<Serie *>(videos[i]))
                        {
                            if (serieVector6->getNombre() == serieAProm)
                            {
                                vacio.setCalificacion(vacio + *serieVector6);
                                numEpisodios ++;
                            }
                        }
                    }
                    subtotal = vacio.getCalificacion();
                    cout << to_string(subtotal) << endl;
                    cout << "El promedio de la serie " << serieAProm << " es de: " << to_string(subtotal/numEpisodios) << endl;
                }
            }
        }
    }
    return 0;
}