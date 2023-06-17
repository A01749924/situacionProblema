#include "Serie.h"

Serie::Serie() : Serie("","","",0,0,"","","",0,0)
{
}

Serie::Serie(string ID, string nombre, string genero, double calificacion, int duracion, string release,
             string IDEpisodio, string nombreEpisodio, int temporada, int episodio) : Video(ID, nombre, genero, calificacion, duracion, release), IDEpisodio(IDEpisodio), nombreEpisodio(nombreEpisodio),
                                                                                      temporada(temporada), episodio(episodio)
{
}

void Serie::verEpisodio()
{
    cout << "SERIE: " << nombre << " EPISODIO: " << nombreEpisodio << endl;
}

string Serie::getNombreEpisodio()
{
    return nombreEpisodio;
}

void Serie::verVideo()
{
    cout << "SERIE: " << nombre << " EPISODIO: " << nombreEpisodio << endl;
}

double Serie::operator+(Serie &sum)
{
    return calificacion+sum.calificacion;
}
