#include <stdio.h>
#include <math.h>
#define MAX 7

int input(int[]);
void stampa();

int input(int vet[]) {
int i;
for(i=0;i<MAX;i++) {
printf("Inserisci un valore:\n");
scanf("%d",&vet[i]);  }
}


void stampa(int a[]) {
int i;
for(i=0;i<MAX;i++) 
printf("%d",a[i]); }

int main(void) {
int a[MAX],i;
input(a);
stampa(a); }
