#include "controladorasApresentacao.h"

int CntrAprAutenticacao :: autenticar(Identificador *id) throw(runtime_error) {
	string entrada;
	Senha* senha = new Senha();
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

	return resultado;
}

int CntrAprUsuario :: descadastrar(Indentificador *id) throw(runtime_error) {
	char opcao;
	int resultado;

	cout << "Você realmente deseja se descadastrar?" << endl;
	cout << SIM << " - SIM" << endl;
	cout << NAO << " - NÃO" << endl;
	cin >> opcao;

	resultado = FALHA;
	switch(int(opcao)){
		case SIM:
			resultado = servidor->descadastrar(id);
		break;
		
		default:
			resultado = DESISTENCIA;
	}

}