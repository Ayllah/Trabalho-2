#ifndef CONTROLADORA_MIC_H_INCLUDED
#define CONTROLADORA_MIC_H_INCLUDED

#include "interfacesApresentacao.h"
#include "interfacesServico.h"
#include "controladorasApresentacao.h"
#include "controladorasServico.h"
#include "dominios.h"
#include "entidades.h"

class CntrMIC{
    private:
        IAprAutenticacao* cntrAutenticar;
        IAprUsuario* cntrUsuario;
        IAprAcomodacao* cntrAcomodacao;

        IServAutenticacao* servidorAutenticar;
        IServUsuario* servidorUsuario;
        IServAcomodacao* servidorAcomodacao;
        
    public:
        const static int ENTRAR = 1;
        const static int CADASTRAR = 2;
        const static int SAIR = 0;
        
        const static int SUCESSO = 0;

        void inicializar();
        void entrar();
        void cadastrar();

        void menu();
};

#endif //