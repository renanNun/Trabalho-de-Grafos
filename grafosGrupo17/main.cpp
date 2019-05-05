#include <iostream>
#include <string>
#include "Grafo.h"
#include "leitor.h"

using namespace std;

int main(int argc, char* argv[])
{

    if (argc < 3 || argc > 6)
    {
        cout << "Argumentos passados invalidos";

        return -1;
    }

    LeituraArquivo *Leitura = new LeituraArquivo();
    Grafo *g;

     if (argc == 6) {
        g = new Grafo(stoi(argv[3]), stoi(argv[4]), stoi(argv[5]));
    } else if (argc == 5) {
        g = new Grafo(stoi(argv[3]), stoi(argv[4]));
    } else if (argc == 4) {
        g = new Grafo(stoi(argv[3]));
    } else {
        g = new Grafo();
    }

    Leitura->atribuirDados(argv[1],*g);
    Leitura->imprimirDados(argv[2],*g);




    return 0;
}
