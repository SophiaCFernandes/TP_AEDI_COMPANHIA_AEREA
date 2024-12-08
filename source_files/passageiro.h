#ifndef PASSAGEIRO_H
#define PASSAGEIRO_H

#include "pessoa.h"
#include <vector>

/**
 * Classe Passageiro que herda de Pessoa
 */
class Passageiro : public Pessoa {
private:
    string endereco;
    int pontosDeFidelidade;

public:
    Passageiro();
    string criaStringDeDados();

    void setEndereco(string endereco);
    string getEndereco();

    void setCodigo();
    string getCodigo();

    void mostrarPessoa();
    void adicionaPassageiro(Passageiro &p);
    void buscaPassageiro(string codigo);
    void atulizaPassageiro(string codigo, Passageiro &p);
};

#endif