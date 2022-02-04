#include "regras.h"
#include "stdc++.h"
#include <string>
using namespace std;

vector<int> Formula24(vector<int> form24) {
  int t = 0;
  for (size_t i = 0; i < NUM - 2; i++)
    form24[i] = 0;

  form24[2] = form24[0] * form24[1];

  return form24;
}

string convChar(char f) {

  string c(1, f);
  char cX[20];
  strcpy(cX, c.c_str());
  return cX;
}

void verificaFinal(int *jogo, int *final) {
  if (jogo[0] == final[0] && jogo[1] == final[1] && jogo[2] == final[2] && jogo[3] == final[3] && jogo[4] == final[4])
    cout << "\nFim de jogo!\n";
  else
    cout << "\nContinue...\n";
}

void verificaFinalH(int *jogo, int *final, int &custo, vector<string> &lstFechados) {
  if (jogo[0] == final[0] && jogo[1] == final[1] && jogo[2] == final[2] && jogo[3] == final[3] && jogo[4] == final[4]) {
    {
      cout << "\nSucesso!\n";
      for (size_t i = 0; i < lstFechados.size(); i++)
        custo += stoi(lstFechados[i].substr(2, 2));
      cout << "Custo: " << custo << endl;
    }
  } else {
    if (jogo[0] != final[0] && jogo[1] == final[1] && jogo[2] == final[2] && jogo[3] == final[3] && jogo[4] == final[4])
      cout << "\nImpasse!\n";
    else
      cout << "\nContinue...\n";
  }
}

void impEstado(int *jogo) {
  cout << "{";
  for (int i = 0; i < NUM; i++) {
    cout << jogo[i];
    if (i < NUM - 1)
      cout << ", ";
  }
  cout << "}";
}

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

void escolheCarta(int *jogo, int cartaE) {

  for (size_t i = 0; i < NUM; i++) {
    if (jogo[i] == cartaE) {
      jogo[0] = cartaE;
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

  for (size_t i = 0; i < fila.size(); i++) {
    f = noFilho[i];
    k = to_string(fila[i]);
    char *str;
    str = concStrCharA(k, f, lstAbertos);
    // lstAbertos.push_back(str);
    cout << f << "(";
    cout << k << ") ";
  }
}

void printVec(string i) { // function:
  cout << ' ', i;
}

void impLstAbertos(vector<string> &lstAbertos) {
  cout << "Lista de Abertos: {";
  for (size_t i = 0; i < lstAbertos.size(); i++) {
    cout << " " << lstAbertos[i];
  }
  cout << " }\n";
}

void impLstFechados(vector<string> &lstFechados) {
  cout << "Lista de Fechados: {";
  for (size_t i = 0; i < lstFechados.size(); i++) {
    cout << " " << lstFechados[i];
  }
  cout << " }\n";
}

void impLstFila(vector<string> &fila) {
  cout << "Fila: {";
  for (size_t i = 0; i < fila.size(); i++) {
    cout << " " << fila[i];
  }
  cout << " }\n";
}

void impLstPilha(stack<string> &p) {
  stack<string> temp;
  cout << "Pilha: {";
  // for (size_t i = 0; i < p.size(); i++)
  while (!p.empty()) {
    cout << " " << p.top();
    temp.push(p.top());
    p.pop();
  }
  cout << " }\n";
  while (!temp.empty()) {
    p.push(temp.top());
    temp.pop();
  }
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

char *concStrCharA(string k, char f, vector<string> &lstAbertos) {

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
  char *strchar = str;
  lstAbertos.push_back(strchar);
  return strchar;
}

//! Ordena a lista de abertos
void ordenaFila(vector<int> &fila, vector<string> &lstAbertos) {

  string *filaAb = new string[10];
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

//! Regra: Inicial
int valorI(int *jogo, int i) {
  int valor = 0;
  int temp = 0;

  for (int j = 1; j < NUM; j++) {
    temp += jogo[j];
  }
  if (jogo[i] != 0 && RESULT % jogo[i] == 0) {
    valor = (RESULT / jogo[i]);
    valor += (temp - jogo[i]);
  }
  return valor;
}
//! Regra: segunda carta escolhida
int valorDiv(int *jogo, int i) {
  int valor = 0;
  int temp = 0;
  for (int j = 1; j < NUM; j++) {
    temp += jogo[j];
  }
  if (jogo[i] != 0) {
    valor = (4 - jogo[i]);
    if (valor < 0)
      valor = valor * (-1);
    valor += (temp - jogo[i]);
  }
  return valor;
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

  if (jogo[i] != 0) {
    valor = (1 + jogo[i]);
    if (valor < 0)
      valor = valor * (-1);
    valor -= 4;
    valor = valor * (-1);
    valor += (temp - jogo[i]);
  }
  return valor;
}
vector<int> gravaFilaFilho(int *jogo, vector<char> &noFilho, int &filho, int *carta, int *cartaX) {
  int cont = 0, valor = 0;
  vector<int> filaFilho;
  for (size_t i = 1; i < NUM; i++)
    if (jogo[i] != 0)
      cont++;
  switch (cont) {
  case 4: {
    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0 && RESULT % jogo[i] == 0) {
        filho++;
        valor = valorI(jogo, i);
        if (valor < cartaX[0]) {
          cartaX[0] = valor;
          cartaX[1] = jogo[i];
        }
        filaFilho.push_back(valor);
        noFilho.push_back(char(filho));
      } else {
        filho++;
      }
    }
  } break;
  case 3: {
    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0) {
        filho++;
        valor = valorDiv(jogo, i);
        if (valor < cartaX[0]) {
          cartaX[0] = valor;
          cartaX[1] = jogo[i];
        }
        filaFilho.push_back(valorDiv(jogo, i));
        noFilho.push_back(char(filho));
      }
    }
  } break;
  case 2: {
    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0) {
        filho++;
        valor = valorSub(jogo, i);
        if (valor < cartaX[0]) {
          cartaX[0] = valor;
          cartaX[1] = jogo[i];
        }
        filaFilho.push_back(valorSub(jogo, i));
        noFilho.push_back(char(filho));
      }
    }
    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0) {
        filho++;
        valor = valorSoma(jogo, i);
        if (valor < cartaX[0]) {
          cartaX[0] = valor;
          cartaX[1] = jogo[i];
        }
        filaFilho.push_back(valorSoma(jogo, i));
        noFilho.push_back(char(filho));
      }
    }
  } break;
  case 1: {
    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0) {
        filho++;
        valor = valorSomaQ(jogo, i);
        if (valor < cartaX[0]) {
          cartaX[0] = valor;
          cartaX[1] = jogo[i];
        }
        filaFilho.push_back(valorSomaQ(jogo, i));
        noFilho.push_back(char(filho));
      }
    }
  } break;
  }

  return filaFilho;
}

void impFilhos(vector<int> &fila, vector<string> &lstAbertos, vector<char> &noFilho) {
  for (int i = 0; i < fila.size(); i++) {
    char f = noFilho[i];
    string k = to_string(fila[i]);
    concStrCharA(k, f, lstAbertos);
    cout << noFilho[i] << "(" << fila[i] << ")"
         << " ";
  }
  cout << "}";
}

void limpaNo(vector<char> &noFilho, vector<int> &fila) {
  while (fila.size() != 0)
    fila.erase(fila.begin());

  while (noFilho.size() != 0)
    noFilho.erase(noFilho.begin());
}
void limpaNoH(vector<char> &noFilho, vector<char> &noFilhoA, vector<int> &filaA, vector<int> &filaO, vector<int> &filaH) {
  while (filaA.size() != 0)
    filaA.erase(filaA.begin());
  while (filaO.size() != 0)
    filaO.erase(filaO.begin());
  while (filaH.size() != 0)
    filaH.erase(filaH.begin());

  while (noFilho.size() != 0)
    noFilho.erase(noFilho.begin());
  while (noFilhoA.size() != 0)
    noFilhoA.erase(noFilhoA.begin());
}

void alteraValor(int *jogo, int k) {
  for (int i = 1; i < NUM; i++) {
    if (jogo[i] == k) {
      jogo[i] = 0;
      switch (k) {
      case 4:
        jogo[0] *= k; // E(8) = 4
        break;
      case 6:
        jogo[0] = k; // (0) = 6
        break;
      case 5:
        jogo[0] = 6 * ((4 - 5) * (-1)); // H(6) = 5
        break;
      case 3:
        jogo[0] = 6 * (((4 - 5) * (-1)) + 3); // L(0) = 3
        break;
      default:
        cout << "\n\nOpção inválida! Tente novamente.\n";
        break;
      }
    }
  }
}

void ImpFilhoRaiz(int *jogo, int &filho) {
  int temp = 0;
  int valor = 0;
  for (int j = 1; j < NUM; j++) { //! soma das cartas
    temp += jogo[j];
  }

  cout << "{";
  for (int i = 1; i < NUM; i++) {
    valor = (RESULT / jogo[i]) + (temp - jogo[i]);
    if (RESULT % jogo[i] == 0) {
      cout << " " << char(filho + i) << " - " << RESULT << "/" << jogo[i] << " + " << temp - jogo[i] << " → " << valor;
    } else {
      cout << " " << char(filho + i) << " - " << RESULT << "/" << jogo[i] << " + " << temp - jogo[i] << " → ESTADO INVÁLIDO";
    }
    if (i < NUM - 1)
      cout << ",";
  }
  cout << "}\n";
}

//?================= Heurística ============================

void ImpFilhoRaizH(int *jogo, int &filho) {
  int temp = 0;
  int valor = 0;
  for (int j = 1; j < NUM; j++) { //! soma do numeo de cartas diferente de zero
    if (jogo[j] != 0)
      temp++;
  }

  cout << "{";
  for (int i = 1; i < NUM; i++) {
    valor = (RESULT / jogo[i]) + (temp - 1);
    if (RESULT % jogo[i] == 0) {
      cout << " " << char(filho + i) << " - " << RESULT << "/" << jogo[i] << " + " << temp - 1 << " → " << valor;
    } else {
      cout << " " << char(filho + i) << " - " << RESULT << "/" << jogo[i] << " + " << temp - 1 << " → ESTADO INVÁLIDO";
    }
    if (i < NUM - 1)
      cout << ",";
  }
  cout << "}\n";
}

//! Regra1: Inicial  - Raiz
int valorH4(int *jogo, int i) {
  int valor = 0;
  int temp = 0;

  for (int j = 1; j < NUM; j++) { //! soma do numeo de cartas diferente de zero
    if (jogo[j] != 0)
      temp++;
  }
  if (jogo[i] != 0 && RESULT % jogo[i] == 0) {
    valor = (RESULT / jogo[i]) + (temp - 1);
  }
  return valor;
}
//! Regra2: segunda carta
int valorH3(int *jogo, int i) {
  int valor = 0;
  int temp = 0;

  for (int j = 1; j < NUM; j++) { //! soma do numeo de cartas diferente de zero
    if (jogo[j] != 0)
      temp++;
  }
  if (jogo[i] != 0) {
    // cout<< "\nJogo"<<i<<": " << jogo[i]<< endl;
    valor = (4 - jogo[i]);
    if (valor < 0)
      valor = valor * (-1);
    valor += (temp - 1);
  }

  return valor;
}

//! Regra3: terceira carta - subtração
int valorH2Sub(int *jogo, int i) {
  int valor = 0;
  int temp = 0;

  for (int j = 1; j < NUM; j++) { //! soma do numeo de cartas diferente de zero
    if (jogo[j] != 0)
      temp++;
  }
  //! subtração das cartas restantes
  if (jogo[i] != 0) {
    valor = (4 - jogo[i]);
    if (valor < 0)
      valor = valor * (-1);
    // valor -= 4;
    // if (valor < 0)
    //   valor = valor * (-1);
    valor += (temp - 1) - 4; // (4-(4-i))
  }

  return valor;
}

//! Regra4: terceira carta - Soma
int valorH2Soma(int *jogo, int i) {
  int valor = 0;
  int temp = 0;

  for (int j = 1; j < NUM; j++) { //! soma do numeo de cartas diferente de zero
    if (jogo[j] != 0)
      temp++;
  }
  //! soma das cartas restantes
  if (jogo[i] != 0) {
    valor = (4 + jogo[i]);
    // if (valor < 0)
    //   valor = valor * (-1);
    // valor -= 4;
    // if (valor < 0)
    //   valor = valor * (-1);
    valor += (temp - 1) - 4; // (4-(4+i))
  }

  return valor;
}

//! Regra5: quarta carta
int valorH1(int *jogo, int i) {
  int valor = 0;
  int temp = 0;

  for (int j = 1; j < NUM; j++) { //! soma do numeo de cartas diferente de zero
    if (jogo[j] != 0)
      temp++;
  }
  //! soma da carta restante
  if (jogo[i] != 0) {
    valor = (1 + jogo[i]);
    valor += (temp - 1) - 4;
  }

  return valor;
}

vector<int> gravaFilaFilhoH(int *jogo, vector<char> &noFilho, int &filho, int *carta, int *cartaX) {
  vector<int> v;

  int cont = 0, valor = 0;
  vector<int> filaFilho;
  for (size_t i = 1; i < NUM; i++)
    if (jogo[i] != 0)
      cont++;
  switch (cont) {
  case 4: { // raiz
    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0 && RESULT % jogo[i] == 0) {
        filho++;
        valor = valorH4(jogo, i);
        if (valor < cartaX[0]) {
          cartaX[0] = valor;
          cartaX[1] = jogo[i];
        }
        filaFilho.push_back(valor);
        noFilho.push_back(char(filho));
      } else {
        filho++;
      }
    }
  } break;
  case 3: {
    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0) {
        filho++;
        valor = valorH3(jogo, i);
        if (valor < cartaX[0]) {
          cartaX[0] = valor;
          cartaX[1] = jogo[i];
        }
        filaFilho.push_back(valor);
        noFilho.push_back(char(filho));
      }
    }
  } break;
  case 2: {
    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0) {
        filho++;
        valor = valorH2Sub(jogo, i);
        if (valor < cartaX[0]) {
          cartaX[0] = valor;
          cartaX[1] = jogo[i];
        }
        filaFilho.push_back(valor);
        noFilho.push_back(char(filho));
      }
    }

    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0) {
        filho++;
        valor = valorH2Soma(jogo, i);
        if (valor < cartaX[0]) {
          cartaX[0] = valor;
          cartaX[1] = jogo[i];
        }
        filaFilho.push_back(valor);
        noFilho.push_back(char(filho));
      }
    }
  } break;
  case 1: {
    for (int i = 1; i < NUM; i++) {
      if (jogo[i] != 0) {
        filho++;
        valor = valorH1(jogo, i);
        if (valor < cartaX[0]) {
          cartaX[0] = valor;
          cartaX[1] = jogo[i];
        }
        filaFilho.push_back(valor);
        noFilho.push_back(char(filho));
      }
    }
  } break;
  }
  return filaFilho;
}

//? ================= LARGURA ==================

void ImpFilhoRaizI(int *jogo, int &filho) {
  int valor = 0;

  cout << " → {";
  for (int i = 1; i < NUM; i++) {
    valor = (RESULT / jogo[i]);
    if (RESULT % jogo[i] == 0) {
      cout << " " << char(filho + i) << " - " << RESULT << "/" << jogo[i] << " → " << valor;
    } else {
      cout << " " << char(filho + i) << " - " << RESULT << "/" << jogo[i] << " → ESTADO INVÁLIDO";
    }
    if (i < NUM - 1)
      cout << ",";
  }
  cout << "}";
}

vector<string> gravaEstado(int *jogo, int &filho, int gJogo[][NUM], string cartaXL[][NO], int &contNO, int t) {

  vector<string> vetFilho;
  int temp = 0;
  cout << "{ ";
  for (int i = 1; i < NUM; i++) {

    if (t == 0) {
      filho++;
      if (RESULT % jogo[i] == 0) { //
        char f = char(filho);
        string s = convChar(f);
        vetFilho.push_back(s);

        contNO++;
        cartaXL[0][contNO] = s;
        cartaXL[1][contNO] = to_string(jogo[i]);
        cout << s << "("; // letra
        for (int j = 0; j < NUM; j++) {
          temp = jogo[i];
          jogo[0] = jogo[i];
          jogo[i] = 0;
          int k = jogo[j];
          gJogo[i - 1][j] = k;
          cout << k; // valor da carta
          jogo[i] = temp;
          if (j < NUM - 1)
            cout << ", ";
        }
        cout << ")";
        if (i < NUM - 1)
          cout << ", ";
      }
      jogo[0] = temp;

    } else {
      if (t > 0 && t < 4) {
        if (jogo[i] != 0) {
          filho++;
          char f = char(filho);
          string s = convChar(f);
          vetFilho.push_back(s); // vetFilho - filhos de A
          contNO++;
          cartaXL[0][contNO] = s;                  // letra
          cartaXL[1][contNO] = to_string(jogo[i]); // numero
          cout << s << "(";                        // letra
          for (int j = 0; j < NUM; j++) {
            temp = jogo[i];
            jogo[0] -= jogo[i];
            jogo[i] = 0;
            int k = jogo[j];
            gJogo[i - 1][j] = k;
            cout << k; // valor da carta
            jogo[i] = temp;

            if (j < NUM - 1)
              cout << ", ";

            jogo[0] = stoi(cartaXL[1][t]); //! 4 → A
            // cout << " * "<< jogo[0]<<" * ";
          }
          cout << ")";
          if (i < NUM - 1)
            cout << ", ";
        }
        // jogo[0] = stoi(cartaXL[1][t]); //! 4 → A
      } else {
        i++;

        if (jogo[i] != 0) {
          filho++;
          char f = char(filho);
          string s = convChar(f);
          vetFilho.push_back(s); // vetFilho - filhos de A
          contNO++;
          cartaXL[0][contNO] = s;                  // letra
          cartaXL[1][contNO] = to_string(jogo[i]); // numero
          cout << s << "(";                        // letra
          for (int j = 0; j < NUM; j++) {
            temp = jogo[i];
            jogo[0] += jogo[i];
            jogo[i] = 0;
            int k = jogo[j];
            gJogo[i - 1][j] = k;
            cout << k; // valor da carta
            jogo[i] = temp;

            if (j < NUM - 1)
              cout << ", ";

            jogo[0] = stoi(cartaXL[1][t]); //! 4 → A
            // cout << " * "<< jogo[0]<<" * ";
          }
          cout << ")";
          if (i < NUM - 1)
            cout << ", ";
        }
        // jogo[0] = stoi(cartaXL[1][t]); //! 4 → A
      }
    }
  }
  cout << " }";
  return vetFilho;
}

void limpaFilaL(vector<string> &fila) {
  while (fila.size() != 0)
    fila.erase(fila.begin());
}

void limpaPilha(stack<string> &p) {
  while (!p.empty())
    p.pop();
}




stack<string> gEstadoP(int *jogo, int &filho, int gJogo[][NUM], string cartaXL[][NO], int &contNO, int t) {

  stack<string> pFilho;
  int temp = 0;
  cout << "{ ";
  for (int i = 1; i < NUM; i++) {

    if (t == 0) {
      filho++;
      if (RESULT % jogo[i] == 0) { //
        char f = char(filho);
        string s = convChar(f);
        pFilho.push(s);

        contNO++;
        cartaXL[0][contNO] = s;
        cartaXL[1][contNO] = to_string(jogo[i]);
        cout << s << "("; // letra
        for (int j = 0; j < NUM; j++) {
          temp = jogo[i];
          jogo[0] = jogo[i];
          jogo[i] = 0;
          int k = jogo[j];
          gJogo[i - 1][j] = k;
          cout << k; // valor da carta
          jogo[i] = temp;
          if (j < NUM - 1)
            cout << ", ";
        }
        cout << ")";
        if (i < NUM - 1)
          cout << ", ";
      }
      jogo[0] = temp;

    } else {
      if (t > 0 && t < 4) {
        if (jogo[i] != 0) {
          filho++;
          char f = char(filho);
          string s = convChar(f);
          pFilho.push(s); // vetFilho - filhos de A
          contNO++;
          cartaXL[0][contNO] = s;                  // letra
          cartaXL[1][contNO] = to_string(jogo[i]); // numero
          cout << s << "(";                        // letra
          for (int j = 0; j < NUM; j++) {
            temp = jogo[i];
            jogo[0] -= jogo[i];
            jogo[i] = 0;
            int k = jogo[j];
            gJogo[i - 1][j] = k;
            cout << k; // valor da carta
            jogo[i] = temp;

            if (j < NUM - 1)
              cout << ", ";

            jogo[0] = stoi(cartaXL[1][t]); //! 4 → A
            // cout << " * "<< jogo[0]<<" * ";
          }
          cout << ")";
          if (i < NUM - 1)
            cout << ", ";
        }
        // jogo[0] = stoi(cartaXL[1][t]); //! 4 → A
      } 
    }
  }
  cout << " }";
  return pFilho;
}
