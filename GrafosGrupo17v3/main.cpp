#include <iostream>
#include "leitura.h"
#include "Grafo.h"
#include <string>

int main()
{
    using namespace std;
    Grafo grafo();
    leitura leitor;
    string instance = "Sparse82_01.txt";

    leitor.atribuirDados(instance, &grafo, 'a');
    cout << "Acho que funcionou, heim?!" << endl;
    return 0;
}
