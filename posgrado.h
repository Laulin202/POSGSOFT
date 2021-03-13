#ifndef POSGRADO_H
#define POSGRADO_H

//PENDIENTE: agregar la modalidad vector 

#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <ctime>

#include "acta.h"
#include "persona.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;
using std::vector;

//CLASE POSGRADO 

class Posgrado{
    private:
        vector<Acta> listaActas;      ////// vectores para hacer la busqueda mas facil 
        vector<Persona> listaPersonas;  ///////
        void setDummyData();
    public:
        Posgrado();
        void crearActa();
        void mostrarListaPersonas();
        void crearInformacionPersona();
};


//PENDIENTE


#endif