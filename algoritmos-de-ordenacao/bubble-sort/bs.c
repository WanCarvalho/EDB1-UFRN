#include <stdio.h>

void ord_bolha(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("Iteracao externa %d:\n", i + 1);
        
        for (int j = 0; j < n - i - 1; j++) {
            printf("  Comparando v[%d] = %d e v[%d] = %d\n", j, v[j], j + 1, v[j + 1]);

            if (v[j] > v[j + 1]) {
                printf("  Trocando %d e %d\n", v[j], v[j + 1]);
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }

        // Imprime o array após cada iteração externa
        printf("  Estado do array: ");
        for (int k = 0; k < n; k++) {
            printf("%d ", v[k]);
        }
        printf("\n");
    }
}

int main() {
    int vetor[] = {8, 5, 2, 10, 3};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Array original: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    ord_bolha(vetor, n); 

    // Imprime o array ordenado
    printf("Array ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
