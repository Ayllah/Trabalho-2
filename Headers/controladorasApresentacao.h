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

#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
