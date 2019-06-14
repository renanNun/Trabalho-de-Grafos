#ifndef LEITURA_H_INCLUDED
#define LEITURA_H_INCLUDED

#include "../Grafo.h"
#include "ListaDeArestas.h"
#include <iostream>
#include <stdlib.h>


class Leitura{

public:
    Leitura(){};
    ~Leitura(){};

    void imprimeGrafo(Grafo& g,FILE* arquivo){
        No* p = g.getPrimeiroNo();
        std::fprintf(arquivo, "LISTA DE ADJACENCIAS: \n");

        while(p != NULL){

            std::fprintf(arquivo, "[%d, %f] ",p->getId(),p->getPeso());

            if(p->getAresta() != NULL){

                Aresta* a = p->getPrimeiro();

                while (a != NULL){
                    std::fprintf(arquivo, "%d, %f",a->getId(),a->getPeso());
                    a = a->getProx();
                }
            } else {
                std::fprintf(arquivo, "-----");
            }
            std::fprintf(arquivo, "\n");
            p = p->getProx();

        }
    }

    void imprimeKruskal(ListaDeArestas& lista,FILE* arquivo){
        Aresta* a = lista.getPrimeiro();

        std::fprintf(arquivo, "SOLUCAO KRUSKAL: \n");

        while(a != nullptr){

            std::fprintf(arquivo, // Implementar aqui a lista
                         );
            a = a->getProx();

        }
    }

};

#endif // LEITURA_H_INCLUDED
