#include "posgrado.h"

//CONSTRUCTORES CLASE POSGRADO

Posgrado::Posgrado(){

    this->setDummyData(); //este metodo inicialara una lisa de personas mientas tanto (POTENCIAL PARA SER LA FUNCION CARGAR)

}

//METODOS CLASE POSGRADO

//aunque este hace parte del constructor por ahora
void Posgrado::setDummyData(){
    this->listaPersonas.push_back( Persona("Luisa Rincon","1001","lufe@gmail.com","300045439", 0) );
    this->listaPersonas.push_back( Persona("Joancito Popoloko","1002","elmejorProfedelmundo@gmail.com","3284845439", 0) );
    this->listaPersonas.push_back( Persona("Jhoan Buitrago","1003","jhoanuitrago@gmail.com","3428245439", 0) );
}

void Posgrado::mostrarListaPersonas(){
    for(int i = 0; i < this->listaPersonas.size(); i++ ){
        this->listaPersonas[i].mostrarPersona();
    }
}

