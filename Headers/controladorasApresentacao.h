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

	// Método previsto na interface por meio do qual é solicitada execução da controladora.

	int autenticar(Identificador *id) throw(runtime_error);

	// Método por meio do qual é estabelecido relacionamento com o servidor.
	
	void setServidor(IServAutenticacao *servidor){
		this->servidor = servidor;
	}

	const static int SUCESSO =  0;
    const static int FALHA   = -1;

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
    int reservar() throw(runtime_error);
    int cancelar() throw(runtime_error);
    int cadastrarDisp() throw(runtime_error);
    int descadastrarDisp() throw(runtime_error);

public:

	 // Método previsto na interface por meio do qual é solicitada execução da controladora.

    int executar(Identificador *id);

    // Método por meio do qual é estabelecido relacionamento com o servidor.

    void setServidor(IServAcomodacao *servidor){
        this->servidor = servidor;
    }

    const static int SUCESSO =  0;
    const static int FALHA   = -1;

};


#endif // CONTROLADORASAPRESENTACAO_H_INCLUDED
