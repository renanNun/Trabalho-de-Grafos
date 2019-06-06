#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include "Aresta.h"

class No{

private:
    int id;
    Aresta *primeiro; //Primeiro elemento de uma lista de arestas
    No* prox; //Ponteiro para o próximo No
    int grau;

public:
    No();
    ~No();

    int getId();
    void setId();

    No* getProx();
    void setProx(No* p);

    int getGrau();
    void setGrau(int p);
    void aumentaGrau();
    void diminuiGrau();

    Aresta* getAresta();
    void setAresta(Aresta* a);
    void insereAresta(int no, Aresta* a);
    void removeAresta(int no2);


};


#endif // NO_H_INCLUDED
