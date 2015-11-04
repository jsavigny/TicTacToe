/* TIC TAC TOE TBFO */
/* Levanji Prahyudi, 13513052 */
/* Julio Savigny, 13513084 */

/* KAMUS */
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#define jmlsh 248
#define jmlsc 67
#define jmlchar 55
static FILE *status;
char line[jmlsh][jmlchar];
int i,j,s,xi,oi,x;
char XO[10];
boolean p;
char pil,e;

void STARTCPU(){
/* I.S. : File CPU1st.txt berisi sesuai format table transisi */
/* F.S. : isi file CPU1st.txt dipindahkan ke array line */
    status=fopen("CPU1st.txt","r");
    for (i=0;i<=jmlsc-1;i++){
        fgets(line[i],jmlchar,status);
    }
    fclose(status);
}
void STARTHUMAN(){
/* I.S. : File Human1st.txt berisi sesuai format table transisi */
/* F.S. : isi file Human1st.txt dipindahkan ke array line */
    status=fopen("Human1st.txt","r");
    for (i=0;i<=jmlsh-1;i++){
        fgets(line[i],jmlchar,status);
    }
    fclose(status);
}
void pindahstate(int xin,int v, int *xout){
/* I.S. : current state ada di xin */
/* F.S. : current state ada di xout, dibaca dari masukan v */
    char tempstr[4];
    int i;
    for (i=0;i<=3;i++){
        tempstr[i]=line[xin][5*v+i];
    }
    *xout=(tempstr[1]-'0')*100+(tempstr[2]-'0')*10+(tempstr[3]-'0')*1;

}
boolean finalstate(int x){
/* Mengecek apakah state x adalah final state */
/* final state adalah jika komputer menang atau draw */
    if ((line[x][52]=='c') || (line[x][52]=='d')) {
        return true;
    }
    else {return false;}
}
void Print()
/* I.S. : array XO terisi */
/* F.S. : mencetak array XO menyerupai board tictactoe */
{
    system("cls");
	for (i = 1; i <= 3; i++)
	printf("| %c ", XO[i]);
	printf("|\n");
	printf("-------------\n");
	for (i = 4; i <= 6; i++)
	printf("| %c ", XO[i]);
	printf("|\n");
	printf("-------------\n");
	for (i = 7; i <= 9; i++)
	printf("| %c ", XO[i]);
	printf("|\n");
}
void masuk(char XO[10],char a,int j,boolean *berhasil){
/* I.S. : array XO terdefinisi */
/* F.S. : jika XO[j] bukan 'O' ataupun 'X', XO[j] diisi dengan a, berhasil diisi true, jika gagal diisi false */
    if ((XO[j]!='O')&&(XO[j]!='X')){
        XO[j]=a;
        *berhasil=true;
    }else{
        *berhasil=false;
    }
}
int main(){
    /* ALGORITMA */
    printf("****** TIC TAC TOE ******");
	do
    {
        printf("\na. CPU 1st\nb. Human 1st\nMasukkan pilihan : ");
        scanf("%c", &pil);
        if ((pil != 'a') && (pil != 'b')){
            system("cls");
            printf("****** TIC TAC TOE ******\n");
            printf("Masukan Salah! Silakan ulangi!\n");
        }
    }
	while((pil != 'a') && (pil != 'b'));
    if (pil == 'a')
	{
        for (i=1;i<=9;i++){
            XO[i]=' ';
        }
		XO[1] = 'O';
        STARTCPU();
        x=0;
        Print();
        while ((finalstate(x)==false)){
            do{
                printf("\nMasukkan input (1 - 9) : ");
                scanf("%d", &xi);
                if((xi <= 0) || (xi > 9)) {
                    printf("Masukan Tidak Valid, Silakan Ulangi \n");
                }
            }
            while ((xi <= 0) || (xi > 9));
            masuk(XO,'X',xi,&p);
            if(p==false){
                printf("Masukan Tidak Valid, Silakan Ulangi \n");
            }else{
                pindahstate(x,xi,&s);
                x=s;
                oi=line[x][50]-'0';
                masuk(XO,'O',oi,&p);
                Print();
            }
        }
        if (line[x][52]=='c') {
            printf("Komputer Menang!\n");
        }
        else if (line[x][52]=='d') {
            printf("Draw! Seri!\n");
        }
	}
    else if (pil == 'b')
	{
        for (i=1;i<=9;i++){
            XO[i]=' ';
        }
        STARTHUMAN();
        x=0;
        Print();
        while ((finalstate(x)==false)){
            do{
                printf("\nMasukkan input (1 - 9) : ");
                scanf("%d", &xi);
                if((xi <= 0) || (xi > 9)) {
                    printf("Masukan Tidak Valid, Silakan Ulangi \n");
                }
            }
            while ((xi <= 0) || (xi > 9));
            masuk(XO,'X',xi,&p);
            if(p==false){
                printf("Masukan Tidak Valid, Silakan Ulangi \n");
            }else{
                pindahstate(x,xi,&s);
                x=s;
                if (line[x][52]!='d'){
                    oi=line[x][50]-'0';
                    masuk(XO,'O',oi,&p);
                }
                Print();
            }
        }
        if (line[x][52]=='c') {
            printf("Komputer Menang!\n");
        }
        else if (line[x][52]=='d') {
            printf("Draw! Seri!\n");
        }
	}
    system("pause");
    return 0;
}


