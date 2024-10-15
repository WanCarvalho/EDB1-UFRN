#include <stdio.h>

// Função para realizar a ordenação por inserção
void insertion_sort(int v[], int n) {
    // Loop principal começando do segundo elemento
    for (int i = 1; i < n; i++) {
        int chave = v[i]; // O elemento a ser inserido na parte ordenada
        int j = i - 1; // Índice do último elemento da parte ordenada

        printf("Iteracao %d, chave: %d\n", i, chave);

        // Move os elementos da parte ordenada que são maiores que a chave
        while (j >= 0 && v[j] > chave) {
            printf("  Movendo v[%d] = %d para v[%d]\n", j, v[j], j + 1);
            v[j + 1] = v[j]; // Move o elemento para frente
            j = j - 1; // Decrementa j
        }

        // Insere a chave na posição correta
        v[j + 1] = chave;
        printf("  Inserindo chave %d na posicao v[%d]\n", chave, j + 1);

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
    insertion_sort(vetor, n); 

    // Imprime o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
