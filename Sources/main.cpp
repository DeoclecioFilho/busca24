#include "regras.h"
#include "stdc++.h"
#include <string>
using namespace std;

void imprime(vector<char> noFilho, vector<int> fila, int *jogo, int *carta, int filho) {
  cout << "\njogo: ";
  for (int i = 0; i < NUM; i++)
    cout << " " << jogo[i];
  cout << "\nfila: ";
  for (int i = 0; i < fila.size(); i++)
    cout << " " << fila[i];
  cout << "\nnoFilho: ";
  for (int i = 0; i < noFilho.size(); i++)
    cout << " " << noFilho[i];
  cout << "\ncarta: ";
  for (int i = 0; i < NUM - 1; i++)
    cout << " " << carta[i];

  cout << "\nfilho: "
       << filho;
}

// E(8) = 4
void alteraValor(int *jogo) {
  for (int i = 1; i < NUM; i++) {
    if (jogo[i] == 4) {
      jogo[i] = 0;
      jogo[0] *= 4;
    }
  }
}

// H(6) = 5
void alteraValor2(int *jogo) {
  for (int i = 1; i < NUM; i++) {
    if (jogo[i] == 5) {
      jogo[i] = 0;
      jogo[0] = 6*((4-5)*(-1));
    }
  }
}

// L(0) = 3
void alteraValor3(int *jogo) {
  for (int i = 1; i < NUM; i++) {
    if (jogo[i] == 3) {
      jogo[i] = 0;
      jogo[0] = 6*(((4-5)*(-1))+3);
    }
  }
}

void limpaNo(vector<char> noFilho, vector<int> fila) {
  while (fila.size() != 0)
    fila.erase(fila.begin());

  while (noFilho.size() != 0)
    noFilho.erase(noFilho.begin());
}

int main() {

  int jogo[NUM] = {0, 4, 6, 5, 3}, final[NUM] = {24, 0, 0, 0, 0}, filho = RAIZ;
  int carta[NUM - 1] = {4, 6, 5, 3};
  vector<char> noFilho;
  vector<int> fila;
  vector<string> lstAbertos, lstFechados;
  string k;
  char f;

  cout << "\n\n";
  cout << "           *** BUSCA ORDENADA ***  \n\n";
  cout << " - Critério de desempate - \n";
  cout << "Carta de menor valor ou ordem de entrada na lista de abertos.  \n\n";
  cout << "Estado inicial: ";
  cout << char(RAIZ) << " = ";
  estado(jogo);
  cout << "\n";
  cout << "Estado final: ";
  estado(final);
  cout << endl
       << endl;
  cout << "Filhos da Raiz - " << char(RAIZ) << "(0): ";
  ImpFilhoRaiz(jogo, filho);

  // Início
  fila = gravaFila(jogo, noFilho, filho, 1, 2);
  filaRegras(noFilho, fila, lstAbertos);

  // inicio (0)
  k = "(0)";
  f = char(RAIZ);
  concStrCharF(k, f, lstFechados);

  //!=====================================================
  listaFechados(lstFechados);
  listaAbertos(lstAbertos);
  cout << "Estado atual: ";
  estado(jogo);
  cout << " -> {" << carta[1] << " * ()}" << endl;
  cout << "Filhos de  " << lstAbertos[0] << ": { ";
  lstFechados.push_back(lstAbertos[0]);
  lstAbertos.erase(lstAbertos.begin());
  Grava_Filhos_No(jogo, final, filho, lstAbertos);
  verificaFinal(jogo, final);
  //!=====================================================
  listaFechados(lstFechados);
  ordenaFila(fila, lstAbertos);
  listaAbertos(lstAbertos);

  cout << "Estado atual: ";
  alteraValor(jogo);
  estado(jogo);
  cout << " -> {" << carta[1] << " * (" << carta[0] << ")}" << endl;
  cout << "Filhos de  " << lstAbertos[0] << ": { ";
  lstFechados.push_back(lstAbertos[0]);
  lstAbertos.erase(lstAbertos.begin());
  limpaNo(noFilho, fila);

  while (fila.size() != 0)
    fila.erase(fila.begin());
  while (noFilho.size() != 0)
    noFilho.erase(noFilho.begin());

  // Grava_Filhos_No(jogo, final, filho, lstAbertos);

  fila = gravaFilaFilho(jogo, noFilho, filho, carta, 1, 1);
  imprimeAbertos(fila, lstAbertos, noFilho);
  verificaFinal(jogo, final);

  cout << "\n";
  //!=====================================================
  listaFechados(lstFechados);
  ordenaFila(fila, lstAbertos);
  listaAbertos(lstAbertos);

  cout << "Estado atual: ";
  alteraValor2(jogo);
  estado(jogo);
  cout << " -> {" << carta[1] << " * (|" << carta[0] << " - " << carta[2] << "|)}" << endl;
  cout << "Filhos de  " << lstAbertos[0] << ": { ";

  lstFechados.push_back(lstAbertos[0]);
  lstAbertos.erase(lstAbertos.begin());
  limpaNo(noFilho, fila);
    while (fila.size() != 0)
    fila.erase(fila.begin());
  while (noFilho.size() != 0)
    noFilho.erase(noFilho.begin());

  fila = gravaFilaFilho(jogo, noFilho, filho, carta, 1, 1);
  imprimeAbertos(fila, lstAbertos, noFilho);
  verificaFinal(jogo, final);
  cout << "\n";
//!=====================================================
  listaFechados(lstFechados);
  ordenaFila(fila, lstAbertos);
  listaAbertos(lstAbertos);

  cout << "Estado atual: ";
  alteraValor3(jogo);
  estado(jogo);
  cout << " -> {" << carta[1] << " * (|" << carta[0] << " - " << carta[2] << "| + 3)}" << endl;
  cout << "Filhos de  " << lstAbertos[0] << ": { ";

  lstFechados.push_back(lstAbertos[0]);
  lstAbertos.erase(lstAbertos.begin());
  limpaNo(noFilho, fila);
    while (fila.size() != 0)
    fila.erase(fila.begin());
  while (noFilho.size() != 0)
    noFilho.erase(noFilho.begin());

  fila = gravaFilaFilho(jogo, noFilho, filho, carta, 1, 1);
  imprimeAbertos(fila, lstAbertos, noFilho);
  verificaFinal(jogo, final);

  cout << "\n\n";

  return 0;
}
