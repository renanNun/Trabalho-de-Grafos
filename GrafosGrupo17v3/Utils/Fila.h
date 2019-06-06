#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

#include "../No.h"

class Fila{

private:
    No* c;
    No* f;
public:
    Fila;
    ~Fila();
    int getTopo();
    void enfilera(int id);
    int desenfileira();
    bool vazia();

};

#endif // FILA_H_INCLUDED
