#include "regras.h"
#include "tabI.h"
#include "tabII.h"
#include "stdc++.h"

using namespace std;


void menu()
{
    int selecao;
    cout << "\n --- MENU ---\n\n"
         << "[0] Sair" << endl
         << "[1] Busca em Profundidade" << endl
         << "[2] Busca em Largura" << endl
         << "[3] Busca Gulosa (HEURISTICA)" << endl
         << "[4] Busca Ordenada" << endl
         << "[5] Busca A*" << endl
         << "\nOpção: ";

    cin >> selecao;
    switch (selecao)
    {
    case 0:
        exit(0);
        break;
    case 1:
        buscaProf2();
       // buscaProf();
        break;
    case 2:
        buscaLarg();
        break;
    case 3:
      buscaGulosa();
        break;
    case 4:
      buscaOrdenada();
        break;
    case 5:
      buscaA();
        break;
    default:
        system("clear");
        cout << "\n\nOpção inválida! Tente novamente.\n";
        menu();
        break;
    }
    menu();
}


int main() {
  menu();
  return 0;
}
