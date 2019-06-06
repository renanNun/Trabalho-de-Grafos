#include "GulosoRandomizado.h"
#include "Guloso.h"

using namespace std;

Guloso::Guloso()
{

}

Guloso::~Guloso()
{

}

void Guloso::preencheVector(Grafo *g)
{
    std::list<No*> auxiliar = g->retornaListaNos();
    for(auto i = auxiliar.begin(); i != auxiliar.end(); i++)
    {
        No *aux = *i;
        this->candidatos.push_back(aux);
    }
}

void Guloso::ordenaCriterio(bool (*criterio)(No *no1, No *no2))
{
    std::sort(this->candidatos.begin(), this->candidatos.end(),criterio);
}

bool Guloso::ponderadoIgual(No *no1,No *no2)
{
    return no1->getPeso() < no2->getPeso();
}

void Guloso::atulizarVetor(No *escolhido)
{
    this->removeNoDoCandidato(escolhido);
    this->removeVizinhosDoCandidato(escolhido);
}

void Guloso::removeNoDoCandidato(No *no)
{
    candidatos.erase(std::remove(candidatos.begin(),candidatos.end(),no),candidatos.end());
}

void Guloso::removeVizinhosDoCandidato(No *no)
{
    for (auto i = no->adjacentes.begin(); i != no->adjacentes.end(); i++)
    {
        No *aux = *i;
        this->removeNoDoCandidato(aux);
    }
}

std::list<No *> Guloso::preencheSubConjVert(Grafo *g)
{
    this->preencheVector(g);
    this->ordenaCriterio( ponderadoIgual);

    while(candidatos.size() > 0)
    {
        No *aux = candidatos.at(0);
        this->subConjuntoDeVerticesPond.push_back(aux);
        this->atulizarVetor(aux);

    }

    return subConjuntoDeVerticesPond;

}
