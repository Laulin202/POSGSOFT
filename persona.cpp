#include "persona.h"

//CONSTRUCTOR CLASE PERSONA

//por defecto
Persona::Persona(){}

Persona::Persona(string nombre, string identificacion, string email, string celular, clasePersonaEvaluar clasePersona){
    this->nombre = nombre;
    this->identificacion = identificacion;
    this->email = email;
    this->celular = celular;
    this->clasePersona = clasePersona;
}

//METODOS CLASE PERSONA

void Persona::mostrarNombre(){
    cout << this->nombre << endl;
}
