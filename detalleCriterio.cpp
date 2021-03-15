#include "detalleCriterio.h"

//CONSTRUCTOR CLASE DETALLECRITERIO

//Por defecto
DetalleCriterio::DetalleCriterio(){}

DetalleCriterio::DetalleCriterio( Criterio criterio,float calificacionJurado1, float calificacionJurado2, float promedioCalificacion, string observacion){
    this->calificacionJurado1 = calificacionJurado1;
    this->calificacionJurado2 = calificacionJurado2;
    this->promedioCalificacion = promedioCalificacion;
    this->observacion = observacion;
}