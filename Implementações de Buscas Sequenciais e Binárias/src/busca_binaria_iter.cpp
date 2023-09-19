#include "busca.h"
#include <iostream>

using namespace std;

int busca(string entrada[], int tamanho, string chave)
{
    int inicio = 0, meio, fim = tamanho - 1;

    while (inicio <= fim)
    {
        meio = (inicio + fim) / 2;

        if (chave < entrada[meio])
        {
            fim = meio - 1;
        }
        else if (chave > entrada[meio])
        {
            fim = meio + 1;
        }
        else
        {
            return meio;
        }
    }
    return -1;
}