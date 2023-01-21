#include <stdio.h>
#define N 5

void input(int[]);
int copiapari(int[],int[],int[]);
int stampa(int[],int);

int main(void) {
int a[N],b[N],c[2*N],n;
input(a);
input(b);
n=copiapari(a,b,c);
printf("Gli elementi pari dei due vettori sono:");
stampa(c,n); }


void input(int vet[]) {
int i;
for(i=0;i<N;i++) {
printf("Inserisci un valore:");
scanf("%d",&vet[i]); } }


int copiapari(int a[],int b[], int c[]) {
int i,count=0;
for(i=0;i<N;i++) {
if(a[i]%2==0) {
c[count]=a[i];
count++; }}
for(i=0;i<N;i++) {
if(b[i]%2==0) {
c[count]=b[i];
count++; }}
return count; }

int stampa(int vet[],int n) {
int i;
for(i=0;i<N;i++) 
printf("%d\n",vet[i]); }
