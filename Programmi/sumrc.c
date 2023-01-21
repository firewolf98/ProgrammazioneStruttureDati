#include <stdio.h>
void inizializza(int[][4]);
void input(int[][4]);
void somma(int[][4]);
void stampa(int[][4]);


void inizializza(int mat[][4]) {
int i,j;
for(i=0;i<4;i++) 
for(j=0;j<4;j++){
mat[i][j]=0; }}


void input(int mat[][4]) {
int i,j;
for(i=0;i<3;i++) 
for(j=0;j<3;j++){
printf("Inserisci il valore di posizione %d,%d:\n",i,j);
scanf ("%d",&mat[i][j]); }}


void somma(int mat[][4]){
int i,j,sum=0,temp=0;
for(i=0;i<3;i++) {
for(j=0;j<3;j++){
sum+=mat[i][j]; } 
mat[i][3]=sum;
sum=0;
mat[3][3]+=mat[i][3];}
for(j=0;j<3;j++) {
for(i=0;i<3;i++){
temp+=mat[i][j]; } 
mat[3][j]=temp;
temp=0;
mat[3][3]+=mat[3][j];}}


void stampa(int mat[][4]) {
int i,j;
for(i=0;i<4;i++) {
for(j=0;j<4;j++){
printf("%5d",mat[i][j]); }
printf("\n"); } }

int main(void) {
int mat[4][4];
inizializza(mat);
input(mat);
somma(mat);
stampa(mat); 
return 0; }
