#include "Conjunto.h"
#include <iostream>

using namespace std;

Conjunto::Conjunto(int capacidade)
{
    this->capacidade = capacidade;
    this->elementos = new int[this->capacidade];
    this->quantidade = 0;
}

Conjunto::~Conjunto()
{
    // TO-DO
}

bool Conjunto::buscar(int elemento) const
{
    for (int i = 0; i < this->quantidade; i++)
    {
        if (this->elementos[i] == elemento)
        {
            return true;
        }
    }

    return false;
}

bool Conjunto::inserir(int elemento)
{
    if (this->capacidade == this->quantidade)
    {
        return false;
    }

    for (int i = 0; i < this->quantidade; i++)
    {
        if (this->elementos[i] == elemento)
        {
            return false;
        }
    }

    this->elementos[this->quantidade] = elemento;
    ++this->quantidade;

    return true;
}

bool Conjunto::remover(int elemento)
{
    for (int i = 0; i < this->quantidade; i++)
    {
        if (this->elementos[i] == elemento)
        {
            for (int j = 0; j < this->quantidade - 1; ++j)
            {
                this->elementos[i] = this->elementos[j+1];
            }
            --this->quantidade;
            return true;
        }
    }

    return false;
}

int Conjunto::tamanho() const
{
    return this->quantidade;
}

void Conjunto::imprimir() const
{
    std::cout << "{ ";
    for (int i = 0; i < quantidade; ++i)
    {
        std::cout << this->elementos[i] << " ";
    }
    std::cout << "}" << std::endl;
}
