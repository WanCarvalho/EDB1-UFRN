#include <stdio.h>

void ordenacao_selecao(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        printf("Iteracao externa %d:\n", i + 1);

        int min_ind = i;

        for (int j = i + 1; j < n; j++)
        {
            printf("  Comparando v[%d] = %d e v[%d] = %d\n", j, v[j], min_ind, v[min_ind]);
            if (v[j] < v[min_ind])
            {
                min_ind = j;
            }
        }

        printf("  Trocando %d e %d\n", v[i], v[min_ind]);
        int temp = v[min_ind];
        v[min_ind] = v[i];
        v[i] = temp;

        // Imprime o array após cadcao externa
        printf("  Estado do array: ");
        for (int k = 0; k < n; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
    }
}

int main()
{
    int vetor[] = {8, 5, 2, 10, 3};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Array inicial: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    ordenacao_selecao(vetor, n);

    printf("Array ordenado: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}