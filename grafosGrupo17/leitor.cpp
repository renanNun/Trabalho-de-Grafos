#include "leitor.h"

using namespace std;

void LeituraArquivo::atribuirDados(std::string arquivo,Grafo& grafo){
    int a; //Primeiro ID
    int b; //Segundo ID
    int c; //Ordem/Número de Nós
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
}

void LeituraArquivo::imprimirDados(std::string saida,Grafo& grafo){
    std::ofstream file(saida);


    if(file.is_open()){
        file << "LISTA DE ADJACENCIA" << std::endl;
        std::list<No*> auxiliar = grafo.retornaListaNos();
        std::list<Aresta*> auxliar2 = grafo.retornaListaArestas();
        for(auto i = auxiliar.begin();i != auxiliar.end();i++){
            No *aux = *i;

            file << aux->getId() << " ----> ";

            for (auto j = aux->adjacentes.begin(); j != aux->adjacentes.end(); j++){
                No *aux2 = *j;
                file << "(" << aux2->getId() << ") -->";

            }
        }
        file << std::endl;
    } else {
        std::cout << "Impossível abrir arquivo de saida" << std::endl;
    }
}

