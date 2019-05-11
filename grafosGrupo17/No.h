#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include <iostream>
#include <list>

class No {

public:
    No();
    No(int id);
    No(int id,float peso);
    ~No();

    int getId();
    int diminuiGrauSaida();
    int diminuiGrauEntrada();
    int aumentaGrauSaida();
    int aumentaGrauEntrada();
    void setVisitado(bool v);
    bool getVisitado();
    float getPeso();

    std::list<No *> adjacentes; //Eu n�o to preenchendo com os adjacentes tamb�m, tem que fazer uma fun�ao que os implemente
private:
    int id;
    int grauDeSaida;
    int grauDeEntrada;
    bool visitado;
    float peso;

};

#endif // NO_H_INCLUDED
