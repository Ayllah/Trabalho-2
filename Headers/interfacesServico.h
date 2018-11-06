#ifndef INTERFACESSERVICO_H_INCLUDED
#define INTERFACESSERVICO_H_INCLUDED

#include "dominios.h"
#include "entidades.h"
#include <stdexcept>

using namespace std;

class IServAutenticacao{
	public:
		virtual int autenticar(Identificador* id, Senha* senha) = 0;

		virtual ~IServAutenticacao(){}
};

class IServUsuario{
	public:
		virtual int descadastrar(Identificador* id) = 0;

		virtual ~IServUsuario(){}
};

#endif // INTERFACESSERVICO_H_INCLUDED