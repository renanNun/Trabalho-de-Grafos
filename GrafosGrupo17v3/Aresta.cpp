#include "Aresta.h"
#include "No.h"
#include <iostream>

Aresta::Aresta(){
    this->prox = nullptr;
}

Aresta::~Aresta(){
    //Destrutor
}

int Aresta::getId(){
    return this->id;
}

void Aresta::setId(int id){
    this->id = id;
}

/*No* Aresta::getNoAlvo(){
    return this->alvo;
}

void Aresta::setNoAlvo(No* noAlvo){
    this->alvo = noAlvo;
}*/

Aresta* Aresta::getProx(){
    return this->prox;
}

void Aresta::setProx(Aresta* p){
    this->prox = p;
}

float Aresta::getPeso(){
    return this->peso;
}

void Aresta::setPeso(float peso){
    this->peso = peso;
}
