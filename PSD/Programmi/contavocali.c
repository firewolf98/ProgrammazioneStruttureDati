#include <stdio.h>
#include <string.h>


int main(void) {
int dim,i=0,vet[6]={0};
char parola[10];
printf("Inserisci la parola:\n");
scanf("%s",parola);
dim=strlen(parola); 
while(i<dim) {
switch(parola[i]) {
case 'A': vet[0]++; break; 
case 'E': vet[1]++; break;
case 'I': vet[2]++; break;
case 'O': vet[3]++; break;
case 'U': vet[4]++; break;
case 'a': vet[0]++; break; 
case 'e': vet[1]++; break;
case 'i': vet[2]++; break;
case 'o': vet[3]++; break;
case 'u': vet[4]++; break;
default: vet[5]++; break; }
i++;}
for(i=0;i<6;i++) {
printf("%d\n",vet[i]); }
return 0; }
