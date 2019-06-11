#ifndef LEITURA_H_INCLUDED
#define LEITURA_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "../Grafo.h"

class Leitura{

private:

public:
    static void leituraArquivo(Grafo& g,std::string arquivo);

};

#endif // LEITURA_H_INCLUDED
