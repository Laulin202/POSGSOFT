#ifndef PERSONA_H
#define PERSONA_H


#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;


enum clasePersonaEvaluar{
    interno, externo
};


class Persona{
    private:
        string nombre;
        string identificacion;
        string email;
        string celular;
        clasePersonaEvaluar clasePersona;
        list<int> codigoActasJurado; //o dejarlo como acta NOSEEEE
        list<int> codigoActasDirector;

    public:
        Persona();
};


#endif