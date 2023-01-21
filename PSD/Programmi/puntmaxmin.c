#include <stdio.h>
#define MAX 100
void leggi_lista(int[],int*);
int *cerca_minore(int[],int);
int *cerca_maggiore(int[],int);
void stampa(int*,int*);


int main(void) {
int array[MAX],*punta_a_minore,*punta_a_maggiore,num=0;
leggi_lista(array,&num);
punta_a_minore=cerca_minore(array,num);
punta_a_maggiore=cerca_maggiore(array,num);
stampa(punta_a_minore,punta_a_maggiore);
return 0; }


void leggi_lista(int lista[],int *n) {
printf("Immettere una sequenza di valori (max 100), -1 per terminare\n");
while(*n<MAX) {
printf("Inserisci l'elemento con indice %d\t",*n);
scanf("%d",&lista[*n]);
if(lista[(*n)++]==-1)
break; }}


int *cerca_minore(int array[],int num) {
int *minore,i;
minore=&array[0];
i=1;
while(i<num-1) {
if(array[i]<*minore)
minore=&array[i];
i++; }
return (minore); }


int *cerca_maggiore(int array[],int num) {
int *maggiore,i;
maggiore=&array[0];
i=1;
while(i<num-1) {
if(array[i]>*maggiore)
maggiore=&array[i];
i++; }
return (maggiore); }


void stampa(int *punta_a_minore,int *punta_a_maggiore) {
printf("Il maggiore ha indirizzo %p\ne contiene il valore %d\n",punta_a_maggiore,*punta_a_maggiore);
printf("Il minore ha indirizzo %p\ne contiene il valore %d\n",punta_a_minore,*punta_a_minore); }
