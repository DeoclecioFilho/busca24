#ifndef C56D52EA_FECC_43F3_A9F1_2E6579F5B34E
#define C56D52EA_FECC_43F3_A9F1_2E6579F5B34E
#include "stdc++.h"
using namespace std;

const int NUM = 5;
const int RAIZ = 64;
const int RESULT = 24;

vector <int> Formula24();
void alteraValor(int *jogo, int i);
void impEstado(int *jogo);
int valorCartas(int *jogo, int i);
void ImpFilhoRaiz(int *jogo, int &filho);
vector<int> gravaFila(int *jogo, vector<char> &noFilho, int &filho,  int k, int w);
void filaRegras(vector<char> noFilho, vector<int> fila, vector<string> &lstAbertos);
void impLstAbertos(vector<string> &lstAbertos);
void impLstFechados(vector<string> &lstFechados);
void concat(char letra, char texto[]);
void concStrCharF(string k, char f, vector<string> &lstFechados);
char *concStrCharA(string k, char f, vector<string> &lstAbertos);
void menorFilho(vector<char> noFilho, vector<int> fila,vector<string> &lstAbertos);
//void Grava_Filhos_No(int *jogo,int *final, int &filho,vector<string> &lstAbertos);
void ordenaFila(vector<int> &fila, vector<string> &lstAbertos);
vector<int> gravaFilaFilho(int *jogo, vector<char> &noFilho, int &filho, int *carta, int *cartaX) ;
void impFilhos(vector<int> &fila, vector<string> &lstAbertos, vector<char> &noFilho);
void verificaFinal(int *jogo, int *final);
void limpaNo(vector<char> &noFilho, vector<int> &fila);

//? =========== Heurística =========

void ImpFilhoRaizH(int *jogo, int &filho);
vector<int> gravaFilaFilhoH(int *jogo, vector<char> &noFilho, int &filho, int *carta, int *cartaX) ;
void verificaFinalH(int *jogo, int *final, int &custo, vector<string> &lstFechados);
void limpaNoH(vector<char> &noFilho,vector<char> &noFilhoA, vector<int> &filaA, vector<int> &filaO, vector<int> &filaH);

#endif /* C56D52EA_FECC_43F3_A9F1_2E6579F5B34E */
