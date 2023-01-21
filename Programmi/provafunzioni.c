#include <stdio.h>
int quadrato(int);

int quadrato(int y) {
printf("Inserisci un valore\n");
scanf("%d",&y);
return y*y; }

int main(void) {
int x;
printf("Il quadrato è: %d\n",quadrato(x));
return 0; }
