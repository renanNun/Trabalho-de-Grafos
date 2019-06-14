#ifndef ARESTASOLUCAO_H_INCLUDED
#define ARESTASOLUCAO_H_INCLUDED

/*** CLASSE CRIADA PARA REPRESENTAR AS ARESTAS QUE ENTRÃO NA SOLUÇÃO DO ALGORITMO DE KRUSKAL, CONTENDO AS EXTREMIDADES
     DE CADA ARESTA, UM PONTEIRO PARA A PRÓXIMA ARESTA E UM BOOLEANDO INDICANDO A VISITA PELO ALGORITMO ***/

#include "../No.h"

class ArestaSolucao{

private:

    int No1,No2; //Extremidades da Aresta
    float peso;
    bool visitado;
    ArestaSolucao* prox;

public:

    ArestaSolucao(){ //Construdor
    };
    ~ArestaSolucao(){ //Destrutor
    };

    int getNo1(){
        return this->No1;
    }

    void setNo1(int id){
        this->No1 = id;
    }

    int getNo2(){
        return this->No2;
    }

    void setNo2(int id){
        this->No2 = id;
    }

    float getPeso(){
        return this->peso;
    }

    void setPeso(float peso){
        this->peso = peso;
    }

    bool getVistado(){
        return this->visitado;
    }

    void setVistado(bool x){
        this->visitado = x;
    }

    ArestaSolucao* getProx(){
        return this->prox;
    }


    void setProx(ArestaSolucao* p){
        this->prox = p;
    }

};



#endif // ARESTASOLUCAO_H_INCLUDED
