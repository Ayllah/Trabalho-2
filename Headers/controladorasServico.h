#ifndef CONTROLADORASSERVICO_H_INCLUDED
#define CONTROLADORASSERVICO_H_INCLUDED

#include "interfacesApresentacao.h"
#include "interfacesServico.h"
#include "dominios.h"
#include "sqlite3.h"

#include <stdexcept>
#include <iostream>
#include <string>
#include <cstdlib>
#include <list>

using namespace std;

//classe EErroPersistencia

class EErroPersistencia {
private:
        string mensagem;
public:
        EErroPersistencia(string);
        string what();
};

//classe ElementoResultado

class ElementoResultado {
private:
        string nomeColuna;
        string valorColuna;
public:
        void setNomeColuna(const string&);
        string getNomeColuna() const {
        	return nomeColuna;
        }
        void setValorColuna(const string&);
        string getValorColuna() const{
        	return valorColuna;
        }
};

//classe ContainerUsuario

class ContainerUsuario {
private:
	const char *nomeBancoDados;
    sqlite3 *bd;
    char *mensagem;
    int rc;
    void conectar() throw (EErroPersistencia);
    void desconectar() throw (EErroPersistencia);
    static int callback(void *, int, char **, char **);

protected:
        static list<ElementoResultado> listaResultado;
        string containerUsuario;
public:
	ContainerUsuario() {
		//Informa o nome do banco de dados.
             nomeBancoDados = "BaseDeDados";
	}
	
	void executar() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
// Classe ComandoLerSenha.
class ComandoLerSenha : public ContainerUsuario {
	public:
		ComandoLerSenha(Identificador*);
		string getResultado() throw (EErroPersistencia);
};

//Classe ComandoCadastrarUsuario.

class ComandoCadastrarUsuario : public ContainerUsuario {
public:
        ComandoCadastrarUsuario(Usuario);
};

//---------------------------------------------------------------------------
//Classe ComandoPesquisarUsuario.

class ComandoPesquisarUsuario : public ContainerUsuario {
	public:
		ComandoPesquisarUsuario(Identificador);
		Usuario getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
// Classe Controladora Autenticacao

class CntrServAutenticacao : public IServAutenticacao {
private:
	const static int SUCESSO = 0;
	const static int FALHA = -1;

public:
	int autenticar(Identificador* id, Senha* senha);
};

//---------------------------------------------------------------------------
// Classe Controladora Usuario

class CntrServUsuario : public IServUsuario {
private:

	const static char SIM = 'S';
	const static char NAO = 'N';
	const static int DESISTENCIA = 2;
	const static int USUARIO_JA_CADASTRADO = 1;
	const static int SUCESSO = 0;
	const static int FALHA = -1;
	
public:
	int cadastrar(Nome* nome, Identificador* id, Senha* senha);
	int descadastrarUsuario(Identificador* id);
	int cadastrarContaCorrente(Identificador* id, NumeroDeContaCorrente* conta, Agencia* agencia, Banco* Banco);
	int descadastrarContaCorrente(Identificador* id);
	int cadastrarCartaoDeCredito(Identificador* id, NumeroDeCartaoDeCredito* cartao, DataDeValidade* dataDeValidade);
	int descadastrarCartaoDeCredito(Identificador* id);
};

class CntrServAcomodacao : public IServAcomodacao {
public:

	int cadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade);
	int consultar(Identificador *id, Data *dataInicio, Data *dataTermino);
	int descadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade);
	int reservar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino);
	int cancelar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino);
	int cadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino);
	int descadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino);

	const static int SUCESSO =  0;
    const static int FALHA   = -1;
};


#endif // CONTROLADORASSERVICO_H_INCLUDED
