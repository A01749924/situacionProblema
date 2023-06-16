#ifndef SERIE_H
#define SERIE_H
#include <vector>
#include <string>
#include <iostream>
#include "Video.h"

class Serie : public Video
{
    private:
        string IDEpisodio;
        string nombreEpisodio;
        int temporada;
        int episodio;
    public:
        Serie(string ID,string nombre,string genero,double calificacion,int duracion,string release,
        string IDEpisodio,string nombreEpisodio,int temporada,int episodio);
        void verEpisodio();
        string getNombreEpisodio();
};

#endif