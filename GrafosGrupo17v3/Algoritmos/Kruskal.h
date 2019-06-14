#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

#include "../Grafo.h"
#include "ListaDeArestas.h"

class Kruskal{

private:
    int numComponentesConexas;

    int retornaNoDoVetor(int i,Grafo* g){
        int* vetor = new int[g->getNumNos];
        No* p = g->getPrimeiroNo();

        for(int j = 0; j < g->getNumNos; j++){

            vetor[j] = p->getId();
            p = p->getProx();

        }

        for (int j = 0; j < g->getNumNos; j++){
            if(i == j){
                int aux = vetor[i];
                delete [] vetor;
                return aux;
            }
        }

        delete [] vetor;
        return -1;

    }

    bool ListaSolucaoArestas(ListaDeArestas* lista, int id1,int id2){

        ArestaSolucao* a = lista->getPrimeiro();

        while (a != nullptr){
            if ((id1 == a->getNo1() || id1 == a->getNo2()) && (id2 == a->getNo1() || id2 == a->getNo2()))
                return true;
            a = a->getProx();
        }

        return false;

    }

    void ordenaArestas();

    int buscaArvore();

    void juntaArvores();

    Grafo* algoritmoKruskal(Grafo& g){
        numComponentesConexas = 0;
        No* p = g.getPrimeiroNo();
        ArestaSolucao* a;

        Grafo* grafoSolucao = new Grafo;

        int* arvores = new int[g.getNumNos()];
        ListaDeArestas* lista = new ListaDeArestas();

        for(int i = 0; i < g.getNumNos(); i++){
            arvores[i] = retornaNoDoVetor(i,g);
        }

        if(g.getNumArestas() != 0){

            while(p != nullptr){
                a = p->getAresta();

                while(a != nullptr){
                    if(!this->ListaSolucaoArestas(lista,p->getId(),a->getId()))
                        lista->insereAresta(p->getId(),a->getId(),a->getPeso());

                    a = a->getProx();
                }

                p = p->getProx();
            }

        }

        this->ordenaArestas();

        ArestaSolucao* t = lista->getPrimeiro();

        int cont = 0;
        while(t != nullptr && cont <(g.getNumNos()-1) && !lista->vazia()){

            int arvore1;
            int arvore2;

            arvore1= buscaArvore();
            arvore2= buscaArvore();

            if(arvore1 != arvore2){
                this->juntaArvores();
                grafoSolucao->insereNo(t->getNo1(),t->getPeso());
                grafoSolucao->insereNo(t->getNo2(),t->getPeso());
                grafoSolucao->insereAresta(t->getNo1(),t->getNo2(),t->getPeso());
                cont++;
            }

            t = t->getProx();
            lista->removePrimeiraAresta();

        }

        p = g.getPrimeiroNo();

        while(p!= nullptr){

            if(p->getGrau() == 0)
                grafoSolucao->insereNo(p->getId(),p->getPeso());
            p = p->getProx();

        }

        for(p = g.getPrimeiroNo(); p!= nullptr; p= p->getProx()){
            int id = p->getId();
            for(int i = 0; i < g.getNumNos();i++){
                if (id == arvores[i]){
                    numComponentesConexas = numComponentesConexas + 1;
                    break;
                }
            }
        }

        return grafoSolucao;
    }


public:
    Kruskal(Grafo &g){
        this->algoritmoKruskal(g);
    };
    ~Kruskal(){
        //Destrutor
    };

};

#endif // KRUSKAL_H_INCLUDED
