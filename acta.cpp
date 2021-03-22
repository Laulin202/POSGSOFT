#include "acta.h"

//CONSTRUCTOR CLASE ACTA

//Por defecto
Acta::Acta(){}
/*
Nombre: Acta
Funcion: Contruye el acta con parametros
Entrada: int, string, string, string, tipoTrabajoGrado, string, Persona, Persona, Persona, Persona.
Salida: N/A
*/
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

/*
Nombre: inicializarListaCriterio
Funcion: Se encarga de crear cada uno de los 8 criterios y agregarlos a la listaCriterios
Entrada: N/A
Salida: N/A
*/
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

/*
Nombre: mostrarCriterios
Funcion: Recorre la lista de criterios llamando a la funcion mostrarCriterio de cada uno.
Entrada: N/A
Salida: N/A
*/
void Acta::mostrarCriterios(){
    for(int i = 0; i < this->listaCriterios.size(); i++){
        this->listaCriterios[i].mostrarCriterio();
    }
}

/*
Nombre: mostrarActa
Funcion: Se encarga de mostrar en consola la informacion necesaria de un acta.
Entrada: N/A
Salida: N/A
*/
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

/*
Nombre: getNumero
Funcion: Retorna el numero del acta.
Entrada: N/A
Salida: int
*/
int Acta::getNumero(){
    return this->numero;
}

/*
Nombre: diligenciarCriterios
Funcion: Se recorre la lista de criterios pidiendo al usuario las respectivas calificaciones y observaciones, guardando estos datos en la lista DetallesCriterios y actualizando la nota final del acta.
Entrada: N/A
Salida: N/A
*/
void Acta::diligenciarCriterios(){
    bool continuar = true;
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
        do{
            try{
                cout << "Digite observaciones (max. 220 caracteres):" << endl;
                cin.ignore(100, '\n');
                getline(cin, observacion);
                if(observacion.size() > 220){
                    throw;
                }
                continuar = false;
            } catch(...){
                cout << "Las obserrvaciones superaron el limite de caracteres, reintentelo." << endl;
            }
        } while(continuar);

        this->listaDetallesCriterios.push_back(DetalleCriterio( criterio ,calificacionJurado1, calificacionJurado2, promedioCalificacion, observacion));

        this->notaFinal += promedioCalificacion;
    }
    continuar = true;
    cout << " La nota final es: " << this->notaFinal << endl;
    cout << "Desea añadir comentarios especificos?\n1. Si\n2.No" << endl;
    cin >> opcion;
    if( opcion == 1 ){
        do{
            try{
                cout << " Por favor digite el comentario: " << endl;
                cin.ignore(100, '\n');
                getline(cin, this->comentariosEspeciales);
                if(this->comentariosEspeciales.size() > 283){
                    throw;
                }
                continuar = false;
            } catch(...){
                cout << "Los comentarios superaron el limite de caracteres, reintentelo." << endl;
            }
        } while( continuar );
    }
    else{
        cout << " Se ha finalizado correctamente el proceso para su acta! " << endl;
    }
    this->actualizarEstadoCalificacionActa();
}

/*
Nombre: actualizarEstadoCalificacionActa
Funcion: Actualiza el estado de calificacion del acta a aprobado, pendiente o rechazado dependiendo de la calificacion y los comentarios especiales.
Entrada: N/A
Salida: N/A
*/
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

/*
Nombre: getTipoTrabajo
Funcion: Retorna el tipo de trabajo del acta de grado (Aplicado o Investigacion).
Entrada: N/A
Salida: enum tipoTrabajoGrado
*/
tipoTrabajoGrado Acta::getTipoTrabajo(){
    return this->tipoTrabajo;
}

/*
Nombre: getDirector
Funcion: Retorna un objeto director de clase Persona (si el integer es 1) o un objeto codirector de clase Persona (si el integer no es 1).
Entrada: int
Salida: class Persona
*/
Persona Acta::getDirector(int n){
    return n == 1 ? this->director : this->codirector;
}

/*
Nombre: getJurado
Funcion: Retorna un objeto jurado1 de clase Persona (si el integer es 1) o un objeto jurado2 de clase Persona (si el integer no es 1).
Entrada: int
Salida: class Persona
*/
Persona Acta::getJurado(int n){
    return n == 1 ? this->jurado1 : this->jurado2;
}

/*
Nombre: cerrarActa
Funcion: Actualiza el estado del acta a cerrado si el acta se encuentra pendiente.
Entrada: N/A
Salida: N/A
*/
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
        } else{
            this->estadoActa = cerrado;
        }
    }
}

/*
Nombre: getEstadoCalificacionActa
Funcion: Retorna el estado de calificacion del acta (aprobado, pendiente o rechazado).
Entrada: N/A
Salida: enum estadoCalificacionActa
*/
estadoCalificacionActa Acta::getEstadoCalificacionActa(){
    return this->estadoCalificacion;
}

/*
Nombre: getEstadoActa
Funcion: Retorna el estado del acta (abierto o cerrado).
Entrada: N/A
Salida: enum estado
*/
estado Acta::getEstadoActa(){
    return this->estadoActa;
}

/*
Nombre: mostrarDetallesCriterios
Funcion: Recorre la listaDetallesCriterios para mostrar la informacion necesaria de cada uno.
Entrada: N/A
Salida: N/A
*/
void Acta::mostrarDetallesCriterios(){
    for(int i = 0; i < this->listaDetallesCriterios.size(); i++){
        this->listaDetallesCriterios[i].mostrarDetalleCriterio(); 
    }
}
/*
Nombre: generarPDF
Funcion: Se encarga de crear un objeto de clase PDF en el cual se utilizan diversas funcionalidades de la libreria pdf.h para manejar el pdf e ir agregandole todo lo necesario, finalmente se escribe el pdf en el archivo con el nombre determinado al inicio de la funcion teniendo en cuenta el numero del acta.
Entrada: N/A
Salida: N/A
*/
void Acta::generarPDF(){
   ostringstream out;
   out << "Acta-" << this->numero << ".pdf";
   string nombreArchivo = out.str();
   cout << "-----------------------------------------" << "\n";
   cout << "Generando PDF: [" << nombreArchivo << "]"  << "\n";
   cout << "-----------------------------------------" << "\n";
   PDF p;



   p.setFont(PDF::HELVETICA_BOLD, 14);

   string s = "Facultad de Ingenieria\nMaestria en Ingenieria";
   vector<string> sv = p.wrapText(s, 150, true);
   for(int i = 0, n = sv.size(); i < n; i++)
   {
      p.showTextXY(sv[i], 230, 730 - 15 * i);
   }

   p.setFont(PDF::HELVETICA_BOLD, 10);

   s = "ACTA: ";
   s += std::__cxx11::to_string(this->numero);
   p.showTextXY(s, 40, 690);

   s = "Fecha: ";
   s += this->fecha;
   p.rightJustifyTextXY(s, 560, 690);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "ACTA DE EVALUACION DE TRABAJO DE GRADO";
   p.showTextXY(s, 180, 660);

   p.setFont(PDF::HELVETICA, 11);

   s = "Trabajo de grado denominado: ";
   s += this->nombreTrabajo;
   p.showTextXY(s, 40, 630);

   s = "Autor:";
   p.showTextXY(s, 40, 600);
   s = this->nombreEstudiante;
   p.showTextXY(s, 180, 600);

   s = "Periodo:";
   p.showTextXY(s, 40, 575);
   s = this->periodo;
   p.showTextXY(s, 180, 575);

   s = "Director:";
   p.showTextXY(s, 40, 550);
   s = this->director.getNombre();
   p.showTextXY(s, 180, 550);

   s = "Co-Director:";
   p.showTextXY(s, 40, 525);
   if(this->codirector.getID() == ""){
        s = "NA";
    } else{
        s = this->codirector.getNombre();
    }
   p.showTextXY(s, 180, 525);

   s = "Enfasis en:";
   p.showTextXY(s, 40, 500);
   s = "Sistema y computacion";
   p.showTextXY(s, 180, 500);

   s = "Modalidad:";
   p.showTextXY(s, 40, 475);
   s = this->tipoTrabajo == 0 ? "Aplicado" : "Investigacion";
   p.showTextXY(s, 180, 475);
   
   s = "Jurado 1:";
   p.showTextXY(s, 40, 450);
   s = this->jurado1.getNombre();
   p.showTextXY(s, 180, 450);
   
   s = "Jurado 2:";
   p.showTextXY(s, 40, 425);
   s = this->jurado2.getNombre();
   p.showTextXY(s, 180, 425);

   s = "En atencion al desarrollo de este Trabajo de Grado y al documento y sustentacion que presento el(la) autor(a), los Jurados damos las siguientes calificaciones parciales y observaciones (los criterios a evaluar y sus ponderaciones se estipulan en el articulo 7.1 de las Directrices para Trabajo de Grado de Maestria):";
   sv = p.wrapText(s, 540, true);

   for(int i = 0, n = sv.size(); i < n; i++)
   {
      p.showTextXY(sv[i], 40, 390 - 12 * i);
   }

   p.setFont(PDF::HELVETICA_BOLD, 11);

    string extra = "_";

   s = "1.    Desarrollo y profundidad en el tratamiento del tema: ";
   p.showTextXY(s, 40, 330);

// CRITERIO 1
   p.setFont(PDF::HELVETICA, 11);

   s = "Calificacion Jurado 1: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[0].getCalificacionJurado(1)).erase(4,4);
   s += "     Calificacion Jurado 2: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[0].getCalificacionJurado(2)).erase(4,4);
   p.showTextXY(s, 58, 310);

   s = "Ponderacion: 20%";
   p.rightJustifyTextXY(s, 560, 310);

   s = "Observaciones: ";
   s += this->listaDetallesCriterios[0].getObservacion();
   if(s.size() > 70){
       sv = p.wrapText(s, 500, true);
       for(int i = 0; i < sv.size(); i++){
           p.showTextXY(sv[i], 58, 290 -  20 * i);
       }
   } else{
       p.showTextXY(s, 58, 290);
   }
   s = "                          _____________________________________________________________________";
   p.showTextXY(s, 58, 290);
   s = "__________________________________________________________________________________";
   for(int i = 0; i < 2; i++){
       p.showTextXY(s, 58, 270 - 20 * i);
   }

// CRITERIO 2
   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "2.    Desafio academico y cientifico del tema:";
   p.showTextXY(s, 40, 230);

   p.setFont(PDF::HELVETICA, 11);

   s = "Calificacion Jurado 1: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[1].getCalificacionJurado(1)).erase(4,4);
   s += "     Calificacion Jurado 2: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[1].getCalificacionJurado(2)).erase(4,4);
   p.showTextXY(s, 58, 210);

   s = "Ponderacion: 15%";
   p.rightJustifyTextXY(s, 560, 210);

   s = "Observaciones: ";
   s += this->listaDetallesCriterios[1].getObservacion();
   if(s.size() > 70){
       sv = p.wrapText(s, 500, true);
       for(int i = 0; i < sv.size(); i++){
           p.showTextXY(sv[i], 58, 190 -  20 * i);
       }
   } else{
       p.showTextXY(s, 58, 190);
   }
   s = "                          _____________________________________________________________________";
   p.showTextXY(s, 58, 190);
   s = "__________________________________________________________________________________";
   for(int i = 0; i < 2; i++){
       p.showTextXY(s, 58, 170 - 20 * i);
   }

   p.newPage();


   p.setFont(PDF::HELVETICA_BOLD, 14);

   s = "Facultad de Ingenieria\nMaestria en Ingenieria";
   sv = p.wrapText(s, 150, true);
   for(int i = 0, n = sv.size(); i < n; i++)
   {
      p.showTextXY(sv[i], 230, 730 - 15 * i);
   }

   p.setFont(PDF::HELVETICA_BOLD, 10);

   s = "ACTA: ";
   s += std::__cxx11::to_string(this->numero);
   p.showTextXY(s, 40, 690);

   s = "Fecha: ";
   s += this->fecha;
   p.rightJustifyTextXY(s, 560, 690);

//CRITERIO 3
   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "3.    Cumplimiento de los objetivos propuestos: ";
   p.showTextXY(s, 40, 660);

   p.setFont(PDF::HELVETICA, 11);

   s = "Calificacion Jurado 1: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[2].getCalificacionJurado(1)).erase(4,4);
   s += "     Calificacion Jurado 2: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[2].getCalificacionJurado(2)).erase(4,4);
   p.showTextXY(s, 58, 640);

   s = "Ponderacion: 10% ";
   p.rightJustifyTextXY(s, 560, 640);

   s = "Observaciones: ";
   s += this->listaDetallesCriterios[2].getObservacion();
   if(s.size() > 70){
       sv = p.wrapText(s, 500, true);
       for(int i = 0; i < sv.size(); i++){
           p.showTextXY(sv[i], 58, 620 -  20 * i);
       }
   } else{
       p.showTextXY(s, 58, 620);
   }
   s = "                          _____________________________________________________________________";
   p.showTextXY(s, 58, 620);
   s = "__________________________________________________________________________________";
   for(int i = 0; i < 2; i++){
       p.showTextXY(s, 58, 600 - 20 * i);
   }

//CRITERIO 4
   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "4.    Creatividad e innovacion de las soluciones y desarrollos propuestos:";
   p.showTextXY(s, 40, 560);

   p.setFont(PDF::HELVETICA, 11);

   s = "Calificacion Jurado 1: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[3].getCalificacionJurado(1)).erase(4,4);
   s += "     Calificacion Jurado 2: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[3].getCalificacionJurado(2)).erase(4,4);
   p.showTextXY(s, 58, 540);

   s = "Ponderacion: 10%";
   p.rightJustifyTextXY(s, 560, 540);

   s = "Observaciones: ";
   s += this->listaDetallesCriterios[3].getObservacion();
   if(s.size() > 70){
       sv = p.wrapText(s, 500, true);
       for(int i = 0; i < sv.size(); i++){
           p.showTextXY(sv[i], 58, 520 -  20 * i);
       }
   } else{
       p.showTextXY(s, 58, 520);
   }
   s = "                          _____________________________________________________________________";
   p.showTextXY(s, 58, 520);
   s = "__________________________________________________________________________________";
   for(int i = 0; i < 2; i++){
       p.showTextXY(s, 58, 500 - 20 * i);
   }

//CRITERIO 5
   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "5.    Validez de los resultados y conclusiones:";
   p.showTextXY(s, 40, 460);

   p.setFont(PDF::HELVETICA, 11);

   s = "Calificacion Jurado 1: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[4].getCalificacionJurado(1)).erase(4,4);
   s += "     Calificacion Jurado 2: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[4].getCalificacionJurado(2)).erase(4,4);
   p.showTextXY(s, 58, 440);

   s = "Ponderacion: 20%";
   p.rightJustifyTextXY(s, 560, 440);

   s = "Observaciones: ";
   s += this->listaDetallesCriterios[4].getObservacion();
   if(s.size() > 70){
       sv = p.wrapText(s, 500, true);
       for(int i = 0; i < sv.size(); i++){
           p.showTextXY(sv[i], 58, 420 -  20 * i);
       }
   } else{
       p.showTextXY(s, 58, 420);
   }
   s = "                          _____________________________________________________________________";
   p.showTextXY(s, 58, 420);
   s = "__________________________________________________________________________________";
   for(int i = 0; i < 2; i++){
       p.showTextXY(s, 58, 400 - 20 * i);
   }

//CRITERIO 6
   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "6.    Manejo y procesamiento de la informacion y bibliografia:";
   p.showTextXY(s, 40, 360);

   p.setFont(PDF::HELVETICA, 11);

   s = "Calificacion Jurado 1: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[5].getCalificacionJurado(1)).erase(4,4);
   s += "     Calificacion Jurado 2: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[5].getCalificacionJurado(2)).erase(4,4);
   p.showTextXY(s, 58, 340);

   s = "Ponderacion: 10%";
   p.rightJustifyTextXY(s, 560, 340);

   s = "Observaciones: ";
   s += this->listaDetallesCriterios[5].getObservacion();
   if(s.size() > 70){
       sv = p.wrapText(s, 500, true);
       for(int i = 0; i < sv.size(); i++){
           p.showTextXY(sv[i], 58, 320 -  20 * i);
       }
   } else{
       p.showTextXY(s, 58, 320);
   }
   s = "                          _____________________________________________________________________";
   p.showTextXY(s, 58, 320);
   s = "__________________________________________________________________________________";
   for(int i = 0; i < 2; i++){
       p.showTextXY(s, 58, 300 - 20 * i);
   }

//CRITERIO 7
   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "7.    Calidad y presentacion del documento escrito:";
   p.showTextXY(s, 40, 260);

   p.setFont(PDF::HELVETICA, 11);

   s = "Calificacion Jurado 1: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[6].getCalificacionJurado(1)).erase(4,4);
   s += "     Calificacion Jurado 2: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[6].getCalificacionJurado(2)).erase(4,4);
   p.showTextXY(s, 58, 240);

   s = "Ponderacion: 7,5%";
   p.rightJustifyTextXY(s, 560, 240);

   s = "Observaciones: ";
   s += this->listaDetallesCriterios[6].getObservacion();
   if(s.size() > 70){
       sv = p.wrapText(s, 500, true);
       for(int i = 0; i < sv.size(); i++){
           p.showTextXY(sv[i], 58, 220 -  20 * i);
       }
   } else{
       p.showTextXY(s, 58, 220);
   }
   s = "                          _____________________________________________________________________";
   p.showTextXY(s, 58, 220);
   s = "__________________________________________________________________________________";
   for(int i = 0; i < 2; i++){
       p.showTextXY(s, 58, 200 - 20 * i);
   }

//CRITERIO 8
   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "8.    Presentacion oral:";
   p.showTextXY(s, 40, 160);

   p.setFont(PDF::HELVETICA, 11);

   s = "Calificacion Jurado 1: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[7].getCalificacionJurado(1)).erase(4,4);
   s += "     Calificacion Jurado 2: ";
   s += std::__cxx11::to_string(this->listaDetallesCriterios[7].getCalificacionJurado(2)).erase(4,4);
   p.showTextXY(s, 58, 140);

   s = "Ponderacion: 7,5%";
   p.rightJustifyTextXY(s, 560, 140);

   s = "Observaciones: ";
   s += this->listaDetallesCriterios[7].getObservacion();
   if(s.size() > 70){
       sv = p.wrapText(s, 500, true);
       for(int i = 0; i < sv.size(); i++){
           p.showTextXY(sv[i], 58, 120 -  20 * i);
       }
   } else{
       p.showTextXY(s, 58, 120);
   }
   s = "                          _____________________________________________________________________";
   p.showTextXY(s, 58, 120);
   s = "__________________________________________________________________________________";
   for(int i = 0; i < 2; i++){
       p.showTextXY(s, 58, 100 - 20 * i);
   }

   p.newPage();
   p.setFont(PDF::HELVETICA_BOLD, 14);

   s = "Facultad de Ingenieria\nMaestria en Ingenieria";
   sv = p.wrapText(s, 150, true);
   for(int i = 0, n = sv.size(); i < n; i++){
      p.showTextXY(sv[i], 230, 730 - 15 * i);
   }

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "Como resultado de estas calificaciones parciales y sus ponderaciones, la calificacion del Trabajo de";
   sv = p.wrapText(s, 540, true);
   for(int i = 0, n = sv.size(); i < n; i++){
      p.showTextXY(sv[i], 40, 670 - 12 * i);
   }

   s = "Grado es: ";
   s += std::__cxx11::to_string(this->notaFinal).erase(4,4);
   p.showTextXY(s, 40, 658);

   s = std::__cxx11::to_string(this->notaFinal).erase(4,4);
   p.showTextXY(s, 110, 633);

   s = ""; 
   p.showTextXY(s, 310, 633);

   s = "Numeros";
   p.showTextXY(s, 95, 621);

   s = "Letras";
   p.showTextXY(s, 338, 621);

   p.setFont(PDF::HELVETICA, 11);
   s = "Observaciones adicionales:";
   s += this->comentariosEspeciales;
   if(s.size() > 58){
       sv = p.wrapText(s, 480, true);
       for(int i = 0; i < sv.size(); i++){
           p.showTextXY(sv[i], 40, 581 -  20 * i);
       }
   } else{
       p.showTextXY(s, 40, 581);
   }
   s = "                                              _________________________________________________________________";
   p.showTextXY(s, 40, 581);

   s = "________________________________________________________________________________________";
   for(int i = 0; i < 3; i++){
       p.showTextXY(s, 40, 561 - 20 * i);
   }

   s = "La calificacion final quedas sujeta a que se implementen las siguientes correcciones: ";
   for(int i = 0; i < 20; i++){
       s += extra;
   }
   p.showTextXY(s, 40, 451);
   s = "________________________________________________________________________________________";
   for(int i = 0; i < 3; i++){
       p.showTextXY(s, 40, 431 - 20 * i);
   }

   s = "________________________________     _______________________________";
   p.showTextXY(s, 80, 261);

   s = "    Firma del Jurado1                                     Firma del Jurado2";
   p.showTextXY(s, 150, 243);

   p.newPage();

   p.setFont(PDF::HELVETICA_BOLD, 14);

   s = "Facultad de Ingenieria\nMaestria en Ingenieria";
   sv = p.wrapText(s, 150, true);
   for(int i = 0, n = sv.size(); i < n; i++)
   {
      p.showTextXY(sv[i], 230, 730 - 15 * i);
   }

   p.setFont(PDF::HELVETICA_BOLD, 10);

   s = "ACTA: ";
   s += std::__cxx11::to_string(this->numero);
   p.showTextXY(s, 40, 690);

   s = "Fecha: ";
   s += this->fecha;
   p.rightJustifyTextXY(s, 560, 690);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "RECOMENDACION DE MENCION DE HONOR AL TRABAJO DE GRADO";
   p.showTextXY(s, 120, 660);

   p.setFont(PDF::HELVETICA, 11);

   s = "Trabajo de grado denominado: ";
   s += this->nombreTrabajo;
   p.showTextXY(s, 40, 630);

   s = "Autor:";
   p.showTextXY(s, 40, 600);
   s = this->nombreEstudiante;
   p.showTextXY(s, 180, 600);

   s = "Periodo:";
   p.showTextXY(s, 40, 575);
   s = this->periodo;
   p.showTextXY(s, 180, 575);

   s = "Director:";
   p.showTextXY(s, 40, 550);
   s = this->director.getNombre();
   p.showTextXY(s, 180, 550);

   s = "Co-Director:";
   p.showTextXY(s, 40, 525);
   if(this->codirector.getID() == ""){
        s = "NA";
    } else{
        s = this->codirector.getNombre();
    }
   p.showTextXY(s, 180, 525);

   s = "Enfasis en:";
   p.showTextXY(s, 40, 500);
   s = "Sistema y computacion";
   p.showTextXY(s, 180, 500);

   s = "Modalidad:";
   p.showTextXY(s, 40, 475);           
   s = this->tipoTrabajo == 0 ? "Aplicado" : "Investigacion";
   p.showTextXY(s, 180, 475);
   
   s = "Jurado 1:";
   p.showTextXY(s, 40, 450);
   s = this->jurado1.getNombre();
   p.showTextXY(s, 180, 450);
   
   s = "Jurado 2:";
   p.showTextXY(s, 40, 425);
   s = this->jurado2.getNombre();
   p.showTextXY(s, 180, 425);

   s = "En atencion a que el Trabajo de Grado se distingue porque la calificacion del trabajo es superior a 4,50 y se destaca por dos condiciones (que indicamos) de las siguientes tres como se estipula en el articulo 7.6 de las"; 
   sv = p.wrapText(s, 540, true);

   for(int i = 0, n = sv.size(); i < n; i++){
      p.showTextXY(sv[i], 40, 390 - 12 * i);
   }

   s = "Directrices para Trabajo de Grado de Maestria:";
   p.showTextXY(s, 40, 366);

   p.fillCircle(43, 353, 2);
   p.drawCircle(43, 353, 2);
   s = "         El estudiante supero los objetivos propuestos.";
   p.showTextXY(s, 40, 350);

   p.fillCircle(43, 335, 2);
   p.drawCircle(43, 335, 2);
   s = "         El estudiante demostro una profundidad destacable en el conocimiento y tratamiento del tema.";
   p.showTextXY(s, 40, 332);

   p.fillCircle(43, 317, 2);
   p.drawCircle(43, 317, 2);
   s = "         El tema ofrecia una dificultad superior a lo ordinario.";
   p.showTextXY(s, 40, 314);

   s = "Los jurados recomendamos que el Consejo de la Facultad otogue Mencion de Honor a este Trabajo de Grado,";
   p.showTextXY(s, 40, 294);
   s = "y motivamos esta recomendacion con base en las siguientes apreciaciones:";
   p.showTextXY(s, 40, 278);

   s = "_______________________________________________________________________________";
   p.showTextXY(s, 40, 258);

   s = "________________________________              _________________________________";
   p.showTextXY(s, 40, 218);

   s = "                         Firma del Jurado1                                       Firma del Jurado2";
   p.showTextXY(s, 40, 200);

   p.setFont(PDF::HELVETICA_BOLD, 11);

   s = "Decision del Consejo de la Facultad:";
   p.showTextXY(s, 40, 170);

   p.setFont(PDF::HELVETICA, 11);

   s = "En virtud de las condiciones que indicaron los Jurados y su motivacion, el Consejo de la Facultad decidio lo";
   p.showTextXY(s, 40, 150);
   
   s = "siguiente:";
   p.showTextXY(s, 40, 138);

   p.fillCircle(43, 125, 2);
   p.drawCircle(43, 125, 2);
   s = "         Conceder Mencion de Honor al Proyecto de Grado____";
   p.showTextXY(s, 40, 122);

   p.fillCircle(43, 113, 2);
   p.drawCircle(43, 113, 2);
   s = "         No Conceder Mencion de Honor al Proyecto de Grado____";
   p.showTextXY(s, 40, 110);

   s = "Tal y como se consigna en el Acta No.";
   s += "del Consejo de la Facultad.";
   p.showTextXY(s, 40, 94);

   string errMsj;
   if(!p.writeToFile(nombreArchivo, errMsj)){
      cout << errMsj << endl;
   } else{
      cout << "(El archivo se genero correctamente)" << endl;
   }

   cout << endl;
}

