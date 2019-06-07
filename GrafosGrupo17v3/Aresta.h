#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

class Aresta{

private:
    int id;
    float peso;
    Aresta* prox;

public:
    Aresta();
    ~Aresta();

    int getId();
    void setId(int id);
    Aresta* getProx();
    void setProx(Aresta *p);
    float getPeso();
    void setPeso(float peso);
};

#endif // ARESTA_H_INCLUDED
