#ifndef DJISKTRA_H_INCLUDED
#define DJISKTRA_H_INCLUDED

#include "../Grafo.h"

class Djisktra{

private:
    void algoritmoDjisktra(Grafo &g, int noIncial, int estimativaMax)
    {
        int* vertices = new int[g.getNumNos()]; //vertice é a mesma coisa que No
        int* distancias = new int[g.getNumNos()];
        int* predecessores = new int[g.getNumNos()];
        int* abertos = new int[g.getNumNos()];

        No* p = g.getPrimeiroNo();

        while(p != NULL){

            int i = g.buscaIndice(p->getId());

            vertices[i] = p->getId();

            if(p->getId() == noInicial){
                distancias[i] = 0;
                predecessores[i] = p->getId();
            } else {
                distancias[i] = estimativaMax;
                predecessores[i] = -1;
            }

            abertos[i] = -1;
            p = p->getProx();
        }

        p = g.getPrimeiroNo();
        Aresta *adj;
        int numNosAbertos = g.getNumNos();
        int indiceComMenorEstimativa;

        while(numNosAbertos > 0){

            indiceComMenorEstimativa = //auxiliar que calcula isso aqui.

        }

    };

public:
    Djisktra(){
        //Construtor
    };

    ~Djisktra(){
        //Destrutor
    };
};


#endif // DJISKTRA_H_INCLUDED
