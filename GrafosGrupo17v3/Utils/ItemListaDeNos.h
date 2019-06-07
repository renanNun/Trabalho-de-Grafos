#ifndef ITEMLISTADENOS_H
#define ITEMLISTADENOS_H


class ItemListaDeNos
{
private:
    No* item;
    ItemListaDeNos* anterior;
    ItemListaDeNos* proximo;
    int posicao;

public:
    ItemListaDeNos(ItemListaDeNos* ant, ItemListaDeNos* prox, No* no);
    ~ItemListaDeNos();
    int getPosicao();

};

#endif // ITEMLISTADENOS_H
