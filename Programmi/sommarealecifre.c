#include <stdio.h>
#include <math.h>
int main(void) {
double s,n,r,i,c,y,x,a,b,t;

s=0; y=0; t=0; c=0;

printf("Inserisci un numero reale N:\n");
scanf("%lf",&n);


	x=modf(n,&i);
	
	if(x==0) 
	{
	
	do 
	{
	n=n/10;
	c=modf(n,&a);
	n=n-c;
	c=c*10;
	s=s+c;
	}
	while(n>0);
	}
	
	else {
	do 
	{
	i=i/10;
	c=modf(i,&a);
	i=i-c;
	c=c*10;
	s=s+c;
	}
	while(i>0);
	x=x*10000000;
	do 
	{
	x=x/10;
	y=modf(x,&b);
	x=x-y;
	y=y*10;
	t=t+y;
	}
	while(x>0);
	}

printf("Vuoi la somma della parte intera separata da quella della parte frazionaria o vuoi una somma totale?\n Digita:\n 1=somma totale\n 0=somme divise\n");
scanf("%lf",&r);
if(r==1) {
	s=s+t;
	printf("La somma totale è: %lf\n",s); }
else if(r==0) {
	printf("La somma della parte intera è: %lf\n",s);
	printf("La somma della parte frazionaria è: %lf\n",t); }
else {
	printf("Valore non valido\n"); }
 return 0; }
