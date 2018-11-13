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

class CntrServAcomodacao : public IServAcomodacao {
public:

	int cadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade);
	int descadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade);
	int reservar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino);
	int cancelar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino);
	int cadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino);
	int descadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino);

	const static int SUCESSO =  0;
    const static int FALHA   = -1;
	

};


#endif // CONTROLADORASSERVICO_H_INCLUDED
