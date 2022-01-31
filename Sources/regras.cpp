#include "regras.h"
#include "stdc++.h"
#include <string>
using namespace std;

int c1 = 4,
    c2 = 6,
    c3 = 5,
    c4 = 3,
    r = 24;

//! R1 - O primeiro número dentro dos parênteses é o 4 (sua posição no vetor será zerada);
void r1(int jogo[], int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    v1 = c1;
    // cout << v1 <<" " << v2 << " "<< v3 <<" " << v4 << endl;
    jogo[0] = (v1);
    // cout <<"("<< v1 << ")"<<endl;
    jogo[1] = 0;
  }
}

//! R2 - O primeiro número dentro dos parênteses é o 6 (sua posição no vetor será zerada);
void r2(int *jogo, int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    v1 = c2;
    jogo[0] = (v1);
    jogo[2] = 0;
  }
}

//! R3 - O primeiro número dentro dos parênteses é o 5 (sua posição no vetor será zerada);
void r3(int *jogo, int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    v1 = c3;
    jogo[0] = (v1);
    jogo[3] = 0;
  }
}

//! R4 - O primeiro número dentro dos parênteses é o 3 (sua posição no vetor será zerada);
void r4(int *jogo, int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    v1 = c4;
    jogo[0] = (v1);
    jogo[4] = 0;
  }
}

//! R5 - Os sinais aritméticos simples dentro dos parênteses serão na ordem + e -;
void r5(int *jogo, int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    jogo[0] = (v1 + v2 - v3);
  }
}

//! R6 - Os sinais aritméticos simples dentro dos parênteses serão na ordem - e +;
void r6(int *jogo, int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    jogo[0] = (v1 - v2 + v3);
  }
}

//! R7 - Caso o valor do vetor na posição 1 não seja 0, o número entre os sinais
//! dentro dos parênteses será o 4 (sua posição no vetor será zerada);
void r7(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[1] != 0) {
    v2 = c1;
    jogo[0] = (v1 - v2 + v3);
    jogo[1] = 0;
  }
}

//! R8 - Caso o valor do vetor na posição 2 não seja 0, o número entre os sinais
//! dentro dos parênteses será o 6 (sua posição no vetor será zerada);
void r8(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[2] != 0) {
    v2 = c2;
    jogo[0] = (v1 - v2 + v3);
    // cout <<"("<< v1 <<" - " << v2 << " + " << v3 << ")"<<endl;
    jogo[2] = 0;
  }
}

//! R9 - Caso o valor do vetor na posição 3 não seja 0, o número entre os sinais
//! dentro dos parênteses será o 5 (sua posição no vetor será zerada);
void r9(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[3] != 0) {
    v2 = c3;
    jogo[0] = (v1 - v2 + v3);
    jogo[3] = 0;
  }
}

//! R10 - Caso o valor do vetor na posição 4 não seja 0, o número entre os sinais
//! dentro dos parênteses será o 3 (sua posição no vetor será zerada);
void r10(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[4] != 0) {
    v2 = c4;
    jogo[0] = (v1 - v2 + v3);
    jogo[4] = 0;
  }
}

//! R11 - Caso o valor do vetor na posição 1 não seja 0, o último número dentro
//! dos parênteses será o 4 (sua posição no vetor será zerada);
void r11(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[1] != 0) {
    v3 = c1;
    jogo[0] = (v1 - v2 + v3);
    jogo[1] = 0;
  }
}
//! R12 - Caso o valor do vetor na posição 2 não seja 0, o último número entre os sinais
//! dentro dos parênteses será o 6 (sua posição no vetor será zerada);
void r12(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[2] != 0) {
    v3 = c2;
    jogo[0] = (v1 - v2 + v3);
    jogo[2] = 0;
  }
}

//! R13 - Caso o valor do vetor na posição 3 não seja 0, o último número entre os sinais
//! dentro dos parênteses será o 5 (sua posição no vetor será zerada);
void r13(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[3] != 0) {
    v3 = c3;
    jogo[0] = (v1 - v2 + v3);
    jogo[3] = 0;
  }
}

//! R14 - Caso o valor do vetor na posição 4 não seja 0, o último número entre os sinais
//! dentro dos parênteses será o 3 (sua posição no vetor será zerada);
void r14(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[4] != 0) {
    v3 = c4;
    jogo[0] = (v1 - v2 + v3);
    jogo[4] = 0;
  }
}

//! R15 - A posição no vetor entre 1 e 4 que não possuir 0 como valor será zerada
//! e o número contido nessa posição será colocado após a multiplicação na
//! posição 0 do vetor.
void r15(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  for (int i = 1; i < NUM; i++)
    if (jogo[i] != 0) {
      v4 = jogo[i];
      jogo[0] = (v1 - v2 + v3) * v4;
      jogo[i] = 0;
    }
}

//?----------------------------------------------------------------------

void verificaFinal(int *jogo, int *final) {
  if (jogo[0] == final[0] && jogo[1] == final[1] && jogo[2] == final[2] && jogo[3] == final[3] && jogo[4] == final[4])
    cout << "\nFim de jogo!\n";
  else
    cout << "\nContinue...\n";
}

/**
 * @brief Imprime o estado atual
 *
 * @param jogo
 * @param n
 */
void estado(int *jogo) {
  cout << "{";
  for (int i = 0; i < NUM; i++) {
    cout << jogo[i];
    if (i < NUM - 1)
      cout << ", ";
  }
  cout << "}";
}

void idNo(char *no, int i) {
  no[i] = char(RAIZ + i);
}

//! Regra: Primeira carta escolhida
int valorCartas(int *jogo, int i) {
  int valor = 0;
  int temp = 0;
  for (int j = 1; j < NUM; j++) {
    temp += jogo[j];
  }
  if (jogo[i] != 0 && RESULT % jogo[i] == 0) {
    valor = (RESULT / jogo[i]) + temp - jogo[i]; // 24/6 + SOMA DAS CARTAS - CARTA(i)
  }
  return valor;
}

void ImpFilhoRaiz(int *jogo, int &filho) {

  cout << "{";
  for (int i = 1; i < NUM; i++) {

    if (RESULT % jogo[i] == 0) {
      cout << " " << char(filho + i) << " - " << RESULT << "/" << jogo[i] << " = " << valorCartas(jogo, i);
    } else {
      cout << " " << char(filho + i) << " - " << RESULT << "/" << jogo[i] << " = ESTADO INVÁLIDO";
    }
    if (i < NUM - 1)
      cout << ",";
  }
  cout << "}\n";
}

void escolheCarta(int *jogo, int cartaE) {

  for (size_t i = 0; i < NUM; i++) {
    if (jogo[i] == cartaE) {
      jogo[0] = cartaE;
      // carta[0] = cartaE;
      jogo[i] = 0;
    }
  }
}

vector<int> gravaFila(int *jogo, vector<char> &noFilho, int &filho, int k, int w) {
  vector<int> fila;
  int *filaRg = new int[NUM];
  char *letraRg = new char[NUM];
  int menor = valorCartas(jogo, k), temp = 0, cartaE = jogo[w];
  filho++;
  char menorL = char(filho), tempL;
  filaRg[k] = menor;
  letraRg[k] = menorL;

  // inicia o vetor
  for (size_t i = 0; i < NUM; i++) {
    filaRg[i] = 0;
  }

  for (int i = w; i < NUM; i++) {
    if (jogo[i] != 0 && RESULT % jogo[i] == 0) {
      int vCarta = valorCartas(jogo, i);
      if (menor > vCarta) {
        temp = menor;
        tempL = menorL;
        menor = vCarta;
        filho++;
        menorL = char(filho);
        filaRg[i - 1] = menor;
        filaRg[i] = temp;
        letraRg[i - 1] = menorL;
        letraRg[i] = tempL;
        cartaE = jogo[i];

      } else {
        filaRg[i] = vCarta;
        filho++;
        letraRg[i] = char(filho);
      }
    } else {
      filho++;
    }
  }
  for (int i = 1; i < NUM; i++) {

    if (filaRg[i] != 0) {
      fila.push_back(filaRg[i]);
      noFilho.push_back(letraRg[i]);
    }
  }
  delete[] filaRg;
  delete[] letraRg;

  escolheCarta(jogo, cartaE);

  return fila;
}

void filaRegras(vector<char> noFilho, vector<int> fila, vector<string> &lstAbertos) {
  string k;
  char f;
  cout << "Filhos de "<< char(RAIZ) << "(0): " "{ ";
  for (size_t i = 0; i < fila.size(); i++) {
    f = noFilho[i];
    k = to_string(fila[i]);
    concStrCharA(k, f, lstAbertos);
    cout << f << "(";
    cout << k << ") ";
  }
  cout << "}\n";
}

void printVec(string i) { // function:
  cout << ' ', i;
}

void listaAbertos(vector<string> &lstAbertos) {
  cout << "Lista de Abertos: { ";
  for (size_t i = 0; i < lstAbertos.size(); i++) {
    cout << lstAbertos[i];
  }
  cout << "}\n";
}

void listaFechados(vector<string> &lstFechados) {
  cout << "\nLista de Fechados: {";
  for (size_t i = 0; i < lstFechados.size(); i++) {
    cout << " " << lstFechados[i];
  }
  cout << "}\n";
}

void concat(char letra, char texto[]) {
  size_t tamanho = strlen(texto);
  texto[tamanho] = letra;
  texto[tamanho + 1] = '\0';
}

void concStrCharF(string k, char f, vector<string> &lstFechados) {

  // char f = char(RAIZ);
  string c(1, f);
  char cX[20];
  strcpy(cX, c.c_str());

  // string k = "(0)";
  char kX[20];
  strcpy(kX, k.c_str());

  char str1[20];
  char str2[20];
  strcpy(str1, cX);
  strcpy(str2, kX);
  strncat(str1, str2, 3);

  lstFechados.push_back(str1);
}

void concStrCharA(string k, char f, vector<string> &lstAbertos) {

  string c(1, f);
  char cX[20];
  strcpy(cX, c.c_str());

  string b = "(";
  char bX[20];
  strcpy(bX, b.c_str());

  char kX[20];
  strcpy(kX, k.c_str());

  string b1 = ") ";
  char b1X[20];
  strcpy(b1X, b1.c_str());

  char str1[20];
  char str2[20];
  char str3[20];
  char str4[20];

  strcpy(str1, cX);
  strcpy(str2, bX);
  strcpy(str3, kX);
  strcpy(str4, b1X);

  char str[80];
  strcpy(str, str1);
  strcat(str, str2);
  strcat(str, str3);
  strcat(str, str4);

  lstAbertos.push_back(str);
}

void Grava_Filhos_No(int *jogo, int *final, int &filho, vector<string> &lstAbertos) {
  for (int i = 1; i < NUM; i++) {
    int val = 0, temp;
    if (jogo[i] != 0) {
      for (int j = 1; j < NUM; j++)
        val += jogo[j];
      val -= jogo[i];                        // soma dos valores das cartas, menos a carta i
      val += (jogo[i] % (RESULT / jogo[0])); // (24/6) = 4 // 4%4 // 5%4 // 3%4 = resto + soma das cartas

      filho++;
      char f = char(filho);
      string k = to_string(val);
      concStrCharA(k, f, lstAbertos);
      cout << char(filho)
           << "(" << val << ")"
           << " ";
    }
  }
  cout << "} ";
}

//*

void ordenaFila(vector<int> &fila, vector<string> &lstAbertos) {

  string *filaAb = new string[100];
  int *filaRg = new int[10];
  int cont = 0;
  for (size_t i = 0; i < lstAbertos.size(); i++) {
    filaRg[i] = stoi(lstAbertos[i].substr(2, 2));
    filaAb[i] = lstAbertos[i];
    cont++;
  }
  int aux;
  string auxAb;
  for (int i = 0; i < lstAbertos.size(); i++) {
    for (int j = 0; j < lstAbertos.size(); j++) {
      if (filaRg[i] < filaRg[j]) {
        aux = filaRg[i];
        auxAb = filaAb[i];
        filaRg[i] = filaRg[j];
        filaAb[i] = filaAb[j];
        filaRg[j] = aux;
        filaAb[j] = auxAb;
      }
    }
  }
  lstAbertos.clear();

  for (size_t i = 0; i < cont; i++) {
    lstAbertos.push_back(filaAb[i]);
  }
  delete[] filaRg;
  delete[] filaAb;
}

//! Regra: terceira carta escolhida
int valorSoma(int *jogo, int i) {
  int valor = 0;
  int temp = 0;
  for (int j = 1; j < NUM; j++) { //! soma das cartas restantes
    temp += jogo[j];
  }
  //! soma das cartas restantes
  if (jogo[i] != 0) { //&& RESULT % jogo[i] == 0
    valor = (4 + jogo[i]);
    valor -= 4;
    valor += (temp - jogo[i]); // 4 % x + SOMA DAS CARTAS - CARTA(i)
  }
  return valor;
}

//! Regra: terceira carta escolhida
int valorSub(int *jogo, int i) {
  int valor = 0;
  int temp = 0;
  for (int j = 1; j < NUM; j++) { //! soma das cartas restantes
    temp += jogo[j];
  }
  //! subtração das cartas restantes
  if (jogo[i] != 0) { //&& RESULT % jogo[i] == 0
    valor = (4 - jogo[i]);
    if (valor < 0)
      valor = valor * (-1);
    valor -= 4;
    valor = valor * (-1);
    valor += (temp - jogo[i]); // 4 % x + SOMA DAS CARTAS - CARTA(i)
  }
  return valor;
}

//! Regra: quarta carta escolhida
int valorSomaQ(int *jogo, int i) {
  int valor = 0;
  int temp = 0;
  for (int j = 1; j < NUM; j++) { //! soma das cartas restantes
    temp += jogo[j];
  }
  //! subtração das cartas restantes
  if (jogo[i] != 0) {
    valor = (1 + jogo[i]);
    if (valor < 0)
      valor = valor * (-1);
    valor -= 4;
    valor = valor * (-1);
    valor += (temp - jogo[i]); // 4 % x + SOMA DAS CARTAS - CARTA(i)
  }
  return valor;
}
vector<int> gravaFilaFilho(int *jogo, vector<char> &noFilho, int &filho, int *carta, int k, int w) {
  int cont = 0;
  vector<int> filaFilho;
  for (size_t i = 1; i < NUM; i++)
    if (jogo[i] != 0)
      cont++;

  if (cont > 1) {

    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0) {
        filho++;
        filaFilho.push_back(valorSub(jogo, i));
        noFilho.push_back(char(filho));
      }
    }
    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0) {
        filho++;
        filaFilho.push_back(valorSoma(jogo, i));
        noFilho.push_back(char(filho));
      }
    }
  } else {
    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0) {
        filho++;
        filaFilho.push_back(valorSomaQ(jogo, i));
        noFilho.push_back(char(filho));
      }
    }
  }
  return filaFilho;
}

void imprimeAbertos(vector<int> &fila, vector<string> &lstAbertos, vector<char> &noFilho) {
  for (int i = 0; i < fila.size(); i++) {
    char f = noFilho[i];
    string k = to_string(fila[i]);
    concStrCharA(k, f, lstAbertos);
    cout << noFilho[i] << "(" << fila[i] << ")"
         << " ";
  }
  cout << "}";
}