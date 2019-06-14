#ifndef PRIM_H_INCLUDED
#define PRIM_H_INCLUDED

#include "../Grafo.h"
#include "ArestaSolucao.h"

class Prim
{

private:
    int noDePartida;

    void OrdenaListaDeArestas(ListaDeArestas* auxilar; int inicio,int final) //ISSO AQUI É UM QUICKSORT PRA LISTA DE ARESTAS, AMÉM
    {
        int i,j, pivo;
        i = inicio;
        j = fim-1;
        ArestaSolucao aux;

        pivo = auxiliar[(inicio + fim)/2];

        while (i <= j)
        {

            while (auxiliar[i] > pivo &&  i < fim)
                i++;

            while (auxiliar[j] < pivo && j > inicio)
                j--;

            if (i <= j)
            {
                auxiliar[i] = lista[j];
                auxiliar[j] = aux;
                i++;
                j++;
            }
        }

        if (j > inicio)
            OrdenaListaDeArestas(auxiliar,inicio,j+1);
        if (i < fim)
            OrdenaListaDeArestas(auxiliar,i,fim);
    }

    Grafo* algoritmoPrim(Grafo* g)
    {
        Grafo* copiaGrafo = g->copiaGrafo();
        Grafo* grafoPrim = new Grafo();
        bool visitados[g->getNumNos()];

        for(int i = 0; i < g->getNumNos(); i++)
        {
            visitados[i] = false;
        }

        visitados[this->noDePartida-1] = true;
        No* p;
        Prim->insereNo(this->noDePartida,0);
        ArestaSolucao* vetorDeArestas = new ArestaSolucao[g.getNumArestas];
        Aresta* a;

        int arestas = 0;
        int aux = 0;
        int numVisitados = 1;


        for(int i = 0; i < copiaGrafo->getNumNos(); i++)
        {
            if(visitados[i] == true)
            {
                p = copiaGrafo->buscaNo(i+1);
                if(p != nullptr)
                {
                    a = p->getAresta();

                    while(a != nullptr)
                    {
                        vetorDeArestas[arestas].setNo1(p->getId());
                        vetorDeArestas[arestas].setNo2(a->getId());
                        vetorDeArestas[arestas].setPeso(a->getPeso());
                        a = a->getProx();
                        arestas++;
                    }
                }
            }
        }

        this->OrdenaListaDeArestas(vetorDeArestas,0,arestas-1);
        arestas = 0;
        aux = 0;

        while((visitados[vetorDeArestas[aux].getNo2()-1] == true)
                aux++;

                if(copiaGrafo->buscaNo(vetorDeArestas[aux].getNo2()) == nullptr)
                    grafoPrim->insereNo(vetorDeArestas[aux].getNo2());

                    if(!(visitados[vetorDeArestas[aux].getNo2()-1])
            {

                grafoPrim->insereAresta(vetorDeArestas[aux].getNo1(),vetorDeArestas[aux].getNo2(),vetorDeArestas[aux].getPeso());
                    copiaGrafo->removeAresta(vetorDeArestas[aux].getNo1(),vetorDeArestas[aux].getNo2());
                    visitados[vetorDeArestas[aux].getNo2() == true];
                    numVisitados++;

                }

        return grafoPrim;
    };

public:
    Prim(int noDePartida,Grafo *g)
    {
        this->noDePartida = noDePartida;

        algoritmoPrim(g);
    };

    ~Prim()
    {
        //Destrutor
    };

};


#endif // PRIM_H_INCLUDED
