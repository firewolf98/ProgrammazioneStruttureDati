#include <stdio.h>
int main(void) {
int n,i,somma=0; 
printf("Inserisci N\n");
scanf("%d",&n); 
switch(n) {
case 1: printf("Lunedì\n"); break;
case 2: printf("Martedì\n"); break;
case 3: printf("Mercoledì\n"); break;
case 4: printf("Giovedì\n"); break;
case 5: printf("Venerdì\n"); break;
case 6: printf("Sabato\n"); break;
case 7: printf("Domenica\n"); break;
default: printf("Non è un giorno della settimana\n"); break; }
 }
