#include "ListaDeArestas.h"

using namespace std;

ListaDeArestas::ListaDeArestas(){
    this->tamanho = 0;
    this->primeiro = nullptr;
}

ListaDeArestas::~ListaDeArestas(){
    ArestaSolucao* a = this->primeiro;

    while (a != nullptr){
        ArestaSolucao* aux = a->getProx();
        delete a;
        a = aux;
    }
}

ArestaSolucao* ListaDeArestas::getPrimeiro(){
    return this->primeiro;
}

void ListaDeArestas::insereAresta(int id,int id2, float peso){
    ArestaSolucao* p = this->primeiro;
    ArestaSolucao* a = new ArestaSolucao();

    a->setNo1(id);
    a->setNo2(id2);
    a->setPeso(peso);

    if(p == nullptr){
        this->primeiro = a;
        a->setProx(nullptr);
        tamanho++;
    } else {
        this->primeiro = a;
        a->setProx(p);
        tamanho++;
    }
}

ArestaSolucao* ListaDeArestas::removeAresta(int id,int id2){
    ArestaSolucao* p = this->primeiro;
    ArestaSolucao* aux = nullptr;

    while(p!=nullptr){

        if((p->getNo1() == id && p->getNo2() == id2) || (p->getNo1() == id2 && p->getNo2() == id)){
                break;
           }
        aux = p;
        p = p->getProx();
    }

    if(p != nullptr){

        aux->setProx(p->getProx());

        delete p;
        tamanho--;
    }


}

int ListaDeArestas::getTamanho(){
    return this->tamanho;
}

bool ListaDeArestas::vazia(){
    if (this->primeiro == nullptr){
        return true;
    } else{
        return false;
    }
}

ArestaSolucao* ListaDeArestas::removePrimeiraAresta(){

    ArestaSolucao* p = this->primeiro;

    if(p!= nullptr){
        this->primeiro = p->getProx();
        delete p;
        tamanho--;
    }

}
