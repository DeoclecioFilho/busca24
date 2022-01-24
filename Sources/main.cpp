#include "Headers\regras.h"
#include "stdc++.h"
#include "Headers" 
using namespace std;


int main() {

  int jogo[NUM] = {0, 4, 6, 5, 3}, final[NUM] = {24, 0, 0, 0, 0}, filho = RAIZ;

  vector<char> noFilho;
  vector<int> fila;
  vector<string> lstAbertos, lstFechados;
  string k;
  char f;

  cout << "\n\n";
  cout << "   *** BUSCA ORDENADA ***  \n\n";
  cout << " - Critério de desempate - \n";
  cout
      << " Carta de menor valor ou ordem de entrada na lista de abertos.  \n\n";
  cout << "Estado inicial: ";
  cout << char(RAIZ) << " = ";
  estado(jogo);
  cout << "\n";
  cout << "Estado final: ";
  estado(final);
  cout << endl;
  cout << "Filhos da Raiz: ";
  filhoRaiz(jogo, filho);

  fila = gravaFila(jogo, noFilho, filho);
  filaRegras(noFilho, fila);

  // inicio (0)
  k = "(0)";
  f = char(RAIZ);
  concStrCharF(k, f, lstFechados);
  listaFechados(lstFechados);
  menorFilho(noFilho, fila, lstAbertos);
  listaAbertos(lstAbertos);

  //
  cout << "filho: " << filho;
  cout << endl << endl;

  return 0;
}