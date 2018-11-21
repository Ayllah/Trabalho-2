#include "controladorasApresentacao.h"
#include "controladorasServico.h" // Porque precisa dessa linha?

//***********************************************************************************************************
// Classe CntrAprAutenticacao

int CntrAprAutenticacao :: autenticar(Identificador *id) throw(runtime_error) {
	string entrada;
	Senha *senha = new Senha();
	int resultado;

	//Perguntar id e senha

		cout << endl << "Autenticacao de Usuario." << endl << endl;

	try{
		cout << "Digite seu ID: " << endl;
		getline(cin, entrada);
		id->setIdentificador(entrada);
		cout << "Digite sua senha: " << endl;
		getline(cin, entrada);
		senha->setSenha(entrada);

		//Solicitar autenticacao
		resultado = servidor->autenticar(id,senha);
	}
	catch (const invalid_argument &exp) {	
		cout << endl << "Formato invalido! Tente novamente." << endl;
		resultado = FALHA;
	}
	
	delete senha;

	return resultado;
}

//***********************************************************************************************************
// Classe CntrAprUsuario

int CntrAprUsuario :: menuMinhaConta(Identificador *id) throw(runtime_error){
	string opcao;
	int resultado;
	string entrada;
	
	IAprAutenticacao *cntrAutenticacao = new CntrAprAutenticacao();
	IServAutenticacao *servidorAutenticacao = new CntrServAutenticacao();
	
	cntrAutenticacao->setServidor(servidorAutenticacao);

	while(true){
		cout << endl << "-------------- Minha Conta ---------------" << endl;
		//cout << EDITAR << " - Editar Perfil de Usuario" << endl;
		cout << MENU_CONTA_CORRENTE << " - Gerenciar Dados da Conta Corrente" << endl;
		cout << MENU_CARTAO_DE_CREDITO << " - Gerenciar Dados do Cartao de Credito" << endl;
		cout << DESCADASTRAR << " - Descadastrar minha conta"<< endl;
		cout << VOLTAR << " - Voltar" << endl;
		cout << "Selecione uma opcao : ";
		
		getline(cin, opcao);

		if(opcao.size() != 0){
			switch(stoi(opcao)){
				case EDITAR:

					break;
				case MENU_CONTA_CORRENTE:
					resultado = menuContaCorrente(id);
					break;

				case MENU_CARTAO_DE_CREDITO:
					resultado = menuCartaoDeCredito(id);
					break;
				/*
				
				
				*/

				case DESCADASTRAR:
					cout << "Para sua seguranca, sera preciso que voce se autentique novamente" << endl;

					resultado = cntrAutenticacao->autenticar(id);
					if(resultado == SUCESSO){
						resultado = descadastrarUsuario(id);
						
						if(resultado == SUCESSO){
							cout << "Usuario removido do sistema" << endl;
							break;
						}				
					}
					else{
						cout << "Falha na autenticacao" << endl;
					}

					
					break;

				case VOLTAR:
					opcao = to_string(VOLTAR);
					break;
			}

			if(stoi(opcao) == VOLTAR){
				break;
			}
		}

	}

	delete cntrAutenticacao;
	delete servidorAutenticacao;

	return resultado;
}

int CntrAprUsuario :: menuContaCorrente(Identificador *id) throw(runtime_error){
	int resultado;
	string opcao;

	while(true){
		cout << endl << "------------- Menu Conta Corrente --------------" << endl;
		cout << CADASTRAR_CONTA_CORRENTE << " - Cadastrar uma conta corrente" << endl;
		// cout << EDITAR_CONTA_CORRENTE << " - Editar os dados da conta corrente" << endl;
		cout << DESCADASTRAR_CONTA_CORRENTE << " - Descadastrar minha conta corrente" << endl;
		cout << VOLTAR << " - Voltar" << endl;
		cout << "Selecione uma opcao : ";

		getline(cin, opcao);

		if(opcao.size() != 0){
			switch(stoi(opcao)){
				case CADASTRAR_CONTA_CORRENTE:

					resultado = cadastrarContaCorrente(id);

					if(resultado == SUCESSO){
						cout << "Conta corrente cadastrada com sucesso!" << endl;
					}
					else if(resultado == CONTA_CORRENTE_JA_CADASTRADA){
						cout << "Ja existe uma conta corrente associada a sua conta." << endl;
					}
					else if(resultado == FALHA){
						cout << "Erro no cadastramento de conta corrente." << endl;
					}
					
					break;

				case DESCADASTRAR_CONTA_CORRENTE:
					resultado = descadastrarContaCorrente(id);

					if(resultado == SUCESSO){
						cout << "Conta corrente REMOVIDA!" << endl;
					}
					else if (resultado == ACOMODACAO_AINDA_CADASTRADA){
						cout << "Erro! Usuario possui acomodacao cadastrada." << endl;
					}
					else if (resultado == FALHA){
						cout << "Erro ao tentar descadastrar conta corrente." << endl;
					}

					break;
			}

			if(stoi(opcao) == VOLTAR){
				break;
			}
		}
	}
	
	return resultado;
}

int CntrAprUsuario :: menuCartaoDeCredito(Identificador *id) throw(runtime_error){
	int resultado;
	string opcao;

	while(true){
		cout << endl << "------------- Menu Cartao de Credito --------------" << endl;
		cout << CADASTRAR_CARTAO_CREDITO << " - Cadastrar um cartao de credito" << endl;
		// cout << EDITAR_CARTA_CREDITO << " - Editar os dados do cartao de credito" << endl;
		cout << DESCADASTRAR_CARTAO_CREDITO << " - Descastrar meu cartao de credito" << endl;
		cout << VOLTAR << " - Voltar" << endl;
		cout << "Selecione uma opcao : ";

		getline(cin, opcao);

		if(opcao.size() != 0){
			switch(stoi(opcao)){
				case CADASTRAR_CARTAO_CREDITO:
				
					resultado = cadastrarCartaoDeCredito(id);

					if(resultado == SUCESSO){
						cout << "Cartão cadastrado com sucesso!" << endl;
					}
					else if(resultado == CARTAO_DE_CREDITO_JA_CADASTRADO){
						cout << "Ja existe um cartao de credito associado a sua conta." << endl;
					}
					else if(resultado == FALHA){
						cout << "Erro no cadastramento de cartao de credito." << endl;
					}

					break;

				case DESCADASTRAR_CARTAO_CREDITO:
					resultado = descadastrarCartaoDeCredito(id);
					if(resultado == SUCESSO){
						cout << "Cartão REMOVIDO!" << endl;
					}
					break;
			}

			if(stoi(opcao) == VOLTAR){
				break;
			}
		}
	}
	
	return resultado;
}

int CntrAprUsuario :: descadastrarUsuario(Identificador *id) throw(runtime_error){
	int resultado;
	int autentica = SUCESSO;
	string entrada;

	while(true){
		cout << "Você realmente deseja se descadastrar do sistema?" << endl;
		cout << SIM << " - Sim" << endl;
		cout << NAO << " - Não" << endl;
		cout << "Selecione uma opcao : ";

		getline(cin, entrada);
		
		for(int i = 0; i < entrada.size(); ++i){
			entrada[i] = toupper(entrada[i]);
		}

		if(entrada[0] == SIM){ // Verificar possibilidade do usuário digitar mais de 1 caracter
			// Busca no BD
			
			resultado = servidor->descadastrarUsuario(id);
			break; 
		}		
		
		else if(entrada[0] == NAO){
			break;
		}

		cout << "Opcao Invalida" << endl;
	}

	return resultado;	
}

int CntrAprUsuario :: cadastrarContaCorrente(Identificador *id) throw(runtime_error){
	int resultado;
	string entrada;

	Agencia *agencia = new Agencia();
	Banco *banco = new Banco();
	NumeroDeContaCorrente *conta = new NumeroDeContaCorrente();


	cout << "__________________________" << endl;
	cout << "Cadastro de Conta Corrente" << endl << endl;

	try{
		cout << "Digite o número de sua conta corrente: " << endl; //pedro
		getline(cin, entrada);
		conta->setNumeroDeContaCorrente(entrada);
		cout << "Digite o número de sua agência: " << endl; //1a3A567$
		getline(cin, entrada);
		agencia->setAgencia(entrada);
		cout << "Digite o código do seu banco: " << endl;
		getline(cin, entrada);
		banco->setBanco(entrada);

		resultado = servidor->cadastrarContaCorrente(id, conta, agencia, banco);
	}
	catch (const invalid_argument &exp) {
		cout << endl << "Formato invalido! Tente novamente." << endl;
		resultado = FALHA;
	}	
	
	delete agencia;
	delete banco;
	delete conta;

	return resultado;
}

int CntrAprUsuario :: descadastrarContaCorrente(Identificador *id) throw(runtime_error){
	int resultado;
	string entrada;

	while(true){
		cout << "Deseja remover a conta corrente associada à sua conta?" << endl;
		cout << SIM << " - Sim" << endl;
		cout << NAO << " - Não" << endl;
		cout << "Selecione uma opcao : ";

		getline(cin, entrada);
		
		for(int i = 0; i < entrada.size(); ++i){
			entrada[i] = toupper(entrada[i]);
		}

		if(entrada[0] == SIM){ // ideal era não precisar usar o [0]
			resultado = servidor->descadastrarContaCorrente(id);
			break;
		}
		else if(entrada[0] == NAO){
			break;
		}

		cout << "Opcao Invalida" << endl;
	}

	return resultado;
}

int CntrAprUsuario :: cadastrarCartaoDeCredito(Identificador *id) throw(runtime_error){
	int resultado;
	string entrada;

	NumeroDeCartaoDeCredito *cartao = new NumeroDeCartaoDeCredito();
	DataDeValidade *dataDeValidade = new DataDeValidade();


	cout << "_____________________________" << endl;
	cout << "Cadastro de Cartao de credito" << endl << endl;
	
	try{
		cout << "Digite o número de seuu cartao de credito: " << endl;
		getline(cin, entrada);
		cartao->setNumeroDeCartaoDeCredito(entrada);
		cout << "Digite a data de validade do seu cartao: " << endl;
		getline(cin, entrada);
		dataDeValidade->setDataDeValidade(entrada);

		resultado = servidor->cadastrarCartaoDeCredito(id, cartao, dataDeValidade);
	}
	catch (const invalid_argument &exp) {
		cout << endl << "Formato invalido! Tente novamente." << endl;
		resultado = FALHA;
	}	
	
	delete cartao;
	delete dataDeValidade;

	return resultado;
}

int CntrAprUsuario :: descadastrarCartaoDeCredito(Identificador *id) throw(runtime_error){
	int resultado;
	string entrada;

	while(true){
		cout << "Deseja remover o cartao de credito associado a sua conta?" << endl;
		cout << SIM << " - Sim" << endl;
		cout << NAO << " - Não" << endl;
		cout << "Selecione uma opcao : ";

		getline(cin, entrada);
		
		for(int i = 0; i < entrada.size(); ++i){
			entrada[i] = toupper(entrada[i]);
		}

		if(entrada[0] == SIM){
			resultado = servidor->descadastrarCartaoDeCredito(id);
			break;
		}
		else if(entrada[0] == NAO){
			break;
		}

		cout << "Opcao Invalida" << endl;
	}

	return resultado;
}

int CntrAprUsuario :: cadastrar(Identificador *id) throw(runtime_error) {
	string opcao;
	int resultado;
	string entrada;
	
	Nome *nome = new Nome();
	Identificador *identificador = new Identificador();
	Senha *senha = new Senha();

	cout << "_________________________" << endl;
	cout << "Cadastramento de Usuario." << endl;

	try{
		cout << "Digite seu nome: ";
		getline(cin, entrada);
		nome->setNome(entrada);

		cout << "Digite seu identificador. Ele sera usado para acessar sua conta.: ";
		getline(cin, entrada);
		identificador->setIdentificador(entrada);

		cout << "Digite sua senha: ";
		getline(cin, entrada);
		senha->setSenha(entrada);

	}
	catch (const invalid_argument &exp) {
		cout << endl << "Formato invalido! Tente novamente." << endl;
	}

	resultado = servidor->cadastrar(nome, identificador, senha); //chama cadastrar no serviço
	
	if (resultado == SUCESSO){
			cout << "Usuario cadastrado com sucesso!" << endl;
		}
	else if (resultado == FALHA){
		cout << "Falha no cadastramento. Tente novamente mais tarde." << endl; 
	}
	else if (resultado == USUARIO_JA_CADASTRADO){
		cout << "Identificador ja utilizado por outro usuario." << endl;
	}

	delete nome;
	delete identificador;
	delete senha;

	return resultado;
}

int CntrAprUsuario :: executar (Identificador *id) throw (runtime_error){
	string opcao;
	int resultado;
	bool opcaoInvalida = false;

	IAprAcomodacao *cntrAcomodacao = new CntrAprAcomodacao();
	IServAcomodacao *servidorAcomodacao = new CntrServAcomodacao();
	
	cntrAcomodacao->setServidor(servidorAcomodacao);

	while(true){
		cout << endl << "Painel Principal" << endl << endl;
		cout << CONTA << " - Minha conta" << endl;
		cout << PESQUISAR << " - Pesquisar Acomodacoes" << endl;
		cout << ACOMODACAO << " - Painel de Acomodacoes" << endl;
		cout << SAIR << " - Sair" << endl;
		cout << "Selecione uma opcao : ";

		getline(cin, opcao);
		
		if(opcao.size() != 0){
			switch(stoi(opcao)){
				case CONTA:
					resultado = menuMinhaConta(id);
					break;

				case PESQUISAR:
					resultado = cntrAcomodacao->consultar(id);					
					break;
				
				case ACOMODACAO:
					resultado = cntrAcomodacao->executar(id);
					break;

				case SAIR:
					break;

				default:
					cout << "Opcao Invalida" << endl;
					break;
			}
		
		
			if(stoi(opcao) == SAIR){
				break;
			}
		}
		
	}

	return resultado;
}

// **********************************************************************************
// Classe CntrAprAcomodacao

int CntrAprAcomodacao :: consultar(Identificador *id){
	int resultado;
	string entrada;
	Data *dataInicio = new Data();
	Data *dataTermino = new Data();
	CapacidadeDeAcomodacao *capacidade = new CapacidadeDeAcomodacao();
	Nome *nomeCidade = new Nome();
	Estado *estado = new Estado();

	try{
		cout << endl << "Janela de Pesquisa de Acomodacoes" << endl << endl;

		cout << "Digite a data de início do intervalo de pesquisa: " << endl;
		getline(cin, entrada);
		dataInicio->setData(entrada);
		cout << "Digite a data final do intervalo de pesquisa: " << endl;
		getline(cin, entrada);
		dataTermino->setData(entrada);
		cout << "Digite a capacidade mínima da acomodacao:" << endl;
		getline(cin, entrada);
		capacidade->setCapacidade(stoi(entrada));
		cout << "Digite o nome da cidade na qual a acomodacao esta localizada:" << endl;
		getline(cin, entrada);
		nomeCidade->setNome(entrada);
		cout << "Digite a sigla da UF da cidade na qual a acomodacao esta localizada:" << endl;
		getline(cin, entrada);
		estado->setEstado(entrada);
	}
	catch (const invalid_argument &exp) {
		cout << endl << "Formato invalido! Tente novamente." << endl;
	}

	resultado = servidor->consultar(id, dataInicio, dataTermino, capacidade, nomeCidade, estado);
	
	if(resultado == ACOMODACAO_NAO_ENCONTRADA){
		cout << "Busca nao encontrou nenhuma acomodacao" << endl;
	}

	delete dataInicio;
	delete dataTermino;
	delete capacidade;
	delete nomeCidade;
	delete estado;

	return resultado;
}

int CntrAprAcomodacao :: executar(Identificador *id) {
	string opcao;
    int resultado;

	while(true){

		cout << endl << "Painel de Acomodacao:" << endl << endl;

        cout << CADASTRAR_ACOMODACAO << " - Cadastrar Acomodacao         " << endl;
        cout << DESCADASTRAR_ACOMODACAO << " - Descadastrar Acomodacao      " << endl;
        cout << RESERVAR_ACOMODACAO << " - Reservar Acomodacao          " << endl;
        cout << CANCELAR_RESERVA << " - Cancelar Reserva             " << endl;
        cout << CADASTRAR_DISPONIBILIDADE << " - Cadastrar Disponibilidade    " << endl;
        cout << DESCADASTRAR_DISPONIBILIDADE << " - Descadastrar Disponibilidade " << endl;
        cout << RETORNAR << " - Retornar                     " << endl << endl;
        cout << "Selecione uma opcao : ";

        getline(cin, opcao);

		if(opcao.size() != 0){
			switch(stoi(opcao)){
				case CADASTRAR_ACOMODACAO:          
					resultado = cadastrar(id);
					
					if(resultado == SUCESSO){
						cout << "Acomodacao cadastrada com sucesso" << endl;
					}
					else if (resultado == ID_ACOMODACAO_JA_UTILIZADO){
						cout << "O identificador escolhido ja pertence a alguma acomodacao." << endl;
						cout << "Por favor, tente outro" << endl;
					}
					else if(resultado == CONTA_CORRENTE_AUSENTE){
						cout << "Você nao tem uma conta corrente associada a sua conta." << endl;
						cout << "Por favor, cadastre uma antes que você possa cadastrar suas acomodacoes." << endl;
					}

					break;

				case DESCADASTRAR_ACOMODACAO:       
					resultado = descadastrar(id);
					
					break;

				case RESERVAR_ACOMODACAO:           
					resultado = reservar(id);
					if (resultado == SUCESSO){
						cout << "Reserva realizada com sucesso!" << endl;
					}
					else if (resultado == ACOMODACAO_INEXISTENTE) {
						cout << "Nao encontramos nenhum acomodacao com esse identificador" << endl;
					}
					else if (resultado == ACOMODACAO_PERTECE_USUARIO){
						cout << "Voce nao pode reservar sua propria acomodacao." << endl;
					}
					else if (resultado == ACOMODACAO_NAO_DISPONIVEL){
						cout << "Esta acomodacao esta indisponivel no momento." << endl;
					}
					else if (resultado == ACOMODACAO_INDISPONIVEL_NO_PERIODO){
						cout << "Esta acomodacao nao esta disponivel no periodo desejado. Por favor, tente outro perido." << endl;
					}
					else if (resultado == FALHA){
						cout << "Erro no cadastro da reserva. Por favor, tente novamente mais tarde." << endl;
					}
					
					break;

				case CANCELAR_RESERVA:              
					resultado = cancelar (id);
					
					break;

				case CADASTRAR_DISPONIBILIDADE:     
					resultado = cadastrarDisp(id);

					if (resultado == SUCESSO){
						cout << "Disponibilidade cadastrada com sucesso." << endl;
					}
					else if (resultado == ACOMODACAO_NAO_PERTECE_USUARIO){
						cout << "Nao encontramos uma acomodacao, com esse identificador, cadastrada por voce." << endl;
					}
					else if(resultado == DISPONIBILIDADE_NAO_DISPONIVEL){
						cout << "O periodo desejado ja esta reservado. Por favor, aguarde o fim da reserva." << endl;
					}
					else if (resultado == ACOMODACAO_JA_TEM_DISPONIBILIDADE){
						cout << "Esta acomodacao ja tem uma disponibilidade" << endl;
					}
					else if (resultado == FALHA){
						cout << "Nao foi possivel cadastrar sua disponibilidade." << endl;
					}

					break;

				case DESCADASTRAR_DISPONIBILIDADE:  
					resultado = descadastrarDisp(id);
					
					break;
			}

			if(stoi(opcao) == RETORNAR){
				break;
			}
		}
	}

	return resultado;
}

int CntrAprAcomodacao :: cadastrar(Identificador *id) throw(runtime_error) {
    Identificador *idAcomodacao = new Identificador();
	TipoDeAcomodacao *tipo = new TipoDeAcomodacao();
    CapacidadeDeAcomodacao *capacidade =  new CapacidadeDeAcomodacao();
    Diaria *preco = new Diaria();
    Estado *estado = new Estado();
    Nome *cidade = new Nome();

    // OBS: Para cadastrar e preciso ter conta corrente

    string entrada;
    int resultado;

	cout << endl << "Cadastro de Acomodacao." << endl << endl;

	try{
		cout << "Digite o identificador de sua acomodacao: " << endl;
		getline(cin, entrada);
		idAcomodacao->setIdentificador(entrada);
		cout << "Digite o tipo de acomodacao (flat, apartamento ou casa): " << endl;
		getline(cin, entrada);
		tipo->setTipoDeAcomodacao(entrada);
		cout << "Digite a capacidade de sua acomodacao (1 a 9): " << endl;
		getline(cin, entrada);
		capacidade->setCapacidade(stoi(entrada));
		cout << "Digite o valor da diaria: (R$ 1,00 a R$ 10.000,00)" << endl;
		getline(cin, entrada);
		preco->setDiaria(stof(entrada));
		cout << "Digite o Estado onde se encontra a acomodacao (sigla): " << endl;
		getline(cin, entrada);
		estado->setEstado(entrada);
		cout << "Digite a cidade onde se encontra a acomodacao: " << endl;
		getline(cin, entrada);
		cidade->setNome(entrada);
	
		resultado = servidor->cadastrar(id, idAcomodacao, tipo, capacidade, preco, estado, cidade);	
	}
	catch (const invalid_argument &exp) {
		cout << endl << "Formato invalido! Tente novamente." << endl;
		resultado = FALHA;
	}

    delete tipo;
    delete capacidade;
    delete preco;
    delete estado;
    delete cidade;

    return resultado;

}

int CntrAprAcomodacao :: descadastrar(Identificador *id) throw(runtime_error){
    TipoDeAcomodacao *tipo = new TipoDeAcomodacao();
    CapacidadeDeAcomodacao *capacidade =  new CapacidadeDeAcomodacao();
    Diaria *preco = new Diaria();
    Estado *estado = new Estado();
    Nome *cidade = new Nome();

    //OBS: Somente o anfitriao pode descadastrar a acomodacao.
    //     Uma acomodacao nao pode ser descadastrada se estiver reservada.

    string entrada;
    int resultado;

	cout << endl << "Descadastro de Acomodacao." << endl << endl;

	try{
		cout << "Digite seu ID: " << endl;
		getline(cin, entrada);
		id->setIdentificador(entrada);
		cout << "Digite o tipo de acomodacao (flat, apartamento ou casa): " << endl;
		getline(cin, entrada);
		tipo->setTipoDeAcomodacao(entrada);
		cout << "Digite a capacidade de acomodacao (1 a 9): " << endl;
		getline(cin, entrada);
		capacidade->setCapacidade(stoi(entrada));
		cout << "Digite o valor da diaria: (R$ 1,00 a R$ 10.000,00)" << endl;
		getline(cin, entrada);
		preco->setDiaria(stof(entrada));
		cout << "Digite o Estado onde se encontra a acomodacao (sigla): " << endl;
		getline(cin, entrada);
		estado->setEstado(entrada);
		cout << "Digite a cidade onde se encontra a acomodacao: " << endl;
		getline(cin, entrada);
		cidade->setNome(entrada);
		
		resultado = servidor->descadastrar(id, tipo, capacidade, preco, estado, cidade);
	}
	catch (const invalid_argument &exp) {
		cout << endl << "Formato invalido! Tente novamente." << endl;
		resultado = FALHA;
	}
    
    delete tipo;
    delete capacidade;
    delete preco;
    delete estado;
    delete cidade;

    return resultado;

}

int CntrAprAcomodacao :: reservar(Identificador *id) throw(runtime_error){
    Data *dataInicio = new Data();
    Data *dataTermino = new Data();
    Identificador *idAcomodacao = new Identificador();

    // OBS: Para reservar e preciso ter cartao de credito

    string entrada;
    int resultado;

	cout << endl << "Reserva de Acomodacao." << endl << endl;

	try{
		cout << "Digite o identificador da acomodacao que voce deseja reservar: " << endl; 
		getline(cin, entrada);
		idAcomodacao->setIdentificador(entrada);
		cout << "Digite a data de inicio da reserva (DD/MMM/AAAA): " << endl;
		getline(cin, entrada);
		dataInicio->setData(entrada);
		cout << "Digite a data de termino da reserva (DD/MMM/AAAA): " << endl; 
		getline(cin, entrada);
		dataTermino->setData(entrada);

		resultado = servidor->reservar(id, idAcomodacao, dataInicio, dataTermino);
	}
	catch (const invalid_argument &exp) {
		cout << endl << "Formato invalido! Tente novamente." << endl;
		resultado = FALHA;
	}

    delete dataInicio;
    delete dataTermino;
    delete idAcomodacao;

    return resultado;

}

int CntrAprAcomodacao :: cancelar(Identificador *id) throw(runtime_error){
    Data *dataInicio = new Data();
    Data *dataTermino = new Data();
    Identificador *idAcomodacao = new Identificador();

    // OBS: Uma reserva pode ser cancelada, desde que a data de cancelamento anteceda o período da reserva.

    string entrada;
    int resultado;

	cout << endl << "Cancelamento de Reserva." << endl << endl;

	try{
		cout << "Digite a ID da acomodacao que esta reserva e você deseja cancelar a reserva: " << endl; //pedro
		getline(cin, entrada);
		idAcomodacao->setIdentificador(entrada);
		cout << "Digite a data de inicio da reserva (DD/MMM/AAAA): " << endl;
		getline(cin, entrada);
		dataInicio->setData(entrada);
		cout << "Digite a data de termino da reserva (DD/MMM/AAAA): " << endl; 
		getline(cin, entrada);
		dataTermino->setData(entrada);
    	
		resultado = servidor->cancelar(id, idAcomodacao, dataInicio, dataTermino);
	}
	catch (const invalid_argument &exp) {
		cout << endl << "Formato invalido! Tente novamente." << endl;
		resultado = FALHA;
	}


    delete dataInicio;
    delete dataTermino;
    delete idAcomodacao;
    
    return resultado;
}

int CntrAprAcomodacao :: cadastrarDisp(Identificador *id) throw(runtime_error){
    Data *dataInicio = new Data();
    Data *dataTermino = new Data();
    Identificador *idAcomodacao = new Identificador();

    // OBS: O anfitrião associado a uma acomodação pode cadastrar períodos de disponibilidade da acomodação.

    string entrada;
    int resultado;

	cout << endl << "Cadastro de Disponibilidade." << endl << endl;

	try{
		cout << "Digite o identificador da acomodacao que voce deseja tornar disponível: " << endl;
		getline(cin, entrada);
		idAcomodacao->setIdentificador(entrada);
		cout << "Digite a data de inicio da disponibilidade (DD/MMM/AAAA): " << endl;
		getline(cin, entrada);
		dataInicio->setData(entrada);
		cout << "Digite a data de termino da disponibilidade (DD/MMM/AAAA): " << endl; 
		getline(cin, entrada);
		dataTermino->setData(entrada);
		
		resultado = servidor->cadastrarDisp(id, idAcomodacao, dataInicio, dataTermino);
	}
	catch (const invalid_argument &exp) {
		cout << endl << "Formato invalido! Tente novamente." << endl;
	}


    delete dataInicio;
    delete dataTermino;
    delete idAcomodacao;

    return resultado;


}

int CntrAprAcomodacao :: descadastrarDisp(Identificador *id) throw(runtime_error){
    Data *dataInicio = new Data();
    Data *dataTermino = new Data();
    Identificador *idAcomodacao = new Identificador();

    string entrada;
    int resultado;

    

	cout << endl << "Descadastramento de Disponibilidade." << endl << endl;

	try{
		cout << "Digite o identificador da acomodacao que voce deseja descadastrar um período de disponibilidade: " << endl;
		cin >> entrada;
		idAcomodacao->setIdentificador(entrada);
		cout << "Digite a data de inicio da disponibilidade (DD/MMM/AAAA): " << endl;
		cin >> entrada;
		dataInicio->setData(entrada);
		cout << "Digite a data de termino da disponibilidade (DD/MMM/AAAA): " << endl; 
		cin >> entrada;
		dataTermino->setData(entrada);

		resultado = servidor->descadastrarDisp(id, idAcomodacao, dataInicio, dataTermino);
	}
	catch (const invalid_argument &exp) {
		cout << endl << "Formato invalido! Tente novamente." << endl;
		resultado = FALHA;
	}
    
    delete dataInicio;
    delete dataTermino;
    delete idAcomodacao;

    return resultado;
}
