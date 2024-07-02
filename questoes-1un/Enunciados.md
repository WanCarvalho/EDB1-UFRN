# IMD0029 - Estruturas de Dados 1 - 2023.2 - Unidade 1 

<div style="page-break-after: always;"/>

## Questão 1
Dado um número natural N, implemente uma função recursiva que retorne o maior dos dígitos de N. Por exemplo, se N for igual a 2173, sua função deve retornar 7, visto que 7 é maior do que os dígitos 2, 1 e 3.

Nesta questão, implemente a seguinte função: 

```c++ 
int maiorDigito(int N)
```

A função deve ser implementada no arquivo ``q1/main_q1.cpp``.

Obs.: Nesta questão, não podem ser usadas instruções para realizar repetição, como ``for``, ``while`` e ``do-while``. Ou seja, você deverá construir sua solução apenas com chamadas recursivas.

## Questão 2 - (Não implementada)
Implemente o algoritmo de ordenação Merge Sort de modo que os elementos do array de entrada estejam ordenados em ordem decrescente. Sua implementação deverá seguir a assinatura:

``` c++
void mergeSort(int array[], int esquerda, int direita)
```

A função deve ser implementada no arquivo ``q2/main_q2.cpp``. Note que há nesse arquivo uma função auxiliar chamada ``estaDecrescente`` que eu criei para poder testar a ordenação. Você não pode alterar essa função auxiliar.

## Questão 3
Dado um inteiro ``soma`` e um array ``A`` contendo apenas inteiros positivos, o problema Soma-2 é definido como o problema de determinar se existem dois índices i e j tais que ``A[i] + A[j] == soma`` e os índices i e j são diferentes um do outro.  

Nesta questão, implemente uma solução para o problema Soma-2 com complexidade Θ(n*lg(n)). Sua função deverá ter a seguinte assinatura:


``` c++
bool  soma2(int array[], int tamanho, int soma)
```

Essa função retorna ``true`` ou ``false``, de acordo com a especificação anterior. A função deve ser implementada no arquivo ``q3/main_q3.cpp``. 

## Questão 4

Nesta questão, implemente uma função que calcula de forma recursiva a divisão entre dois números inteiros e positivos. Sua função deverá seguir a assinatura: 

```c++
int divide(int a, int b)
```

Obs.: Não precisa tratar os casos de divisão por zero.

## Questão 5

Sequências bitônicas inversas são aquelas que possuem duas sequências, sendo uma sequência inicial decrescente, seguida de uma sequência crescente.
Ou seja, os elementos de uma sequência bitônica inversa obedecem a seguinte relação: 

A0 > A1 > ... > Ai-1 > Ai < Ai+1 < ... < An
 
Considere que um vetor bitônico-inverso é um vetor de inteiros sem repetições cujos elementos representam uma sequência bitônica inversa.
Nesta questão, implemente a função findBase que recebe como entrada um vetor bitônico-inverso e retorna o índice da base, isto é, do elemento Ai, que representa a transição da sequencia decrescente para a sequencia crescente.
Sua solução deverá ser recursiva ter complexidade Θ (lg(n)).

## Questão 6

Um anagrama é um jogo de palavras em que uma palavra é construída a partir do rearranjo das letras de uma outra palavra utilizando cada letra da palavra original exatamente uma vez, isto é, não mais nem menos do que isso.
Por exemplo: Iracema é um anagrama da palavra America.
Implemente a função isAnagram que recebe duas strings e retorna verdadeiro se estas palavras são anagramas e falso caso contrário.

Obs.: Nesta questão, pode assumir que as strings de entrada terão todos os caracteres em caixa alta (letras maiúsculas).
Dicas: Para acessar o i-ésimo caractere de uma string, basta usar o operador [ ] (ex.: char ci = str[i]).
Para saber o tamanho de uma string, basta invocar o método size (ex.: size_t stringSize = str.size() ).

## Questão 7

Nesta questão, implemente a seguinte função

```c++ 
int acharMenorOuIgual(int array[], int esquerda, int direita, int chave)
```

 Esta função recebe um array de inteiros e um inteiro ``chave`` e retorna um inteiro que indica o índice do primeiro elemento que seja menor ou igual ao valor de ``chave``, ou -1 caso não exista qualquer elemento menor do que ``chave`` no array de entrada. Os parâmetros ``esquerda`` e ``direita`` indicam os índices entre os quais está se realizando a busca.
 
 Sua função deverá obrigatoriamente ser recursiva e ter complexidade Θ(lg(n)).

Obs.1: Assuma que o array já está ordenado em ordem crescente e que ele não possui elementos repetidos.
Obs.2: Nesta questão, não podem ser usadas instruções para realizar repetição, como for, while e do-while. Ou seja, você deverá construir sua solução apenas com chamadas recursivas.

## Questão 8

Implemente a seguinte função:

``` c++
int contarImpares(int array, int tamanho)
```

A função ``contarImpares`` deverá contar e retornar quantos números ímpares um array de entrada contém. Sua função deverá obrigatoriamente ser recursiva.

Obs.: Nesta questão, não podem ser usadas instruções para realizar repetição, como for, while e do-while. Ou seja, você deverá construir sua solução apenas com chamadas recursivas.