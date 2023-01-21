#include <stdio.h>
#include <math.h> 

int scelta(int);
int somma(int,int);
int sottrazione(int,int);
int moltiplicazione(int,int);
int divisione(int,int);

int main(void) {
int n,a,b;
switch(scelta(n)) {
case 0: printf("La somma è: %d\n",somma(a,b)); break;
case 1: printf("La sottrazione è: %d\n",sottrazione(a,b)); break; 
case 2: printf("La moltiplicazione è: %d\n",moltiplicazione(a,b)); break;
case 3: printf("La divisione è: %d\n",divisione(a,b)); break;
}
}

int scelta(int r) {
int i=1;
do {
printf("Scegli quale operazione svolgere:\n 0:Somma\n 1:Sottrazione\n 2:Moltiplicazione\n 3:Divisione\n");
scanf("%d",&r);
if((r>=0)&&(r<=3))
i--;
}
while(i!=0);
return r; }

int somma(int x,int y) {
printf("Inserisci due valori:\n");
scanf("%d %d",&x,&y);
return x+y; }

int sottrazione(int x,int y) {
printf("Inserisci due valori:\n");
scanf("%d %d",&x,&y);
return x-y; }

int moltiplicazione(int x,int y) {
printf("Inserisci due valori:\n");
scanf("%d %d",&x,&y);
return x*y; }

int divisione(int x,int y) {
printf("Inserisci due valori:\n");
scanf("%d %d",&x,&y);
return x/y; }

