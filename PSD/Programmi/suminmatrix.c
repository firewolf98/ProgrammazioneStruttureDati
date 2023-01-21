#include <stdio.h>
#define n 5
#define m 5
void inizializza(int[][m]);
void sommarig(int[][m],int[]);
void sommacol(int[][m],int[]);
void stampa(int[]);


int main(void) {
int matrix[n][m], somma[n]={0};
inizializza(matrix);
sommarig(matrix,somma);
sommacol(matrix,somma); }


void inizializza(int matrix[][m]) {
int i,j;
for(i=0;i<n;i++) 
for(j=0;j<m;j++){
matrix[i][j]=0;
printf("Inserisci il valore di posto (%d,%d)\n",i,j);
scanf("%d",&matrix[i][j]); }}


void sommarig(int matrix[][m],int vet[]) {
int i,j,sum=0;
for(i=0;i<n;i++) {
for(j=0;j<m;j++){
sum+=matrix[i][j];}
vet[i]=sum;
sum=0; }
printf("La somma delle righe è:\n");
stampa(vet); }


void sommacol(int matrix[][m],int vet[]) {
int i,j,sum=0;
for(j=0;j<m;j++) {
for(i=0;i<n;i++){
sum+=matrix[i][j];}
vet[j]=sum;
sum=0; }
printf("La somma delle colonne è:\n");
stampa(vet); }


void stampa(int vet[]) {
int i;
for(i=0;i<n;i++) {
printf("%d\n",vet[i]); } }
