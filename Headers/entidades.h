/**
 *@file entidades.h
 *@version 1.0
 *@date 24/09/2018
 *@author Ayllah Ahmad Lopes e Juliano Balcante Pereira
 *@title Classes de entidade
 *@brief Arquivo com a descrição das classes de entidade (classes que armazenarão dados).
 */

#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include <string>

using namespace std;

/**
 *@brief Classe responsável por armazenar as informações do usuário.
 */

class Usuario {
private:
    Nome nomeUsuario;
    Identificador identificadorUsuario;
    Senha senhaUsuario;

public:

    /**
     *@brief Seta o objeto Nome da classe Usuario.
     *@param nomeUsuario é o nome fornecido pelo usuário.
     */

    void setNomeUsuario(Nome nomeUsuario){
        this->nomeUsuario = nomeUsuario;
    }

    /**
     *@brief Retorna o nome do objeto da classe Usuario.
     *@return Nome nomeUsuario (objeto da classe).
     */

    Nome getNomeUsuario() const {
        return nomeUsuario;
    }

    /**
     *@brief Seta o objeto Identificador da classe Usuario.
     *@param identificadorUsario é o identificador fornecido pelo usuário.
     */

    void setIdentificadorUsuario(Identificador identificadorUsuario){
        this->identificadorUsuario = identificadorUsuario;
    }

    /**
     *@brief Retorna o identificador do objeto da classe Usuario.
     *@return Identificador identificadorUsuario (objeto da classe).
     */

    Identificador getIdentificadorUsuario() const {
        return identificadorUsuario;
    }

    /**
     *@brief Seta o objeto Senha da classe Usuario.
     *@param senhauaUsario é a senha fornecida pelo usuário.
     */

    void setSenhaUsuario(Senha senhaUsuario){
        this->senhaUsuario = senhaUsuario;
    }

    /**
     *@brief Retorna a senha do objeto da classe Usuario.
     *@return Senha senhaUsuario (objeto da classe).
     */

    Senha getSenhaUsuario() const {
        return senhaUsuario;
    }
};

/**
 *@brief Classe responsável por armazenar as informações da acomodação.
 */

class Acomodacao {
private:
	Identificador identificadorAcomodacao;
	TipoDeAcomodacao acomodacaoAcomodacao;
	CapacidadeDeAcomodacao capacidadeAcomodacao;
	Data dataInicioAcomodacao;
	Data dataTerminoAcomodacao;
	Nome cidadeAcomodacao;
	Estado siglaAcomodacao;
	Diaria precoAcomodacao;

public:

    /**
     *@brief Seta o objeto Identificador da classe Acomodação.
     *@param identificadorAcomodacao é o identificador fornecido pelo usuário.
     */

	void setIdentificadorAcomodacao(Identificador identificadorAcomodacao){
        this->identificadorAcomodacao = identificadorAcomodacao;
    }

    /**
     *@brief Retorna o identificador do objeto da classe Acomodacao.
     *@return Identificador identificadorAcomodacao (objeto da classe).
     */

    Identificador getIdentificadorAcomodacao() const {
        return identificadorAcomodacao;
    }

    /**
     *@brief Seta o objeto TipoDeAcomodacao da classe Acomodação.
     *@param acomodacaoAcomodacao é o tipo de acomodação fornecida pelo usuário.
     */

    void setTipoAcomodacao(TipoDeAcomodacao acomodacaoAcomodacao){
        this->acomodacaoAcomodacao = acomodacaoAcomodacao;
    }

    /**
     *@brief Retorna o acomodacao do objeto da classe Acomodacao.
     *@return TipoDeAcomodacao acomodacaoAcomodacao (objeto da classe).
     */

    TipoDeAcomodacao getTipoAcomodacao() const {
        return acomodacaoAcomodacao;
    }

    /**
     *@brief Seta o objeto CapacidadeDeAcomodacao da classe Acomodação.
     *@param capacidadeAcomodacao é a capacidade de acomodação fornecida pelo usuário.
     */

    void setCapacidadeAcomodacao(CapacidadeDeAcomodacao capacidadeAcomodacao){
        this->capacidadeAcomodacao = capacidadeAcomodacao;
    }

    /**
     *@brief Retorna a capacidade do objeto da classe Acomodacao.
     *@return CapacidadeDeAcomodacao capacidadeAcomodacao (objeto da classe).
     */

    CapacidadeDeAcomodacao getCapacidadeAcomodacao() const {
        return capacidadeAcomodacao;
    }

    /**
     *@brief Seta o objeto Data da classe Acomodação.
     *@param dataInicioAcomodacao é a data fornecida pelo usuário.
     */

    void setDataInicioAcomodacao(Data dataInicioAcomodacao){
        this->dataInicioAcomodacao = dataInicioAcomodacao;
    }

    /**
     *@brief Retorna a data do objeto da classe Acomodacao.
     *@return Data dataInicioAcomodacao (objeto da classe).
     */

    Data getDataInicioAcomodacao() const {
        return dataInicioAcomodacao;
    }

    /**
     *@brief Seta o objeto Data da classe Acomodação.
     *@param dataTerminoAcomodacao é a data pelo usuário.
     */

    void setDataTerminoAcomodacao(Data dataTerminoAcomodacao){
        this->dataTerminoAcomodacao = dataTerminoAcomodacao;
    }

    /**
     *@brief Retorna a data do objeto da classe Acomodacao.
     *@return Data dataTerminoAcomodacao (objeto da classe).
     */

    Data getDataTerminoAcomodacao() const {
        return dataTerminoAcomodacao;
    }

    /**
     *@brief Seta o objeto Nome da classe Acomodação.
     *@param cidadeAcomodacao é o nome fornecido pelo usuário.
     */

    void setNomeCidadeAcomodacao(Nome cidadeAcomodacao){
        this->cidadeAcomodacao = cidadeAcomodacao;
    }

    /**
     *@brief Retorna a cidade do objeto da classe Acomodacao.
     *@return Nome cidadeAcomodacao (objeto da classe).
     */

    Nome getNomeCidadeAcomodacao() const {
        return cidadeAcomodacao;
    }

    /**
     *@brief Seta o objeto Estado da classe Acomodação.
     *@param siglaAcomodacao é o estado fornecido pelo usuário.
     */

    void setEstadoAcomodacao(Estado siglaAcomodacao){
        this->siglaAcomodacao = siglaAcomodacao;
    }

    /**
     *@brief Retorna a sigla do objeto da classe Acomodacao.
     *@return Estado siglaAcomodacao (objeto da classe).
     */

    Estado getEstadoAcomodacao() const {
        return siglaAcomodacao;
    }

    /**
     *@brief Seta o objeto Diaria da classe Acomodação.
     *@param precoAcomodacao é a diária fornecida pelo usuário.
     */

    void setDiariaAcomodacao(Diaria precoAcomodacao){
        this->precoAcomodacao = precoAcomodacao;
    }

    /**
     *@brief Retorna o preco do objeto da classe Acomodacao.
     *@return Diaria precoAcomodacao (objeto da classe).
     */

    Diaria getDiariaAcomodacao() const {
        return precoAcomodacao;
    }
};

/**
 *@brief Classe responsável por armazenar as informações do cartão de crédito.
 */

class CartaoDeCredito {
private:
	NumeroDeCartaoDeCredito numCartaoCredito;
	DataDeValidade dataDeValidadeCartaoDeCredito;

public:

    /**
     *@brief Seta o objeto NumeroDeCartaoDeCredito da classe CartaoDeCredito.
     *@param numCartapCredito é o número de cartão de crédito fornecido pelo usuário.
     */

	void setNumeroCartaoCredito(NumeroDeCartaoDeCredito numCartaoCredito){
        this->numCartaoCredito = numCartaoCredito;
    }

    /**
     *@brief Retorna o número de cartão de crédito do objeto da classe CartaoDeCredito.
     *@return NumeroDeCartaoDeCredito numCartaoCredito (objeto da classe).
     */

    NumeroDeCartaoDeCredito getNumeroCartaoCredito() const {
        return numCartaoCredito;
    }

    /**
     *@brief Seta o objeto dataDeValidade da classe CartaoDeCredito.
     *@param dataDeValidadeCartaoDeCredito é a data de validade fornecida pelo usuário.
     */

    void setDataDeValidadeCartaoDeCredito(DataDeValidade dataDeValidadeCartaoDeCredito){
        this->dataDeValidadeCartaoDeCredito = dataDeValidadeCartaoDeCredito;
    }

    /**
     *@brief Retorna a data de validade do objeto da classe CartaoDeCredito.
     *@return DataDeValidade dataDeValidadeCartaoDeCredito (objeto da classe).
     */

    DataDeValidade getDataDeValidadeCartaoDeCredito() const {
        return dataDeValidadeCartaoDeCredito;
    }
};

/**
 *@brief Classe responsável por armazenar as informações da conta corrente.
 */

class ContaCorrente {
private:
	NumeroDeContaCorrente numeroContaCorrente;
	Agencia agenciaContaCorrente;
	Banco bancoContaCorrente;

public:

    /**
     *@brief Seta o objeto NumeroDeContaCorrente da classe ContaCorrente.
     *@param numeroContaCorrente é o número de conta corrente fornecido pelo usuário.
     */

	void setNumeroContaCorrente(NumeroDeContaCorrente numeroContaCorrente){
        this->numeroContaCorrente = numeroContaCorrente;
    }

    /**
     *@brief Retorna o número de conta corrente do objeto da classe ContaCorrente.
     *@return NumeroDeContaCorrente numeroContaCorrente (objeto da classe).
     */

    NumeroDeContaCorrente getNumeroContaCorrente() const {
        return numeroContaCorrente;
    }

    /**
     *@brief Seta o objeto Agencia da classe ContaCorrente.
     *@param agenciaContaCorrente é a agência fornecida pelo usuário.
     */

    void setAgenciaContaCorrente(Agencia agenciaContaCorrente){
        this->agenciaContaCorrente = agenciaContaCorrente;
    }

    /**
     *@brief Retorna a agência do objeto da classe ContaCorrente.
     *@return Agencia agenciaContaCorrente (objeto da classe).
     */

    Agencia getAgenciaContaCorrente() const {
        return agenciaContaCorrente;
    }

    /**
     *@brief Seta o objeto Banco da classe ContaCorrente.
     *@param bancoContaCorrente é o banco fornecido pelo usuário.
     */

    void setBancoContaCorrente(Banco bancoContaCorrente){
        this->bancoContaCorrente = bancoContaCorrente;
    }

    /**
     *@brief Retorna o banco do objeto da classe ContaCorrente.
     *@return Banco bancoContaCorrente (objeto da classe).
     */

    Banco getBancoContaCorrente() const {
        return bancoContaCorrente;
    }
};

class Reserva{
private:
    Data dataInicioReserva;
    Data dataTerminoReserva;

public:
    /**
     *@brief Seta o objeto Data da classe Reserva.
     *@param dataInicioReserva é a data fornecida pelo usuário.
     */

    void setDataInicioReserva(Data dataInicioReserva){
        this->dataInicioReserva = dataInicioReserva;
    }

    /**
     *@brief Retorna a data do objeto da classe Reserva.
     *@return Data dataInicioReserva (objeto da classe).
     */

    Data getDataInicioReserva() const {
        return dataInicioReserva;
    }

    /**
     *@brief Seta o objeto Data da classe Reserva.
     *@param dataTerminoReserva é a data pelo usuário.
     */

    void setDataTerminoReserva(Data dataTerminoReserva){
        this->dataTerminoReserva = dataTerminoReserva;
    }

    /**
     *@brief Retorna a data do objeto da classe Reserva.
     *@return Data dataTerminoReserva (objeto da classe).
     */

    Data getDataTerminoReserva() const {
        return dataTerminoReserva;
    }

};

class Disponibilidade{
private:
    Data dataInicioDisponibilidade;
    Data dataTerminoDisponibilidade;

public:
    /**
     *@brief Seta o objeto Data da classe Disponibilidade.
     *@param dataInicioDisponibilidade é a data fornecida pelo usuário.
     */

    void setDataInicioDisponibilidade(Data dataInicioDisponibilidade){
        this->dataInicioDisponibilidade = dataInicioDisponibilidade;
    }

    /**
     *@brief Retorna a data do objeto da classe Disponibilidade.
     *@return Data dataInicioDisponibilidade (objeto da classe).
     */

    Data getDataInicioDisponibilidade() const {
        return dataInicioDisponibilidade;
    }

    /**
     *@brief Seta o objeto Data da classe Disponibilidade.
     *@param dataTerminoDisponibilidade é a data pelo usuário.
     */

    void setDataTerminoDisponibilidade(Data dataTerminoDisponibilidade){
        this->dataTerminoDisponibilidade = dataTerminoDisponibilidade;
    }

    /**
     *@brief Retorna a data do objeto da classe Disponibilidade.
     *@return Data dataTerminoDisponibilidade (objeto da classe).
     */

    Data getDataTerminoDisponibilidade() const {
        return dataTerminoDisponibilidade;
    }

    bool comparaDisponibilidade(Disponibilidade, Disponibilidade) const;
};

#endif // ENTIDADES_H_INCLUDED

