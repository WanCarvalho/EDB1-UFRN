#include <iostream>
#include "Conjunto.h"

int main() 
{
  int num;

  Conjunto c1(10);

  for(int i = 0; i < 10; i++){
    c1.inserir(i);
  }

  Conjunto c2(10);

  for(int i = 0; i < 10; i++){
    c2.inserir(i+6);
  }

  Conjunto intersecao = c1.intersecao(c2);
  intersecao.imprimir();

  /*while (true) 
  {
    std::cout << "Digite um número inteiro positivo para adicionar ao conjunto, ou um número negativo para terminar o programa." << std::endl;
    std::cin >> num;
    if (num < 0) 
    {
      std::cout << "Terminando o programa." << std::endl;
      break;
    }
    c.inserir(num);
    std::cout << "Adicionando " << num << " ao conjunto. Tamanho do conjunto: " << c.tamanho() << std::endl;
    c.imprimir();
  }*/
  return 0;
}
