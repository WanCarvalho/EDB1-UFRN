#include "Conjunto.h"
#include <iostream>

Conjunto::Conjunto(int capacidade)
{
    this->quantidade = 0;
    this->capacidade = capacidade;
    this->elementos = new int[capacidade];
}

Conjunto::~Conjunto()
{
    delete[] this->elementos;
}

bool Conjunto::buscar(int elemento) const
{
    for(int i = 0; i < this->quantidade; i++){
        if(this->elementos[i] == elemento){
            return true;
        }
    }

    return false;
}

bool Conjunto::inserir(int elemento)
{
    if(this->quantidade == this->capacidade){
        return false;
    } else {

        bool jaExiste = this->buscar(elemento);

        if(jaExiste){
            return false;
        } else {
            this->elementos[this->quantidade] = elemento;
            this->quantidade++;

            return true;
        }

    }
    
}

bool Conjunto::remover(int elemento)
{
    bool jaExiste = this->buscar(elemento);

    if(!jaExiste){
        return false;
    } else {

        for(int i = 0; i < this->quantidade; i++){
            if(this->elementos[i] == elemento){
                for(int j = i; j < this->quantidade; j++){
                    this->elementos[j] = this->elementos[j+1];
                }

                this->quantidade--;
                return true;
            }
            
        }
    }

}

int Conjunto::tamanho() const
{
    return this->quantidade;
}

void Conjunto::imprimir() const
{
    std::cout << "{ ";
    for(int i = 0; i < quantidade; ++i)
    {
        std::cout << this->elementos[i] << " ";
    }
    std::cout << "}" << std::endl;
}


Conjunto Conjunto::intersecao(Conjunto c){
    int novoTamanho = this->tamanho() <= c.tamanho() ? this->tamanho() : c.tamanho();
    
    Conjunto intersecao(novoTamanho);

    for(int i = 0; i < this->quantidade; i++){
        bool existe = c.buscar(this->elementos[i]);
        if(existe){
            intersecao.inserir(this->elementos[i]);
        }
    }

    return intersecao;
}