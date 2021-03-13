#include "persona.h"

//CONSTRUCTOR CLASE PERSONA

//por defecto
Persona::Persona(){}

//para inicializar el set dummy DE POSGRADOS
Persona::Persona(string nombre, string identificacion, string email, string celular, clasePersonaEvaluar clasePersona){
    this->nombre = nombre;
    this->identificacion = identificacion;
    this->email = email;
    this->celular = celular;
    this->clasePersona = clasePersona; 
}

//METODOS CLASE PERSONA

void Persona::mostrarPersona(){
    cout << "Nombre:    " << this->nombre << endl;
    cout << "idenficicacion:    " << this->identificacion << endl;
    cout << "email:    " << this->email << endl;
    cout << "celular:    " << this->celular << endl;
    cout << "clase persona:    " << this->clasePersona << endl;
}

void Persona::mostrarNombre(){
    cout << this->nombre << endl;

}
