#include "No.h"
#include <iostream>

using namespace std;

No::No(){

    this->primeiro = nullptr;

}

No::~No(){

    Aresta *aux = primeiro;

    while( aux != NULL ){
        Aresta *aux2 = aux->getProx();
        delete aux;
        aux = aux2;
    }
}

int No::getId(){
    return this->id;
}

void No::setId(int id){
    this->id = id;
}

float No::getPeso(){
    return this->peso;
}

void No::setPeso(float peso){
    this->peso = peso;
}

int No::getGrau(){
    return this->grau;
}

void No::setGrau(int p){
    this->grau = p;
}

void No::aumentaGrau(){
    this->grau = this->grau + 1;
}

void No::diminuiGrau(){
    this->grau = this->grau - 1;
}

No* No::getProx(){
    return this->prox;
}

void No::setProx(No* p){
    this->prox = p;
}

Aresta* No::getAresta(){
    return this->primeiro;
}

void No::setAresta(Aresta* a){
    this->primeiro = a;
}

void No::insereAresta(int no,Aresta* a){
    Aresta* p = primeiro;

    if(this->primeiro == NULL){
        this->primeiro = a;
        a->setId(no);
        a->setProx(NULL);
    } else {
        this->primeiro = a;
        a->setId(no);
        a->setProx(p);
    }

    this->aumentaGrau();
}

void No::removeAresta(int no2){

    Aresta* p = this->primeiro;
    Aresta* aux = NULL;

    if(p == NULL){
        std::cout<< "Aresta inexistente! O Vértice: " << this->id << "não possui nenhuma Aresta!";
    }

    while( p != NULL){

        if(p->getId() == no2){
            break;
        }
        aux = p;
        p = p->getProx();
    }

    if (aux == NULL){
        this->primeiro = this->primeiro->getProx();
        delete p;
    } else {
        aux->setProx(p->getProx());
        delete p;
    }

    this->diminuiGrau();
}
