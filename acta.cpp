#include "acta.h"

//CONSTRUCTOR CLASE ACTA

//por defecto
Acta::Acta(){}

Acta::Acta(int numero, string nombreTrabajo, string nombreEstudiante, string fecha, tipoTrabajoGrado tipoTrabajo, string periodo, Persona director, Persona codirector, Persona jurado1, Persona jurado2){
    this->numero = numero;
    this->nombreTrabajo = nombreTrabajo;
    this-> nombreEstudiante = nombreEstudiante;
    this->fecha = fecha;
    this->tipoTrabajo = tipoTrabajo;
    this->periodo = periodo;
    this->director = director;
    this->codirector = codirector;
    this->jurado1 = jurado1;
    this->jurado2 = jurado2;
    this->notaFinal = 0.0;
    this->estadoActa = abierto;
    this->estadoCalificacion = pendiente;
    //inicializa los 8 criterios (seran los mismos siempre)
    this->inicializarListaCriterios();
} //pendiente directores y jurados

void Acta::inicializarListaCriterios(){
    int identificador;
    float porcentajePonderacion;
    string descripcion;
    for(int i = 1; i <= 8; i++){
        identificador = i;
        switch( i ){
            case 1:
                descripcion = "Desarrollo y profundidad en el tratamiento del tema: ";
                porcentajePonderacion = 0.2;
                break;
            case 2:
                descripcion = "Desafio academico y cientifico del tema: ";
                porcentajePonderacion = 0.15;
                break;
            case 3:
                descripcion = "Cumplimiento de los objetivos propuestos: ";
                porcentajePonderacion = 0.1;
                break;
            case 4:
                descripcion = "Creatividad e innovacion de las soluciones y desarrollos propuestos: ";
                porcentajePonderacion = 0.1;
                break;
            case 5:
                descripcion = "Validez de los resultados y conclusiones: ";
                porcentajePonderacion = 0.2;
                break;
            case 6:
                descripcion = "Manejo y procesamiento de la informacion y bibliografia: ";
                porcentajePonderacion = 0.1;
                break;
            case 7:
                descripcion = "Calidad y presentacion del documento escrito: ";
                porcentajePonderacion = 0.075;
                break;
            case 8:
                descripcion = "Presentacion oral: ";
                porcentajePonderacion = 0.075;
                break;
        }
        Criterio criterio(identificador, porcentajePonderacion, descripcion);
        this->listaCriterios.push_back(criterio);
    }
}

//METODOS CLASE ACTA

void Acta::mostrarCriterios(){
    for(int i = 0; i < this->listaCriterios.size(); i++){
        this->listaCriterios[i].mostrarCriterio();
    }
} //funcion de prueba

void Acta::mostrarActa(){

    cout << "=================================================" << endl;
    cout << "        "<< this->nombreTrabajo << "            "<< endl;
    cout << " Estudiante: " << this->nombreEstudiante << endl;
    cout << " Fecha: " << this->fecha << endl;
    cout << " Tipo trabajo: " << this->tipoTrabajo << endl;
    cout << " Periodo: " << this->periodo << endl;
    cout << " Director: ";
    this->director.mostrarNombre();
    cout << endl << " Codirector: ";
    this->codirector.mostrarNombre();
    cout << endl << " Jurado 1: ";
    this->jurado1.mostrarNombre();
    cout << endl << " Jurado 2: ";
    this->jurado2.mostrarNombre();
    cout << endl << " Nota final: " << this->notaFinal << endl;
    cout << " Estado acta: " << (this->estadoActa == 0 ? "abierto" : "cerrado") << endl; // pendiente acomodar por que retornara un int
    cout << " Estado calificacion: ";
    if(this->estadoCalificacion == 0)
        cout << "aprobado";
    else if(this->estadoCalificacion == 1)
        cout << "pendiente";
    else
        cout << "rechazado";
    cout << endl;
    cout << "=================================================" << endl;

}

