#ifdef NO_H
#define NO_H
#include <iostream>
#include "Aresta.h"

using namespace std;

class No {

public:

    No(int _id);
    No(int _id, float _peso);
    ~No();

    void setProx(No *n);
    bool setAresta(Aresta *aresta);
    void aumentaGrauEntrada();
    void aumentaGrauSaida();

    int getId();
    float getPeso();
    int getGrauEntrada();
    int getGrauSaida();
    No* getProx();
    Aresta *getAresta();
    Aresta *getAresta(int i);

private:

    int id; //Indíce do Vértice.
    float peso; //Peso Contido no Vértice.
    Aresta *adj; //Aresta Adjacente ao Nó.
    No *prox; //O próximo Vértice.

    /*Caso estejamos nos referindo a um Grafo Ponderado*/
    int grauEntrada; //Grau de Entrada do Vértice.
    int grauSaida;  //Grau de Saída do Vértice.
};

#endif //NO_H