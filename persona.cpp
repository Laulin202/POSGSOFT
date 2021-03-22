#include "persona.h"

//CONSTRUCTOR CLASE PERSONA

//por defecto
Persona::Persona(){

}

/*
Nombre: Persona
Funcion: Iniciliza el objeto Persona con nombre, identificacion, email, celular, clase persona(interno/externo), y el bool jurado
Entrada: string(nombre), string(identificacion), string(email), string(celular), clasePersonaEvaluar(clasePersona)
Salida: n/a
*/
Persona::Persona(string nombre, string identificacion, string email, string celular, clasePersonaEvaluar clasePersona){
    this->nombre = nombre;
    this->identificacion = identificacion;
    this->email = email;
    this->celular = celular;
    this->clasePersona = clasePersona; 
    this->jurado = false;
}

//METODOS CLASE PERSONA

/*
Nombre: mostrarPersona
Funcion: muestra la informacion de la persona
Entrada: n/a
Salida: n/a
*/
void Persona::mostrarPersona(){
    cout << "Nombre:    " << this->nombre << endl;
    cout << "Idenficacion:    " << this->identificacion << endl;
    cout << "Email:    " << this->email << endl;
    cout << "Celular:    " << this->celular << endl;
    cout << "Clase persona:    " << this->clasePersona << endl;
}

/*
Nombre: mostrarNombre
Funcion: muestra el nombre
Entrada: n/a
Salida: n/a
*/
void Persona::mostrarNombre(){
    cout << this->nombre;
}

/*
Nombre: getID
Funcion: retorna la identificacion
Entrada: n/a
Salida: string(identificacion)
*/
string Persona::getID(){
    return this->identificacion;
}

/*
Nombre: getClasePersona
Funcion: retorna la clase a la cual pertenece la persona (interno/externo)
Entrada: n/a
Salida: clasePersonaEvaluar(clasePersona)
*/
clasePersonaEvaluar Persona::getClasePersona(){
    return this->clasePersona;
}

/*
Nombre: setJurado
Funcion: cambia el valor bool jurado a "true" en caso de que sea seleccionado para ser jurado en algun acta
Entrada: n/a
Salida: n/a
*/
void Persona::setJurado(){
    this->jurado = true;
}

/*
Nombre: validarJurado
Funcion: retorna el bool jurado
Entrada: n/a
Salida: bool(jurado)
*/
bool Persona::validarJurado(){
    return this->jurado;
}

/*
Nombre: validarJurado
Funcion: retorna el bool jurado
Entrada: n/a
Salida: bool(jurado)
*/
string Persona::getNombre(){
    return this->nombre;
}

