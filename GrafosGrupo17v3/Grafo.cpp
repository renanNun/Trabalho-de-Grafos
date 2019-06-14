#include "Grafo.h"
#include <iostream>

using namespace std;

Grafo::Grafo()
{

    this->numNos= 0;
    this->numArestas = 0;
    this->ehDirecionado = false;
    this->primeiro = NULL;

}

Grafo::~Grafo()
{
    No* p = this->primeiro;

    while(p != NULL)
    {
        No* q = p->getProx();
        delete p;
        p = q;
    }
}

No* Grafo::getPrimeiroNo()
{
    return this->primeiro;
}

int Grafo::getNumNos()
{
    return this->numNos;
}

int Grafo::getNumArestas()
{
    return this->numArestas;
}

bool Grafo::ehGrafoDirecionado()
{
    return this->ehDirecionado;
}

void Grafo::setDirecionado(bool x)
{
    this->ehDirecionado = x;
}

No* Grafo::buscaNo(int id)
{
    No* p = this->primeiro;

    while (p != NULL)
    {
        if(p->getId() == id)
        {
            return p;
        }
        p = p->getProx();
    }

    return p;
}

Aresta* Grafo::buscaAresta(int no1,int no2)
{

    No* p = buscaNo(no1);
    Aresta* aux = p->getAresta();

    if(p != NULL && aux != NULL)
    {

        while(aux != NULL)
        {
            if(aux->getId() == no2)
                return aux;
            aux = aux->getProx();
        }
    }

    return aux;
}

void Grafo::insereNo(int id, float peso)
{

    No *t = this->primeiro;

    if(!this->buscaNo(id))
    {

        No* p = new No();
        p->setId(id);

        if (t == NULL)
        {
            this->primeiro = p;
            p->setProx(NULL);
        }
        else
        {
            while (t->getProx() != NULL)
                t = t->getProx();
            t->setProx(p);
            p->setProx(NULL);
        }

        this->numNos++;
    }
}

void Grafo::removeNo(int no)
{
    No* p = this->primeiro;
    No* aux = NULL;

    if (p == NULL || this->buscaNo(no) == NULL)
    {
        std::cout<< "Nó inexistente!" << std::endl;
        exit(1);
    }
    else
    {

        while(p != NULL)
        {
            if (this->buscaAresta(p->getId(),no) != NULL)
            {
                p->removeAresta(no);
                this->numArestas--;
            }
            p = p->getProx();
        }

        p = this->primeiro;

        while(p != NULL)
        {
            if(p->getId() == no)
            {
                break;
            }
            aux = p;
            p = p->getProx();
        }

        if(aux == NULL)
        {
            this->primeiro = this->primeiro->getProx();
            delete p;
            this->numNos--;
        }
        else
        {
            aux->setProx(p->getProx());
            delete p;
            this->numNos--;
        }
    }
}

void Grafo::insereAresta(int no1,int no2,float peso)
{

    if(!this->ehGrafoDirecionado())
    {

        No* p = this->buscaNo(no1);
        No* t = this->buscaNo(no2);
        Aresta* a = new Aresta();
        Aresta* b = new Aresta();

        a->setPeso(peso);
        b->setPeso(peso);


        if(no1 == no2)
        {
            std::cout << "Não é possível criar self-loops!" << std::endl;
            exit(1);
        }
        else
        {
            if (this->buscaAresta(no1,no2) == NULL)
            {
                if (p != NULL && t != NULL)
                {
                    p->insereAresta(no2,a);
                    t->insereAresta(no1,b);
                    p->aumentaGrau();
                    t->aumentaGrau();
                    this->numArestas++;
                }
                else
                {
                    std::cout << "\nNós não encontrados!" << std::endl;
                }
            }
            else
            {
                std::cout<< "Aresta já existe entre os Nós!" << std::endl;
            }

            std::cout << "Não é possível criar aresta em um Grafo direcionado" << std::endl;
        }
    }
}

void Grafo::removeAresta(int no1,int no2)
{

    if(!this->ehGrafoDirecionado())
    {

        No* p = this->buscaNo(no1);
        No* t = this->buscaNo(no2);

        if (p == NULL && t == NULL)
        {
            std::cout<< "Nós inexistentes!" << std::endl;
        }
        else
        {
            if (this->buscaAresta(no1,no2) != NULL)
            {
                p->removeAresta(no2);
                t->removeAresta(no1);
            }
            this->numArestas--;
        }
    }
}

void Grafo::buscaEmProfundidade(int id)
{

    No* p = this->primeiro;
    int* vetorDeVisitados = new int [this->numNos];

    while(p != NULL)
    {
        vetorDeVisitados[this->buscaIndice(p->getId())] = 0;
        p = p->getProx();
    }

    p = this->primeiro;

    while (p != NULL)
    {
        if(vetorDeVisitados[this->buscaIndice(p->getId())] == 0)
        {
            this->auxBuscaProfundidade(p, vetorDeVisitados, id);
        }

        p = p->getProx();
    }

    delete [] vetorDeVisitados;
}

void Grafo::auxBuscaProfundidade(No* p,int *vetorDeVisitados,int id)
{
    Aresta* a = p->getAresta();

    vetorDeVisitados[this->buscaIndice(a->getId())] = 1;

    while(a != NULL)
    {
        if (a != NULL && vetorDeVisitados[this->buscaIndice(a->getId())] == 0)
            this->auxBuscaProfundidade(this->buscaNo(a->getId()),vetorDeVisitados,id);
        a = a->getProx();
    }
}

int Grafo::buscaIndice(int id)  // Passando um índice como Parâmetro, retorno o vértice Correspondente
{

    int *aux = new int[this->numNos];
    No* p = this->primeiro;

    for (int i = 0; i < this->numNos; i++)  //Preencho o Vetor Auxiliar com os IDs de cada Nó
    {
        aux[i] = p->getId();
        p = p->getProx();
    }

    for (int j = 0; j < this->numNos; j++)  //Procuro No vetor auxiliar o indice correspondente e retorno sua posição
    {
        if (aux[j] == id)
        {
            delete [] aux;
            return j;
        }
    }

    delete [] aux;
    return -1; // Caso não encontre o id.
}

void Grafo::buscaEmLargura()
{
    Fila fila;

    No* p = this->primeiro;

    int vetorDeVisitados[this->numNos];

    while(p!=NULL){
        vetorDeVisitados[this->buscaIndice(p->getId())] = 0;
        p = p->getProx();
    }

    vetorDeVisitados[this->primeiro->getId()] = 1;

    fila.enfilera(primeiro->getId());

    No* v;
    Aresta* a;

    while(!fila.vazia()){
        v = this->buscaNo(fila.desenfileira());
        a = v->getAresta();

        while(a != NULL){
            if(vetorDeVisitados[this->buscaIndice(a->getId())] == 0){
                vetorDeVisitados[this->buscaIndice(a->getId())] = 1;
                fila.enfilera(a->getId());
            }

            a = a->getProx();
        }
    }
}

void Grafo::quickSort(int lista[], int inicio, int fim){

    int i,j, pivo, aux;
    i = inicio;
    j = fim-1;
    pivo = lista[(inicio + fim)/2];

    while (i <= j){

        while (lista[i] > pivo &&  i < fim)
            i++;

        while (lista[j] < pivo && j > inicio)
            j--;

        if (i <= j){
            lista[i] = lista[j];
            lista[j] = aux;
            i++;
            j++;
        }
    }

    if (j > inicio)
        quickSort(lista,inicio,j+1);
    if (i < fim)
        quickSort(lista,i,fim);

}

/* Funções para implementação dos algoritmos */

Grafo* Grafo::copiaGrafo(){

    No* p = this->primeiro;
    Aresta* a;
    Grafo* grafoCopiado;

    while( p != nullptr){
        a = p->getAresta();
        grafoCopiado->insereNo(p->getId(),p->getPeso());

        while(a != nullptr){
            grafoCopiado->insereNo(a->getId(),buscaNo(a->getId())->getPeso());
            grafoCopiado->insereAresta(a->getId(),a->getId(),a->getPeso());
            a = a->getProx();
        }

        p = p->getProx();
    }

    return grafoCopiado;
}
