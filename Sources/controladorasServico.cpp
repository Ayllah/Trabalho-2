#include "controladorasServico.h"

//Atributo estático container List.

list<ElementoResultado> ContainerUsuario::listaResultado;
list<ElementoResultado> ContainerAcomodacao::listaResultado;
list<ElementoResultado> ContainerDisponibilidade::listaResultado;
list<ElementoResultado> ContainerReserva::listaResultado;

// Classe EErroPersistencia

EErroPersistencia :: EErroPersistencia(string mensagem){
        this->mensagem = mensagem;
}

string EErroPersistencia :: what() {
        return mensagem;
}

//classe ElementoResultado

void ElementoResultado :: setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado :: setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}

// ---------------------------------------------------------------------
// Classe ContainerUsuario

void ContainerUsuario :: conectar() throw (EErroPersistencia) {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ContainerUsuario :: desconectar() throw (EErroPersistencia) {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");      
}

void ContainerUsuario::executar() throw (EErroPersistencia) {
        conectar();
		cout << containerUsuario << endl;
        rc = sqlite3_exec(bd, containerUsuario.c_str(), callback, 0, &mensagem);
        cout << "Digite s para imprimir mensagem" << endl;
		char c = getchar();
		if (c == 's')
			cout << mensagem << endl;

        if(rc != SQLITE_OK){
		        if (mensagem){
                	free(mensagem);
                }
                throw EErroPersistencia("Erro na execucao do comando SQL");
        } 
        
		desconectar();
    
}

int ContainerUsuario::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed = 0;
      ElementoResultado elemento;
      int i;
      for(i = 0; i < argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}

// ---------------------------------------------------------------------
// Classe ContainerAcomodacao

void ContainerAcomodacao :: conectar() throw (EErroPersistencia) {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ContainerAcomodacao :: desconectar() throw (EErroPersistencia) {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");      
}

void ContainerAcomodacao :: executar() throw (EErroPersistencia) {
        conectar();
		cout << containerAcomodacao << endl;
        rc = sqlite3_exec(bd, containerAcomodacao.c_str(), callback, 0, &mensagem);
        cout << "Digite s para imprimir mensagem" << endl;
		char c = getchar();
		if (c == 's')
			cout << mensagem << endl;

        if(rc != SQLITE_OK){
		        if (mensagem){
                	free(mensagem);
                }
                throw EErroPersistencia("Erro na execucao do comando SQL");
        } 
        
		desconectar();
}

int ContainerAcomodacao::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed = 0;
      ElementoResultado elemento;
      int i;
      for(i = 0; i < argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}

// ---------------------------------------------------------------------
// Classe ContainerDisponibilidade

void ContainerDisponibilidade :: conectar() throw (EErroPersistencia) {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ContainerDisponibilidade :: desconectar() throw (EErroPersistencia) {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");      
}

void ContainerDisponibilidade :: executar() throw (EErroPersistencia) {
        conectar();
		cout << containerDisponibilidade << endl;
        rc = sqlite3_exec(bd, containerDisponibilidade.c_str(), callback, 0, &mensagem);
        cout << "Digite s para imprimir mensagem" << endl;
		char c = getchar();
		if (c == 's')
			cout << mensagem << endl;

        if(rc != SQLITE_OK){
		        if (mensagem){
                	free(mensagem);
                }
                throw EErroPersistencia("Erro na execucao do comando SQL");
        } 
        
		desconectar();
}

int ContainerDisponibilidade::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed = 0;
      ElementoResultado elemento;
      int i;
      for(i = 0; i < argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}

// ---------------------------------------------------------------------
// Classe ContainerReserva

void ContainerReserva :: conectar() throw (EErroPersistencia) {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ContainerReserva :: desconectar() throw (EErroPersistencia) {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");      
}

void ContainerReserva :: executar() throw (EErroPersistencia) {
        conectar();
		cout << containerReserva << endl;
        rc = sqlite3_exec(bd, containerReserva.c_str(), callback, 0, &mensagem);
        cout << "Digite s para imprimir mensagem" << endl;
		char c = getchar();
		if (c == 's')
			cout << mensagem << endl;

        if(rc != SQLITE_OK){
		        if (mensagem){
                	free(mensagem);
                }
                throw EErroPersistencia("Erro na execucao do comando SQL");
        } 
        
		desconectar();
}

int ContainerReserva::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed = 0;
      ElementoResultado elemento;
      int i;
      for(i = 0; i < argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}
//---------------------------------------------------------------------------
// Classe Ordenacao

bool Ordenacao :: comparacao (Disponibilidade disponibilidadeX, Disponibilidade disponibilidadeY){
	Data dataInicioDisponibilidadeX = disponibilidadeX.getDataInicioDisponibilidade();
	Data dataInicioDisponibilidadeY = disponibilidadeY.getDataInicioDisponibilidade();
	if (Data :: comparaDatas(dataInicioDisponibilidadeX, dataInicioDisponibilidadeY) == -1){
		return true;
	}
	else{
		return false;
	}
}
// --------------------------------------------------------------
// Classe ComandoLerSenha

ComandoLerSenha :: ComandoLerSenha(Identificador *id) {
	containerUsuario = "SELECT Senha FROM Usuarios WHERE Identificador = ";
    containerUsuario += '\'' + id->getIdentificador() + '\'';
}

string ComandoLerSenha :: getResultado() throw (EErroPersistencia){
	ElementoResultado resultado;
	string senha_recuperada;

	if (listaResultado.empty()){
        throw EErroPersistencia("Lista de resultados vazia.");
    }

    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha_recuperada = resultado.getValorColuna();

	listaResultado.clear();
    return senha_recuperada;
}

//---------------------------------------------------------------------------
//Classe ComandoCadastrarUsuario.

ComandoCadastrarUsuario :: ComandoCadastrarUsuario(Usuario usuario) {
	containerUsuario = "INSERT INTO Usuarios VALUES (";
	containerUsuario += "'" + usuario.getIdentificadorUsuario().getIdentificador() + "', ";
	containerUsuario += "'" + usuario.getNomeUsuario().getNome() + "', ";
	containerUsuario += "'" + usuario.getSenhaUsuario().getSenha() + "' , null, null, null, null, null)";
}

//---------------------------------------------------------------------------
// Classe ComandoPesquisarUsuario

ComandoPesquisarUsuario :: ComandoPesquisarUsuario(Identificador id){
	containerUsuario = "SELECT * FROM Usuarios WHERE Identificador = ";
	containerUsuario += '\'' + id.getIdentificador() + '\'';
}

Usuario ComandoPesquisarUsuario :: getResultado() throw (EErroPersistencia){
	ElementoResultado resultado;
	Nome nome;
	Identificador id;
	Senha senha;
	Usuario usuario;

	//Remover identificador
	if(listaResultado.empty()){
		return usuario;
		throw EErroPersistencia("Lista de resultado vazia.");
	}
	resultado = listaResultado.back();
	listaResultado.pop_back();
	id.setIdentificador(resultado.getValorColuna());
	usuario.setIdentificadorUsuario(id);

	//Remover nome
	if(listaResultado.empty()){
		return usuario;
		throw EErroPersistencia("Lista de resultado vazia.");
	}
	resultado = listaResultado.back();
	listaResultado.pop_back();
	nome.setNome(resultado.getValorColuna());
	usuario.setNomeUsuario(nome);

	//Remover senha;
	if(listaResultado.empty()){
		return usuario;
		throw EErroPersistencia("Lista de resultado vazia.");
	}
	resultado = listaResultado.back();
	listaResultado.pop_back();
	senha.setSenha(resultado.getValorColuna());
	usuario.setSenhaUsuario(senha);

	listaResultado.clear();
	return usuario;
}

//---------------------------------------------------------------------------
// Classe ComandoCadastrarContaCorrente.

ComandoCadastrarContaCorrente :: ComandoCadastrarContaCorrente (Identificador id, ContaCorrente contaCorrente){
	containerUsuario = "UPDATE Usuarios ";
	containerUsuario += "SET NumeroConta = '" + contaCorrente.getNumeroContaCorrente().getNumeroDeContaCorrente();
	containerUsuario += "', Agencia = '" + contaCorrente.getAgenciaContaCorrente().getAgencia();
	containerUsuario += "', Banco = '" + contaCorrente.getBancoContaCorrente().getBanco();
	containerUsuario += "' WHERE Identificador = ";
	containerUsuario += '\'' + id.getIdentificador() + '\'';
}

//---------------------------------------------------------------------------
// Classe ComandoPesquisarContaCorrente.

ComandoPesquisarContaCorrente :: ComandoPesquisarContaCorrente (Identificador id){
	containerUsuario = "SELECT NumeroConta, Agencia, Banco FROM Usuarios WHERE Identificador = ";
	containerUsuario += '\'' + id.getIdentificador() + '\'';
	containerUsuario += " AND NumeroConta <> 'null'";
}

ContaCorrente ComandoPesquisarContaCorrente :: getResultado() throw (EErroPersistencia) {
	ElementoResultado resultado;
	NumeroDeContaCorrente numeroDeContaCorrente;
	Agencia agencia;
	Banco banco;
	ContaCorrente contaCorrente;

	//Remover Numero Conta Corrente
	if(listaResultado.empty()){
		return contaCorrente;
		throw EErroPersistencia("Lista de resultado vazia.");
	}
	resultado = listaResultado.back();
	listaResultado.pop_back();
	numeroDeContaCorrente.setNumeroDeContaCorrente(resultado.getValorColuna());
	contaCorrente.setNumeroContaCorrente(numeroDeContaCorrente);

	//Remover Agencia
	if(listaResultado.empty()){
		return contaCorrente;
		throw EErroPersistencia("Lista de resultado vazia.");
	}
	resultado = listaResultado.back();
	listaResultado.pop_back();
	agencia.setAgencia(resultado.getValorColuna());
	contaCorrente.setAgenciaContaCorrente(agencia);	

	//Remover Banco
	if(listaResultado.empty()){
		return contaCorrente;
		throw EErroPersistencia("Lista de resultado vazia.");
	}
	resultado = listaResultado.back();
	listaResultado.pop_back();
	banco.setBanco(resultado.getValorColuna());
	contaCorrente.setBancoContaCorrente(banco);	
	
	listaResultado.clear();
	return contaCorrente;
}

//---------------------------------------------------------------------------
// Classe ComandoDescadastrarContaCorrente.

ComandoDescadastrarContaCorrente :: ComandoDescadastrarContaCorrente(Identificador id){
	containerUsuario = "UPDATE Usuarios ";
	containerUsuario += "SET NumeroConta = null, ";
	containerUsuario += "Agencia = null, ";
	containerUsuario += "Banco = null WHERE Identificador = ";
	containerUsuario += '\'' + id.getIdentificador() + '\'';
}

//---------------------------------------------------------------------------
// Classe ComandoCadastrarCartaoDeCredito.

ComandoCadastrarCartaoDeCredito :: ComandoCadastrarCartaoDeCredito(Identificador id, CartaoDeCredito cartaoDeCredito){
	containerUsuario = "UPDATE Usuarios ";
	containerUsuario += "SET NumeroCartao = '" + cartaoDeCredito.getNumeroCartaoCredito().getNumeroDeCartaoDeCredito();
	containerUsuario += "', ValidadeCartao = '" + cartaoDeCredito.getDataDeValidadeCartaoDeCredito().getDataDeValidade();
	containerUsuario += "' WHERE Identificador = ";
	containerUsuario += '\'' + id.getIdentificador() + '\'';
}

//---------------------------------------------------------------------------
// Classe ComandoPesquisarCartaoDeCredito.

ComandoPesquisarCartaoDeCredito :: ComandoPesquisarCartaoDeCredito (Identificador id){
	containerUsuario = "SELECT NumeroCartao, ValidadeCartao FROM Usuarios WHERE Identificador = ";
	containerUsuario += '\'' + id.getIdentificador() + '\'';
	containerUsuario += " AND NumeroCartao <> 'null'";
}

CartaoDeCredito ComandoPesquisarCartaoDeCredito :: getResultado() throw (EErroPersistencia){
	ElementoResultado resultado;
	NumeroDeCartaoDeCredito cartao;
	DataDeValidade dataDeValidade;
	CartaoDeCredito cartaoDeCredito;

	// Remover Numero Cartao de Credito
	if(listaResultado.empty()){
		return cartaoDeCredito;
		throw EErroPersistencia("Lista de resultado vazia.");
	}
	resultado = listaResultado.back();
	listaResultado.pop_back();
	cartao.setNumeroDeCartaoDeCredito(resultado.getValorColuna());
	cartaoDeCredito.setNumeroCartaoCredito(cartao);

	// Remover Data de Validade
	if(listaResultado.empty()){
		return cartaoDeCredito;
		throw EErroPersistencia("Lista de resultado vazia.");
	}
	resultado = listaResultado.back();
	listaResultado.pop_back();
	dataDeValidade.setDataDeValidade(resultado.getValorColuna());
	cartaoDeCredito.setDataDeValidadeCartaoDeCredito(dataDeValidade);	

	listaResultado.clear();
	return cartaoDeCredito;
}

//---------------------------------------------------------------------------
// Classe ComandoDescadastrarCartaoDeCredito.

ComandoDescadastrarCartaoDeCredito :: ComandoDescadastrarCartaoDeCredito(Identificador id){
	containerUsuario = "UPDATE Usuarios ";
	containerUsuario += "SET NumeroCartao = null, ";
	containerUsuario += "ValidadeCartao = null WHERE Identificador = ";
	containerUsuario += '\'' + id.getIdentificador() + '\'';
}

//---------------------------------------------------------------------------
// Classe ComandoCadastrarAcomodacao

ComandoCadastrarAcomodacao :: ComandoCadastrarAcomodacao(Identificador identificador, Acomodacao acomodacao){
	containerAcomodacao = "INSERT INTO Acomodacoes VALUES (";
	containerAcomodacao += "'" + acomodacao.getIdentificadorAcomodacao().getIdentificador() + "', ";
	containerAcomodacao += "'" + identificador.getIdentificador() + "', ";
	containerAcomodacao += "'" + acomodacao.getTipoAcomodacao().getTipoDeAcomodacao() + "', ";
	containerAcomodacao += "'" + to_string(acomodacao.getCapacidadeAcomodacao().getCapacidade()) + "', ";
	containerAcomodacao += "'" + acomodacao.getNomeCidadeAcomodacao().getNome() + "', ";
	containerAcomodacao += "'" + acomodacao.getEstadoAcomodacao().getEstado() + "', ";
	containerAcomodacao += "'" + to_string(acomodacao.getDiariaAcomodacao().getDiaria()) + "')";
}

//---------------------------------------------------------------------------
// Classe ComandoVerificaExclusividadeIdentificadorAcomodacao

ComandoVerificaExclusividadeIdentificadorAcomodacao :: ComandoVerificaExclusividadeIdentificadorAcomodacao (Identificador idAcomodacao){
	containerAcomodacao = "SELECT Identificador FROM Acomodacoes WHERE Identificador = ";
	containerAcomodacao += '\'' + idAcomodacao.getIdentificador() + '\'';
};

bool ComandoVerificaExclusividadeIdentificadorAcomodacao :: getResultado() throw (EErroPersistencia){
	bool resultado;

	if(listaResultado.empty()){
		resultado = false;
	}
	else{
		resultado = true;
	}

	listaResultado.clear();
	return resultado;
}

//---------------------------------------------------------------------------
// Classe ComandoPesquisaIDAcomodacao
ComandoPesquisaIDAcomodacao :: ComandoPesquisaIDAcomodacao (Identificador idAcomodacao){
	containerAcomodacao = "SELECT Identificador FROM Acomodacoes WHERE Identificador = ";
	containerAcomodacao += '\'' + idAcomodacao.getIdentificador() + '\'';
}

bool ComandoPesquisaIDAcomodacao :: getResultado() throw (EErroPersistencia){
	bool resultado;

	if(listaResultado.empty()){
		resultado = false;
	}
	else{
		resultado = true;
	}

	listaResultado.clear();
	return resultado;
}

//---------------------------------------------------------------------------
// Classe ComandoPesquisaAcomodacao

ComandoPesquisaAcomodacao :: ComandoPesquisaAcomodacao(Identificador id, Data dataInicio, Data dataTermino, CapacidadeDeAcomodacao capacidade, Nome cidade, Estado estado){
	containerAcomodacao = "SELECT Identificador, Tipo, Capacidade, Diaria FROM Acomodacoes WHERE IdentificadorUsuario <> ";
	containerAcomodacao += '\'' + id.getIdentificador() + '\'';
	containerAcomodacao += " AND Capacidade >= ";
	containerAcomodacao += '\'' + capacidade.getCapacidade() + '\'';
	containerAcomodacao += " AND Cidade = ";
	containerAcomodacao += '\'' + cidade.getNome() + '\'';
	containerAcomodacao += " AND Estado = ";
	containerAcomodacao += '\'' + estado.getEstado() + '\'';
	containerAcomodacao += " INNER JOIN Disponibilidades ON DataInicio <= ";
	containerAcomodacao += '\'' + dataInicio.getData() + '\'';
	containerAcomodacao += " AND DataTermino >= ";
	containerAcomodacao += '\'' + dataTermino.getData() + '\'';
}

list<Acomodacao> ComandoPesquisaAcomodacao :: getResultado() throw (EErroPersistencia){
	list<Acomodacao> listaAcomodacao;
	ElementoResultado resultado;
	Identificador idAcomodacao;
	TipoDeAcomodacao tipo;
	CapacidadeDeAcomodacao capacidade;
	Nome cidade;
	Estado estado;
	Acomodacao acomodacao_recuperada;

	while(!listaResultado.empty()){
		// Remove Identificador
		if (listaResultado.empty()){
 	       throw EErroPersistencia("Lista de resultados vazia.");
   		}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		idAcomodacao.setIdentificador(resultado.getValorColuna());

		// Remove Tipo
		if (listaResultado.empty()){
 	       throw EErroPersistencia("Lista de resultados vazia.");
   		}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		tipo.setTipoDeAcomodacao(resultado.getValorColuna());

		// Remove Capacidade
		if (listaResultado.empty()){
 	       throw EErroPersistencia("Lista de resultados vazia.");
   		}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		capacidade.setCapacidade(stoi(resultado.getValorColuna()));

		// Remove Cidade
		if (listaResultado.empty()){
 	       throw EErroPersistencia("Lista de resultados vazia.");
   		}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		cidade.setNome(resultado.getValorColuna());

		// Remove Estado		
		if (listaResultado.empty()){
 	       throw EErroPersistencia("Lista de resultados vazia.");
   		}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		estado.setEstado(resultado.getValorColuna());

		acomodacao_recuperada.setIdentificadorAcomodacao(idAcomodacao);
		acomodacao_recuperada.setTipoAcomodacao(tipo);
		acomodacao_recuperada.setCapacidadeAcomodacao(capacidade);
		acomodacao_recuperada.setNomeCidadeAcomodacao(cidade);
		acomodacao_recuperada.setEstadoAcomodacao(estado);

		listaAcomodacao.push_back(acomodacao_recuperada);
	}	

	listaResultado.clear();
	return listaAcomodacao;
}

//---------------------------------------------------------------------------
//Classe ComandoProcuraAcomodacao.
ComandoProcuraAcomodacao :: ComandoProcuraAcomodacao(Identificador id) {
	containerAcomodacao = "SELECT Identificador, Tipo, Capacidade, Cidade, Estado, Diaria FROM Acomodacoes WHERE IdentificadorUsuario = ";
	containerAcomodacao += '\'' + id.getIdentificador() + '\'';
}

list<Acomodacao> ComandoProcuraAcomodacao :: getResultado() throw (EErroPersistencia){
	list<Acomodacao> listaAcomodacao;
	ElementoResultado resultado;
	Acomodacao acomodacao_recuperada;
	Identificador idAcomodacao_recuperado;
	TipoDeAcomodacao tipo_recuperado;
	CapacidadeDeAcomodacao capacidade_recuperada;
	Nome cidade_recuperada;
	Estado estado_recuperado;
	Diaria diaria_recuperada;

	while(!listaResultado.empty()){
		// Remove Identificador
		if (listaResultado.empty()){
 	       throw EErroPersistencia("Lista de resultados vazia.");
   		}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		idAcomodacao_recuperado.setIdentificador(resultado.getValorColuna());
		acomodacao_recuperada.setIdentificadorAcomodacao(idAcomodacao_recuperado);
		cout << "Identificador: " << idAcomodacao_recuperado.getIdentificador() << endl;
		
		// Remove Tipo
		if (listaResultado.empty()){
     	   throw EErroPersistencia("Lista de resultados vazia.");
    	}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		tipo_recuperado.setTipoDeAcomodacao(resultado.getValorColuna());
		acomodacao_recuperada.setTipoAcomodacao(tipo_recuperado);
		cout << "Tipo: " << tipo_recuperado.getTipoDeAcomodacao() << endl;

		// Remove Capacidade
		if (listaResultado.empty()){
     	   throw EErroPersistencia("Lista de resultados vazia.");
    	}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		capacidade_recuperada.setCapacidade(stoi(resultado.getValorColuna()));
		acomodacao_recuperada.setCapacidadeAcomodacao(capacidade_recuperada);
		cout << "Capacidade: " << capacidade_recuperada.getCapacidade() << endl;

		// Remove Nome
		if (listaResultado.empty()){
     	   throw EErroPersistencia("Lista de resultados vazia.");
    	}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		cidade_recuperada.setNome(resultado.getValorColuna());
		acomodacao_recuperada.setNomeCidadeAcomodacao(cidade_recuperada);
		cout << "Cidade: " << cidade_recuperada.getNome() << endl;

		// Remove Estado
		if (listaResultado.empty()){
     	   throw EErroPersistencia("Lista de resultados vazia.");
    	}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		estado_recuperado.setEstado(resultado.getValorColuna());
		acomodacao_recuperada.setEstadoAcomodacao(estado_recuperado);
		cout << "Estado: " << estado_recuperado.getEstado() << endl;

		// Remove Diaria
		if (listaResultado.empty()){
     	   throw EErroPersistencia("Lista de resultados vazia.");
    	}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		diaria_recuperada.setDiaria(stof(resultado.getValorColuna()));
		acomodacao_recuperada.setDiariaAcomodacao(diaria_recuperada);
		cout << "Diaria: " << diaria_recuperada.getDiaria() << endl;

		// Insere na lista de disponibilidades
		
		listaAcomodacao.push_back( acomodacao_recuperada );
	}

	listaResultado.clear();
	return listaAcomodacao;
}

//---------------------------------------------------------------------------
// Classe ComandoVerificaAcomodacaoPertenceUsuario

ComandoVerificaAcomodacaoPertenceUsuario :: ComandoVerificaAcomodacaoPertenceUsuario (Identificador id, Identificador idAcomodacao){
	containerAcomodacao = "SELECT Identificador FROM Acomodacoes WHERE Identificador = ";
	containerAcomodacao += '\'' + idAcomodacao.getIdentificador() + '\'';
	containerAcomodacao += " AND IdentificadorUsuario = ";
	containerAcomodacao += '\'' + id.getIdentificador() + '\'';
}

bool ComandoVerificaAcomodacaoPertenceUsuario :: getResultado() throw (EErroPersistencia){
	bool resultado;

	if(listaResultado.empty()){
		resultado = false;
	}
	else{
		resultado = true;
	}

	listaResultado.clear();
	return resultado;
}

//---------------------------------------------------------------------------
// Classe ComandoCadastrarDisponibilidade

ComandoCadastrarDisponibilidade :: ComandoCadastrarDisponibilidade (Identificador idAcomodacao, Disponibilidade disponibilidade){
	containerDisponibilidade += "INSERT INTO Disponibilidades VALUES (";
	containerDisponibilidade += '\'' + idAcomodacao.getIdentificador() + "', ";
	containerDisponibilidade += '\'' + disponibilidade.getDataInicioDisponibilidade().getData() + "', ";
	containerDisponibilidade += '\'' + disponibilidade.getDataTerminoDisponibilidade().getData() + "')";
}

//---------------------------------------------------------------------------
// Classe ComandoPesquisarDisponibilidade

ComandoPesquisarDisponibilidade :: ComandoPesquisarDisponibilidade (Identificador idAcomodacao){
	containerDisponibilidade += "SELECT DataInicio, DataTermino FROM Disponibilidades WHERE IdentificadorAcomodacao = ";
	containerDisponibilidade += '\'' + idAcomodacao.getIdentificador() + '\'';
}

list<Disponibilidade> ComandoPesquisarDisponibilidade :: getResultado() throw (EErroPersistencia){
	list<Disponibilidade> listaDisponibilidade;
	ElementoResultado resultado;
	Data dataInicio_recuperada;
	Data dataTermino_recuperada;
	Disponibilidade disponibilidade_recuperada;

	while(!listaResultado.empty()){
		// Remove DataInicio
		if (listaResultado.empty()){
 	       throw EErroPersistencia("Lista de resultados vazia.");
   		}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		dataInicio_recuperada.setData(resultado.getValorColuna());
		disponibilidade_recuperada.setDataInicioDisponibilidade(dataInicio_recuperada);
		// cout << "Data inicio: " << dataInicio_recuperada.getData() << endl;
		
		// Remove DataTermino
		if (listaResultado.empty()){
     	   throw EErroPersistencia("Lista de resultados vazia.");
    	}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		dataTermino_recuperada.setData(resultado.getValorColuna());
		disponibilidade_recuperada.setDataTerminoDisponibilidade(dataTermino_recuperada);
		// cout << "Data termino: " << dataTermino_recuperada.getData() << endl;

		// Insere na lista de disponibilidades
		
		listaDisponibilidade.push_back( disponibilidade_recuperada );
	}

	listaResultado.clear();
	return listaDisponibilidade;
}

//---------------------------------------------------------------------------
//Classe ComandoDescadastrarAcomodacao.

ComandoDescadastrarAcomodacao :: ComandoDescadastrarAcomodacao(Identificador idAcomodacao) {
        containerAcomodacao = "DELETE FROM Acomodacoes WHERE Identificador = ";
        containerAcomodacao += '\'' + idAcomodacao.getIdentificador() + '\'';
}

//---------------------------------------------------------------------------
// Classe ComandoDescadastrarDisponibilidade

ComandoDescadastrarDisponibilidade :: ComandoDescadastrarDisponibilidade (Identificador idAcomodacao, Disponibilidade disponibilidade){
	containerDisponibilidade = "DELETE FROM Disponibilidades WHERE IdentificadorAcomodacao = ";
	containerDisponibilidade += '\'' + idAcomodacao.getIdentificador() + '\'';
	containerDisponibilidade += " AND DataInicio = ";
	containerDisponibilidade += '\'' + disponibilidade.getDataInicioDisponibilidade().getData() + '\'';
	containerDisponibilidade += " AND DataTermino = ";
	containerDisponibilidade += '\'' + disponibilidade.getDataTerminoDisponibilidade().getData() + '\'';
}

//---------------------------------------------------------------------------
// Classe ComandoDescadastrarTodasDisponibilidadesAcomodacao

ComandoDescadastrarTodasDisponibilidadesAcomodacao :: ComandoDescadastrarTodasDisponibilidadesAcomodacao (Identificador idAcomodacao){
	containerDisponibilidade = "DELETE FROM Disponibilidades WHERE IdentificadorAcomodacao = ";
	containerDisponibilidade += '\'' + idAcomodacao.getIdentificador() + '\'';
}

//---------------------------------------------------------------------------
// Classe ComandoCadastrarReserva

ComandoCadastrarReserva :: ComandoCadastrarReserva (Identificador id, Identificador idAcomodacao, Reserva reserva){
	containerReserva = "INSERT INTO Reservas VALUES (";
	containerReserva += "'" + id.getIdentificador() + "', ";
	containerReserva += "'" + idAcomodacao.getIdentificador() + "', ";
	containerReserva += "'" + reserva.getDataInicioReserva().getData() + "', ";
	containerReserva += "'" + reserva.getDataTerminoReserva().getData() + "')";
}

//---------------------------------------------------------------------------
// Classe ComandoPesquisaReserva

ComandoPesquisaReserva :: ComandoPesquisaReserva (Identificador idAcomodacao){
	containerReserva = "SELECT DataInicio, DataTermino FROM Reservas WHERE IdentificadorAcomodacao = ";
	containerReserva += '\'' + idAcomodacao.getIdentificador() + '\'';
}

list<Reserva> ComandoPesquisaReserva :: getResultado () throw (EErroPersistencia){
	list<Reserva> listaReservas;
	ElementoResultado resultado;
	Data dataInicio_recuperada;
	Data dataTermino_recuperada;
	Reserva reserva_recuperada;

	while(!listaResultado.empty()){
		// Remove DataInicio
		if (listaResultado.empty()){
 	       throw EErroPersistencia("Lista de resultados vazia.");
   		}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		dataInicio_recuperada.setData(resultado.getValorColuna());
		reserva_recuperada.setDataInicioReserva(dataInicio_recuperada);
		// cout << "Data inicio: " << dataInicio_recuperada.getData() << endl;
		
		// Remove DataTermino
		if (listaResultado.empty()){
     	   throw EErroPersistencia("Lista de resultados vazia.");
    	}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		dataTermino_recuperada.setData(resultado.getValorColuna());
		reserva_recuperada.setDataTerminoReserva(dataTermino_recuperada);
		// cout << "Data termino: " << dataTermino_recuperada.getData() << endl;

		// Insere na lista de disponibilidades
		
		listaReservas.push_back( reserva_recuperada );
	}

	listaResultado.clear();
	return listaReservas;
} 

//---------------------------------------------------------------------------
//Classe ComandoProcuraReserva.

ComandoProcuraReserva :: ComandoProcuraReserva(Identificador id) {
	containerReserva = "SELECT DataInicio, DataTermino FROM Reservas WHERE IdentificadorUsuario = ";
	containerReserva += '\'' + id.getIdentificador() + '\'';
}

list<Reserva> ComandoProcuraReserva :: getResultado() throw (EErroPersistencia){
	list<Reserva> listaReservas;
	ElementoResultado resultado;
	Reserva reserva_recuperada;
	//Identificador idAcomodacao_recuperado;
	Data dataInicio_recuperada;
	Data dataTermino_recuperada;

	while(!listaResultado.empty()){
		// Remove DataInicio
		if (listaResultado.empty()){
     	   throw EErroPersistencia("Lista de resultados vazia.");
    	}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		dataInicio_recuperada.setData(resultado.getValorColuna());
		reserva_recuperada.setDataInicioReserva(dataInicio_recuperada);
		cout << "DataInicio: " << dataInicio_recuperada.getData() << endl;

		// Remove DataTermino
		if (listaResultado.empty()){
     	   throw EErroPersistencia("Lista de resultados vazia.");
    	}
		resultado = listaResultado.back();
		listaResultado.pop_back();
		dataTermino_recuperada.setData(resultado.getValorColuna());
		reserva_recuperada.setDataTerminoReserva(dataTermino_recuperada);
		cout << "DataTermino: " << dataTermino_recuperada.getData() << endl;

		// Insere na lista de reservas
		
		listaReservas.push_back( reserva_recuperada );
	}

	listaResultado.clear();
	return listaReservas;
}

//---------------------------------------------------------------------------
//Classe Controle Servico Autenticacao.

int CntrServAutenticacao :: autenticar(Identificador *id, Senha *senha){
	int resultado;
	string senha_recuperada;

	ComandoLerSenha comandoLerSenha(id);

	try{
		comandoLerSenha.executar();
		senha_recuperada = comandoLerSenha.getResultado();
	} 
	catch(EErroPersistencia exp){
		cout << endl << exp.what();
		cout << endl << endl << "Digite algo para continuar.";
		// getch();
	}
	
    if (senha_recuperada == senha->getSenha()){
		cout << endl << "Autenticado com sucesso" << endl;
    	resultado = SUCESSO;
    }

    else{
    	resultado = FALHA;
    }

	return resultado;
}

//---------------------------------------------------------------------------
//Classe Controle Servico Usuario.

int CntrServUsuario :: cadastrar(Nome* nome, Identificador* identificador, Senha* senha){
	Usuario usuario;
	Usuario usuario_recuperado;

	usuario.setNomeUsuario(*nome);
	usuario.setIdentificadorUsuario(*identificador);
	usuario.setSenhaUsuario(*senha);

	// Verificar se a id já está cadastrada
	ComandoPesquisarUsuario comandoPesquisar (*identificador);
	
	try{
		comandoPesquisar.executar();
		usuario_recuperado = comandoPesquisar.getResultado();
	}
	catch (EErroPersistencia){
		cout << "Erro" << endl;
		return FALHA;
	}

	// Caso verifique que o usuário ainda não foi cadastrado
	if(usuario_recuperado.getNomeUsuario().getNome().size() == 0 &&
	   usuario_recuperado.getIdentificadorUsuario().getIdentificador().size() == 0 &&
	   usuario_recuperado.getSenhaUsuario().getSenha().size() == 0){
		
		ComandoCadastrarUsuario comando (usuario);
		
		try{
			comando.executar();
		}
		catch (EErroPersistencia){
			cout << "Erro no cadastro" << endl;
			return FALHA;
		}
   	}
	else{
		return USUARIO_JA_CADASTRADO;
	}

	return SUCESSO;
}

int CntrServUsuario :: descadastrarUsuario(Identificador* id){

}

int CntrServUsuario :: cadastrarContaCorrente(Identificador* identificador, NumeroDeContaCorrente* conta, Agencia* agencia, Banco* banco){
	ContaCorrente contaCorrente;
	ContaCorrente contaCorrente_recuperada;

	contaCorrente.setNumeroContaCorrente(*conta);
	contaCorrente.setAgenciaContaCorrente(*agencia);
	contaCorrente.setBancoContaCorrente(*banco);

	// Verificar se já existe uma conta corrente cadastrada
	ComandoPesquisarContaCorrente comandoPesquisar(*identificador);
	
	try{
		comandoPesquisar.executar();
		contaCorrente_recuperada = comandoPesquisar.getResultado();
	}
	catch (EErroPersistencia){
		cout << "Erro" << endl;
		return FALHA;
	}

	// Se não encontra uma conta corrente já cadastrada
	if(contaCorrente_recuperada.getNumeroContaCorrente().getNumeroDeContaCorrente().size() == 0 &&
	   contaCorrente_recuperada.getAgenciaContaCorrente().getAgencia().size() == 0 &&
	   contaCorrente_recuperada.getBancoContaCorrente().getBanco().size() == 0){

		ComandoCadastrarContaCorrente comando (*identificador, contaCorrente);
		
		try{
			comando.executar();
		}
		catch (EErroPersistencia){
			cout << "Erro no cadastro" << endl;
			return FALHA;
		}

		return SUCESSO;
   	}
	else{
		return CONTA_CORRENTE_JA_CADASTRADA;
	}

}

int CntrServUsuario :: descadastrarContaCorrente(Identificador* id){
int resultado;
	list<Acomodacao> listaAcomodacao;

	ComandoProcuraAcomodacao comandoProcura(*id);

	try{
		comandoProcura.executar();
		listaAcomodacao = comandoProcura.getResultado();

	}
	catch (EErroPersistencia){
		resultado = FALHA;
	}


	if(listaAcomodacao.empty()){
		
		ComandoDescadastrarContaCorrente comando (*id);
		
		try{
			comando.executar();
		}
		catch (EErroPersistencia){
			resultado = FALHA;
		}

		resultado = SUCESSO;
   	}
	else{

		resultado = ACOMODACAO_AINDA_CADASTRADA;
	}

	return resultado;
}

int CntrServUsuario :: cadastrarCartaoDeCredito(Identificador* id, NumeroDeCartaoDeCredito* cartao, DataDeValidade* dataDeValidade){
	CartaoDeCredito cartaoDeCredito;
	CartaoDeCredito cartaoDeCredito_recuperado;

	cartaoDeCredito.setNumeroCartaoCredito(*cartao);
	cartaoDeCredito.setDataDeValidadeCartaoDeCredito(*dataDeValidade);

	ComandoPesquisarCartaoDeCredito comandoPesquisar(*id);

	try{
		comandoPesquisar.executar();
		cartaoDeCredito_recuperado = comandoPesquisar.getResultado();
	}
	catch (EErroPersistencia){
		cout << "Erro" << endl;
		return FALHA;
	}

	// Se não encontra um cartao de credito ja cadastrado

	if(cartaoDeCredito_recuperado.getNumeroCartaoCredito().getNumeroDeCartaoDeCredito().size() == 0 &&
	   cartaoDeCredito_recuperado.getDataDeValidadeCartaoDeCredito().getDataDeValidade().size() == 0){
		
		ComandoCadastrarCartaoDeCredito comando(*id, cartaoDeCredito);
		
		try{
			comando.executar();
		}
		catch (EErroPersistencia){
			cout << "Erro no cadastro" << endl;
			return FALHA;
		}

		return SUCESSO;
   	}
	else{
		return CARTAO_DE_CREDITO_JA_CADASTRADO;
	}
}

int CntrServUsuario :: descadastrarCartaoDeCredito(Identificador* id){
	int resultado;
	list<Reserva> listaReservas;

	ComandoProcuraReserva comandoProcura(*id);

	try{
		comandoProcura.executar();
		listaReservas = comandoProcura.getResultado();

	}
	catch (EErroPersistencia){
		resultado = FALHA;
	}


	if(listaReservas.empty()){
		
		ComandoDescadastrarCartaoDeCredito comando (*id);
		
		try{
			comando.executar();
		}
		catch (EErroPersistencia){
			resultado = FALHA;
		}

		resultado = SUCESSO;
   	}
	else{

		resultado = RESERVA_AINDA_CADASTRADA;
	}

	return resultado;
}


int CntrServAcomodacao :: cadastrar(Identificador *id, Identificador *idAcomodacao, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade){
	int resultado;
	Acomodacao acomodacao;
	ContaCorrente contaCorrente_recuperada;

	acomodacao.setIdentificadorAcomodacao(*idAcomodacao);
	acomodacao.setTipoAcomodacao(*tipo);
	acomodacao.setCapacidadeAcomodacao(*capacidade);
	acomodacao.setDiariaAcomodacao(*preco);
	acomodacao.setEstadoAcomodacao(*estado);
	acomodacao.setNomeCidadeAcomodacao(*cidade);

	// Verifica se existe uma conta corrente associada ao usuário
	ComandoPesquisarContaCorrente comandoPesquisar(*id);
	try{
		comandoPesquisar.executar();
		contaCorrente_recuperada = comandoPesquisar.getResultado();
	}
	catch (EErroPersistencia){
		cout << "Erro" << endl;
		return FALHA;
	}
	
	// Verifica se a id da acomodacao ja foi utilizada
	ComandoVerificaExclusividadeIdentificadorAcomodacao comandoVerificaIdentificador (*idAcomodacao);

	try{
		comandoVerificaIdentificador.executar();
		resultado = comandoVerificaIdentificador.getResultado();
		if (resultado == true){ // true: identificador ja utilizado
			return ID_ACOMODACAO_JA_UTILIZADO;
		}
	}
	catch (EErroPersistencia){
		cout << "Erro" << endl;
		return FALHA;
	}

	// Se recuperou alguma conta corrente, então pode cadastrar acomodação
	if(contaCorrente_recuperada.getNumeroContaCorrente().getNumeroDeContaCorrente().size() != 0 &&
	   contaCorrente_recuperada.getAgenciaContaCorrente().getAgencia().size() != 0 &&
	   contaCorrente_recuperada.getBancoContaCorrente().getBanco(). size() != 0){

		ComandoCadastrarAcomodacao comando (*id, acomodacao);
	
		try{
			comando.executar();
			resultado = SUCESSO;
		}
		catch (EErroPersistencia){
			cout << "Erro no cadastro" << endl;
			resultado = FALHA;
		}
	}
	else{
		resultado = CONTA_CORRENTE_AUSENTE;	
	}
	
	return resultado;	
}

int CntrServAcomodacao :: consultar(Identificador *id, Data *dataInicio, Data *dataTermino, CapacidadeDeAcomodacao *capacidade, Nome *cidade, Estado* estado){
	list<Acomodacao> listaAcomodacao;
	list<Acomodacao> :: iterator it;
	Acomodacao acomodacao_recuperada;

	ComandoPesquisaAcomodacao comandoPesquisar (*id, *dataInicio, *dataTermino, *capacidade, *cidade, *estado);
	try{
		comandoPesquisar.executar();
		listaAcomodacao = comandoPesquisar.getResultado();
		if(listaAcomodacao.empty()){
			return ACOMODACAO_NAO_ENCONTRADA;
		}
		else{
			for(it = listaAcomodacao.begin(); it != listaAcomodacao.end(); ++it){
				acomodacao_recuperada = *it;
				cout << "++" << acomodacao_recuperada.getIdentificadorAcomodacao().getIdentificador() << endl;
			}
		}
	}
	catch (EErroPersistencia){

	}
}

int CntrServAcomodacao :: descadastrar(Identificador *id, Identificador *idAcomodacao){
	int resultado;
	int IDAcomodacao_recuperado;

	ComandoVerificaAcomodacaoPertenceUsuario comandoAcomodacao(*id , *idAcomodacao);
	ComandoDescadastrarAcomodacao comando(*idAcomodacao);


	try{
		comandoAcomodacao.executar();
		IDAcomodacao_recuperado = comandoAcomodacao.getResultado();

		if(IDAcomodacao_recuperado == true){
			comando.executar();
			resultado = SUCESSO;
		}
		else if (IDAcomodacao_recuperado == false) {
			resultado = NAO_ANFITRIAO;
		}	

	}
	catch (EErroPersistencia) {
		resultado = FALHA;
	}

	cout << "Resultado: " << resultado << endl;
	return resultado;
}

int CntrServAcomodacao :: reservar(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino){
	int resultado;
	list<Disponibilidade> listaDisponibilidade;
	list<Disponibilidade> ::iterator it;
	Disponibilidade disponibilidadeOriginal;
	Reserva reserva;
	Data dataAnteriorReserva;
	Data dataPosteriorReserva;
	Data inicioDisponibilidadeOriginal;
	Data terminoDisponibilidadeOriginal;

	// A ação de reservar pode quebrar um intervalo de dispobilidade em até 2 partes
	Data inicioDisponibilidadeModificadaEsquerda;
	Data terminoDisponibilidadeModificadaEsquerda;
	Disponibilidade disponibilidadeModificadaEsquerda;

	Data inicioDisponibilidadeModificadaDireita;
	Data terminoDisponibilidadeModificadaDireita;
	Disponibilidade disponibilidadeModificadaDireita;

	// Preenche o objeto Reserva
	reserva.setDataInicioReserva(*dataInicio);
	reserva.setDataTerminoReserva(*dataTermino);
	
	dataAnteriorReserva = dataInicio->getDataAnterior();
	dataPosteriorReserva = dataTermino->getDataAnterior();
	
	ComandoVerificaAcomodacaoPertenceUsuario comandoVerificaPropriedadeDaAcomodacao (*id, *idAcomodacao);
	try{
		comandoVerificaPropriedadeDaAcomodacao.executar();
		resultado = comandoVerificaPropriedadeDaAcomodacao.getResultado();
		if(resultado == true){
			return ACOMODACAO_PERTECE_USUARIO;
		}
	}
	catch (EErroPersistencia){
		resultado = FALHA;
	}

	ComandoPesquisaIDAcomodacao comandoPesquisaAcomodacao (*idAcomodacao);
	try{
		comandoPesquisaAcomodacao.executar();
		resultado = comandoPesquisaAcomodacao.getResultado();
		if(resultado == false){
			return ACOMODACAO_INEXISTENTE;
		}
	}
	catch (EErroPersistencia){
		resultado = FALHA;
	}

	ComandoPesquisarDisponibilidade comandoPesquisar (*idAcomodacao);

	try{
		comandoPesquisar.executar();
		listaDisponibilidade = comandoPesquisar.getResultado();
		listaDisponibilidade.sort(Ordenacao :: comparacao);
		if(listaDisponibilidade.empty()){
			return ACOMODACAO_NAO_DISPONIVEL;
		}
		else{
			for(it = listaDisponibilidade.begin(); it != listaDisponibilidade.end(); ++it){
				disponibilidadeOriginal = *it;
				cout << "^^^^"<< disponibilidadeOriginal.getDataInicioDisponibilidade().getData() << endl;
				inicioDisponibilidadeOriginal = disponibilidadeOriginal.getDataInicioDisponibilidade();
				terminoDisponibilidadeOriginal = disponibilidadeOriginal.getDataTerminoDisponibilidade();
				
				if(true){
				if(!(Data :: comparaDatas(*dataInicio, inicioDisponibilidadeOriginal) == -1) &&
				     !(Data :: comparaDatas(*dataTermino, terminoDisponibilidadeOriginal) == 1)){
					cout << "Reserva dentro do intervalo:" << endl;
					cout << disponibilidadeOriginal.getDataInicioDisponibilidade().getData() << endl;
					cout << disponibilidadeOriginal.getDataTerminoDisponibilidade().getData() << endl;

					ComandoCadastrarReserva comandoCadastrar (*id, *idAcomodacao, reserva);

					try{
						comandoCadastrar.executar();
					}
					catch (EErroPersistencia){
						
					}
					
					ComandoDescadastrarDisponibilidade comandoDescadastrar (*idAcomodacao, disponibilidadeOriginal);

					try{
						comandoDescadastrar.executar();
					}
					catch (EErroPersistencia){

					}
					
					// Caso: Reserva ocupa todo o intervalo de disponibilidade
					if ((Data :: comparaDatas(*dataInicio, inicioDisponibilidadeOriginal) == 0) &&
					    (Data :: comparaDatas(*dataTermino, terminoDisponibilidadeOriginal) == 0)){
						cout << "Reserva ocupar o intervalo fechado" << endl;
						// Sem nova disponibilidade
					}

					// Caso: Reserva começa no extremo inicial do intervalo de disponibilidade
					else if ((Data :: comparaDatas(*dataInicio, inicioDisponibilidadeOriginal) == 0) &&
					         (Data :: comparaDatas(*dataTermino, terminoDisponibilidadeOriginal) == -1)){
						cout << "Reserva no extremo inicial do intervalo" << endl;
						
						// Deve gerar uma nova disponibilidade que fica a direita, na linha temporal, do intervalo reservado
						inicioDisponibilidadeModificadaDireita = dataTermino->getDataPosterior();
						terminoDisponibilidadeModificadaDireita = terminoDisponibilidadeOriginal;

						cout << "Novo intervalo:" << endl;
						cout << inicioDisponibilidadeModificadaDireita.getData() << endl;
						cout << terminoDisponibilidadeModificadaDireita.getData() << endl;
						
						disponibilidadeModificadaDireita.setDataInicioDisponibilidade ( inicioDisponibilidadeModificadaDireita );
						disponibilidadeModificadaDireita.setDataTerminoDisponibilidade ( terminoDisponibilidadeModificadaDireita );

						//  Cadastrar o intervalo de disponibilidade que é devolvido para as Disponibilidades; o que sobre da reserva
						ComandoCadastrarDisponibilidade comandoCadastrar (*idAcomodacao, disponibilidadeModificadaDireita);

						try{
							comandoCadastrar.executar();
						}
						catch (EErroPersistencia){

						}
					}

					// Caso: Reserva termina no extremo final do intervalo de disponibilidade
					else if((Data :: comparaDatas(*dataInicio, inicioDisponibilidadeOriginal) == 1) &&
					        (Data :: comparaDatas(*dataTermino, terminoDisponibilidadeOriginal) == 0)){
						cout << "Reverva no extremo final do intervalo" << endl;

						// Deve gerar uma nova disponibilidade que fica a esquerda, na linha temporal, do intervalo reservado
						inicioDisponibilidadeModificadaEsquerda = inicioDisponibilidadeOriginal;
						terminoDisponibilidadeModificadaEsquerda = dataInicio->getDataAnterior();

						cout << "Novo intervalo:" << endl;
						cout << inicioDisponibilidadeModificadaEsquerda.getData() << endl;
						cout << terminoDisponibilidadeModificadaEsquerda.getData() << endl;

						disponibilidadeModificadaEsquerda.setDataInicioDisponibilidade ( inicioDisponibilidadeModificadaEsquerda );
						disponibilidadeModificadaEsquerda.setDataTerminoDisponibilidade ( terminoDisponibilidadeModificadaEsquerda );

						//  Cadastrar o intervalo de disponibilidade que é devolvido para as Disponibilidades; o que sobre da reserva
						ComandoCadastrarDisponibilidade comandoCadastrar (*idAcomodacao, disponibilidadeModificadaEsquerda);

						try{
							comandoCadastrar.executar();
						}
						catch (EErroPersistencia){

						}
					}
					else{
						cout << "Reserva no interior do intervalo, exceto os extremos" << endl;

						// Deve gerar duas novas disponibilidades, a esquerda e a direita, na linha temporal, do intervalo reservado
						inicioDisponibilidadeModificadaEsquerda = inicioDisponibilidadeOriginal;
						terminoDisponibilidadeModificadaEsquerda = dataInicio->getDataAnterior();

						inicioDisponibilidadeModificadaDireita = dataTermino->getDataPosterior();
						terminoDisponibilidadeModificadaDireita = terminoDisponibilidadeOriginal;

						cout << "Novo intervalo (esquerdo)"	<< endl;
						cout << inicioDisponibilidadeModificadaEsquerda.getData() << endl;
						cout << terminoDisponibilidadeModificadaEsquerda.getData() << endl;

						disponibilidadeModificadaEsquerda.setDataInicioDisponibilidade ( inicioDisponibilidadeModificadaEsquerda );
						disponibilidadeModificadaEsquerda.setDataTerminoDisponibilidade ( terminoDisponibilidadeModificadaEsquerda );

						cout << "Novo intervalo (direito)"	<< endl;
						cout << inicioDisponibilidadeModificadaDireita.getData() << endl;
						cout << terminoDisponibilidadeModificadaDireita.getData() << endl;

						disponibilidadeModificadaDireita.setDataInicioDisponibilidade( inicioDisponibilidadeModificadaDireita );
						disponibilidadeModificadaDireita.setDataTerminoDisponibilidade( terminoDisponibilidadeModificadaDireita );

						//  Cadastrar os intervalos de disponibilidade que sao devolvidos para as Disponibilidades; o que sobre da reserva
						ComandoCadastrarDisponibilidade comandoCadastrarEsquerda (*idAcomodacao, disponibilidadeModificadaEsquerda);
						try{
							comandoCadastrarEsquerda.executar();
						}
						catch (EErroPersistencia){

						}

						ComandoCadastrarDisponibilidade comandoCadastrarDireita (*idAcomodacao, disponibilidadeModificadaDireita);
						try{
							comandoCadastrarDireita.executar();
						}
						catch (EErroPersistencia){

						}

					}
				
					resultado =  SUCESSO;	
					break;
				}
				}
			}

			// Se chegar no final e o resultado não for sucesso, então a acomodacao nao esta disponivel no periodo desejado
			if (resultado != SUCESSO){
				resultado = ACOMODACAO_INDISPONIVEL_NO_PERIODO;
			}
		}
	}
	catch (ElementoResultado){
		cout << "Erro aqui" << endl;
		resultado = FALHA;
	}

	return resultado;
}

int CntrServAcomodacao :: cancelar(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino){

}

int CntrServAcomodacao :: cadastrarDisp(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino){
	int resultado;
	bool houveUniao;

	list<Reserva> listaReservasCadastradas;
	list<Reserva> :: iterator it_reserva;
	Reserva reserva_recuperada;

	list<Disponibilidade> listaDisponibilidade;
	list<Disponibilidade> :: iterator it;
	list<Disponibilidade> :: iterator it_proximo;
	list<Disponibilidade> :: iterator it_auxiliar;
	list<Disponibilidade> :: iterator it_print;
	Disponibilidade novaDisponibilidade;
	Disponibilidade disponibilidadeX;
	Disponibilidade disponibilidadeY;

	novaDisponibilidade.setDataInicioDisponibilidade(*dataInicio);
	novaDisponibilidade.setDataTerminoDisponibilidade(*dataTermino);

	// Verifica se a acomodacao realmente pertence ao usuário
	ComandoVerificaAcomodacaoPertenceUsuario comandoVerificaPropriedadeDaAcomodacao (*id, *idAcomodacao);

	try{
		comandoVerificaPropriedadeDaAcomodacao.executar();
		resultado = comandoVerificaPropriedadeDaAcomodacao.getResultado();
		if(resultado == false){ //false: usuario nao e dono da acomodacao
			return ACOMODACAO_NAO_PERTECE_USUARIO;
		}
	}
	catch (ElementoResultado){
		resultado = FALHA;
	}

	// Verifica se o período desejado para cadastramento de disponibilidade já está reservado
	ComandoPesquisaReserva comandoPesquisaReserva (*idAcomodacao);
	try{
		comandoPesquisaReserva.executar();
		listaReservasCadastradas = comandoPesquisaReserva.getResultado();
		if(!listaReservasCadastradas.empty()){
			for(it_reserva = listaReservasCadastradas.begin(); it_reserva != listaReservasCadastradas.end(); ++it_reserva){
				reserva_recuperada = *it_reserva;
				// PENSAR NAS CONDIÇÕES DISSO AQUI
				if(!(((Data :: comparaDatas(novaDisponibilidade.getDataInicioDisponibilidade(), reserva_recuperada.getDataInicioReserva()) == 1) && 
				      (Data :: comparaDatas(novaDisponibilidade.getDataInicioDisponibilidade(), reserva_recuperada.getDataTerminoReserva()) == 1)) ||
					 ((Data :: comparaDatas(novaDisponibilidade.getDataTerminoDisponibilidade(), reserva_recuperada.getDataInicioReserva()) == -1) &&
					  (Data :: comparaDatas(novaDisponibilidade.getDataTerminoDisponibilidade(), reserva_recuperada.getDataTerminoReserva()) == -1)))){
					// Se o início da disponibilidade cadastrada não for maior que o inicio e o termino da reserva ou
					// Se o término da disponibilidae cadastrada não for menor que o incio e o termino da reserva
					// Entao o intervalo de disponibilidade coincide com o intervalo de reserva
					
					return DISPONIBILIDADE_NAO_DISPONIVEL;
				}
			}
		}
	}
	catch (ElementoResultado){
		resultado = FALHA;
	}

	// Recupera todas as disponibilidades já cadastradas, insere a nova e ordena
	ComandoPesquisarDisponibilidade comandoRecuperaDisponibilidade (*idAcomodacao);
	try{
		comandoRecuperaDisponibilidade.executar();
		listaDisponibilidade = comandoRecuperaDisponibilidade.getResultado();
		listaDisponibilidade.push_back(novaDisponibilidade);
		listaDisponibilidade.sort(Ordenacao :: comparacao);
	}
	catch (ElementoResultado){
		resultado = FALHA;
	}

	// Une os intervalos de disponibilidade
	houveUniao = false;
	for(it = listaDisponibilidade.begin(); it != listaDisponibilidade.end(); ){
		disponibilidadeX = *it;
		cout << "--" << disponibilidadeX.getDataInicioDisponibilidade().getData() << endl;
		it_proximo = it;
		++it_proximo;
		if (it_proximo != listaDisponibilidade.end()){
			// Então podemos comparar o conteudo de it_proximo com o de it para verificar qual o tipo de relação entre
			// os intervalos e realizar as operações necessárias para juntá-los
			// Cuidado, pois a relação é definida entre a segunda disponibilidade (Y: it_proximo) e a primeira(X: it)
			// Tais casos não possuem propriedade comutativa

			disponibilidadeY = *it_proximo;			
			cout << "Compara:" << endl;
			cout << disponibilidadeX.getDataInicioDisponibilidade().getData() << " " << disponibilidadeX.getDataTerminoDisponibilidade().getData() << endl;
			cout << disponibilidadeY.getDataInicioDisponibilidade().getData() << " " << disponibilidadeY.getDataTerminoDisponibilidade().getData() << endl;

			// Caso: Intervalo adjacente a esquerda		
			if((Data :: comparaDatas(disponibilidadeX.getDataInicioDisponibilidade().getDataAnterior(), disponibilidadeY.getDataTerminoDisponibilidade()) == 0)){
				// Se a data anterior ao inicio da primeira disponibilidade for igual ao termino da segunda disponibilidade
				// Então é o caso: INTERVALO ADJACENTE A ESQUERDA
				cout << "Intervalo adjacente a esquerda" << endl;

			}

			// Caso: Intervalo adjacente a direita		
			else if((Data :: comparaDatas(disponibilidadeX.getDataTerminoDisponibilidade().getDataPosterior(), disponibilidadeY.getDataInicioDisponibilidade()) == 0)){
				// Se a data posterior ao termino da primeira disponibilidade for igual ao inicio da segunda disponibilidade
				// Então é o caso: INTERVALO ADJACENTE A DIREITA

				cout << "Intervalo adjacente a direita" << endl;
				cout << it->getDataTerminoDisponibilidade().getData() << '=' << it_proximo->getDataTerminoDisponibilidade().getData() << endl;
				it->setDataTerminoDisponibilidade(it_proximo->getDataTerminoDisponibilidade());
				// cout << it->getDataTerminoDisponibilidade().getData() << '=' << it_proximo->getDataTerminoDisponibilidade().getData() << endl;

				cout << "tam " << listaDisponibilidade.size() << endl;
				for(it_print = listaDisponibilidade.begin(); it_print != listaDisponibilidade.end(); ++it_print){
					cout << it_print->getDataInicioDisponibilidade().getData() << ' ' << it_print->getDataTerminoDisponibilidade().getData() << endl;
				}

				// Apaga it_proximo
				listaDisponibilidade.erase(it_proximo);
				cout << "tam " << listaDisponibilidade.size() << endl;
				for(it_print = listaDisponibilidade.begin(); it_print != listaDisponibilidade.end(); ++it_print){
					cout << it_print->getDataInicioDisponibilidade().getData() << ' ' << it_print->getDataTerminoDisponibilidade().getData() << endl;
				}
			}

			// Caso: Intervalo parcialmente coincidente a esquerda
			else if(!(Data :: comparaDatas(disponibilidadeX.getDataInicioDisponibilidade(), disponibilidadeY.getDataTerminoDisponibilidade()) == 1) &&
			        !(Data :: comparaDatas(disponibilidadeX.getDataTerminoDisponibilidade(), disponibilidadeY.getDataTerminoDisponibilidade()) == -1) &&
					 (Data :: comparaDatas(disponibilidadeX.getDataInicioDisponibilidade(), disponibilidadeY.getDataInicioDisponibilidade()) == 1)){
				// Se o inicio da primeira disponibilidade for menor ou igual ao termino da segunda disponibilidade
				// E se o termino da primeira disponibilidade for maior ou igual ao termino da segunda disponibilidade
				// E se ,além disso, o inicio da primeira disponibilidade for maior que o inicio da segunda
				// Então o caso é INTERVALO PARCIALMENTE COINCIDENTE A ESQUERDA
				cout << "Caso: Intervalo parcialmente coincidente a esquerda" << endl;
			}

			// Caso: Intervalo parcialmente coincidente a direita
			else if(!(Data :: comparaDatas(disponibilidadeX.getDataInicioDisponibilidade(), disponibilidadeY.getDataInicioDisponibilidade()) == 1) &&
			        !(Data :: comparaDatas(disponibilidadeX.getDataTerminoDisponibilidade(), disponibilidadeY.getDataInicioDisponibilidade()) == -1) &&
					 (Data :: comparaDatas(disponibilidadeX.getDataTerminoDisponibilidade(), disponibilidadeY.getDataTerminoDisponibilidade()) == -1)){
				// Se o inicio da primeira disponibilidade for menor ou igual ao inicio da segunda disponiblidade
				// E se o termino da primeira disponibilidade for maior ou igual ao inicio da segunda disponibilidade
				// E se, além disso, o termino da primeira disponibilidade for menor que o termino da primeira
				// Então o caso é INTERVALO PARCIALMENTE COINCIDENTE A DIREITA

				cout << "Intervalo parcialmente coincidente a direita" << endl;
				cout << it->getDataTerminoDisponibilidade().getData() << '=' << it_proximo->getDataTerminoDisponibilidade().getData();
				it->setDataTerminoDisponibilidade(it_proximo->getDataTerminoDisponibilidade());
				
				cout << "tam " << listaDisponibilidade.size() << endl;
				for(it_print = listaDisponibilidade.begin(); it_print != listaDisponibilidade.end(); ++it_print){
					cout << it_print->getDataInicioDisponibilidade().getData() << endl;
					cout << it_print->getDataTerminoDisponibilidade().getData() << endl;
				}

				// Apaga it_proximo
				listaDisponibilidade.erase(it_proximo);
				cout << "tam " << listaDisponibilidade.size() << endl;
				for(it_print = listaDisponibilidade.begin(); it_print != listaDisponibilidade.end(); ++it_print){
					cout << it_print->getDataInicioDisponibilidade().getData() << endl;
					cout << it_print->getDataTerminoDisponibilidade().getData() << endl;
				}
				
			}

			// Caso: Intervalo totalmente coincidente interno
			else if(!(Data :: comparaDatas(disponibilidadeX.getDataInicioDisponibilidade(), disponibilidadeY.getDataInicioDisponibilidade()) == 1) &&
					 !(Data :: comparaDatas(disponibilidadeX.getDataTerminoDisponibilidade(), disponibilidadeY.getDataTerminoDisponibilidade()) == -1)){
				// Se o inicio da primeira disponibilidade for menor ou igual que o inicio da segunda disponibilidade
				// E se o termino da primeira disponibilidade for maior ou igual que o termino da segunda disponibilidade
				// Então o caso é INTERVALO TOTALMENTE COINCIDENTE INTERNO
				cout << "Intervalo totalmente coincidente interno" << endl;

				// Apagar o it_proximo
			}

			// Caso: Intervalo totalmente coincidente externo
			else if((Data :: comparaDatas(disponibilidadeX.getDataInicioDisponibilidade(), disponibilidadeY.getDataInicioDisponibilidade()) == 1) &&
					(Data :: comparaDatas(disponibilidadeX.getDataTerminoDisponibilidade(), disponibilidadeY.getDataTerminoDisponibilidade()) == -1)){
				// Se o inicio da primeira disponibilidade for menor que o inicio da segunda disponibilidade
				// E se o termino da primeira disponibilidade for menor que o termino da segunda disponibilidade
				// Então o caso é INTERVALO TOTALMENTE COINCIDENTE EXTERNO
				cout << "Intervalo totalmente coincidente externo" << endl;
			}
			
			// Caso: Intervalo nao coincidente nem adjacente
			else if(((Data :: comparaDatas(disponibilidadeX.getDataInicioDisponibilidade(), disponibilidadeY.getDataTerminoDisponibilidade()) == 1)) ||
			  	    ((Data :: comparaDatas(disponibilidadeX.getDataTerminoDisponibilidade(), disponibilidadeY.getDataInicioDisponibilidade()) == -1))){
				// Se inicio da primeira disponibilidade for maior que o termino da segunda
				// Ou se o termino da primeira disponibilidade for menor que o inicio da segunda
				// Então é o caso INTERVALO NAO COINCIDENTE NEM ADJACENTE
				// OBS.: Já foi verificado que não é adjacente em uma estrutura condicional acima
				
				// Avança o ponteiro it
				++it;
				cout << "Nao ha união" << endl;
			}

			char c = getchar();
		}
		
		// Verifica se o proximo do proximo é o final da lista. Encerra o loop se for verdade.
		it_auxiliar = it_proximo;
		++it_auxiliar;
		if(it_auxiliar == listaDisponibilidade.end()){
			cout << "Chegou no final da lista" << endl;
			break;
		}

		
		
	}

	// Se houve uniao de algum intervalo, remove todas as disponibilidades do banco de dados da acomodação
	// liberando espaço para a inserção da lista de disponibilidades atualizada, ou seja,
	// com os intervalos de disponibilidade já unidos
	// Isso só não acontece, quando se cadastrar uma disponibilidade que não intercepta nenhum outro intervalo previamente cadastrado
	if(false){//houveUniao == true;
		ComandoDescadastrarTodasDisponibilidadesAcomodacao comandoDescadastrarTodasDisponibilidades (*idAcomodacao);
		try{
			// comandoDescadastrarTodasDisponibilidades.executar();
		}
		catch (ElementoResultado){
			resultado = FALHA;
		}
	}

	// Cadastra a disponibilidade
	/*
	ComandoCadastrarDisponibilidade comando (*idAcomodacao, disponibilidade);

	try{
		comando.executar();
		resultado = SUCESSO;
	}
	catch (ElementoResultado){
		resultado = FALHA;
	}
	*/
	return resultado;
}

int CntrServAcomodacao :: descadastrarDisp(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino){
	int resultado;
	Disponibilidade disponibilidade_descadastrada;

	// ComandoDescadastrarDisponibilidade (*id, );
}