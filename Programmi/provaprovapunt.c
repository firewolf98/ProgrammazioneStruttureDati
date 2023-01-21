#include <stdio.h>
void funct(int **);
int main(void) {
int x[2][2],i,j;
for(i=0;i<2;i++)
for(j=0;j<2;j++) 
scanf("%d",&x[i][j]);
funct(x); }

void funct(int **y) {
int i,j;
 for(i=0;i<2;i++)
for(j=0;j<2;j++)
printf("%d\n",y[i][j]);
 }
