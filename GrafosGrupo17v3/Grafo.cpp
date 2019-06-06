#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo(){

    this->numNos= 0;
    this->numArestas = 0;
    this->ehDirecionado = false;
    this->primeiro = NULL;

}

Grafo::~Grafo(){
    No* p = this->primeiro;

    while(p != NULL){
        No* q = p->getProx();
        delete p;
        p = q;
    }
}

No* Grafo::getPrimeiroNo(){
    return this->primeiro;
}

int Grafo::getNumNos(){
    return this->numNos;
}

int Grafo::getNumArestas(){
    return this->numArestas;
}

bool Grafo::ehGrafoDirecionado(){
    return this->ehDirecionado;
}

void Grafo::setDirecionado(bool x){
    this->ehDirecionado = x;
}

No* Grafo::buscaNo(int id){
    No* p = this->primeiro;

    while (p != NULL){
        if(p->getId() == id){
            return p;
        }
        p = p->getProx();
    }

    return p;
}

Aresta* Grafo::buscaAresta(int no1,int no2){

    No* p = buscaNo(int no1);
    Aresta* aux = p->getAresta();

    if(p != NULL && aux != NULL){

        while(aux != NULL){
            if(aux->getId() == no2)
                return aux;
            aux = aux->getProx();
        }
    }

    return aux;
}

void Grafo::insereNo(int id, float peso){

    No *t = this->primero;

    if(!this->buscaNo(id)){

        No* p = new No();
        p->setId(id);

        if (t == NULL){
            this->primeiro = p;
            p->setProx(NULL);
        } else {
            while (t->getProx() != NULL)
                t = t->getProx();
            t->setProx(p);
            p->setProx(NULL);
        }

        this->numNos++;
    }
}
