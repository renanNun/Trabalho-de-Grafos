#include "leitor.h"

using namespace std;

leitura()
{
}

~leitura()
{
}

void leitura::atribuirDados(std::string instanceName, Grafo *grafo, char instanceType)
{
    i = 0;
    if (instanceType == 'a' || instanceType == 'A')
    {
        cout << "O PRIMEIRO PORTÃO: O PORTÃO DE ABERTURA! KAI!" << endl;
        usleep(2100000);                      //Sleep(2100); PARA WINDOWS
        instanceFile.open("Sparse82_01.txt"); //SUBSTITUIR POR: instanceFile.open(instanceName);
        while (!instanceFile.eof())
        {
            getline(instanceFile, output);
            totalOutput += output + "\n";
        }
        instanceFile.close();

        cout << "O SEGUNDO PORTÃO: O PORTÃO DA CURA! KAI!" << endl;
        usleep(1500000); //Sleep(1500); PARA WINDOWS
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
        usleep(1500000); //Sleep(1500); PARA WINDOWS
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
        usleep(1500000); //Sleep(1500); PARA WINDOWS
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
        usleep(1500000);                      //Sleep(1500); PARA WINDOWS
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
        usleep(1500000);                      //Sleep(1500); PARA WINDOWS
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
        usleep(1500000); //Sleep(1500); PARA WINDOWS
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

        Grafo grafo;
        for (int n = 0; n < numElements; n++)
        {
            grafo.insereNo(n, nodeWeight[n]);
        }

        for (int p = 0; p < numElements; p++)
        {
            grafo.insereAresta(edgesWeightMatrix[p][0], edgesWeightMatrix[p][1], edgesWeight[p]);
        }

        int clusterLowerLimitArray[clusterLowerLimit.size()];
        int clusterUpperLimitArray[clusterUpperLimit.size()];

        for (int r = 0; r < clusterLowerLimit.size(); r++)
        {
            clusterLowerLimitArray[r] = clusterLowerLimit[r];
            clusterUpperLimitArray[r] = clusterUpperLimit[r];
        }

        Guloso guloso;
        guloso.solucaoGulosoRandomizadoReativo(sasuhsanumClusters, grafo, clusterLowerLimitArray, clusterUpperLimitArray, 0.8);
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
