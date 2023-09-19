#include "busca.h"

int busca_rec(string entrada[], int primeira, int ultima, string chave)
{
    throw "ERRO: Busca binária recursiva ainda não foi implementada.";
}

int busca(string entrada[], int tamanho, string chave)
{
    return busca_rec(entrada, 0, tamanho-1, chave);
}