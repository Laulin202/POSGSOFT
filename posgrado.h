#ifndef POSGRADO_H
#define POSGRADO_H


#include <iostream>
#include <fstream>
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
using std::ofstream;
using std::ios;
using std::ifstream;

//CLASE POSGRADO 

class Posgrado{
    private:
        vector<Acta> listaActas;      ////// vectores para hacer la busqueda mas facil 
        vector<Persona> listaPersonas;  ///////
        void setDummyData();
    public:
        Posgrado();
        void crearActa();
        void modificarActa();
        void mostrarListaPersonas();
        void crearInformacionPersona();
        void mostrarListaActas();
        Acta* buscarActa( int ); //tiene que retornar un puntero a acta por que quiero que se actualice en la lista
        void trabajosTipoAplicado();
        void trabajosTipoInvestigacion();
        void trabajosProfesor();
        void trabajosJurado();
        void mostrarListaJurados();
        void mostrarListasActasPendientesRechazadas();
        void mostrarInternosExternos();
        void eliminarActa();
        void mostrarCriterios();
        void mostrarListaActasAbiertasCerradas();
        void generarPDF();
};


//PENDIENTE


#endif