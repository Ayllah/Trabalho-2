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

	return cartaoDeCredito;
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

	return resultado;
}

//---------------------------------------------------------------------------
// Classe ComandoVerificaAcomodacaoPertenceUsuario

ComandoVerificaAcomodacaoPertenceUsuario :: ComandoVerificaAcomodacaoPertenceUsuario (Identificador id, Identificador idAcomodacao){
	containerAcomodacao += "SELECT Identificador FROM Acomodacoes WHERE Identificador = ";
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
// Classe ComandoVerificaAcomodacaoPossuiDisponibilidade

ComandoVerificaAcomodacaoPossuiDisponibilidade :: ComandoVerificaAcomodacaoPossuiDisponibilidade (Identificador idAcomodacao){
	containerDisponibilidade += "SELECT IdentificadorAcomodacao FROM Disponibilidades WHERE IdentificadorAcomodacao = ";
	containerDisponibilidade += '\'' + idAcomodacao.getIdentificador() + '\'';
}

bool ComandoVerificaAcomodacaoPossuiDisponibilidade :: getResultado() throw (EErroPersistencia){
	bool resultado;

	if(listaResultado.empty()){
			resultado = false;
		}
	else{
			resultado = true;
		}

	return resultado;
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

	ComandoDescadastrarContaCorrente comando (*id);

	try{
		comando.executar();
		resultado = SUCESSO;
	}
	catch (EErroPersistencia) {
		resultado = FALHA;
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

int CntrServAcomodacao :: consultar(Identificador *id, Data *dataInicio, Data *dataTermino){

}

int CntrServAcomodacao :: descadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade){
}

int CntrServAcomodacao :: reservar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){

}

int CntrServAcomodacao :: cancelar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){

}

int CntrServAcomodacao :: cadastrarDisp(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino){
	int resultado;
	Disponibilidade disponibilidade;

	disponibilidade.setDataInicioDisponibilidade(*dataInicio);
	disponibilidade.setDataTerminoDisponibilidade(*dataTermino);

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

	// Verifica se a acomodação já tem uma disponibilidade
	ComandoVerificaAcomodacaoPossuiDisponibilidade comandoAcomodacaoPossuiDisponibilidade (*idAcomodacao);
	
	try{
		comandoAcomodacaoPossuiDisponibilidade.executar();
		resultado = comandoAcomodacaoPossuiDisponibilidade.getResultado();
		if(resultado == true){ //false: usuario nao e dono da acomodacao
			return ACOMODACAO_JA_TEM_DISPONIBILIDADE;
		}
	}
	catch (ElementoResultado){
		resultado = FALHA;
	}

	// Cadastra a disponibilidade
	ComandoCadastrarDisponibilidade comando (*idAcomodacao, disponibilidade);

	try{
		comando.executar();
		resultado = SUCESSO;
	}
	catch (ElementoResultado){
		resultado = FALHA;
	}
	
	return resultado;
}

int CntrServAcomodacao :: descadastrarDisp(Identificador *id, Identificador *idAcomodacao, Data *dataInicio, Data *dataTermino){
}