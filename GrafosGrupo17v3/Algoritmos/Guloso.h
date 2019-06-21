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

        int pivot = arr->getItem(high)->getItem()->getPeso();
        int i = (low - 1);
        for(int j = low; j <= high - 1; j++){
            if (arr->getItem(j)->getItem()->getPeso() <= pivot){
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

    void preencheVetor(Grafo *g){

    }

    void atualizarVetor(No* escolhido){

    }

    void removeCandidato(No* no){

    }
    ListaDeNos** clusters;
    ListaDeNos* listaDeCanditatos;

public:
    Guloso(int nClusters, Grafo* g, int L, int U, float alpha){

        //Aqui estao sendo inicializados a Lista de candidatos e a Lista de Clusters
        listaDeCanditatos = new ListaDeNos();
        clusters = new ListaDeNos*[nClusters];
        for(int i = 0; i<nClusters; i++){
            clusters[i] = new ListaDeNos(); //Aqui cada um dos clusters � inicializado com uma lista de nos
        }

        //Aqui preenchemos a lista de candidatos inicial por peso( para fazer o HWE )

        No* percorreNosDoGrafo = g->primeiro;
        while(percorreNosDoGrafo->getProx() != nullptr){
            listaDeCanditatos.adicionaNo(percorreNosDoGrafo);
            percorreNosDoGrafo = percorreNosDoGrafo->getProx();
        }

        quickSortPorPesoDoNo(listaDeCanditatos, 0, listaDeCanditatos->length - 1);

        for(int i = 0; i<nClusters; i++){
            No* noAtual = listaDeCanditatos->popNo(listaDeCanditatos->length - 1);
            clusters[i]->adicionaNo(noAtual,i);
        }




        //Construtor
    }
    ~Guloso(){
        //Destrutor
    }

};


#endif // GULOSO_H_INCLUDED
