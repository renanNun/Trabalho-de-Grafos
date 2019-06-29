#include "Fila.h"
#include <iostream>

using namespace std;

Fila::Fila(){

    this->c = NULL;
    this->f = NULL;

}

Fila::~Fila(){
    No* p = this->c;

    while( this->c != NULL){
        this->c = p->getProx();
        delete p;
        p = this->c;
    }
}

int Fila::getTopo(){

    if(this->c == NULL)
        return -1;
    else {
        return this->c->getId();
    }
}

void Fila::enfilera(int id){
    No* p = new No();
    p->setId(id);
    p->setProx(NULL);

    if(f == NULL){
        this->c = p;
    } else {
        this->f->setProx(p);
    }

    this->f = p;
}

int Fila::desenfileira(){
    No* p;

    if(this->c != NULL){

        p = this->c;
        this->c = p->getProx();

        if(this->c == NULL)
            this->f = NULL;

        int val = p->getId();
        delete p;
        return val;
    }
    cout << "Lista Vazia!" << endl;
}

bool Fila::vazia(){
    if(this->c == NULL)
        return true;
    else return false;
}
