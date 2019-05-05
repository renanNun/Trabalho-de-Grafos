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

               Aresta *a = new Aresta(no1,no2);
        }
    }
}

void LeituraArquivo::imprimirDados(std::string saida,Grafo& grafo){

}

