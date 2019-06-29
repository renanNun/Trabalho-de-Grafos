#ifndef LISTADEARESTAS_H_INCLUDED
#define LISTADEARESTAS_H_INCLUDED

#include "ArestaSolucao.h"

/*** LISTA DE ARESTAS SOLUÇÃO PARA A RESOLUÇÃO DO ALGORITMO DE KRUSKAL, PRIM ***/

class ListaDeArestas{

private:
    ArestaSolucao* primeiro;
    int tamanho;
public:
    ListaDeArestas();
    ~ListaDeArestas();

    ArestaSolucao* getPrimeiro();
    void insereAresta(int id,int id2, float peso);
    ArestaSolucao* removeAresta(int id,int id2);
    ArestaSolucao* removePrimeiraAresta();
    int getTamanho();
    bool vazia();

};

#endif // LISTADEARESTAS_H_INCLUDED
