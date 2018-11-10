#ifndef INTERFACESSERVICO_H_INCLUDED
#define INTERFACESSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

class IServAutenticacao{
	public:
		virtual int autenticar(Identificador* id, Senha* senha) = 0;

		virtual ~IServAutenticacao(){}
};

class IServUsuario{
	public:

		// Métodos por meio dos quais são solicitados serviços.
		
		virtual int cadastrar(Nome* nome, Identificador* id, Senha* senha) = 0;
		virtual int descadastrarUsuario(Identificador* id) = 0;
		virtual int cadastrarContaCorrente(Identificador* id, NumeroDeContaCorrente* conta, Agencia* agencia, Banco* Banco) = 0;
		virtual int descadastrarContaCorrente(Identificador* id) = 0;
		virtual int cadastrarCartaoDeCredito(Identificador* id, NumeroDeCartaoDeCredito* cartao, DataDeValidade* dataDeValidade) = 0;
		virtual int descadastrarCartaoDeCredito(Identificador* id) = 0;
		
		virtual ~IServUsuario(){}
};

#endif // INTERFACESSERVICO_H_INCLUDED