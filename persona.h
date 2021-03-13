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
        //dejo por aqui la idea de un posible booleano para verificar si es jurado o no, espero estar vivo para explicarle esto xd
        clasePersonaEvaluar clasePersona;
        list<int> codigoActasJurado; //o dejarlo como acta NOSEEEE / xd con actas se complicaria demasiado, pues estariamos manejando dos o hasta tres listas de actas, y por ejemplo esta lista y la principal no van a ser como tal las mismas actas, seran copias, asi que seria ineficiente
        list<int> codigoActasDirector;
    public:
        Persona();
        Persona(string, string, string, string, clasePersonaEvaluar);
        void mostrarNombre();
};

//Todo lo relacionado a persona aun lo tengo muy en duda porque necesito tu aprobacion y eso xd

#endif