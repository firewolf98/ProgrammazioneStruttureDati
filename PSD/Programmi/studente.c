#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct studente{
int matricola;
char cognome[20];
char nome[20];
char luogo[20];
int anno;
int *esami;}studente;

void controllo_input(int);
void controllo_file(FILE*,char*);
void conta_in_file_esami(FILE*,int*);
void update(int,char*[],studente*,FILE*);
void scrivi_file(FILE*,studente,int);


int main(int argc,char *argv[]) {
char *info[]={"Verde","Luisa","Napoli"};
studente rec;
int num_esami=0;
FILE *input, *output;
controllo_input(argc);
input=fopen(argv[1],"r");
controllo_file(input,argv[1]);
output=fopen(argv[2],"w");
controllo_file(output,argv[2]);
conta_in_file_esami(input,&num_esami);
update(num_esami,info,&rec,input);
scrivi_file(output,rec,num_esami);
fclose(input);
fclose(output);
free(rec.esami);
return 0;}


void controllo_input(int n) {
if(n!=3) {
printf("Il programma apre 2 file uno in lettura e uno in scrittura\n");
exit(1); }}


void controllo_file(FILE *file, char *stringa) {
if (file!=NULL)
printf("%s è stato aperto correttamente\n",stringa);
else 
exit(1); }


void conta_in_file_esami(FILE *primo,int *conta) {
int n;
while(fscanf(primo,"%d",&n)!=EOF)
(*conta)++;}


void update(int num,char *info[],studente *std,FILE *primo) {
int i=0;
printf("Inserisci numero di matricola e l'anno\n");
scanf("%d %d",&std->matricola,&std->anno);
std->esami=calloc(num,sizeof(int));
strcpy(std->cognome,info[0]);
strcpy(std->nome,info[1]);
strcpy(std->luogo,info[2]);
rewind(primo);
while(fscanf(primo,"%d",&std->esami[i])!=EOF)
i++;}


void scrivi_file(FILE *secondo,studente std,int num) {
int i;
fprintf(secondo,"%d\t%s\t%s\t%s\t%d\t",std.matricola,std.cognome,std.nome,std.luogo,std.anno);
for(i=0;i<num;i++)
fprintf(secondo,"%d\t",std.esami[i]);}
