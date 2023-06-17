/*
Autor: José Luis Del Alto Ordorica      A01749924       ITD
Situación Problema
Archivo Pelicula.cpp
*/

//Incluir .h
#include "Pelicula.h"

//Constructor con parámetros que hereda de Video
Pelicula::Pelicula(string ID, string nombre, string genero, double calificacion, int duracion, string release) :
Video(ID,nombre,genero,calificacion,duracion,release)
{
}

//Reescribir función virtual pura
void Pelicula::verVideo()
{
    cout << "PELÍCULA: " << nombre << endl;
}
