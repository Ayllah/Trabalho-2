#include "controladorasServico.h"

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
}