#include "tabI.h"
#include "regras.h"
#include "stdc++.h"
#include <string>

using namespace std;

//! ------------------------BUSCA EM PROFUNDIDADE ----------------

void buscaProf() {

  int custo = 0, filho = RAIZ, contNO = 0, t = 0;
  int jogo[NUM] = {0, 4, 6, 5, 3},
      final[NUM] = {24, 0, 0, 0, 0},
      carta[NUM - 1] = {4, 6, 5, 3},
      gJogo[][NUM] = {{0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0}};
  string cartaXL[2][NO];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < NO; j++)
      cartaXL[i][j] = " ";

  vector<char> noFilho;
  vector<int> altValor;
  vector<string> lstAbertos, lstFechados, vetTemp;
  string k = "(0)", r;
  char f = char(RAIZ);
  r = convChar(f);
  stack<string> pilha, pilhaTemp, pt, pFechados, pAbertos;
  //!-----------------------------------------------------------

  cout << "\n\n"
       << "                    *** BUSCA EM PROFUNDIDADE ***  \n\n"
       << " Direção: Direita \n"
       << "PILHA - Primeiro a entrar é ultimo a sair.  \n\n";

  cout << "RAIZ DA ÁRVORE → Estado inicial: ";
  impEstado(jogo);
  cout << "\nEstado final: ";
  impEstado(final);
  cout << "\n";
  cout << "Raiz → " << f << k;
  ImpFilhoRaizI(jogo, filho);
  cout << "\n\n";
  //!===============================================================

  cout << "Inicio\n";
  impPilhaAbertos(pAbertos);
  impPilhaFechados(pFechados);
  cout << "\n\n";

  //!=========================================

  cout << "Filhos de  " << f << k;

  vetTemp = gravaEstado(jogo, filho, gJogo, cartaXL, contNO, t);
  for (int i = 0; i < vetTemp.size(); i++)
    pilha.push(vetTemp[i]);
  cout << "\n";
  pAbertos.push(r);
  impPilhaAbertos(pAbertos);
  impPilhaFechados(pFechados);
  impPilha(pilha);

  //!=========================================

  cout << "\n\n";
  pFechados.push(pAbertos.top());
  pAbertos.pop();
  for (int i = 0; i < vetTemp.size(); i++)
    pAbertos.push(vetTemp[i]);

  limpaPilha(pilhaTemp);
  impPilhaAbertos(pAbertos);
  impPilhaFechados(pFechados);

  // inicia os filhos de A
  //!=========================================

  for (size_t j = 1; j < NUM - 1; j++) {
    cout << "\nFilhos de  " << pAbertos.top();

    if (pAbertos.top() == cartaXL[0][j - 1]) { //! j = 1: A → 4

      cout << "\nAbertos: " << pAbertos.top() << " == "
           << "CartaX: " << cartaXL[0][j] << " ";
      //    cout<< "\nAbertos: "<< pAbertos.top()<< " == "<<"CartaX: "<< cartaXL[0][j]<<" ";

      jogo[0] = stoi(cartaXL[1][j]);
      for (size_t i = 0; i < NUM; i++) {
        jogo[i + 1] = carta[i];
        if (jogo[i + 1] == jogo[0])
          jogo[i + 1] = 0;
      }
      //  jogo[i] = gJogo[0][i]; // grava o valor do jogo atua
      gEstadoP(jogo, filho, gJogo, cartaXL, contNO, j, pt);

      while (!pt.empty()) {
        pilhaTemp.push(pt.top());
        pt.pop();
      }
    }
    //   limpaPilha;
    while (!pilhaTemp.empty()) {
      pilha.push(pilhaTemp.top());
      pilhaTemp.pop();
    }
    cout << "\n";

    impPilhaAbertos(pAbertos);
    impPilhaFechados(pFechados);
    impPilha(pilha);

    cout << "\n\n";
    pFechados.push(pAbertos.top());
    pAbertos.pop();
    while (!pilhaTemp.empty()) {
      pAbertos.push(pilhaTemp.top());
      pilhaTemp.pop();
    }
  }
}

//! ------------------------BUSCA EM LARGURA ----------------

void buscaLarg() {
  int custo = 0, filho = RAIZ, contNO = 0, t = 0;
  int jogo[NUM] = {0, 4, 6, 5, 3},
      final[NUM] = {24, 0, 0, 0, 0},
      carta[NUM - 1] = {4, 6, 5, 3},
      gJogo[][NUM] = {{0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0}};
  string cartaXL[2][NO];
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < NO; j++)
      cartaXL[i][j] = " ";

  vector<char> noFilho;
  vector<int> altValor;
  vector<string> lstAbertos, lstFechados, fila, vetTemp;
  string k = "(0)", r;
  char f = char(RAIZ);
  r = convChar(f);

  /*   cartaXL[0][contNO] = r;
    cartaXL[1][contNO] = to_string(0); */

  cout << "\n\n"
       << "                    *** BUSCA EM LARGURA ***  \n\n"
       << " - Critério de desempate - \n"
       << "Carta de menor valor ou ordem de entrada na lista de abertos.  \n\n";

  cout << "RAIZ DA ÁRVORE → Estado inicial: ";
  impEstado(jogo);
  cout << "\nEstado final: ";
  impEstado(final);
  cout << "\n";
  cout << "Raiz → " << f << k;
  ImpFilhoRaizI(jogo, filho);
  cout << "\n\n";
  //!===============================================================

  cout << "Inicio\n";
  impLstAbertos(lstAbertos);
  impLstFechados(lstFechados);
  cout << "\n\n";

  //!=========================================

  cout << "Filhos de  " << f << k;
  vetTemp = gravaEstado(jogo, filho, gJogo, cartaXL, contNO, t);
  for (int i = 0; i < vetTemp.size(); i++)
    fila.push_back(vetTemp[i]);
  cout << "\n";
  lstAbertos.push_back(r);
  impLstAbertos(lstAbertos);
  impLstFechados(lstFechados);
  impLstFila(fila);

  //!=========================================

  cout << "\n\n";
  lstFechados.push_back(lstAbertos[0]);
  lstAbertos.erase(lstAbertos.begin());
  for (int i = 0; i < vetTemp.size(); i++)
    lstAbertos.push_back(vetTemp[i]);
  limpaFilaL(vetTemp);
  impLstAbertos(lstAbertos);
  impLstFechados(lstFechados);

  // inicia os filhos de A
  //!=========================================

  for (size_t j = 1; j < NUM - 1; j++) {
    cout << "\nFilhos de  " << lstAbertos[0];
    if (lstAbertos[0] == cartaXL[0][j]) { //! j = 1: A → 4

      jogo[0] = stoi(cartaXL[1][j]);
      for (size_t i = 0; i < NUM; i++) {
        jogo[i + 1] = carta[i];
        if (jogo[i + 1] == jogo[0])
          jogo[i + 1] = 0;
      }
      //  jogo[i] = gJogo[0][i]; // grava o valor do jogo atua

      vetTemp = gravaEstado(jogo, filho, gJogo, cartaXL, contNO, j);
    }
    limpaFilaL(fila);
    for (int i = 0; i < vetTemp.size(); i++)
      fila.push_back(vetTemp[i]);

    cout << "\n";

    impLstAbertos(lstAbertos);
    impLstFechados(lstFechados);
    impLstFila(fila);

    lstFechados.push_back(lstAbertos[0]);
    lstAbertos.erase(lstAbertos.begin());
    for (int i = 0; i < vetTemp.size(); i++)
      lstAbertos.push_back(vetTemp[i]);
  }
  /*         for (size_t i = 0; i < NUM; i++) {
            jogo[i + 1] = carta[i];
            if (jogo[i + 1] == jogo[0])
              jogo[i + 1] = 0;
          } */

  //!=========================================

  for (size_t j = 1 + 3; j < NUM + 5; j++) {
    cout << "\nFilhos de  " << lstAbertos[0];
    if (lstAbertos[0] == cartaXL[0][j]) { //!

      jogo[0] = stoi(cartaXL[1][j]);
      for (size_t i = 0; i < NUM; i++) {
        jogo[i + 1] = carta[i];
        if (jogo[i + 1] == jogo[0])
          jogo[i + 1] = 0;
      }
      //  jogo[i] = gJogo[0][i]; // grava o valor do jogo atua

      vetTemp = gravaEstado(jogo, filho, gJogo, cartaXL, contNO, j);
    }
    limpaFilaL(fila);
    for (int i = 0; i < vetTemp.size(); i++)
      fila.push_back(vetTemp[i]);

    cout << "\n";

    impLstAbertos(lstAbertos);
    impLstFechados(lstFechados);
    impLstFila(fila);

    lstFechados.push_back(lstAbertos[0]);
    lstAbertos.erase(lstAbertos.begin());
    for (int i = 0; i < vetTemp.size(); i++)
      lstAbertos.push_back(vetTemp[i]);
  }

  cout << "\n\n";

  //!=========================================

  cout << "\n\n";
  /* lstFechados.push_back(lstAbertos[0]);
  lstAbertos.erase(lstAbertos.begin());

  for (int i = 0; i < fila.size(); i++)
    lstAbertos.push_back(fila[i]);
  limpaFilaL(vetTemp);
  impLstAbertos(lstAbertos);
  impLstFechados(lstFechados); */

  cout << "\n\n";
  for (size_t i = 0; i < 2; i++) {
    for (size_t j = 0; j < NO; j++) {
      if (cartaXL[i][j] != " ")
        cout << " " << cartaXL[i][j] << " ";
    }
    cout << "\n";
  }
  cout << "\n\n";
}

//? ------------------------BUSCA EM PROFUNDIDADE II ----------------

void buscaProf2() {

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
       << "                    *** BUSCA EM PROFUNDIDADE ***  \n\n"
       << " Direção: Direita \n"
       << "PILHA - Primeiro a entrar é ultimo a sair.  \n\n";

  cout << "RAIZ DA ÁRVORE → Estado inicial: ";
  impEstado(jogo);
  cout << "\nEstado final: ";
  impEstado(final);
  cout << "\n";
  cout << "Raiz → " << f << k;
  ImpFilhoRaizI(jogo, filho);
  cout << "\n\n";

  //!===============================================================

  cout << "Inicio\n";

  // cout << "Filhos de " << f << k;
  // ImpFilhoRaizP(jogo, filho);
  fila = gravaFilaFilhoP(jogo, noFilho, filho, carta, cartaX);
  cout << "\n";
  cout << "Filhos de " << f << k << ": { ";
  impFilhosO(fila, lstAbertos, noFilho);
  // ordenaFila(fila, lstAbertos);
  cout << "}\n";
  concStrCharF(k, f, lstFechados);
  //!=====================================================

  for (size_t i = 0; i < 4; i++) {
    cout << "\n";
    impLstFechadosP(lstFechados); // Pilha de Fechados
    // ordenaFila(fila, lstAbertos);
    impLstAbertosP(lstAbertos); // Pilha de abertos
    cout << "Estado atual: ";   
    cartaX[0] = 100;
    alteraValorP(jogo, cartaX[5]);
    impEstado(jogo); // Valores do Estado atual
    switch (cartaX[5]) {
    case 3:
      cout << " -> {" << carta[3] << " * ()}" << endl;
      break;
    case 4:
      cout << " -> {" << carta[3] << " * (" << carta[0] << ")}" << endl;
      break;
    case 5:
      cout << " -> {" << carta[3] << " * (|" << carta[0] << " - " << carta[2] << "|)}" << endl;
      break;
    case 6:
      cout << " -> {" << carta[3] << " * (|" << carta[0] << " - " << carta[2] << "| + " << carta[3] << ")}" << endl;
      break;
    default:
      cout << "\nOpção inválida! Tente novamente.\n";
      break;
    }
    cout << "\n";
    cout << "Filhos de  " << lstAbertos[0] << ": { ";
    lstFechados.push_back(lstAbertos[0]);
    lstAbertos.erase(lstAbertos.begin());
    limpaNo(noFilho, fila);
    fila = gravaFilaFilhoP(jogo, noFilho, filho, carta, cartaX);
    // custo = custo + fila[0]; // custo
    impFilhosO(fila, lstAbertos, noFilho);  // Filhos e concatena
    cout << "\n";
    verificaFinal(jogo, final);
    cout << "\n";
  }
}