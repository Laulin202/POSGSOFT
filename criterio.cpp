#include "criterio.h"

//CONSTRUCTOR CLASE CRITERIO

//por defecto
Criterio::Criterio(){}

/*
Nombre: Criterio
Funcion: Construye el criterio con parametros
Entrada: N/A
Salida: N/A
*/
Criterio::Criterio(int identificador, float porcentajePonderacion, string descripcion){
    this->identificador = identificador;
    this->porcentajePonderacion = porcentajePonderacion;
    this->descripcion = descripcion;
}

//METODOS CLASE CRITERIO

/*
Nombre: mostrarCriterio
Funcion: Muestra en consola el criterio con su respectivo identificador, descripcion y porcentaje de ponderacion.
Entrada: N/A
Salida: N/A
*/
void Criterio::mostrarCriterio(){
    cout << this->identificador << ". " << this->descripcion << "\nPorcentaje de ponderacion: " << this->porcentajePonderacion * 100 << "%" << endl;
}

/*
Nombre: getPorcentajePonderacion
Funcion: Retorna el porcentaje de ponderacion
Entrada: N/A
Salida: float
*/
float Criterio::getPorcentajePonderacion(){
    return this->porcentajePonderacion;
}