#include <stdio.h>
#include <string.h>
#define RIGHE 4
#define COLONNE 20
void copia(char*[],char*[],char[][COLONNE],char*[]);
void ordina(char*[]);
int scorri(char*[]);
void swap(char*lista[],int i);
void stampa(char[][COLONNE]);
void stampa_ord(char*[]);


int main(void) {
char *archivio1[RIGHE]={"ago","uccello","castello","ultraleggero"}, *archivio2[RIGHE]={"sole","marmo","ottica","martello"}, archivio[2*RIGHE][COLONNE], *ordinato[2*RIGHE];
copia(archivio1,archivio2,archivio,ordinato);
stampa(archivio);
ordina(ordinato);
stampa_ord(ordinato); }


void copia(char*primo[],char*secondo[],char totale[][COLONNE],char*ordinato[]) {
int i,j;
for (i=0;i<RIGHE;i++) {
strcpy(&totale[i][0],primo[i]);
ordinato[i]=&totale[i][0]; }
for (j=0;i<2*RIGHE;i++,j++) {
strcpy(&totale[i][0],secondo[j]);
ordinato[i]=&totale[i][0]; } }


void stampa(char totale[][COLONNE]) { 
int i,j;
for (i=0;i<2*RIGHE;i++) 
printf("%s\n",&totale[i][0]);
for (j=0;j<COLONNE;j++) 
printf("%c",totale[i][0]); }


void ordina(char*ord[]) {
while(scorri(ord)); }


int scorri(char *ord[]) {
int i,scambi=0;
for(i=0;i<2*RIGHE-1;i++){
if(strlen(ord[i])>strlen(ord[i+1])) {
swap(ord,i);
scambi++;}}
return scambi;}


void swap(char*lista[],int i) {
char *temp;
temp=lista[i];
lista[i]=lista[i+1];
lista[i+1]=temp; }


void stampa_ord(char*totale[]) {
int i;
for(i=0;i<2*RIGHE;i++)
printf("%s\n",totale[i]); }
