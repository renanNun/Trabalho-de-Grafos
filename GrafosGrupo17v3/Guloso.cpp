#include "Guloso.h"

using namespace std;


Guloso::Guloso(Grafo* g){
    this->solucaoInicial = new No[g->getNumNos()];
}

Guloso::~Guloso(){

}

void Guloso::preencheSolucaoInicial(Grafo *g){
    No* p = g->getPrimeiroNo();

    int cont = 0;
    while(p != nullptr){
        this->solucaoInicial[cont] = *p;

        p = p->getProx();
        cont++;
    }
}

void Guloso::ordenaSolucao(){

}
