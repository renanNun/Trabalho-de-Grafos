#ifndef MENU_H
#define MENU_H

// Menu que roda as opções e verifica a validade delas
void Grafo::menu()
{
    char Menu;
    while (true)
    {
        cout << endl;
        cout << "# Menu principal #" << endl;
        cout << "[1] - Adicionar aresta" << endl;
        cout << "[2] - Deletar aresta" << endl;
        cout << "[3] - Adicionar vertice" << endl;
        cout << "[4] - Deletar vertice" << endl;
        cout << "[5] - Buscar vertice" << endl;
        cout << "[6] - Vertices adjacentes" << endl;
        cout << "[7] - Limpar Grafo" << endl;
        cout << "[8] - Informaçoes do Grafo" << endl;
        cout << "[9] - Guloso" << endl;
        cout << "[0] - Imprimir Grafo" << endl;
        cout << "[q] - sair" << endl;
        cout << endl;
        do
        {
            cout << "Digite uma opcao do menu: ";
            cin >> menu;
        }
        while (((menu < '0' || menu > '9') && (menu < 'a' || menu > 'z')) && menu != 'q');

        if (menu == 'q')
        {
            cout << "Saindo" << endl;
            return;
        }
        menuSelecionado(menu);
    }
}


void Grafo::menuSelecionado(char a)
{
    switch (a)
    {

    case '1':
    {
        int no1, no2;
        float peso;

        cout << "Adicionando Aresta" << endl;
        cout << "Digite os Nos e em seguida o peso" << endl;
        cin >> no1>> no2 >> peso;
        insereAresta(int no1, int no2, float peso);

        break;
    }
    case '2':
    {
        int no1, no2;

        cout << "Removendo Aresta" << endl;
        cout << "Digite os Nos que deseja remover a aresta " << endl;
        cin >> no1>> no2;
        removeAresta(int no1,int no2);
        break;

    }
    case '3':
    {
        int id;
        float peso;

        cout << "Adicionando Vertice" << endl;
        cout << "Digite o id do No e em seguida o peso" << endl;
        cin >> no1>> peso;
        insereNo(int id, float peso);
        break;
    }

    case '4':
    {
        int id;


        cout << "Removendo Vertice" << endl;
        cout << "Digite o id do No " << endl;
        cin >> no1;
        removeNo(int no);
        break;
    }
    }
case '5':
    {
        int id;
        cout<< "Buscando Nó";
        cout <<"Digite o id do  nó:";
        cin>>id;
        buscaIndice(int id);
        break;
    }
case '6':
    {


    }
case '7':
    {


    }
case '8':
    {
        cout>>"Numero de nos:"
            getNumNos();
        cout>> "numero de arestas:"
            getNumArestas();
        cout>>"é direcionado ?"
            cin<<ehGrafoDirecionado();
        break;


    }
case '9':
    {
        char a;
        cout>> "qual tipo de guloso? [a] Guloso comum \n [b] Guloso randomizado \n [c] Guloso reativo"
        cin<<a;

        switch(a)
        {
        case 'a':
        {}

        case'b':
        {}

        case 'c':
        {}
        default:
            cout>> "Essa opção não existe";
            break;
        }


    }
case '0':
    {}

default:
    break;
}
}


#endif // MENU_H
