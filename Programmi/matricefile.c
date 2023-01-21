#include <stdio.h>
#include <stdlib.h>


void scelta(int*);
void inserisci(int[][],int);
void scrivi(FILE*,int[][],int);


int main(void) {
FILE *output;
int n,*mat;
output=fopen("prova","w");
scelta(&n);
mat=malloc(n,sizeof(int));
inserisci(mat,n);
scrivi(output,mat,n);
fclose(output);
return 0;}


void scelta(int *n) {
printf("Consideriamo una matrice quadrata\nInserisci il numero di righe/colonne:\n");
scanf("%d",n);}


void inserisci(int mat[][n],int n) {
int i,j;
for(i=0;i<n;i++)
for(j=0;j<n;j++) {
printf("Inserisci l'elemento di posizione: (%d,%d)\n");
scanf("%d",mat[i][j]);}}


void scrivi(FILE *output,int mat[][n];int n) {
int i,j;
for(i=0;i<n;i++) {
for(j=0;j<n;j++) {
fprintf(output,"%d\t",mat[i][j]);}
fprintf(output,"\n"); } }
