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

int main()
{

	IAprAutenticacao* cntr = new CntrAprAutenticacao();
	IServAutenticacao* servidor = new CntrServAutenticacao();

	Identificador* id = new Identificador();
	
	cntr->setServidor(servidor);
	int resultado = cntr->autenticar(id);

	if(resultado){
		cout << "SUCESSO" << endl;
	}
	else{
		cout << "FALHA" << endl;
	}

	return 0;
}