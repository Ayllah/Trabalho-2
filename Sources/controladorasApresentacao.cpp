#include "controladorasApresentacao.h"

int CntrAprAutenticacao :: autenticar(Identificador *id) throw(runtime_error) {
	Senha* senha = new Senha();
	
	string entrada;
	int resultado;

	//Perguntar id e senha

	while(true){
		cout << endl << "Autenticacao de usuario." << endl << endl;

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

	delete senha;

	return resultado;
}

int CntrAprAcomodacao :: executar(Identificador *id) {
	int opcao;
    int resultado;

	while(true){

		cout << endl << "Acomodacao:" << endl << endl;

        cout << "Cadastrar Acomodacao         - " << CADASTRAR_ACOMODACAO << endl;
        cout << "Descadastrar Acomodacao      - " << DESCADASTRAR_ACOMODACAO << endl;
        cout << "Reservar Acomodacao          - " << RESERVAR_ACOMODACAO << endl;
        cout << "Cancelar Reserva             - " << CANCELAR_RESERVA << endl;
        cout << "Cadastrar Disponibilidade    - " << CADASTRAR_DISPONIBILIDADE << endl;
        cout << "Descadastrar Disponibilidade - " << DESCADASTRAR_DISPONIBILIDADE << endl;
        cout << "Retornar                     - " << RETORNAR << endl << endl;
        cout << "Selecione uma opcao :";

        cin >> opcao;

        switch(opcao){
            case CADASTRAR_ACOMODACAO:          resultado = cadastrar(id);
                                                return resultado;
                                                break;
            case DESCADASTRAR_ACOMODACAO:       resultado = descadastrar(id);
                                                return resultado;
                                                break;
            case RESERVAR_ACOMODACAO:           resultado = reservar();
                                                return resultado;
                                                break;
            case CANCELAR_RESERVA:              resultado = cancelar ();
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
            cin >> entrada;
            id->setIdentificador(entrada);
            cout << "Digite o tipo de acomodacao (flat, apartamento ou casa): " << endl;
            cin >> entrada;
            tipo->setTipoDeAcomodacao(entrada);
            cout << "Digite a capacidade de acomodacao (1 a 9): " << endl;
            cin >> entrada;
            capacidade->setCapacidade(stoi(entrada));
            cout << "Digite o valor da diaria: (R$ 1,00 a R$ 10.000,00)" << endl;
            cin >> entrada;
            preco->setDiaria(stof(entrada));
            cout << "Digite o Estado onde se encontra a acomodacao (sigla): " << endl;
            cin >> entrada;
            estado->setEstado(entrada);
            cout << "Digite a cidade onde se encontra a acomodacao: " << endl;
            cin >> entrada;
            cidade->setNome(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Formato invalido! Tente novamente." << endl;
        }

    }

    //Solicitar autenticacao
    
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
            cout << "Digite seu ID: " << endl; //pedro
            cin >> entrada;
            id->setIdentificador(entrada);
            cout << "Digite o tipo de acomodacao (flat, apartamento ou casa): " << endl;
            cin >> entrada;
            tipo->setTipoDeAcomodacao(entrada);
            cout << "Digite a capacidade de acomodacao (1 a 9): " << endl;
            cin >> entrada;
            capacidade->setCapacidade(stoi(entrada));
            cout << "Digite o valor da diaria: (R$ 1,00 a R$ 10.000,00)" << endl;
            cin >> entrada;
            preco->setDiaria(stof(entrada));
            cout << "Digite o Estado onde se encontra a acomodacao (sigla): " << endl;
            cin >> entrada;
            estado->setEstado(entrada);
            cout << "Digite a cidade onde se encontra a acomodacao: " << endl;
            cin >> entrada;
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

int CntrAprAcomodacao :: reservar() throw(runtime_error){
    Data *dataInicio = new Data();
    Data *dataTermino = new Data();

    // OBS: Para reservar e preciso ter cartao de credito

    string entrada;
    int resultado;

    while(true){

        cout << endl << "Reserva de Acomodacao." << endl << endl;

        try{
            cout << "Digite a data de inicio da reserva (DD/MMM/AAAA): " << endl; // 30/jan/2018
            cin >> entrada;
            dataInicio->setData(entrada);
            cout << "Digite a data de termino da reserva (DD/MMM/AAAA): " << endl; 
            cin >> entrada;
            dataTermino->setData(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Formato invalido! Tente novamente." << endl;
        }

    }

    //Solicitar autenticacao
    
    resultado = servidor->reservar(dataInicio, dataTermino);

    delete dataInicio;
    delete dataTermino;

    return resultado;

}

int CntrAprAcomodacao :: cancelar() throw(runtime_error){
    Data *dataInicio = new Data();
    Data *dataTermino = new Data();

    // OBS: Uma reserva pode ser cancelada, desde que a data de cancelamento anteceda o período da reserva.

    string entrada;
    int resultado;

    while(true){

        cout << endl << "Cancelamento de Reserva." << endl << endl;

        try{
            cout << "Digite a data de inicio da reserva (DD/MMM/AAAA): " << endl; // 30/jan/2018
            cin >> entrada;
            dataInicio->setData(entrada);
            cout << "Digite a data de termino da reserva (DD/MMM/AAAA): " << endl; 
            cin >> entrada;
            dataTermino->setData(entrada);
            break;
        }
        catch (const invalid_argument &exp) {
            cout << endl << "Formato invalido! Tente novamente." << endl;
        }

    }

    //Solicitar autenticacao
    
    resultado = servidor->cancelar(dataInicio, dataTermino);

    delete dataInicio;
    delete dataTermino;

    return resultado;

}

int CntrAprAcomodacao :: cadastrarDisp() throw(runtime_error){
    Data *dataInicio = new Data();
    Data *dataTermino = new Data();

    // OBS: O anfitrião associado a uma acomodação pode cadastrar períodos de disponibilidade da acomodação.

    string entrada;
    int resultado;

    while(true){

        cout << endl << "Cadastro de Disponibilidade." << endl << endl;

        try{
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

    //Solicitar autenticacao
    
    resultado = servidor->cadastrarDisp(dataInicio, dataTermino);

    delete dataInicio;
    delete dataTermino;

    return resultado;


}

int CntrAprAcomodacao :: descadastrarDisp() throw(runtime_error){
    Data *dataInicio = new Data();
    Data *dataTermino = new Data();

    string entrada;
    int resultado;

    while(true){

        cout << endl << "Descadastramento de Disponibilidade." << endl << endl;

        try{
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

    //Solicitar autenticacao
    
    resultado = servidor->descadastrarDisp(dataInicio, dataTermino);

    delete dataInicio;
    delete dataTermino;

    return resultado;


}