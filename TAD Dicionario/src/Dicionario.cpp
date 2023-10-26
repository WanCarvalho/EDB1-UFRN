#include "Dicionario.h"
#include <iostream>

Dicionario::Dicionario(const int capacidade)
{
    this->quantidade = 0;
    this->capacidade = capacidade;
    this->elementos = new Par[capacidade];
}

Dicionario::~Dicionario()
{
    delete[] this->elementos;
}

bool Dicionario::inserir(const std::string &chave, const int &valor)
{

    int *existe = this->buscar(chave);

    if (this->capacidade != this->quantidade && existe == 0)
    {
        this->elementos[quantidade].chave = chave;
        this->elementos[quantidade].valor = valor;
        this->quantidade++;

        return true;
    }

    return false;
}

bool Dicionario::atualizar(const std::string &chave, const int &valor)
{
    // TO-DO
    return false;
}

bool Dicionario::remover(const std::string &chave)
{
    int *existe = this->buscar(chave);

    if (existe == 0)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < this->quantidade; i++)
        {
            if (this->elementos[i].chave == chave)
            {
                for (int j = i; j < this->quantidade; j++)
                {
                    this->elementos[j] = this->elementos[j + 1];
                }

                this->quantidade--;
                return true;
            }
        }
    }
}

int *Dicionario::buscar(const std::string &chave) const
{
    for (int i = 0; i < this->quantidade; i++)
    {
        if (this->elementos[i].chave == chave)
        {
            return &elementos[i].valor;
        }
    }

    return 0;
}

int Dicionario::tamanho() const
{
    return this->quantidade;
}

void Dicionario::imprimir() const
{
    std::cout << "{ ";
    for (int i = 0; i < quantidade; i++)
    {
        std::cout << "(" << elementos[i].chave << ": " << elementos[i].valor << ") ";
    }
    std::cout << "}\n";
}
