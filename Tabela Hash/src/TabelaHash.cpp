//
//  TabelaHash.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "../include/TabelaHash.h"
#include <string>
#include <iostream>

using namespace std;

Par<std::string, std::string> *REMOVIDO = (Par<std::string,std::string>*)(-1);

TabelaHash::TabelaHash()
{
    this->tamanho = TAMANHO_PADRAO;
    iniciar();
}

TabelaHash::TabelaHash(const std::size_t tamanho)
{
    this->tamanho = tamanho;
    iniciar();
}

void TabelaHash::iniciar()
{
    this->array = new Par<std::string, string>*[ this->getTamanho() ];
    this->quantidade = 0;
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        this->array[i] = nullptr;
    }
}

TabelaHash::~TabelaHash()
{
    for( std::size_t i = 0; i < this->getTamanho(); i++ )
    {
        Par<string, string>* entry = this->array[i];
        
        if( entry != nullptr && entry != REMOVIDO )
        {
            delete entry;
        }
    }
    delete [] array;
}

/**
 Este método deve inserir na tabela um novo Par com 'chave' e 'valor' recebidos como parâmetros. Neste caso, a quantidade de itens na tabela deve ser incrementada e retorna-se 'true'.
 Caso já exista um Par com atributo 'chave' == parâmetro 'chave', deve apenas atualizar o atributo 'valor' do Par. Neste caso, a quantidade de itens na tabela não é modificada e retorna-se 'true'.
 */
bool TabelaHash::inserir(const string chave, const string valor)
{
    auto hash = this->hash(chave);

    int indiceRemovido = -1;

    // Trata colisão usando sondagem linear: calcula o hash e testa a posição, caso não dê certo testa +1, +2, +3...
    for(int delta = 0; delta < this->getTamanho(); delta++){
        auto indice = (hash + delta) % this->getTamanho(); // Módulo tamanho para circular o array (evita chegar na ultima posição do array e não verificar as primeiras posições)

        auto elemento = this->array[indice];

        if(elemento == nullptr){
            
            // Decide se vai inserir numa posição nula ou marcada como REMOVIDO
            auto posicaoInsercao = indiceRemovido != -1 ? indiceRemovido : indice;
            
            // Insiro novo elemento
            auto novoELemento = new Par<string, string>(chave, valor);
            this->array[posicaoInsercao] = novoELemento;
            ++this->quantidade;

            return true;
        }
        else if(elemento == REMOVIDO){
            indiceRemovido = indice;
            continue;
        }
        else if(elemento->getChave() == chave){ //caso possua um elemento com mesma chave é feita a atualização do valor desse elemento
            this->array[indice]->setValor(valor);
            return true;
        }
    }

    return false;
}

/**
 Este método deve buscar na tabela um Par com 'chave', retornando o 'valor' associado. 
 */
std::string TabelaHash::buscar(const string chave)
{
    auto hash = this->hash(chave);

    for(int delta = 0; delta < this->getTamanho(); delta++){
        auto indice = (hash + delta) % this->getTamanho();

        auto elemento = this->array[indice];

        if(elemento == nullptr){
            return "NÃO ACHOU";
        }
        else if(elemento == REMOVIDO){
            continue;
        }
        else if(elemento->getChave() == chave){
            return elemento->getValor();
        }
    }

    return "NÃO ACHOU";
}

/**
 Este método deve remover da tabela o Par cujo atributo 'chave' == parâmetro 'chave'. Neste caso, a quantidade de itens na tabela deve ser dencrementada e retorna-se 'true'.
 Caso não exista um Par com atributo 'chave' == parâmetro 'chave',a quantidade de itens na tabela não é modificada e retorna-se 'false'.
 */
bool TabelaHash::remover(const string chave)
{
    auto hash = this->hash(chave);

    for(int delta = 0; delta < this->getTamanho(); delta++){
        auto indice = (hash + delta) % this->getTamanho();
        
        auto elemento = this->array[indice];

        if(elemento == nullptr){ //condição de parada, caso o elemento seja nulo quer dizer que o que está sendo procurado não está no array
            return false;
        }
        else if(elemento == REMOVIDO){ //condição para que caso ache um elemento com REMOVIDO continue a procurar nos elementos seguintes
            continue;
        }
        else if(elemento->getChave() == chave){
            delete this->array[indice];
            this->array[indice] = REMOVIDO;
            --this->quantidade;

            return true;
        }
    }

    return false;
}

float TabelaHash::fatorDeCarga()
{
    return (float)this->getQuantidade() / (float)this->getTamanho();
}

void TabelaHash::aumentar()
{
    std::size_t tamanhoNovo = 2*this->getTamanho() + 1;
    this->redimensionar(tamanhoNovo);
}

void TabelaHash::diminuir()
{
    std::size_t metadeTamanho = this->getTamanho()/2;
    std::size_t tamanhoNovo = metadeTamanho % 2 == 0 ? metadeTamanho + 1 : metadeTamanho;
    this->redimensionar(tamanhoNovo);
}

void TabelaHash::redimensionar(std::size_t tamanhoNovo)
{
    
}

std::size_t TabelaHash::preHash(const string chave)
{
    std::size_t x = 0;
    for(std::size_t i = 0; i < chave.size(); i++)
    {
        // Não mudar!
        // Coloquei propositalmente uma versão simples pra facilitar a criação de colisões nos testes!
        x += chave.at(i);
    }
    return x;
}

std::size_t TabelaHash::hash(const string chave)
{
    std::size_t hashValue = this->preHash(chave);
    return hashValue % this->getTamanho();
}

std::size_t TabelaHash::getTamanho()
{
    return this->tamanho;
}

void TabelaHash::setTamanho(std::size_t tamanhoNovo)
{
    this->tamanho = tamanhoNovo;
}

std::size_t TabelaHash::getQuantidade()
{
    return this->quantidade;
}

bool TabelaHash::vazia()
{
    return this->quantidade == 0;
}

bool TabelaHash::cheia()
{
    return this->quantidade == this->getTamanho();
}

bool TabelaHash::verificarDuplicatas()
{
    
    for(std::size_t i = 0; i < tamanho; ++i)
    {
        auto elementoI = this->array[i];
        if(elementoI != nullptr && elementoI != REMOVIDO)
        {
            for(std::size_t j = i+1; j < tamanho; ++j)
            {
                auto elementoJ = this->array[j];
                if(elementoJ != nullptr && elementoJ != REMOVIDO)
                {
                    if(elementoI->getChave() == elementoJ->getChave())
                    {
                        // Repetição de chaves
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

void TabelaHash::imprimir()
{
    for(std::size_t  i = 0; i < this->getTamanho(); i++)
    {
        Par<string, string> * entry = array[i];
        if( entry == REMOVIDO )
        {
            std::cout << i << ": REMOVIDO" << std::endl;
        }
        else if( entry != nullptr )
        {
            std::cout << i << ": " << entry->getChave() << ":" << entry->getValor() << std::endl;
        }
        else
        {
            std::cout << i << ": []" << std::endl;
        }
    }
}
