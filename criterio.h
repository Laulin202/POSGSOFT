#ifndef CRITERIO_H
#define CRITERIO_H

#include <iostream>
#include <list>
#include <string>


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

class Criterio{
    private:
        int identificador;
        float procentajePonderacion;
        string descripcion;
        float calificacionJurado1;
        float calificacionJurado2;
        float promedioCalificacion;
        string observacion; //puede ser lista observaciones para que cada jurado agregue las que quiera(?
    public:
        Criterio();

};


#endif