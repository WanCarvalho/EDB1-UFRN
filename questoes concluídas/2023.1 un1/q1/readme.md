Nesta questão, implemente a seguinte função

```c++ 
int acharMenorOuIgual(int array[], int esquerda, int direita, int chave)
```

 Esta função recebe um array de inteiros e um inteiro ``chave`` e retorna um inteiro que indica o índice do primeiro elemento que seja menor ou igual ao valor de ``chave``, ou -1 caso não exista qualquer elemento menor do que ``chave`` no array de entrada. Os parâmetros ``esquerda`` e ``direita`` indicam os índices entre os quais está se realizando a busca.
 
 Sua função deverá obrigatoriamente ser recursiva e ter complexidade Θ(lg(n)).

Obs.1: Assuma que o array já está ordenado em ordem crescente e que ele não possui elementos repetidos.
Obs.2: Nesta questão, não podem ser usadas instruções para realizar repetição, como for, while e do-while. Ou seja, você deverá construir sua solução apenas com chamadas recursivas.
