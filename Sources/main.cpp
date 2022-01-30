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

int main() {

  int jogo[NUM] = {0, 4, 6, 5, 3}, final[NUM] = {24, 0, 0, 0, 0}, filho = RAIZ;
  int carta[NUM - 1] = {4, 6, 5, 3};
  vector<char> noFilho;
  vector<int> fila;
  vector<string> lstAbertos, lstFechados;
  string k;
  char f;

  cout << "\n\n";
  cout << "   *** BUSCA ORDENADA ***  \n\n";
  cout << " - Critério de desempate - \n";
  cout
      << " Carta de menor valor ou ordem de entrada na lista de abertos.  \n";
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
  cout << " -> {" << carta[0] << "*()}" << endl;
  cout << "Filhos de  " << lstAbertos[0] << ": { ";
  lstFechados.push_back(lstAbertos[0]);
  lstAbertos.erase(lstAbertos.begin());
  Grava_Filhos_No(jogo, final, filho, lstAbertos);

  //!=====================================================
  listaFechados(lstFechados);
  ordenaFila(fila, lstAbertos);
  listaAbertos(lstAbertos);

  cout << "Estado atual: ";
  alteraValor(jogo);
  estado(jogo);
  cout << " -> {" << carta[1] << "*(" << carta[0] << ")}" << endl;
  cout << "Filhos de  " << lstAbertos[0] << ": { ";
  lstFechados.push_back(lstAbertos[0]);
  lstAbertos.erase(lstAbertos.begin());
  Grava_Filhos_No(jogo, final, filho, lstAbertos);

  //!=====================================================
  cout << endl
       << endl;

  cout << "\n";
  while (fila.size() != 0)
    fila.erase(fila.begin());

  while (noFilho.size() != 0)
    noFilho.erase(noFilho.begin());

  imprime(noFilho, fila, jogo, carta, filho);
  cout << "\n\ndepois gravaFila";

  // verifica final do jogo
  int i = 1;
  if (jogo[i] == 0 && jogo[i + 1] == 0 && jogo[i + 2] == 0 && jogo[i + 3] == 0)
    cout << "\nFim de jogo!\n";
  else
    cout << "\nContinue...\n";

  fila = gravaFilaFilho(jogo, noFilho, filho, carta, 1, 1);
  imprime(noFilho, fila, jogo, carta, filho);

  cout << "\n\n";

  cout << "\nfilho: " << filho;
  cout << endl
       << endl;

  return 0;
}
