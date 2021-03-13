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
    //interno =0, externo = 1
};


class Persona{
    private:
        string nombre;
        string identificacion;
        string email;
        string celular;
        clasePersonaEvaluar clasePersona;

    public:
        Persona();
        Persona( string, string, string, string, clasePersonaEvaluar );
        void mostrarPersona();
};


#endif