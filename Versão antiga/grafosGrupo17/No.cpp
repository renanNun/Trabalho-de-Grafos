##include <iostream>
#include "No.h"

/**
     * Construtor do TAD No
     * Constroi um Vertice
     * Parâmetro: _id
     * Parâmetro: _peso
     * encapsulamento: public
     */
No::No(int _id, float _peso) {
    this->id = _id;
    this->peso = _peso;
    this->grauSaida = 0;
    this->grauEntrada = 0;
    this->prox = nullptr;
    this->adj = nullptr;
}

/**
     * Construtor do TAD No
     * Constroi um Vertice
     * Parâmetro: _id
     * encapsulamento: public
     */
No::No(int _id) {
    this->id = _id;
    this->peso = -1;
    this->grauSaida = 0;
    this->grauEntrada = 0;
    this->prox = nullptr;
    this->adj = nullptr;
}

/**
     * Destrutor do TAD No
     * Deleta todos os Nos e todas as Arestas
     *
     * encapsulamento: public
     */
No::~No() {

    // Deletando todos os nós
    No* p = this->prox;
    while (p != NULL){
    No *aux;
    aux = p->getProx();

    delete p;

    p = aux;
    }
    delete this->adj;
}

/*Getters and Setters*/

int No::getId()
{
  return this->id;
}

No* No::getProx()
{
  return this->prox;
}

float No::getPeso()
{
  return this->peso;
}

int No::getGrauEntrada()
{
  return this->grauEntrada;
}

int No::getGrauSaida()
{ return this->grauSaida;
}

Aresta *No::getAresta()
{ return this->adj;
}

Aresta *No::getAresta(int i) {
    Aresta *a = this->adj;
    int c = 0;

    for (a, c; a != nullptr || c < i; a = a->getProx(), c++);

    if (c == i)
        return a;
    else
        return nullptr;
}

void No::setProx(No *n)
{
  this->prox = n;
}

bool No::setAresta(Aresta *aresta) {
    Aresta *a = this->adj;

    // Inicialzando arestas
    if (a == nullptr) {
        this->adj = aresta;
        this->aumentaGrauSaida();

        return true;
    }

    // Encontrando a ultima aresta inserida e certificando que não existe essa aresta
    for (a; a->getProx() != nullptr && a->getNoAdj() != aresta->getNoAdj(); a = a->getProx());

    // Inserindo aresta ou imprimindo erro se já existe aresta
    if (a->getNoAdj() != aresta->getNoAdj()) {
        a->setProx(aresta);
    } else {
        std::cout << "Aresta ja inserida: " << this->getId() << " ---> " << aresta->getNoAdj() << std::endl;
        return false;
    }

    this->aumentaGrauSaida();

    return true;

}

void No::aumentaGrauEntrada()
{
  this->grauEntrada++;
}

void No::aumentaGrauSaida()
{
  this->grauSaida++;
}
