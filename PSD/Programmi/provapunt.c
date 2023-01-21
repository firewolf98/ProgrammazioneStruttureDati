#include <stdio.h>
int cubo(int*);

int main(void) {
int n;
printf("Inserisci il numero:\n");
scanf("%d",&n);
cubo(&n);
printf("Il cubo è:%d\n",n);
return 0; }

int cubo(int *pn) {
return *pn= *pn * *pn * *pn; }
