#include "posgrado.h"

//CONSTRUCTOR CLASE POSGRADO

Posgrado::Posgrado(){}

//METODOS CLASE POSGRADO

void Posgrado::crearActa(){
    time_t now = time(0); //Se inicializa una variable de tipo tiempo que cuenta el tiempo desde 0 hasta la actualidad
    tm *ltm = localtime(&now); //Se toma en la variable tm la fecha y hora del sistema
    string fecha = std::__cxx11::to_string(ltm->tm_mday) + "/" + std::__cxx11::to_string(1 + ltm->tm_mon) + "/" + std::__cxx11::to_string(1900 + ltm->tm_year); //Se guarda en el string fecha los integers de dia, mes y anio pasandolos a string con esa funcion
    int numero, selec;
    tipoTrabajoGrado tipoTrabajo;
    string nombreTrabajo, nombreEstudiante, periodo;
    Persona director, codirector, jurado1, jurado2;
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


    //Separo esto porque no se xd, puede estar bien o puede que no, de funcionar funciona todo, pero ahi ta :D


    Acta acta(numero, nombreTrabajo, nombreEstudiante, fecha, tipoTrabajo, periodo, director, codirector, jurado1, jurado2);
    this->listaActas.push_back(acta);
} //Esta pendiente directores y jurados, debido a la clase Persona 

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