#include <stdio.h>

// Função para realizar a ordenação por seleção
void selection_sort(int v[], int n)
{
    // Loop principal para cada posição do vetor
    for (int i = 0; i < n - 1; i++)
    {
        int min_ind = i; // Assume que o menor valor está na posição i
        printf("Iteracao %d, indice inicial: %d, valor: %d\n", i, i, v[i]);

        // Loop para encontrar o menor elemento no restante do vetor
        for (int j = i + 1; j < n; j++)
        {
            printf("  Comparando v[%d] = %d com v[%d] = %d\n", j, v[j], min_ind, v[min_ind]);
            // Se o elemento atual for menor que o elemento mínimo encontrado
            if (v[j] < v[min_ind])
            {
                min_ind = j; // Atualiza o índice do menor elemento
                printf("  Novo minimo encontrado em v[%d] = %d\n", min_ind, v[min_ind]);
            }
        }

        // Troca o elemento mínimo encontrado com o elemento na posição i
        printf("  Trocando v[%d] = %d com v[%d] = %d\n", i, v[i], min_ind, v[min_ind]);
        int temp = v[min_ind];
        v[min_ind] = v[i];
        v[i] = temp;

        // Imprime o estado atual do vetor
        printf("  Estado atual do vetor: ");
        for (int k = 0; k < n; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
    }
}

int main() {
    // Array de inteiros a ser ordenado
    int vetor[] = {8, 5, 2, 10, 3};
    int n = sizeof(vetor) / sizeof(vetor[0]); // Calcula o tamanho do vetor

    // Imprime o array original
    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Chama a função de ordenação
    selection_sort(vetor, n); 

    // Imprime o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
