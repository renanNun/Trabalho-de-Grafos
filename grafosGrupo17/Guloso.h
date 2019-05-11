#ifndef GULOSO_H_INCLUDED
#define GULOSO_H_INCLUDED

#include <iostream>
#include <list>
#include <vector>
#include <algorithm> //Essa biblioteca Ordena as coisas, eu não sei como funciona, mas funciona, não mexam... Glória ao deus Stack

#include "Grafo.h"

class Guloso{

public:
    Guloso();
    ~Guloso();
private:
    std::vector<No *> subConjuntoDeVerticesPond;
    std::vector<No *> candidatos;
    void preencheVector(Grafo *g);
    void ordenaCriterio(float chave); //Ordena o Vetor de acordo com o criterio escolhido
    bool ponderadoIgual(No* no1,float chave); //Isso aqui retorna se meu critério vai ser verdadeiro ou falso
    void atulizarVetor(No *escolhido);
    void removeNoDoCandidato(No *no);
    void removeVizinhosDoCandidato(No *no);
    std::list<No *> preencheSubConjVert(Grafo *g, float crit);
};

#endif // GULOSO_H_INCLUDED
