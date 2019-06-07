#include "ListaDeNos.h"
#include <iostream>

using namespace std;

ListaDeNos::ListaDeNos()
{
    this->length = 0;
    this->primeiro = nullptr;
    this->ultimo = nullptr;
}

ListaDeNos::~ListaDeNos()
{
    //dtor
}
