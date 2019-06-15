#ifndef KRUSKAL_H_INCLUDED
#define KRUSKAL_H_INCLUDED

#include "../Grafo.h"
#include "ListaDeArestas.h"

class Kruskal
{

private:
    int numComponentesConexas;

    int retornaNoDoVetor(int i,Grafo* g)
    {
        int* vetor = new int[g->getNumNos];
        No* p = g->getPrimeiroNo();

        for(int j = 0; j < g->getNumNos; j++)
        {

            vetor[j] = p->getId();
            p = p->getProx();

        }

        for (int j = 0; j < g->getNumNos; j++)
        {
            if(i == j)
            {
                int aux = vetor[i];
                delete [] vetor;
                return aux;
            }
        }

        delete [] vetor;
        return -1;

    }

    bool ListaSolucaoArestas(ListaDeArestas* lista, int id1,int id2)
    {

        ArestaSolucao* a = lista->getPrimeiro();

        while (a != nullptr)
        {
            if ((id1 == a->getNo1() || id1 == a->getNo2()) && (id2 == a->getNo1() || id2 == a->getNo2()))
                return true;
            a = a->getProx();
        }

        return false;

    }

    void ordenaArestas(ListaDeArestas* lista, int inicio,int final)
    {
        ArestaSolucao vetorAux[lista->getTamanho()];

        int cont = lista->getTamanho();

        ArestaSolucao* p = lista->getPrimeiro();

        for(int i = 0; i < cont; i++)
        {

            ArestaSolucao* aux = p;
            if(aux != nullptr)
                vetorAux[i] = *aux;
            p = p->getProx();

        }

        auxOrdenaListaDeArestas(vetorAux,inicio,final);

        ListaDeArestas* novaLista = new ListaDeArestas();

        for(int i = (cont-1); i >= 0; i--)
        {
            ArestaSolucao* aux = &vetorAux[i];
            novaLista->insereAresta(aux->getNo1(),aux->getNo2(),aux->getPeso());
            lista->removePrimeiraAresta();
        }

        ArestaSolucao* t = novaLista->getPrimeiro();

        ListaDeArestas* novaLista2 = new ListaDeArestas();

        while (t != nullptr)
        {
            novaLista2->insereAresta(t->getNo1(),t->getNo2(),t->getPeso());
            t = t->getProx();
        }

        ArestaSolucao* w = novaLista2->getPrimeiro();

        while(w != nullptr)
        {
            lista->insereAresta(w->getNo1(),w->getNo2(),w->getPeso());
            w =  w->getProx();
        }

        delete [] novaLista;
        delete [] novaLista2;

    };

    void auxOrdenaListaDeArestas(ArestaSolucao* vetor,int inicio, int fim)  //Mais um quick sort pra lista, dessa vez com arestas
    {
        int i, j;
        float pivo;
        ArestaSolucao aux;
        i = inicio;
        j = fim-1;

        pivo = vetor[(inicio + fim) / 2].getPeso();

        while(i <= j)
        {

            while(vetor[i].getPeso() < pivo && i < fim)
                i++;

            while(vetor[j].getPeso() > pivo && j > inicio)
                j--;

            if(i <= j)
            {
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                i++;
                j--;
            }
        }

        if(j > inicio)
            auxOrdenaListaDeArestas(vetor, inicio, j+1);

        if(i < fim)
            auxOrdenaListaDeArestas(vetor, i, fim);
    }

    int buscaArvore(int id, int* vetor,Grafo* g)
    {
        int arvore = id;
        int aux = g->buscaIndice(id) ;

        while(arvore != vetor[aux])
            arvore = vetor[aux];

        return arvore;

    };

    void juntaArvores(int id, int id2, int* vetor,Grafo* g)
    {

        int arv1 = vetor[g->buscaIndice(id)];
        int arv2 = vetor[g->buscaIndice(id2)];
        int aux,aux2;

        if(arv1 < arv2)
        {
            aux = arv1;
            aux2 =arv2;
        }
        else
        {
            aux = arv2;
            aux2 =arv1;
        }

        for(int i = 0; i < g->getNumNos() ; i++)
        {
            if(vetor[i] = aux2)
                vetor[i] = aux;
        }

    };

    Grafo* algoritmoKruskal(Grafo& g)
    {
        numComponentesConexas = 0;
        No* p = g.getPrimeiroNo();
        ArestaSolucao* a;

        Grafo* grafoSolucao = new Grafo;

        int* arvores = new int[g.getNumNos()];
        ListaDeArestas* lista = new ListaDeArestas();

        for(int i = 0; i < g.getNumNos(); i++)
        {
            arvores[i] = retornaNoDoVetor(i,g);
        }

        if(g.getNumArestas() != 0)
        {

            while(p != nullptr)
            {
                a = p->getAresta();

                while(a != nullptr)
                {
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
        while(t != nullptr && cont <(g.getNumNos()-1) && !lista->vazia())
        {

            int arvore1;
            int arvore2;

            arvore1= buscaArvore(t->getNo1(),arvores,g);
            arvore2= buscaArvore(t->getNo2(),arvores,g);

            if(arvore1 != arvore2)
            {
                this->juntaArvores(arvore1,arvore2,arvores,g);
                grafoSolucao->insereNo(t->getNo1(),t->getPeso());
                grafoSolucao->insereNo(t->getNo2(),t->getPeso());
                grafoSolucao->insereAresta(t->getNo1(),t->getNo2(),t->getPeso());
                cont++;
            }

            t = t->getProx();
            lista->removePrimeiraAresta();

        }

        p = g.getPrimeiroNo();

        while(p!= nullptr)
        {

            if(p->getGrau() == 0)
                grafoSolucao->insereNo(p->getId(),p->getPeso());
            p = p->getProx();

        }

        for(p = g.getPrimeiroNo(); p!= nullptr; p= p->getProx())
        {
            int id = p->getId();
            for(int i = 0; i < g.getNumNos(); i++)
            {
                if (id == arvores[i])
                {
                    numComponentesConexas = numComponentesConexas + 1;
                    break;
                }
            }
        }

        return grafoSolucao;
    }


public:
    Kruskal(Grafo &g)
    {
        this->algoritmoKruskal(g);
    };
    ~Kruskal()
    {
        //Destrutor
    };

};

#endif // KRUSKAL_H_INCLUDED
