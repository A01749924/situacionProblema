/*
Autor: José Luis Del Alto Ordorica      A01749924       ITD
Situación Problema
Archivo .h de la clase Pelicula
*/

//Verificar que se defina sólo una vez
#ifndef PELICULA_H
#define PELICULA_H
//Incluir librerías
#include <vector>
#include <string>
#include <iostream>
#include "Video.h"
using namespace std;

//Declarar clase que hereda de lo público de video
class Pelicula : public Video 
{
    //Declarar métodos públicos
    public:
    //Constructor con parámetros
    Pelicula(string ID,string nombre,string genero,double calificacion,int duracion,string release);
    //Reescribir método abstracto heredado
    void verVideo();
};
#endif