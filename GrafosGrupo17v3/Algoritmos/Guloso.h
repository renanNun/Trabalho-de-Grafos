#ifndef GULOSO_H_INCLUDED
#define GULOSO_H_INCLUDED

#include <cstdlib>
#include <ctime>
#include "../Grafo.h"
#include "ListaDeNos.h"
#include "ItemListaDeNos.h"

class Guloso{

private:

    void trocar(ItemListaDeNos* a, ItemListaDeNos* b){
        No* aux = a->getItem();
        float auxPontos = a->addPontuacaoNoCluster();
        int auxCluster = a->getClusterAtualSendoTestado();
        a->setItem(b->getItem());
        a->setPontuacaoNoCluster(b->getPontuacaoNoCluster());
        a->setClusterAtualSendoTestado(b->getClusterAtualSendoTestado());
        b->setItem(aux);
        b->setPontuacaoNoCluster(auxPontos);
        b->setClusterAtualSendoTestado(auxCluster);
    }

    int particaoPesoDoNo(ListaDeNos* arr, int low, int high){
        float pivot = arr->getNo(high)->getPeso();
        int i = (low - 1);
        for(int j = low; j <= high - 1; j++){
            if(arr->getNo(j)->getPeso() <= pivot){
                i++;
                trocar(arr->getItem(i),arr->getItem(j));
            }
        }
    trocar(arr->getItem(i + 1), arr->getItem(high));
    return (i+1);
    }

    int particaoPontosNaSolucao(ListaDeNos* arr, int low, int high){
        float pivot = arr->getItem(high)->getPontuacaoNoCluster();
        int i = (low - 1);
        for(int j = low; j <= high - 1; j++){
            if(arr->getItem(j)->getPontuacaoNoCluster() <= pivot){
                i++;
                trocar(arr->getItem(i),arr->getItem(j));
            }
        }
    trocar(arr->getItem(i + 1), arr->getItem(high));
    return (i+1);
    }

    void organizaPorPesoDoNo(){
        if(listaDeCanditatos == nullptr){
            std::cout << "Lista de Candidatos vazia, portanto organizada" << std::endl;
        }
        else {
            quickSortPorPesoDoNo(listaDeCanditatos, 0, listaDeCanditatos->getLength()-1);
        }
    }

    void organizaPorPontosNaSolucao(){
        if(listaDeCanditatos == nullptr){
            std::cout << "Lista de Candidatos vazia, portanto organizada" << std::endl;
        }
        else {
            quickSortPorPontosNaSolucao(listaDeCanditatos, 0, listaDeCanditatos->getLength()-1);
        }
    }

    void quickSortPorPesoDoNo(ListaDeNos* arr, int low, int high){
        if(low < high){
            int pi = particaoPesoDoNo(arr, low, high);

            quickSortPorPesoDoNo(arr, low, pi - 1);
            quickSortPorPesoDoNo(arr, pi+1, high);
        }
    }

    void quickSortPorPontosNaSolucao(ListaDeNos* arr, int low, int high){
        if(low < high){
            int pi = particaoPontosNaSolucao(arr, low, high);

            quickSortPorPontosNaSolucao(arr, low, pi - 1);
            quickSortPorPontosNaSolucao(arr, pi+1, high);

        }
    }

    void somaPossiveisPontosAosItems(No* noAdicionadoASolucao, int clusterDesignado){
        Aresta* arestaPercorredoraDaListaDeAdjacencias = noAdicionadoASolucao->getAresta();
        while(arestaPercorredoraDaListaDeAdjacencias->getProx()!= nullptr){
            for(int i = 0; i<listaDeCanditatos; i++){
                ItemListaDeNos* aux = listaDeCanditatos->getItem(i);
                if(aux->getItem()->getId() != arestaPercorredoraDaListaDeAdjacencias->getId()){
                    aux->addPontuacaoNoCluster(arestaPercorredoraDaListaDeAdjacencias->getPeso());
                }
            }
        }
    }

    void insereItemNaSolucaoPelosPontos(int index){
        ItemListaDeNos* itemEscolhido = listaDeCanditatos->getItem(index);
        No* noEscolhido = itemEscolhido->getItem();
        int clusterEscolhido = itemEscolhido->getClusterAtualSendoTestado();
        clusters[clusterEscolhido]->adicionaNo(listaDeCanditatos->popNo(index));
        somaPossiveisPontosAosItems(noEscolhido, clusterEscolhido);
        this->organizaPorPontosNaSolucao();
    }

    void getRandomNumber(int lower, int upper){
        return rand()%(upper - lower) + lower;
    }

    bool podeAdicionarONoAoCluster(ItemListaDeNos* itemEscolhido, float upperBound){
        No* noEscolhido = itemEscolhido->getItem();
        int clusterEscolhido = itemEscolhido->getClusterAtualSendoTestado();
        if(noEscolhido->getPeso() + clusters[clusterEscolhido]->getPeso() > upperBound){
            return false;
        }
        else{
            return true;
        }
    }

    bool oMinimoDosClustersFoiAtingido(float lowerBound, int nClusters){
        for(int i = 0; i<nClusters; i++){
            if(!nClusters[i]->getMinimoDoClusterSatisfeito()){
                return false;
            }
        }
        return true;
    }

    ListaDeNos** clusters;
    ListaDeNos* listaDeCanditatos;

public:
    Guloso(){
       //Construtor
    }
    ~Guloso(){
        //Destrutor
    }

    void geraSolucao(int nClusters, Grafo* g, int L, int U, float alpha){

        //Aqui estao sendo inicializados a Lista de candidatos e a Lista de Clusters
        listaDeCanditatos = new ListaDeNos();
        clusters = new ListaDeNos*[nClusters];
        for(int i = 0; i<nClusters; i++){
            clusters[i] = new ListaDeNos(); //Aqui cada um dos clusters � inicializado com uma lista de nos
        }

        //Aqui preenchemos a lista de candidatos inicial

        No* percorreNosDoGrafo = g->primeiro;
        while(percorreNosDoGrafo->getProx() != nullptr){
            //Aqui vai ser colocado como se fosse o teste pro cluster 0 pois fica mais facil do que mudar logo a frente
            listaDeCanditatos->adicionaNo(percorreNosDoGrafo, 0);
            percorreNosDoGrafo = percorreNosDoGrafo->getProx();
        }

        //Aqui � feita a organiza��o por peso e os n�s mais pesados s�o colocados um em cada cluster
        quickSortPorPesoDoNo(listaDeCanditatos, 0, listaDeCanditatos->getLength() - 1);

        for(int i = 0; i<nClusters; i++){
            No* noAtual = listaDeCanditatos->popNo(listaDeCanditatos->getLength() - 1);
            clusters[i]->adicionaNo(noAtual,i);
        }

        //A lista de candidatos sgora ser� alterada para ser por quantos pontos ela adiciona para a solu��o
        //Por isso cada item ter� nClusters copias de si mesmo (Cada um para o numero de pontos que ele adiciona em cada cluster)

        //Aqui salvamos quantos n�s tem na CL e fazemos as outras (nClustes - 1) copias de cada item da lista
        int nNosListaDeCandidatos = listaDeCanditatos->getLength();
        for (int i = 0; i<nClusters-1; i++){
            for(int j = 0; j<nNosListaDeCandidatos; j++){
                listaDeCanditatos->adicionaNo(listaDeCanditatos->getNo(j), i + 1);
            }
        }

        for(int i = 0; i<nCluster; i++){
            this->somaPossiveisPontosAosItems(clusters[i]->getNo(0), i);
        }

        //Agora temos uma CL com nClusters copias de cada No e vamos organizar por pontos que ela soma a solu��o
        this->organizaPorPontosNaSolucao();

        //Vamos colocar em cada um dos clusters a aresta de maior peso, para concluir o HWE (Heavyiest Weight Edge)
        for(int i = 0; i<nCluster; i++){
            for(int j = 0; j<listaDeCanditatos->getLength(); j++){
                if(listaDeCanditatos->getItem(j)->getClusterAtualSendoTestado() == i){
                    this->insereItemNaSolucaoPelosPontos(j);
                    break;
                }
            }
        }


        //Agora que o setup t� pronto, come�a o guloso randomizado
        int seedTime = time(0)
        srand(seedTime);

        //Primeiro Vamos preencher os clusters at� o minimo para ser uma solucao viavel
        while(listaDeCanditatos->getLength() > 0){
            int teto = static_cast<int>(listaDeCanditatos->getLength()*alpha) + 1;
            if(teto>listaDeCanditatos->getLength()){
                teto = listaDeCanditatos->getLength();
            }
            int index = this->getRandomNumber(0, teto);
            if(this->podeAdicionarONoAoCluster(listaDeCanditatos->getItem(index),U)){
                this->insereItemNaSolucaoPelosPontos(index);
            }
        }


    }

};


#endif // GULOSO_H_INCLUDED
