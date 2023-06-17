/*
Autor: José Luis Del Alto Ordorica      A01749924       ITD
Situación Problema
Archivo .h de la clase Video
*/

//Verificar que se defina sólo una vez
#ifndef VIDEO_H
#define VIDEO_H
//Incluir librerías
#include <vector>
#include <string>
#include <iostream>
using namespace std;

//Definir clase abstracta
class Video
{
    //Declarar variables protected
    protected:
        string ID;
        string nombre;
        string genero;
        double calificacion;
        int duracion;
        string release;
    //Declarar métodos públicos
    public:
        //Constructor con parámetros
        Video(string ID,string nombre,string genero,double calificacion,int duracion,string release);
        virtual void verVideo() = 0;            //Función abstracta
        //Getters
        double getCalificacion();
        string getGenero();
        string getNombre();
        //Setters
        void setCalificacion(double calificacion);
};
#endif
