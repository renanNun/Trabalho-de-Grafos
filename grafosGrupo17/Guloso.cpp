#include "Guloso.h"

using namespace std;

Guloso::Guloso(){

}

Guloso::~Guloso(){

}

void Guloso::preencheVector(std::vector<No *> &candidatos,Grafo *g){
    std::list<No*> auxiliar = g->retornaListaNos();
    for(auto i = auxiliar.begin();i != auxiliar.end(); i++){
        No *aux = *i;
        candidatos.push_back(aux);
    }
}
