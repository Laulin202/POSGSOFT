#include "posgrado.h"

//CONSTRUCTOR CLASE POSGRADO

Posgrado::Posgrado(){
    this->setDummyData(); //este metodo inicialara una lisa de personas mientas tanto (POTENCIAL PARA SER LA FUNCION CARGAR)
}

/*
Nombre: setDummyData
Funcion: inicializa la listaPersonas con 3 objetos Persona apenas se cree un objeto de tipo Posgrado
Entrada: n/a
Salida: n/a
*/
void Posgrado::setDummyData(){
    this->listaPersonas.push_back( Persona("Luisa Rincon","1001","lufe@gmail.com","300045439", interno) );
    this->listaPersonas.push_back( Persona("Joancito Popoloko","1002","elmejorProfedelmundo@gmail.com","3284845439", interno) );
    this->listaPersonas.push_back( Persona("Jhoan Buitrago","1003","jhoanuitrago@gmail.com","3428245439", interno) );
}

//METODOS CLASE POSGRADO

/*
Nombre: crearActa
Funcion: pide la informacion necesaria para crear un Acta, y finaliza creando el acta y colocandola a la listaActas
Entrada: n/a
Salida: n/a
*/
void Posgrado::crearActa(){
    bool continuar = true;
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
        cout << "Seleccione el tipo de trabajo:\n\033[1;32m0.\033[0m Aplicado\n\033[1;32m1.\033[0m Investigacion" << endl;
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
    do{
        try{
            cout << "Seleccione el director (o en su defecto puede agregar uno): " << endl;
            this->mostrarListaPersonas();
            cout << "\033[1;32m0.\033[0m Agregar director" << endl;
            cin >> selec;
            if(selec < 0 || selec > this->listaPersonas.size()){
                throw 1;
            }
            if(selec == 0){
                this->crearInformacionPersona();
                director = this->listaPersonas.back();
            } else{
                director = this->listaPersonas[selec - 1]; 
            }
            continuar = false;
        } catch(...){
            cout << "Seleccione una opcion valida, por favor." << endl;
        }
    } while(continuar);

    //Apartado Codirector
    continuar = true;
    cout << "Desea agregar un codirector?\n\033[1;32m1.\033[0m Si\n\033[1;32m2.\033[0m No" << endl;
    cin >> selec;
    if(selec == 1){
        do{
            try{
                cout << "Seleccione el codirector (o en su defecto puede agregar uno): " << endl;
                this->mostrarListaPersonas();
                cout << "\033[1;32m0.\033[0m Agregar codirector" << endl;
                cin >> selec;
                if(selec < 0 || selec > this->listaPersonas.size()){
                    throw 1;
                }
                if(selec == 0){
                    this->crearInformacionPersona();
                    codirector = this->listaPersonas.back();
                } else{
                    codirector = this->listaPersonas[selec - 1];
                    if(codirector.getID() == director.getID()){
                        throw 2;
                    }
                }
                continuar = false;
            } catch(int error){
                if(error == 1){
                    cout << "Seleccione una opcion valida, por favor." << endl;
                } else if(error == 2){
                    cout << "El/la senior/a ";
                    codirector.mostrarNombre();
                    cout << " ya se encuentra inscrita como director/a en esta acta." << endl;
                }
            }
        } while(continuar);
    } else{
    }

    //apartado jurado1
    continuar = true;
    do{
        try{
            cout << "Seleccione el jurado numero 1 (o en su defecto puede agregar uno): " << endl;
            this->mostrarListaPersonas();
            cout << "\033[1;32m0.\033[0m Agregar jurado" << endl;
            cin >> selec;
            if(selec < 0 || selec > this->listaPersonas.size()){
                throw 1;
            }
            if(selec == 0){
                this->crearInformacionPersona();
                jurado1 = this->listaPersonas.back();
                this->listaPersonas.back().setJurado();
            } else{
                jurado1 = this->listaPersonas[selec - 1];
                if(jurado1.getID() == director.getID()){
                    throw 2;
                } else if(jurado1.getID() == codirector.getID()){
                    throw 3;
                }
                this->listaPersonas[ selec - 1 ].setJurado();
            }
            continuar = false;
        } catch(int error){
            if(error == 1){
                cout << "Seleccione una opcion valida, por favor." << endl;
            } else if(error == 2){
                cout << "El/la senior/a ";
                director.mostrarNombre();
                cout << " ya se encuentra inscrita como director/a en esta acta." << endl;
            } else if(error == 3){
                cout << "El/la senior/a ";
                codirector.mostrarNombre();
                cout << " ya se encuentra inscrita como codirector/a en esta acta." << endl;
            }
        }
    } while(continuar);

    //apartado jurado2
    continuar = true;
    do{
        try{
            cout << "Seleccione el jurado numero 2 (o en su defecto puede agregar uno): " << endl;
            this->mostrarListaPersonas();
            cout << "\033[1;32m0.\033[0m Agregar jurado" << endl;
            cin >> selec;
            if(selec < 0 || selec > this->listaPersonas.size()){
                throw 1;
            }
            if(selec == 0){
                this->crearInformacionPersona();
                jurado2 = this->listaPersonas.back();
                this->listaPersonas.back().setJurado();
            } else{
                jurado2 = this->listaPersonas[selec - 1];
                if(jurado2.getID() == director.getID()){
                    throw 2;
                } else if(jurado2.getID() == codirector.getID()){
                    throw 3;
                } else if(jurado2.getID() == jurado1.getID()){
                    throw 4;
                }
                this->listaPersonas[ selec - 1 ].setJurado();  
            }
            jurado2.setJurado();
            continuar = false;
        } catch(int error){
            if(error == 1){
                cout << "Seleccione una opcion valida, por favor." << endl;
            } else if(error == 2){
                cout << "El/la senior/a ";
                director.mostrarNombre();
                cout << " ya se encuentra inscrita como director/a en esta acta." << endl;
            } else if(error == 3){
                cout << "El/la senior/a ";
                codirector.mostrarNombre();
                cout << " ya se encuentra inscrita como codirector/a en esta acta." << endl;
            } else if(error == 4){
                cout << "El/la senior/a ";
                jurado1.mostrarNombre();
                cout << " ya se encuentra inscrita como jurado/a 1 en esta acta." << endl;
            }
        }
    } while(continuar);

    //se envia el acta
    Acta acta( numero, nombreTrabajo, nombreEstudiante, fecha, tipoTrabajo, periodo, director, codirector, jurado1, jurado2 );
    this->listaActas.push_back(acta);

}  

/*
Nombre: mostrarListaPersonas 
Funcion: muestra el nombre de las personas de la lista personas
Entrada: n/a
Salida: n/a
*/
void Posgrado::mostrarListaPersonas(){
    if(this->listaPersonas.size() == 0){
        cout << "Por el momento no se encuentran personas registradas en el sistema, proceda a agregar." << endl;
    } else{
        for(int i = 0; i < this->listaPersonas.size(); i++){
            cout << "\033[1;32m" << i + 1 << ".\033[0m ";
            this->listaPersonas[i].mostrarNombre();
            cout << endl;
        }
    }
} //Cree esta funcion para que la asistenta pueda escoge de la lista de personas a quienes quiere como director, codirector y jurados

/*
Nombre: crearInformacionPersona
Funcion: Crea una nueva persona y la agrega a la a lista de personas 
Entrada: n/a
Salida: n/a
*/
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
    
} 

/*
Nombre: mostrarListaActa
Funcion: Muestra la informacion de todas las actas almacenadas en listaActas
Entrada: n/a
Salida: n/a
*/
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

/*
Nombre: buscarActa
Funcion: busca un acta en listaActas (como referente el numero) y retorna un puntero hacia esa acta
Entrada: int(numero)
Salida: Acta*
*/
Acta* Posgrado::buscarActa( int numero){
    Acta* p_acta = NULL;
    for( int i = 0; i < this->listaActas.size(); i++){
        if( numero == listaActas[i].getNumero()){ 
            p_acta = &this->listaActas[i];
            return p_acta;
        }
    }

    return p_acta;
}

/*
Nombre: modificarActa
Funcion: permite modificar el acta seleccionada, ya sea diligenciandola o cerrandola
Entrada: n/a
Salida: n/a
*/
void Posgrado::modificarActa(){
    int opcion, numero;
    Acta * pActa;
    bool continuar = true;


    cout << "-----------MODIFICAR ACTA-------------" << endl;

    cout << " Digite el codigo del acta a modificar: " << endl;
    cin >> numero;
    pActa = this->buscarActa( numero );
    if( pActa == NULL ){
        cout << "Lo siento, no se pudo encontrar el acta " << endl;
    }
    else if( pActa->getEstadoActa() == cerrado ){
        cout << "Lo siento, el acta ya se encuentra cerrada " << endl;
    }
    else{
        pActa->mostrarActa();
        do{
            try{
            cout << " ??Que desea hacer con el acta de evaluacion? " << endl;
            cout << "====================" << endl;
            cout << "1. Diligenciar Acta." << endl;
            cout << "2. Cerrar Acta." << endl;
            cin >> opcion;
            if( opcion > 3 || opcion < 1){
                throw;
                }
            continuar = false;
            }catch(...){
                cout << "Por favor digite una opcion valida " << endl;
            }
        }while( continuar );

        switch (opcion){
            case 1:
                pActa->diligenciarCriterios();
            break;

            case 2:
                pActa->cerrarActa();
            break;

            default:
            break;
        }
    }
    
}

/*
Nombre: trabajosTipoAplicado
Funcion: muestra todas las actas de tipo "aplicado" que se encuentren en listaActas
Entrada: n/a
Salida: n/a
*/
void Posgrado::trabajosTipoAplicado(){
    int contAplicado = 0;
    for(int i = 0; i < this->listaActas.size(); i++){
        if(this->listaActas[i].getTipoTrabajo() == aplicado){
            this->listaActas[i].mostrarActa();
            contAplicado++;
        }
    }
    cout << "Se encontraron " << contAplicado << " trabajos de tipo Aplicado." << endl;
}

/*
Nombre: trabajosTipoInvestigacion
Funcion: muestra todas las actas de tipo "investigacion" que se encuentren en listaActas
Entrada: n/a
Salida: n/a
*/
void Posgrado::trabajosTipoInvestigacion(){
    int contInvestigacion = 0;
    for(int i = 0; i < this->listaActas.size(); i++){
        if(this->listaActas[i].getTipoTrabajo() == investigacion){
            this->listaActas[i].mostrarActa();
            contInvestigacion++;
        }
    }
    cout << "Se encontraron " << contInvestigacion << " trabajos de tipo Investigacion." << endl;
}

/*
Nombre: trabajosProfesor
Funcion: muestra las actas donde ha sido director y/o codirector una persona
Entrada: n/a
Salida: n/a
*/
void Posgrado::trabajosProfesor(){
    int selec, contDirector = 0, contCodirector = 0;
    bool continuar = true;
    cout << "Seleccione una de las siguientes personas para consultar las actas de grado dirigidas (cerciorese de que la persona escogida sea interna a la universidad): ";
    do{
        try{
            this->mostrarListaPersonas();
            cin >> selec;
            if(selec < 0 || selec > this->listaPersonas.size()){
                throw 1;
            } else if(this->listaPersonas[selec - 1].getClasePersona() == externo){
                throw 2;
            }
            for(int i = 0; i < this->listaActas.size(); i++){
                if(this->listaActas[i].getDirector(1).getID() == this->listaPersonas[selec - 1].getID()){
                    this->listaActas[i].mostrarActa();
                    contDirector++;
                } else if(this->listaActas[i].getDirector(2).getID() == this->listaPersonas[selec - 1].getID()){
                    this->listaActas[i].mostrarActa();
                    contCodirector++;
                }
            }
            cout << "El/la profesor/a ";
            this->listaPersonas[selec - 1].mostrarNombre();
            contDirector == 0 ? cout << " no ha dirigido ningun trabajo de grado." : cout << " es director/a de " << contDirector << " trabajos de grado.";
            cout << endl;
            cout << "Ademas el/la profesor/a ";
            this->listaPersonas[selec - 1].mostrarNombre();
            contCodirector == 0 ? cout << " no ha codirigido ningun trabajo de grado." : cout << " es codirector/a de " << contCodirector << " trabajos de grado.";
            cout << endl;
            continuar = false;
        } catch(int error){
            if(error == 1){
                cout << "Seleccione una opcion valida, por favor." << endl;
            } else if(error == 2){
                cout << "La persona seleccionada es externa a la universidad, por favor escoja a un profesor (persona interna)." << endl;
            }
        }
    } while(continuar);
}

/*
Nombre: trabajosJurado
Funcion: muestra las actas de grado donde ha sido jurado una persona
Entrada: n/a
Salida: n/a
*/
void Posgrado::trabajosJurado(){
    int selec, contJurado = 0;
    bool continuar = true;
    cout << "Seleccione una de las siguientes personas para consultar las actas de grado en las que ha participado como jurado: ";
    do{
        try{
            this->mostrarListaPersonas();
            cin >> selec;
            if(selec < 0 || selec > this->listaPersonas.size()){
                throw;
            }
            for(int i = 0; i < this->listaActas.size(); i++){
                if(this->listaActas[i].getJurado(1).getID() == this->listaPersonas[selec - 1].getID() || this->listaActas[i].getJurado(2).getID() == this->listaPersonas[selec - 1].getID()){
                    this->listaActas[i].mostrarActa();
                    contJurado++;
                }
            }
            cout << "El/la senior/a ";
            this->listaPersonas[selec - 1].mostrarNombre(); 
            //if alternativo
            contJurado == 0 ? cout << " no ha sido jurado de ningun trabajo de grado." : cout << " es jurado/a de " << contJurado << " trabajos de grado.";
            cout << endl;
            continuar = false;
        } catch(...){
            cout << "Seleccione una opcion valida, por favor." << endl;
        }
    } while(continuar);
}

void Posgrado::mostrarListaJurados(){
    for( int i = 0; i < this->listaPersonas.size(); i++){
        if (this->listaPersonas[i].validarJurado()){
            cout << " =====================" << endl;
            cout << i + 1 << ".";
            listaPersonas[i].mostrarNombre();
        }
    }
}

/*
Nombre: mostrarListasActasPendientesRechazadas
Funcion: muestra las actas que se encuentren en estado "pendiente" o "rechazada"
Entrada: n/a
Salida: n/a
*/
void Posgrado::mostrarListasActasPendientesRechazadas(){
    for( int i = 0; i < this->listaActas.size(); i++ ){
        if( this->listaActas[i].getEstadoCalificacionActa() == pendiente || this->listaActas[i].getEstadoCalificacionActa() == rechazada ){
            this->listaActas[i].mostrarActa();
        }
    }
}

/*
Nombre: mostrarInternosExternos
Funcion: muestra los profesores de tipo "interno" o "externo"
Entrada: n/a
Salida: n/a
*/
void Posgrado::mostrarInternosExternos(){
    cout << " Internos: " << endl;
    for(int i = 0; i < this->listaPersonas.size(); i++){
        if( this->listaPersonas[i].validarJurado()){
            if(this->listaPersonas[i].getClasePersona() == interno ){
                cout << endl;
                this->listaPersonas[i].mostrarNombre();
            }
        }
    }
    cout << " ==================================" << endl;
    cout << " Externos: " << endl;
    for(int i = 0; i < this->listaPersonas.size(); i++){
        if( this->listaPersonas[i].validarJurado()){
            if(this->listaPersonas[i].getClasePersona() == externo ){
                cout << endl;
                this->listaPersonas[i].mostrarNombre();
            }
        }
    }
}

/*
Nombre: eliminarActa
Funcion: elimina el acta seleccionada de listaActas
Entrada: n/a
Salida: n/a
*/
void Posgrado::eliminarActa(){
    int numero, bandera = 0;

    cout << " Digite el numero del acta a eliminar " << endl;
    cin >> numero;

    for(int i = 0; i < this->listaActas.size(); i++ ){
        if( this->listaActas[i].getNumero() == numero ){
            this->listaActas.erase(this->listaActas.begin() + i );
            bandera = 1;
            break;
        }
    }

    if(bandera = 0){
        cout << " Acta no encontrada :( " << endl;
    }
}

/*
Nombre: mostrarCriterios
Funcion: pide el numero del acta que desea ver el usuario para hacer la busqueda correspondiente
Entrada: n/a
Salida: n/a
*/
void Posgrado::mostrarCriterios(){
    Acta* pActa;
    int numero;
    
    cout << "Digite el numero del acta que desea ver los criterios: " << endl;
    cin >> numero;
    pActa = this->buscarActa( numero );
    if( pActa == NULL ){
        cout << "Lo siento, no se pudo encontrar el acta " << endl;
    }
    else{
        pActa->mostrarDetallesCriterios(); 
    }

}

void Posgrado::mostrarListaActasAbiertasCerradas(){
    int selec, cont = 0;;
    bool continuar = true;
    do{
        try{
            cout << "Desea ver la lista de actas abiertas o cerradas (1/2): ";
            cin >> selec;
            if(selec != 1 && selec != 2){
                throw;
            }
            if(selec == 1){
                cout << "oliwi\n";
                for( int i = 0; i < this->listaActas.size(); i++ ){
                    if( this->listaActas[i].getEstadoActa() == abierto){
                        this->listaActas[i].mostrarActa();
                        cont++;
                    }
                }
            } else{
                for( int i = 0; i < this->listaActas.size(); i++ ){
                    if( this->listaActas[i].getEstadoActa() == cerrado){
                        this->listaActas[i].mostrarActa();
                        cont++;
                    }
                }
            }
            if(cont == 0){
                cout << "No se encontraron actas en ese estado :(." << endl;
            }
            continuar = false;
        } catch(...){
            cout << "Seleccione una opcion valida." << endl;
        }
    } while( continuar );
}
/*
Nombre: generarPDF
Funcion: pide el numero del acta que se desea exportar a pdf
Entrada: n/a
Salida: n/a
*/
void Posgrado::generarPDF(){
    Acta* pActa;
    int numero;

    cout << " Digite el numero del acta que desea exportar a pdf " << endl;
    cin >> numero;

    pActa = this->buscarActa( numero );

    if( pActa == NULL ){
        cout << "Lo siento, no se pudo encontrar el acta " << endl;
    }
    else{
        if(pActa->getEstadoActa() == abierto){
            cout << "El acta no se encuentra cerrada, por lo tanto no se puede generar el PDF." << endl;
        } else{
            pActa->generarPDF();
        }
    }

}