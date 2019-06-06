#include "Aresta.h
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
