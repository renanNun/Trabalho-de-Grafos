#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include "No.h"
#include "Utils/fila.h"


class Grafo{

private:
    int numNos;
    int numArestas;
    bool ehDirecionado;
    No* primeiro;


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
    int buscaIndice(int id);

    void buscaEmLargura();

    void insereNo(int id, float peso);
    void removeNo(int no);
    void insereAresta(int no1, int no2, float peso);
    void removeAresta(int no1,int no2);

    void quickSort(int lista[], int inicio, int fim);



};


#endif // GRAFO_H_INCLUDED
