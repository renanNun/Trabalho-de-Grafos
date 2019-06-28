#ifndef GULOSO_H_INCLUDED
#define GULOSO_H_INCLUDED

#include <cstdlib>
#include <ctime>
#include <math.h>
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
        float pesoDaSolucao = 0;
        for(int i = 0; i<nClusters; i++){
            pesoDaSolucao = pesoDaSolucao + clusters[i]->getPeso();
        }
        if(pesoCL > pesoDaSolucao){
            std::cout << "Erro pois, o peso da solucao é " << pesoDaSolucao << " e o peso do grafo é " << pesoCL << std::endl;
            return 0.0;
        }
        float pontosTotais = 0;
        for(int i = 0; i<nClusters; i++){
            pontosTotais = pontosTotais + clusters[nClusters]->getPontuacaoAtual();
        }
        return pontosTotais;
    }

    ListaDeNos** clusters;
    ListaDeNos* listaDeCandidatos;
    ListaDeNos* listaDeCandidatosRetiradosTemporariamente;
    int pesoCL;
    float* resultados;
    float* alfaResultados;

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
        //Eu uso esse beta para pegar só essa porcentagem da parte superior da lista
        beta = 1-alpha;
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
        pesoCL = listaDeCandidatos->getPeso();

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
            //Aqui pegamos o teto para o beta
            int teto = static_cast<int>(listaDeCandidatos->getLength()*beta) + 1;
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
            int teto = static_cast<int>(listaDeCandidatos->getLength()*beta) + 1;
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
        geraSolucao(nClusters, g, L, U, 0);
        ListaDeNos** resultadoSolucaoGuloso = clusters;
        return resultadoSolucaoGuloso;
    }

    ListaDeNos** solucaoGulosoRandomizado(int nClusters, Grafo* g, int L[], int U[], int iteracoes, float alpha){
        geraSolucao(nClusters, g, L, U, 1);
        ListaDeNos** melhorSolucao = clusters;
        float pontuacaoMelhor = this->contaPontosDaSolucaoAtual(nClusters);
        for(int i = 1; i<iteracoes; i++}){
            geraSolucao(nClusters, g, L, U, alpha);
            if(this->contaPontosDaSolucaoAtual(nClusters)>pontuacaoMelhor){
                ListaDeNos** aux = melhorSolucao;
                melhorSolucao = clusters;
                delete [] aux;
            }
        }
        return melhorSolucao;
    }

    ListaDeNos** solucaoGulosoRandomizadoReativo(int nClusters, Grafo* g, int L[], int U[], int iteracoes, int iterEntreAtualizacoes, int alphas[], float fatorAmplificacao){
        //Aqui vao ser rodados nested loops principais, um para continuar rodando até todas as iteracoes concluirem e outro para o intervalo entre atualizacoes dos alphas

        //Aqui eu inicializo todos os valores que vou precisar e uso o guloso pra ter uma solução inicial, conforme dito em aula
        int iterAtual = 0;
        int nAlphas = sizeof(alphas)/sizeof(*alphas);
        float percentageAlphas[nAlphas];
        float geradorDeMedia[nAlphas][2];
        geraSolucao(nClusters, g, L, U, 1);
        ListaDeNos** melhorSolucao = clusters;
        float pontosMelhorSolucao = contaPontosDaSolucaoAtual(nClusters);

        //Aqui inicializo uma matriz de tamanho nAlphas por 2, onde o indice 1 guarda todos os pontos feitos pelo alpha e o 2 guarda quantas solucoes foram feitas
        //Isso é para gerar a media que será usado no calculo das porcentagens
        for(int i = 0; i<nAlphas; i++){
            geradorDeMedia[i][1] = 0.0;
            geradorDeMedia[i][2] = 0.0;
        }
        //Aqui todas as porcentagens são inicializadas com o mesmo valor
        for(int i = 0; i<nAlphas; i++){
            percentageAlphas[i] = 1.0/(float)nAlphas;
        }
        //Aqui comeca o primeiro loop que vai até o final da execucao do algoritmo
        while(iterAtual<iteracoes){
            float somaPorcentagemAtual = percentageAlphas[0];
            int i = 0;
            //Aqui o loop que dura entre atualizações
            for(int j = 0; j<iterEntreAtualizacoes;j++){
                //Caso tenham passado o numero de iterações de um alpha especifico ele soma um ao i para passar para o proximo alfa, retorna um na contagem desse loop
                //E em seguida roda essa iteração do loop novamente
                if(somaPorcentagemAtual>=(float)j/(float)iterEntreAtualizacoes){
                    i++;
                    somaPorcentagemAtual = somaPorcentagemAtual + percentageAlphas[i]
                    j = j - 1;
                    continue;
                //Caso não seja hora de ir pro proximo alpha, ele gera uma solução com o alfa atual, testa se é a nova melhor e adiciona os valores ao gerador de media
                } else {
                    geraSolucao(nClusters,f,L,U,alpha[i]);
                    float pontuacaoAtual = contaPontosDaSolucaoAtual(nClusters);
                    if(pontuacaoAtual>pontosMelhorSolucao){
                        ListaDeNos** aux = melhorSolucao;
                        melhorSolucao = clusters;
                        delete[]aux;
                        pontosMelhorSolucao = pontuacaoAtual;
                    }
                    geradorDeMedia[i][1] = geradorDeMedia[i][1] + pontuacaoAtual;
                    geradorDeMedia[i][2] = geradorDeMedia[i][2] + 1.0;
                }
                //Aqui ele indica que passou a iteração do while, para a contagem principal da iteração que estamos prosseguir de forma correta
                iterAtual++;
            }

            //Aqui ele calcula as novas porcentagens e prossegue com mais iterações
            float auxRecalculaPorcentagem[nAlphas];
            float somaDosQs = 0;
            for(int k = 0; k<nAlphas; k++){
                float aux = pontosMelhorSolucao/(geradorDeMedia[k][1]/geradorDeMedia[k][2]);
                auxRecalculaPorcentagem[k] = pow(aux, fatorAmplificacao);
                somaDosQs = somaDosQs + auxRecalculaPorcentagem[k];
            }
            for(int k = 0; k<nAlphas; k++){
                percentageAlphas[k] = auxRecalculaPorcentagem[k]/somaDosQs;
            }
        }

        return melhorSolucao;
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
