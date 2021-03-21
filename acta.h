#ifndef ACTA_H
#define ACTA_H

#include <iostream>
#include <list>
#include <string>
#include <vector>

#include <iomanip>
#include <sstream>
#include <fstream>
#include <complex>
#include <cmath>
#include "pdf.h"

#include "criterio.h"
#include "detalleCriterio.h"
#include "persona.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;
using std::vector;

using std::ostringstream;
using std::ifstream;
using std::complex;
using std::ios;


//enum tipoTrabajo

enum tipoTrabajoGrado{
    aplicado, investigacion
};

//enum para el estado del acta (abierto, cerrado)

enum estado{
    abierto, cerrado
};

enum estadoCalificacionActa{
    aprobado, pendiente, rechazada
};


//CLASE ACTA

class Acta{
    private:
        int numero;
        string nombreTrabajo;
        string nombreEstudiante;
        string fecha; 
        tipoTrabajoGrado tipoTrabajo;
        string periodo;
        Persona director; 
        Persona codirector; 
        Persona jurado1; 
        Persona jurado2; 
        vector<Criterio> listaCriterios;
        vector<DetalleCriterio> listaDetallesCriterios;
        float notaFinal;
        estado estadoActa;
        estadoCalificacionActa estadoCalificacion;
        string comentariosEspeciales;
        void inicializarListaCriterios();
    public:
        Acta(); 
        Acta(int, string, string, string, tipoTrabajoGrado, string, Persona, Persona, Persona, Persona); //pendiente directores y jurados
        void mostrarCriterios(); 
        void mostrarActa();
        int getNumero();
        tipoTrabajoGrado getTipoTrabajo();
        Persona getDirector(int);
        Persona getJurado(int);
        void diligenciarCriterios();
        void actualizarEstadoCalificacionActa();
        void cerrarActa();
        estadoCalificacionActa getEstadoCalificacionActa();
        void generarPDF();
        void mostrarDetallesCriterios();
        estado getEstadoActa();
};


#endif