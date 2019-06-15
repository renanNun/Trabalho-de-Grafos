#ifndef FLOYD_H_INCLUDED
#define FLOYD_H_INCLUDED

#include "../Grafo.h"

class Floyd{

private:
    int n;
    int **A;
    int **B;


    void caminhosMinimos(){};
    void mostrarCaminhosMinimos(){};
    void mostrarMatrizDeCustos(){};

public:
    Floyd(Grafo& g){
        this->n = g.getNumNos();
        A = new int*[n+1];
        B = new int*[n+1];


    };
    ~Floyd(){};

};


#endif // FLOYD_H_INCLUDED
