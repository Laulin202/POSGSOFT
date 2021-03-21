#include "detalleCriterio.h"

//CONSTRUCTOR CLASE DETALLECRITERIO

//Por defecto
DetalleCriterio::DetalleCriterio(){}

DetalleCriterio::DetalleCriterio( Criterio criterio, float calificacionJurado1, float calificacionJurado2, float promedioCalificacion, string observacion){
    this->criterio = criterio;
    this->calificacionJurado1 = calificacionJurado1;
    this->calificacionJurado2 = calificacionJurado2;
    this->promedioCalificacion = promedioCalificacion;
    this->observacion = observacion;
}

void DetalleCriterio::mostrarDetalleCriterio(){
    
    this->criterio.mostrarCriterio();
    cout << "-------------------------------------| " << endl;
    cout << "Calificacion jurado 1:               | " << this->calificacionJurado1 << endl;
    cout << "-------------------------------------| " << this->calificacionJurado1 << endl;
    cout << "Calificacion jurado 2:               | " << this->calificacionJurado2 << endl;
    cout << "-------------------------------------| " << endl;
    cout << "Promedio clasificacion del criterio  | " << this->promedioCalificacion << endl;
    cout << "-------------------------------------| " << endl;
    cout << "Observaciones:                        " << endl;
    cout << this->observacion << endl;

}