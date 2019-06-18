#ifndef GULOSO_H_INCLUDED
#define GULOSO_H_INCLUDED

#include "../Grafo.h"

class Guloso{

private:
    No* sucConjDeVertices(Grafo *g){

    }

    void preencheVetor(Grafo *g){

    }

    void atualizarVetor(No* escolhido){

    }

    void removeCandidato(No* no){

    }
    ListaDeNos** clusters;
    ListaDeNos* listaDeCanditatos;

public:
    Guloso(int nClusters, Grafo* g, int L, int U){
        listaDeCanditatos = new ListaDeNos();
        clusters = new ListaDeNos*[nClusters];
        for(int i = 0, i<nClusters, i++){
            clusters[i] = new ListaDeNos();
        }

        //Construtor
    }
    ~Guloso(){
        //Destrutor
    }

};


#endif // GULOSO_H_INCLUDED
