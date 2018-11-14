#include <stdexcept>
#include <iostream>
#include <string>

#include "dominios.h"
#include "entidades.h"
#include "controladorasApresentacao.h"
#include "controladorasServico.h"
#include "interfacesApresentacao.h"
#include "interfacesServico.h"
#include "controladoraMIC.h"

using namespace std;

const static int SUCESSO =  0;
const static int SAIR = 0;

int main()
{
	CntrMIC *cntr = new CntrMIC();
	cntr->menu();

	return 0;
}
