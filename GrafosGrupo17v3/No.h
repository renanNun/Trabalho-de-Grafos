#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include "Aresta.h"

class No{

private:
    int id;
    Aresta *primeiro; //Primeiro elemento de uma lista de arestas
    No* prox; //Ponteiro para o pr�ximo No
    int grau; //Grau de um N�
    float peso; //Peso que um N� carrega

public:
    No();
    ~No();

    int getId(); //Retorna o ID de um N�
    void setId(int id); // Insere um ID para um N�

    float getPeso(); //Retorna o Peso de um N�
    void setPeso(float peso); //Insere o valor de Peso a um n�

    No* getProx(); //Retorna o ponteiro para o Pr�ximo N�
    void setProx(No* p); //Define o ponteiro para o Pr�ximo N�

    int getGrau(); //Retorna o Grau de um N�
    void setGrau(int p); //Define o Grau de um N�
    void aumentaGrau(); //Aumenta o Grau de um N�
    void diminuiGrau(); //Diminui o Grau de um N�

    Aresta* getAresta(); //Retorna o primeiro elemento de uma lista de Arestas daquele N�
    void setAresta(Aresta* a); //Define o primeiro elemento de uma lista de Arestas daquele N�
    void insereAresta(int no, Aresta* a); //Insere uma aresta na lista de N�s
    void removeAresta(int no2); //Remove uma aresta da lista de N�s


};


#endif // NO_H_INCLUDED
