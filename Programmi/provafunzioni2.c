#include <stdio.h>
int somma(int,int); 

int somma(int x,int y) {
printf("Inserisci i due valori\n");
scanf("%d%d",&x,&y);
return x+y; }

int main(void) {
int x;
printf("La somma è: %d\n",somma(x,x)); 
return 0;}
