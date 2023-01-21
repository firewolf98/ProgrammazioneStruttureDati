#include <stdio.h>
int main(void) {
float n,i,s,m;
s=0;
i=0; 

printf ("Il ciclo si interrompe quando scrivi -1\n");

do {
	printf("Inserisci un numero:\n");
	scanf("%f",&n);
	s=s+n; 
	i=i+1; 
    }
	while(n!=-1);
	
	s=s+1;
	i=i-1;
	m=s/i; 
printf("La media è: %f\n",m);
return 0; }
