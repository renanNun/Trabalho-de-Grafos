#ifndef ITEMLISTADENOS_H
#define ITEMLISTADENOS_H

#include "../No.h"

class ItemListaDeNos
{
private:
    No* item;
    ItemListaDeNos* anterior;
    ItemListaDeNos* proximo;

public:
    ItemListaDeNos(ItemListaDeNos* ant, ItemListaDeNos* prox, No* no);
    ~ItemListaDeNos();
    void setItem(No* novoItem);
    No* getItem();
    void setAnterior(ItemListaDeNos* novoAnterior);
    ItemListaDeNos* getAnterior();
    void setProximo(ItemListaDeNos* novoProximo);
    ItemListaDeNos* getProximo();


};

#endif // ITEMLISTADENOS_H
