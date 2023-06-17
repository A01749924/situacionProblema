/*
Autor: José Luis Del Alto Ordorica      A01749924       ITD
Situación Problema
Archivo .h de la clase Serie
*/

//Verificar que se defina sólo una vez
#ifndef SERIE_H
#define SERIE_H

//Incluir librerías y .h de la superclase Video
#include <vector>
#include <string>
#include <iostream>
#include "Video.h"

//Declarar clase que hereda de lo público de video
class Serie : public Video
{
    //Declarar variables privadas
    private:
        string IDEpisodio;
        string nombreEpisodio;
        int temporada;
        int episodio;
    //Declarar métodos públicos
    public:
        //Constructores
        Serie();
        Serie(string ID,string nombre,string genero,double calificacion,int duracion,string release,
        string IDEpisodio,string nombreEpisodio,int temporada,int episodio);
        string getNombreEpisodio();         //Getter
        void verVideo();                //Reescribir método abstracto heredado
        double operator+ (Serie &sum);             //Sobrecargar operador
};

#endif