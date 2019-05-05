#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

#include <iostream>
#include "No.h"

class Aresta{

public:
    Aresta();
    Aresta(No *no1,No *no2,float peso);
    Aresta(No *no1,No *no2);
    ~Aresta();

    float getPeso();
    No* getNo1();
    No* getNo2();
private:
    No *no1;
    No *no2;
    float peso;
};

#endif // ARESTA_H_INCLUDED
