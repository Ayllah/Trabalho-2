#ifndef CONTROLADORASAPRESENTACAO_H_INCLUDED
#define CONTROLADORASAPRESENTACAO_H_INCLUDED

#include "interfacesApresentacao.h"
#include "interfacesServico.h"
#include "dominios.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

class CntrAprAutenticacao : public IAprAutenticacao {
private:
	IServAutenticacao *servidor;

public:
	int autenticar(Identificador *id) throw(runtime_error);
	void setServidor(IServAutenticacao *servidor){
		this->servidor = servidor;
	}

	const static int SUCESSO =  0;
    const static int FALHA   = -1;

};

class CntrAprUsuario : public IAprUsuario {
private:
	IServUsuario *servidor;
	const static int CONTA = 1;
	const static int PESQUISAR = 2;
	const static int ACOMODACAO = 3;
	const static int SAIR = 0;

	const static int EDITAR = 1;
	const static int CADASTRAR_CONTA_CORRENTE = 2;
	const static int DESCADASTRAR_CONTA_CORRENTE = 3;
	const static int CADASTRAR_CARTAO_CREDITO = 4;
	const static int DESCADASTRAR_CARTAO_CREDITO = 5;
	const static int DESCADASTRAR = 6;

	const static char SIM = 'S';
	const static char NAO = 'N';

	int painelConta(Identificador *id) throw(runtime_error);
	int editarUsuario(Identificador *id) throw(runtime_error);
	int descadastrarUsuario(Identificador *id) throw(runtime_error);
	int cadastrarContaCorrente(Identificador *id) throw(runtime_error);
	int descadastrarContaCorrente(Identificador *id) throw(runtime_error);
	int cadastrarCartaoCredito(Identificador *id) throw(runtime_error);
	int descadastrarCartaoCredito(Identificador *id) throw(runtime_error);

public:
	int cadastrar(Identificador *id) throw(runtime_error);
	int executar(Identificador* id) throw(runtime_error);

	void setServidor(IServUsuario *servidor){
		this->servidor = servidor;
	}

	const static int VOLTAR = 0;
	const static int CONTINUAR = 1;
	
	const static int DESISTENCIA = 2;
	const static int SUCESSO = 0;
	const static int FALHA = -1;
};

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
