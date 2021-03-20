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
    this->comentariosEspeciales = " ";
    //inicializa los 8 criterios (seran los mismos siempre)
    this->inicializarListaCriterios();
}

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
    cout << " Tipo trabajo: " << (this->tipoTrabajo == 0 ? "Aplicado" : "Investigacion") << endl;
    cout << " Periodo: " << this->periodo << endl;
    cout << " Director: ";
    this->director.mostrarNombre();
    cout << endl;
    cout << " Codirector: ";
    if(this->codirector.getID() == ""){
        cout << "NA";
    } else{
        this->codirector.mostrarNombre();
    }
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

int Acta::getNumero(){
    return this->numero;
}

void Acta::diligenciarCriterios(){
    float calificacionJurado1, calificacionJurado2, promedioCalificacion;
    string observacion;
    Criterio criterio;
    int opcion;

    for( int i = 0; i < listaCriterios.size(); i++){

        criterio = this->listaCriterios[i];

        cout << "==============================" << endl;
        cout << "       Criterio " << i + 1 << endl;

        cout << "Digite calificacion jurado 1: " << endl;
        cin >> calificacionJurado1;

        cout << "Digite calificacion jurado 2: " << endl;
        cin >> calificacionJurado2;

        promedioCalificacion = ((calificacionJurado1 + calificacionJurado2)/2) * criterio.getPorcentajePonderacion();
        cout << "El promedio de calificacion del criterio es: " << promedioCalificacion << endl;

        cout << "Digite observaciones " << endl;
        cin.ignore(100, '\n');
        getline(cin, observacion);

        this->listaDetallesCriterios.push_back(DetalleCriterio( criterio ,calificacionJurado1, calificacionJurado2, promedioCalificacion, observacion));

        this->notaFinal += promedioCalificacion;
    }
    cout << " La nota final es: " << this->notaFinal << endl;
    cout << "Desea añadir comentarios especiales?\n1. Si\n2.No" << endl;
    cin >> opcion;
    if( opcion == 1){
        cout << " Por favor digite el comentario: " << endl;
        cin.ignore(100, '\n');
        getline(cin, this->comentariosEspeciales);
    }
    else{
        cout << " Se ha finalizado correctamente el proceso para su acta! " << endl;
    }
    this->actualizarEstadoCalificacionActa();

}

void Acta::actualizarEstadoCalificacionActa(){
    if( this->notaFinal >= 3.5 ){
        if( this->comentariosEspeciales == " " ){
            this->estadoCalificacion = aprobado;
        }
        else{
            this->estadoCalificacion = pendiente;
        }
    }
    else{
        this->estadoCalificacion = rechazada;
    }
}

tipoTrabajoGrado Acta::getTipoTrabajo(){
    return this->tipoTrabajo;
}

Persona Acta::getDirector(int n){
    return n == 1 ? this->director : this->codirector;
}

Persona Acta::getJurado(int n){
    return n == 1 ? this->jurado1 : this->jurado2;
}

void Acta::cerrarActa(){
    int op;
    if( this->estadoActa == cerrado){
        cout << "Oops, El acta seleccionada ya se encuentra cerrada! :)" << endl;
    }
    else{
        if( this->estadoCalificacion == pendiente ){
            cout << "El acta seleccionada se encuentra con comentarios especificos sujeta a la calificacion, ¿Continuar de todos modos?" << endl;
            cin >> op;
            if( op == 1 ){
                this->estadoActa = cerrado;
            }
        }
    }
}

estadoCalificacionActa Acta::getEstadoCalificacionActa(){
    return this->estadoCalificacion;
}

estado Acta::getEstadoActa(){
    return this->estadoActa;
}

void Acta::mostrarDetallesCriterios(){
    for(int i = 0; i < this->listaDetallesCriterios.size(); i++){
        this->listaDetallesCriterios[i].mostrarDetalleCriterio(); //pendiente crear 
    }
}