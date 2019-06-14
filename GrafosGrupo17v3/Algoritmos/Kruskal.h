#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

#include "../Grafo.h"
#include "ListaDeArestas.h"

class Kruskal{

private:
    int numComponentesConexas;

    void algoritmoKruskal(Grafo& g){
        numComponentesConexas = 0;
        No* p = g.getPrimeiroNo();
        ArestaSolucao* a;

        Grafo* grafoSolucao = new Grafo;

        int* arvores = new int[g.getNumNos()];
        ListaDeArestas* lista = new ListaDeArestas();

    }


public:
    Kruskal(Grafo &g);
    ~Kruskal();

};

#endif // KRUSKAL_H_INCLUDED
