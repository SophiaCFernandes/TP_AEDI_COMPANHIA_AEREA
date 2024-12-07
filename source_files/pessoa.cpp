#include "Pessoa.h"

/**
 * Construtor padrao da classe Pessoa
 */
Pessoa::Pessoa() {
    codigo = '\0';
    nome = '\0';
    telefone = '\0';
}

/**
 * Metodo para definir acessar e definir o atributo nome da classe pessoa
 */
void Pessoa::setPessoa(string nome){
    this->nome = nome;
}

/**
 * Metodo para definir acessar e definir o atributo telefone da classe pessoa
 */
void Pessoa::setTelefone(string telefone){
    this->telefone = telefone;
}

/**
 * Metodo para definir acessar o atributo telefone da classe pessoa
 */
string Pessoa::getPessoa(){
    return nome;
}

/**
 * Metodo para definir acessar e definir o atributo telefone da classe pessoa
 */
string Pessoa::getTelefone(){
    return telefone;
}
