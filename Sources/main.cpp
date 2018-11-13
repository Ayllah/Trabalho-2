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
	IServAutenticacao* servidor = new CntrServAutenticacao();
	
	IAprUsuario* cntrUsuario = new CntrAprUsuario();
	IServUsuario* servidorUsuario = new CntrServUsuario();

	IAprAcomodacao* cntrAcomodacao = new CntrAprAcomodacao();
	IServAcomodacao* servidorAcomodacao = new CntrServAcomodacao();

	Identificador* id = new Identificador();
	
	cntr->setServidor(servidor);
	cntrUsuario->setServidor(servidorUsuario);
	cntrAcomodacao->setServidor(servidorAcomodacao);

	// cntrUsuario->setServidorAutenticacao(servidor);

	int resultado = cntr->autenticar(id);
	// int resultado2 = cntrAcomodacao->executar(id);
	
	if(resultado == SUCESSO){
		cout << endl << "SUCESSO" << endl;
	}
	else{
		cout << endl << "FALHA" << endl;
	}

	delete cntr;
	delete servidor;

	return 0;
}