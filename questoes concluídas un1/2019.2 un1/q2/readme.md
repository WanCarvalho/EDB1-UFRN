Sequências bitônicas inversas são aquelas que possuem duas sequências, sendo uma sequência inicial decrescente, seguida de uma sequência crescente.
Ou seja, os elementos de uma sequência bitônica inversa obedecem a seguinte relação: 

A0 > A1 > ... > Ai-1 > Ai < Ai+1 < ... < An
 
Considere que um vetor bitônico-inverso é um vetor de inteiros sem repetições cujos elementos representam uma sequência bitônica inversa.
Nesta questão, implemente a função findBase que recebe como entrada um vetor bitônico-inverso e retorna o índice da base, isto é, do elemento Ai, que representa a transição da sequencia decrescente para a sequencia crescente.
Sua solução deverá ser recursiva ter complexidade Θ (lg(n) ).
