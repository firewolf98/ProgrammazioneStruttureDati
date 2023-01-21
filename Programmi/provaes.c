#include <stdio.h>
int main(void) {
int vet[7],i;
for(i=0;i<7;i++) {
vet[i]=0;
printf("Inserisci un valore\n");
scanf("%d",&vet[i]); }

for(i=0;i<7;i++) {
printf("%d\n",vet[i]); }
return 0; }
