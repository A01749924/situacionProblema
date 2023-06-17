/*
Autor: José Luis Del Alto Ordorica      A01749924       ITD
Situación Problema
Archivo Video.cpp
*/

//Incluir .h
#include "Video.h"

//Constructor con parámetros
Video::Video(string ID, string nombre, string genero, double calificacion, int duracion, string release)
{
    this->ID=ID;
    this->nombre=nombre;
    this->genero=genero;
    this->calificacion=calificacion;
    this->duracion=duracion;
    this->release=release;
}

//Getter del atributo tipo double calificacion
double Video::getCalificacion()
{
    return calificacion;
}

//Getter del atributo tipo string genero
string Video::getGenero()
{
    return genero;
}

//Setter del atributo tipo string calificacion para poder modificarlo desde el main
void Video::setCalificacion(double calificacion)
{
    this->calificacion=calificacion;
}

//Getter del atributo tipo string nombre
string Video::getNombre()
{
    return nombre;
}
