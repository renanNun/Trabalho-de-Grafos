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
        /**
        * Troca da posicao dos items para os QuickSorts.
        *
        * @param a  Item que vai para a posição de b
        * @param b  Item que vai para a posição de a
        * @author   Lucas Ribeiro
        */
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
        /**
        * Faz a parte da divisão da lista de nos para o QuickSort por Peso dos Nos.
        *
        * @param arr  Lista que será organizada
        * @param low  Indice onde comeca a organização
        * @param high Indice onde termina a organização
        * @author   Lucas Ribeiro
        */
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
        /**
        * Faz a parte da divisão da lista de nos para o QuickSort por pontos(Peso das arestas) somados a solução.
        *
        * @param arr  Lista que será organizada
        * @param low  Indice onde comeca a organização
        * @param high Indice onde termina a organização
        * @author   Lucas Ribeiro
        */
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
        if(listaDeCandidatos == nullptr){
            std::cout << "Lista de Candidatos vazia, portanto organizada" << std::endl;
        }
        else {
            quickSortPorPesoDoNo(listaDeCandidatos, 0, listaDeCandidatos->getLength()-1);
        }
    }

    void organizaPorPontosNaSolucao(){
        if(listaDeCandidatos == nullptr){
            std::cout << "Lista de Candidatos vazia, portanto organizada" << std::endl;
        }
        else {
            quickSortPorPontosNaSolucao(listaDeCandidatos, 0, listaDeCandidatos->getLength()-1);
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
            for(int i = 0; i<listaDeCandidatos->getLength(); i++){
                ItemListaDeNos* aux = listaDeCandidatos->getItem(i);
                if(aux->getItem()->getId() != arestaPercorredoraDaListaDeAdjacencias->getId()){
                    aux->addPontuacaoNoCluster(arestaPercorredoraDaListaDeAdjacencias->getPeso());
                }
            }
            for(int i = 0; i<listaDeCandidatosRetiradosTemporariamente->getLength(); i++){
                ItemListaDeNos* aux = listaDeCandidatosRetiradosTemporariamente->getItem(i);
                if(aux->getItem()->getId() != arestaPercorredoraDaListaDeAdjacencias->getId()){
                    aux->addPontuacaoNoCluster(arestaPercorredoraDaListaDeAdjacencias->getPeso());
                }
            }
        }
    }

    void insereItemNaSolucaoPelosPontos(int index, int nClusters){
        ItemListaDeNos* itemEscolhido = listaDeCandidatos->getItem(index);
        No* noEscolhido = itemEscolhido->getItem();
        int clusterEscolhido = itemEscolhido->getClusterAtualSendoTestado();
        clusters[clusterEscolhido]->addPontuacaoAtual(itemEscolhido->getPontuacaoNoCluster());
        this->limpaClones(itemeEscolhido,nClusters);
        clusters[clusterEscolhido]->adicionaNo(listaDeCandidatos->popNo(index));
        somaPossiveisPontosAosItems(noEscolhido, clusterEscolhido);
        this->organizaPorPontosNaSolucao();
    }

    void getRandomNumber(int lower, int upper){
        return rand()%(upper - lower) + lower;
    }

    bool oMinimoDosClustersFoiAtingido(float lowerBound[], int nClusters){
        for(int i = 0; i<nClusters; i++){
            if(nClusters[i]->getPontuacaoAtual()<lowerBound[i]){
                return false;
            }
        }
        return true;
    }

    void limpaClones(ItemListaDeNos* itemEscolhido, int nClusters){
        No* noEscolhido = itemEscolhido->getItem();
        int clusterEscolhido = itemEscolhido->getClusterAtualSendoTestado();
        for(int i = 0; i<nClusters; i++){
            if(i!=clusterEscolhido){
                ItemListaDeNos* percorredor = listaDeCandidatos->getItem(0);
                while((percorredor->getProximo()!=nullptr)&&
                    ((percorredor->getItem()->getId() != noEscolhido->getId())||
                     (percorredor->getClusterAtualSendoTestado()==clusterEscolhido))){
                    percorredor = percorredor->getProximo();
                }
                if(percorredor!=nullptr){
                    listaDeCandidatos->apagaItem(percorredor);
                }
                else{
                    percorredor = listaDeCandidatosRetiradosTemporariamente->getItem(0);
                    while((percorredor->getProximo()!=nullptr)&&
                        ((percorredor->getItem()->getId() != noEscolhido->getId())||
                        (percorredor->getClusterAtualSendoTestado()==clusterEscolhido)))
                    {
                        percorredor = percorredor->getProximo();
                    }
                    if(percorredor!=nullptr){
                        listaDeCandidatosRetiradosTemporariamente->apagaItem(percorredor);
                    }
                    else{
                        std::cout << "Algo deu errado no limpa clones" << std::endl;
                    }
                }

            }
        }

    }

    void limpaOpcoesDoCluster(int cluster){
        ItemListaDeNos* percorredor = listaDeCandidatos->getItem(0);
           while(percorredor->getProximo()!=nullptr){
               if(percorredor->getClusterAtualSendoTestado()==cluster){
                   listaDeCandidatosRetiradosTemporariamente->adicionaNo(percorredor->getItem(),percorredor->getClusterAtualSendoTestado());
                   listaDeCandidatosRetiradosTemporariamente->getUltimo()->setPontuacaoNoCluster(percorredor->getPontuacaoNoCluster());
                   percorredor = percorredor->getProximo();
                   listaDeCandidatos->apagaItem(percorredor->getAnterior());
               }
               else{
                   listaDeCandidatosRetiradosTemporariamente->adicionaNo(percorredor->getItem(),percorredor->getClusterAtualSendoTestado());
                   listaDeCandidatosRetiradosTemporariamente->getUltimo()->setPontuacaoNoCluster(percorredor->getPontuacaoNoCluster());
                   percorredor = percorredor->getProximo();
               }
           }
    }

    float contaPontosDaSolucaoAtual(int nClusters){
        float pontosTotais = 0;
        for(int i = 0; i<nClusters; i++){
            pontosTotais = pontosTotais + clusters[nClusters]->getPontuacaoAtual();
        }
        return pontosTotais;
    }

    ListaDeNos** clusters;
    ListaDeNos* listaDeCandidatos;
    ListaDeNos* listaDeCandidatosRetiradosTemporariamente;

public:
    Guloso(){
       //Construtor
    }
    ~Guloso(){
        //Destrutor
    }

    void geraSolucao(int nClusters, Grafo* g, int L[], int U[], float alpha){

        //Aqui estao sendo inicializados a Lista de candidatos e a Lista de Clusters
        listaDeCandidatos = new ListaDeNos();
        listaDeCandidatosRetiradosTemporariamente = new ListaDeNos();
        clusters = new ListaDeNos*[nClusters];
        for(int i = 0; i<nClusters; i++){
            clusters[i] = new ListaDeNos(); //Aqui cada um dos clusters é inicializado com uma lista de nos
        }

        //Aqui preenchemos a lista de candidatos inicial

        No* percorreNosDoGrafo = g->primeiro;
        while(percorreNosDoGrafo->getProx() != nullptr){
            //Aqui vai ser colocado como se fosse o teste pro cluster 0 pois fica mais facil do que mudar logo a frente
            listaDeCandidatos->adicionaNo(percorreNosDoGrafo, 0);
            percorreNosDoGrafo = percorreNosDoGrafo->getProx();
        }

        //Aqui é feita a organização por peso e os nós mais pesados são colocados um em cada cluster
        quickSortPorPesoDoNo(listaDeCandidatos, 0, listaDeCandidatos->getLength() - 1);

        for(int i = 0; i<nClusters; i++){
            No* noAtual = listaDeCandidatos->popNo(listaDeCandidatos->getLength() - 1);
            clusters[i]->adicionaNo(noAtual,i);
        }

        //A lista de candidatos sgora será alterada para ser por quantos pontos ela adiciona para a solução
        //Por isso cada item terá nClusters copias de si mesmo (Cada um para o numero de pontos que ele adiciona em cada cluster)

        //Aqui salvamos quantos nós tem na CL e fazemos as outras (nClustes - 1) copias de cada item da lista
        int nNosListaDeCandidatos = listaDeCandidatos->getLength();
        for (int i = 0; i<nClusters-1; i++){
            for(int j = 0; j<nNosListaDeCandidatos; j++){
                listaDeCandidatos->adicionaNo(listaDeCandidatos->getNo(j), i + 1);
            }
        }

        for(int i = 0; i<nCluster; i++){
            this->somaPossiveisPontosAosItems(clusters[i]->getNo(0), i);
        }

        //Agora temos uma CL com nClusters copias de cada No e vamos organizar por pontos que ela soma a solução
        this->organizaPorPontosNaSolucao();

        //Vamos colocar em cada um dos clusters a aresta de maior peso, para concluir o HWE (Heavyiest Weight Edge)
        for(int i = 0; i<nCluster; i++){
            for(int j = 0; j<listaDeCandidatos->getLength(); j++){
                if(listaDeCandidatos->getItem(j)->getClusterAtualSendoTestado() == i){
                    this->insereItemNaSolucaoPelosPontos(j,nClusters);
                    break;
                }
            }
        }


        //Agora que o setup tá pronto, começa o guloso randomizado
        int seedTime = time(0)
        srand(seedTime);

        //Primeiro Vamos preencher os clusters até o minimo para ser uma solucao viavel
        while(listaDeCandidatos->getLength() > 0&&!this->oMinimoDosClustersFoiAtingido(L ,nClusters)){
            //Aqui pegamos o teto para o alpha
            int teto = static_cast<int>(listaDeCandidatos->getLength()*alpha) + 1;
            if(teto>listaDeCandidatos->getLength()){
                teto = listaDeCandidatos->getLength();
            }
            int index = this->getRandomNumber(0, teto);

            ItemListaDeNos* itemEscolhido = listaDeCandidatos->getItem(index);
            int clusterEscolhido = itemEscolhido->getClusterAtualSendoTestado();

            //Aqui testamos se esse no faz o cluster passar do peso minimo
            if(itemEscolhido->getItem()->getPeso() + clusters[clusterEscolhido]->getPeso() > L[clusterEscolhido]){

                //Se ele faz o cluster passar do minimo e ficar abaixo do maximo, limpamos as outras opcoes do cluster temporariamente da CL
                if(itemEscolhido->getItem()->getPeso() + clusters[clusterEscolhido]->getPeso() <U[clusterEscolhido]){
                    this->insereItemNaSolucaoPelosPontos(index,nClusters);
                    this->limpaOpcoesDoCluster(clusterEscolhido);
                }

                //Se o no fizer o cluster estourar o maximo tambem, nao pode estar na solucao
                else{
                    listaDeCandidatos->apagaItem(itemEscolhido);
                }
            }

            //E aqui, se ele nao faz o cluster ultrapassar limite algum ele só é adicionado a solucao
            else{
                this->insereItemNaSolucaoPelosPontos(index,nClusters);
            }
        }

        //Agora como todos já atingiram o minimo vamos preencher os clusters com o resto dos nos
        listaDeCandidatos = listaDeCandidatosRetiradosTemporariamente;
        organizaPorPontosNaSolucao();

        while(listaDeCandidatos->getLength() > 0){
            int teto = static_cast<int>(listaDeCandidatos->getLength()*alpha) + 1;
            if(teto>listaDeCandidatos->getLength()){
                teto = listaDeCandidatos->getLength();
            }
            int index = this->getRandomNumber(0, teto);

            ItemListaDeNos* itemEscolhido = listaDeCandidatos->getItem(index);
            int clusterEscolhido = itemEscolhido->getClusterAtualSendoTestado();

            if(clusters[clusterEscolhido]->getPontuacaoAtual()+itemEscolhido->getItem()->getPeso() > U[clusterEscolhido]){
                listaDeCandidatos->apagaItem(itemEscolhido);
            }
            else{
                insereItemNaSolucaoPelosPontos(index,nClusters);
            }

    }

    ListaDeNos** solucaoGuloso(int nClusters, Grafo* g, int L[], int U[]){
        geraSolucao(nClusters, f, L, U, 0);
        ListaDeNos** resultadoSolucaoGuloso = clusters;
        return resultadoSolucaoGuloso;
    }

    ListaDeNos** solucaoGulosoRandomizado(int nClusters, Grafo* g, int L[], int U[], int iteracoes){
        return;
    }

    ListaDeNos** solucaoGulosoRandomizadoReativo(int nClusters, Grafo* g, int L[], int U[], int iteracoes){
        return;
    }

    float contaPontosDeUmaSolucao(ListaDeNos** solucaoASerContada, int nClusters){
        float pontosTotais = 0;
        for(int i = 0; i<nClusters;i++){
            pontosTotais = pontosTotais + solucaoASerContada[nClusters]->getPontuacaoAtual();
        }
        return pontosTotais;
    }

};


#endif // GULOSO_H_INCLUDED
