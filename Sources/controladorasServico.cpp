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

	delete senha_recuperada;

}

int CntrServAcomodacao :: cadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade){
	TipoDeAcomodacao *tipo_recuperado = new TipoDeAcomodacao();
	CapacidadeDeAcomodacao *capacidade_recuperada = new CapacidadeDeAcomodacao();
	Diaria *preco_recuperado = new Diaria();
	Estado *estado_recuperado = new Estado();
	Nome *cidade_recuperada = new Nome();

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

		return SUCESSO;
	}

	else{
		return FALHA;
	}

	delete tipo_recuperado;
    delete capacidade_recuperada;
    delete preco_recuperado;
    delete estado_recuperado;
    delete cidade_recuperada;

}

int CntrServAcomodacao :: descadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade){
	TipoDeAcomodacao *tipo_recuperado = new TipoDeAcomodacao();
	CapacidadeDeAcomodacao *capacidade_recuperada = new CapacidadeDeAcomodacao();
	Diaria *preco_recuperado = new Diaria();
	Estado *estado_recuperado = new Estado();
	Nome *cidade_recuperada = new Nome();

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

		return SUCESSO;
	}

	else{
		return FALHA;
	}

	delete tipo_recuperado;
    delete capacidade_recuperada;
    delete preco_recuperado;
    delete estado_recuperado;
    delete cidade_recuperada;

}

int CntrServAcomodacao :: reservar(Data *dataInicio, Data *dataTermino){
	Data *data_recuperada = new Data();

	//Recuperar data do repositorio

	if(dataInicio->getData() == "30/jan/2018"){
		data_recuperada->setData(dataTermino->getData());
	}

	//Comparar data informada com data recuperada

	if(dataTermino->getData() == data_recuperada->getData()){

		//Retornar resultado de comparacao

		return SUCESSO;
	}

	else{
		return FALHA;
	}

	delete data_recuperada;
}

int CntrServAcomodacao :: cancelar(Data *dataInicio, Data *dataTermino){
	Data *data_recuperada = new Data();

	//Recuperar data do repositorio

	if(dataInicio->getData() == "30/jan/2018"){
		data_recuperada->setData(dataTermino->getData());
	}

	//Comparar data informada com data recuperada

	if(dataTermino->getData() == data_recuperada->getData()){

		//Retornar resultado de comparacao

		return SUCESSO;
	}

	else{
		return FALHA;
	}

	delete data_recuperada;
}

int CntrServAcomodacao :: cadastrarDisp(Data *dataInicio, Data *dataTermino){
	Data *data_recuperada = new Data();

	//Recuperar data do repositorio

	if(dataInicio->getData() == "30/jan/2018"){
		data_recuperada->setData(dataTermino->getData());
	}

	//Comparar data informada com data recuperada

	if(dataTermino->getData() == data_recuperada->getData()){

		//Retornar resultado de comparacao

		return SUCESSO;
	}

	else{
		return FALHA;
	}

	delete data_recuperada;
}

int CntrServAcomodacao :: descadastrarDisp(Data *dataInicio, Data *dataTermino){
	Data *data_recuperada = new Data();

	//Recuperar data do repositorio

	if(dataInicio->getData() == "30/jan/2018"){
		data_recuperada->setData(dataTermino->getData());
	}

	//Comparar data informada com data recuperada

	if(dataTermino->getData() == data_recuperada->getData()){

		//Retornar resultado de comparacao

		return SUCESSO;
	}

	else{
		return FALHA;
	}

	delete data_recuperada;
}