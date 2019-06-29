using namespace std;

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <cctype>
#include <unistd.h> //#include <Windows.h>

#include "Grafo.h"
#include "Guloso.h"



class leitura
{
private:
    ifstream instanceFile;
    string output, totalOutput; //VARIÁVEIS DE EXTRAÇÃO DA STRING. O DOCUMENTO FICARÁ TODO ARMAZENADO EM totalOutput
    int numElements, numClusters; //NÚMERO DE NÓS, NÚMERO DE CLUSTERS A SEREM FORMADOS
    bool areClustersSameSized; //VARIÁVEL DETERMINA SE OS CLUSTERS DEVEM TER O MESMO TAMAMHO
    string strExtractedValue; //VARIÁVEL DE USO NA EXTRAÇÃO, NÃO ARMAZENA INFORMAÇÃO FINAL
    unsigned long i; //INDICE PARA DETERMINAR UM PONTO DO DOCUMENTO
    vector <int> clusterLowerLimit; //clusterLowerLimit e clusterUpperLimit são vetores paralelos, os elementos de mesmo indice correspondem ao mesmo cluster
    vector <int> clusterUpperLimit;
    vector <int> nodeWeight; //Vetor de peso dos nós
    vector <vector<int>> edgesWeightMatrix; //MATRIZ ONDE A COLUNA 0 É UMA PONTA DA ARESTA E A COLUNA 1 E A OUTRA PONTA
    vector <int> edgesWeightRow;
    vector <double> edgesWeight;
    char charCounter = 0;
    double clustersCapacity;


public:
    leitura();
    ~leitura();
    void atribuirDados(string instanceName, Grafo grafo, char instanceType);
};
