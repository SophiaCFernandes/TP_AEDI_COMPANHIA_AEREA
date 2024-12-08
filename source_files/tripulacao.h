#ifndef TRIPULACAO_H
#define TRIPULACAO_H

#include "pessoa.h"
#include <vector>

/**
 * Classe Tripulacao que herda de Pessoa
 */
class Tripulacao : public Pessoa {
private:
    string cargo;

public:
    Tripulacao();
    string criaStringDeDados();

    void setCargo(string cargo);
    string getCargo();

    void setCodigo();
    void setCodigo(string codigo);
    
    string getCodigo();

    void mostrarPessoa();
    void adicionaTripulacao();
    void buscaTripulacao(string codigo);
    void atulizaTripulacao(string codigo, Tripulacao &p);
    void excluirTripulacao(string codigo, Tripulacao &p);
};

#endif