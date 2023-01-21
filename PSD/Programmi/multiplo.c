#include <stdio.h>
int main(void)
{ 
int m,n,i,r;
printf("Inserisci i numeri m ed n\n"); 
scanf("%d %d",&m,&n);

for (i=0;i<=n;i++) {
r=i%m;
if(r==0) {
printf("%d\n",i); } }

return 0; }
