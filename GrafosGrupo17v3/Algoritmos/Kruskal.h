#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

#include "../Grafo.h"


class Kruskal{

private:
    int numComponentesConexas;

    void algoritmoKruskal(Grafo& g){
        numComponentesConexas = 0;
        No* p = g.getPrimeiroNo();
        Aresta* a;

        Grafo* grafoSolucao = new Grafo;

        int* arvores = new int[g.getNumNos()];

    }


public:
    Kruskal(Grafo &g);
    ~Kruskal();

};

#endif // KRUSKAL_H_INCLUDED
