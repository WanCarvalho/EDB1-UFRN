#include "busca.h"

int busca(string entrada[], int tamanho, string chave)
{
    if (tamanho == 0)
    {
        return -1;
    }
    else
    {
        if (entrada[tamanho - 1] == chave)
        {
            return 1;
        }
        else
        {
            return busca(entrada, tamanho - 1, chave);
        }
    }
}