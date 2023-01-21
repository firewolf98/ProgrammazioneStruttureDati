#include <stdio.h>
#include <stdlib.h>
void inserisci(int[][2]);
void scrivi(int[][2],FILE*);
int main(void) {
int mat[2][2];
FILE *output;
output=fopen("testo","w");
inserisci(mat);
scrivi(mat,output);
fclose(output);
return 0; }


void inserisci(int mat[][2]) {
int i,j;
for(i=0;i<2;i++) 
for(j=0;j<2;j++) {
printf("Inserisci l'elemento di posizione (%d,%d)\n",i,j);
scanf("%d",&mat[i][j]);}}


void scrivi(int mat[][2],FILE *out) {
int i,j;
for(i=0;i<2;i++) {
for(j=0;j<2;j++) {
fprintf(out,"%d\t",mat[i][j]); }
fprintf(out,"\n"); } }


