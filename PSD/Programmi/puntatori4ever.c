#include <stdio.h>
#include <stdlib.h>
void inserisci(int[]);
void minmax(int [],int*,int*);


int main(void) {
int minimo,massimo,vet[10];
inserisci(vet);
minmax(vet,&massimo,&minimo);
printf("Il massimo è: %d\n",massimo);
printf("Il minimo è: %d\n",minimo); 
return 0; }


void inserisci (int a[]) {
int i;
for (i=0;i<10;i++) {
printf ("Inserisci il valore di posizione %d\n",i);
scanf ("%d",&a[i]); } }


void minmax (int a[],int *max,int *min) {
int i; 
*max=*min=a[0];
for(i=0;i<10;i++) {
if(a[i]>*max)
*max=a[i];
else if(a[i]<*min)
*min=a[i]; }}
