#include <stdio.h>
#include <math.h>
#define MAX 32

int main(void) {
int i,s,vet[MAX],r,n;
printf("Inserisci N:\n");
scanf("%d",&n);

for (i=MAX-1;i>=0;i--) {
r=n%2;
n=n/2;
if (r==0) 
vet[i]=0;
else
vet[i]=1; }

for(i=0; i<MAX;i++) 
printf("%d",vet[i]);

return 0; }
