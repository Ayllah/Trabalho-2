#include "controladoraMIC.h"

void CntrMIC :: inicializar(){
    servidorAutenticar = new CntrAprAutenticacao();
    servidorUsuario = new CntrAprUsuario();
    servidorAcomodacao = new CntrAprAcomodacao();
}

void CntrMIC :: entrar(){
    int resultado;
    Identificador *id = new Identificador();

    resultado = servidorAutenticar->autenticar(id);

    if(resultado == SUCESSO){
        servidorUsuario->executar(id);
    }
    else{
        return;
    }

    return;
}

void CntrMIC :: cadastrar(){
    int resultado;
    
    resultado - servidorUsuario->cadastrar():

    if(resultado == SUCESSO){
        cout << "Cadastro feito com sucesso" << endl;
        return;
    }
    else{
        return;
    }
}