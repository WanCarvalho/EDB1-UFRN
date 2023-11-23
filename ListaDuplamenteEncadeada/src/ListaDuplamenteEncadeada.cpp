//
//  ListaDuplamenteEncadeada.cpp
//
//  Criado por Eiji Adachi Medeiros Barbosa
//

#include "ListaDuplamenteEncadeada.h"

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada()
{
	this->cabeca = new No<std::string>("CABECA_NAO_DEVE_SER_ACESSADA");
	this->cauda = new No<std::string>("CAUDA_NAO_DEVE_SER_ACESSADA");

	this->cabeca->setProximo(this->cauda);
	this->cabeca->setAnterior(nullptr);

	this->cauda->setProximo(nullptr);
	this->cauda->setAnterior(this->cabeca);

	this->quantidade = 0;
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada()
{
	// TO-DO
}

No<std::string> *ListaDuplamenteEncadeada::getCabeca(void)
{
	return this->cabeca;
}

No<std::string> *ListaDuplamenteEncadeada::getCauda(void)
{
	return this->cauda;
}

int ListaDuplamenteEncadeada::tamanho(void)
{
	return this->quantidade;
}

bool ListaDuplamenteEncadeada::vazia(void)
{
	return this->tamanho() == 0;
}

std::string ListaDuplamenteEncadeada::recuperar(int i)
{
	return "";
}

int ListaDuplamenteEncadeada::buscar(std::string s)
{
	if (this->tamanho() == 0)
	{
		return -1;
	}
	else
	{
	}

	return -1;
}

bool ListaDuplamenteEncadeada::inserirNaCabeca(std::string s)
{
	return true;
}

bool ListaDuplamenteEncadeada::inserirNaCauda(std::string s)
{
	return true;
}

bool ListaDuplamenteEncadeada::inserir(int i, std::string s)
{
	return true;
}

std::string ListaDuplamenteEncadeada::removerDaCabeca(void)
{
	return "";
}

std::string ListaDuplamenteEncadeada::removerDaCauda(void)
{
	return "";
}

std::string ListaDuplamenteEncadeada::remover(int i)
{
	return "";
}

void ListaDuplamenteEncadeada::imprimir(void)
{
	for (auto n = this->cabeca->getProximo(); n != this->cauda; n = n->getProximo())
	{
		std::cout << n->getValor() << " ";
	}
	std::cout << std::endl;
}

StatusDaLista ListaDuplamenteEncadeada::checarConsistencia()
{
	if (this->cabeca == nullptr)
	{
		return CABECA_NULA;
	}
	else if (this->cabeca->getProximo() == nullptr)
	{
		return CABECA_PROXIMO_NULO;
	}
	else if (this->cabeca->getProximo()->getAnterior() != this->cabeca)
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if (this->cabeca->getAnterior() != nullptr)
	{
		return CABECA_ANTERIOR;
	}

	if (this->cauda == nullptr)
	{
		return CAUDA_NULA;
	}
	else if (this->cauda->getAnterior() == nullptr)
	{
		return CAUDA_ANTERIOR_NULO;
	}
	else if (this->cauda->getAnterior()->getProximo() != this->cauda)
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if (this->cauda->getProximo() != nullptr)
	{
		return CAUDA_PROXIMO;
	}

	if (this->vazia())
	{
		if (this->cabeca->getProximo() != this->cauda)
		{
			return CABECA_CAUDA;
		}

		if (this->cabeca != this->cauda->getAnterior())
		{
			return CABECA_CAUDA;
		}
	}
	else
	{
		// Verifica encadeamento dos elementos
		for (No<std::string> *i = this->cabeca->getProximo(); i != this->cauda; i = i->getProximo())
		{
			if (i->getProximo()->getAnterior() != i)
			{
				return ENCADEAMENTO_INCORRETO;
			}
			if (i->getAnterior()->getProximo() != i)
			{
				return ENCADEAMENTO_INCORRETO;
			}
		}
	}

	return OK;
}
