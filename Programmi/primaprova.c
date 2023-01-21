#include <stdio.h>
#include <math.h>
#define MAX 10

void input(int[]);
int primo(int);
int somma_cifre(int);
int somma_totale(int[]); 

int main(void) {
int a[MAX],sum,su;
input(a);
sum=somma_totale(sum);
printf("La somma totale è:%d\n",sum);
}


void input(int vet[]) {
int i;
for(i=0;i<MAX;i++) {
printf("Inserisci un valore:\n");
scanf("%d",&vet[i]); }
}


int primo(int num) {
int i,a[MAX],r=0,s=0,risp;
for(i=0;i<MAX;i++) {
r=a[i]%2; 
if(r==0) {
s=s+1;
if(s==2)
risp=1;}
else 
risp=0; } }
return risp; }


int somma_cifre(int sum) {
int i,temp=0,inter,vet[MAX];
double f,fract;
for(i=0;i<MAX;i++) {
f=vet[i];
do {
	f/=10;
	fract=modf(f,&inter);
	f=f-fract;
	fract*=10;
	temp+=fract; }
while(inter!=0);
}
return temp; }


int somma_totale(int vet[]) {
int i,x,s,a[MAX];
for(i=0;i<MAX;i++) {
s=primo(a);
if(s==1) 
x=somma_cifre(x);
else
x=-somma_cifre(x);
somma+=x;}
return somma; }













