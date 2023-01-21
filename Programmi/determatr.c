#include <stdio.h>
void input(int[][2]);
int det(int[][2]);

int main(void) {
int mat[2][2];
input(mat);
printf("Il determinante è:%d",det(mat));
return 0; }

void input(int mat[][2]) {
int i,j;
for(i=0;i<2;i++) 
for(j=0;j<2;j++){
printf("Inserisci un valore:\n");
scanf ("%d",&mat[i][j]); } }

int det(int mat[][2]) {
int i,j,det=0,temp1=1,temp2=1;
for(i=0;i<2;i++) 
for(j=0;j<2;j++){
if(i==j)
temp1*=mat[i][j];
else 
temp2*=mat[i][j];
det=temp1-temp2; 
}
return det; }
