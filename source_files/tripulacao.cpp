#include "tripulacao.h"

#define FILE_TRIPULACAO "../data_files/tripulacao.txt"

const string PILOTO = "Piloto";
const string COPILOTO = "Copiloto";
const string COMISSARIO = "Comissario";

/**
 * Construtor padrao da classe Tripulacao
 */
Tripulacao::Tripulacao():Pessoa(){
    cargo = "\0";
}

/**
 * Metodo que cria a string de dados para armazenamento no arquivo
 */
string Tripulacao::criaStringDeDados() {
    return this->codigo + "," + 
    this->nome + "," + 
    this->telefone + "," +
    this->cargo + ";\n";
}

/**
 * Metodo para definir acessar e definir o atributo cargo da classe tripulacao
 */
void Tripulacao::setCargo(string cargo){
    this->cargo = cargo;
}

/**
 * Metodo para definir acessar o atributo endereco da classe tripulacao
 */
string Tripulacao::getCargo(){
    return cargo;
}

/**
 * Metodo para definir acessar e definir o atributo codigo da classe pessoa
 */
void Tripulacao::setCodigo() {
    int maiorCodigoAtual = 0;
    string linha;

    // Abre o arquivo para leitura
    ifstream arq_entrada(FILE_TRIPULACAO);

    if (!arq_entrada.is_open()) {
        cout << "Arquivo de tripulacao nao encontrado. Criando um novo codigo inicial." << endl;
    } else {
        // Percorre todas as linhas do arquivo
        while (getline(arq_entrada, linha)) {
            // Ignora linhas vazias
            if (linha.empty()) {
                continue;
            }

            // Extrai o codigo (considerando que o codigo esta antes da primeira virgula)
            size_t pos = linha.find(",");
            if (pos != string::npos) {
                string codigoExtraido = linha.substr(0, pos);

                // Verifica o prefixo do codigo e tenta extrair o numero
                try {
                    if (codigoExtraido.rfind("PT", 0) == 0 ||  // Prefixo "PT"
                        codigoExtraido.rfind("CP", 0) == 0 ||  // Prefixo "CP"
                        codigoExtraido.rfind("CS", 0) == 0) {  // Prefixo "CS"
                        int codigoNumerico = stoi(codigoExtraido.substr(2)); // Ignora os 2 primeiros caracteres
                        if (codigoNumerico > maiorCodigoAtual) {
                            maiorCodigoAtual = codigoNumerico;
                        }
                    }
                } catch (const std::invalid_argument &e) {
                    // Ignora a linha se nao for possivel converter
                    continue;
                } catch (const std::out_of_range &e) {
                    // Ignora se o numero estiver fora do intervalo
                    continue;
                }
            }
        }

        arq_entrada.close();
    }

    // Define o novo codigo incrementando o maior codigo encontrado
    string prefixo;
    if (cargo == "Piloto") {
        prefixo = "PT";
    } else if (cargo == "Copiloto") {
        prefixo = "CP";
    } else if (cargo == "Comissario") {
        prefixo = "CS";
    } else {
        cout << "Cargo invalido ao gerar o codigo." << endl;
        return;
    }

    this->codigo = prefixo + to_string(maiorCodigoAtual + 1);
}


/**
 * Metodo auxiliar para setar codigo na busca
 */
void Tripulacao::setCodigo(string codigo) {
    if(codigo == PILOTO || codigo == COPILOTO || codigo == COMISSARIO){
        this->codigo = codigo;
    }
}

/**
 * Metodo para definir acessar o atributo codigo da classe tripulacao
 */
string Tripulacao::getCodigo(){
    return codigo;
}

/**
 * Metodo para exibir os atributos da classe tripulacao
 */
void Tripulacao::mostrarPessoa(){
    cout << "Nome da pessoa: " << getPessoa() << endl;
    cout << "Telefone: " << getTelefone() << endl;
    cout << "Cargo: " << getCargo() << endl;
    cout << "Codigo: " << getCodigo() << endl;
}

/**
 * Metodo para adicionar novos tripulacao
 */
void Tripulacao::adicionaTripulacao() {
    string nome, telefone, cargo; // Declarando as variaveis localmente

    cout << "Digite o nome da tripulacao: ";
    cin.ignore();
    getline(cin, nome);
    setPessoa(nome);

    cout << "Digite o telefone da tripulacao: ";
    getline(cin, telefone);
    setTelefone(telefone);

    cout << "Digite o cargo da tripulacao (PT - PILOTO | CP - COPILOTO | CS - COMISSARIO): ";
    getline(cin, cargo);

    if (cargo == "PT") {
        cargo = "Piloto";
    } else if (cargo == "CP") {
        cargo = "Copiloto";
    } else if (cargo == "CS") {
        cargo = "Comissario";
    } else {
        cout << "Cargo invalido. Cadastro cancelado." << endl;
        return;
    }

    setCargo(cargo);
    setCodigo(); // Metodo da classe para definir o codigo
    cout << "Cadastro adicionado com sucesso!" << endl;

    if (armazenaDadosEmArquivo(FILE_TRIPULACAO, criaStringDeDados()) == -1) {
        cout << "\nErro ao salvar em arquivo!\n";
    } else {
        cout << "\nInformacoes salvas em arquivo!\n";
    }
}


/**
 * Metodo para buscar novos passageiros
 */
void Tripulacao::buscaTripulacao(string codigo) {
    bool encontrado = false;
    string linha;

    ifstream arq_entrada(FILE_TRIPULACAO);

    if (!arq_entrada.is_open()) {
        cout << "Erro ao abrir o arquivo de passageiros para leitura" << endl;
        return;
    }

    while (getline(arq_entrada, linha)) {
        // Verifica se a linha contem o codigo do tripulacao
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
                setCodigo(codigo);
                setPessoa(partes[1]);    // Nome
                setTelefone(partes[2]);  // Telefone
                setCargo(partes[3]);  // Cargo

                cout << "Tripulacao encontrado com as seguintes informacoes:\n";
                mostrarPessoa();// Exibe as informacoes
            }
            break;
        }
    }

    arq_entrada.close();

    if (!encontrado) {
        cout << "Tripulacao com codigo " << codigo << " nao encontrado." << endl;
    }
}

/**
 * Metodo para atualizar novos passageiros
 */
void Tripulacao::atulizaTripulacao(string codigo, Tripulacao &p) {
    // Primeiro busca o tripulacao pelo codigo
    p.buscaTripulacao(codigo);

    // Pergunta se deseja atualizar os dados
    char escolha;
    cout << "Deseja atualizar as informacoes deste tripulacao? (s/n): ";
    cin >> escolha;

    if (tolower(escolha) != 's') {
        cout << "Atualizacao cancelada." << endl;
        return;
    }

    // Solicita novas informacoes
    string novoNome, novoTelefone, novoCargo;

    cout << "Digite o novo nome (ou pressione Enter para manter o atual): ";
    cin.ignore();
    getline(cin, novoNome);

    cout << "Digite o novo telefone (ou pressione Enter para manter o atual): ";
    getline(cin, novoTelefone);

    cout << "Digite o novo cargo (ou pressione Enter para manter o atual): ";
    getline(cin, novoCargo);

    // Atualiza apenas se o usuario informou novos dados
    if (!novoNome.empty()) {
        p.setPessoa(novoNome);
    }
    if (!novoTelefone.empty()) {
        p.setTelefone(novoTelefone);
    }
    if (!novoCargo.empty()) {
        p.setCargo(novoCargo);
    }

    // Atualiza o arquivo
    ifstream arq_entrada(FILE_TRIPULACAO);
    ofstream arq_temp("temp.txt");

    if (!arq_entrada.is_open() || !arq_temp.is_open()) {
        cout << "Erro ao abrir os arquivos para atualizacao." << endl;
        return;
    }

    string linha;
    while (getline(arq_entrada, linha)) {
        // Substitui a linha do tripulacao pelo conteudo atualizado
        if (linha.find(codigo + ",") == 0) {
            arq_temp << p.criaStringDeDados(); // Insere os dados atualizados
        } else {
            arq_temp << linha << endl; // Mantem os outros registros
        }
    }

    arq_entrada.close();
    arq_temp.close();

    // Substitui o arquivo original pelo atualizado
    remove(FILE_TRIPULACAO);
    rename("temp.txt", FILE_TRIPULACAO);

    cout << "Tripulacao atualizado com sucesso!" << endl;
}

/**
 * Metodo para excluir passageiros
 */
void Tripulacao::excluirTripulacao(string codigo, Tripulacao &p) {
    // Primeiro busca o tripulacao pelo codigo
    p.buscaTripulacao(codigo);
    // Pergunta se deseja excluir o tripulacao
    char escolha;
    cout << "Deseja excluir este tripulacao? (s/n): ";
    cin >> escolha;

    if (tolower(escolha) != 's') {
        cout << "Exclusao cancelada." << endl;
        return;
    }

    // Atualiza o arquivo
    ifstream arq_entrada(FILE_TRIPULACAO);
    ofstream arq_temp("temp.txt");

    if (!arq_entrada.is_open() || !arq_temp.is_open()) {
        cout << "Erro ao abrir os arquivos para exclusao." << endl;
        return;
    }

    string linha;
    bool encontrado = false;

    while (getline(arq_entrada, linha)) {
        // Se encontrar o tripulacao pelo codigo, nao escreve essa linha no arquivo temporario
        if (linha.find(codigo + ",") == 0) {
            encontrado = true;
            cout << "Tripulacao excluido com sucesso!" << endl;
        } else {
            arq_temp << linha << endl; // Mantem os outros registros
        }
    }

    if (!encontrado) {
        cout << "Tripulacao nao encontrado!" << endl;
    }

    arq_entrada.close();
    arq_temp.close();

    // Substitui o arquivo original pelo atualizado
    remove(FILE_TRIPULACAO);
    rename("temp.txt", FILE_TRIPULACAO);
}
