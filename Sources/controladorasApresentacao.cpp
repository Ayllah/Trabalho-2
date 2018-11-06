#include "controladorasApresentacao.h"

int CntrAprAutenticacao :: autenticar(Identificador *id) throw(runtime_error) {
	string entrada;
	Senha* senha = new Senha();
	int resultado;

	//Perguntar id e senha

	while(true){
		cout << endl << "Autenticacao de Usuário." << endl << endl;

		try{
			cout << "Digite seu ID: " << endl; //pedro
			cin >> entrada;
			id->setIdentificador(entrada);
			cout << "Digite sua senha: " << endl; //1a3A567$
			cin >> entrada;
			senha->setSenha(entrada);
			break;
		}
		catch (const invalid_argument &exp) {
            cout << endl << "Formato invalido! Tente novamente." << endl;
        }
	}

	//Solicitar autenticacao

	resultado = servidor->autenticar(id,senha);

	return resultado;
}

int CntrAprUsuario :: painelConta(Identificador *id) throw(runtime_error){
	string opcao;
	int resultado;
	string entrada;

	Agencia* agencia = new Agencia();
	Banco* banco = new Banco();
	NumeroDeContaCorrente* numeroDeContaCorrente = new NumeroDeContaCorrente();
	NumeroDeCartaoDeCredito* numeroDeCartaoDeCredito = new NumeroDeCartaoDeCredito();
	DataDeValidade* dataDeValidade = new DataDeValidade();

	while(true){
		cout << "-------------- Minha Conta ---------------" << endl;
		cout << EDITAR << " - Editar Perfil de Usuário" << endl;
		cout << CADASTRAR_CONTA_CORRENTE << " - Cadastrar uma conta corrente" << endl;
		cout << DESCADASTRAR_CONTA_CORRENTE << " - Descadastrar minha conta corrente" << endl;
		cout << CADASTRAR_CARTAO_CREDITO << " - Cadastrar um cartão de crédito" << endl;
		cout << DESCADASTRAR_CARTAO_CREDITO << " - Descastrar meu cartão de crédito" << endl;
		cout << DESCADASTRAR << " - Descadastrar minha conta"<< endl;
		cout << VOLTAR << " - Voltar" << endl;
		getline(cin, opcao);

		switch(stoi(opcao)){
			case EDITAR:

				break;

			case CADASTRAR_CONTA_CORRENTE:
				while(true){
					cout << endl << "Cadastro de Conta Corrente" << endl << endl;

					try{
						cout << "Digite o número de sua conta corrente: " << endl; //pedro
						cin >> entrada;
						numeroDeContaCorrente->setNumeroDeContaCorrente(entrada);
						cout << "Digite o número de sua agência: " << endl; //1a3A567$
						cin >> entrada;
						agencia->setAgencia(entrada);
						cout << "Digite o código do seu banco: " << endl;
						cin >> entrada;
						banco->setBanco(entrada);
						break;
					}
					catch (const invalid_argument &exp) {
						cout << endl << "Formato invalido! Tente novamente." << endl;
					}	
				}
				
				// Chamar servidor

				break;

			case DESCADASTRAR_CONTA_CORRENTE:
				while(true){
					cout << "Deseja remover a conta corrente associada à sua conta?" << endl;
					cout << SIM << " - Sim" << endl;
					cout << NAO << " - Não" << endl;
					cin >> entrada;
					
					for(int i = 0; i < entrada.size(); ++i){
						entrada[i] = toupper(entrada[i]);
					}

					if(entrada == to_string(SIM)){
						// chama servidor
						break;
					}
					else if(entrada == to_string(NAO)){
						break;
					}
				}
				break;

			case CADASTRAR_CARTAO_CREDITO:
				while(true){
					cout << endl << "Cadastro de Cartão de Crédito" << endl << endl;

					try{
						cout << "Digite o número de seuu cartão de crédito: " << endl; //pedro
						cin >> entrada;
						numeroDeCartaoDeCredito->setNumeroDeCartaoDeCredito(entrada);
						cout << "Digite a data de validade do seu cartão: " << endl; //1a3A567$
						cin >> entrada;
						dataDeValidade->setDataDeValidade(entrada);
						break;
					}
					catch (const invalid_argument &exp) {
						cout << endl << "Formato invalido! Tente novamente." << endl;
					}	
				}

				//chamar servidor

				break;

			case DESCADASTRAR_CARTAO_CREDITO:
				while(true){
					cout << "Deseja remover o cartão de crédito associada à sua conta?" << endl;
					cout << SIM << " - Sim" << endl;
					cout << NAO << " - Não" << endl;
					cin >> entrada;
					
					for(int i = 0; i < entrada.size(); ++i){
						entrada[i] = toupper(entrada[i]);
					}

					if(entrada == to_string(SIM)){
						// chama servidor
						break;
					}
					else if(entrada == to_string(NAO)){
						break;
					}
				}

				break;

			case DESCADASTRAR:
				
				break;

			case VOLTAR:
				opcao = to_string(VOLTAR);
				break;

			default:
				cout << "Opção inválida" << endl;
				break;
		}

		if(stoi(opcao) == VOLTAR){
			break;
		}
	}

	resultado = 0;
	return resultado;
}

int CntrAprUsuario :: cadastrar(Identificador *id) throw(runtime_error) {
	string opcao;
	int resultado;
	string entrada;
	//string strNome, strIdentificador, strSenha;
	
	Nome* nome = new Nome();
	Identificador* identificador = new Identificador();
	Senha* senha = new Senha();

	cout << endl << "Cadastramento de Usuário." << endl;
	cout << CONTINUAR << " - Continuar" << endl;
	cout << VOLTAR << " - Voltar" << endl;
	getline(cin, opcao);

	switch(stoi(opcao)){
		case CONTINUAR:
			cout << "Nome: ";
			getline(cin, entrada);
			nome->setNome(entrada);

			cout << "Identificador: ";
			getline(cin, entrada);
			identificador->setIdentificador(entrada);

			cout << "Senha: ";
			getline(cin, entrada);
			senha->setSenha(entrada);

			resultado = 0;//chama cadastrar no serviço
			break;

		case VOLTAR:
			return DESISTENCIA;

		default:
			return FALHA;
	}
	
	return resultado;
}

int CntrAprUsuario :: executar (Identificador* id) throw (runtime_error){
	string opcao;
	int resultado;
	bool opcaoInvalida = false;
	
	while(true){
		cout << endl << "Painel Principal" << endl << endl;
		cout << CONTA << " - Minha conta" << endl;
		cout << PESQUISAR << " - Pesquisar usuários" << endl;
		cout << ACOMODACAO << " - Painel de Acomodações" << endl;
		cout << SAIR << " - Sair" << endl;

		getline(cin, opcao);

		switch(stoi(opcao)){
			case CONTA:
				painelConta(id);
				break;

			case PESQUISAR:

				break;
			
			case ACOMODACAO:

				break;

			case SAIR:
				break;

			default:
				cout << "Opção inválida" << endl;
				break;
			}

		if(stoi(opcao) == SAIR){
			break;
		}
	}
	
	return resultado;
};