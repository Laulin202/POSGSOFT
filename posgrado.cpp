#include "posgrado.h"

//CONSTRUCTOR CLASE POSGRADO

Posgrado::Posgrado(){
    this->setDummyData(); //este metodo inicialara una lisa de personas mientas tanto (POTENCIAL PARA SER LA FUNCION CARGAR)
}

void Posgrado::setDummyData(){
    this->listaPersonas.push_back( Persona("Luisa Rincon","1001","lufe@gmail.com","300045439", interno) );
    this->listaPersonas.push_back( Persona("Joancito Popoloko","1002","elmejorProfedelmundo@gmail.com","3284845439", interno) );
    this->listaPersonas.push_back( Persona("Jhoan Buitrago","1003","jhoanuitrago@gmail.com","3428245439", interno) );
}

//METODOS CLASE POSGRADO

//Nombre: crearActa
void Posgrado::crearActa(){
    int numero, selec;
    tipoTrabajoGrado tipoTrabajo;
    string nombreTrabajo, nombreEstudiante, periodo;
    Persona director, codirector, jurado1, jurado2;

    //FECHA DEL COMPUTADOR
    time_t now = time(0); //Se inicializa una variable de tipo tiempo que cuenta el tiempo desde 0 hasta la actualidad
    tm *ltm = localtime(&now); //Se toma en la variable tm la fecha y hora del sistema
    string fecha = std::__cxx11::to_string(ltm->tm_mday) + "/" + std::__cxx11::to_string(1 + ltm->tm_mon) + "/" + std::__cxx11::to_string(1900 + ltm->tm_year); //Se guarda en el string fecha los integers de dia, mes y anio pasandolos a string con esa funcion

    
    cout << "Digite el numero del acta: ";
    cin >> numero;

    cout << "Ingrese el nombre del estudiante a cargo del acta: ";
    cin.ignore(100, '\n');
    getline(cin, nombreEstudiante);

    cout << "Ingrese el nombre del trabajo del acta de grado: ";
    getline(cin, nombreTrabajo);

    do{
        cout << "Seleccione el tipo de trabajo:\n0. Aplicado\n1. Investigacion" << endl;
        cin >> selec;
        if(selec == 0){
            tipoTrabajo = aplicado;
        } else if(selec == 1){
            tipoTrabajo = investigacion;
        } else{
            cout << "Ingrese una opcion valida por favor." << endl;
        }
    } while(selec != 0 && selec != 1);

    cout << "Ingrese el periodo en el que se realizo el acta: ";
    cin >> periodo;

    //Apartado director
    cout << "Seleccione el director (o en su defecto puede agregar uno): " << endl;
    this->mostrarListaPersonas();
    cout << "0. Agregar director" << endl;
    cin >> selec;
    if(selec == 0){
        this->crearInformacionPersona();
        director = this->listaPersonas.back();
    } else{
        director = this->listaPersonas[selec - 1]; 
    }

    //Apartado Codirector
    cout << "Desea agregar un codirector?\n1. Si\n2. No" << endl;
    cin >> selec;
    if(selec == 1){
        cout << "Seleccione el codirector (o en su defecto puede agregar uno): " << endl;
        this->mostrarListaPersonas();
        cout << "0. Agregar codirector" << endl;
        cin >> selec;
        if(selec == 0){
            this->crearInformacionPersona();
            codirector = this->listaPersonas.back();
        } else{
            codirector = this->listaPersonas[selec - 1];
        }
    } else{
        Persona codirectorFantasma;
        codirector = codirectorFantasma;
    }

    //apartado jurado
    cout << "Seleccione el jurado numero 1 (o en su defecto puede agregar uno): " << endl;
    this->mostrarListaPersonas();
    cout << "0. Agregar jurado" << endl;
    cin >> selec;
    if(selec == 0){
        this->crearInformacionPersona();
        jurado1 = this->listaPersonas.back();
    } else{
        jurado1 = this->listaPersonas[selec - 1]; 
    }

    cout << "Seleccione el jurado numero 2 (o en su defecto puede agregar uno): " << endl;
    this->mostrarListaPersonas();
    cout << "0. Agregar jurado" << endl;
    cin >> selec;
    if(selec == 0){
        this->crearInformacionPersona();
        jurado2 = this->listaPersonas.back();
    } else{
        jurado2 = this->listaPersonas[selec - 1]; 
    }

    //se envia el acta
    Acta acta( numero, nombreTrabajo, nombreEstudiante, fecha, tipoTrabajo, periodo, director, codirector, jurado1, jurado2 );
    this->listaActas.push_back(acta);

} //Esta pendiente directores y jurados, debido a la clase Persona 

//Nombre: mostrarListaPersonas 
//Funcion muestra el nombre de las personas de la lista personas
void Posgrado::mostrarListaPersonas(){
    if(this->listaPersonas.size() == 0){
        cout << "Por el momento no se encuentran personas registradas en el sistema, proceda a agregar." << endl;
    } else{
        for(int i = 0; i < this->listaPersonas.size(); i++){
            cout << i + 1 << ". ";
            this->listaPersonas[i].mostrarNombre();
        }
    }
} //Cree esta funcion para que la asistenta pueda escoge de la lista de personas a quienes quiere como director, codirector y jurados

//Clase: Posgrado
//Nombre: crearInformacionPersona
//Funcion: Crea una nueva persona y la agrega a la a lista de personas 
void Posgrado::crearInformacionPersona(){
    int selec;
    string nombre, identificacion, email, celular;
    clasePersonaEvaluar clasePersona;

    cout << "Ingrese el nombre de la persona: ";
    cin.ignore(100, '\n');
    getline(cin, nombre);

    cout << "Ingrese el numero de identificacion de la persona: ";
    cin >> identificacion;

    cout << "Ingrese el email de la persona: ";
    cin >> email;

    cout << "Ingrese el numero de celular de la persona: ";
    cin >> celular;

    do{
        cout << "Seleccione el tipo de relacion con la universidad:\n0. Interno\n1. Externo" << endl;
        cin >> selec;
        if(selec == 0){
            clasePersona = interno;
        } else if(selec == 1){
            clasePersona = externo;
        } else{
            cout << "Ingrese una opcion valida por favor." << endl;
        }

    } while(selec != 0 && selec != 1);
    
    Persona persona(nombre, identificacion, email, celular, clasePersona);

    this->listaPersonas.push_back(persona);
    
} //Me adelante un poquito pues esta funcionalidad es de las ultimas que se piden, pero la vi necesaria para el crearActa

void Posgrado::mostrarListaActas(){
    if(this->listaActas.size() == 0){
        cout << "Oops, parece que aun no hay ningun acta en el sistema, porfavor cree una e intente nuevamente." << endl;
    }
    else{
        for( int i = 0; i < this->listaActas.size(); i++){
            this->listaActas[i].mostrarActa();
        }
    }
}

Acta* Posgrado::buscarActa( int numero){
    Acta* p_acta;
    for( int i = 0; i < this->listaActas.size(); i++){
        if( numero == listaActas[i].getNumero()){ //PENDIENTE Funcion getNumero
            p_acta = &this->listaActas[i];
            break;
        }
    }
    return p_acta;
}


void Posgrado::modificarActa(){
    int opcion, numero;
    Acta * pActa;


    cout << "-----------MODIFICAR ACTA-------------" << endl;

    cout << " Digite el codigo del acta a modificar: " << endl;
    cin >> numero;
    pActa = this->buscarActa( numero );
    pActa->mostrarActa();
    //funcion buscarActa;

    cout << " ¿Que desea hacer con el acta de evaluacion? " << endl;
    cout << "====================" << endl;
    cout << "1. Diligenciar Acta." << endl;
    cin >> opcion;

    //Aqui se dividen las opciones donde se pueden hacer con el acta :)



    switch (opcion){
        case 1:
            pActa->diligenciarCriterios();
        break;
    
        default:
        break;
    }

}

/*
Criterio criterio;
        float calificacionJurado1;
        float calificacionJurado2;
        float promedioCalificacion;
        string observacion; /
*/