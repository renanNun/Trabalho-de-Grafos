#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

class Aresta{

private:
    int id; //O ID do Nó que uma aresta aponta
    float peso; //O Peso que uma aresta carrega
    Aresta* prox; //Ponteiro para a próxima Aresta
    //No* alvo;

public:
    Aresta();
    ~Aresta();

    int getId(); //Retorna o Id contido na aresta
    void setId(int id); //Insere o Id uma aresta
    Aresta* getProx();
    void setProx(Aresta *p);
    float getPeso();
    void setPeso(float peso);
 //   No* getNoAlvo();
//    void setNoAlvo(No* noAlvo);
};

#endif // ARESTA_H_INCLUDED
