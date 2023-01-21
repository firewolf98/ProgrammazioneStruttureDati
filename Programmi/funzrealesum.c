#include <stdio.h>
#include <math.h>

int intero(double,double,double,double);
int decimale(double);
int input(double);
int modeffe(double,double);
int parteintera(double)
int verifica(double)

int main(void) {



return 0; }


int input(double  n) {
printf("Inserisci un numero reale N:\n");
scanf("%lf",&n);  
return n; }


int modeffe(double x, double i) {
x=modf(input(n),&i);
return x; 
return i;}


int verifica(double







int intero(double n,double c,double s,double a) {
	do 
	{
	n=n/10;
	c=modf(n,&a);
	n=n-c;
	c=c*10;
	s=s+c;
	}
	while(n>0);
return s; }


int decimale(double
