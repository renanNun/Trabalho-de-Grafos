#ifndef FLOYD_H_INCLUDED
#define FLOYD_H_INCLUDED

#include "../Grafo.h"
#include <limits.h>

/*** O Problema disso aqui é que tem um custo computacional do caralho, 3 laços ***/

class Floyd
{

private:
    int n;
    int **A;
    int **B;


    void caminhosMinimos()
    {

        for(int i = 1 ; i <= n ; i++)
            for(int j = 1 ; j <= n ; j++)
                A[i][j] = B[i][j];

        /*** Três Laços para a resolução da matriz de distâncias de Floyd ***/
        for(int k = 1; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(A[i][j] > A[i][k] + A[k][j])
                    {
                        A[i][j] = A[i][k] + A[k][j]
                    }
                }
            }
        }

    };

    void mostrarMatrizDeCustos()
    {

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if(B[i][j] == INT_MAX / 2)
                {
                    std::cout << "I " ;
                }
                else
                {
                    std::cout << B[i][j] << " ";
                }
            }
            std::cout << std::endl;
        }


    };

public:
    Floyd(Grafo& g)
    {
        this->n = g.getNumNos(); // N é o tamanho do grafo/ Tamanho do Grafo
        A = new int*[n+1]; //Cria uma lista com Tamanho n+1
        B = new int*[n+1]; //Cria uma lista com Tamanho n+1

        for(int i = 0; i < g.getNumNos(); i++)
        {

            A[i] = new int[n+1]; //Cria uma lista de listas/ Uma matriz
            B[i] = new int[n+1]; //Cria uma lista de listas/ Uma matriz

        }

        for(int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i == j)
                    B[i][j] = 0;
                else
                    B[i][j] = INT_MAX / 2;
            }
        }

        for(No* p = g.getPrimeiroNo(); p != nullptr; p = p->getProx())
        {
            for(Aresta* a = p->getAresta(); a != nullptr; a = a->getProx())
            {
                B[p->getId()][a->getProx()->getId()] = a->getPeso();
            }
        }


    };

    ~Floyd() {};

};


#endif // FLOYD_H_INCLUDED
