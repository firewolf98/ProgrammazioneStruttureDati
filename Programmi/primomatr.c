#include <stdio.h>
#define n 2
#define m 2
void inizializza(int[][m]);
void primo(int[][m],int[]);
void stampa(int[]);


int main(void) {
int mat[n][m],vet[n*m];
inizializza(mat);
primo(mat,vet);
stampa(vet); }


void inizializza(int mat[][m]) {
int i,j;
for(i=0;i<n;i++) 
for(j=0;j<m;j++){
mat[i][j]=0;
printf("Inserisci il valore di posto (%d,%d)\n",i,j);
scanf("%d",&mat[i][j]); }}


void primo(int mat[][m],int vet[]) {
int i,j,r=0,x=1,s=0,count=0;
for(i=0;i<n;i++) 
for(j=0;j<m;j++){
if(mat[i][j]>1) 

while(x<=mat[i][j]) 
		{
		r=mat[i][j]%x; 

		if(r==0) 
			{
			s=s+1;
			} 
		x=x+1;
		}
if(s==2) 
vet[count++]=mat[i][j];
x=1; 
  }} 


void stampa(int vet[]) {
int i;
for(i=0;i<n*m;i++) {
printf("%d\n",vet[i]); } }
