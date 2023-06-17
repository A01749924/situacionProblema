/*
Autor: José Luis Del Alto Ordorica      A01749924       ITD
Situación Problema
Archivo Serie.cpp
*/

//Incluir .h
#include "Serie.h"

//Constructor por deffault. Se va a utilizar para la sobrecarga de operadores
Serie::Serie() : Serie("","","",0,0,"","","",0,0)
{
}


//Constructor con parámetros que hereda de Video
Serie::Serie(string ID, string nombre, string genero, double calificacion, int duracion, string release,
string IDEpisodio, string nombreEpisodio, int temporada, int episodio) : Video(ID, nombre, genero, calificacion, 
duracion, release), IDEpisodio(IDEpisodio), nombreEpisodio(nombreEpisodio),temporada(temporada), episodio(episodio)
{
}

//Getter del atributo tipo string nombreEpisodio
string Serie::getNombreEpisodio()
{
    return nombreEpisodio;
}

//Reescribir función virtual pura
void Serie::verVideo()
{
    cout << "SERIE: " << nombre << " EPISODIO: " << nombreEpisodio << endl;
}

//Sobrecargar operador + para que regrese un double del resultado de la suma del atributo de calificación de 2
//Objetos tipo serie
double Serie::operator+(Serie &sum)
{
    return calificacion+sum.calificacion;
}