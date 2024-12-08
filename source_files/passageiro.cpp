#include "passageiro.h"

#define FILE_PASSAGEIRO "../data_files/passageiro.txt"

int maiorCodigo = 0;

/**
 * Construtor padrao da classe Passageiro
 */
Passageiro::Passageiro():Pessoa(){
    endereco = "\0";
    pontosDeFidelidade = 0;
}

/**
 * Metodo que cria a string de dados para armazenamento no arquivo
 */
string Passageiro::criaStringDeDados() {
    return this->codigo + "," + 
    this->nome + "," + 
    this->telefone + "," +
    this->endereco + "," + 
    to_string(this->pontosDeFidelidade) + 
    ";\n";
}

/**
 * Metodo para definir acessar e definir o atributo endereco da classe pessoa
 */
void Passageiro::setEndereco(string endereco){
    this->endereco = endereco;
}

/**
 * Metodo para definir acessar o atributo endereco da classe pessoa
 */
string Passageiro::getEndereco(){
    return endereco;
}

/**
 * Metodo para definir acessar e definir o atributo codigo da classe pessoa
 */
void Passageiro::setCodigo(){
    this->codigo = "P" + to_string(maiorCodigo++);
}

/**
 * Metodo para definir acessar o atributo codigo da classe pessoa
 */
string Passageiro::getCodigo(){
    return codigo;
}

/**
 * Metodo para exibir os atributos da classe pessoa
 */
void Passageiro::mostrarPessoa(){
    cout << "Nome da pessoa: " << getPessoa() << endl;
    cout << "Telefone: " << getTelefone() << endl;
    cout << "Endereco: " << getEndereco() << endl;
    cout << "Codigo: " << getCodigo() << endl;
}

/**
 * Metodo para adicionar novos passageiros
 */
void Passageiro::adicionaPassageiro(Passageiro &p){
    
    cout << "Digite o nome do passageiro: ";
    cin.ignore(); //Limpa o buffer de entrada do primeiro getline
    getline(cin, nome);
    p.setPessoa(nome);

    cout << "Digite o telefone do passageiro: ";
    getline(cin, telefone);
    p.setTelefone(telefone);

    cout << "Digite o endereco do passageiro: ";
    getline(cin, endereco);
    p.setEndereco(endereco);
    p.setCodigo();

    cout << "Cadastro adicionado com sucesso!" << endl;
    
    if(p.armazenaDadosEmArquivo(FILE_PASSAGEIRO, p.criaStringDeDados()) == -1){
        cout << "\nErro ao salvar em arquivo!\n";
    }
    else{
        cout << "\nInformacoes salvas em arquivo!\n";
    }
}

/**
 * Metodo para buscar novos passageiros
 */
void Passageiro::buscaPassageiro(string codigo) {
    bool encontrado = false;
    string linha;

    ifstream arq_entrada(FILE_PASSAGEIRO);

    if (!arq_entrada.is_open()) {
        cout << "Erro ao abrir o arquivo de passageiros para leitura" << endl;
        return;
    }

    while (getline(arq_entrada, linha)) {
        // Verifica se a linha contem o codigo do passageiro
        if (linha.find(codigo + ",") == 0) {
            encontrado = true;

            // Divide a linha em partes para preencher os atributos
            stringstream ss(linha);
            string parte;
            vector<string> partes;

            while (getline(ss, parte, ',')) {
                partes.push_back(parte);
            }

            // Preenche os atributos do objeto atual
            if (partes.size() >= 4) { // Certifica que ha ao menos 4 partes
                setCodigo();
                setPessoa(partes[1]);    // Nome
                setTelefone(partes[2]);  // Telefone
                setEndereco(partes[3]);  // Endereco

                cout << "Passageiro encontrado com as seguintes informacoes:\n";
                mostrarPessoa();// Exibe as informacoes
            }
            break;
        }
    }

    arq_entrada.close();

    if (!encontrado) {
        cout << "Passageiro com codigo " << codigo << " nao encontrado." << endl;
    }
}


