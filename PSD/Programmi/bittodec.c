#include <stdio.h>
#include <math.h>
#define MAX 32

int main(void) {
long int n;
int t=0,g=0,j=0,r=0;
double s,i,f;

printf("Inserisci N (MAX 32 bit)\n");
scanf("%ld",&n);
f=n;
do {
	f=f/10;
	s=modf(f,&i);
	f=f-s;
	s=s*10;
	j++;
	g=j;
	do {
		s=s*2;
		g--; }
	while(g>1);

	t=t+s; }
while(i!=0);

		
printf("%d",t);






return 0; }


