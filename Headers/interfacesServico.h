#ifndef INTERFACESSERVICO_H_INCLUDED
#define INTERFACESSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

class IServAutenticacao{
	public:

		// Métodos por meio dos quais são solicitados serviços.
		
		virtual int autenticar(Identificador* id, Senha* senha) = 0;

		virtual ~IServAutenticacao(){}
};

class IServAcomodacao{
	public:

		// Métodos por meio dos quais são solicitados serviços.

		virtual int cadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade) = 0;
		virtual int descadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade) = 0;
		virtual int reservar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino) = 0;
		virtual int cancelar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino) = 0;
		virtual int cadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino) = 0;
		virtual int descadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino) = 0;


		virtual ~IServAcomodacao(){}
};

#endif // INTERFACESSERVICO_H_INCLUDED