#include <stdio.h>
#include <math.h>
#define MAX 7

void input(int[]);
int somma(int[]);


int main(void) {
int a[MAX],sum;
input(a);
sum=somma(a);
printf("La somma è:%d\n",sum);
 }



void input(int vet[]) {
int i;
for(i=0;i<=MAX;i++) {
printf("Inserisci un valore:\n");
scanf("%d",&vet[i]); } }


int somma(int vet[]) {
int i,sum=0;
for(i=0;i<=MAX;i++)
sum+=vet[i];
return sum; }


