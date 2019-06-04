#ifdef ARESTA_H
#define ARESTA_H
#include <iostream>

using namespace std;

class Aresta {

public:

    Aresta(int _no); //Construtor 1
    Aresta(int _no, float _peso); //Construtor 2
    ~Aresta();

    float getPeso();
    Aresta *getProx();
    int getNoAdj();


    void setProx(Aresta *aresta);

private:

    int noAdj;
    float peso;
    Aresta* prox;

};

#endif //ARESTA_H