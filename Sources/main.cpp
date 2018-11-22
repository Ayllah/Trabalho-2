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

int main(){
	CntrMIC *cntr = new CntrMIC();
	
	cntr->menu();

	delete cntr;
	return 0;
}