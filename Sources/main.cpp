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

	Identificador* id = new Identificador();
	
	cntr->setServidor(servidor);
	int resultado = cntr->autenticar(id);

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