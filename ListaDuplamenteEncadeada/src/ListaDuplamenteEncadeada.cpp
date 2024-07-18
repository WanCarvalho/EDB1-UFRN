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
    auto aux = this->cabeca;

	while(aux != nullptr){
		auto aux2 = aux;
		aux = aux->getProximo();
		delete aux2;
	}
}

No<std::string>* ListaDuplamenteEncadeada::getCabeca(void)
{
    return this->cabeca;
}

No<std::string>* ListaDuplamenteEncadeada::getCauda(void)
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
	if(this->quantidade == 0){
		throw "ERRO: Lista vazia";
	} else {
		No<std::string>* aux = this->cabeca->getProximo();
		int contador = 1;

		while(contador < i){
			aux = aux->getProximo();
			contador++;
		}

		return aux->getValor();
	}
}

int ListaDuplamenteEncadeada::buscar(std::string s)
{
	No<std::string>* aux = this->cabeca->getProximo();

	for(int i = 0; i < this->quantidade; i++){
		if(aux->getValor() == s){
			return i + 1;
		} else {
			aux = aux->getProximo();
		}
	}

	return -1;
}

bool ListaDuplamenteEncadeada::inserirNaCabeca(std::string s)
{   
    No<std::string>* novo = new No<std::string>(s);

	novo->setAnterior( this->cabeca );
	novo->setProximo( this->cabeca->getProximo());

	novo->getAnterior()->setProximo(novo);
	novo->getProximo()->setAnterior(novo);

	this->quantidade++;

	return true;
}

bool ListaDuplamenteEncadeada::inserirNaCauda(std::string s)
{    
	No<std::string>* novo = new No<std::string>(s);

	novo->setProximo(this->cauda);
	novo->setAnterior(this->cauda->getAnterior());

	novo->getAnterior()->setProximo(novo);
	novo->getProximo()->setAnterior(novo);

	this->quantidade++;

    return true;
}

bool ListaDuplamenteEncadeada::inserir(int i, std::string s)
{    
    No<std::string>* novo = new No<std::string>(s);

	int contador = 1;
	auto aux = this->getCabeca()->getProximo();

	while(contador < i){
		aux = aux->getProximo();
		contador++;
	}

	novo->setProximo(aux);
	novo->setAnterior(aux->getAnterior());

	novo->getAnterior()->setProximo(novo);
	novo->getProximo()->setAnterior(novo);

	this->quantidade++;

	return true;
}

std::string ListaDuplamenteEncadeada::removerDaCabeca(void)
{   
    if(this->quantidade == 0){
		throw "ERRO: Lista vazia";
	} else {
		auto aux = this->cabeca->getProximo();

		aux->getAnterior()->setProximo(aux->getProximo());
		aux->getProximo()->setAnterior(aux->getAnterior());

		auto valor = aux->getValor();

		delete aux;
		this->quantidade--;

		return valor;
	}
}

std::string ListaDuplamenteEncadeada::removerDaCauda(void)
{    
    if(this->quantidade == 0){
		throw "ERRO: Lista vazia";
	} else {
		auto aux = this->cauda->getAnterior();

		aux->getProximo()->setAnterior(aux->getAnterior());
		aux->getAnterior()->setProximo(aux->getProximo());

		auto valor = aux->getValor();
		
		delete aux;
		this->quantidade--;

		return valor;
	}
}

std::string ListaDuplamenteEncadeada::remover(int i)
{    
    if(this->quantidade == 0){
		throw "ERRO: Lista vazia";
	} else {
		auto aux = this->cabeca->getProximo();

		int contador = 1;

		while(contador < i){
			aux = aux->getProximo();
			contador++;
		}

		aux->getAnterior()->setProximo(aux->getProximo());
		aux->getProximo()->setAnterior(aux->getAnterior());

		auto valor = aux->getValor();

		delete aux;
		this->quantidade--;

		return valor;
	}
}

void ListaDuplamenteEncadeada::imprimir(void)
{
	for(auto n = this->cabeca->getProximo(); n != this->cauda; n = n->getProximo())
	{
		std::cout << n->getValor() << " ";
	}
	std::cout << std::endl;
}

StatusDaLista ListaDuplamenteEncadeada::checarConsistencia()
{
	if( this->cabeca == nullptr )
	{
		return CABECA_NULA;
	}
	else if( this->cabeca->getProximo() == nullptr )
	{
		return CABECA_PROXIMO_NULO;
	}
	else if( this->cabeca->getProximo()->getAnterior() != this->cabeca )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cabeca->getAnterior() != nullptr )
	{
		return CABECA_ANTERIOR;
	}
	
	if( this->cauda == nullptr )
	{
		return CAUDA_NULA;
	}
	else if( this->cauda->getAnterior() == nullptr )
	{
		return CAUDA_ANTERIOR_NULO;
	}
	else if( this->cauda->getAnterior()->getProximo() != this->cauda )
	{
		return ENCADEAMENTO_INCORRETO;
	}
	else if( this->cauda->getProximo() != nullptr )
	{
		return CAUDA_PROXIMO;
	}
	
	if(this->vazia())
	{
		if( this->cabeca->getProximo() != this->cauda )
		{
			return CABECA_CAUDA;
		}
		
		if( this->cabeca != this->cauda->getAnterior() )
		{
			return CABECA_CAUDA;
		}
	}
	else
	{
		// Verifica encadeamento dos elementos
		for(No<std::string>* i = this->cabeca->getProximo(); i != this->cauda; i=i->getProximo())
		{
			if( i->getProximo()->getAnterior() != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
			if( i->getAnterior()->getProximo() != i )
			{
				return ENCADEAMENTO_INCORRETO;
			}
		}
	}
	
	return OK;
}
