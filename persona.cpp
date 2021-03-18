#include "persona.h"

//CONSTRUCTOR CLASE PERSONA

//por defecto
Persona::Persona(){

}

//para inicializar el set dummy DE POSGRADOS
Persona::Persona(string nombre, string identificacion, string email, string celular, clasePersonaEvaluar clasePersona){
    this->nombre = nombre;
    this->identificacion = identificacion;
    this->email = email;
    this->celular = celular;
    this->clasePersona = clasePersona; 
    this->jurado = false;
}

//METODOS CLASE PERSONA

void Persona::mostrarPersona(){
    cout << "Nombre:    " << this->nombre << endl;
    cout << "Idenficacion:    " << this->identificacion << endl;
    cout << "Email:    " << this->email << endl;
    cout << "Celular:    " << this->celular << endl;
    cout << "Clase persona:    " << this->clasePersona << endl;
}

void Persona::mostrarNombre(){
    cout << this->nombre;
}

string Persona::getID(){
    return this->identificacion;
}

clasePersonaEvaluar Persona::getClasePersona(){
    return this->clasePersona;
}

void Persona::setJurado(){
    this->jurado = true;
}

bool Persona::validarJurado(){
    return this->jurado;
}


