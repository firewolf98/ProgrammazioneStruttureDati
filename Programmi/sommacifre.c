#include <stdio.h>
#include <math.h>
int main(void) {
double n,c,s,i;
printf("Inserisci il numero N:\n");
scanf("%lf",&n);
s=0; c=0;

do
{
	n=n/10;
	c=modf(n,&i);
	n=n-c;
	c=c*10;
	s=s+c;
	
	}
	while(n>0);
printf("La somma è:%lf\n",s); 
return 0; }
