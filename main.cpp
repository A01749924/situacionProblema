/*
Autor: José Luis Del Alto Ordorica      A01749924       ITD
Situación Problema
Archivo principal
*/

// Incluir librerías y .h's
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include "Pelicula.h"
#include "Video.h"
#include "Serie.h"
using namespace std;

// Crear función para mostrar menú
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
    // Desplegar mensaje inicial
    cout << endl
         << endl
         << "Bienvenid@ a la base de datos del servicio de streaming" << endl;
    // Inicializar vectores y variables que se usan dentro y fuera de las estructuras de control
    vector<string> nombresPelis;
    vector<string> nombresSeries;
    vector<Video *> videos;
    int tam;
    int opcionMenu;
    bool catalogoCargado = false;
    bool continuar = true;

    // Ciclo del menú que se repetirá hasta elegir la opción 7
    while (continuar == true)
    {
        // Imprimir menú con la función y solicitar input
        desplegarMenu();
        cout << "Ingrese la opción deseada: ";
        cin >> opcionMenu;
        // Verificar que el input sea válido
        if (opcionMenu < 1 || opcionMenu > 7)
        {
            cout << "OPCIÓN NO EXISTENTE" << endl;
        }
        // Terminar el ciclo en el caso de que se ingrese 7
        else if (opcionMenu == 7)
        {
            cout << "Muchas gracias por utilizar el servicio";
            continuar = false;
        }
        else
        {
            // Ver casos en los que no se carga el catálogo
            if (catalogoCargado == false)
            {
                // Cargar catálogo cuando el input es 1
                if (opcionMenu == 1)
                {
                    cout << "Cátalogo cargado exitosamente" << endl;
                    catalogoCargado = true;
                    // Abrir datos
                    ifstream entrada("DatosPeliculas.csv");
                    string linea, l0, l1, l2, l3;
                    string cols[10] = {};
                    getline(entrada, linea); // Obtener la línea del título para descartar
                    // Leer archivo
                    while (getline(entrada, linea))
                    {
                        // Convertir línea a stream
                        stringstream ss(linea);
                        for (int i = 0; i < 10; i++)
                        {
                            getline(ss, cols[i], ',');
                        }
                        // Ver si es película o serie
                        if (cols[8] == "")
                        {
                            string tempID = cols[0];
                            string tempNombre = cols[1];
                            int tempDuracion = stoi(cols[2]);
                            string tempGenero = cols[3];
                            double tempCalificacion = stod(cols[4]);
                            string tempRelease = cols[5];

                            // Crear objeto Pelicula dinámicamente con los datos
                            Pelicula *peli = new Pelicula(tempID, tempNombre, tempGenero, tempCalificacion, tempDuracion, tempRelease);
                            // Anexarlo al vector de referencias
                            videos.push_back(peli);
                            int dentro = 0;
                            // Crear vector de los nombres para imprimir sin formato ágilmente
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
                            // Almacenar datos en variables
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

                            // Crear objeto Serie dinámicamente con los datos
                            Serie *ser = new Serie(tempID, tempNombre, tempGenero, tempCalificacion, tempDuracion, tempRelease, tempIDEpisodio,
                                                   tempNombreEpisodio, tempTemporada, tempEpisodio);
                            videos.push_back(ser);
                            int dentro = 0;
                            // Crear vector de los nombres para imprimir sin formato ágilmente
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
                    // Cerrar archivo
                    entrada.close();
                    tam = size(videos); // Guardar el tamaño final del vector como variable
                }
                else
                // En el caso de no haber cargado el catálogo y seleccionar cualquier opción, mostrar
                // este mensaje y reiniciar el ciclo del menú
                {
                    cout << "El cátalogo no ha sido cargado" << endl;
                }
            }
            else
            {
                // Si ya se cargó el menú y se solicita volver a cargar, mostrar mensaje
                if (opcionMenu == 1)
                {
                    cout << "Cátalogo previamente cargado" << endl;
                }
                // Filtrar por género y calificación
                else if (opcionMenu == 2)
                {
                    int resultados2 = 0;
                    // Imprimir opciones de géneros
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
                    // Solicitar género
                    // Declarar variables: string del género e int de la opción
                    string genDeseado;
                    int input;
                    // Ciclo while para verificar que el input sea un número válido con ifs para asignar valores al string de género
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
                    // Declarar variable de calificación
                    double califDeseada2 = 0;
                    // Verificar con ciclo while que la calificación ingresada sea posible
                    while (califDeseada2 < 1 || califDeseada2 > 7)
                    {
                        cout << "Ingrese la calificación mínima a filtrar: ";
                        cin >> califDeseada2;
                        if (califDeseada2 < 1 || califDeseada2 > 7)
                        {
                            cout << "La calificación no es válida. Tiene que estar entre 1 y 7" << endl;
                        }
                    }
                    // Crear variables temporales para comparar los inputs con los atributos de los objetos
                    string genTemp;
                    double califTemp;
                    cout << "Mostrando todos los videos del género " << genDeseado << " con una calificación mayor a " << califDeseada2 << endl;
                    // Recorrer vector. Si se cumplen ambas condiciones, imprimir video con el método virtual
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
                                resultados2 ++;
                            }
                        }
                    }
                    cout << "Se hallaron " << to_string(resultados2) << " resultados" << endl;
                }
                // Mostrar capítulos de una serie
                else if (opcionMenu == 3)
                {
                    int resultados3 = 0;
                    // Desplegar series para que el usuario pueda seleccionar
                    for (int i = 0; i < size(nombresSeries); i++)
                    {
                        cout << nombresSeries[i] << endl;
                    }
                    // Declarar variables
                    int adentro3 = 0;
                    string serieSeleccionada3;
                    // Verificar con ciclo que el nombre se encuentre en el vector de nombres
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
                    // Recorrer vector de apuntadores tipo video
                    for (int i = 0; i < tam; i++)
                    {
                        // Si es posible, hacer upcasting de video a serie
                        if (Serie *serieVector3 = dynamic_cast<Serie *>(videos[i]))
                        {
                            // Si coincide el nombre de la serie con la seleccionada, imprimir el episodio
                            if (serieVector3->getNombre() == serieSeleccionada3)
                            {
                                serieVector3->verVideo();
                                resultados3 ++;
                            }
                        }
                    }
                    cout << "La serie tiene " << to_string(resultados3) << " episodios" << endl;
                }
                // Mostrar películas con calificación mayor a la seleccionada
                else if (opcionMenu == 4)
                {
                    int resultados4 = 0;
                    cout << endl;
                    // Inicializar variable
                    double califSeleccionada5 = 0;
                    // Verificar que la calificación sea válida con ciclo
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
                    // Recorrer vector de apuntadores tipo video
                    for (int i = 0; i < tam; i++)
                    {
                        // Hacer upcasting a película si es posible
                        if (Pelicula *peliVector5 = dynamic_cast<Pelicula *>(videos[i]))
                        {
                            // Si la calificación es mayor a la deseada, imprimir pelicula
                            if ((peliVector5->getCalificacion()) > califSeleccionada5)
                            {
                                peliVector5->verVideo();
                                resultados4 ++;
                            }
                        }
                    }
                    cout << "Se encontraron " << to_string(resultados4) << " resultados" << endl;
                }
                // Calificar video
                else if (opcionMenu == 5)
                {
                    // Inicializar variables
                    string nombreVidCalif, nombreEpisCalif;
                    int numEpisodios = 0;
                    int contiene = 0;
                    double oldCalif, newCalif;
                    // Verificar con un ciclo que es válido el nombre comparando con el vector
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
                    // Ver si es película o serie, contando cuántas veces se repite el nombre
                    for (int i = 0; i < tam; ++i)
                    {
                        if (videos[i]->getNombre() == nombreVidCalif)
                        {
                            numEpisodios++;
                        }
                    }
                    // Si es serie
                    if (numEpisodios > 1)
                    {
                        // Recorrer vector de apuntadores tipo video
                        for (int i = 0; i < tam; i++)
                        {
                            // Hacer downcasting a serie
                            if (Serie *serieVector5 = dynamic_cast<Serie *>(videos[i]))
                            {
                                // Desplegar los episodios de la serie deseada
                                if (serieVector5->getNombre() == nombreVidCalif)
                                {
                                    serieVector5->verVideo();
                                }
                            }
                        }
                        contiene = 0;
                        // Verificar con un ciclo que el episodio deseado sea de la serie correspondiente
                        while (contiene == 0)
                        {
                            cout << "Ingrese el nombre del capítulo de la serie " << nombreVidCalif << " a calificar: ";
                            getline(cin, nombreEpisCalif);
                            // Recorrer vector de apuntadores tipo video
                            for (int i = 0; i < tam; i++)
                            {
                                // Hacer upcasting a serie si se puede
                                if (Serie *serieVector3 = dynamic_cast<Serie *>(videos[i]))
                                {
                                    // Verificar que el episodio coincida
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

                            // Recorrer vector de apuntadores tipo video
                            for (int i = 0; i < tam; i++)
                            {
                                // Hacer upcasting a serie si se puede
                                if (Serie *serieVector5 = dynamic_cast<Serie *>(videos[i]))
                                {
                                    // Ver si el nombre del episodio coincide
                                    if ((serieVector5->getNombreEpisodio() == nombreEpisCalif) && (serieVector5->getNombre() == nombreVidCalif))
                                    {
                                        // Guardar calificación vieja en una variable
                                        oldCalif = serieVector5->getCalificacion();
                                        double newCalif = 0;
                                        // Verificar que la calificación ingresada sea válida con ciclo while
                                        while (newCalif < 1 || newCalif > 7)
                                        {
                                            cout << "Ingrese la nueva calificación: ";
                                            cin >> newCalif;
                                            if (newCalif < 1 || newCalif > 7)
                                            {
                                                cout << "La calificación no es válida. Tiene que estar entre 1 y 7" << endl;
                                            }
                                        }
                                        // Guardar calificación en el objeto e imprimir la nueva y la anterior
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
                    // Obtener la calificación de la película deseada
                    {
                        for (int i = 0; i < tam; i++)
                        {
                            // Ubicar la película en el vector con su nombre
                            if (videos[i]->getNombre() == nombreVidCalif)
                            {
                                oldCalif = videos[i]->getCalificacion();
                                double newCalif = 0;
                                // Verificar con un ciclo while que la calificación sea válida
                                while (newCalif < 1 || newCalif > 7)
                                {
                                    cout << "Ingrese la nueva calificación: ";
                                    cin >> newCalif;
                                    if (newCalif < 1 || newCalif > 7)
                                    {
                                        cout << "La calificación no es válida. Tiene que estar entre 1 y 7" << endl;
                                    }
                                }
                                // Guardar calificación en el objeto e imprimir la nueva y la anterior
                                videos[i]->setCalificacion(newCalif);
                                cout << "La calificación de ";
                                videos[i]->verVideo();
                                cout << "cambio de " << to_string(oldCalif) << " a " << to_string(videos[i]->getCalificacion()) << endl << endl;
                            }
                        }
                    }
                }
                // Promedio de una serie
                else
                {
                    // Inicializar variables y objeto vacío para la sobrecarga del operador +
                    Serie vacio;
                    double subtotal = 0;
                    double local = 0;
                    int numEpisodios = 0;
                    int contiene = 0;
                    string serieAProm;
                    // Desplegar el nombre de las series
                    for (int i = 0; i < size(nombresSeries); i++)
                    {
                        cout << nombresSeries[i] << endl;
                    }
                    // Verificar que la serie se encuentre en el vector con ciclo while
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
                            cout << "La serie no existe en el catálogo" << endl;
                        }
                    }
                    // Recorrer vector de apuntadores tipo Video
                    for (int i = 0; i < tam; i++)
                    {
                        // Hacer upcasting a serie si es posible
                        if (Serie *serieVector6 = dynamic_cast<Serie *>(videos[i]))
                        {
                            // Si el nombre de la serie coincide
                            if (serieVector6->getNombre() == serieAProm)
                            {
                                // Sumar 2 objetos con sobrecarga (sólo se suman las calificaciones)
                                vacio.setCalificacion(vacio + *serieVector6);
                                numEpisodios++;
                            }
                        }
                    }
                    // Guardar las calificaciones almacenadas en el objeto vacío en una variable e imprimirla
                    subtotal = vacio.getCalificacion();
                    cout << to_string(subtotal) << endl;
                    cout << "El promedio de la serie " << serieAProm << " es de: " << to_string(subtotal / numEpisodios) << endl;
                }
            }
        }
    }
    return 0;
}