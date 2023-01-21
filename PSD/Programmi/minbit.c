#include <stdio.h>
int main(void) {
int x=1,n,i;
printf("Inserisci un numero:\n");
scanf("%d",&n);
if ((n==0)||(n==1)) {
printf("Il numero di bit necessari per rappresentare %d in binario è: %d\n",n,x); }
else {
for(i=n;i!=1;x++)
i=i/2;
printf("Il numero di bit necessari per rappresentare %d in binario è: %d\n",n,x); }
return 0; }
