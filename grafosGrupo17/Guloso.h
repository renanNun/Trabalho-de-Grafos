#ifndef GULOSO_H_INCLUDED
#define GULOSO_H_INCLUDED

#include <iostream>
#include <list>
#include <vector>

#include "Grafo.h"

class Guloso{

public:
    Guloso();
    ~Guloso();
private:
    std::vector<No *> subConjuntoDeVerticesPond;
    void preencheVector(std::vector<No *> &candidatos,Grafo *g);

};

#endif // GULOSO_H_INCLUDED
