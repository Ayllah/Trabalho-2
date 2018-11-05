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
const static int FALHA = -1;

int main()
{

	IAprAutenticacao* cntr = new CntrAprAutenticacao();
	IServAutenticacao* servidor = new CntrServAutenticacao();

	IAprAcomodacao* cntrAco = new CntrAprAcomodacao();
	IServAcomodacao* servidorAco = new CntrServAcomodacao();

	Identificador* id = new Identificador();
	
	cntr->setServidor(servidor);
	//cntrAco->setServidor(servidorAco);

	int resultado = cntr->autenticar(id);
	int resultadoAco;

	if(resultado == SUCESSO){
		cout << endl << "SUCESSO" << endl;
		cntrAco->setServidor(servidorAco);
		resultadoAco = cntrAco->executar(id);
	}
	else{
		cout << endl << "FALHA" << endl;
	}


	if(resultadoAco == SUCESSO){
		cout << endl << "SUCESSO" << endl;
	}
	else{
		cout << endl << "FALHA" << endl;
	}

	delete cntr;
	delete servidor;
	delete cntrAco;
	delete servidorAco;

	return 0;
}