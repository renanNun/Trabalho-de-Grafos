#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "No.h"

class Grafo{

private:
    int numNos;
    int numArestas;
    bool ehDirecionado;
    No* primeiro;

    void auxBuscaProfundidade();

public:
    Grafo();
    ~Grafo();

    /**Funcionalidades do Grafo**/
    int getNumNos();
    int getNumArestas();

    bool ehGrafoDirecionado();
    void setDirecionado(bool x);

    No* getPrimeiroNo();
    No* buscaNo(int id);
    Aresta* buscaAresta(int no1, int no2);

    int grauDoGrafo();
    int ordemDoGrafo();

    bool ehCompleto();

    void buscaEmProfundidade();
    void buscaEmLargura();

    void insereNo(int id, float peso);
    void removeNo(int no);
    void insereAresta(int no1, int no2, float peso);
    void removeAresta(int no1,int no2);





};


#endif // GRAFO_H_INCLUDED
