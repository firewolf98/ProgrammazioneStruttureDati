#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#define MAX 20


typedef struct libro{
char titolo[MAX];
char autore[MAX];
int pagine;
char genere[MAX];
}libro;


void inserisci(libro*);
int scelta(char*);
void ricerca(libro*,char*,libro*,int*n);
void stampa(libro*,int,char*);


int main(void) {
libro a[5];
int n=0;
libro *b;
char writer[MAX];
inserisci(a);
if(scelta(writer)==1) {
ricerca(a,writer,b,&n);
b=calloc(n,sizeof(libro));
stampa(b,n,writer);}
free(b);
return 0;}


void inserisci(libro *a) {
int i;
for(i=0;i<5;i++){
printf("Inserisci Titolo, Autore, Numero di pagine e il genere del libro\n");
scanf("%s %s %d %s",a[i].titolo,a[i].autore,&a[i].pagine,a[i].genere);}}


int scelta(char *nome) {
int n;
printf("Vuoi cercare dei libri nell'archivio?\n(1=Si,2=No)\n");
scanf("%d",&n);
if(n==1){
printf("Di quale autore vuoi cercare i libri?\n");
scanf("%s",nome);
return 1;}
else 
return 0;}


void ricerca(libro *a,char *nome,libro *b,int *n) {
int i,j=0,k=0;
for(i=0;i<5;i++) {
if(strcmp(a[i].autore,nome)){
b[j]=a[i];
j++;
}}
*n=j;}


void stampa(libro *b,int n,char *nome){
int i;
printf("I libri di %s sono %d:\n",nome,n);
if(n>0) {
printf("Titolo\tNumero di pagine\tGenere\n");
for(i=0;i<n;i++) {
printf("%s\t%d\t%s\n",b[i].titolo,b[i].pagine,b[i].genere);}}}
