#include "controladorasServico.h"

//Atributo estático container List.

list<ElementoResultado> ContainerUsuario::listaResultado;

//classe EErroPersistencia

EErroPersistencia::EErroPersistencia(string mensagem){
        this->mensagem = mensagem;
}

string EErroPersistencia::what() {
        return mensagem;
}

//classe ElementoResultado

void ElementoResultado::setNomeColuna(const string& nomeColuna) {
        this->nomeColuna = nomeColuna;
}

void ElementoResultado::setValorColuna(const string& valorColuna){
        this->valorColuna = valorColuna;
}

//classe ContainerUsuario

void ContainerUsuario::conectar() throw (EErroPersistencia) {
      rc = sqlite3_open(nomeBancoDados, &bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na conexao ao banco de dados");
}

void ContainerUsuario::desconectar() throw (EErroPersistencia) {
      rc =  sqlite3_close(bd);
      if( rc != SQLITE_OK )
        throw EErroPersistencia("Erro na desconexao ao banco de dados");      
}

void ContainerUsuario::executar() throw (EErroPersistencia) {
	cout << "Entrou" << endl;
        conectar();
        cout << "Parte 1" << endl;
        rc = sqlite3_exec(bd, containerUsuario.c_str(), callback, 0, &mensagem);
         cout << "Parte 2" << endl;
        if(rc != SQLITE_OK){
                if (mensagem){
                	cout << "Esteve aqui" << endl;
                	free(mensagem);
                }
                throw EErroPersistencia("Erro na execucao do comando SQL");
        } 
         cout << "Parte 3" << endl;    
        desconectar();
    cout << "Saiu" << endl;
}

int ContainerUsuario::callback(void *NotUsed, int argc, char **valorColuna, char **nomeColuna){
      NotUsed = 0;
      ElementoResultado elemento;
      int i;
      for(i = 0; i < argc; i++){
        elemento.setNomeColuna(nomeColuna[i]);
        elemento.setValorColuna(valorColuna[i] ? valorColuna[i]: "NULL");
        listaResultado.push_front(elemento);
      }
      return 0;
}

void ContainerUsuario :: obterIdentificador(Identificador* id) {
	containerUsuario = "SELECT Senha FROM Usuarios WHERE Identificador = ";
    containerUsuario += id->getIdentificador();
}

string ContainerUsuario :: obterSenha() throw (EErroPersistencia){
	ElementoResultado resultado;
	string senha_recuperada;

	cout << "Teste 1" << endl;

	if (listaResultado.empty()){
        throw EErroPersistencia("Lista de resultados vazia.");
    }

    cout << "Teste 2" << endl;

    resultado = listaResultado.back();
    listaResultado.pop_back();
    senha_recuperada = resultado.getValorColuna();

    cout << "Teste 3" << endl;

    return senha_recuperada;

}

//classe ServAutenticacao

int CntrServAutenticacao :: autenticar(Identificador* id, Senha* senha){	
	ContainerUsuario* container = new ContainerUsuario();
	string senha_recuperada;

	cout << "Passo 1" << endl;
    
    container->obterIdentificador(id);
    container->executar();

    cout << "Passo 2" << endl;

    senha_recuperada = container->obterSenha();

    cout << senha_recuperada << endl;

    cout << "Passo 3" << endl;

    if (senha_recuperada == senha->getSenha()){
    	return SUCESSO;
    }
    else{
    	return FALHA;
    }

    cout << "Passo 4" << endl;
}

int CntrServUsuario :: cadastrar(Nome* nome, Identificador* identificador, Senha* senha){

}

int CntrServUsuario :: descadastrarUsuario(Identificador* id){

}

int CntrServUsuario :: cadastrarContaCorrente(Identificador* id, NumeroDeContaCorrente* conta, Agencia* agencia, Banco* banco){
}

int CntrServUsuario :: descadastrarContaCorrente(Identificador* id){
}

int CntrServUsuario :: cadastrarCartaoDeCredito(Identificador* id, NumeroDeCartaoDeCredito* cartao, DataDeValidade* dataDeValidade){

}

int CntrServUsuario :: descadastrarCartaoDeCredito(Identificador* id){
}


int CntrServAcomodacao :: cadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade){

}

int CntrServAcomodacao :: descadastrar(Identificador *id, TipoDeAcomodacao *tipo, CapacidadeDeAcomodacao *capacidade, Diaria *preco, Estado *estado, Nome *cidade){
}

int CntrServAcomodacao :: reservar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){

}

int CntrServAcomodacao :: cancelar(Identificador *id, TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){

}

int CntrServAcomodacao :: cadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){
}

int CntrServAcomodacao :: descadastrarDisp(TipoDeAcomodacao *tipo, Data *dataInicio, Data *dataTermino){
}