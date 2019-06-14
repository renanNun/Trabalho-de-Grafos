#include "ListaDeArestas.h"

using namespace std;

ListaDeArestas::ListaDeArestas(){
    this->tamanho = 0;
    this->primeiro = nullptr;
}

ListaDeArestas::~ListaDeArestas(){
    Aresta* a = this->primeiro;

    while (a != nullptr){
        Aresta* aux = a->getProx();
        delete a;
        a = aux;
    }
}

Aresta* ListaDeArestas::getPrimeiro(){
    return this->primeiro;
}

void ListaDeArestas::insereAresta(int id,int id2, float peso){

}

Aresta* ListaDeArestas::removeAresta(int id,int id2){

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
void ListaDeArestas::imprime(){

}
