#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <vector>
#include <cctype>
#include <unistd.h> //#include <Windows.h>
#include "Grafo.h"
#include "Guloso.h"
#include "ListaDeNos.h"

using namespace std;

void leituraArquivo(string instanceName, char type);

int main()
{
    string instancePath = "Sparse82_01.txt";
    char type = 'a';//oi

    leituraArquivo(instancePath, type);
    cout << "Acho que funcionou, heim?!" << endl;
    return 0;
}

void leituraArquivo(string instanceName, char instanceType)
{
    ifstream instanceFile;
    string output, totalOutput; //VARIÁVEIS DE EXTRAÇÃO DA STRING. O DOCUMENTO FICARÁ TODO ARMAZENADO EM totalOutput
    int numElements, numClusters; //NÚMERO DE NÓS, NÚMERO DE CLUSTERS A SEREM FORMADOS
    bool areClustersSameSized; //VARIÁVEL DETERMINA SE OS CLUSTERS DEVEM TER O MESMO TAMAMHO
    string strExtractedValue; //VARIÁVEL DE USO NA EXTRAÇÃO, NÃO ARMAZENA INFORMAÇÃO FINAL
    unsigned long i; //INDICE PARA DETERMINAR UM PONTO DO DOCUMENTO
    vector <int> clusterLowerLimit; //clusterLowerLimit e clusterUpperLimit são vetores paralelos, os elementos de mesmo indice correspondem ao mesmo cluster
    vector <int> clusterUpperLimit;
    vector <float> nodeWeight; //Vetor de peso dos nós
    vector <vector<int>> edgesWeightElementsMatrix; //MATRIZ ONDE A COLUNA 0 É UMA PONTA DA ARESTA E A COLUNA 1 E A OUTRA PONTA
    vector <int> edgesWeightElementsRow;
    vector <double> edgesWeight;
    vector <int> edgeWeightMatrixRows;
    vector <vector<int>> edgeWeightMatrix;
    int charCounter = 0;
    double clustersCapacity;
    double instanceSeed;

    i = 0;
    if (instanceType == 'a' || instanceType == 'A')
    {
        cout << "O PRIMEIRO PORTÃO: O PORTÃO DE ABERTURA! KAI!" << endl;
        instanceFile.open("Sparse82_01.txt"); //SUBSTITUIR POR: instanceFile.open(instanceName);
        while (!instanceFile.eof())
        {
            getline(instanceFile, output);
            totalOutput += output + "\n";
        }
        instanceFile.close();

        cout << "O SEGUNDO PORTÃO: O PORTÃO DA CURA! KAI!" << endl;
        while (1)        //LOOP DE EXTRAÇÃO DA PRIMEIRA INFORMAÇÃO, O NÚMERO DE ELEMENTOS
        {
            if (totalOutput[i] == ' ')
            {
                i++;
                break;
            }

            strExtractedValue += totalOutput[i];
            i++;
        }
        numElements = stoi(strExtractedValue);
        strExtractedValue.clear();

        cout << "O TERCEIRO PORTÃO: O PORTÃO DA VIDA! KAI!" << endl;
        while (1)        //LOOP PARA EXTRAÇÃO DO NÚMERO DE CLUSTERS A SEREM FORMADOS
        {
            if (totalOutput[i] == ' ')
            {
                i++;
                break;
            }

            strExtractedValue += totalOutput[i];
            i++;
        }
        numClusters = stoi(strExtractedValue);
        strExtractedValue.clear();

        cout << "O QUARTO PORTÃO: O PORTÃO DA DOR! KAI!" << endl;
        while (1)        //LOOP PARA EXTRAÇÃO DO TIPO DE GRUPO ds ss (Clusters de mesmo tamanho) ou ds (Tamanhos diferentes)
        {
            if (totalOutput[i] == ' ')
            {
                i++;
                break;
            }

            strExtractedValue += totalOutput[i];
            i++;
        }
        areClustersSameSized = bool(!strExtractedValue.compare("ss")); //se for ss, true, se for ds, false
        strExtractedValue.clear();

        cout << "O QUINTO PORTÃO: O PORTÃO DO LIMITE! KAI!" << endl;
        for (int k = 0; k < numClusters; k++) //LOOP PARA EXTRAÇÃO DAS INFORMAÇÕES DE LIMITE DOS CLUSTERS
        {
            while (1)
            {
                if (totalOutput[i] == ' ')
                {
                    i++;
                    break;
                }
                strExtractedValue += totalOutput[i];
                i++;
            }
            clusterLowerLimit.push_back(stoi(strExtractedValue));
            strExtractedValue.clear();

            while (1)
            {
                if (totalOutput[i] == ' ')
                {
                    i++;
                    if (totalOutput[i] == 'W')
                        i += 2;
                    break;
                }

                strExtractedValue += totalOutput[i];
                i++;
            }
            clusterUpperLimit.push_back(stoi(strExtractedValue));
            strExtractedValue.clear();
        }

        cout << "O SEXTO PORTÃO: O PORTÃO DA VISÃO! KAI!" << endl;
        for (int l = 0; l < numElements; l++) //LOOP PARA EXTRAÇÃO DOS PESOS DOS NÓS
        {
            while (1)
            {
                if (totalOutput[i] == ' ' || totalOutput[i] == '\n')
                {
                    i++;
                    if (totalOutput[i] == '\n')
                        i++;
                    break;
                }

                strExtractedValue += totalOutput[i];
                i++;
            }
            nodeWeight.push_back(stoi(strExtractedValue));
            strExtractedValue.clear();
        }

        cout << "O SÉTIMO PORTÃO: O PORTÃO DA MARAVILHA! KAI!" << endl;
        while (isdigit(totalOutput[i]))
        {
            for (int m = 0; m < 3; m++)
            {
                if (m == 2)
                {
                    while (totalOutput[i] != '\n')
                    {
                        strExtractedValue += totalOutput[i];
                        i++;
                    }
                    edgesWeight.push_back(stod(strExtractedValue));
                    strExtractedValue.clear();
                    i++;
                    break;
                }
                while (1)
                {
                    if (totalOutput[i] == ' ')
                    {
                        i++;
                        break;
                    }
                    strExtractedValue += totalOutput[i];
                    i++;
                }
                edgesWeightElementsRow.push_back(stoi(strExtractedValue));
                strExtractedValue.clear();
            }
            edgesWeightElementsMatrix.push_back(edgesWeightElementsRow);
        }

        cout << "O OITAVO PORTÃO: O PORTÃO DA MORTEEEEE! KAI!" << endl;

        Grafo* grafo = new Grafo();
        grafo->setDirecionado(false);
        for (int n = 0; n < numElements; n++) //INSERÇÃO DE NÓS
        {
            grafo->insereNo(n, nodeWeight[n]);
        }

        for (int p = 0; p < numElements; p++) //INSERÇÃO DE ARESTAS
        {
            grafo->insereAresta(edgesWeightElementsMatrix[p][0], edgesWeightElementsMatrix[p][1], edgesWeight[p]);
        }

        float clusterLowerLimitArray[clusterLowerLimit.size()];
        float clusterUpperLimitArray[clusterUpperLimit.size()];
        cout << "Arrays criados com successo!" << endl;

        for (int r = 0; r < clusterLowerLimit.size(); r++)
        {
            clusterLowerLimitArray[r] = clusterLowerLimit[r];
            clusterUpperLimitArray[r] = clusterUpperLimit[r];

        } cout <<"chegou aqui" << endl;

        Guloso *guloso = new Guloso();
        cout << "Gula é pecado" << endl;

        ListaDeNos** lista = guloso->solucaoGuloso(numClusters, grafo, clusterLowerLimitArray, clusterUpperLimitArray);


    }
    else if (instanceType == 'd' || instanceType == 'D')
    {
        instanceFile.open(instanceName); //SUBSTITUIR POR: instanceFile.open(instanceName);
        while (!instanceFile.eof())
        {
            getline(instanceFile, output);
            totalOutput += output + "\n";
        }
        instanceFile.close();

        while (1)
        {
            i++;
            if (instanceName[i] == '_')
                charCounter++;
            if (charCounter == 2)
            {
                for (int a = i + 1; a <= (instanceName.length() - 1); a++)
                    strExtractedValue += instanceName[a];
                break;
            }
        }
        instanceSeed = stod(strExtractedValue);
        strExtractedValue.clear();
        i = 0;

        while (1)
        {
            if (totalOutput[i] == '\n')
            {
                i++;
                break;
            }

            strExtractedValue += totalOutput[i];
            i++;
        }
        numElements = stoi(strExtractedValue);
        strExtractedValue.clear();

        while (1)
        {
            if (totalOutput[i] == '\n')
            {
                i++;
                break;
            }

            strExtractedValue += totalOutput[i];
            i++;
        }
        numClusters = stoi(strExtractedValue);
        strExtractedValue.clear();

        while (1)
        {
            if (totalOutput[i] == '\n')
            {
                i++;
                break;
            }

            strExtractedValue += totalOutput[i];
            i++;
        }
        clustersCapacity = stod(strExtractedValue);
        strExtractedValue.clear();

        for (int b = 0; b < numElements; b++)
        {
            while (1)
            {
                if (totalOutput[i] == '\n')
                {
                    i++;
                    break;
                }
                strExtractedValue += totalOutput[i];
            }
            nodeWeight.push_back(stod(strExtractedValue));
            strExtractedValue.clear();
        }

        for (int c = 0; c < numElements; c++) //C++, HAHAHA! É que nem quando você tá assistindo um filme e falam o nome do filme no decorrer da trama.
        {
            edgeWeightMatrixRows.push_back(c);
        }
        edgeWeightMatrix.push_back(edgeWeightMatrixRows);
        for (int d = 0; d < numElements; d++)
        {
            for (int e = 1; e < (numElements - 1); e++)
            {
                while (1)
                {
                    if (totalOutput[i] == ' ')
                    {
                        i++;
                        break;
                    }
                    strExtractedValue += totalOutput[i];
                }
                edgeWeightMatrix[d].push_back(stoi(strExtractedValue));
                strExtractedValue.clear();
            }
        }
    }
    else
    {
        cout << "Tipo de instância inválido! =(" << endl;
    }
}
