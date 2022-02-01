#include "regras.h"
#include "stdc++.h"
#include "tabI.h"

using namespace std;

void buscaGulosa(){

};

void buscaOrdenada() {

  int jogo[NUM] = {0, 4, 6, 5, 3},
      final[NUM] = {24, 0, 0, 0, 0},
      carta[NUM - 1] = {4, 6, 5, 3},
      cartaX[2] = {100, 0};
  int v = 6, filho = RAIZ;

  vector<char> noFilho;
  vector<int> fila, altValor;
  vector<string> lstAbertos, lstFechados;
  string k = "(0)";
  char f = char(RAIZ);

  cout << "           \n\n*** BUSCA ORDENADA ***  \n\n"
       << " - Critério de desempate - \n"
       << "Carta de menor valor ou ordem de entrada na lista de abertos.  \n\n";

  cout << "Estado inicial: " << f << " = ";
  impEstado(jogo);
  cout << "\nEstado final: ";
  impEstado(final);
  cout << "\n\n";
  //!===============================================================
  cout << "Inicio\n";
  cout << "Filhos da Raiz - " << f << k;
  ImpFilhoRaiz(jogo, filho);
  fila = gravaFilaFilho(jogo, noFilho, filho, carta, cartaX);
  cout << "Filhos de " << f << k << ": { ";
  impFilhos(fila, lstAbertos, noFilho);
  // ordenaFila(fila, lstAbertos);
  cout << "}\n";
  concStrCharF(k, f, lstFechados);
  //!=====================================================

  for (size_t i = 0; i < 4; i++) {
    impLstFechados(lstFechados);
    ordenaFila(fila, lstAbertos);
    impLstAbertos(lstAbertos);
    cout << "Estado atual: ";
    cartaX[0] = 100;
    alteraValor(jogo, cartaX[1]);
    impEstado(jogo);
    switch (cartaX[1]) {
    case 6:
      cout << " -> {" << carta[1] << " * ()}" << endl;
      break;
    case 4:
      cout << " -> {" << carta[1] << " * (" << carta[0] << ")}" << endl;
      break;
    case 5:
      cout << " -> {" << carta[1] << " * (|" << carta[0] << " - " << carta[2] << "|)}" << endl;
      break;
    case 3:
      cout << " -> {" << carta[1] << " * (|" << carta[0] << " - " << carta[2] << "| + " << carta[3] << ")}" << endl;
      break;
    default:
      cout << "\nOpção inválida! Tente novamente.\n";
      break;
    }
    cout << "Filhos de  " << lstAbertos[0] << ": { ";
    lstFechados.push_back(lstAbertos[0]);
    lstAbertos.erase(lstAbertos.begin());
    limpaNo(noFilho, fila);
    fila = gravaFilaFilho(jogo, noFilho, filho, carta, cartaX);
    impFilhos(fila, lstAbertos, noFilho);
    verificaFinal(jogo, final);
    cout << "\n";
  }
}

void buscaA() {
}
