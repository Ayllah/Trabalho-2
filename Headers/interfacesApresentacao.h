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

class IAprAcomodacao{
public:

	//Método por meio do qual é solicitado serviço

	virtual int executar(Identificador *id) = 0;
	virtual int cadastrar(Identificador *id) throw(runtime_error) = 0;
	virtual int descadastrar(Identificador *id) throw(runtime_error) = 0;
	virtual int reservar() throw(runtime_error) = 0;
	virtual int cancelar() throw(runtime_error) = 0;
	virtual int cadastrarDisp() throw(runtime_error) = 0;
	virtual int descadastrarDisp() throw(runtime_error) = 0;

	//Método por meio do qual é estabelecida ligação (link) com a controladora de negócio

	virtual void setServidor(IServAcomodacao *servidor) = 0;

	// Destrutor virtual

	virtual ~IAprAcomodacao(){}
	
};

#endif // INTERFACESAPRESENTACAO_H_INCLUDED