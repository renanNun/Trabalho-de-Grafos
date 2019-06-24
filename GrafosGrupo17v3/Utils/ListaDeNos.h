#ifndef LISTADENOS_H
#define LISTADENOS_H

#include "ItemListaDeNos.h"
#include "../No.h"

class ListaDeNos
{
private:
    int length;
    ItemListaDeNos* primeiro;
    ItemListaDeNos* ultimo;
    float peso;
    float pontuacaoAtual;

public:
    ListaDeNos();
    ~ListaDeNos();
    int getLength();
    ItemListaDeNos* getUltimo();
    void adicionaNo(No* novoNo, int clusterSendoTestado);
    void insereNo(int posicao, No* novoNo, int clusterSendoTestado);
    ItemListaDeNos* getItem(int posicao);
    No* getNo(int posicao);
    void apagaItem (ItemListaDeNos* apagado);
    void setPeso(float novoPeso);
    void addPeso(float adicionado);
    float getPeso();
    No* popNo(int index);
    float getPontuacaoAtual();
    void setPontuacaoAtual(float novoValor);
    void addPontuacaoAtual(float adicionado);
};

#endif // LISTADENOS_H
