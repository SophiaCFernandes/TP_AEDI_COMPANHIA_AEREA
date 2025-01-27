#include "menu.h"
#include "passageiro.h"
#include "tripulacao.h"
#include <iostream>

using namespace std;

/**
 * Funcao principal do menu
 */
void menu() {
    bool exit = false;

    cout << "Bem vindo(a) a Companhia Aerea Voo Seguro\n";

    while (!exit) {
        cout << "\n1) Gerenciar Passageiros\n"
            << "2) Gerenciar Tripulacao\n"
            << "3) Gerenciar Voos\n"
            << "4) Gerenciar Reservas\n"
            << "5) Programa de Fidelidade\n"
            << "6) Sair\n";

        int input = 0;
        cin >> input;

        switch (input) {
            case 1:
                menu_passageiro();
                break;
            case 2:
                menu_tripulacao();
                break;
            case 3:
                menu_voo();
                break;
            case 4:
                menu_reserva();
                break;
            case 5:
                cout <<"Funcao ainda a ser implementada";
                break;
            case 6:
                cout << "Saindo... Obrigado por utilizar o sistema!\n";
                exit = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }
}

/**
 * Submenu para gerenciar voos
 */
void menu_voo() {
    bool exit = false;

    while (!exit) {
        cout << "\n*** Gerenciar Voos ***\n"
            << "1) Cadastrar Voo\n"
            << "2) Atualizar Voo\n"
            << "3) Buscar Voo\n"
            << "4) Excluir Voo\n"
            << "5) Sair\n";

        int input = 0;
        cin >> input;

        switch (input) {
            case 1: {
                string data, hora, origem, destino, codigoAviao, codigoPiloto, codigoCopiloto, codigoComissario;
                double tarifa;

                cout << "Digite a data do voo (DD/MM/AAAA): ";
                cin.ignore();
                getline(cin, data);

                cout << "Digite a hora do voo (HH:MM): ";
                getline(cin, hora);

                cout << "Digite a origem do voo: ";
                getline(cin, origem);

                cout << "Digite o destino do voo: ";
                getline(cin, destino);

                cout << "Digite o codigo do aviao: ";
                getline(cin, codigoAviao);

                cout << "Digite o codigo do piloto: ";
                getline(cin, codigoPiloto);

                cout << "Digite o codigo do copiloto: ";
                getline(cin, codigoCopiloto);

                cout << "Digite o codigo do comissario: ";
                getline(cin, codigoComissario);

                cout << "Digite a tarifa do voo: ";
                cin >> tarifa;
                
                break;
            }
            case 2:
                cout << "Funcao de atualizar voo ainda nao implementada.\n";
                break;
            case 3:
                cout << "Funcao de buscar voo ainda nao implementada.\n";
                break;
            case 4:
                cout << "Funcao de excluir voo ainda nao implementada.\n";
                break;
            case 5:
                cout << "Retornando ao menu principal...\n";
                exit = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }
}

/**
 * Submenu para gerenciar reservas
 */
void menu_reserva() {
    bool exit = false;

    while (!exit) {
        cout << "\n*** Gerenciar Reservas ***\n"
            << "1) Cadastrar Reserva\n"
            << "2) Atualizar Reserva\n"
            << "3) Buscar Reserva\n"
            << "4) Excluir Reserva\n"
            << "5) Sair\n";

        int input = 0;
        cin >> input;

        switch (input) {
            case 1: {
                cout << "Funcao de adicionar reserva ainda nao implementada.\n";

                break;
            }
            case 2:
                cout << "Funcao de atualizar reserva ainda nao implementada.\n";
                break;
            case 3:
                cout << "Funcao de buscar reserva ainda nao implementada.\n";
                break;
            case 4:
                cout << "Funcao de excluir reserva ainda nao implementada.\n";
                break;
            case 5:
                cout << "Retornando ao menu principal...\n";
                exit = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }
}

/**
 * Submenu para gerenciar passageiros
 */
void menu_passageiro(){
    bool exit = false;
    
    string nome, codigo;
    Passageiro p;

    while (!exit) {
        cout << "\n*** Gerenciar Passageiros ***\n"
            << "1) Cadastrar Passageiro\n"
            << "2) Atualizar Passageiro\n"
            << "3) Buscar Passageiro\n"
            << "4) Excluir Passageiro\n"
            << "5) Sair\n";

        int input = 0;
        cin >> input;

        switch (input) {
            case 1: {
                p.adicionaPassageiro(p);
                break;
            }
            case 2:
                cout << "Digite o codigo de passageiro que voce deseja atualizar: " << endl;
                cin >> codigo;
                p.atulizaPassageiro(codigo, p);
                break;
            case 3:
                cout << "Digite o codigo de passageiro que voce deseja buscar: " << endl;
                cin >> codigo;
                p.buscaPassageiro(codigo);
                break;
            case 4:
                cout << "Digite o codigo de passageiro que voce deseja atualizar: " << endl;
                cin >> codigo;
                p.excluirPassageiro(codigo, p);
                break;
            case 5:
                cout << "Retornando ao menu principal...\n";
                exit = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }
}

/**
 * Submenu para gerenciar tripulacao
 */
void menu_tripulacao(){
    bool exit = false;
    string nome, telefone, cargo, codigo;
    Tripulacao p;

    while (!exit) {
        cout << "\n*** Gerenciar Tripulacao ***\n"
            << "1) Cadastrar Tripulacao\n"
            << "2) Atualizar Tripulacao\n"
            << "3) Buscar Tripulacao\n"
            << "4) Excluir Tripulacao\n"
            << "5) Sair\n";

        int input = 0;
        cin >> input;

        switch (input) {
            case 1: {
                p.adicionaTripulacao();
                break;
            }
            case 2:
                cout << "Digite o codigo de tripulacao que voce deseja atualizar: " << endl;
                cin >> codigo;
                p.atulizaTripulacao(codigo, p);
                break;
            case 3:
                cout << "Digite o codigo de tripulacao que voce deseja atualizar: " << endl;
                cin >> codigo;
                p.buscaTripulacao(codigo);
                break;
            case 4:
                cout << "Digite o codigo de tripulacao que voce deseja excluir: " << endl;
                cin >> codigo;
                p.excluirTripulacao(codigo, p);
                break;
            case 5:
                cout << "Retornando ao menu principal...\n";
                exit = true;
                break;
            default:
                cout << "Opcao invalida. Tente novamente.\n";
                break;
        }
    }
}
