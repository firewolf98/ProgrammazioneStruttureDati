#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define N 10 
#define M 10
void inizializza(char[][M]);
void walk(char[][M]);
void stampa(char[][M]);


int main(void) {
char mat[N][M];
srand((unsigned)time(NULL));
inizializza(mat);
stampa(mat);
printf("\n");
walk(mat);
stampa(mat); }



void inizializza(char mat[][M]) {
int i,j;
for(i=0;i<N;i++)
for(j=0;j<M;j++) 
mat[i][j]='.'; } 


void walk(char mat[][M]) {
int i,err=0,x,y,move,cnt='A'-'.';
x=rand()%10;
y=rand()%10;
mat[x][y]+=cnt++;
for(i=0;i<25;i++) {
retry:
if(err>=50)
break;
move=rand()%4;
switch(move) {
case 0: if(x-1<0||mat[x-1][y]!='.') { err++; goto retry; } x--; mat[x][y]+=cnt++; err=0; break;
case 1: if(x+1>9||mat[x+1][y]!='.') { err++; goto retry; } x++; mat[x][y]+=cnt++; err=0; break;
case 2: if(y-1<0||mat[x][y-1]!='.') { err++; goto retry; } y--; mat[x][y]+=cnt++; err=0; break;
case 3: if(y+1>9||mat[x][y+1]!='.') { err++; goto retry; } y++; mat[x][y]+=cnt++; err=0; break; }}
if(i!=25)
printf("La randomwalk è terminata prima della lettera Z\n");
else 
printf("La randomwalk è terminata con successo!\n");}




void stampa(char mat[][M]) {
int i,j;
for(i=0;i<N;i++) {
for(j=0;j<M;j++) 
printf("%2c",mat[i][j]);
printf("\n");} }
