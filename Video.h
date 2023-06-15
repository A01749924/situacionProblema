// A
#ifndef VIDEO_H
#define VIDEO_H
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Video
{
    protected:
        string ID;
        string nombre;
        string genero;
        double calificacion;
        int duracion;
        string release;
    public:
        Video(string ID,string nombre,string genero,double calificacion,int duracion,string release);
        virtual void verVideo();
        double getCalificacion();
        string getGenero();
        void setCalificacion(double calificacion);
        string getNombre();
};
#endif
