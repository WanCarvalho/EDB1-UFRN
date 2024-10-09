#include <stdio.h>

void ord_insercao(int v[], int n)
{
    for (int i = 1; i < n; i++)
    {
        printf("Iteracao externa %d:\n", i);
        int chave = v[i];
        int j = i - 1;

        // Mostra o valor da chave que está sendo inserido
        printf("  Chave: %d\n", chave);

        while (j >= 0 && v[j] > chave)
        {
            v[j + 1] = v[j];
            j = j - 1;
            // Mostra o estado do vetor a cada movimentação
            printf("  Movendo %d para a posicao %d\n", v[j + 1], j + 1);
        }

        v[j + 1] = chave;

        // Mostra o estado do vetor após a inserção da chave
        printf("  Inserindo a chave %d na posicao %d\n", chave, j + 1);
        printf("  Estado atual do vetor: ");
        for (int k = 0; k < n; k++)
        {
            printf("%d ", v[k]);
        }
        printf("\n");
    }
}

int main()
{
    int vetor[] = {8, 5, 2, 10, 3};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    ord_insercao(vetor, n);

    // Imprime o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}