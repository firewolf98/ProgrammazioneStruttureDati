#include <stdio.h>
int main(void) {
int n,m,i,r;

printf("Inserisci due numeri che sono gli estremi dell'intervallo\n");
scanf("%d %d",&m, &n);

printf("I numeri primi sono:\n");

while(m<n) {
r=0;	
for(i=2; i<=m/2;i++) {
if(m%i==0) {
r=1; break; }}
if(r==0) {
	if((m!=0)&&(m!=1))
printf("%d\n",m); }
m=m+1; }
return 0; }
