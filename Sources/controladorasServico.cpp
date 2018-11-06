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

int CntrServUsuario :: descadastrar(Identificador* id){
	char opcao;
	int resultado;

	//IAprAutenticacao* cntr = new CntrAprAutenticacao();
	IServAutenticacao* servidorAutenticacao = new CntrServAutenticacao();
	//cntr->setServidor(servidorAutenticacao);

	cout << "Você deseja realmente se descadastrar?" << endl;
	cout << SIM << " - Sim" << endl;
	cout << NAO << " - Não" << endl;
	cin >> opcao;

	switch(int(opcao)){
		case SIM:
	//		resultado = cntr->autenticar(id);
			break;
		case NAO:
			resultado = DESISTENCIA;
			break;
		default:
			resultado = FALHA;
			break;
	}

	
}