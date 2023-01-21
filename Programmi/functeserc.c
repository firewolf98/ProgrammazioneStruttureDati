#include <stdio.h>
#define MAX 10

int input(int[]);
int stampa(int[]);
int media(int[],int);

int main(void) {
int vet[MAX],m;
input(vet);
stampa(vet);
printf("La media è: %d\n",media(vet,m));
}


int input(int vet[]) {
int i;
for(i=0;i<MAX;i++) {
printf("Inserisci un valore:\n");
scanf("%d",&vet[i]); }
}


int stampa(int vet[]) {
int i; 
if(vet[MAX-1]>=0) 
	for(i=0;i<MAX;i++) {
		if(vet[i]>=0) 
		printf("%d\n",vet[i]); }
else 
	for(i=0;i<MAX;i++) {
		if(vet[i]<0) 
		printf("%d\n",vet[i]); }
}


int media(int vet[],int m) {
int s=0,i; 
for(i=0;i<MAX;i++) 
	s+=vet[i];
m=s/MAX;
return m; }
