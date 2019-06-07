#ifndef GULOSO_H_INCLUDED
#define GULOSO_H_INCLUDED
#include "../Grafo.h"

class Guloso{

private:
    No* solucaoInicial;

    void preencheSolucaoInicial(Grafo* g);

public:
    Guloso(Grafo *g);
    ~Guloso();

};


#endif // GULOSO_H_INCLUDED
