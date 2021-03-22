#ifndef DETALLECRITERIO_H
#define DETALLECRITERIO_H

#include <iostream>
#include <string>
#include <list>

#include "criterio.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

class DetalleCriterio{
    private:
        Criterio criterio;
        float calificacionJurado1;
        float calificacionJurado2;
        float promedioCalificacion;
        string observacion; //puede ser lista observaciones para que cada jurado agregue las que quiera(?)
    public:
        DetalleCriterio();
        DetalleCriterio( Criterio ,float, float, float, string );
        void mostrarDetalleCriterio();
        float getCalificacionJurado( int );
        string getObservacion();
};

#endif