#include <stdexcept>
#include <iostream>
#include <string>

#include "dominios.h"
#include "entidades.h"
#include "controladorasApresentacao.h"
#include "controladorasServico.h"
#include "interfacesApresentacao.h"
#include "interfacesServico.h"

using namespace std;

const static int SUCESSO =  0;

int main()
{

	IAprAutenticacao* cntr = new CntrAprAutenticacao();
	IAprUsuario* cntrUsuario = new CntrAprUsuario();
	IServAutenticacao* servidor = new CntrServAutenticacao();
	IServUsuario* servidorUsuario = new CntrServUsuario();

	Identificador* id = new Identificador();
	
	cntr->setServidor(servidor);
	cntrUsuario->setServidor(servidorUsuario);

	// int resultado = cntr->autenticar(id);
	int resultado2 = cntrUsuario->executar(id);
	
	if(resultado2 == SUCESSO){
		cout << endl << "SUCESSO" << endl;
	}
	else{
		cout << endl << "FALHA" << endl;
	}

	delete cntr;
	delete servidor;

	return 0;
}