#include "No.h"

/**
     * Construtor do TAD No
     * Constroi um Vertice
     *
     *
     * encapsulamento: public
     */
No::No(){
    this->grauDeEntrada = 0;
    this->grauDeSaida = 0;
    this->peso = NULL;
}

/**
     * Construtor do TAD No
     * Constroi um Vertice
     * Parâmetro: id
     *
     * encapsulamento: public
     */
No::No(int id){
    this->id = id;
    this->grauDeEntrada = 0;
    this->grauDeSaida = 0;
    this->peso = NULL;
}

/**
     * Construtor do TAD No
     * Constroi um Vertice
     * Parâmetro: id
     * Parâmetro: peso
     * encapsulamento: public
     */
No::No(int id,float peso){
    this->id = id;
    this->grauDeEntrada = 0;
    this->grauDeSaida = 0;
    this->peso = peso;
}

/**
     * Destrutor do TAD No
     * Destroi um Vertice
     *
     *
     * encapsulamento: public
     */
No::~No(){
    //Destrutor
}

/**
     * Retorna o Id de um No
     *
     *
     *
     * encapsulamento: public
     */
int No::getId(){
    return this->id;
}

/**
     * Diminui o Grau de saida de um No
     *
     *
     *
     * encapsulamento: public
     */
int No::diminuiGrauSaida(){
    this->grauDeSaida = this->grauDeSaida - 1;
}

/**
     * Aumenta o Grau de Saida de um No
     *
     *
     *
     * encapsulamento: public
     */
int No::aumentaGrauSaida(){
    this->grauDeSaida++;
}

/**
     * Aumenta o Grau de Entrada de um No
     *
     *
     *
     * encapsulamento: public
     */
int No::aumentaGrauEntrada(){
    this->grauDeEntrada++;
}

/**
     * Diminui o Grau de entrada de um No
     *
     *
     *
     * encapsulamento: public
     */
int No::diminuiGrauEntrada(){
    this->grauDeEntrada = this->grauDeEntrada - 1;
}

/**
     * Altera o estado de visita de um No
     * Parâmetro: v
     *
     *
     * encapsulamento: public
     */
void No::setVisitado(bool v){
    this->visitado = v;
}

/**
     * Retorna o estado de visita de um No
     *
     *
     *
     * encapsulamento: public
     */
bool No::getVisitado(){
    return this->visitado;
}

float No::getPeso(){
    return this->peso;
}
