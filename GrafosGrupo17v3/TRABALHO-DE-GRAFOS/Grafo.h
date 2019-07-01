#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "No.h"
#include "Aresta.h"
#include "Fila.h"
#include <stdlib.h>



class Grafo{

private:
    int numNos;
    int numArestas;
    bool ehDirecionado;



    void auxBuscaProfundidade(No* p,int* vetorDeVisitados, int id);

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

    int grauDoGrafo(); // Falta Implementar
    int ordemDoGrafo(); // Falta Implementar

    void buscaEmProfundidade(int id);
    int buscaIndice(int id); // Passando um �ndice como Par�metro, retorno o v�rtice Correspondente

    void buscaEmLargura();

    void insereNo(int id, float peso);
    void removeNo(int no);
    void insereAresta(int no1, int no2, float peso);
    void removeAresta(int no1,int no2);

    void quickSort(int lista[], int inicio, int fim);

    /* Fun��es �teis para os algoritmos de Djisktra, Floyd, Prim e Kruskal */
    Grafo* copiaGrafo();

    No* primeiro;


};


#endif // GRAFO_H_INCLUDED