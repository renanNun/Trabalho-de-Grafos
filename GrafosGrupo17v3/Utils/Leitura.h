#ifndef LEITURA_H_INCLUDED
#define LEITURA_H_INCLUDED

#include "../Grafo.h"



class Leitura{

public:
    void imprimeGrafo(Grafo& g, FILE* arquivo){
        No* p = g.getPrimeiroNo();
        std::fprintf(arquivo, "LISTA DE ADJACENCIAS: \n");

        while(p != NULL){

            std::fprintf(arquivo, "[%d,%f] ",p->getId(),p->getPeso());

        }
    }

};

#endif // LEITURA_H_INCLUDED
