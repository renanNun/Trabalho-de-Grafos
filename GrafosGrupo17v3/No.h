#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include "Aresta.h"

class No{

private:
    int id;
    Aresta *primeiro; //Primeiro elemento de uma lista de arestas
    No* prox; //Ponteiro para o próximo No
    int grau; //Grau de um Nó
    float peso; //Peso que um Nó carrega

public:
    No();
    ~No();

    int getId(); //Retorna o ID de um Nó
    void setId(int id); // Insere um ID para um Nó

    float getPeso(); //Retorna o Peso de um Nó
    void setPeso(float peso); //Insere o valor de Peso a um nó

    No* getProx(); //Retorna o ponteiro para o Próximo Nó
    void setProx(No* p); //Define o ponteiro para o Próximo Nó

    int getGrau(); //Retorna o Grau de um Nó
    void setGrau(int p); //Define o Grau de um Nó
    void aumentaGrau(); //Aumenta o Grau de um Nó
    void diminuiGrau(); //Diminui o Grau de um Nó

    Aresta* getAresta(); //Retorna o primeiro elemento de uma lista de Arestas daquele Nó
    void setAresta(Aresta* a); //Define o primeiro elemento de uma lista de Arestas daquele Nó
    void insereAresta(int no, Aresta* a); //Insere uma aresta na lista de Nós
    void removeAresta(int no2); //Remove uma aresta da lista de Nós


};


#endif // NO_H_INCLUDED
