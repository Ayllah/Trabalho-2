#include "controladorasServico.h"

//Atributo estático container List.

list<ElementoResultado> ContainerUsuario::listaResultado;

//classe EErroPersistencia

EErroPersistencia::EErroPersistencia(string mensagem){
        this->mensagem = mensagem;
}

string EErroPersistencia::what() {
        return mensagem;
}

//classe ElementoResultado

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}

//classe ContainerUsuario

void ContainerUsuario::conectar() throw (EErroPersistencia) {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ContainerUsuario::desconectar() throw (EErroPersistencia) {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");      
}

void ContainerUsuario::executar() throw (EErroPersistencia) {
        conectar();
        
        rc = sqlite3_exec(bd, containerUsuario.c_str(), callback, 0, &mensagem);
        
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
	containerUsuario += "'" + usuario.getNomeUsuario().getNome() + "', ";
	containerUsuario += "'" + usuario.getIdentificadorUsuario().getIdentificador() + "', ";
	containerUsuario += "'" + usuario.getSenhaUsuario().getSenha() + "' , null, null, null, null, null)";
}

//---------------------------------------------------------------------------
//Classe Controle Servico Autenticacao.

int CntrServAutenticacao :: autenticar(Identificador *id, Senha *senha){
	int resultado;
	ContainerUsuario* container = new ContainerUsuario();
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

	usuario.setNomeUsuario(*nome);
	usuario.setIdentificadorUsuario(*identificador);
	usuario.setSenhaUsuario(*senha);

	// Verificar se a id já está cadastrada
	
	ComandoCadastrarUsuario comando (usuario);
	
	try{
		comando.executar();
	}
	catch (EErroPersistencia){
		cout << "Erro" << endl;
		return FALHA;
	}

	return SUCESSO;
}

int CntrServUsuario :: descadastrarUsuario(Identificador* id){

}

int CntrServUsuario :: cadastrarContaCorrente(Identificador* id, NumeroDeContaCorrente* conta, Agencia* agencia, Banco* banco){
}

int CntrServUsuario :: descadastrarContaCorrente(Identificador* id){
}

int CntrServUsuario :: cadastrarCartaoDeCredito(Identificador* id, NumeroDeCartaoDeCredito* cartao, DataDeValidade* dataDeValidade){

}

int CntrServUsuario :: descadastrarCartaoDeCredito(Identificador* id){
}


int CntrServAcomodacao :: cadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade){

}

int CntrServAcomodacao :: consultar(Identificador *id, Data *dataInicio, Data *dataTermino){

}

int CntrServAcomodacao :: descadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade){
}

int CntrServAcomodacao :: reservar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){

}

int CntrServAcomodacao :: cancelar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){

}

int CntrServAcomodacao :: cadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){
}

int CntrServAcomodacao :: descadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){
}

/*
int CntrServAutenticacao :: autenticar(Identificador* id, Senha* senha){
	Senha *senha_recuperada = new Senha();

	//Recuperar senha do repositorio

	if(id->getIdentificador() == "pedro"){
		senha_recuperada->setSenha(senha->getSenha());
	}

	//Comparar senha informada com senha recuperada

	if(senha->getSenha() == senha_recuperada->getSenha()){

		//Retornar resultado da comparacao

		return SUCESSO;
	}

	else{
		return FALHA;
	}

}

int CntrServUsuario :: cadastrar(Nome* nome, Identificador* identificador, Senha* senha){

	return 0;
}

int CntrServUsuario :: descadastrarUsuario(Identificador* id){
	int resultado;
	
	if(id->getIdentificador() == "pedro"){
		resultado = SUCESSO;
	}
	else{
		cout << "falhou" << endl;
		resultado = FALHA;
	}

	return resultado;
}

int CntrServUsuario :: cadastrarContaCorrente(Identificador* id, NumeroDeContaCorrente* conta, Agencia* agencia, Banco* banco){
	int resultado;
	
	NumeroDeContaCorrente* conta_recuperada = new NumeroDeContaCorrente();
	Agencia* agencia_recuperada = new Agencia();
	Banco* banco_recuperado = new Banco();

	// Armazena no Banco de dados
	
	if(id->getIdentificador() == "pedro"){
		conta_recuperada->setNumeroDeContaCorrente(conta->getNumeroDeContaCorrente());
		agencia_recuperada->setAgencia(agencia->getAgencia());
		banco_recuperado->setBanco(banco->getBanco());
	}

	// Comparar os dados informados com os dados recuperados para verificar sucesso no cadastro

	if(conta->getNumeroDeContaCorrente() == conta_recuperada->getNumeroDeContaCorrente() &&
	   agencia->getAgencia() == agencia_recuperada->getAgencia() &&
	   banco->getBanco() == banco_recuperado->getBanco()){

		// Retornar sucesso

		resultado = SUCESSO;
	   }
	
	else{
		resultado = FALHA;
	}

	delete conta_recuperada;
	delete agencia_recuperada;
	delete banco_recuperado;

	return resultado;
}

int CntrServUsuario :: descadastrarContaCorrente(Identificador* id){
	int resultado;
	
	// Busca no BD

	if(id->getIdentificador() == "pedro"){
		resultado = SUCESSO;
	}
	else{
		cout << "falhou" << endl;
		resultado = FALHA;
	}

	return resultado;
}

int CntrServUsuario :: cadastrarCartaoDeCredito(Identificador* id, NumeroDeCartaoDeCredito* cartao, DataDeValidade* dataDeValidade){
	int resultado;
	NumeroDeCartaoDeCredito* cartao_recuperado = new NumeroDeCartaoDeCredito();
	DataDeValidade* dataDeValidade_recuperada = new DataDeValidade();

	// Armazena no Banco de dados

	if(id->getIdentificador() == "pedro"){
		cartao_recuperado->setNumeroDeCartaoDeCredito(cartao->getNumeroDeCartaoDeCredito());
		dataDeValidade_recuperada->setDataDeValidade(dataDeValidade->getDataDeValidade());
	}

	// Comparar os dados informados com os dados recuperados para verificar sucesso no cadastro

	if(cartao->getNumeroDeCartaoDeCredito() == cartao_recuperado->getNumeroDeCartaoDeCredito() &&
	   dataDeValidade->getDataDeValidade() == dataDeValidade_recuperada->getDataDeValidade()){

		// Retornar sucesso

		resultado = SUCESSO;
	   }
	
	else{
		resultado = FALHA;
	}

	return resultado;
}

int CntrServUsuario :: descadastrarCartaoDeCredito(Identificador* id){
	int resultado;
	
	// Busca no BD

	if(id->getIdentificador() == "pedro"){
		resultado = SUCESSO;
	}
	else{
		cout << "falhou" << endl;
		resultado = FALHA;
	}

	return resultado;
}


int CntrServAcomodacao :: cadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade){
	TipoDeAcomodacao *tipo_recuperado = new TipoDeAcomodacao();
	CapacidadeDeAcomodacao *capacidade_recuperada = new CapacidadeDeAcomodacao();
	Diaria *preco_recuperado = new Diaria();
	Estado *estado_recuperado = new Estado();
	Nome *cidade_recuperada = new Nome();

	int resultado;
	
	//Recuperar dados do repositorio

	if(id->getIdentificador() == "pedro"){
		tipo_recuperado->setTipoDeAcomodacao(tipo->getTipoDeAcomodacao());
		capacidade_recuperada->setCapacidade(capacidade->getCapacidade());
		preco_recuperado->setDiaria(preco->getDiaria());
		estado_recuperado->setEstado(estado->getEstado());
		cidade_recuperada->setNome(cidade->getNome());
	}

	//Comparar dados informados com dados recuperados

	if((tipo->getTipoDeAcomodacao() == tipo_recuperado->getTipoDeAcomodacao()) && 
		(capacidade->getCapacidade() == capacidade_recuperada->getCapacidade()) && 
		(preco->getDiaria() == preco_recuperado->getDiaria()) &&
		(estado->getEstado() == estado_recuperado->getEstado()) &&
		(cidade->getNome() == cidade_recuperada->getNome()) ){

		//Retornar resultado da comparacao

		resultado = SUCESSO;
	}

	else{
		resultado = FALHA;
	}

	delete tipo_recuperado;
    delete capacidade_recuperada;
    delete preco_recuperado;
    delete estado_recuperado;
    delete cidade_recuperada;

    return resultado;

}

int CntrServAcomodacao :: consultar(Identificador *id, Data *dataInicio, Data *dataTermino){
	int resultado;
	Acomodacao *acomodacao_recuperada = new Acomodacao(); // Isso deve virar uma lista

	if(id->getIdentificador() == "pedro"){
		acomodacao_recuperada->setDataInicioAcomodacao(*dataInicio);
		acomodacao_recuperada->setDataTerminoAcomodacao(*dataTermino);
	}

	if(dataInicio->getData() == acomodacao_recuperada->getDataInicioAcomodacao().getData() &&
	   dataTermino->getData() == acomodacao_recuperada->getDataTerminoAcomodacao().getData())
	{
		resultado = SUCESSO;
	}

	else
	{
		resultado = FALHA;
	}

	return resultado;
}

int CntrServAcomodacao :: descadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade){
	TipoDeAcomodacao *tipo_recuperado = new TipoDeAcomodacao();
	CapacidadeDeAcomodacao *capacidade_recuperada = new CapacidadeDeAcomodacao();
	Diaria *preco_recuperado = new Diaria();
	Estado *estado_recuperado = new Estado();
	Nome *cidade_recuperada = new Nome();

	int resultado;

	//Recuperar dados do repositorio

	if(id->getIdentificador() == "pedro"){
		tipo_recuperado->setTipoDeAcomodacao(tipo->getTipoDeAcomodacao());
		capacidade_recuperada->setCapacidade(capacidade->getCapacidade());
		preco_recuperado->setDiaria(preco->getDiaria());
		estado_recuperado->setEstado(estado->getEstado());
		cidade_recuperada->setNome(cidade->getNome());
	}

	//Comparar dados informados com dados recuperados

	if((tipo->getTipoDeAcomodacao() == tipo_recuperado->getTipoDeAcomodacao()) && 
		(capacidade->getCapacidade() == capacidade_recuperada->getCapacidade()) && 
		(preco->getDiaria() == preco_recuperado->getDiaria()) &&
		(estado->getEstado() == estado_recuperado->getEstado()) &&
		(cidade->getNome() == cidade_recuperada->getNome()) ){

		//Retornar resultado da comparacao

		resultado = SUCESSO;
	}

	else{
		resultado = FALHA;
	}

	delete tipo_recuperado;
    delete capacidade_recuperada;
    delete preco_recuperado;
    delete estado_recuperado;
    delete cidade_recuperada;

    return resultado;

}

int CntrServAcomodacao :: reservar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){
	Data *data_recuperada = new Data();
	Identificador *id_recuperado = new Identificador();
	TipoDeAcomodacao *tipo_recuperado = new TipoDeAcomodacao();

	int resultado;

	//Recuperar data do repositorio

	if(dataInicio->getData() == "30/jan/2018"){
		data_recuperada->setData(dataTermino->getData());
		id_recuperado->setIdentificador(id->getIdentificador());
		tipo_recuperado->setTipoDeAcomodacao(tipo->getTipoDeAcomodacao());
	}

	//Comparar data informada com data recuperada

	if((dataTermino->getData() == data_recuperada->getData()) && 
		(id->getIdentificador() == id_recuperado->getIdentificador()) &&
		(tipo->getTipoDeAcomodacao() == tipo_recuperado->getTipoDeAcomodacao()) ){

		//Retornar resultado de comparacao

		resultado = SUCESSO;
	}

	else{
		resultado = FALHA;
	}

	delete data_recuperada;
	delete id_recuperado;
	delete tipo_recuperado;

	return resultado;
}

int CntrServAcomodacao :: cancelar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){
	Data *data_recuperada = new Data();
	Identificador *id_recuperado = new Identificador();
	TipoDeAcomodacao *tipo_recuperado = new TipoDeAcomodacao();

	int resultado;

	//Recuperar data do repositorio

	if(dataInicio->getData() == "30/jan/2018"){
		data_recuperada->setData(dataTermino->getData());
		id_recuperado->setIdentificador(id->getIdentificador());
		tipo_recuperado->setTipoDeAcomodacao(tipo->getTipoDeAcomodacao());
	}

	//Comparar data informada com data recuperada

	if((dataTermino->getData() == data_recuperada->getData()) &&
		(id->getIdentificador() == id_recuperado->getIdentificador()) &&
		(tipo->getTipoDeAcomodacao() == tipo_recuperado->getTipoDeAcomodacao()) ){

		//Retornar resultado de comparacao

		resultado = SUCESSO;
	}

	else{
		resultado = FALHA;
	}

	delete data_recuperada;
	delete id_recuperado;
	delete tipo_recuperado;

	return resultado;
}

int CntrServAcomodacao :: cadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){
	Data *data_recuperada = new Data();
	TipoDeAcomodacao *tipo_recuperado = new TipoDeAcomodacao();

	int resultado;
	

	//Recuperar data do repositorio

	if(dataInicio->getData() == "30/jan/2018"){
		data_recuperada->setData(dataTermino->getData());
		tipo_recuperado->setTipoDeAcomodacao(tipo->getTipoDeAcomodacao());
	}

	//Comparar data informada com data recuperada

	if((dataTermino->getData() == data_recuperada->getData()) && 
		(tipo->getTipoDeAcomodacao() == tipo_recuperado->getTipoDeAcomodacao())){

		//Retornar resultado de comparacao

		resultado = SUCESSO;
	}

	else{
		resultado = FALHA;
	}

	delete data_recuperada;
	delete tipo_recuperado;

	return resultado;
}

int CntrServAcomodacao :: descadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){
	Data *data_recuperada = new Data();
	TipoDeAcomodacao *tipo_recuperado = new TipoDeAcomodacao();

	int resultado;

	//Recuperar data do repositorio

	if(dataInicio->getData() == "30/jan/2018"){
		data_recuperada->setData(dataTermino->getData());
		tipo_recuperado->setTipoDeAcomodacao(tipo->getTipoDeAcomodacao());
	}

	//Comparar data informada com data recuperada

	if((dataTermino->getData() == data_recuperada->getData()) && 
		(tipo->getTipoDeAcomodacao() == tipo_recuperado->getTipoDeAcomodacao())){

		//Retornar resultado de comparacao

		resultado = SUCESSO;
	}

	else{
		resultado = FALHA;
	}

	delete data_recuperada;
	delete tipo_recuperado;

	return resultado;
}*/