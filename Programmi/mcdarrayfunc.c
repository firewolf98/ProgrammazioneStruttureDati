#include <stdio.h>
#include <math.h>
#define MAX 10 

void input(int[]);
int massimo(int[]);
int minimo(int[]);
int mcd(int[],int,int);


int main(void) {
int a[MAX],x,y,m;
input(a);
x=massimo(a);
y=minimo(a);
m=mcd(a,x,y);
printf("Il MCD è:%d\n",m);

}



void input(int vet[]) {
int i;
for(i=0;i<MAX;i++) {
printf("Inserisci un valore\n");
scanf("%d",&vet[i]); } 
}


int massimo(int vet[]) {
int i,mas=0;
for(i=0;i<MAX;i++) {
if(vet[i]>mas)
mas=vet[i]; }
return mas; }

int minimo(int vet[]) {
int i,min=0;
for(i=0;i<MAX;i++) {
if(vet[i]<min)
min=vet[i]; }
return min; }

int mcd(int vet[],int a,int b) {
int mcd;
while(a!=b) {
if(a>b)
a=a-b;
else
b=b-a;
mcd=a; }
return mcd; }
