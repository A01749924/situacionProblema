#ifndef PELICULA_H
#define PELICULA_H
#include <vector>
#include <string>
#include <iostream>
#include "Video.h"
using namespace std;

class Pelicula : public Video 
{
    public:
    Pelicula(string ID,string nombre,string genero,double calificacion,int duracion,string release);
};
#endif