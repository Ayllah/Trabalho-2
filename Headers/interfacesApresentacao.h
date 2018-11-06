#ifndef INTERFACESAPRESENTACAO_H_INCLUDED
#define INTERFACESAPRESENTACAO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include "interfacesServico.h"
#include <stdexcept>

using namespace std;

class IAprAutenticacao{
	public:

		//Método por meio do qual é solicitado serviço

		virtual int autenticar(Identificador *id) throw(runtime_error) = 0;

		//Método por meio do qual é estabelecida ligação (link) com a controladora de negócio

		virtual void setServidor(IServAutenticacao *servidor) = 0;

		// Destrutor virtual

		virtual ~IAprAutenticacao(){}
	
};

class IAprUsuario{
	public:
		//Método por meio do qual é solicitado serviço
		
		virtual int cadastrar(Identificador* id) throw(runtime_error) = 0;
		virtual int executar(Identificador* id) throw(runtime_error) = 0;

		//Método por meio do qual é estabelecida ligação (link) com a controladora de negócio

		virtual void setServidor(IServUsuario *servidor) = 0;

		//Destrutor virtual

		virtual ~IAprUsuario(){}

};

#endif // INTERFACESAPRESENTACAO_H_INCLUDED