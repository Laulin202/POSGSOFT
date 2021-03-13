#include "criterio.h"

//CONSTRUCTOR CLASE CRITERIO

//por defecto
Criterio::Criterio(){}

Criterio::Criterio(int identificador, float porcentajePonderacion, string descripcion){
    this->identificador = identificador;
    this->porcentajePonderacion = porcentajePonderacion;
    this->descripcion = descripcion;
}

//METODOS CLASE CRITERIO

void Criterio::mostrarCriterio(){
    cout << this->identificador << ". " << this->descripcion << "\nPorcentaje de ponderacion: " << this->porcentajePonderacion * 100 << "%" << endl;
}