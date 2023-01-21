#include <stdio.h>
#include <stdlib.h>
void inverti(int *);
int main(void) {
int mat[2][2];
int*p,**t;
mat[0][0]=1;
mat[0][1]=2;
mat[1][0]=3;
mat[1][1]=4;
p=&mat[0][0];
printf("%d\n",*p);
inverti(&mat[0][0]);
printf("%d\n",*p);
return 0;}

void inverti(int *mat) {
int b;
b=mat[0][0];
mat[0][0]=mat[1][1];
mat[1][1]=b;
}
