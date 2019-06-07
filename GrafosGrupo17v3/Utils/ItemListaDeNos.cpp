#include "ItemListaDeNos.h"
#include <iostream>

using namespace std;

ItemListaDeNos::ItemListaDeNos(ItemListaDeNos* ant, ItemListaDeNos* prox, No* no)
{
    this->anterior = ant;
    this->proximo = prox;
    this->item = no;
}

ItemListaDeNos::~ItemListaDeNos()
{
    //dtor
}


void ItemListaDeNos::setItem(No* novoItem){
    this->item = novoItem;
}

No* ItemListaDeNos::getItem(){
    return this->item;
}

void ItemListaDeNos::setAnterior(ItemListaDeNos* novoAnterior){
    this->anterior = novoAnterior;
}

ItemListaDeNos* ItemListaDeNos::getAnterior(){
    return this->anterior;
}

void ItemListaDeNos::setProximo(ItemListaDeNos* novoProximo){
    this->proximo = novoProximo;
}

ItemListaDeNos* ItemListaDeNos::getProximo(){
    return this->proximo;
}
