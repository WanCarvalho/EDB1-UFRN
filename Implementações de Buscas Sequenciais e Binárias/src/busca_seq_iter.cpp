#include "busca.h"

int busca(string entrada[], int tamanho, string chave)
{
    for (int i = 0; i < tamanho; i++)
    {
        if (chave == entrada[i])
        {
            return i;
        }
    }

    return -1;
}