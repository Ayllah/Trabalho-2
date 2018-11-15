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
	
	IAprAutenticacao *cntrAutenticacao;
	IAprAcomodacao *cntrAcomodacao;

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

	const static int VOLTAR = 0;
	const static int CONTINUAR = 1;
	
	const static char SIM = 'S';
	const static char NAO = 'N';

	const static int CARTAO_DE_CREDITO_JA_CADASTRADO = 3;
	const static int CONTA_CORRENTE_JA_CADASTRADA = 2;
	const static int USUARIO_JA_CADASTRADO = 1;
	const static int SUCESSO = 0;
	const static int FALHA = -1;
	const static int DESISTENCIA = -2;

	int painelConta(Identificador *id) throw(runtime_error);
	//int editarUsuario(Identificador *id) throw(runtime_error);
	int descadastrarUsuario(Identificador *id) throw(runtime_error);

	int cadastrarContaCorrente(Identificador *id) throw(runtime_error);
	//int editarContaCorrent(Identificador *id) throw(runtime_error);
	int descadastrarContaCorrente(Identificador *id) throw(runtime_error);
	
	int cadastrarCartaoDeCredito(Identificador *id) throw(runtime_error);
	//int editarCartaoCredito(Identificador *id) throw(runtime_error);
	int descadastrarCartaoDeCredito(Identificador *id) throw(runtime_error);

public:
	int cadastrar(Identificador *id) throw(runtime_error);
	int executar(Identificador *id) throw(runtime_error);

	void setServidor(IServUsuario *servidor){
		this->servidor = servidor;
	}
};

class CntrAprAcomodacao : public IAprAcomodacao {
private:

	const static int CADASTRAR_ACOMODACAO   = 1;
    const static int DESCADASTRAR_ACOMODACAO   = 2;
    const static int RESERVAR_ACOMODACAO = 3;
    const static int CANCELAR_RESERVA    = 4;
    const static int CADASTRAR_DISPONIBILIDADE = 5;
    const static int DESCADASTRAR_DISPONIBILIDADE = 6;
    const static int RETORNAR = 0;

	IServAcomodacao *servidor;

    int cadastrar(Identificador *id) throw(runtime_error);
    int descadastrar(Identificador *id) throw(runtime_error);
    int reservar(Identificador *id) throw(runtime_error);
    int cancelar(Identificador *id) throw(runtime_error);
    int cadastrarDisp() throw(runtime_error);
    int descadastrarDisp() throw(runtime_error);

public:

	 // Método previsto na interface por meio do qual é solicitada execução da controladora.

    int executar(Identificador *id);
	int consultar(Identificador *id);
    // Método por meio do qual é estabelecido relacionamento com o servidor.

    void setServidor(IServAcomodacao *servidor){
        this->servidor = servidor;
    }

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

};

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
