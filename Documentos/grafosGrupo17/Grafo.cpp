#include <iostream>
#include "Grafo.h"

using namespace std;

/**
     * Construtor do TAD Grafo
     * Constroi um Grafo (podendo ser um digrafo, ponderado ou não)
     *
     *
     * encapsulamento: public
     */
Grafo::Grafo() {
    this->direcional = false;
    this->ponderadoAresta = false;
    this->ponderadoNo = false;
}

/**
     * Construtor do TAD Grafo
     * Constroi um Grafo (podendo ser um digrafo, ponderado ou não)
     * Parâmetro: entrada
     * Parâmetro: saida
     * encapsulamento: public
     */
Grafo::Grafo(string entrada, string saida) {
    this->direcional = false;
    this->ponderadoAresta = false;
    this->ponderadoNo = false;
    this->leitura_arquivo(entrada);
    this->imprime(saida);
}

/**
     * Construtor do TAD Grafo
     * Constroi um Grafo (podendo ser um digrafo, ponderado ou não)
     * Parâmetro: entrada
     * Parâmetro: saida
     * Parâmetro: direcional
     * encapsulamento: public
     */
Grafo::Grafo(string entrada, string saida, bool direcional) {
    this->direcional = direcional;
    this->ponderadoNo = false;
    this->ponderadoAresta = false;
    this->leitura_arquivo(entrada);
    this->imprime(saida);
}


/**
     * Construtor do TAD Grafo
     * Constroi um Grafo (podendo ser um digrafo, ponderado ou não)
     * Parâmetro: entrada
     * Parâmetro: saida
     * Parâmetro: direcional
     * Parâmetro: ponderadoAresta
     * encapsulamento: public
     */
Grafo::Grafo(string entrada, string saida, bool direcional, bool ponderadoAresta) {
    this->direcional = direcional;
    this->ponderadoNo = false;
    this->ponderadoAresta = ponderadoAresta;
    this->leitura_arquivo(entrada);
    this->imprime(saida);
}
/**
     * Construtor do TAD Grafo
     * Constroi um Grafo (podendo ser um digrafo, ponderado ou não)
     * Parâmetro: entrada
     * Parâmetro: saida
     * Parâmetro: direcional
     * Parâmetro: ponderadoAresta
     * Parâmetro: ponderadoNo
     * encapsulamento: public
     */
Grafo::Grafo(string entrada, string saida, bool direcional, bool ponderadoNo, bool ponderadoAresta) {
    this->direcional = direcional;
    this->ponderadoNo = ponderadoNo;
    this->ponderadoAresta = ponderadoAresta;
    this->leitura_arquivo(entrada);
    this->imprime(saida);
}

/**
     * Destrutor do TAD Grafo
     * encapsulamento: public
     */
Grafo::~Grafo() {
    delete this->listaNos;
}


void Grafo::imprime() {
    cout << "DADOS: " << endl;
    cout << "Grau: " << this->grau << endl;
    cout << "Ordem: " << this->ordem << endl;
    cout << "M: " << this->m << endl;

    cout << "LISTA DE ADJACENCIA: " << endl;
    for (No* n = this->listaNos; n != nullptr; n = n->getProx()) {

        cout << n->getId() << " ---> ";

        for (Aresta *a = n->getAresta(); a != nullptr; a = a->getProx()) {
            // Se for ponderado nas arestas é imprimido o peso
            if (ponderadoAresta) {
                if (a->getProx() != nullptr)
                    cout << a->getNoAdj() << " (" << a->getPeso() << ") ---> ";
                else
                    cout << a->getNoAdj() << " (" << a->getPeso() << ")";
            } else {
                if (a->getProx() != nullptr)
                    cout << a->getNoAdj() << " ---> ";
                else
                    cout << a->getNoAdj();
            }
        }

        cout << endl;

    }
}

/**
     * Este método imprime na tela grafo no formato de lista de adjacência:
     * Parâmetro: arquivo
     *
     * @param arquivo: Caminho do arquivo onde será gravada a impressão
     */
void Grafo::imprime(string arquivo) {

    ofstream myFile;

    myFile.open(arquivo, ios::out);

    if (myFile.is_open()) {

        myFile << "DADOS: " << endl;
        myFile << "Grau: " << this->grau << endl;
        myFile << "Ordem: " << this->ordem << endl;
        myFile << "M: " << this->m << endl;

        myFile << "LISTA DE ADJACENCIA: " << endl;
        for (No *n = this->listaNos; n != nullptr; n = n->getProx()) {

            myFile << n->getId() << " ---> ";

            for (Aresta *a = n->getAresta(); a != nullptr; a = a->getProx()) {
                // Se for ponderado nas arestas é imprimido o peso
                if (ponderadoAresta) {
                    if (a->getProx() != nullptr)
                        myFile << a->getNoAdj() << " (" << a->getPeso() << ") ---> ";
                    else
                        myFile << a->getNoAdj() << " (" << a->getPeso() << ")";
                } else {
                    if (a->getProx() != nullptr)
                        myFile << a->getNoAdj() << " ---> ";
                    else
                        myFile << a->getNoAdj();
                }
            }

            myFile << endl;

        }
    } else {
        cout << "Output file does not open." << endl;
    }
}

// *** GETTERS E SETTERS ***


void Grafo::setNo(int id, float peso) {

    No* no = new No(id, peso);

    No *list = this->listaNos;

    if (list == nullptr) {
        this->listaNos = no;
        this->ordem = 1; // Inicializa a ordem
        return;
    }

    // Percorrendo lista de nós até encontrar o ultimo
    for (list; list->getProx() != nullptr; list = list->getProx()) {
        if (list->getId() == no->getId()) {
            //cout << "No com mesmo id ja inserido" << endl;
            return;
        }
    }

    // Certificando se o nó já não foi inserido
    if (list->getId() != no->getId()) {
        list->setProx(no);
        this->ordem++; // Aumentando a ordem
    }

}

void Grafo::setNo(int id) {
    this->setNo(id, -1);
}

void Grafo::setAresta(int idOrigem, int idFim, float peso) {
    No * list = this->listaNos;
    No * origem = nullptr;
    No * fim = nullptr;

    // Evitando self loops
    if (idOrigem == idFim) {
        cout << "Nao e permitido self-loop" << endl;
        return;
    }

    // Percorrendo lista de nós até encontrar os nós que irão receber a aresta
    for (list; list != nullptr; list = list->getProx()) {

        if (list->getId() == idOrigem)
            origem = list;

        if (list->getId() == idFim)
            fim = list;

        // Evitando percorrer até o final desnecessáriamente
        if (origem != nullptr && fim != nullptr) break;

    }

    if (origem != nullptr && fim != nullptr) {
        Aresta *origem_fim = new Aresta(idFim, peso);

        if (origem->setAresta(origem_fim))
            fim->aumentaGrauEntrada();

    } else {
        cout << "No nao encontrado" << endl;
        return;
    }

    // Se o grafo não for direcional o nó de chegada também recebe uma aresta
    if (!this->direcional) {
        Aresta *fim_origem = new Aresta(idOrigem, peso);

        if (fim->setAresta(fim_origem))
            origem->aumentaGrauEntrada();

        // Atualizando o grau do grafo

        // Como ambos graus são atualizados para grafos não direcionais
        // Tanto faz verifivar o grau de saída ou entrada;
        int grauOrigem = origem->getGrauEntrada();
        int grauFim = fim->getGrauEntrada();

        if (grauOrigem > grauFim)
            this->atualizaGrau(grauOrigem);
        else
            this->atualizaGrau(grauFim);

    }

    // Atualizando grau do grafo

    int grauOrigem = origem->getGrauSaida();
    int grauFim = fim->getGrauEntrada();

    if (grauOrigem > grauFim)
        this->atualizaGrau(grauOrigem);
    else
        this->atualizaGrau(grauFim);

    this->m++;

}

void Grafo::setAresta(int idOrigem, int idFim) {
    // Verifica se o grafo é ponderado ou não da aresta para colocar um valour default
    if (!this->ponderadoAresta)
        this->setAresta(idOrigem, idFim, -1);
    else
        this->setAresta(idOrigem, idFim, 1);

}


No* Grafo::getNo(int id) {
    No *n;

    // Percorrendo lista de nós até encontrar o desejado
    for (n = this->listaNos; n != nullptr && n->getId() != id; n = n->getProx());

    return n;
}

Aresta* Grafo::getAresta(int idOrigem, int idFim) {
    No *n = this->getNo(idOrigem); // Encontrando nó de origem

    // Se encontrar nó inicia a busca se não retorna nullptr
    if (n != nullptr) {
        Aresta* a = n->getAresta();

        // Procurando aresta com nó passado, se encontrar o retorna, se não retorna nullptr
        for (a; a != nullptr && a->getNoAdj() != idFim; a = a->getProx());

        return a;

    } else {
        return nullptr;
    }

}

// Deleta só a ida, se for deletar a ida e a volta, favor chamar duas vezes
bool Grafo::deleteAresta(int idOrigem, int idFim){
    No * origem = this->getNo(idOrigem);
    if (origem == nullptr)return false;

    // Deletando a aresta da lista de adjacencia da origem
    if(origem != nullptr){
        Aresta* anterior = origem->getAresta();

        if(anterior->getProx() == nullptr){
            return false;
        }
        Aresta* del = anterior->getProx();
        for (anterior; del != nullptr && del->getNoAdj() != idFim; anterior = anterior->getProx()){
            del = del->getProx();
        }
        if(del == nullptr)return false;
        // A aresta vai ser tirada da lista de adjacencias
        anterior->setProx(del->getProx());
        delete *del;
    }
    // Atualizando os graus de tudo
    origem->diminuiGrauSaida();
    this->getNo(idFim)->diminuiGrauEntrada();
    this->atualizaGrau(origem->getGrauSaida());

}
bool Grafo::deleteNo(int id){
    No* del = this.getNo(id);
    if(del == nullptr)return false;
    No *list = this->listaNos;

    Aresta* percorredor = del->getAresta();
    while(percorredor!= nullptr){
        bool hasDeleted = this->deleteAresta(percorredor->getNoAdj(),id);
        if(!hasDeleted){
            cout << "Alguma inversa n foi deletada ou não existia" << endl;
        }
    }
    delete *del;
}


void Grafo::atualizaGrau(int grau) {
    if (grau > this->grau)
        this->grau = grau;
}

void Grafo::leitura_arquivo(string arquivo) {

    ifstream file; // Leitura de arquivo
    int n_nos = 0; // Numero de nós
    string line; // Auxilar para leitura de cada linha

    file.open(arquivo, ios::in); // Lendo arquivo de entrada

    if (file.is_open()) {

        getline(file, line); // Lendo a primeira linha com número de nós

        n_nos = stoi(line); // Convertendo de string para int

        //this->ordem = n_nos;

        // Percorrendo cada linha do arquivo e adicionando a variavel dados
        while (getline(file, line)) {

            istringstream str_stream(line);

            int origem, fim;
            float peso;

            // Verifica se é ponderado nas arestas
            if (this->ponderadoAresta) {

                // Lendo valores
                str_stream >> origem >> fim >> peso;

                // TODO implementar pensando que pode ser ponderado no nó

                // Inserindo nós da aresta, a verificaçao de existencia é feita pelo método
                this->setNo(origem);
                this->setNo(fim);
                this->setAresta(origem,fim,peso);

            } else {

                // Lendo valores
                str_stream >> origem >> fim;

                // TODO implementar pensando que pode ser ponderado no nó

                // Inserindo nós da aresta, a verificaçao de existencia é feita pelo método
                this->setNo(origem);
                this->setNo(fim);
                this->setAresta(origem,fim);

            }

        }

        file.close();

    } else {
        cout << "Input file does not open." << endl;
    }
}

//Arquivos Luan-> teste!!

int Grafo::getGrau(){
return this->grau;
}

void Grafo::buscaProfundidade(int id){


int v=grau;
//Criar um vetor de visitados
bool visitados[v];
//Marca vetor como falso
for(int i = 0; i < v; i++)
    visitados[i] = false;
//pilha de ids
stack <int> pilhadeIDs;

while(true)
{

    if(!visitados[v])
    {
        cout << "Visitando vertice " << id << " ...\n";
        visitados[id] = true; // marca como visitado
        pilhadeIDs.push(id); // insere "v" na pilha
    }

bool achou = false;
		list<int>::iterator it;

		// busca por um vizinho não visitado
		for(it = adj[id].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it])
			{
				achou = true;
				break;
			}
		}

	if(achou)
			id = *it; // atualiza o "id"
		else
		{
			// se todos os vizinhos estão visitados ou não existem vizinhos
			// remove da pilha
			pilhadeIDs.pop();
			// se a pilha ficar vazia, então terminou a busca
			if(pilhadeIDs.empty())
				break;
			// se chegou aqui, é porque pode pegar elemento do topo
			v = pilhadeIDs.top();
		}



}
}

void Grafo::Caminhamentolargura(int id)
{
	queue<int> filadeids;
	int v=getGrau();
	bool visitados[v]; // vetor de visitados

	for(int i = 0; i < v; i++)
		visitados[i] = false;

	cout << "Visitando vertice " << id << " ...\n";
	visitados[id] = true; // marca como visitado

	while(true)
	{
		list<int>::iterator it;
		for(it = adj[id].begin(); it != adj[id].end(); it++)
		{
			if(!visitados[*it])
			{
				cout << "Visitando vertice " << *it << " ...\n";
				visitados[*it] = true; // marca como visitado
				filadeids.push(*it); // insere na fila
			}
		}

		// verifica se a fila NÃO está vazia
		if(!filadeids.empty())
		{
			id= filadeids.front(); // obtém o primeiro elemento
			filadeids.pop(); // remove da fila
		}
		else
			break;
	}
}
