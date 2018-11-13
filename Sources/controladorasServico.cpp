#include "controladorasServico.h"
#include "controladorasApresentacao.h"

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
	int autentica;

	IAprAutenticacao* cntr = new CntrAprAutenticacao();
	IServAutenticacao* servidorAutenticacao = new CntrServAutenticacao();
	cntr->setServidor(servidorAutenticacao);

	// Busca no BD
	autentica = cntr->autenticar(id);

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
