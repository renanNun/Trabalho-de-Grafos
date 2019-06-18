#ifndef LISTADENOS_H
#define LISTADENOS_H

#include "ItemListaDeNos.h"
#include "No.h"

class ListaDeNos
{
private:
    int length;
    ItemListaDeNos* primeiro;
    ItemListaDeNos* ultimo;
    int peso;

public:
    ListaDeNos();
    ~ListaDeNos();
    int getLength();
    void adicionaNo(No* novoNo);
    void insereNo(int posicao, No* novoNo);
    ItemListaDeNos* getItem(int posicao);
    void apagaItem (ItemListaDeNos* apagado);
    void setPeso(int novoPeso);
    void addPeso(int adicionado);
    int getPeso();
};

#endif // LISTADENOS_H
