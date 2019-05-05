#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <iostream>
#include "No.h"
#include "Aresta.h"

class Grafo{

public:
    Grafo();
    Grafo(bool direcional);
    Grafo(bool direcional, bool ponderadoAresta);
    Grafo(bool direcional, bool ponderadoAresta, bool ponderadoNo);
    ~Grafo();

    void setOrdem(int ordem);
    int getOrdem();
    No *getNo(int id);
    void setNo(int id);
    void setAresta(int id1,int id2);
    bool deleteAresta(int id);
    bool deleteNo(int id);
    void setGrau(int grau);
    int getGrau();
    void buscaProfundidade(int id);
    void caminhamentoLargura(int id);
    int quantCompenetesConexas();
    int quantComponentesFortConexas();
    void gerarComplementar();

    bool ehPonderadoAresta();
    bool ehPonderadoNo();

private:
    int ordem;
    int grau;
    bool direcional;
    bool ponderadoNos;
    bool ponderadoArestas;
    std::list<No *> nos;
    std::list<Aresta *> arestas;
};


#endif // GRAFO_H_INCLUDED
