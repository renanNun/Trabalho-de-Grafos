#include "Grafo.h"

/**
     * Construtor do TAD Grafo
     * Constroi um Grafo
     *
     *
     * encapsulamento: public
     */
Grafo::Grafo()
{
    this->ordem = 0;
    this->grau = 0;
    this->direcional = false;
    this->ponderadoNos = false;
    this->ponderadoArestas = false;
}

/**
     * Construtor do TAD Grafo
     * Constroi um Grafo
     * Par�metro: direcional
     *
     * encapsulamento: public
     */
Grafo::Grafo(bool direcional)
{
    this->ordem = 0;
    this->grau = 0;
    this->direcional = direcional;
    this->ponderadoNos = false;
    this->ponderadoArestas = false;
}

/**
     * Construtor do TAD Grafo
     * Constroi um Grafo
     * Par�metro: direcional
     * Par�metro: ponderadoAresta
     * encapsulamento: public
     */
Grafo::Grafo(bool direcional,bool ponderadoAresta)
{
    this->ordem = 0;
    this->grau = 0;
    this->direcional = direcional;
    this->ponderadoNos = false;
    this->ponderadoArestas = ponderadoAresta;
}

/**
     * Construtor do TAD Grafo
     * Constroi um Grafo
     * Par�metro: direcional
     * Par�metro: ponderadoAresta
     * Par�metro: ponderadoNo
     * encapsulamento: public
     */
Grafo::Grafo(bool direcional,bool ponderadoAresta,bool ponderadoNo)
{
    this->ordem = 0;
    this->grau = 0;
    this->direcional = direcional;
    this->ponderadoNos = ponderadoNo;
    this->ponderadoArestas = ponderadoAresta;
}

/**
     * Destrutor do TAD Grafo
     * Destroi um Grafo
     *
     *
     * encapsulamento: public
     */
Grafo::~Grafo()
{

}

/**
     * Insere a Ordem de um Grafo
     * Ordem de um Grafo
     * Par�metro: ordem
     *
     * encapsulamento: public
     */
void Grafo::setOrdem(int ordem)
{
    this->ordem = ordem;
}

/**
     * Retorna a Ordem de um Grafo
     * Ordem de um Grafo
     *
     *
     * encapsulamento: public
     */
int Grafo::getOrdem()
{
    return this->ordem;
}

/**
     * Busca o Indice de um No e retorna o mesmo
     * Par�metro: id
     * Caso n�o encontre o No correspondente ao id, retorna null
     *
     * encapsulamento: public
     */
No* Grafo::getNo(int id)
{
    for (auto i = this->nos.begin(); i != this->nos.end(); i++)
    {
        No *aux = *i;
        if(aux->getId() == id)
        {
            return aux;
        }
    }
    //Caso tenha percorrido toda a lista e n�o encontrado o No correspondente
    return nullptr;
}

/**
     * Adiciona um N� no grafo
     * Par�metro: id
     *
     *
     * encapsulamento: public
     */
void Grafo::setNo(int id){
    if(getNo(id) != nullptr){
        this->setOrdem(this->getOrdem()+1);
        No *no = new No(id);
        this->nos.push_back(no);
    }
    else {
        std::cout<< "Erro: N� j� existe no Grafo" << std::endl;
    }
}

void Grafo::setAresta(int id1,int id2){
     for (auto i = this->arestas.begin(); i != this->arestas.end(); i++){
        Aresta *aux = *i;
        if(aux->getNo1()->getId() == id1 && aux->getNo2()->getId() == id2 ||
           aux->getNo1()->getId() == id2 && aux->getNo2()->getId() == id1){
            std::cout << "Erro: j� existe aresta que ligue ambos os n�s";
            exit(0);
        }
     }

     Aresta *a = new Aresta(this->getNo(id1),this->getNo(id2));
     this->arestas.push_back(a);
}


/**
     * Deleta uma Aresta do Grafo
     * Par�metro: id
     *
     *
     * encapsulamento: public
     */
bool Grafo::deleteAresta(int id)
{
    for (auto i = this->arestas.begin(); i != this->arestas.end();)
    {
        Aresta *aresta = *i;
        if (aresta->getNo1()->getId() == id || aresta->getNo2()->getId() == id)
        {
            i = this->arestas.erase(i);
        }
        else
        {
            i++;
        }
    }
}

/**
     * Deleta um No Grafo
     * Par�metro: id
     *
     *
     * encapsulamento: public
     */
bool Grafo::deleteNo(int id)
{

    if(this->getNo(id) == nullptr)
        return false;

    this->setOrdem(this->getOrdem() - 1);
    for (auto i = this->nos.begin(); i != this->nos.end();)
    {
        No *aux = *i;
        if(aux->getId() == id)
        {
            i = this->nos.erase(i);
        }
        else
        {

            for (auto j = this->nos.begin(); j != this->nos.end(); j++)
            {
                No *auxAdj = *j;
                if(auxAdj->getId() == id)
                    j = this->nos.erase(j);
            }
            i++;
        }
        this->deleteAresta(id);
    }

}

/**
     * Atualiza o Grau do Grafo
     * Par�metro: grau
     *
     *
     * encapsulamento: public
     */
void Grafo::setGrau(int grau)
{
    if (grau > this->grau)
        this->grau = grau;
}

/**
     * Retorna o Grau do Grafo
     * Par�metro: grau
     *
     *
     * encapsulamento: public
     */
int Grafo::getGrau()
{
    return this->grau;
}

/**
     * Busca em Profundidade em um Grafo
     * Par�metro: id
     *
     *
     * encapsulamento: public
     */
void Grafo::buscaProfundidade(int id)
{

    No *no = this->getNo(id);
    no->setVisitado(true);
    for (auto i = no->adjacentes.begin(); i != no->adjacentes.end(); i++)
    {
        No *aux = *i;
        if(aux->getVisitado())
        {
            this->buscaProfundidade(aux->getId());
        }
    }


}

#include <queue>

/**
     * Caminho em largura de um Grafo
     * Par�metro: id
     *
     *
     * encapsulamento: public
     */
void Grafo::caminhamentoLargura(int id)
{
    std::queue<No> filaIds;

    for(auto i = this->nos.begin(); i != this->nos.end(); i++)
    {
        No *aux = *i;
        aux->setVisitado(false);
    }

    //std::cout << "Visitando Vertice " << id << std::endl;
    No *no = this->getNo(id);
    no->setVisitado(true);

    while(true)
    {

        for (auto i = no->adjacentes.begin(); i != no->adjacentes.end(); i++)
        {
            No *aux = *i;
            //std::cout << "Visitando Vertice " << aux->getId() << std::endl;
            aux->setVisitado(true);
            filaIds.push(*aux);
        }

        //Verifico se a fila n�o est� vazia
        if(!filaIds.empty())
        {
            id = filaIds.front().getId(); //obt�m o primeiro elemento
            filaIds.pop();//remove da fila
        }
        else
            break;


    }


}

/**
     * Quantidade de componentes Conexas
     *
     *
     *
     * encapsulamento: public
     */
int Grafo::quantCompenetesConexas()
{
    int cont = 0;
    for (auto i = this->nos.begin(); i!= this->nos.end(); i++)
    {
        No *aux = *i;
        aux->setVisitado(false);
    }
    for (auto i = this->nos.begin(); i!= this->nos.end(); i++)
    {
        No *aux = *i;
        if(aux->getVisitado() == true)
        {
            cont ++;
            this->buscaProfundidade(aux->getId());
        }
    }
    return cont;
}

/**
     * Quantidade de componentes Fortemente Conexas
     *
     *
     *
     * encapsulamento: public
     */
int Grafo::quantComponentesFortConexas()
{
    int cont = 0;

    if(this->direcional == false)
    {
        std::cout << "N�o � poss�vel ser fortemente Conexo" << std::endl;
        exit(0);
    }
    for (auto i = this->nos.begin(); i!= this->nos.end(); i++)
    {
        No *aux = *i;
        aux->setVisitado(false);
    }


}


/**
     * Gerar Complementar de um Grafo
     *
     *
     *
     * encapsulamento: public
     */
void Grafo::gerarComplementar()
{
    if(this->getGrau() > 0)
    {
        std::cout << "Este grafo j� possui n�s, apague os n�s ou crie um novo objeto instanciado sem n�s." << std::endl;
    }
    else
    {

        int idsNos[this->getOrdem()][this->getOrdem()]; //matriz que ser� uma c�pia da lista encadeada, algo como uma pseudo-lista
        int comprimentos[this->getOrdem()]; //Comprimento aqui � a quantidade de n�s adjacentes que cada elemento da lista tem
        int comprimentosComplementares[this->getOrdem()]; //Quantos n�s adjacentes cada n� do grafo complementar ter�
        int complementares[this->getOrdem()][this->getOrdem()];  //matriz que ser� como uma pseudo-lista, mas referente ao grafo complementar
        bool estaNaLista = false;

        int j, m, n, p, s, t, u = 0;


        /*
        -Inicializa a matriz que � uma pseudolista de adjac�ncia com todos os valores iguais a -1
        -Inicializa o vetor "comprimentos" que conter� quantos n�s s�o adjacentes com todos os valores iguais a 0
        -Inicializa o vetor "comprimentosComplementares" que conter� quantos n�s adjacentes cada n� do Grafo Complementar ter�
        */

        for (int q = 0; q <= this->getOrdem(); q++)
        {
            for (int r = 0; r <= this->getOrdem(); r++)
            {
                complementares[q][r] = -1;
                comprimentos[q] = 0;
                comprimentosComplementares[q] = 0;
            }
        }

        /*
        -Faz uma copia da lista de adjac�ncia para dentro da pseudo-lista, que � uma matriz
        Aqui, a primeira coluna (i,0) representa os n�s da lista, e os seus adjac�nctes est�o contidos
        em suas respectivas linhas.
        Por exemplo: para um n� 4, que tem como adjacentes 1 e 3, temos na lista a representa��o:
        4->3->7
        J� na matriz, temos:
        Colunas: 0 1 2
                 4 3 7
        */

        j = 0;

        for (auto n = this->nos.begin(); n != this->nos.end(); n++)
        {
            for(int i = 0; i < this->nos.size();i++){
            No *aux = *n;
            idsNos[i][j] = aux->getId();

            for (auto a = this->arestas.begin(); a != this->arestas.end(); a++ , j++)
            {
                Aresta *aux = *a;
                int index = 0;
                if (this->arestas.front() != nullptr)
                {
                    idsNos[i][j] = aux->getNo2()->getId();
                    comprimentos[i]++;
                }
                index++;
            }
            }
        }

        /*
        -Aqui copiamos a primeira coluna, que cont�m os n�s, para a matriz de n�s complementares
        */
        for (m = 0; m <= this->getOrdem()-1; m++)
        {
            complementares[m][0] = idsNos[m][0];
        }



        /*
        Aqui percorremos a matriz formada no bloco de c�digo anterior verificando se
        os elementos da primeira coluna [u][0], que s�o os n�s do grafo, ent�o entre
        os adjacentes de cada n�. Caso estejam o loop d� um break e passa para o pr�ximo.
        Em caso do n� n�o ser achado entre os adjacentes, ele � adicionado nas colunas de
        adjacencia da matriz complementares.
        */

        for (int u = 0; u <= this->getOrdem()-1; u++)
        {
            for (n = 0; n <= this->getOrdem()-1; n++)
            {
                estaNaLista = false;

                for (int p = 1; p <= comprimentos[n]; p++)
                {
                    estaNaLista = (idsNos[n][0] == idsNos[n][p]);
                    if (estaNaLista)
                        break;
                }

                if (!estaNaLista)
                {
                    complementares[u][t] = idsNos[n][0];
                    t++;
                    comprimentosComplementares[u]++;
                }
            }
        }



        /*
        Por fim, a matriz de complementares � transformada novamente em uma lista de adjacencia,
        agora de um grafo complementar ao passado por parametro.
        */
        for (int k = complementares[0][0]; k <= complementares[this->getOrdem()-1][0]; k++)
        {
            this->setNo(k);
            for (int l = complementares[k][1]; l <= comprimentosComplementares[k]; l++)
            {
                this->setAresta(complementares[k][0], complementares[k][l]);
            }
        }

        std::cout << "Grafo complementar criado com sucesso." << std::endl;
    }

}

No Grafo::retornaListaNos (){
    No *aux = *this->nos.begin();
    return *aux;
}

Aresta Grafo::retornaListaArestas (){
    Aresta *aux = *this->arestas.begin();
    return *aux;
}
