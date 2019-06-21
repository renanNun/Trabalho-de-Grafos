#ifndef GULOSO_H_INCLUDED
#define GULOSO_H_INCLUDED

#include "../Grafo.h"
#include "../Utils/ListaDeNos.h"
#include "../Utils/ItemListaDeNos.h"

class Guloso{

private:

    void trocar(ItemListaDeNos* a, ItemListaDeNos* b){
        No* aux = a->getItem();
        a->setItem(b->getItem());
        b->setItem(aux);
    }

    int particaoPesoDoNo(ListaDeNos* arr, int low, int high){

        int pivot = arr->getNo(high)->getPeso();
        int i = (low - 1);
        for(int j = low; j <= high - 1; j++){
            if (arr->getNo(j)->getPeso() <= pivot){
                i++;
                trocar(arr->getItem(i),arr->getItem(j));
            }
        }
    trocar(arr->getItem(i + 1), arr->getItem(high));
    return (i+1);
    }

    void organizaPorPesoDoNo(){
        if(listaDeCanditatos == nullptr){
            std::cout << "Lista de Candidatos vazia, portanto organizada" << endl;
            return;
        }

        quickSortPorPesoDoNo(listaDeCanditatos, 0, listaDeCanditatos->getLength()-1);
    }

    void quickSortPorPesoDoNo(ListaDeNos* arr, int low, int high){
        if(low < high){
            int pi = partition(arr, low, high);

            quickSortPorPesoDoNo(arr, low, pi - 1);
            quickSortPorPesoDoNo(arr, pi+1, high);
        }
    }



    ListaDeNos** clusters;
    ListaDeNos* listaDeCanditatos;

public:
    Guloso(int nClusters, Grafo* g, int L, int U, float alpha){

        //Aqui estao sendo inicializados a Lista de candidatos e a Lista de Clusters
        listaDeCanditatos = new ListaDeNos();
        clusters = new ListaDeNos*[nClusters];
        for(int i = 0; i<nClusters; i++){
            clusters[i] = new ListaDeNos(); //Aqui cada um dos clusters é inicializado com uma lista de nos
        }

        //Aqui preenchemos a lista de candidatos inicial

        No* percorreNosDoGrafo = g->primeiro;
        while(percorreNosDoGrafo->getProx() != nullptr){
            //Aqui vai ser colocado como se fosse o teste pro cluster 0 pois fica mais facil do que mudar logo a frente
            listaDeCanditatos->adicionaNo(percorreNosDoGrafo, 0);
            percorreNosDoGrafo = percorreNosDoGrafo->getProx();
        }

        //Aqui é feita a organização por peso e os nós mais pesados são colocados um em cada cluster
        quickSortPorPesoDoNo(listaDeCanditatos, 0, listaDeCanditatos->getLength() - 1);

        for(int i = 0; i<nClusters; i++){
            No* noAtual = listaDeCanditatos->popNo(listaDeCanditatos->getLength() - 1);
            clusters[i]->adicionaNo(noAtual,i);
        }

        //A lista de candidatos sgora será alterada para ser por quantos pontos ela adiciona para a solução
        //Por isso cada item terá nClusters copias de si mesmo (Cada um para o numero de pontos que ele adiciona em cada cluster)

        //Aqui salvamos quantos nós tem na CL e fazemos as outras (nClustes - 1) copias de cada item da lista
        int nNosListaDeCandidatos = listaDeCanditatos->getLength();
        for (int i = 0; i<nClusters-1; i++){
            for(int j = 0; j<nNosListaDeCandidatos; j++){
                listaDeCanditatos->adicionaNo(listaDeCanditatos->getItem(j), i + 1);
            }
        }

        //Agora temos uma CL com nClusters copias de cada No e vamos organizar por pontos que ela soma a solução



        //Construtor
    }
    ~Guloso(){
        //Destrutor
    }

};


#endif // GULOSO_H_INCLUDED
