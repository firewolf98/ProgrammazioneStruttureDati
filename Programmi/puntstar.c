#include <stdio.h>
#include <stdlib.h>
int main(void) {
int i,*p;
printf("Inserisci un numero:\n");
scanf("%d",&i);
p=&i;
*++p;
printf("%d",i);
return 0;}
