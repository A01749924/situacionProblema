#include "Video.h"

Video::Video(string ID, string nombre, string genero, double calificacion, int duracion, string release)
{
    this->ID=ID;
    this->nombre=nombre;
    this->genero=genero;
    this->calificacion=calificacion;
    this->duracion=duracion;
    this->release=release;
}

double Video::getCalificacion()
{
    return calificacion;
}

string Video::getGenero()
{
    return genero;
}

void Video::setCalificacion(double calificacion)
{
    this->calificacion=calificacion;
}

string Video::getNombre()
{
    return nombre;
}
