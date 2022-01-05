#include "regras.h"
#include "stdc++.h"

int c1 = 4,
    c2 = 6,
    c3 = 5,
    c4 = 3,
    r = 24;

using namespace std;

//! R1 - O primeiro número dentro dos parênteses é o 4 (sua posição no vetor será zerada);
void r1(int jogo[], int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    v1 = c1;
    //cout << v1 <<" " << v2 << " "<< v3 <<" " << v4 << endl;
    jogo[0] = (v1);
   // cout <<"("<< v1 << ")"<<endl;
    jogo[1] = 0;
  }
}

//!R2 - O primeiro número dentro dos parênteses é o 6 (sua posição no vetor será zerada);
void r2(int *jogo, int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    v1 = c2;
    jogo[0] = (v1);
    jogo[2] = 0;
  }
}

//!R3 - O primeiro número dentro dos parênteses é o 5 (sua posição no vetor será zerada);
void r3(int *jogo, int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    v1 = c3;
    jogo[0] = (v1);
    jogo[3] = 0;
  }
}

//!R4 - O primeiro número dentro dos parênteses é o 3 (sua posição no vetor será zerada);
void r4(int *jogo, int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    v1 = c4;
    jogo[0] = (v1);
    jogo[4] = 0;
  }
}

//!R5 - Os sinais aritméticos simples dentro dos parênteses serão na ordem + e -;
void r5(int *jogo, int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    jogo[0] = (v1 + v2 - v3);
  }
}

//!R6 - Os sinais aritméticos simples dentro dos parênteses serão na ordem - e +;
void r6(int *jogo, int &v1, int &v2, int &v3, int &v4) {
  if (jogo[0] == 0) {
    jogo[0] = (v1 - v2 + v3);
  }
}

//!R7 - Caso o valor do vetor na posição 1 não seja 0, o número entre os sinais
//!dentro dos parênteses será o 4 (sua posição no vetor será zerada);
void r7(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[1] != 0) {
    v2 = c1;
    jogo[0] = (v1 - v2 + v3);
    jogo[1] = 0;
  }
}

//!R8 - Caso o valor do vetor na posição 2 não seja 0, o número entre os sinais
//!dentro dos parênteses será o 6 (sua posição no vetor será zerada);
void r8(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[2] != 0) {
    v2 = c2;
    jogo[0] = (v1 - v2 + v3);
   // cout <<"("<< v1 <<" - " << v2 << " + " << v3 << ")"<<endl;
    jogo[2] = 0;
  }
}

//!R9 - Caso o valor do vetor na posição 3 não seja 0, o número entre os sinais
//!dentro dos parênteses será o 5 (sua posição no vetor será zerada);
void r9(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[3] != 0) {
    v2 = c3;
    jogo[0] = (v1 - v2 + v3);
    jogo[3] = 0;
  }
}

//!R10 - Caso o valor do vetor na posição 4 não seja 0, o número entre os sinais
//!dentro dos parênteses será o 3 (sua posição no vetor será zerada);
void r10(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[4] != 0) {
    v2 = c4;
    jogo[0] = (v1 - v2 + v3);
    jogo[4] = 0;
  }
}

//!R11 - Caso o valor do vetor na posição 1 não seja 0, o último número dentro
//!dos parênteses será o 4 (sua posição no vetor será zerada);
void r11(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[1] != 0) {
    v3 = c1;
    jogo[0] = (v1 - v2 + v3);
    jogo[1] = 0;
  }
}
//!R12 - Caso o valor do vetor na posição 2 não seja 0, o último número entre os sinais
//!dentro dos parênteses será o 6 (sua posição no vetor será zerada);
void r12(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[2] != 0) {
    v3 = c2;
    jogo[0] = (v1 - v2 + v3);
    jogo[2] = 0;
  }
}

//!R13 - Caso o valor do vetor na posição 3 não seja 0, o último número entre os sinais
//!dentro dos parênteses será o 5 (sua posição no vetor será zerada);
void r13(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[3] != 0) {
    v3 = c3;
    jogo[0] = (v1 - v2 + v3);
    jogo[3] = 0;
  }
}

//!R14 - Caso o valor do vetor na posição 4 não seja 0, o último número entre os sinais
//!dentro dos parênteses será o 3 (sua posição no vetor será zerada);
void r14(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  if (jogo[4] != 0) {
    v3 = c4;
    jogo[0] = (v1 - v2 + v3);
    jogo[4] = 0;
  }
}

//!R15 - A posição no vetor entre 1 e 4 que não possuir 0 como valor será zerada
//!e o número contido nessa posição será colocado após a multiplicação na
//!posição 0 do vetor.
void r15(int *jogo, int &v1, int &v2, int &v3, int &v4) {

  for (int i = 1; i < NUM; i++)
    if (jogo[i] != 0) {
      v4 = jogo[i];
      jogo[0] = (v1 - v2 + v3) * v4;
      jogo[i] = 0;
    }
}