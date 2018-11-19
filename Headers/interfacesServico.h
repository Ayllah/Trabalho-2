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

class IServAcomodacao{
	public:

		// Métodos por meio dos quais são solicitados serviços.

		virtual int cadastrar(Identificador *id, Identificador *idAcomodacao, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade) = 0;
		virtual int consultar(Identificador *id, Data *dataInicio, Data *dataTermino) = 0;
		virtual int descadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade) = 0;
		virtual int reservar(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino) = 0;
		virtual int cancelar(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino) = 0;
		virtual int cadastrarDisp(Identificador* id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino) = 0;
		virtual int descadastrarDisp(Identificador* id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino) = 0;


		virtual ~IServAcomodacao(){}
};

#endif // INTERFACESSERVICO_H_INCLUDED