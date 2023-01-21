#include <stdio.h>
#include <math.h>

int input(int);
int mcd(int,int);


int main(void) {
int a,b,c,x,y,mcm,prod;
x=input(a);
y=input(b);
c=mcd(x,y);
printf("%d\n",c);
prod=x*y;
mcm=prod/c;
printf("%d\n",mcm);

}


int input(int a) {
printf("Inserisci un valore:\n");
scanf("%d",&a);
return a; }


int mcd(int a,int b) {
int mcd;
while(a!=b) {
if(a>b)
a=a-b;
else b=b-a; }
mcd=a;
return mcd; }

