#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "interfacesApresentacao.h"
#include "interfacesServico.h"
#include "dominios.h"

#include <stdexcept>
#include <iostream>
#include <cstdlib>

using namespace std;

class CntrServAutenticacao : public IServAutenticacao {
public:
	int autenticar(Identificador* id, Senha* senha);

	const static int SUCESSO =  0;
    const static int FALHA   = -1;

};

class CntrServUsuario : public IServUsuario {
private:
	// IAprAutenticacao* cntr = new CntrAprAutenticacao();
	// IServAutenticacao* servidorAutenticacao = new CntrServAutenticacao();

	const static char SIM = 'S';
	const static char NAO = 'N';

public:
	int cadastrar(Nome* nome, Identificador* id, Senha* senha);
	int descadastrarUsuario(Identificador* id);
	int cadastrarContaCorrente(Identificador* id, NumeroDeContaCorrente* conta, Agencia* agencia, Banco* Banco);
	int descadastrarContaCorrente(Identificador* id);
	int cadastrarCartaoDeCredito(Identificador* id, NumeroDeCartaoDeCredito* cartao, DataDeValidade* dataDeValidade);
	int descadastrarCartaoDeCredito(Identificador* id);

	const static int DESISTENCIA = 2;
	const static int SUCESSO = 0;
	const static int FALHA = -1;
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
