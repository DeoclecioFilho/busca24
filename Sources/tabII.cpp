#include "regras.h"
#include "stdc++.h"
#include "tabI.h"

using namespace std;

void buscaGulosa() {
  int jogo[NUM] = {0, 4, 6, 5, 3},
      final[NUM] = {24, 0, 0, 0, 0},
      carta[NUM - 1] = {4, 6, 5, 3},
      cartaX[2] = {100, 0};
  int custo = 0, filho = RAIZ;

  vector<char> noFilho;
  vector<int> fila, altValor;
  vector<string> lstAbertos, lstFechados;
  string k = "(0)";
  char f = char(RAIZ);

  cout << "\n\n"
       << "                        *** BUSCA GULOSA ***  \n\n"
       << "                             HEURÍSTICA\n\n"
       << " - Critério de desempate - \n"
       << "Ordem de entrada na lista de abertos.  \n\n";
  cout << "Estado inicial: " << f << " = ";
  impEstado(jogo);
  cout << "\nEstado final: ";
  impEstado(final);
  cout << "\n\n";
  //!===============================================================
  cout << "Inicio\n";
  cout << "Filhos da Raiz - " << f << k;
  ImpFilhoRaizH(jogo, filho);
  fila = gravaFilaFilhoH(jogo, noFilho, filho, carta, cartaX);
  cout << "Filhos de " << f << k << ": { ";
  impFilhos(fila, lstAbertos, noFilho);
  concStrCharF(k, f, lstFechados);
  for (size_t i = 0; i < NUM-1; i++) {
    cout << "\n";
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
    fila = gravaFilaFilhoH(jogo, noFilho, filho, carta, cartaX);
    impFilhos(fila, lstAbertos, noFilho);
    cout << "\n";
    impLstFechados(lstFechados);
    ordenaFila(fila, lstAbertos);
    impLstAbertos(lstAbertos);
    verificaFinalH(jogo, final, custo, lstFechados);
    cout << "\n";
  }
}


//!  --------------------- Busca Ordenada -------------------------
void buscaOrdenada() {

  int jogo[NUM] = {0, 4, 6, 5, 3},
      final[NUM] = {24, 0, 0, 0, 0},
      carta[NUM - 1] = {4, 6, 5, 3},
      cartaX[2] = {100, 0};
  int custo = 0, filho = RAIZ;

  vector<char> noFilho;
  vector<int> fila, altValor;
  vector<string> lstAbertos, lstFechados;
  string k = "(0)";
  char f = char(RAIZ);

  cout << "\n\n"
       << "                    *** BUSCA ORDENADA ***  \n\n"
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
    cout << "\n";
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
    // custo = custo + fila[0]; // custo
    impFilhos(fila, lstAbertos, noFilho);
    verificaFinal(jogo, final);
    cout << "\n";
  }
}

void buscaA() {

 int jogo[NUM] = {0, 4, 6, 5, 3},
      final[NUM] = {24, 0, 0, 0, 0},
      carta[NUM - 1] = {4, 6, 5, 3},
      cartaX[2] = {100, 0};
  int custo = 0, filho = RAIZ, filhoA = RAIZ;

  vector<char> noFilho, noFilhoA;
  vector<int> filaA, filaH, filaO;
  vector<string> lstAbertos, lstFechados;
  string k = "(0)";
  char f = char(RAIZ);


  cout << "\n\n"
       << "                    *** BUSCA A* ***  \n\n"
       << " - Critério de desempate - \n"
       << "Ordem de entrada na lista de abertos.  \n\n";

  cout << "Estado inicial: " << f << " = ";
  impEstado(jogo);
  cout << "\nEstado final: ";
  impEstado(final);
  cout << "\n\n";

    //!===============================================================
  
  cout << "Inicio\n\n";
  cout << "Valor Real → " ;
  ImpFilhoRaiz(jogo, filhoA);

  cout << "\nHeurística → " ;
  ImpFilhoRaizH(jogo, filhoA);

  filaO = gravaFilaFilho(jogo, noFilho, filho, carta, cartaX);
  filaH = gravaFilaFilhoH(jogo, noFilhoA, filhoA, carta, cartaX);

  for (size_t i = 0; i < filaO.size(); i++)
    filaA.push_back(filaO[i] + filaH[i]);
  
  cout << "\n\nFilhos de " << f << k << ": { ";
  impFilhos(filaA, lstAbertos, noFilho);
  concStrCharF(k, f, lstFechados);
  cout << "\n\n";
  for (size_t i = 0; i < 4; i++) {
    cout << "\n";
    impLstFechados(lstFechados);
    ordenaFila(filaA, lstAbertos);
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
    limpaNoH(noFilho, noFilhoA, filaA, filaO, filaH);


  filaO = gravaFilaFilho(jogo, noFilho, filho, carta, cartaX);
  filaH = gravaFilaFilhoH(jogo, noFilhoA, filhoA, carta, cartaX);
  
  for (size_t i = 0; i < filaO.size(); i++)
    filaA.push_back(filaO[i] + filaH[i]);


    //fila = gravaFilaFilhoH(jogo, noFilho, filho, carta, cartaX);
    
    impFilhos(filaA, lstAbertos, noFilhoA);
    cout << "\n";
    impLstFechados(lstFechados);
    ordenaFila(filaA, lstAbertos);
    impLstAbertos(lstAbertos);
    verificaFinalH(jogo, final, custo, lstFechados);

    cout << "\n";
  }

}
