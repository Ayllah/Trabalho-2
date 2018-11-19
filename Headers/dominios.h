/**
 *@file dominios.h
 *@version 1.0
 *@date 24/09/2018
 *@author Ayllah Ahmad Lopes e Juliano Balcante Pereira
 *@title Classes de domínio
 *@brief Arquivo com a descrição das classes de domínio (classes com menor nível de abstração).
 */

#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <stdexcept>
#include <string>

using namespace std;

/**
 *@brief Classe responsável por armazenar e verificar a agencia do usuário.
 *
 * Deve conter 5 caracteres e cada um destes deve ser um dígito (0-9).
 *
 */

class Agencia {
private:
	string agencia;
	const static int TAMANHO = 5;

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se a agencia fornecida pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param string que o usuário irá fornecer.
 	 */

	void validar(string) throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta a agência caso esta esteja de acordo com os padrões estabelecidos.
	 *@param string fornecida pelo usuário.
	 */

	void setAgencia(string) throw (invalid_argument);

	/**
	 *@brief Retorna a agência.
	 *@return string agencia.
	 */

    string getAgencia() const {
        return agencia;
    }

};

/**
 *@brief Classe responsável por armazenar e verificar o banco do usuário.
 *
 * Deve conter 3 caracteres e cada um destes deve ser um dígito (0-9).
 *
 */

class Banco {
private:
	string banco;
	const static int TAMANHO = 3;

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se o banco fornecido pelo usuário está de acordo
 	 *com os padrões definidos.
 	 @param string que o usuário irá fornecer.
 	 */

	void validar(string) throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta o banco caso este esteja de acordo com os padrões estabelecidos.
	 *@param string fornecida pelo usuário.
	 */

	void setBanco(string) throw (invalid_argument);

	/**
	 *@brief Retorna o banco.
	 *@return string banco.
	 */

    string getBanco() const {
        return banco;
    }

};

/**
 *@brief Classe responsável por armazenar e verificar a capacidade de acomodação.
 *
 * Deve ser um valor de 1 a 9.
 *
 */

class CapacidadeDeAcomodacao {
private:
	int capacidade;
	const static int CAPACIDADE_MAXIMA = 9;
	const static int CAPACIDADE_MINIMA = 1;

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se a capacidade de acomodação fornecida pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param inteiro fornecido pelo usuário.
     */

	void validar(int) throw (invalid_argument);

public:

 	//Métodos de acesso

 	/**
	 *@brief Seta a capidade de acomodação caso esta esteja de acordo com os padrões estabelecidos.
	 *@param inteiro fornecido pelo usuário.
	 */

	void setCapacidade(int) throw (invalid_argument);

	/**
	 *@brief Retorna a capacidade de acomodação.
	 *@return int capacidade.
	 */

    int getCapacidade() const {
        return capacidade;
    }
};

/**
 *@brief Classe responsável por armazenar e verificar a diária.
 *
 * Deve ser um valor R$ 1,00 a R$ 10.000,00.
 *
 */

class Diaria {
private:
	double preco;
	const static int PRECO_MAXIMO = 10000;
	const static int PRECO_MINIMO = 1;

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se a diária estabelecida pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param número fornecido pelo usuário.
 	 */

	void validar(double) throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta a diária caso esta esteja de acordo com os padrões estabelecidos.
	 *@param double fornecido pelo usuário.
	 */

	void setDiaria(double) throw (invalid_argument);

	/**
	 *@brief Retorna o preço da diária.
	 *@return double preco.
	 */

    double getDiaria() const {
        return preco;
    }

};

/**
 *@brief Classe responsável por armazenar e verificar a data.
 *
 * Deve ter o formato DD/MMM/AAAA (onde DD é número de 01 a 31, MMM é jan, fev, mar, abr, mai,
 * jun, jul, ago, set, out, nov ou dez e AAAA é número de 2000 a 2099) e deve considerar anos bissextos.
 *
 */

class Data {
private:
	string data;
	const static int TAMANHO = 11;
	const static int TAMANHO_PADRAO_DIA = 2;
	const static int TAMANHO_PADRAO_MES = 3;
	const static int TAMANHO_PADRAO_ANO = 4;

	const static int POSICAO_DIA = 0;
	const static int POSICAO_SEPARADOR_DIA_MES = TAMANHO_PADRAO_DIA;
	const static int POSICAO_SEPARADOR_MES_ANO = POSICAO_SEPARADOR_DIA_MES + TAMANHO_PADRAO_MES + 1;

	const static int DIA_MINIMO = 1;
	const static int DIA_MAXIMO = 31;
	const static int QUANTIDADE_MESES = 12;
	const static int ANO_MINIMO = 2000;
	const static int ANO_MAXIMO = 2099;
	const static int FEVEREIRO_NAO_BISSEXTO = 28;

	const static int VALIDO = 1;
	const static int INVALIDO = 0;

	string meses[QUANTIDADE_MESES] = {"jan", "fev", "mar", "abr",
                                  "mai", "jun", "jul", "ago",
                                  "set", "out", "nov", "dez"};
    int numeroDiasDoMes[QUANTIDADE_MESES] = {31, 29, 31, 30,
                                         31, 30, 31, 31,
                                         30, 31, 30, 31};


	//Métodos auxiliares de validação

	/**
	 *@brief Método responsável por verificar se o mês fornecido está de acordo com os padrões definidos.
	 */

	int verificaMes(string);

	/**
	 *@brief Método responsável por verificar se o ano fornecido é ou não bissexto.
	 */

	int verificaBissexto(int) throw (invalid_argument);

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se a data fornecida pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param string fornecida pelo usuário.
     */

	void validar(string) throw (invalid_argument);

	//Métodos auxiliares para verificar posição relativa de uma data no calendário

	bool diaComecoMes() throw (invalid_argument);
	bool diaMeioMes() throw (invalid_argument);
	bool diaFimMes() throw (invalid_argument);
	bool diaComecoAno() throw (invalid_argument);
	bool diaFimAno() throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta a data caso esta esteja de acordo com os padrões estabelecidos.
	 *@param string fornecida pelo usuário.
	 */

	void setData(string) throw (invalid_argument);

	/**
	 *@brief Retorna a data.
	 *@return string data.
	 */

    string getData() const {
        return data;
    }

	/**
	 *@brief Retorna a data do dia anterior.
	 *@return Data dataAnterior.
	 */

	Data getDataAnterior() throw (invalid_argument);

	/**
	 *@brief Retorna a data do dia posterior.
	 *@return Data dataPosterior.
	 */

	Data getDataPosterior() throw (invalid_argument);

	/**
	 *@brief Retorna um inteiro indicando o tipo de relação comparativa entre a primeira e a segunda Data.
	 *-1: menor que
	 *0: igual
	 *1: maior que
	 *@return int resultadoComparacao.
	 */

	static int comparaDatas(Data, Data); 

};

/**
 *@brief Classe responsável por armazenar e verificar a data de validade.
 *
 * Deve ter o formato MM/AA (onde MM é número de 01 a 12 e AA é número de 00 a 99).
 *
 */

class DataDeValidade {
private:
	string dataDeValidade;
	const static int TAMANHO = 5;
	const static int TAMANHO_PADRAO_MES = 2;
	const static int POSICAO_INICIAL_MES = 0;
	const static int POSICAO_FINAL_MES = 2;
	const static int POSICAO_SEPARADOR = 2;
	const static int TAMANHO_PADRAO_ANO = 2;
	const static int POSICAO_INICIAL_ANO = 3;
	const static int POSICAO_FINAL_ANO = 4;

	const static int MES_MINIMO = 1;
	const static int MES_MAXIMO = 12;
	const static int ANO_MINIMO = 0;
	const static int ANO_MAXIMO = 99;

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se a data de validade fornecida pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param string fornecida pelo usuário.
     */

	void validar(string) throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta a data de validade caso esta esteja de acordo com os padrões estabelecidos.
	 *@param string fornecida pelo usuário.
	 */

	void setDataDeValidade(string) throw (invalid_argument);

	/**
	 *@brief Retorna a data de validade.
	 *@return string dataDeValidade.
	 */

    string getDataDeValidade() const {
        return dataDeValidade;
    }

};

/**
 *@brief Classe responsável por armazenar e verificar o estado.
 *
 * Deve ser uma das siglas AC, AL, AP, AM, BA, CE, DF, ES, GO, MA, MT, MS, MG, PA, PB, PR, PE,
 * PI, RJ, RN, RS, RO, RR, SC, SP, SE, TO
 *
 */

class Estado {
private:
	string sigla;
	const static int TAMANHO_PADRAO_UF = 2;
	const static int QUANTIDADE_ESTADOS = 27;

	const static int VALIDO = 1;
	const static int INVALIDO = 0;

	//Método auxiliar da função validação

	/**
	 *@brief Método responsável por verificar se a sigla fornecida corresponde a uma das siglas definidas.
	 */

	int verificaEstado(string, string* );

	/**
 	 *@brief Método responsável por verificar se o estado fornecido pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param string fornecida pelo usuário.
     */

	//Método responsável por validação

	void validar(string) throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta o estado caso esta esteja de acordo com os padrões estabelecidos.
	 *@param string fornecida pelo usuário.
	 */

	void setEstado(string) throw (invalid_argument);

	/**
	 *@brief Retorna o Estado.
	 *@return string sigla.
	 */

    string getEstado() const {
        return sigla;
    }


};

/**
 *@brief Classe responsável por armazenar e verificar o identificador do usuário.
 *
 * Deve conter 5 caracteres e cada um destes deve ser uma letra minúscula (a-z).
 *
 */

class Identificador {
private:
	string identificador;
	const static int TAMANHO = 5;

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se o identificador fornecido pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param string fornecida pelo usuário.
     */

	void validar(string) throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta o identificador caso esta esteja de acordo com os padrões estabelecidos.
	 *@param string fornecida pelo usuário.
	 */

	void setIdentificador(string) throw (invalid_argument);

	/**
	 *@brief Retorna o identificador do usuário.
	 *@return string identificador.
	 */

    string getIdentificador() const {
        return identificador;
    }


};

/**
 *@brief Classe responsável por armazenar e verificar o nome do usuário ou de cidade.
 *
 * Deve conter no máximo 15 caracteres e cada um destes pode ser letra, espaço ou ponto.
 * Pelos menos um caracter é letra, não deve haver espaços seguidos e o ponto deve ser precedido por letra.
 *
 */

class Nome {
private:
	string nome;
	const static int TAMANHO_MAXIMO = 15;

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se o nome fornecido pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param string fornecida pelo usuário.
     */

	void validar(string) throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta o nome caso esta esteja de acordo com os padrões estabelecidos.
	 *@param string fornecida pelo usuário.
	 */

	void setNome(string) throw (invalid_argument);

	/**
	 *@brief Retorna o nome do usuário.
	 *@return string nome.
	 */

    string getNome() const {
        return nome;
    }


};

/**
 *@brief Classe responsável por armazenar e verificar o número de cartão de crédito do usuário.
 *
 * Deve conter 16 caracteres e cada um destes deve ser um dígito (0-9).
 * O número de cartão de crédito deve ser válido de acordo com o algoritmo de Luhn.
 *
 */

class NumeroDeCartaoDeCredito {
private:
	string numCartaoDeCredito;
	const static int TAMANHO = 16;

	const static int VALIDO = 1;
	const static int INVALIDO = 0;

	//Métodos auxiliares da validação

	/**
	 *@brief Método responsável por verificar se o número sw cartão de crédito está de acordo
	 * com o algoritmo de Luhn.
	 */

	int checkLuhn(string) throw (invalid_argument);

	/**
	 *@brief Método responsável por verificar se todos os caracteres fornecidos são dígitos.
	 */

	int verificaExisteSomenteDigito(string) throw (invalid_argument);

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se o número de cartão de crédito fornecido pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param string fornecida pelo usuário.
     */

	void validar(string) throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta o número de cartão de crédito caso esta esteja de acordo com os padrões estabelecidos.
	 *@param string fornecida pelo usuário.
	 */

	void setNumeroDeCartaoDeCredito(string) throw (invalid_argument);

	/**
	 *@brief Retorna o número de cartão de crédito.
	 *@return string numCartãoDeCredito.
	 */

    string getNumeroDeCartaoDeCredito() const {
        return numCartaoDeCredito;
    }

};

/**
 *@brief Classe responsável por armazenar e verificar o número de conta corente do usuário.
 *
 * Deve conter 6 caracteres e cada um destes deve ser um dígito (0-9).
 *
 */

class NumeroDeContaCorrente {
private:
	string contaCorrente;
	const static int TAMANHO_MAXIMO = 6;

	const static int VALIDO = 1;
	const static int INVALIDO = 0;

	//Método auxiliar da validação

	/**
	 *@brief Método responsável por verificar se todos os caracteres fornecidos são dígitos.
	 */

	int verificaExisteSomenteDigito(string) throw (invalid_argument);

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se o número de conta corrente fornecido pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param string fornecida pelo usuário.
     */

	void validar(string) throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta o número de conta corrente caso esta esteja de acordo com os padrões estabelecidos.
	 *@param string fornecida pelo usuário.
	 */

	void setNumeroDeContaCorrente(string) throw (invalid_argument);

	/**
	 *@brief Retorna o número de conta corrente.
	 *@return string contaCorrente.
	 */

    string getNumeroDeContaCorrente() const {
        return contaCorrente;
    }

};

/**
 *@brief Classe responsável por armazenar e verificar a senha do usuário.
 *
 * Deve conter 8 caracteres e cada um destes pode ser um símbolo (! # $ % &), uma letra
 * maiúscula ou minúscula (A–Z a–z) ou um dígito (0-9).
 * Não deve haver caracters repetidos. Há, pelo menos, uma letra maiúscula, uma minúscula, um dígito e
 * um símbolo.
 *
 */

class Senha {
private:
	string senha;
	const static int TAMANHO = 8;
	const static int QUANTIDADE_SIMBOLOS_PERMITIDOS = 5;
	const static int QUANTIDADE_CARACTERES = 256;

	const static int VALIDO = 1;
	const static int INVALIDO = 0;

	//Métodos auxiliares da validação

	/**
	 *@brief Método responsável por verificar se os símbolos fornecidos estão de acordo com os estabelecidos.
	 */

	int verificaSimbolo(string, string* ) throw (invalid_argument);

	/**
	 *@brief Método responsável por verificar se os caracteres fornecidos estão de acordo com o padrão definido.
	 */

	int verificaCaracteresObrigatorios(string, string* ) throw (invalid_argument);

	/**
	 *@brief Método responsável por verificar se há caracteres repetidos.
	 */

	int verificaRepeticao(string) throw (invalid_argument);

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se a senha fornecida pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param string fornecida pelo usuário.
     */

	void validar(string) throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta a senha caso esta esteja de acordo com os padrões estabelecidos.
	 *@param string fornecida pelo usuário.
	 */

	void setSenha(string) throw (invalid_argument);

	/**
	 *@brief Retorna a senha.
	 *@return string senha.
	 */

    string getSenha() const {
        return senha;
    }

};

/**
 *@brief Classe responsável por armazenar e verificar o tipo de acomodação.
 *
 * Deve ser um dos seguintes tipos: Apartamento, Casa ou Flat.
 *
 */

class TipoDeAcomodacao {
private:
	string acomodacao;
	const static int QUANTIDADE_TIPOS_ACOMODACAO = 3;

	const static int VALIDO = 1;
	const static int INVALIDO = 0;

	//Método auxiliar da validação

	/**
	 *@brief Método responsável por verificar se a acomodação fornecida se refere a uma das estabelecidas.
	 */

	int verificaAcomodacao(string, string* );

	//Método responsável por validação

	/**
 	 *@brief Método responsável por verificar se o tipo de acomodação fornecido pelo usuário está de acordo
 	 *com os padrões definidos.
 	 *@param string fornecida pelo usuário.
     */

	void validar(string) throw (invalid_argument);

public:

	//Métodos de acesso

	/**
	 *@brief Seta o tipo de acomodação caso esta esteja de acordo com os padrões estabelecidos.
	 *@param string fornecida pelo usuário.
	 */

	void setTipoDeAcomodacao(string) throw (invalid_argument);

	/**
	 *@brief Retorna o tipo de acomodação.
	 *@return string acomodacao.
	 */

    string getTipoDeAcomodacao() const {
        return acomodacao;
    }

};

#endif // DOMINIOS_H_INCLUDED

