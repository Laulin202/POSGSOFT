#ifndef CRITERIO_H
#define CRITERIO_H

#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

class Criterio{
    private:
        int identificador;
        float porcentajePonderacion;
        string descripcion;
    public:
        Criterio();
        Criterio(int, float, string);
        void mostrarCriterio();
};


#endif