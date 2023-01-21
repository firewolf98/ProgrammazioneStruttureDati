#include <stdio.h>
#include <string.h>
#define RIGHE 4
void cerca(char*[],char*[],char*[],int*);
int prefisso(char*,char*,int);
void aggiorna(char*,char*,char*[],int*,int*);
void stampa(char*[],int);


int main(void) {
char *parole[RIGHE]={"agosto","soleggiato","castello","marmotta"}, *prefix[RIGHE]={"sole","marmo","ottica","ago"}, *archivio[2*RIGHE]={NULL};
int num_pref=0;
cerca(parole,prefix,archivio,&num_pref); 
stampa(archivio,num_pref); }


void cerca(char *word[],char *pref[],char *addr[], int *num) {
int i,j,dim,dim1,risp,ind=0;
for(i=0;i<RIGHE;i++) {
dim=strlen(pref[i]);
for(j=0;j<RIGHE;j++) {
dim1=strlen(word[j]);
if(dim<dim1) {
risp=prefisso(pref[i],word[j],dim);
if(risp)
aggiorna(pref[i],word[j],addr,&ind,num); }}}}


int prefisso(char *vect,char *vect1, int size) {
if(!strncmp(vect,vect1,size))
return 1;
else 
return 0; }


void aggiorna(char *vect,char*vect1,char *addr[],int *ind,int *n) {
(*n)++;
addr[(*ind)++]=vect;
addr[(*ind)++]=vect1; }


void stampa(char *arch[],int num) {
int i;
printf("Il numero di prefissi è %d\n",num);
for(i=0;arch[i]!=NULL;i+=2)
printf("\n%s è prefisso di %s\n",arch[i],arch[i+1]); }
