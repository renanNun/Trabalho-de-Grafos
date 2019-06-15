#ifndef FLOYD_H_INCLUDED
#define FLOYD_H_INCLUDED

#include "../Grafo.h"

/*** O Problema disso aqui � que tem um custo computacional do caralho, 3 la�os ***/

class Floyd{

private:
    int n;
    int **A;
    int **B;


    void caminhosMinimos(){};
    void mostrarCaminhosMinimos(){};
    void mostrarMatrizDeCustos(){};

public:
    Floyd(Grafo& g){
        this->n = g.getNumNos(); // N � o tamanho do grafo/ Tamanho do Grafo
        A = new int*[n+1]; //Cria uma lista com Tamanho n+1
        B = new int*[n+1]; //Cria uma lista com Tamanho n+1

        for(int i = 0; i < g.getNumNos(); i++){

            A[i] = new int*[n+1]; //Cria uma lista de listas/ Uma matriz
            B[i] = new int*[n+1]; //Cria uma lista de listas/ Uma matriz

        }

        /*** Tr�s La�os para a resolu��o da matriz de dist�ncias de Floyd ***/
        for(int k = 1; k < n; k++){
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    if(/*Dist�ncia[i][j]*/> /*distancia[i][k] + distancia[k][j]*/){
                        /*Dist�ncia[i][j] = dist�ncia[i][k] + dist�ncia[k][j]*/
                    }
                }
            }
        }

    };
    ~Floyd(){};

};


#endif // FLOYD_H_INCLUDED
