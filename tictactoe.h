#include "boolean.h"
#include <stdio.h>
#ifndef TICTACTOE_H
#define TICTACTOE_H
void STARTCPU();
/* I.S. : File CPU1st.txt berisi sesuai format table transisi */
/* F.S. : isi file CPU1st.txt dipindahkan ke array line */
void STARTHUMAN();
/* I.S. : File Human1st.txt berisi sesuai format table transisi */
/* F.S. : isi file Human1st.txt dipindahkan ke array line */
void pindahstate(int x,int s, int *xout);
/* I.S. : current state ada di x */
/* F.S. : current state ada di xout */
boolean finalstate(int x);
void Print();
#endif // TICTACTOE_H
