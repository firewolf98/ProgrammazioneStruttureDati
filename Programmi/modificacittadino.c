#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct cittadino
{
    
    char cognome[20];
    char nome[20];
    char luogo[20];
    int anno;
}cittadino;
 
void controllo_input(int);
void controllo_file(FILE *,char *);
void leggi_da_file(FILE *,cittadino *);
void new_aggiorna (cittadino *);
cittadino aggiorna_second(cittadino);
cittadino * aggiorna(char *[]);
void copia_in_vect(cittadino*, cittadino, cittadino, cittadino*);
void stampa(cittadino*);
void stampa_vect(cittadino*);
void controllo_file(FILE *,char *);
void scrivi_file(FILE *,cittadino *, int);
void scrivi_file_cognomi(FILE *,cittadino **,int);
void copia_cognomi(char**,cittadino *);
void append_file(FILE*,cittadino *);
 
int main (int argc,char *argv[]) {
    char *info[]={"Nappi","Michele"},**cognomi;
    cittadino *third, second, first, *records,*rec;
    int num_rec;
	FILE *uno, *due, *tre;
	controllo_input(argc);
	uno=fopen(argv[1],"r");
	controllo_file(uno,argv[1]);
	due=fopen(argv[2],"w");
	controllo_file(due,argv[2]);
	tre=fopen(argv[3],"w");
	controllo_file(tre,argv[3]);
    printf("Quanti sono i record da creare?\n");
    scanf("%d", &num_rec);
    records=calloc(num_rec, sizeof(cittadino));
	cognomi=calloc(num_rec, sizeof(char *));
    new_aggiorna(&first);
    second=aggiorna_second(first);
    third=aggiorna(info);
    stampa(&first);
    stampa(&second);
    stampa(third);
    copia_in_vect(records,first,second,third);
leggi_da_file(uno,records);
	copia_cognomi(cognomi,records);
    stampa_vect(records);
scrivi_file(due,records,num_rec);
scrivi_file_cognomi(tre,records,num_rec);
fclose(uno);
fclose(due);
fclose(tre);
free(records);
free(cognomi);
free(third);
    return 0;
}
 
void new_aggiorna(cittadino* data)
{
    printf("Inserisci Cognome, Nome, Luogo e Anno di Nascita:\n\n");
    scanf("%s%s%s%d",data->cognome,data->nome,data->luogo,&data->anno);
}
 
cittadino aggiorna_second(cittadino rec)
{
    cittadino tmp;
    tmp.anno=rec.anno;
    strcpy(tmp.cognome,rec.cognome);
    strcpy(tmp.nome,rec.nome);
    strcpy(tmp.luogo,rec.luogo);
    return tmp;
}
 
 
 
cittadino *aggiorna(char *data[])
{
    cittadino *new;
    char risposta;
    printf("Vuoi inserire un nuovo cittadino?\tSI=s\tNO=n\n");
    scanf("%s",&risposta);
    if(risposta=='n')
        return NULL;
    else
    {
        new=malloc(sizeof(cittadino));
        strcpy(new->cognome, data[0]);
        strcpy(new->nome, data[1]);
        printf("Inserisci luogo e anno di nascita\n");
        scanf("%s %d", new->luogo, &new->anno);
        return new;
    }
}
 
void copia_in_vect(cittadino *dest, cittadino uno, cittadino due, cittadino *tre)
{
    dest[0]=uno;
    dest[1]=due;
    dest[2]=*tre;
}

void controllo_input(int n) {
if(n!=4) {
printf("Il programma apre 3 file denominati uno, due e tre: il primo in lettura e gli altri in scrittura\n");
exit(1); }}

void controllo_file(FILE *file, char *stringa) {
if (file!=NULL)
printf("%s è stato aperto correttamente\n",stringa);
else 
exit(1); }

void leggi_da_file(FILE *in,cittadino *vect) {
if(fscanf(in,"%s %s %s %d",vect[3].cognome,vect[3].nome,vect[3].luogo,vect[3].anno)!=EOF); 
else 
printf("Il file è vuoto\n"); }

void stampa(cittadino *rec) {
printf("%s\t%s\t%s\t%d\n",rec->cognome,rec->nome,rec->luogo,rec->anno); }

void stampa_vect(cittadino *vect) {
printf("%s\t%s\t%s\t%d\n",vect[0].cognome,vect[0].nome,vect[0].luogo,vect[0].anno);
printf("%s\t%s\t%s\t%d\n",vect[1].cognome,vect[1].nome,vect[1].luogo,vect[1].anno);
printf("%s\t%s\t%s\t%d\n",vect[2].cognome,vect[2].nome,vect[2].luogo,vect[2].anno);
printf("%s\t%s\t%s\t%d\n",vect[3].cognome,vect[3].nome,vect[3].luogo,vect[3].anno); }

void scrivi_file(FILE *out,cittadino *vect, int size) {
int i;
for(i=0;i<size;i++) 
fprintf(out,"%s %s %s %d\n",vect[i].cognome,vect[i].nome,vect[i].luogo,vect[i].anno); }

void copia_cognomi(char **vect, cittadino *rec) {
vect[0]=calloc(strlen(rec[0].cognome),sizeof(char));
strcpy(vect[0],rec[0].cognome);
vect[1]=calloc(strlen(rec[1].cognome),sizeof(char));
strcpy(vect[1],rec[1].cognome);
vect[2]=calloc(strlen(rec[2].cognome),sizeof(char));
strcpy(vect[2],rec[2].cognome);
vect[3]=calloc(strlen(rec[3].cognome),sizeof(char));
strcpy(vect[3],rec[3].cognome); }

void scrivi_file_cognomi(FILE *out,cittadino **vect,int size) {
int i;
for(i=0;i<size;i++) 
fprintf(out,"%s\n",vect[i]); }
