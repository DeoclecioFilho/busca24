#ifndef C56D52EA_FECC_43F3_A9F1_2E6579F5B34E
#define C56D52EA_FECC_43F3_A9F1_2E6579F5B34E
#include "stdc++.h"
using namespace std;

const int NUM = 5;
const int RAIZ = 64;
const int RESULT = 24;

void r1(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r2(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r3(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r4(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r5(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r6(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r7(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r8(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r9(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r11(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r12(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r10(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r13(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r14(int *jogo, int &v1, int &v2, int &v3, int &v4);
void r15(int *jogo, int &v1, int &v2, int &v3, int &v4);

void estado(int *jogo);
void idNo(char *no, int i);
int valorCartas(int *jogo, int i);
void ImpFilhoRaiz(int *jogo, int &filho);
vector<int> gravaFila(int *jogo, vector<char> &noFilho, int &filho,  int k, int w);
void filaRegras(vector<char> noFilho, vector<int> fila, vector<string> &lstAbertos);
void listaAbertos(vector<string> &lstAbertos);
void listaFechados(vector<string> &lstFechados);
void concat(char letra, char texto[]);
void concStrCharF(string k, char f, vector<string> &lstFechados);
void concStrCharA(string k, char f, vector<string> &lstAbertos);
void menorFilho(vector<char> noFilho, vector<int> fila,vector<string> &lstAbertos);
void Grava_Filhos_No(int *jogo,int *final, int &filho,vector<string> &lstAbertos);
void ordenaFila(vector<int> &fila, vector<string> &lstAbertos);
vector<int> gravaFilaFilho(int *jogo, vector<char> &noFilho, int &filho, int *carta, int k, int w) ;
void imprimeAbertos(vector<int> &fila, vector<string> &lstAbertos, vector<char> &noFilho);
void verificaFinal(int *jogo, int *final);

#endif /* C56D52EA_FECC_43F3_A9F1_2E6579F5B34E */
