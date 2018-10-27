#include "controladorasApresentacao.h"

int CntrAprAutenticacao :: autenticar(Identificador *id) throw(runtime_error) {
	string entrada;
	Senha* senha;
	int resultado;

	//senha = new Senha();

	//Perguntar id e senha

	while(true){
		cout << endl << "Autenticacao de usuario." << endl << endl;

		try{
			cout << "Digite seu ID: " << endl;
			cin >> entrada;
			id->setIdentificador(entrada);
			cout << "Digite sua senha: " << endl;
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

	// Informar resultado da autenticação.

    //if(resultado.getValor() == ResultadoAutenticacao::FALHA)
    //cout << endl << "Falha na autenticacao." << endl;

	return resultado;
}