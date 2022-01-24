#ifndef C56D52EA_FECC_43F3_A9F1_2E6579F5B34E
#define C56D52EA_FECC_43F3_A9F1_2E6579F5B34E
#include "stdc++.h"
using namespace std;

const int NUM = 5;
const int RAIZ = 65;
const int RESULT = 24;
/*
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
*/
void estado(int *jogo);
void idNo(char *no, int i);
int valorCartas(int *jogo, int i);
void filhoRaiz(int *jogo, int &filho);
vector<int> gravaFila(int *jogo, vector<char> &noFilho, int &filho);
void filaRegras(vector<char> noFilho, vector<int> fila);
void listaAbertos(vector<string> &lstAbertos);
void listaFechados(vector<string> &lstFechados);
void concat(char letra, char texto[]);
void concStrCharF(string k, char f, vector<string> &lstFechados);
void concStrCharA(string k, char f, vector<string> &lstAbertos);
void menorFilho(vector<char> noFilho, vector<int> fila,
                vector<string> &lstAbertos);

#endif /* C56D52EA_FECC_43F3_A9F1_2E6579F5B34E */
