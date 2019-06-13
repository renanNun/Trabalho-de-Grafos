#ifndef DJISKTRA_H_INCLUDED
#define DJISKTRA_H_INCLUDED

#include "../Grafo.h"
#include <limits.h>


class Djisktra{

private:
     int* vertices = new int[g.getNumNos()]; //vertice é a mesma coisa que No
     int* distancias = new int[g.getNumNos()];
     int* predecessores = new int[g.getNumNos()];
     int* abertos = new int[g.getNumNos()];

    void algoritmoDjisktra(Grafo &g, int noIncial)
    {
        No* p = g.getPrimeiroNo();

        while(p != NULL){

            int i = g.buscaIndice(p->getId());

            vertices[i] = p->getId();

            if(p->getId() == noInicial){
                distancias[i] = 0;
                predecessores[i] = p->getId();
            } else {
                distancias[i] = INT_MAX;
                predecessores[i] = -1;
            }

            abertos[i] = -1;
            p = p->getProx();
        }

        p = g.getPrimeiroNo();
        Aresta *adj;
        int numNosAbertos = g.getNumNos();
        int indiceComMenorEstimativa;

        while(numNosAbertos > 0){

            indiceComMenorEstimativa = buscaIndiceComMenorEstimativa(distancias,abertos,g.getNumNos());

            if(abertos[indiceComMenorEstimativa] == -1){

                abertos[indiceComMenorEstimativa] = 1;

                adj = g.buscaNo(vertices[indiceComMenorEstimativa])->getAresta();

                while(adj != NULL){
                    if(distancias[indiceComMenorEstimativa] + adj->getPeso() < distancias[g.buscaIndice(adj->getId())]){
                        distancias[g.buscaIndice(adj->getId())] = distancias[indiceComMenorEstimativa] + adj->getPeso();
                        predecessores[g.buscaIndice(adj->getId())] = vertices[indiceComMenorEstimativa];
                    }
                    adj = adj->getProx();
                }
            }
            numNosAbertos--;
        }

        std::cout<<"DISTANCIAS MINIMAS DO VERTICE %d PARA O RESTANTE DOS VERTICES DO GRAFO :\n", noInicial << std::endl;

        for(int i = 0; i < g.getNumNos();i++){
            std::cout<<"PARA O VERTICE %d = %d\n",  vertice[i],distancias[i] << std::endl;
        }

    };

    int buscaIndiceComMenorEstimativa(int* distancias, int* abertos, int tam)
    {

      int menor;
      int indice = 0;

      for(int i = 0; i < tam; i++){
        if (abertos[i] == -1)
            menor = distancias[i];
      }

      for(int i = 0; i < tam; i++){
        if(abertos[i] == -1){
            if(distancias[i] < menor){
                menor = distancias[i];
                indice = i;
            }
        }
      }

        return indice;
    };

public:
    Djisktra(Grafo& g, int noInicial){
        vertices = new int[g.getNumNos()]; //vertice é a mesma coisa que No
        distancias = new int[g.getNumNos()];
        predecessores = new int[g.getNumNos()];
        abertos = new int[g.getNumNos()];

        algoritmoDjisktra(g,noInicial);
    };

    ~Djisktra(){

        delete [] vertices;
        delete [] distancias;
        delete [] predecessores;
        delete [] abertos;

    };
};


#endif // DJISKTRA_H_INCLUDED
