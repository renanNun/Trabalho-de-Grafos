#include "leitor.h"

using namespace std;

void LeituraArquivo::atribuirDados(std::string instanceName, Grafo &grafo, char instanceType)
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

        cout << "O SEGUNDO PORTÃO: O PORTÃO DA CURA! KAI!" << endl;
        usleep(1500000); //Sleep(1500); PARA WINDOWS
        while (1)        //LOOP DE EXTRAÇÃO DA PRIMEIRA INFORMAÇÃO, O NÚMERO DE ELEMENTOS
        {
            if (totalOutput[i] == ' ')
                break;

            strExtractedValue += totalOutput[i];
            i++;
        }
        numElements = stoi(strExtractedValue);
        strExtractedValue.clear();

        cout << "O TERCEIRO PORTÃO: O PORTÃO DA VIDA! KAI!" << endl;
        usleep(1500000); //Sleep(1500); PARA WINDOWS
        i++;
        while (1) //LOOP PARA EXTRAÇÃO DO NÚMERO DE CLUSTERS A SEREM FORMADOS
        {
            if (totalOutput[i] == ' ')
                break;

            strExtractedValue += totalOutput[i];
            i++;
        }
        numClusters = stoi(strExtractedValue);
        strExtractedValue.clear();

        cout << "O QUARTO PORTÃO: O PORTÃO DA DOR! KAI!" << endl;
        usleep(1500000); //Sleep(1500); PARA WINDOWS
        i++;
        while (1) //LOOP PARA EXTRAÇÃO DO TIPO DE GRUPO ds ss (Clusters de mesmo tamanho) ou ds (Tamanhos diferentes)
        {
            if (totalOutput[i] == ' ')
                break;

            strExtractedValue += totalOutput[i];
            i++;
        }
        areClustersSameSized = bool(!strExtractedValue.compare("ss")); //se for ss, true, se for ds, false
        strExtractedValue.clear();

        cout << "O QUINTO PORTÃO: O PORTÃO DO LIMITE! KAI!" << endl;
        usleep(1500000);                      //Sleep(1500); PARA WINDOWS
        for (int k = 0; k < numClusters; k++) //LOOP PARA EXTRAÇÃO DAS INFORMAÇÕES DE LIMITE DOS CLUSTERS
        {
            i++;
            while (1)
            {
                if (totalOutput[i] == ' ')
                    break;

                strExtractedValue += totalOutput[i];
                i++;
            }
            clusterLowerLimit.push_back(stoi(strExtractedValue));
            strExtractedValue.clear();

            i++;
            while (1)
            {
                if (totalOutput[i] == ' ')
                    break;

                strExtractedValue += totalOutput[i];
                i++;
            }
            clusterUpperLimit.push_back(stoi(strExtractedValue));
            strExtractedValue.clear();
        }

        cout << "O SEXTO PORTÃO: O PORTÃO DA VISÃO! KAI!" << endl;
        usleep(1500000); //Sleep(1500); PARA WINDOWS
        i += 2;
        for (int l = 0; l < numElements; l++) //LOOP PARA EXTRAÇÃO DOS PESOS DOS NÓS
        {
            i++;
            while (1)
            {
                if (totalOutput[i] == ' ' || totalOutput[i] == '\n')
                {
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

        while (i < totalOutput.length() - 1)
        {
            while (1)
            {
                if (totalOutput[i] == '\n')
                {
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
                edgesWeightRow.push_back(stod(strExtractedValue));
                strExtractedValue.clear();
            }
            edgesWeightMatrix.push_back(edgesWeightRow);
        }

        cout << "O OITAVO PORTÃO: O PORTÃO DA MORTEEEEE! KAI!" << endl;
        usleep(1500000); //Sleep(1500); PARA WINDOWS
        cout << "Quantidade de nós: " << numElements << endl;
        cout << "Quantidade de clusters a serem formados: " << numClusters << endl;
        if (areClustersSameSized)
            cout << "Todos os clusters devem ter o mesmo tamanho." << endl;
        else
            cout << "O clusters não precisam ter o mesmo tamanho." << endl;
        cout << "Peso de cada nó: " << endl;
        for (int i = 0; i < numElements; i++)
        {
            cout << "Peso nó " << i << ": ";
            cout << nodeWeight[i] << endl;
        }
        for (unsigned int y = 0; y < edgesWeightMatrix[y].size(); y++)
        {
            for (unsigned int z = 0; z < 3; z++)
            {
                cout << edgesWeightMatrix[y][z];
            }
            cout << endl;
        }

        instanceFile.close();
    }
    else if (instanceType == 'd' || instanceType == 'D')
    {
        cout << "O PRIMEIRO PORTÃO: O PORTÃO DE ABERTURA! KAI!" << endl;
        usleep(2100000);                  //Sleep(2100); PARA WINDOWS
        instanceFile.open("20_5_270001"); //SUBSTITUIR POR: instanceFile.open(instanceName);
        while (!instanceFile.eof())
        {
            getline(instanceFile, output);
            totalOutput += output + "\n";
        }

        cout << totalOutput << endl; //IMPRIME TODA A INSTANCIA, AGORA ARMAZENADA EM totalOutput

        while (1)
        {
            if (instanceName[i] == '_')
                charCounter++;
            if (charCounter == 2)
                for (int a = i + 1; a <= (instanceName.length() - 1); a++)
                    strExtractedValue += instanceName[a];
            break;
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
        instanceFile.close();
    }
    else
    {
        cout << "Tipo de instância inválido! =(" << endl;
    }

    /*
    int a; //Primeiro ID
    int b; //Segundo ID
    int c; //Ordem/N�mero de N�s
    float peso; //Peso
    std::ifstream file(arquivo);

    if(!file.is_open()){
        std:cout << "Erro na Leitura do Arquivo" << std::endl;
        exit(0);
    } else {

        file >> c;


        grafo.setOrdem(c);

        //Percorrendo cada linha do arquivo e adicionando os dados
        while(file >> a >> b){

                if(grafo.getNo(a) == nullptr){
                    No *no1 = new No(a);
                    grafo.setNo(a);
                }

                if(grafo.getNo(b) == nullptr){
                    No *no2 = new No(b);
                    grafo.setNo(b);
                }

               No *no1 = grafo.getNo(a);
               No *no2 = grafo.getNo(b);

               no1->aumentaGrauSaida();
               no2->aumentaGrauEntrada();

               no1->aumentaGrauEntrada();
               no2->aumentaGrauSaida();

               grafo.setAresta(no1->getId(),no2->getId());
        }
    }
    */
}

void LeituraArquivo::imprimirDados(std::string saida, Grafo &grafo)
{
    std::ofstream file(saida);

    if (file.is_open())
    {
        file << "LISTA DE ADJACENCIA" << std::endl;
        std::list<No *> auxiliar = grafo.retornaListaNos();
        std::list<Aresta *> auxliar2 = grafo.retornaListaArestas();
        for (auto i = auxiliar.begin(); i != auxiliar.end(); i++)
        {
            No *aux = *i;

            file << aux->getId() << " ----> ";

            for (auto j = aux->adjacentes.begin(); j != aux->adjacentes.end(); j++)
            {
                No *aux2 = *j;
                file << "(" << aux2->getId() << ") -->";
            }
        }
        file << std::endl;
    }
    else
    {
        std::cout << "Imposs�vel abrir arquivo de saida" << std::endl;
    }
}
