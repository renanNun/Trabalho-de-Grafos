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

void ListaDeNos::adicionaNo(No* novoNo){
    if(this->ultimo != nullptr){
        ItemListaDeNos* novoItem = new ItemListaDeNos(ultimo, nullptr, novoNo);
        ultimo->setProximo(novoItem);
        this->ultimo = novoItem;
    }
    else{
        ItemListaDeNos* novoItem = new ItemListaDeNos(nullptr, nullptr, novoNo);
        this->primeiro = novoItem;
        this->ultimo = novoItem;
    }
}


