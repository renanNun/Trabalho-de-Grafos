#include "Aresta.h"

/**
     * Construtor do TAD Aresta
     * Constroi uma Aresta ligando dois n�s.
     *
     *
     * encapsulamento: public
     */
Aresta::Aresta(){
    this->no1 = nullptr;
    this->no2 = nullptr;
    this->peso = NULL;
}

/**
     * Construtor do TAD Aresta
     * Constroi uma Aresta ligando dois n�s.
     * Par�metro: no1
     * Par�metro: no2
     * encapsulamento: public
     */
Aresta::Aresta(No* no1,No* no2){
    this->no1 = no1;
    this->no2 = no2;
    this->peso = NULL;
}

/**
     * Construtor do TAD Aresta
     * Constroi uma Aresta ligando dois n�s.
     * Par�metro: no1
     * Par�metro: no2
     * Par�metro: peso
     * encapsulamento: public
     */
Aresta::Aresta(No* no1,No* no2,float peso){
    this->no1 = no1;
    this->no2 = no2;
    this->peso = peso;
}

/**
     * Destrutor do TAD Aresta
     * Destroi uma aresta que liga dois n�s.
     *
     *
     * encapsulamento: public
     */
Aresta::~Aresta(){
    //Destrutor
}

/**
     * Retorna o No de Origem da Aresta
     *
     *
     *
     * encapsulamento: public
     */
No* Aresta::getNo1(){
    return this->no1;
}

/**
     * Retorna o No Adjacente a Aresta
     *
     *
     *
     * encapsulamento: public
     */
No* Aresta::getNo2(){
    return this->no2;
}
