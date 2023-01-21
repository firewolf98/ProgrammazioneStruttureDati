#include <stdio.h>
double somma(double,double);
double media(double);

double somma(double x,double y) {
printf("Inserisci i due valori\n");
scanf("%lf%lf",&x,&y);
x=x+y;
return x; }

double media(double m)  {
double x;
m=somma(x,x)/2;
return m; }

int main(void) {
double m;
printf("La media è: %lf\n",media(m));
return 0; }

