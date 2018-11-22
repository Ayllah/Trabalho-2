#include "dominios.h"

#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>
#include <locale>

#include <iostream>

using namespace std;

void Agencia::validar(string agencia) throw (invalid_argument){
	int verificadorTamanho;
	int i;

    verificadorTamanho = agencia.size();

    // Lança exceção se o tamanho da string agencia for diferente do tamanho esperado
	// ou se algum caracter da string apresentar valor diferente de 0-9

	if(verificadorTamanho != TAMANHO){
		throw invalid_argument("Argumento invalido.");
	}
	else{

        // Testa a validade de cada digito

		for (i = 0; i < TAMANHO; ++i){
			if(!isdigit(agencia[i])){
				throw invalid_argument("Argumento invalido.");
            }
        }
	}
}

void Agencia::setAgencia(string agencia) throw (invalid_argument){
	validar(agencia);
	this->agencia = agencia;
}

void Banco::validar(string banco) throw (invalid_argument){
    int verificadorTamanho;
    int i;

    verificadorTamanho = banco.size();

    //Lança exceção se o tamanho da string banco for diferente do tamanho esperado
	// ou se algum caracter da string apresentar valor diferente de 0-9

    if ( verificadorTamanho != TAMANHO ){
        throw invalid_argument("Argumento invalido.");
    }
    else{
		for (i = 0; i < TAMANHO; ++i){
			if( !isdigit(banco[i]) ){
				throw invalid_argument("Argumento invalido.");
            }
        }
    }
}

void Banco::setBanco(string banco) throw (invalid_argument){
    validar(banco);
    this->banco = banco;
}

void CapacidadeDeAcomodacao::validar(int capacidade) throw (invalid_argument){

 	//Lança exceção se o valor for maior ou menor que os limites definidos

    if (capacidade > CAPACIDADE_MAXIMA || capacidade < CAPACIDADE_MINIMA){
        throw invalid_argument("Argumento invalido.");
    }
}

void CapacidadeDeAcomodacao::setCapacidade(int capacidade) throw (invalid_argument){
    validar(capacidade);
    this->capacidade = capacidade;
}


void Diaria::validar(double preco) throw (invalid_argument){

 	//Lança exceção se o preço for maior ou menor que os limites definidos

    if (preco > PRECO_MAXIMO || preco < PRECO_MINIMO){
        throw invalid_argument("Argumento invalido.");
    }
}

void Diaria::setDiaria(double preco) throw (invalid_argument){
    validar(preco);
    this->preco = preco;
}

int Data::verificaMes(string nomeMes){
    int verificador = INVALIDO;
    for(int i = 0; i < QUANTIDADE_MESES; ++i){
        if( nomeMes == meses[i]){
            verificador = i + 1;
            break;
        }
    }

    return verificador;
}

int Data::verificaBissexto(int ano) throw (invalid_argument){

    // Se o ano for múltiplo de 100 e não for múltiplo de 400 ou
    // ano não for múltiplo de 4, então NÃO É bissexto

    if((ano % 100 == 0) && (ano % 400 != 0) || (ano % 4 != 0)){
        return INVALIDO;
    }

    // Do contrário, o ano certamente É bissexto.

    else{
        return VALIDO;
    }
}

void Data::validar(string data) throw (invalid_argument){
    string::size_type sz;
    int verificadorTamanho;
    int verificadorMes;
    int i;
    int dia;
    char ano[TAMANHO_PADRAO_ANO];
    string mes;
    verificadorTamanho = data.size();

    dia = stoi(data, 0);
    memcpy(ano,&data[7],4);
    ano[4] = '\0';
    mes = data.substr(3,3);

    verificadorMes = verificaMes(mes);

    // Lança exceção se o tamanho da string agencia for diferente do tamanho esperado

    if( (verificadorTamanho != TAMANHO) ){
        throw invalid_argument("Argumento invalido.");
    }

    // Lança exceção se não for encontrado os caracteres separadores dos campos da data
    // na posiçãoe esperada, violando o formato

    else if( data[POSICAO_SEPARADOR_DIA_MES] != '/' &&
             data[POSICAO_SEPARADOR_MES_ANO] != '/'){
        throw invalid_argument("Argumento invalido.");
    }

    // Lança exceção se o dia estiver fora do intervalo definido com válido

    else if(dia < DIA_MINIMO || dia > DIA_MAXIMO){
        throw invalid_argument("Argumento invalido.");
    }

    // Lança exceção se o ano estiver fora do intervalo definido como válido

    else if(atoi(ano) < ANO_MINIMO || atoi(ano) > ANO_MAXIMO){
        throw invalid_argument("Argumento invalido.");
    }
    else{
        // Lança exceção se houver caracteres que não são letra na string nomeMes

        for(i = 0; mes[i] != '\0'; ++i){
            if(!isalpha(mes[i])){
                throw invalid_argument("Argumento invalido.");
            }
        }

        // Lança exceção se o nome do mês não for encontrado no vetor de string dos meses
        // ou se o dia não existir para o mês dada
        // ou se, para dado ano bissexto e para o mês de ferevereiro, o dia for maior que
        // o limite dado ao mês de fereiro em ano não bissexto

        if(verificadorMes == INVALIDO){
            throw invalid_argument("Argumento invalido.");
        }
        else if(dia > numeroDiasDoMes[verificadorMes - 1]){
            throw invalid_argument("Argumento invalido.");
        }
        else{
            if((verificaBissexto(atoi(ano)) == INVALIDO)  && (mes == "fev") && ( dia > FEVEREIRO_NAO_BISSEXTO )){
                throw invalid_argument("Argumento invalido.");
            }
        }
    }
}

bool Data :: diaComecoMes() throw (invalid_argument){
    string dia;

    dia = this->getData().substr(POSICAO_DIA, TAMANHO_PADRAO_DIA);
    
    if (stoi(dia) == 1){
        return true;
    }
    else{
        return false;
    }
}

bool Data :: diaMeioMes() throw (invalid_argument){
    string dia, mes, ano;
    int int_mes;
    int ultimoDiaMes;

    dia = this->getData().substr(POSICAO_DIA, TAMANHO_PADRAO_DIA);
    mes = this->getData().substr(POSICAO_SEPARADOR_DIA_MES + 1, TAMANHO_PADRAO_MES);
    int_mes = this->verificaMes(mes);
    ano = this->getData().substr(POSICAO_SEPARADOR_MES_ANO + 1, TAMANHO_PADRAO_ANO);

    ultimoDiaMes = numeroDiasDoMes[int_mes - 1];

    if(!this->verificaBissexto(stoi(ano)) && int_mes == 2){
        ultimoDiaMes -= 1;
    }

    if(stoi(dia) > 1 && stoi(dia) < ultimoDiaMes){
        return true;
    }
    else{
        return false;
    }
}

bool Data :: diaFimMes() throw (invalid_argument){
    string dia, mes, ano;
    int int_mes;
    int ultimoDiaMes;

    dia = this->getData().substr(POSICAO_DIA, TAMANHO_PADRAO_DIA);
    mes = this->getData().substr(POSICAO_SEPARADOR_DIA_MES + 1, TAMANHO_PADRAO_MES);
    int_mes = this->verificaMes(mes);
    ano = this->getData().substr(POSICAO_SEPARADOR_MES_ANO + 1, TAMANHO_PADRAO_ANO);

    ultimoDiaMes = numeroDiasDoMes[int_mes - 1];

    if(!this->verificaBissexto(stoi(ano)) && int_mes == 2){
        ultimoDiaMes -= 1;
    }

    if(stoi(dia) == ultimoDiaMes){
        return true;
    }
    else{
        return false;
    }
}

bool Data :: diaComecoAno() throw (invalid_argument){
    string dia, mes;
    int int_mes;

    dia = this->getData().substr(POSICAO_DIA, TAMANHO_PADRAO_DIA);
    mes = this->getData().substr(POSICAO_SEPARADOR_DIA_MES + 1, TAMANHO_PADRAO_MES);
    int_mes = this->verificaMes(mes);

    if(stoi(dia) == 1 && int_mes == 1){
        return true;
    }
    else{
        return false;
    }
}

bool Data :: diaFimAno() throw (invalid_argument){
    string dia, mes;
    int int_mes;

    dia = this->getData().substr(POSICAO_DIA, TAMANHO_PADRAO_DIA);
    mes = this->getData().substr(POSICAO_SEPARADOR_DIA_MES + 1, TAMANHO_PADRAO_MES);
    int_mes = this->verificaMes(mes);

    if(stoi(dia) == 31 && int_mes == 12){
        return true;
    }
    else{
        return false;
    }
}

void Data::setData(string data) throw (invalid_argument){
    string dia, mes, ano;

    dia = data.substr(POSICAO_DIA, TAMANHO_PADRAO_DIA);
    
    mes = data.substr(POSICAO_SEPARADOR_DIA_MES + 1,TAMANHO_PADRAO_MES);
    for(int i = 0; mes[i] != '\0'; ++i){
        if(isalpha(mes[i])){
            mes[i] = tolower(mes[i]);
        }
    }

    ano = data.substr(POSICAO_SEPARADOR_MES_ANO + 1, TAMANHO_PADRAO_ANO);

    data = dia + '/' + mes + '/' + ano;
    
    validar(data);
    this->data = data;
}

Data Data :: getDataAnterior() throw (invalid_argument){
    Data dataAnterior;
    string str_dataAtual, str_dataAnterior;
    string diaDataAtual, mesDataAtual, anoDataAtual;
    int int_mesDataAtual;
    string diaDataAnterior, mesDataAnterior, anoDataAnterior;
    int int_mesDataAnterior;
    int ultimoDiaMesAtual;
    int ultimoDiaMesAnterior;
    str_dataAtual = this->getData();

    diaDataAtual = str_dataAtual.substr(POSICAO_DIA, TAMANHO_PADRAO_DIA);
    mesDataAtual = str_dataAtual.substr(POSICAO_SEPARADOR_DIA_MES + 1, TAMANHO_PADRAO_MES);
    int_mesDataAtual = this->verificaMes(mesDataAtual);
    anoDataAtual = str_dataAtual.substr(POSICAO_SEPARADOR_MES_ANO + 1, TAMANHO_PADRAO_ANO);

    ultimoDiaMesAtual = numeroDiasDoMes[int_mesDataAtual - 1];
    ultimoDiaMesAnterior = numeroDiasDoMes[int_mesDataAtual - 2];
    if(int_mesDataAtual > 1){
        ultimoDiaMesAnterior = numeroDiasDoMes[int_mesDataAtual - 2];
    }

    if(!this->verificaBissexto(stoi(anoDataAtual)) && int_mesDataAtual == 2){
        ultimoDiaMesAtual -= 1;
    }
    
    if(!this->verificaBissexto(stoi(anoDataAtual)) && int_mesDataAnterior == 2){
        ultimoDiaMesAnterior -= 1;
    }
    
    if (this->diaMeioMes()){
        if(stoi(diaDataAtual) < 11){ // quando dia anterior está entre 01 e 09
            diaDataAnterior = '0' + to_string(stoi(diaDataAtual) - 1);
        }
        else{
            diaDataAnterior = to_string(stoi(diaDataAtual) - 1);
        }

        mesDataAnterior = mesDataAtual;
        anoDataAnterior = anoDataAtual;
    }
    else if (this->diaComecoAno()){
        diaDataAnterior = to_string(numeroDiasDoMes[11]);
        mesDataAnterior = meses[11];
        anoDataAnterior = to_string(stoi(anoDataAtual) - 1);
    }
    else if (this->diaFimAno()){
        diaDataAnterior = to_string(numeroDiasDoMes[11] - 1);
        mesDataAnterior = mesDataAtual;
        anoDataAnterior = anoDataAtual;
    }
    else if (this->diaComecoMes()){
        int_mesDataAnterior = int_mesDataAtual - 1;
        diaDataAnterior = to_string(ultimoDiaMesAnterior);
        mesDataAnterior = meses[int_mesDataAnterior - 1];
        anoDataAnterior = anoDataAtual;
    }
    else if (this->diaFimMes()){
        diaDataAnterior = to_string(ultimoDiaMesAtual - 1);
        mesDataAnterior = mesDataAtual;
        anoDataAnterior = anoDataAtual;
    }
    
    str_dataAnterior = diaDataAnterior + '/' + mesDataAnterior + '/' + anoDataAnterior;
    
    dataAnterior.setData(str_dataAnterior);

    return dataAnterior;
}

Data Data :: getDataPosterior() throw (invalid_argument){
    Data dataPosterior;
    string str_dataAtual, str_dataPosterior;
    string diaDataAtual, mesDataAtual, anoDataAtual;
    int int_mesDataAtual;
    string diaDataPosterior, mesDataPosterior, anoDataPosterior;
    int int_mesDataPosterior;
    int ultimoDiaMesAtual;
    int ultimoDiaMesAnterior;
    str_dataAtual = this->getData();

    diaDataAtual = str_dataAtual.substr(POSICAO_DIA, TAMANHO_PADRAO_DIA);
    mesDataAtual = str_dataAtual.substr(POSICAO_SEPARADOR_DIA_MES + 1, TAMANHO_PADRAO_MES);
    int_mesDataAtual = this->verificaMes(mesDataAtual);
    anoDataAtual = str_dataAtual.substr(POSICAO_SEPARADOR_MES_ANO + 1, TAMANHO_PADRAO_ANO);

    if (this->diaMeioMes()){
        if(stoi(diaDataAtual) < 9){ // quando dia anterior está entre 01 e 09
            diaDataPosterior = '0' + to_string(stoi(diaDataAtual) + 1);
        }
        else{
            diaDataPosterior = to_string(stoi(diaDataAtual) + 1);
        }
    
        mesDataPosterior = mesDataAtual;
        anoDataPosterior = anoDataAtual;
    }
    else if (this->diaComecoAno()){
        diaDataPosterior = "02";
        mesDataPosterior = mesDataAtual;
        anoDataPosterior = anoDataAtual;
    }
    else if (this->diaFimAno()){
        diaDataPosterior = "01";
        mesDataPosterior = meses[0];
        anoDataPosterior = to_string(stoi(anoDataAtual) + 1);
    }
    else if (this->diaComecoMes()){
        diaDataPosterior = "02";
        mesDataPosterior = mesDataAtual;
        anoDataPosterior = anoDataAtual;
    }
    else if (this->diaFimMes()){
        diaDataPosterior = "01";
        mesDataPosterior = meses[int_mesDataAtual];
        anoDataPosterior = anoDataAtual;
    }

    str_dataPosterior = diaDataPosterior + '/' + mesDataPosterior + '/' + anoDataPosterior;

    dataPosterior.setData(str_dataPosterior);

    return dataPosterior;
}

int Data :: comparaDatas(Data dataX,Data dataY){
    int resultadoComparacao;
    int i;
    string diaX, mesX, anoX;
    int int_mesX;
    string diaY, mesY, anoY;
    int int_mesY;
    string str_dataX = dataX.getData();
    string str_dataY = dataY.getData();
    
    diaX = str_dataX.substr(POSICAO_DIA, TAMANHO_PADRAO_DIA);
    mesX = str_dataX.substr(POSICAO_SEPARADOR_DIA_MES + 1, TAMANHO_PADRAO_MES);
    int_mesX = dataX.verificaMes(mesX);
    anoX = str_dataX.substr(POSICAO_SEPARADOR_MES_ANO + 1, TAMANHO_PADRAO_ANO);

    diaY = str_dataY.substr(POSICAO_DIA, TAMANHO_PADRAO_DIA);
    mesY = str_dataY.substr(POSICAO_SEPARADOR_DIA_MES + 1, TAMANHO_PADRAO_MES);
    int_mesY = dataY.verificaMes(mesY);
    anoY = str_dataY.substr(POSICAO_SEPARADOR_MES_ANO + 1, TAMANHO_PADRAO_ANO);

    if((diaX == diaY) && (int_mesX == int_mesY) && (anoX == anoY)){
        resultadoComparacao = 0;
    }
    else if((anoX < anoY) ||
           ((anoX == anoY) && (int_mesX < int_mesY)) ||
           ((anoX == anoY) && (int_mesX == int_mesY) && (diaX < diaY))){
        resultadoComparacao = -1;
    }
    else {
        resultadoComparacao = 1;
    }

    return resultadoComparacao;
}

void DataDeValidade::validar(string dataDeValidade) throw (invalid_argument){
    int verificadorTamanho;
    string mes;
    char ano[TAMANHO_PADRAO_ANO];
    int numMes;
    verificadorTamanho = dataDeValidade.size();

    mes = dataDeValidade.substr(0,2);
    mes[2] = '\0';
    numMes = stoi(mes, 0);

    memcpy(ano, &dataDeValidade[3],2);
    ano[2] = '\0';

    // Lança exceção se o tamanho da string dataDeValidade for diferente do tamanho esperado

    if(verificadorTamanho != TAMANHO){
        throw invalid_argument("Argumento invalido.");
    }

    // Lança exceção se não houver um separador '/' na data de validade

    else if(dataDeValidade[POSICAO_SEPARADOR] != '/'){
        throw invalid_argument("Argumento invalido.");
    }
    else{

        // Lança exceção se o valor do mês ou do ano estiver fora do intervalo definido com válido

        if(numMes < MES_MINIMO || numMes > MES_MAXIMO ||
           atoi(ano) < ANO_MINIMO || atoi(ano) > ANO_MAXIMO){
            throw invalid_argument("Argumento invalido.");
        }
    }
}

void DataDeValidade::setDataDeValidade(string dataDeValidade) throw (invalid_argument){
    validar(dataDeValidade);
    this->dataDeValidade = dataDeValidade;
}

int Estado::verificaEstado(string sigla, string *listaEstados){
    int verificador = INVALIDO;
    for(int i = 0; i < QUANTIDADE_ESTADOS; ++i){
        if( sigla == listaEstados[i]){
            verificador = VALIDO;
            break;
        }
    }

    return verificador;
}

void Estado::validar(string sigla) throw (invalid_argument){
	int i;
    int verificadorTamanho;
    int verificadorEstado = INVALIDO;
	string listaEstados[QUANTIDADE_ESTADOS] = {"AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS",
                              "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};

    verificadorTamanho = sigla.size();

    //Converte os caracteres, se do tipo letra, da string sigla para caixa alta

    for(i = 0; sigla[i] != '\0'; ++i){
        if(isalpha(sigla[i])){
            sigla[i] = toupper(sigla[i]);
        }
    }

    verificadorEstado = verificaEstado(sigla, &listaEstados[0]);

    //Lança exceção se a sigla não tiver tamanho esperado

    if(verificadorTamanho != TAMANHO_PADRAO_UF){
        throw invalid_argument("Argumento invalido.");
    }
    else{

        //Lança exceção se houver algum caracter que não seja uma letra

        for(i = 0; sigla[i] != '\0'; ++i){
            if(!isalpha(sigla[i])){
                throw invalid_argument("Argumento invalido.");
            }
        }

        // Lança exceção se a sigla não corresponder a um estado válido

        if(verificadorEstado != VALIDO){
            throw invalid_argument("Argumento invalido.");
        }
    }

}

void Estado::setEstado(string sigla) throw (invalid_argument){
    validar(sigla);
    this->sigla = sigla;
}

void Identificador::validar(string identificador) throw (invalid_argument){
    int verificadorTamanho;
    int i;

    verificadorTamanho = identificador.size();

    // Lança exceção se o tamanho da string identificador for diferente do tamanho esperado

    if (verificadorTamanho != TAMANHO){
        throw invalid_argument("Argumento invalido.");
    }
    else{

        // Lança exceção se algum caracter da string identificador não for uma letra minúscula

        for (i=0; identificador[i] != '\0'; ++i){
            if(!islower(identificador[i])){
                throw invalid_argument("Argumento invalido.");
            }
        }
    }
}

void Identificador::setIdentificador(string identificador) throw (invalid_argument){
    validar(identificador);
    this->identificador = identificador;
}

void Nome::validar(string nome) throw (invalid_argument){
    int verificadorTamanho;
    int i;

    verificadorTamanho = nome.size();

    // Lança exceção se o tamanho da string nome for maior que o tamanho máximo

    if(verificadorTamanho > TAMANHO_MAXIMO){
        throw invalid_argument("Argumento invalido.");
    }
    else{

        // Lança exceção se o primeiro caracter do nome for um ponto '.', pois assim
        // não seria possível que ele fosse precedido por uma letra

        if(nome[0] == '.'){
            throw invalid_argument("Argumento invalido.");
        }

        for(i = 0; i < verificadorTamanho; ++i){

            // Faz uma verificação sequencial, ou seja, caracter a caracter
            // Lança exceção se dado caracter não for letra, não for espaço em branco e não for ponto

            if(!isalpha(nome[i]) && nome[i] != ' ' && nome[i] != '.'){
                throw invalid_argument("Argumento invalido.");
            }

            // Faz uma verificação de adjacência, ou seja, analisa um caracter e o seu vizinho anterior

            if(i > 0){

                // Lança exceção se sendo um dado caracter um ponto, seu vizinho não for uma letra

                if(nome[i] == '.' && !isalpha(nome[i-1])){
                    throw invalid_argument("Argumento invalido.");
                }

                // Lança exceção se uma caracter que é um espaço em branco for precedido por outro espaço em branco

                if(nome[i] == ' ' && nome[i-1] == ' '){
                    throw invalid_argument("Argumento invalido.");
                }
            }
        }
    }
}

void Nome::setNome(string nome) throw (invalid_argument){
    validar(nome);
    this->nome = nome;
}

int NumeroDeCartaoDeCredito::checkLuhn(string numCartaoDeCredito) throw (invalid_argument){
    int somatorio = 0;
    int numeroDigitos = numCartaoDeCredito.size();
    int numeroParidade = (numeroDigitos - 1) % 2;
    int digito;
    char caracterDigito[2] = "\0";
    int i;

    for (i = numeroDigitos; i > 0; i--){
        caracterDigito[0] = numCartaoDeCredito[i - 1];
        digito = atoi(caracterDigito);

        // Se número de paridade = 1, então dobra o valor extraído do dígito nas posições ímpares da string do número de cartão
        // Se número de paridade = 0, então dobra o valor extraído do dígito nas posições pares da string do número de cartão

        if ( numeroParidade == (i % 2)){
            digito = digito * 2;
        }

        // Adiciona ao somatório a soma de todos os dígitos do valor da v;ariávle digito
        // Exemplo: se digito igual a 14 (caso em que o valor original (dígito 7) foi dobrado), adiciona-se ao somatório 1 + 4

        somatorio += digito / 10;
        somatorio += digito % 10;
    }

    // Retorna VALIDO se o valor do somatório for divisível por 10, confirmando que o número do cartão é válido
    // Retorna INVALIDO, do contrário

    if(somatorio % 10 == 0){
        return VALIDO;
    }
    else{
        return INVALIDO;
    }
}

int NumeroDeCartaoDeCredito::verificaExisteSomenteDigito(string contaCorrente) throw (invalid_argument){
    for (int i = 0; numCartaoDeCredito[i] != '\0'; ++i){
        if( !isdigit(numCartaoDeCredito[i]) ){
            return INVALIDO;
        }
    }

    return VALIDO;
}

void NumeroDeCartaoDeCredito::validar(string numCartaoDeCredito) throw (invalid_argument){
    int verificadorTamanho;
    int existeSomenteDigito;

    verificadorTamanho = numCartaoDeCredito.size();
    existeSomenteDigito = verificaExisteSomenteDigito(numCartaoDeCredito);


    // Lança exceção se o tamanho do string numCartaoDeCredito for diferente do tamanho esperado

    if(verificadorTamanho != TAMANHO){
        throw invalid_argument("Argumento invalido.");
    }

    // Lança exceção se houver algum caracter não numérico

    else if( !existeSomenteDigito ){
        throw invalid_argument("Argumento invalido.");
    }

    // Lança exceção se o algoritmo de Luhn não checar que o número é válido

    else if( !checkLuhn(numCartaoDeCredito)){
        throw invalid_argument("Argumento invalido.");
    }
}

void NumeroDeCartaoDeCredito::setNumeroDeCartaoDeCredito (string numCartaoDeCredito) throw (invalid_argument){
    validar(numCartaoDeCredito);
    this->numCartaoDeCredito = numCartaoDeCredito;
}

int NumeroDeContaCorrente::verificaExisteSomenteDigito(string contaCorrente) throw (invalid_argument){
    for (int i = 0; contaCorrente[i] != '\0'; ++i){
        if( !isdigit(contaCorrente[i]) ){
            return INVALIDO;
        }
    }

    return VALIDO;
}

void NumeroDeContaCorrente::validar(string contaCorrente) throw (invalid_argument){
    int existeSomenteDigito;
    int verificadorTamanho;

    verificadorTamanho = contaCorrente.size();
    existeSomenteDigito = verificaExisteSomenteDigito(contaCorrente);

    // Lança exceção se o tamanho da string contaCorrente for diferente do tamanho definido
    // ou se algum caracter da string apresentar valor diferente de 0-9

    if(verificadorTamanho != TAMANHO_MAXIMO){
        throw invalid_argument("Argumento invalido.");
    }

    // Lança exceção se houver algum caracter não numérico

    else if( !existeSomenteDigito ){
        throw invalid_argument("Argumento invalido.");
    }
}

void NumeroDeContaCorrente::setNumeroDeContaCorrente(string contaCorrente) throw (invalid_argument){
    validar(contaCorrente);
    this->contaCorrente = contaCorrente;
}

int Senha::verificaSimbolo(string senha, string* simbolos) throw (invalid_argument){
    int verificador = INVALIDO;
    string caracter;
    for (int i = 0; senha[i] != '\0'; ++i){
        for (int j = 0; j < QUANTIDADE_SIMBOLOS_PERMITIDOS; ++j){
            caracter = senha[i];
            if( caracter == simbolos[j]){
                verificador = VALIDO;
                break;
            }
        }
    }

    return verificador;
}

int Senha::verificaCaracteresObrigatorios(string senha, string* simbolosObrigatorios) throw (invalid_argument){
    bool existeDigito = INVALIDO;
    bool existeLetraMaiuscula = INVALIDO;
    bool existeLetraMinuscula = INVALIDO;
    bool existeSimbolo = INVALIDO;
    int i, j;
    string caracter;

    for(i = 0; senha[i] != '\0'; ++i){
        if( islower(senha[i]) ){
            existeLetraMinuscula = VALIDO;
        }
        else if( isupper(senha[i]) ){
            existeLetraMaiuscula = VALIDO;
        }
        else if( isdigit(senha[i]) ){
            existeDigito = VALIDO;
        }
        else{
            caracter = senha[i];
            for(j = 0; j < QUANTIDADE_SIMBOLOS_PERMITIDOS; ++j){
                if(caracter == simbolosObrigatorios[j]){
                    existeSimbolo = VALIDO;
                }
            }
        }

        if (existeDigito && existeLetraMaiuscula && existeLetraMinuscula && existeSimbolo){
            return VALIDO;
        }
    }

    return INVALIDO;
}

int Senha::verificaRepeticao(string senha) throw (invalid_argument){
    int i;
    bool caracteres[QUANTIDADE_CARACTERES];

    const static int OCORREU = 1;
    const static int SEM_MULTIPLAS_OCORRENCIAS = 0;

    // Inicializa o vetor booleano que guarda a informação da ocorrência (1) ou não ocorrência (0) de algum caracter
    // da string senha em uma posição que correponde ao número ASCII do dado caracter

    for (i = 0; i < QUANTIDADE_CARACTERES; ++i){
        caracteres[i] = 0;
    }

    for (i = 0; senha[i] != '\0'; ++i){

        // Se o caracter já tiver ocorrido, retorna 1 confirmando uma repetição, pois o loop só
        // visita uma posição no vetor caracteres quando há uma ocorrência.
        // Se ainda não houve ocorrência na posição dada, marca que ela passa a ter ocorrido.

        if(caracteres[int(senha[i])] == OCORREU){
            return 1;
        }
        else{
            caracteres[int(senha[i])] = OCORREU;
        }
    }

    return SEM_MULTIPLAS_OCORRENCIAS;
}

void Senha::validar(string senha) throw (invalid_argument){
    int verificadorTamanho;
    int verificadorSimbolo;
    int verificadorCaracteresObrigatorios;
    int verificadorRepeticao;
    int i;

    string simbolos[QUANTIDADE_SIMBOLOS_PERMITIDOS] = {"!", "#", "$", "\%", "&"};

    verificadorTamanho = senha.size();
    verificadorSimbolo = verificaSimbolo(senha, &simbolos[0]);
    verificadorCaracteresObrigatorios = verificaCaracteresObrigatorios(senha, &simbolos[0]);
    verificadorRepeticao = verificaRepeticao(senha);

    // Lança exceção se o tamanho da string senha for diferente do tamanho esperado

    if (verificadorTamanho != TAMANHO){
        throw invalid_argument("Argumento invalido.");
    }

    // Lança exceção se faltar algum caracter de algum tipo (letra, dígito e simbolo permitido)

    else if( verificadorCaracteresObrigatorios == INVALIDO){
        throw invalid_argument("Argumento invalido.");
    }

    // Lança exceção se houver repetição de caracteres

    else if( verificadorRepeticao == VALIDO){
        throw invalid_argument("Argumento invalido.");
    }
    else {

        // Lança exceção se algum caracter não for nem letra, nem dígito e nem um simbolo válido

        for (i = 0; senha[i] != '\0'; ++i){
            if(!isalnum(senha[i]) && verificadorSimbolo == INVALIDO){
                throw invalid_argument("Argumento invalido.");
            }
        }
    }
}

void Senha::setSenha(string senha) throw (invalid_argument){
    validar(senha);
    this->senha = senha;
}

int TipoDeAcomodacao::verificaAcomodacao(string acomodacao, string *acomodacoes){
    int verificador = INVALIDO;
    for(int i = 0; i < QUANTIDADE_TIPOS_ACOMODACAO; ++i){
        if( acomodacao == acomodacoes[i]){
            verificador = VALIDO;
            break;
        }
    }

    return verificador;
}


void TipoDeAcomodacao::validar(string acomodacao) throw (invalid_argument){
    int i;
    int verificadorAcomodacao;
    string acomodacoes[QUANTIDADE_TIPOS_ACOMODACAO] = {"apartamento", "casa", "flat"};

    //Converte os caracteres, se do tipo letra, da string acomodacao para caixa baixa

    for(i = 0; acomodacao[i] != '\0'; ++i){
        if(isalpha(acomodacao[i])){
            acomodacao[i] = tolower(acomodacao[i]);
        }
    }

    verificadorAcomodacao = verificaAcomodacao(acomodacao, &acomodacoes[0]);

    // Lança exceção se o nome da acomodacao não for encontrado na vetor de string acomodacoes

    if(verificadorAcomodacao == INVALIDO){
        throw invalid_argument("Argumento invalido.");
    }
}

void TipoDeAcomodacao::setTipoDeAcomodacao(string acomodacao) throw (invalid_argument){
    validar(acomodacao);
    this->acomodacao = acomodacao;
}

