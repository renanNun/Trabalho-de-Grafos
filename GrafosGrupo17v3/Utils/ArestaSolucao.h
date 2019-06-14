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

    void setNo1(int id, float peso){

    }

    int getNo2(){
        return this->No2;
    }

    void setNo2(int id, float peso){

    }

    float getPeso(){
        return this->peso;
    }

    void setPeso(float peso){

    }

    bool getVistado(){
        return this->visitado;
    }

    void setVistado(bool x){

    }

    ArestaSolucao* getProx(){
        return this->prox;
    }


    void setProx(ArestaSolucao* p){

    }

};



#endif // ARESTASOLUCAO_H_INCLUDED
