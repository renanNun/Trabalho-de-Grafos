#include "Guloso.h"

using namespace std;

Guloso::Guloso(){

}

Guloso::~Guloso(){

}

void Guloso::preencheVector(Grafo *g){
    std::list<No*> auxiliar = g->retornaListaNos();
    for(auto i = auxiliar.begin();i != auxiliar.end(); i++){
        No *aux = *i;
        this->candidatos.push_back(aux);
    }
}

void Guloso::ordenaCriterio(float chave){
    bool crit = this->ponderadoIgual(this->candidatos,chave);
    std::sort(this->candidatos.begin(), this->candidatos.end(), criterio);
}

bool Guloso::ponderadoIgual(No* no1,float chave){
    return no1->getPeso() == chave;
}

void Guloso::atulizarVetor(No *escolhido){
    this->removeNoDoCandidato(escolhido);
    this->removeVizinhosDoCandidato(escolhido);
}

void Guloso::removeNoDoCandidato(No *no){
    candidatos.erase(std::erase(candidatos.begin(),candidatos.end(),no),candidatos.end());
}

void Guloso::removeVizinhosDoCandidato(No *no){
    for (auto i = no->adjacentes.begin(); i != no->adjacentes.end();i++){
        No *aux = *i;
        this->removeNoDoCandidato(aux);
    }
}

std::list<No *> Guloso::preencheSubConjVert(Grafo *g, float crit){
    this->preencheVector(g);
    this->ordenaCriterio(crit);

}
