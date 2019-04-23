#include <iostream>
#include "Aresta.h"

using namespace std;

/**
     * Construtor do TAD Aresta
     * Constroi uma aresta e passa como parâmetro o indice do Vertice;
     * Parâmetro: _no
     * encapsulamento: public
     */
Aresta::Aresta(int _no) {
    this->noAdj = _no;
    this->peso = -1;
    this->prox = nullptr;
}


/**
     * Construtor do TAD Aresta
     * Constroi uma aresta e passa como parâmetro o indice do Vertice;
     * Parâmetro: _no
     * Parâmetro: _peso
     * encapsulamento: public
     */
Aresta::Aresta(int _no, float _peso) {
    this->noAdj = _no;
    this->peso = _peso;
    this->prox = nullptr;
}

/**
     * Destrutor do TAD Aresta
     * Deletando todas as Arestas
     * encapsulamento: public
     */
Aresta::~Aresta() {
    Aresta* ant = this->prox;
    while(a != nullptr){
        Aresta *a = ant->getProx();
        delete ant;
        a = a->getProx();
    }
}

/* Setters */

void Aresta::setProx(Aresta *aresta){
    this->prox = aresta;
}

/* Getters */

float Aresta::getPeso()
{
    return this->peso;
}

Aresta* Aresta::getProx()
{
    return this->prox;
}

int Aresta::getNoAdj()
{
    return this->noAdj;
}