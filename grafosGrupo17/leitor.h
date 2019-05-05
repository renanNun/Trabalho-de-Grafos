#ifndef LEITOR_H_INCLUDED
#define LEITOR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "Grafo.h"

class LeituraArquivo{

public:
    static void atribuirDados(std::string arquivo,Grafo& grafo);
    static void imprimirDados(std::string saida,Grafo& grafo);

};

#endif // LEITOR_H_INCLUDED
