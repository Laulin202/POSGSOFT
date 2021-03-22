#include "detalleCriterio.h"

//CONSTRUCTOR CLASE DETALLECRITERIO

//Por defecto
DetalleCriterio::DetalleCriterio(){}

/*
Nombre: DetalleCriterio
Funcion: inicializa el objeto DetalleCriterio con un objeto criterio, calificacion del jurado1, calificacion jurado 2, promedio calificacion, y observacion
Entrada: Criterio, float, float, float, string
Salida: n/a
*/
DetalleCriterio::DetalleCriterio( Criterio criterio, float calificacionJurado1, float calificacionJurado2, float promedioCalificacion, string observacion){
    this->criterio = criterio;
    this->calificacionJurado1 = calificacionJurado1;
    this->calificacionJurado2 = calificacionJurado2;
    this->promedioCalificacion = promedioCalificacion;
    this->observacion = observacion;
}

/*
Nombre: mostrarDetalleCriterio
Funcion: muestra la informacion del DetalleCriterio
Entrada: n/a
Salida: n/a
*/
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

/*
Nombre: getCalificacionJurado
Funcion: retorna la calificacion del jurado 1 o 2
Entrada: int(num)
Salida: float
*/
float DetalleCriterio::getCalificacionJurado( int num ){
    if( num == 1)
        return this->calificacionJurado1;
    else
        return this->calificacionJurado2;
}

/*
Nombre: getObservacion
Funcion: retorna la observacion 
Entrada: n/a
Salida: string(observacion)
*/
string DetalleCriterio::getObservacion(){
    return this->observacion;
}