#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include "posgrado.h"

#include "posgrado.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;
using std::ofstream;
using std::ios;
using std::ifstream;


int menu(){
    int opcion, nActas;
    cout << " \033[1;31mBIENVENIDO A LA OFICINA DE POSGRADOS DE INGENIERA DE SOFTWARE, POR FAVOR DIGITE SU OPCION:\033[0m" << endl;
    cout << "\033[1;32m1.\033[0m Crear acta de grado" << endl;
    cout << "\033[1;32m2.\033[0m Modificar acta de grado" << endl;
    cout << "\033[1;32m3.\033[0m Mostrar lista Personas" << endl;
    cout << "\033[1;32m4.\033[0m Mostrar lista actas " << endl;
    cout << "\033[1;32m5.\033[0m Mostrar trabajos de grado de tipo aplicado " << endl;
    cout << "\033[1;32m6.\033[0m Mostrar trabajos de grado de tipo investigacion " << endl;
    cout << "\033[1;32m7.\033[0m Mostrar trabajos de grado dirigidos por una persona " << endl;
    cout << "\033[1;32m8.\033[0m Mostrar trabajos de grado de los que ha sido jurado una persona " << endl;
    cout << "\033[1;32m9.\033[0m Mostrar todos los jurados de las actas registradas " << endl;
    cout << "\033[1;32m10.\033[0m Consultar actas pendientes o rechazadas " << endl;
    cout << "\033[1;32m11.\033[0m Crear informacion persona " << endl;
    cout << "\033[1;32m12.\033[0m Consultar lista de jurados internos o externos " << endl;
    cout << "\033[1;32m13.\033[0m Eliminar acta " << endl;
    cout << "\033[1;32m14.\033[0m Mostrar Criterios " << endl;
    cout << "\033[1;32m15.\033[0m Mostrar lista actas cerradas o abiertas " << endl;
    cout << "\033[1;32m16.\033[0m Generar pdf " << endl;
    cout << "\033[1;32m0.\033[0m Salir\n" << endl;
    cout << "\033[1;32mDigita el numero: \033[0m";
    cin >> opcion;
    return opcion;
}

int main(){
    int opcion, i;
    Posgrado javeriana;

    do{
        opcion = menu();
        switch (opcion)
        {
        case 0:
            break;
        case 1:
            javeriana.crearActa();
            break;
        case 2:
            cout << "\n";
            javeriana.modificarActa();
            cout << "\n";
            break;
        case 3:
            javeriana.mostrarListaPersonas();
            break;
        case 4:
            cout << "\n";
            javeriana.mostrarListaActas();
            cout << "\n";
            break;
        case 5:
            javeriana.trabajosTipoAplicado();
            break;
        case 6:
            javeriana.trabajosTipoInvestigacion();
            break;
        case 7:
            javeriana.trabajosProfesor();
            break;
        case 8:
            javeriana.trabajosJurado();
            break;
        case 9:
            javeriana.mostrarListaJurados();
            break;
        case 10:
            javeriana.mostrarListasActasPendientesRechazadas();
            break;
        case 11:
            javeriana.crearInformacionPersona();
            break;    
        case 12:
            javeriana.mostrarInternosExternos();
            break;
        case 13:
            javeriana.eliminarActa();
            break;
        case 14:
            javeriana.mostrarCriterios();
            break;
        case 15:
            javeriana.mostrarListaActasAbiertasCerradas();
            break;
        case 16:
            javeriana.generarPDF();
            break;
        default:
            cout << "\nNumero invalido\n"
                      << endl;
            break;
        }
    } while (opcion != 0);

    return 0;
}