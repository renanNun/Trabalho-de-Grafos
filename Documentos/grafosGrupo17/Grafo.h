#ifdef GRAFO_H
#define GRAFO_H
  #include <iostream>
  #include <fstream>
  #include <sstream>
  #include "No.h"

  using namespace std;

  class Grafo {

  public:

      Grafo();
      Grafo(std::string entrada, std::string saida);
      Grafo(std::string entrada, std::string saida, bool direcional);
      Grafo(std::string entrada, std::string saida, bool direcional, bool ponderadoAresta);
      Grafo(std::string entrada, std::string saida, bool direcional, bool ponderadoAresta, bool ponderadoNo);
      ~Grafo();


      void imprime();
      void imprime(std::string arquivo);

      void setNo(int id, float peso);
      void setNo(int id);
      void setAresta(int idOrigem, int idFim, float peso);
      void setAresta(int idOrigem, int idFim);

      No* getNo(int id);
      Aresta* getAresta(int idOrigem, int idFim);

      bool deleteAresta(int idOrigem, int idFim);
      bool deleteNo(int id);

      int getGrau();
      void buscaProfundidade(int id);
      void Caminhamentolargura(int id);

      int componentesConexas();
      int componentesFortConexas();

      void GerarComplementar(Grafo grafinho);

  private:

      No* listaNos;
      int ordem;
      int m;
      int grau;
      bool direcional;
      bool ponderadoNo;
      bool ponderadoAresta;

      void atualizaGrau(int grau);
      void leitura_arquivo(string arquivo);
      void auxConexo(No *v);
      void auxFortConexo(No *v);

  };

#endif //GRAFO_H
