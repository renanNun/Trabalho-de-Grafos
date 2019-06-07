#include "ListaDeNos.h"
#include <iostream>

using namespace std;

ListaDeNos::ListaDeNos()
{
    this->length = 0;
    this->primeiro = nullptr;
    this->ultimo = nullptr;
}

ListaDeNos::~ListaDeNos()
{
    //dtor
}

int ListaDeNos::getLength(){
    return this->length;
}

void ListaDeNos::adicionaNo(No* novoNo){
    if(this->ultimo != nullptr){
        ItemListaDeNos* novoItem = new ItemListaDeNos(ultimo, nullptr, novoNo);
        ultimo->setProximo(novoItem);
        this->ultimo = novoItem;
        length++;
    }
    else{
        ItemListaDeNos* novoItem = new ItemListaDeNos(nullptr, nullptr, novoNo);
        this->primeiro = novoItem;
        this->ultimo = novoItem;
        length++;
    }
}

void ListaDeNos::insereNo(int posicao, No* novoNo){
    if (posicao >= length){
        this->adicionaNo(novoNo);
        std::cout<< "Posicao maior ou igual ao tamanho da lista, o no sera adicionado na ultima posicao" << std::endl;
    }
    else if (posicao == 0){
        ItemListaDeNos* novoItem = new ItemListaDeNos(nullptr, this->primeiro ,novoNo);
        this->primeiro->setAnterior(novoItem);
        this->primeiro = novoItem;
        length++;
    }
    else{
        int i;
        ItemListaDeNos* antigoItemDaPosicao = this->primeiro;
        for(i = 0; i<posicao;i++){
            antigoItemDaPosicao = antigoItemDaPosicao->getProximo();
            i++;
        }
        ItemListaDeNos* novoItem = new ItemListaDeNos(antigoItemDaPosicao->getAnterior(), antigoItemDaPosicao, novoNo);
        antigoItemDaPosicao->getAnterior()->setProximo(novoItem);
        antigoItemDaPosicao->setAnterior(novoItem);
    }
}


