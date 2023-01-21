#include <stdio.h>
#define N 5
int carica(int a[]);
int verifica(int a[],int b[],int c[]);
int stampa(int a[],int n);


int carica(int a[]) {
int x;
for(x=0;x<N;x++) {
printf("Inserisci un valore\n");
scanf("%d",&a[x]); }
 }


int verifica(int a[],int b[],int c[]) {
int x,y=0;
for(x=0;x<N;x++) 
	{
	if(a[x]%2==0) 
		{
		c[y]=a[x];
		y++;
		}
	}
for(x=0;x<N;x++) 
	{
	if(b[x]%2==0) 
		{
		c[y]=b[x];
		y++;
		}
	}
return y; }


int stampa(int a[],int n) {
int x;
for(x=0;x<n;x++) 
printf("%d",a[x]); printf("\n"); }

int main(void) {
int a[N],b[N],c[2*N],n;
printf("Inserisci il primo vettore\n");
carica(a);
printf("Inserisci il secondo vettore\n");
carica(b);
n=verifica(a,b,c);
printf("Gli elementi pari dei due vettori sono:\n");
stampa(c,n);
return 0; }

