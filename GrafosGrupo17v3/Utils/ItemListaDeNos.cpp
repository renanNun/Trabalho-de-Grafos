#include "ItemListaDeNos.h"
#include <iostream>

using namespace std;

ItemListaDeNos::ItemListaDeNos(ItemListaDeNos* ant, ItemListaDeNos* prox, No* no)
{
    this->anterior = ant;
    this->proximo = prox;
    this->item = no;
    if(ant != nullptr){
        posicao = ant->getPosicao();
    }
    else{
        posicao = 0;
    }
}

ItemListaDeNos::~ItemListaDeNos()
{
    //dtor
}

int ItemListaDeNos::getPosicao(){
    return this->posicao;
}
