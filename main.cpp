#include <iostream>
#include <string>
#include <list>
#include "posgrado.h"

#include "posgrado.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::list;

//PARA RECORDAR
/*
cout << "Escribe tu nombre : ";
   string nombre;
   getline(cin, nombre);
*/

int menu(){
    int opcion;
    cout << " BIENVENIDO A LA OFICINA DE POSGRADOS DE INGENIERA DE SOFTWARE, POR FAVOR DIGITE SU OPCION:" << endl;
    cout << "1. Crear acta de grado" << endl;
    cout << "2. Modificar acta de grado" << endl;
    cout << "3. Mostrar lista Personas" << endl;
    cout << "4. Mostrar lista actas " << endl;
    cout << "5. Mostrar trabajos de grado de tipo aplicado " << endl;
    cout << "6. Mostrar trabajos de grado de tipo investigacion " << endl;
    cout << "7. Mostrar trabajos de grado dirigidos por una persona " << endl;
    cout << "8. Mostrar trabajos de grado de los que ha sido jurado una persona " << endl;
    cout << "9. En proceso" << endl;
    cout << "0. Salir\n" << endl;
    cout << "Digita el numero: ";
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
        default:
            cout << "\nNumero invalido\n"
                      << endl;
            break;
        }
    } while (opcion != 0);

   

    return 0;
}