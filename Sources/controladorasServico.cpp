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

int CntrServUsuario :: descadastrar(Identificador* id){
	//Verifica os requisitos de descadastramento...
	//Autentica novamento
	int resultado = servidorAutenticacao->autenticar(id);
}