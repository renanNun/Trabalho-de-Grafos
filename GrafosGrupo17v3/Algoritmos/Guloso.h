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
        listaDeCanditatos = new ListaDeNos();
        clusters = new ListaDeNos*[nClusters];
        for(int i = 0; i<nClusters; i++){
            clusters[i] = new ListaDeNos();
        }

        No* percorreNosDoGrafo = g->primeiro;
        while(percorreNosDoGrafo->getProx() != nullptr){
            listaDeCanditatos.adicionaNo(percorreNosDoGrafo);
            percorreNosDoGrafo = percorreNosDoGrafo->getProx();
        }


        //Construtor
    }
    ~Guloso(){
        //Destrutor
    }

};


#endif // GULOSO_H_INCLUDED
