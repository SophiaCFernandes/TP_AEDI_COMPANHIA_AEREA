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

/**
 * Metodo que armazena os dados da pessoa no arquivo
 * Entrada: string arquivo, string dados
 * Retorna: -1 em caso de erro, 0 em caso de sucesso
 */
int Pessoa::armazenaDadosEmArquivo(string arquivo, string dados) {
    ofstream arquivoEscrita(arquivo, ios::app);
    if (!arquivoEscrita.is_open()) {
        cerr << "Erro ao abrir o arquivo " << arquivo << " para escrita.\n";
        return -1;
    }

    arquivoEscrita << dados;
    arquivoEscrita.close();
    return 0;
}