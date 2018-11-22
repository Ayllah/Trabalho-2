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

//---------------------------------------------------------------------------
// Classe ContainerUsuario

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
// Classe ContainerAcomodacao

class ContainerAcomodacao {
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
        string containerAcomodacao;

	public:
		ContainerAcomodacao() {
			//Informa o nome do banco de dados.
				nomeBancoDados = "BaseDeDados";
		}
		
		void executar() throw (EErroPersistencia);

};

//---------------------------------------------------------------------------
// Classe ContainerDisponibilidade

class ContainerDisponibilidade {
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
        string containerDisponibilidade;

	public:
		ContainerDisponibilidade() {
			//Informa o nome do banco de dados.
				nomeBancoDados = "BaseDeDados";
		}
		
		void executar() throw (EErroPersistencia);

};

//---------------------------------------------------------------------------
// Classe ContainerReserva

class ContainerReserva {
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
        string containerReserva;

	public:
		ContainerReserva() {
			//Informa o nome do banco de dados.
				nomeBancoDados = "BaseDeDados";
		}
		
		void executar() throw (EErroPersistencia);

};

//---------------------------------------------------------------------------
// Classe Ordenacao
class Ordenacao {
	public:
		static bool comparacao(Disponibilidade, Disponibilidade);
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
// Classe ComandoRemoverUsuario

class ComandoRemoverUsuario : public ContainerUsuario {
	public:
		ComandoRemoverUsuario (Identificador);
};

//---------------------------------------------------------------------------
// Classe ComandoCadastrarContaCorrente.

class ComandoCadastrarContaCorrente : public ContainerUsuario {
	public:
		ComandoCadastrarContaCorrente(Identificador, ContaCorrente);
};

//---------------------------------------------------------------------------
// Classe ComandoPesquisarContaCorrente.

class ComandoPesquisarContaCorrente : public ContainerUsuario {
	public:
		ComandoPesquisarContaCorrente(Identificador);
		ContaCorrente getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
// Classe ComandoDescadastrarContaCorrente.

class ComandoDescadastrarContaCorrente : public ContainerUsuario {
	public:
		ComandoDescadastrarContaCorrente(Identificador);
};


//---------------------------------------------------------------------------
// Classe ComandoCadastrarCartaoDeCredito.

class ComandoCadastrarCartaoDeCredito : public ContainerUsuario {
	public:
		ComandoCadastrarCartaoDeCredito(Identificador, CartaoDeCredito);
};

//---------------------------------------------------------------------------
// Classe ComandoPesquisarCartaoDeCredito.

class ComandoPesquisarCartaoDeCredito : public ContainerUsuario {
	public:
		ComandoPesquisarCartaoDeCredito(Identificador);
		CartaoDeCredito getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
// Classe ComandoDescadastrarCartaoDeCredito.

class ComandoDescadastrarCartaoDeCredito : public ContainerUsuario {
	public:
		ComandoDescadastrarCartaoDeCredito(Identificador);
};

//---------------------------------------------------------------------------
// Classe ComandoCadastrarAcomodacao

class ComandoCadastrarAcomodacao : public ContainerAcomodacao {
	public:
		ComandoCadastrarAcomodacao(Identificador, Acomodacao);
};

//---------------------------------------------------------------------------
// Classe ComandoVerificaExclusividadeIdentificadorAcomodacao

class ComandoVerificaExclusividadeIdentificadorAcomodacao : public ContainerAcomodacao {
	public:
		ComandoVerificaExclusividadeIdentificadorAcomodacao(Identificador);
		bool getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
// Classe ComandoPesquisaIDAcomodacao

class ComandoPesquisaIDAcomodacao : public ContainerAcomodacao {
	public:
		ComandoPesquisaIDAcomodacao(Identificador);
		bool getResultado() throw (EErroPersistencia);	
};

//---------------------------------------------------------------------------
// Classe ComandoPesquisaProprietarioAcomodacao
class ComandoPesquisaProprietarioAcomodacao : public ContainerAcomodacao{
	public:
		ComandoPesquisaProprietarioAcomodacao(Identificador);
		string getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
// Classe ComandoPesquisaAcomodacao

class ComandoPesquisaAcomodacao : public ContainerAcomodacao{
	public:
		ComandoPesquisaAcomodacao(Identificador, Data, Data, CapacidadeDeAcomodacao, Nome, Estado);
		list<Acomodacao> getResultado() throw (EErroPersistencia);
};


//---------------------------------------------------------------------------
class ComandoProcuraAcomodacao : public ContainerAcomodacao{
	public:
		ComandoProcuraAcomodacao(Identificador);
		list<Acomodacao> getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
// Classe ComandoVerificaAcomodacaoPertenceUsuario

class ComandoVerificaAcomodacaoPertenceUsuario : public ContainerAcomodacao {
	public:
		ComandoVerificaAcomodacaoPertenceUsuario (Identificador id, Identificador idAcomodacao);
		bool getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarAcomodacao.

class ComandoDescadastrarAcomodacao : public ContainerAcomodacao {
	public:
		ComandoDescadastrarAcomodacao (Identificador);
};

//---------------------------------------------------------------------------
// Classe ComandoCadastrarDisponibilidade

class ComandoCadastrarDisponibilidade : public ContainerDisponibilidade {
	public:
		ComandoCadastrarDisponibilidade (Identificador,Disponibilidade);		
};

//---------------------------------------------------------------------------
// Classe ComandoPesquisarDisponibilidade

class ComandoPesquisarDisponibilidade : public ContainerDisponibilidade {
	public:
		ComandoPesquisarDisponibilidade (Identificador);
		list<Disponibilidade> getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
// Classe ComandoDescadastrarDisponibilidade

class ComandoDescadastrarDisponibilidade : public ContainerDisponibilidade {
	public:
		ComandoDescadastrarDisponibilidade (Identificador, Disponibilidade);		
};

//---------------------------------------------------------------------------
// Classe ComandoDescadastrarTodasDisponibilidadesAcomodacao

class ComandoDescadastrarTodasDisponibilidadesAcomodacao : public ContainerDisponibilidade {
	public:
		ComandoDescadastrarTodasDisponibilidadesAcomodacao (Identificador);
};


//---------------------------------------------------------------------------
// Classe ComandoCadastrarReserva

class ComandoCadastrarReserva : public ContainerReserva {
	public:
		ComandoCadastrarReserva (Identificador id, Identificador idAcomodacao, Reserva);
};

//---------------------------------------------------------------------------
// Classe ComandoPesquisaReserva

class ComandoPesquisaReserva : public ContainerReserva {
	public:
		ComandoPesquisaReserva (Identificador);
		list<Reserva> getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
// Classe ComandoPesquisaReservaUsuario
class ComandoPesquisaReservaUsuario : public ContainerReserva {
	public:
		ComandoPesquisaReservaUsuario (Identificador);
		list<Reserva> getResultado() throw (EErroPersistencia);
};

//---------------------------------------------------------------------------
// Classe ComandoDescadastraReserva
class ComandoDescadastraReserva : public ContainerReserva {
	public:
		ComandoDescadastraReserva (Identificador, Identificador, Data, Data);
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
	const static int USUARIO_POSSUI_RESERVA = 6;
	const static int USUARIO_POSSUI_ACOMODACAO = 5;
	const static int ACOMODACAO_AINDA_CADASTRADA = 4;
	const static int CARTAO_DE_CREDITO_JA_CADASTRADO = 3;
	const static int CONTA_CORRENTE_JA_CADASTRADA = 2;
	const static int USUARIO_JA_CADASTRADO = 1;
	const static int SUCESSO = 0;
	const static int FALHA = -1;
	const static int DESISTENCIA = -2;

public:
	int cadastrar(Nome* nome, Identificador* id, Senha* senha);
	int descadastrarUsuario(Identificador* id);
	int cadastrarContaCorrente(Identificador* id, NumeroDeContaCorrente* conta, Agencia* agencia, Banco* Banco);
	int descadastrarContaCorrente(Identificador* id);
	int cadastrarCartaoDeCredito(Identificador* id, NumeroDeCartaoDeCredito* cartao, DataDeValidade* dataDeValidade);
	int descadastrarCartaoDeCredito(Identificador* id);
};

class CntrServAcomodacao : public IServAcomodacao {
private:
	const static int AINDA_RESERVADA = 16;
	const static int RESERVA_NAO_ENCONTRADA = 15;
	const static int NAO_EXISTE_RESERVAS = 14;
	const static int RESERVA_NAO_PODE_SER_CANCELADA = 13;
	const static int DISPONIBILIDADE_NAO_DISPONIVEL = 12;
	const static int ACOMODACAO_NAO_ENCONTRADA = 11;
	const static int ACOMODACAO_INDISPONIVEL_NO_PERIODO = 10;
	const static int ACOMODACAO_INEXISTENTE = 9;
	const static int ACOMODACAO_NAO_DISPONIVEL = 8;
	const static int ACOMODACAO_JA_TEM_DISPONIBILIDADE = 7;
	const static int ACOMODACAO_PERTECE_USUARIO = 6;
	const static int ACOMODACAO_NAO_PERTECE_USUARIO = 5;
	const static int ID_ACOMODACAO_JA_UTILIZADO = 4;
	const static int CONTA_CORRENTE_AUSENTE = 3;
	const static int NAO_ANFITRIAO = 2;

public:

	int cadastrar(Identificador *id, Identificador *idAcomodacao, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade);
	list<Acomodacao> consultar(Identificador *id, Data *dataInicio, Data *dataTermino, CapacidadeDeAcomodacao *capacidade, Nome *cidade, Estado* estado);
	list<Acomodacao> buscarAcomodacao(Identificador *id);
	int descadastrar(Identificador *id, Identificador *idAcomodacao);
	int reservar(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino);
	list<Reserva> buscarReserva(Identificador *id);
	int cancelar(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino, Data *dataAtual);
	int cadastrarDisp(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino);
	int descadastrarDisp(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino);

	const static int SUCESSO =  0;
    const static int FALHA   = -1;
};


#endif // CONTROLADORASSERVICO_H_INCLUDED
