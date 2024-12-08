#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * Classe base para representar uma pessoa (Passageiro ou Tripulacao)
 */
class Pessoa {
protected:
    string codigo;
    string nome;
    string telefone;

public:
    Pessoa();
    Pessoa(string nome, string telefone);
    virtual ~Pessoa() = default;

    //Metodos set para para os atributos da classe pessoa
    void setPessoa(string nome);
    void setTelefone(string telefone);

    string getPessoa();
    string getTelefone();

    int armazenaDadosEmArquivo(string arquivo, string dados);
};

#endif