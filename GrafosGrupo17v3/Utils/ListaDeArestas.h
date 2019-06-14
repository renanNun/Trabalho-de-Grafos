#ifndef LISTADEARESTAS_H_INCLUDED
#define LISTADEARESTAS_H_INCLUDED

#include "../Aresta.h"

class ListaDeArestas{

private:
    Aresta* primeiro;
    int tamanho;
public:
    ListaDeArestas();
    ~ListaDeArestas();

    ListaDeArestas* getPrimeiro();
    void insereAresta(int id,int id2, float peso);
    Aresta* removeAresta(int id,id2);
    int getTamanho();
    bool vazia();
    void imprime();

};

#endif // LISTADEARESTAS_H_INCLUDED
