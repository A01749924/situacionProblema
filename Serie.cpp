#include "Serie.h"

Serie::Serie(string ID, string nombre, string genero, double calificacion, int duracion, string release, 
string IDEpisodio, string nombreEpisodio, int temporada, int episodio) : 
Video(ID,nombre,genero,calificacion,duracion,release),IDEpisodio(IDEpisodio),nombreEpisodio(nombreEpisodio),
temporada(temporada),episodio(episodio)
{
}

void Serie::verEpisodio()
{
    cout << "SERIE: " << nombre << " EPISODIO: " << nombreEpisodio << endl;
}
