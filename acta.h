#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <list>
#include <string>

#include "criterio.h"
#include "persona.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;


//enum tipoTrabajo

enum tipoTrabajoGrado{
    aplicado, investigacion
};

//enum para el estado del acta (abierto, cerrado)

enum estado{
    abierto, cerrado
};

enum estadoCalificacionActa{
    aprobado, pendiente, rechazada
};


//CLASE ACTA

class Acta{
    private:
        int numero;
        string nombreTrabajo;
        string nombreEstudiante;
        string fecha; //pendiente averiguar la clase fecha
        tipoTrabajoGrado tipoTrabajo;
        string periodo;
        Persona director; //PENDIENTE LA CLASE PERSONA
        Persona codirector; //PENDIENTE LA CLASE PERSONA
        Persona jurado1; //PENDIENTE LA CLASE PERSONA
        Persona jurado2; //PENDIENTE LA CLASE PERSONA
        list<Criterio> listaCriterios;//PENDIENTE LA CLASE CRITERIO no sabemos si usaremos vectores 
        float notaFinal;
        estado estado;
        estadoCalificacionActa estadoCalificacion;
    public:
        Acta(); //pendiente el constuctor 
};


#endif