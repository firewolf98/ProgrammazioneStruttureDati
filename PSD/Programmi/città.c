#include <stdio.h>
#include <string.h>
#define MAX 5
void stampa_in(int*);
void leggi_city(char[]);
void cerca_city(char*[],char[]);
void stampa_out(char*[]);

int main(void) {
char *data_city[MAX]={"Milano","Napoli","Palermo","Roma","Torino"}, city[20];
int risposta; 
do {
stampa_in(&risposta);
if(!risposta)
break;
leggi_city(city);
cerca_city(data_city,city);
stampa_out(data_city); }
while(1); }


void stampa_in(int *risp) {
printf("\nQuesto programma determina la presenza di una città in un archivio e la cancella\n");
printf("Vuoi inserire la città?\n1=Si\n0=No\n");
scanf("%d",risp); }


void leggi_city(char nome_city[]) {
printf("Inserisci il nome della città da cancellare\n");
scanf("%s",nome_city); }


void cerca_city(char*data[],char city[]) {
int i;
for(i=0;i<MAX;i++)
if(data[i]!=NULL)
if(!strcmp(data[i],city))
data[i]=NULL; }


void stampa_out(char*new_data[]) {
int i;
for(i=0;i<MAX;i++)
if(new_data[i]!=NULL)
printf("\nLa città presente nell'archivio è %s ed ha indirizzo %p",new_data[i],&new_data[i]);
else 
printf("\nLa città è stata cancellata dall'archivio"); }
