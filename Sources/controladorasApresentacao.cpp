#include "controladorasApresentacao.h"
#include "controladorasServico.h" // Porque precisa dessa linha?

//***********************************************************************************************************
// Classe CntrAprAutenticacao

int CntrAprAutenticacao :: autenticar(Identificador *id) throw(runtime_error) {
	string entrada;
	Senha *senha = new Senha();
	int resultado;

	//Perguntar id e senha

	while(true){
		cout << endl << "Autenticacao de Usuario." << endl << endl;

		try{
			cout << "Digite seu ID: " << endl; //pedro
			getline(cin, entrada);
			id->setIdentificador(entrada);
			cout << "Digite sua senha: " << endl; //1a3A567$
			getline(cin, entrada);
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

//***********************************************************************************************************
// Classe CntrAprUsuario

int CntrAprUsuario :: painelConta(Identificador *id) throw(runtime_error){
	string opcao;
	int resultado;
	string entrada;
	
	IAprAutenticacao *cntrAutenticacao = new CntrAprAutenticacao();
	IServAutenticacao *servidorAutenticacao = new CntrServAutenticacao();
	
	cntrAutenticacao->setServidor(servidorAutenticacao);


	while(true){
		cout << "-------------- Minha Conta ---------------" << endl;
		//cout << EDITAR << " - Editar Perfil de Usuario" << endl;
		cout << CADASTRAR_CONTA_CORRENTE << " - Cadastrar uma conta corrente" << endl;
		cout << DESCADASTRAR_CONTA_CORRENTE << " - Descadastrar minha conta corrente" << endl;
		cout << CADASTRAR_CARTAO_CREDITO << " - Cadastrar um cartao de credito" << endl;
		cout << DESCADASTRAR_CARTAO_CREDITO << " - Descastrar meu cartao de credito" << endl;
		cout << DESCADASTRAR << " - Descadastrar minha conta"<< endl;
		cout << VOLTAR << " - Voltar" << endl;
		cout << "Selecione uma opcao : ";
		
		getline(cin, opcao);

		switch(stoi(opcao)){
			case EDITAR:

				break;

			case CADASTRAR_CONTA_CORRENTE:
				resultado = cadastrarContaCorrente(id);
				if(resultado == SUCESSO){
					cout << "Conta corrente cadastrada com sucesso!" << endl;
				}
				break;

			case DESCADASTRAR_CONTA_CORRENTE:
				resultado = descadastrarContaCorrente(id);
				if(resultado == SUCESSO){
					cout << "Conta corrente REMOVIDA!" << endl;
				}
				break;

			case CADASTRAR_CARTAO_CREDITO:
				resultado = cadastrarCartaoDeCredito(id);
				if(resultado == SUCESSO){
					cout << "Cartão cadastrado com sucesso!" << endl;
				}
				break;

			case DESCADASTRAR_CARTAO_CREDITO:
				resultado = descadastrarCartaoDeCredito(id);
				if(resultado == SUCESSO){
					cout << "Cartão REMOVIDO!" << endl;
				}
				break;

			case DESCADASTRAR:
				
				resultado = cntrAutenticacao->autenticar(id);
				if(resultado == SUCESSO){
					resultado = descadastrarUsuario(id);
					
					if(resultado == SUCESSO){
						cout << "Usuario removido do sistema" << endl;
						break;
					}				
				}
				else{
					cout << "Falha na autenticação" << endl;
				}

				
				break;

			case VOLTAR:
				opcao = to_string(VOLTAR);
				break;

			default:
				cout << "Opcao Invalida" << endl;
				break;
		}

		if(stoi(opcao) == VOLTAR){
			break;
		}
	}

	delete cntrAutenticacao;
	delete servidorAutenticacao;

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

	while(true){
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
			break;
		}
		catch (const invalid_argument &exp) {
			cout << endl << "Formato invalido! Tente novamente." << endl;
		}	
	}
	
	resultado = servidor->cadastrarContaCorrente(id, conta, agencia, banco);

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

	while(true){
		cout << "_____________________________" << endl;
		cout << "Cadastro de Cartao de credito" << endl << endl;
		

		try{
			cout << "Digite o número de seuu cartao de credito: " << endl; //pedro
			getline(cin, entrada);
			cartao->setNumeroDeCartaoDeCredito(entrada);
			cout << "Digite a data de validade do seu cartao: " << endl; //1a3A567$
			getline(cin, entrada);
			dataDeValidade->setDataDeValidade(entrada);
			break;
		}
		catch (const invalid_argument &exp) {
			cout << endl << "Formato invalido! Tente novamente." << endl;
		}	
	}

	resultado = servidor->cadastrarCartaoDeCredito(id, cartao, dataDeValidade);
	
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
	cout << CONTINUAR << " - Deseja prosseguir com o cadastramento?" << endl;
	cout << VOLTAR << " - Voltar" << endl;
	cout << "Selecione uma opcao : ";

	getline(cin, opcao);

	switch(stoi(opcao)){
		case CONTINUAR:
			cout << "Digite seu nome: ";
			getline(cin, entrada);
			nome->setNome(entrada);

			cout << "Digite seu identificador. Ele sera usado para acessar sua conta.: ";
			getline(cin, entrada);
			identificador->setIdentificador(entrada);

			cout << "Digite sua senha: ";
			getline(cin, entrada);
			senha->setSenha(entrada);

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

			break;

		case VOLTAR:
			return DESISTENCIA;

		default:
			return FALHA;
	}
	
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
					resultado = painelConta(id);
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
	Data* dataInicio = new Data();
	Data* dataTermino = new Data();

	try{
		cout << endl << "Janela de Pesquisa de Acomodacoes" << endl << endl;

		cout << "Digite a data de início do intervalo de pesquisa: " << endl;
		getline(cin, entrada);
		dataInicio->setData(entrada);
		cout << "Digite a data final do intervalo de pesquisa: " << endl;
		getline(cin, entrada);
		dataTermino->setData(entrada);
	}
	catch (const invalid_argument &exp) {
		cout << endl << "Formato invalido! Tente novamente." << endl;
	}

	resultado = servidor->consultar(id, dataInicio, dataTermino);
	
	return resultado;
}

int CntrAprAcomodacao :: executar(Identificador *id) {
	int opcao;
    int resultado;

	while(true){

		cout << endl << "Painel de Acomodacao:" << endl << endl;

        cout << CADASTRAR_ACOMODACAO << " - Cadastrar Acomodacao         - " << endl;
        cout << DESCADASTRAR_ACOMODACAO << " - Descadastrar Acomodacao      - " << endl;
        cout << RESERVAR_ACOMODACAO << " - Reservar Acomodacao          - " << endl;
        cout << CANCELAR_RESERVA << " - Cancelar Reserva             - " << endl;
        cout << CADASTRAR_DISPONIBILIDADE << " - Cadastrar Disponibilidade    - " << endl;
        cout << DESCADASTRAR_DISPONIBILIDADE << " - Descadastrar Disponibilidade - " << endl;
        cout << RETORNAR << " - Retornar                     - " << endl << endl;
        cout << "Selecione uma opcao : ";

        cin >> opcao;

        switch(opcao){
            case CADASTRAR_ACOMODACAO:          resultado = cadastrar(id);
                                                return resultado;
                                                break;
            case DESCADASTRAR_ACOMODACAO:       resultado = descadastrar(id);
                                                return resultado;
                                                break;
            case RESERVAR_ACOMODACAO:           resultado = reservar(id);
                                                return resultado;
                                                break;
            case CANCELAR_RESERVA:              resultado = cancelar (id);
                                                return resultado;
            				                    break;
            case CADASTRAR_DISPONIBILIDADE:     resultado = cadastrarDisp();
                                                return resultado;
                                                break;
            case DESCADASTRAR_DISPONIBILIDADE:  resultado = descadastrarDisp();
                                                return resultado;
                                                break;
        }

        if(opcao == RETORNAR)
            break;
    }

}

int CntrAprAcomodacao :: cadastrar(Identificador *id) throw(runtime_error) {
    TipoDeAcomodacao *tipo = new TipoDeAcomodacao();
    CapacidadeDeAcomodacao *capacidade =  new CapacidadeDeAcomodacao();
    Diaria *preco = new Diaria();
    Estado *estado = new Estado();
    Nome *cidade = new Nome();

    // OBS: Para cadastrar e preciso ter conta corrente

    string entrada;
    int resultado;

    while(true){

        cout << endl << "Cadastro de Acomodacao." << endl << endl;

        try{
            cout << "Digite seu ID: " << endl; //pedro
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
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Formato invalido! Tente novamente." << endl;
        }

    }

    //Solicitar autentservidoricacao
    
    resultado = servidor->cadastrar(id, tipo, capacidade, preco, estado, cidade);

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

    while(true){

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
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Formato invalido! Tente novamente." << endl;
        }

    }

    //Solicitar autenticacao
    
    resultado = servidor->descadastrar(id, tipo, capacidade, preco, estado, cidade);

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
    TipoDeAcomodacao *tipo = new TipoDeAcomodacao();

    // OBS: Para reservar e preciso ter cartao de credito

    string entrada;
    int resultado;

    while(true){

        cout << endl << "Reserva de Acomodacao." << endl << endl;

        try{
            cout << "Digite seu ID: " << endl; //pedro
            getline(cin, entrada);
            id->setIdentificador(entrada);
            cout << "Digite o tipo de acomodacao (flat, apartamento ou casa): " << endl;
            getline(cin, entrada);
            tipo->setTipoDeAcomodacao(entrada);
            cout << "Digite a data de inicio da reserva (DD/MMM/AAAA): " << endl; // 30/jan/2018
            getline(cin, entrada);
            dataInicio->setData(entrada);
            cout << "Digite a data de termino da reserva (DD/MMM/AAAA): " << endl; 
            getline(cin, entrada);
            dataTermino->setData(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Formato invalido! Tente novamente." << endl;
        }

    }

    //Solicitar autenticacao
    
    resultado = servidor->reservar(id, tipo, dataInicio, dataTermino);

    delete dataInicio;
    delete dataTermino;
    delete tipo;

    return resultado;

}

int CntrAprAcomodacao :: cancelar(Identificador *id) throw(runtime_error){
    Data *dataInicio = new Data();
    Data *dataTermino = new Data();
    TipoDeAcomodacao *tipo = new TipoDeAcomodacao();

    // OBS: Uma reserva pode ser cancelada, desde que a data de cancelamento anteceda o período da reserva.

    string entrada;
    int resultado;

    while(true){

        cout << endl << "Cancelamento de Reserva." << endl << endl;

        try{
            cout << "Digite seu ID: " << endl; //pedro
            getline(cin, entrada);
            id->setIdentificador(entrada);
            cout << "Digite o tipo de acomodacao (flat, apartamento ou casa): " << endl;
            getline(cin, entrada);
            tipo->setTipoDeAcomodacao(entrada);
            cout << "Digite a data de inicio da reserva (DD/MMM/AAAA): " << endl; // 30/jan/2018
            getline(cin, entrada);
            dataInicio->setData(entrada);
            cout << "Digite a data de termino da reserva (DD/MMM/AAAA): " << endl; 
            getline(cin, entrada);
            dataTermino->setData(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Formato invalido! Tente novamente." << endl;
        }

    }

    //Solicitar autenticacao
    
    resultado = servidor->cancelar(id, tipo, dataInicio, dataTermino);

    delete dataInicio;
    delete dataTermino;
    delete tipo;
    
    return resultado;

}

int CntrAprAcomodacao :: cadastrarDisp() throw(runtime_error){
    Data *dataInicio = new Data();
    Data *dataTermino = new Data();
    TipoDeAcomodacao *tipo = new TipoDeAcomodacao();

    // OBS: O anfitrião associado a uma acomodação pode cadastrar períodos de disponibilidade da acomodação.

    string entrada;
    int resultado;

    while(true){

        cout << endl << "Cadastro de Disponibilidade." << endl << endl;

        try{
            cout << "Digite o tipo de acomodacao (flat, apartamento ou casa): " << endl;
            getline(cin, entrada);
            tipo->setTipoDeAcomodacao(entrada);
            cout << "Digite a data de inicio da disponibilidade (DD/MMM/AAAA): " << endl; // 30/jan/2018
            getline(cin, entrada);
            dataInicio->setData(entrada);
            cout << "Digite a data de termino da disponibilidade (DD/MMM/AAAA): " << endl; 
            getline(cin, entrada);
            dataTermino->setData(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Formato invalido! Tente novamente." << endl;
        }

    }
    
    resultado = servidor->cadastrarDisp(tipo, dataInicio, dataTermino);

    delete dataInicio;
    delete dataTermino;
    delete tipo;

    return resultado;


}

int CntrAprAcomodacao :: descadastrarDisp() throw(runtime_error){
    Data *dataInicio = new Data();
    Data *dataTermino = new Data();
    TipoDeAcomodacao *tipo = new TipoDeAcomodacao();

    string entrada;
    int resultado;

    while(true){

        cout << endl << "Descadastramento de Disponibilidade." << endl << endl;

        try{
            cout << "Digite o tipo de acomodacao (flat, apartamento ou casa): " << endl;
            cin >> entrada;
            tipo->setTipoDeAcomodacao(entrada);
            cout << "Digite a data de inicio da disponibilidade (DD/MMM/AAAA): " << endl; // 30/jan/2018
            cin >> entrada;
            dataInicio->setData(entrada);
            cout << "Digite a data de termino da disponibilidade (DD/MMM/AAAA): " << endl; 
            cin >> entrada;
            dataTermino->setData(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Formato invalido! Tente novamente." << endl;
        }

    }
    
    resultado = servidor->descadastrarDisp(tipo, dataInicio, dataTermino);

    delete dataInicio;
    delete dataTermino;
    delete tipo;

    return resultado;
}
