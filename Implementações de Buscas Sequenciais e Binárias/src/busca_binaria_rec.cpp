#include "busca.h"

int busca_rec(string entrada[], int inicio, int fim, string chave)
{
    int meio = (inicio + fim) / 2;

    if(chave > entrada[meio]){
        inicio = meio + 1;
    } else if(chave < entrada[meio]){
        fim = meio - 1;
    } else {
        return meio;
    }
    return -1;
}

int busca(string entrada[], int tamanho, string chave)
{
    return busca_rec(entrada, 0, tamanho-1, chave);
}
