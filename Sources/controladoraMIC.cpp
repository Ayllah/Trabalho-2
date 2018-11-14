#include "controladoraMIC.h"

void CntrMIC :: inicializar(){
    cntrAutenticar = new CntrAprAutenticacao();
    cntrUsuario = new CntrAprUsuario();
    cntrAcomodacao = new CntrAprAcomodacao();

    servidorAutenticar = new CntrServAutenticacao();
    servidorUsuario = new CntrServUsuario();
    servidorAcomodacao = new CntrServAcomodacao();  

    cntrAutenticar->setServidor(servidorAutenticar);
    cntrUsuario->setServidor(servidorUsuario);
    cntrAcomodacao->setServidor(servidorAcomodacao);
}

void CntrMIC :: entrar(){
    int resultado;
    Identificador *id = new Identificador();

    resultado = cntrAutenticar->autenticar(id);

    if(resultado == SUCESSO){
        cntrUsuario->executar(id);
    }
    else{
        return;
    }

    return;
}

void CntrMIC :: cadastrar(){
    int resultado;
    Identificador *id = new Identificador();

    resultado = cntrUsuario->cadastrar(id);

    if(resultado == SUCESSO){
        cout << "Cadastro feito com sucesso" << endl;
        return;
    }
    else{
        return;
    }
}

void CntrMIC :: menu(){
    string opcao;

    inicializar();
	
	while(!SAIR){
		cout << endl << "Tela Inicial" << endl << endl;

		cout << ENTRAR << " - Entrar" << endl;
		cout << CADASTRAR << " - Cadastrar" << endl;
		cout << SAIR << " - Sair" << endl;
		getline(cin, opcao);

		switch(stoi(opcao)){
			case ENTRAR:    entrar();
				            break;

			case CADASTRAR:
				cadastrar();
				break;
		}

		if(stoi(opcao) == SAIR){
			break;
		}
	}
}