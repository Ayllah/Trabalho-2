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
	IAprAutenticacao *servidorAutenticacao;
public:
	int cadastrar(Nome* nome, Identificador* id, Senha* senha);
	int descadastrar(Identificador* id);
	const static char SIM = 'S';
	const static char NAO = 'N';

	const static int DESISTENCIA = 2;
	const static int SUCESSO = 0;
	const static int FALHA = -1;
};

#endif // CONTROLADORASSERVICO_H_INCLUDED
