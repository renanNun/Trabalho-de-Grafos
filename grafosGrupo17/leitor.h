#ifndef LEITOR_H_INCLUDED
#define LEITOR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <unistd.h> //#include <Windows.h>

#include "Grafo.h"

class LeituraArquivo{

public:
    static void atribuirDados(std::string instanceName,Grafo& grafo, char instanceType);
    static void imprimirDados(std::string saida,Grafo& grafo);

private:
    ifstream instanceFile;
    string output, totalOutput; //VARIÁVEIS DE EXTRAÇÃO DA STRING. O DOCUMENTO FICARÁ TODO ARMAZENADO EM totalOutput
    int numElements, numClusters; //NÚMERO DE NÓS, NÚMERO DE CLUSTERS A SEREM FORMADOS
    bool areClustersSameSized; //VARIÁVEL DETERMINA SE OS CLUSTERS DEVEM TER O MESMO TAMAMHO
    string strExtractedValue; //VARIÁVEL DE USO NA EXTRAÇÃO, NÃO ARMAZENA INFORMAÇÃO FINAL
    unsigned int i; //INDICE PARA DETERMINAR EM PONTO DO DOCUMENTO
    vector <int> clusterLowerLimit; //clusterLowerLimit e clusterUpperLimit são vetores paralelos, os elementos de mesmo indice correspondem ao mesmo cluster
    vector <int> clusterUpperLimit;
    vector <int> nodeWeight; //Vetor de peso dos nós
    vector <vector<double>> edgesWeightMatrix; //MATRIZ ONDE A LINHA 0 SÃO OS NÓS, AS LINHAS SEGUINTES SÃO O PESO DA ARESTA ENTRE ELES E OUTRO NÓ
    vector <double> edgesWeightRow;

};

#endif // LEITOR_H_INCLUDED
